#include "TFile.h"
#include "RooWorkspace.h"
#include "RooAbsPdf.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooStats/ModelConfig.h"
#include "RooRandom.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TROOT.h"

#include "RooStats/AsymptoticCalculator.h"
#include "RooStats/HybridCalculator.h"
#include "RooStats/FrequentistCalculator.h"
#include "RooStats/ToyMCSampler.h"
#include "RooStats/HypoTestPlot.h"

#include "RooStats/NumEventsTestStat.h"
#include "RooStats/ProfileLikelihoodTestStat.h"
#include "RooStats/SimpleLikelihoodRatioTestStat.h"
#include "RooStats/RatioOfProfiledLikelihoodsTestStat.h"
#include "RooStats/MaxLikelihoodEstimateTestStat.h"

#include "RooStats/HypoTestInverter.h"
#include "RooStats/HypoTestInverterResult.h"
#include "RooStats/HypoTestInverterPlot.h"

#include "RooMinuit.h"
#include "RooGlobalFunc.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooGenericPdf.h"
#include "RooChebychev.h"
#include "RooPolynomial.h"
#include "RooAddPdf.h"
#include "RooExtendPdf.h"
#include "RooPlot.h"
#include "RooFitResult.h"
#include "RooHist.h"

using namespace RooFit;
using namespace RooStats;

bool noSystematics = 0;              // force all systematics to be off (i.e. set all nuisance parameters as constat
double nToysRatio = 1;                   // ratio Ntoys Null/ntoys ALT
double poiValue = -1;                    // change poi snapshot value for S+B model (needed for expected p0 values)
int  printLevel=0;
bool generateBinned = false;             // for binned generation

int calcType = 0; // 0 freq 1 hybrid, 2 asymptotic
int testStatType = 3;   // 0 LEP, 1 TeV, 2 LHC, 3 LHC - one sided
//int ntoys = 5000;
int ntoys = 100;
bool useNC = false;
const char * nuisPriorName = 0;

