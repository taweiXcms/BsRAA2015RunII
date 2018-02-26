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

using namespace RooFit;
using namespace RooStats;

#include "iostream"
using namespace std;

bool noSystematics = true;              // force all systematics to be off (i.e. set all nuisance parameters as constat
double nToysRatio = 1;                   // ratio Ntoys Null/ntoys ALT
double poiValue = -1;                    // change poi snapshot value for S+B model (needed for expected p0 values)
int  printLevel=0;
bool generateBinned = false;             // for binned generation

int calcType = 0; // 0 freq 1 hybrid, 2 asymptotic
int testStatType = 3;   // 0 LEP, 1 TeV, 2 LHC, 3 LHC - one sided
//int ntoys = 5000;
int ntoys = 500;
bool useNC = false;
const char * nuisPriorName = 0;

bool ispp = 1;
TString fname = "";
int _count = 1;
void HypoTest(){
	TCanvas*c = new TCanvas("c","",600,600); c->cd();
	
	fname = "hPtSpectrumSaveHistBplusPP_roofit.root";
	if(!ispp) fname = "hPtSpectrumSaveHistBplusPbPb_roofit.root";
	TFile* inf = new TFile(fname.Data());
	RooWorkspace* ws = (RooWorkspace*)inf->Get("w");
	ws->Print();
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
	RooRealVar* npeakbg = ws->var(Form("npeakbg%d",_count));
    mean->setConstant(true);
	sigma1->setConstant(true);
	sigma2->setConstant(true);
	sig1frac->setConstant(true);
	a0->setConstant(true);
	a1->setConstant(true);
	a2->setConstant(true);
	nbkg->setConstant(true);
	npeakbg->setConstant(true);

	RooRealVar * pObs = ws->var("Bmass"); // get the pointer to the observable
	RooArgSet obs("observables");
	obs.add(*pObs);

	RooArgSet poi("poi");
	poi.add(*ws->var(Form("nsig%d",_count)));

	// create signal+background Model Config
	RooStats::ModelConfig sbHypo("SbHypo");
	sbHypo.SetWorkspace( *ws );
	sbHypo.SetPdf( *ws->pdf(Form("model%d",_count)) );
	sbHypo.SetObservables( obs );
	sbHypo.SetParametersOfInterest( poi );

	RooStats::ModelConfig bHypo = sbHypo;
	bHypo.SetName("BHypo");
	bHypo.SetWorkspace(*ws);

	RooArgSet * pPoiAndNuisance = new RooArgSet("poiAndNuisance");
	((RooRealVar *)poi.first())->setVal( 10 );
	pPoiAndNuisance->add( poi );
	bHypo.SetSnapshot(*pPoiAndNuisance);

	pPoiAndNuisance = new RooArgSet( "poiAndNuisance" );
	((RooRealVar *)poi.first())->setVal( 400 );
	pPoiAndNuisance->add( poi );
	sbHypo.SetSnapshot(*pPoiAndNuisance);

  	ModelConfig* sbModel = &sbHypo;
  	ModelConfig* bModel = &bHypo;

	// print some check
	//sbModel->Print();
	cout<<sbModel->GetObservables()->getSize()<<endl;
	cout<<sbModel->GetNuisanceParameters()<<endl;

//    ProfileLikelihoodTestStat::SetAlwaysReuseNLL(true);
//    RatioOfProfiledLikelihoodsTestStat::SetAlwaysReuseNLL(true);

	// part 1, hypothesis testing
	ProfileLikelihoodTestStat * profll = new ProfileLikelihoodTestStat(*bModel->GetPdf());

	RatioOfProfiledLikelihoodsTestStat * ropl = new RatioOfProfiledLikelihoodsTestStat(*bModel->GetPdf(), *sbModel->GetPdf(), sbModel->GetSnapshot());
	ropl->SetSubtractMLE(false);

	if (testStatType == 3) profll->SetOneSidedDiscovery(1);
	profll->SetPrintLevel(printLevel);

	AsymptoticCalculator::SetPrintLevel(printLevel);

	HypoTestCalculatorGeneric *  hypoCalc = 0;
	// note here Null is B and Alt is S+B
	if (calcType == 0) hypoCalc = new  FrequentistCalculator(*data, *sbModel, *bModel);
	else if (calcType == 1) hypoCalc= new  HybridCalculator(*data, *sbModel, *bModel);

	if (calcType == 0) 
		((FrequentistCalculator*)hypoCalc)->SetToys(ntoys, ntoys/nToysRatio);
	if (calcType == 1) 
		((HybridCalculator*)hypoCalc)->SetToys(ntoys, ntoys/nToysRatio);

	ToyMCSampler * sampler = (ToyMCSampler *)hypoCalc->GetTestStatSampler();
		// set the test statistic
		if (testStatType == 1) sampler->SetTestStatistic(ropl); 
		if (testStatType == 2 || testStatType == 3) sampler->SetTestStatistic(profll); 

	HypoTestResult *  htr = hypoCalc->GetHypoTest();
//return;
	htr->SetPValueIsRightTail(true);
	htr->SetBackgroundAsAlt(false);
	htr->Print(); // how to get meaningfull CLs at this point?

	delete sampler;
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

	if(ispp) c->SaveAs("pp_result.pdf");
	else c->SaveAs("PbPb_result.pdf");
}