bool ispp = 1;
TString fname = "";
int _count = 1;
int nCPU=2;
void HypoTest(){
	TCanvas*c = new TCanvas("c","",600,600); c->cd();
	
	fname = "hPtSpectrumSaveHistBplusPP_roofit.root";
	if(!ispp) fname = "hPtSpectrumSaveHistBplusPbPb_roofit.root";
	TFile* inf = new TFile(fname.Data());
	RooWorkspace* ws = (RooWorkspace*)inf->Get("w");
	RooDataSet *data;
	data =(RooDataSet *) ws->data(Form("ds%d",_count));

	RooRealVar* mean = ws->var(Form("mean%d",_count));
	RooRealVar* sigma1 = ws->var(Form("sigma1%d",_count));
	RooRealVar* sigma2 = ws->var(Form("sigma2%d",_count));
	RooRealVar* sig1frac = ws->var(Form("sig1frac%d",_count));
	RooRealVar* a0 = ws->var(Form("a0%d",_count));
	RooRealVar* a1 = ws->var(Form("a1%d",_count));
	RooRealVar* a2 = ws->var(Form("a2%d",_count));
	RooRealVar* nsig = ws->var(Form("nsig%d",_count));
	RooRealVar* nbkg = ws->var(Form("nbkg%d",_count));
	//RooRealVar* npeakbg = ws->var(Form("npeakbg%d",_count));
	//mean->setConstant(true);
	sigma1->setConstant(true);
	sigma2->setConstant(true);
	sig1frac->setConstant(true);
	//a0->setConstant(true);
	//a1->setConstant(true);
	//a2->setConstant(true);
	//nsig->setConstant(true);
	//nbkg->setConstant(true);
	//npeakbg->setConstant(true);

    RooAddPdf *sig = (RooAddPdf*) ws->pdf(Form("sig%d",_count));
	RooPolynomial* bkg = (RooPolynomial*) ws->pdf(Form("bkg%d",_count));
	//RooGenericPdf* peakbg = (RooGenericPdf*) ws->pdf(Form("peakbg%d",_count));
    RooAddPdf *model = (RooAddPdf*) ws->pdf(Form("model%d",_count));

	RooAbsPdf* sig_abs = static_cast<RooAbsPdf*>(sig->Clone("sig_abs"));
	RooAbsReal* nsig_abs = static_cast<RooAbsReal*>(nsig->Clone("nsig_abs"));
	RooAbsPdf* bkg_abs = static_cast<RooAbsPdf*>(bkg->Clone("bkg_abs"));
	RooAbsReal* nbkg_abs = static_cast<RooAbsReal*>(nbkg->Clone("nbkg_abs"));
	//RooAbsPdf* peakbg_abs = static_cast<RooAbsPdf*>(peakbg->Clone("peakbg_abs"));
	//RooAbsReal* npeakbg_abs = static_cast<RooAbsReal*>(npeakbg->Clone("npeakbg_abs"));
	ws->import(*sig_abs);
	ws->import(*nsig_abs);
	ws->import(*bkg_abs);
	ws->import(*nbkg_abs);
	//ws->import(*peakbg_abs);
	//ws->import(*npeakbg_abs);

	//double systval = 1.10;
	double systval = 1.5;
    ws->factory( Form("kappa_syst[%f]",systval) );
    ws->factory( "expr::alpha_syst('pow(kappa_syst,beta_syst)',kappa_syst,beta_syst[0,-5,5])" );
    ws->factory( Form("prod::nsig_syst(nsig%d,alpha_syst)",_count) );
	//ws->factory( Form("expr::nsig_syst('@0*@1',nsig%d,alpha_syst)",_count) );
    ws->factory( "Gaussian::constr_syst(beta_syst,glob_syst[0,-5,5],1)" );
    RooGaussian *constr_syst = (RooGaussian*) ws->pdf("constr_syst");
	RooRealVar* nsig_syst = ws->var(Form("nsig_syst"));
    //RooAddPdf* model_syst_noconstr = new RooAddPdf(Form("model_syst_noconstr"),"",RooArgList(*bkg,*sig,*peakbg),RooArgList(*nbkg,*nsig_syst,*npeakbg));
    //ws->factory( "SUM::model_syst_noconstr(nbkg_abs * bkg_abs, nsig_syst * sig_abs, npeakbg_abs * peakbg_abs)" ); RooAddPdf* model_syst_noconstr = (RooAddPdf*)ws->pdf("model_syst_noconstr");
    ws->factory( "SUM::model_syst_noconstr(nbkg_abs * bkg_abs, nsig_syst * sig_abs)" ); RooAddPdf* model_syst_noconstr = (RooAddPdf*)ws->pdf("model_syst_noconstr");
    RooProdPdf *model_syst = new RooProdPdf("model_syst","model_syst",RooArgSet(*model_syst_noconstr,*constr_syst));
	ws->import(*model_syst);
	if(!noSystematics) ws->var("beta_syst")->setConstant(kFALSE);
	else ws->var("beta_syst")->setConstant(kTRUE);
	ws->var("glob_syst")->setConstant(true);

	RooRealVar * pObs = ws->var("Bmass"); // get the pointer to the observable
	RooArgSet obs("observables");
	obs.add(*pObs);
    RooArgSet globalObs("global_obs");
    globalObs.add( *ws->var("glob_syst") );
	RooArgSet poi("poi");
	poi.add(*ws->var(Form("nsig%d",_count)));
	//poi.add(*ws->var(Form("nsig_abs")));
    RooArgSet nuis("nuis");
    nuis.add( *ws->var("beta_syst") );
	//ws->saveSnapshot("snapshot",RooArgSet(*nsig,*nbkg));
	ws->Print();

	// create signal+background Model Config
	RooStats::ModelConfig sbHypo("SbHypo");
	sbHypo.SetWorkspace( *ws );
	if(noSystematics) sbHypo.SetPdf( *ws->pdf(Form("model%d",_count)) );
	else sbHypo.SetPdf( *ws->pdf(Form("model_syst")) );
	sbHypo.SetObservables( obs );
	sbHypo.SetGlobalObservables( globalObs );
	sbHypo.SetParametersOfInterest( poi );
	if(!noSystematics) sbHypo.SetNuisanceParameters( nuis );
    RooAbsReal * pNll = sbHypo.GetPdf()->createNLL( *data,NumCPU(nCPU) );
    RooMinuit(*pNll).migrad(); // minimize likelihood wrt all parameters before making plots
    ((RooRealVar *)poi.first())->setMin(0.);
	//RooAbsReal * pProfile = pNll->createProfile( globalObs ); // do not profile global observables
	//pProfile->getVal(); // this will do fit and set POI and nuisance parameters to fitted values
	RooArgSet * pPoiAndNuisance = new RooArgSet("poiAndNuisance");
	if(!noSystematics) pPoiAndNuisance->add( nuis );
	pPoiAndNuisance->add( poi );
	sbHypo.SetSnapshot(*pPoiAndNuisance);

	RooPlot* frame = ws->var("Bmass")->frame(Title(""));
	data->plotOn(frame,Name(Form("ds%d",_count)),Binning(50),MarkerSize(1.55),MarkerStyle(20),MarkerColor(1),LineColor(1),LineWidth(4),LineColor(1));
	model->plotOn(frame,Name(Form("model%d",_count)),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineColor(2),LineWidth(4));

	RooStats::ModelConfig bHypo = sbHypo;
	bHypo.SetName("BHypo");
	bHypo.SetWorkspace(*ws);
    pNll = bHypo.GetPdf()->createNLL( *data,NumCPU(nCPU) );
    RooArgSet poiAndGlobalObs("poiAndGlobalObs");
    poiAndGlobalObs.add( poi );
    poiAndGlobalObs.add( globalObs );
	float oldVal = ((RooRealVar *)poi.first())->getVal();
	((RooRealVar *)poi.first())->setVal( 0 );
    if(!noSystematics) pNll = model->createNLL( *data,NumCPU(nCPU) ); // ues original model without syst to profile
    RooAbsReal * pProfile = pNll->createProfile( poiAndGlobalObs ); // do not profile POI and global observables
	//pProfile->getVal(); // this will do fit and set nuisance parameters to profiled values
	((RooRealVar *)poi.first())->setConstant(kTRUE);
	model->fitTo(*data,NumCPU(nCPU),Minos(RooArgSet(poi)),Extended());
	((RooRealVar *)poi.first())->setConstant(kFALSE);
	RooArgSet * bpPoiAndNuisance = new RooArgSet( "bpoiAndNuisance" );
//((RooRealVar *)nuis.first())->setVal( 0.001 );
	if(!noSystematics) bpPoiAndNuisance->add( nuis );
	bpPoiAndNuisance->add( poi );
	bHypo.SetSnapshot(*bpPoiAndNuisance);

	model->plotOn(frame,Name(Form("model%d",_count)),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineColor(4),LineWidth(4));
	frame->Draw();
	if(ispp) c->SaveAs(Form("pp_PDF.pdf"));
	else c->SaveAs(Form("PbPb_PDF.pdf"));
	//return;

	((RooRealVar *)poi.first())->setVal( oldVal );
  	ModelConfig* sbModel = (ModelConfig*)sbHypo.Clone();
  	ModelConfig* bModel = (ModelConfig*)bHypo.Clone();

	// print some check
	sbModel->Print();
	bModel->Print();
	RooArgSet* arg = sbModel->GetPdf()->getVariables();
	TIterator* it = arg->createIterator();
	RooRealVar* theVar = (RooRealVar*) it->Next();
	while (theVar) {
		theVar->Print();
		theVar = (RooRealVar*) it->Next();
	}
	//return;

    SimpleLikelihoodRatioTestStat::SetAlwaysReuseNLL(true);
    ProfileLikelihoodTestStat::SetAlwaysReuseNLL(true);
    RatioOfProfiledLikelihoodsTestStat::SetAlwaysReuseNLL(true);

	// part 1, hypothesis testing
	SimpleLikelihoodRatioTestStat * slrts = new SimpleLikelihoodRatioTestStat(*bModel->GetPdf(), *sbModel->GetPdf());
	// null parameters must includes snapshot of poi plus the nuisance values
	RooArgSet nullParams(*bModel->GetSnapshot());
	if (bModel->GetNuisanceParameters()) nullParams.add(*bModel->GetNuisanceParameters());

	slrts->SetNullParameters(nullParams);
	RooArgSet altParams(*sbModel->GetSnapshot());
	if (sbModel->GetNuisanceParameters()) altParams.add(*sbModel->GetNuisanceParameters());
	slrts->SetAltParameters(altParams);


	//ProfileLikelihoodTestStat * profll = new ProfileLikelihoodTestStat(*bModel->GetPdf());
	ProfileLikelihoodTestStat * profll = new ProfileLikelihoodTestStat(*sbModel->GetPdf());


	RatioOfProfiledLikelihoodsTestStat *
		ropl = new RatioOfProfiledLikelihoodsTestStat(*bModel->GetPdf(), *sbModel->GetPdf(), sbModel->GetSnapshot());
	ropl->SetSubtractMLE(false);

	if (testStatType == 3) profll->SetOneSidedDiscovery(1);
	profll->SetPrintLevel(printLevel);

	// profll.SetReuseNLL(mOptimize);
	// slrts.SetReuseNLL(mOptimize);
	// ropl.SetReuseNLL(mOptimize);

	AsymptoticCalculator::SetPrintLevel(printLevel);

	HypoTestCalculatorGeneric *  hypoCalc = 0;
	// note here Null is B and Alt is S+B
	if (calcType == 0) hypoCalc = new  FrequentistCalculator(*data, *sbModel, *bModel);
	else if (calcType == 1) hypoCalc= new  HybridCalculator(*data, *sbModel, *bModel);
	else if (calcType == 2) hypoCalc= new  AsymptoticCalculator(*data, *sbModel, *bModel);

	if (calcType == 0) 
		((FrequentistCalculator*)hypoCalc)->SetToys(ntoys, ntoys/nToysRatio);
	if (calcType == 1) 
		((HybridCalculator*)hypoCalc)->SetToys(ntoys, ntoys/nToysRatio);
	if (calcType == 2 ) { 
		if (testStatType == 3) ((AsymptoticCalculator*) hypoCalc)->SetOneSidedDiscovery(true);  
		if (testStatType != 2 && testStatType != 3)  
			Warning("StandardHypoTestDemo","Only the PL test statistic can be used with AsymptoticCalculator - use by default a two-sided PL");


	}


	// check for nuisance prior pdf in case of nuisance parameters 
	if (calcType == 1 && (bModel->GetNuisanceParameters() || sbModel->GetNuisanceParameters() )) {
		RooAbsPdf * nuisPdf = 0; 
		if (nuisPriorName) nuisPdf = ws->pdf(nuisPriorName);
		// use prior defined first in bModel (then in SbModel)
		if (!nuisPdf)  { 
			Info("StandardHypoTestDemo","No nuisance pdf given for the HybridCalculator - try to deduce  pdf from the   model");
			if (bModel->GetPdf() && bModel->GetObservables() ) 
				nuisPdf = RooStats::MakeNuisancePdf(*bModel,"nuisancePdf_bmodel");
			else 
				nuisPdf = RooStats::MakeNuisancePdf(*sbModel,"nuisancePdf_sbmodel");
		}   
		if (!nuisPdf ) {
			if (bModel->GetPriorPdf())  { 
				nuisPdf = bModel->GetPriorPdf();
				Info("StandardHypoTestDemo","No nuisance pdf given - try to use %s that is defined as a prior pdf in the B model",nuisPdf->GetName());            
			}
			else { 
				Error("StandardHypoTestDemo","Cannnot run Hybrid calculator because no prior on the nuisance parameter is specified or can be derived");
				return;
			}
		}
		assert(nuisPdf);
		Info("StandardHypoTestDemo","Using as nuisance Pdf ... " );
		nuisPdf->Print();

		const RooArgSet * nuisParams = (bModel->GetNuisanceParameters() ) ? bModel->GetNuisanceParameters() : sbModel->GetNuisanceParameters();
		RooArgSet * np = nuisPdf->getObservables(*nuisParams);
		if (np->getSize() == 0) { 
			Warning("StandardHypoTestDemo","Prior nuisance does not depend on nuisance parameters. They will be smeared in their full range");
		}
		delete np;

		((HybridCalculator*)hypoCalc)->ForcePriorNuisanceAlt(*nuisPdf);
		((HybridCalculator*)hypoCalc)->ForcePriorNuisanceNull(*nuisPdf);
	}

	// hypoCalc->ForcePriorNuisanceAlt(*sbModel->GetPriorPdf());
	// hypoCalc->ForcePriorNuisanceNull(*bModel->GetPriorPdf());

	ToyMCSampler * sampler = (ToyMCSampler *)hypoCalc->GetTestStatSampler();

	if (sampler && (calcType == 0 || calcType == 1) ) { 

		// look if pdf is number counting or extended
		if (sbModel->GetPdf()->canBeExtended() ) { 
			if (useNC)   Warning("StandardHypoTestDemo","Pdf is extended: but number counting flag is set: ignore it ");
		}
		else {
			// for not extended pdf
			if (!useNC)  { 
				int nEvents = data->numEntries();
				Info("StandardHypoTestDemo","Pdf is not extended: number of events to generate taken  from observed data set is %d",nEvents);
				sampler->SetNEventsPerToy(nEvents);
			}
			else {
				Info("StandardHypoTestDemo","using a number counting pdf");
				sampler->SetNEventsPerToy(1);
			}
		}

		if (data->isWeighted() && !generateBinned) { 
			Info("StandardHypoTestDemo","Data set is weighted, nentries = %d and sum of weights = %8.1f but toy generation is unbinned - it would be faster to set generateBinned to true\n",data->numEntries(), data->sumEntries());
		}
		if (generateBinned)  sampler->SetGenerateBinned(generateBinned);


		// set the test statistic
		if (testStatType == 0) sampler->SetTestStatistic(slrts); 
		if (testStatType == 1) sampler->SetTestStatistic(ropl); 
		if (testStatType == 2 || testStatType == 3) sampler->SetTestStatistic(profll); 

	}

	HypoTestResult *  htr = hypoCalc->GetHypoTest();
	htr->SetPValueIsRightTail(true);
	htr->SetBackgroundAsAlt(false);
	htr->Print(); // how to get meaningfull CLs at this point?

	delete sampler;
	delete slrts; 
	delete ropl; 
	delete profll;

	if (calcType != 2) {
		HypoTestPlot * plot = new HypoTestPlot(*htr,100);
		plot->SetLogYaxis(true);
		plot->Draw();
	}
	else { 
		std::cout << "Asymptotic results " << std::endl;

	}

	// look at expected significances 
	// found median of S+B distribution
	if (calcType != 2) { 

		SamplingDistribution * altDist = htr->GetAltDistribution();   
		HypoTestResult htExp("Expected Result");
		htExp.Append(htr);
		// find quantiles in alt (S+B) distribution 
		double p[5];
		double q[5];
		for (int i = 0; i < 5; ++i) { 
			double sig = -2  + i;
			p[i] = ROOT::Math::normal_cdf(sig,1);
		}
		std::vector<double> values = altDist->GetSamplingDistribution();
		TMath::Quantiles( values.size(), 5, &values[0], q, p, false);  

		for (int i = 0; i < 5; ++i) { 
			htExp.SetTestStatisticData( q[i] );
			double sig = -2  + i;      
			std::cout << " Expected p -value and significance at " << sig << " sigma = " 
				<< htExp.NullPValue() << " significance " << htExp.Significance() << " sigma " << std::endl; 

		}
	}
	else { 
		// case of asymptotic calculator 
		for (int i = 0; i < 5; ++i) { 
			double sig = -2  + i;      
			// sigma is inverted here 
			double pval = AsymptoticCalculator::GetExpectedPValues( htr->NullPValue(), htr->AlternatePValue(), -sig, false);
			std::cout << " Expected p -value and significance at " << sig << " sigma = " 
				<< pval << " significance " << ROOT::Math::normal_quantile_c(pval,1) << " sigma " << std::endl; 

		}
	}

	if(ispp) c->SaveAs(Form("pp_result_%d.pdf",ntoys));
	else c->SaveAs(Form("PbPb_result_%d.pdf",ntoys));
}
