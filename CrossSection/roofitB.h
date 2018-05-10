#include "uti.h"
#include "parameters.h"
#include "RooWorkspace.h"
#include "RooGlobalFunc.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooGenericPdf.h"
#include "RooChebychev.h"
#include "RooPolynomial.h"
#include "RooAddPdf.h"
#include "RooExtendPdf.h"
#include "RooPlot.h"
#include "RooFitResult.h"
#include "RooChi2Var.h"
#include "RooHist.h"
using namespace RooFit;
using namespace std;

#define BSUBS_MASS 5.36682

void clean0 (TH1D* h);
int    drawOpt=0;
double _ErrCor=1;

double setparam0=100.;
double setparam2=0.02;
double setparam3=0.06;
double fixparam1=BSUBS_MASS;

double minhisto=5.00;
double maxhisto=6.00;
int nbinsmasshisto=50;
double binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString seldata;
TString selmc;
TString selmcgen;
TString collisionsystem;
Float_t hiBinMin,hiBinMax,centMin,centMax;
Int_t _count=0;
RooWorkspace* inputw = new RooWorkspace();
RooWorkspace* outputw = new RooWorkspace("w");

RooFitResult *fit(TCanvas* c, TCanvas* cMC, RooDataSet* ds, RooDataSet* dsMC, RooDataHist* dh, RooDataHist* dhMC, RooRealVar* mass, RooPlot* &outframe, Double_t ptmin, Double_t ptmax, int isMC, bool isPbPb, Float_t centmin, Float_t centmax, TString npfit)
{
	cout<<"total data: "<<ds->numEntries()<<endl;
	TH1* h = dh->createHistogram("Bmass");
	h->Sumw2(kFALSE);
	h->SetBinErrorOption(TH1::kPoisson);
	h->SetMarkerSize(1.55);
	h->SetMarkerStyle(20);
	h->SetLineColor(1);
	h->SetLineWidth(4);
	RooPlot* frameMC = mass->frame(Title(""));
	frameMC->SetTitle("");
	//frameMC->SetXTitle("m_{B} (GeV/c^{2})");
	frameMC->SetXTitle("m_{J/#psi(#mu#mu)#phi(KK)} (GeV/c^{2})");
	frameMC->SetYTitle("Events / (20 MeV/c^{2})");
	frameMC->GetXaxis()->CenterTitle();
	frameMC->GetYaxis()->CenterTitle();
	frameMC->GetXaxis()->SetTitleOffset(1.0);
	frameMC->GetYaxis()->SetTitleOffset(1.4);
	frameMC->GetXaxis()->SetTitleSize(0.055);
	frameMC->GetYaxis()->SetTitleSize(0.055);
	frameMC->GetXaxis()->SetTitleFont(42);
	frameMC->GetYaxis()->SetTitleFont(42);
	frameMC->GetXaxis()->SetLabelFont(42);
	frameMC->GetYaxis()->SetLabelFont(42);
	frameMC->GetXaxis()->SetLabelSize(0.055);
	frameMC->GetYaxis()->SetLabelSize(0.055);
	frameMC->SetStats(0);
	frameMC->GetXaxis()->SetNdivisions(-50205);
	RooPlot* frame = (RooPlot*)frameMC->Clone();

	cMC->cd();
	RooRealVar meanMC(Form("meanMC%d",_count),"",BSUBS_MASS,5.,6.) ;
	RooRealVar sigma1MC(Form("sigma1MC%d",_count),"",0.02,0.01,0.1) ;
	RooRealVar sigma2MC(Form("sigma2MC%d",_count),"",0.06,0.01,0.1) ;
	RooGaussian sig1MC(Form("sig1MC%d",_count),"",*mass,meanMC,sigma1MC);  
	RooGaussian sig2MC(Form("sig2MC%d",_count),"",*mass,meanMC,sigma2MC);  
	RooRealVar sig1fracMC(Form("sig1fracMC%d",_count),"",0.5,0.,1.);
	RooAddPdf sigMC(Form("sigMC%d",_count),"",RooArgList(sig1MC,sig2MC),sig1fracMC);
	RooRealVar a0MC(Form("a0MC%d",_count),"",0,0,1e6);
	RooRealVar a1MC(Form("a1MC%d",_count),"",0,-1e4,1e4);
	RooRealVar a2MC(Form("a2MC%d",_count),"",0,-1e4,1e4);
	//RooPolynomial bkgMC(Form("bkgMC%d",_count),"",*mass,RooArgSet(a0MC,a1MC,a2MC));//2nd order poly
	RooPolynomial bkgMC(Form("bkgMC%d",_count),"",*mass,RooArgSet(a0MC,a1MC));//linear
	RooRealVar nsigMC(Form("nsigMC%d",_count),"",1,0,1e8);
	RooRealVar nbkgMC(Form("nbkgMC%d",_count),"",0,0,1e5);
	RooAddPdf* modelMC = new RooAddPdf(Form("modelMC%d",_count),"",RooArgList(sigMC),RooArgList(nsigMC));
	//RooAddPdf* modelMC = new RooAddPdf(Form("modelMC%d",_count),"",RooArgList(bkgMC,sigMC),RooArgList(nbkgMC,nsigMC));
	RooFitResult* fitResultMC = modelMC->fitTo(*dsMC,Save());
	dsMC->plotOn(frameMC,Name(Form("dsMC%d",_count)),Binning(nbinsmasshisto),MarkerSize(1.55),MarkerStyle(20),LineColor(1),LineWidth(4));
	modelMC->plotOn(frameMC,Name(Form("bkgMC%d",_count)),Components(bkgMC),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineStyle(7),LineColor(4),LineWidth(4));
	modelMC->plotOn(frameMC,Name(Form("sigMC%d",_count)),Components(sigMC),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
	modelMC->plotOn(frameMC,Name(Form("sigFMC%d",_count)),Components(sigMC),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("F"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
	modelMC->plotOn(frameMC,Name(Form("modelMC%d",_count)),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineColor(2),LineWidth(4));
	dsMC->plotOn(frameMC,Name(Form("dsMC%d",_count)),Binning(nbinsmasshisto),MarkerSize(1.55),MarkerStyle(20),LineColor(1),LineWidth(4));
	frameMC->Draw();
    cMC->RedrawAxis();

	c->cd();
	RooRealVar mean(Form("mean%d",_count),"",meanMC.getVal(),5.,6.) ;
	RooRealVar sigma1(Form("sigma1%d",_count),"",sigma1MC.getVal(),0.01,0.1) ;
	RooRealVar sigma2(Form("sigma2%d",_count),"",sigma2MC.getVal(),0.01,0.1) ;
	RooGaussian sig1(Form("sig1%d",_count),"",*mass,mean,sigma1);  
	RooGaussian sig2(Form("sig2%d",_count),"",*mass,mean,sigma2);  
	RooRealVar sig1frac(Form("sig1frac%d",_count),"",sig1fracMC.getVal(),0.,1.);
	RooAddPdf sig(Form("sig%d",_count),"",RooArgList(sig1,sig2),sig1frac);
	//RooRealVar a0(Form("a0%d",_count),"a0",0.1,0.,1.);
	//RooRealVar a1(Form("a1%d",_count),"a1",0.1,0.,1.);
	//RooRealVar a2(Form("a2%d",_count),"a2",0.1,0.,1.);
	//RooChebychev bkg(Form("bkg%d",_count),"",*mass,RooArgSet(a0,a1,a2));
	RooRealVar a0(Form("a0%d",_count),"",1e3,0,1e6);
	RooRealVar a1(Form("a1%d",_count),"",1e0,-1e4,1e4);
	RooRealVar a2(Form("a2%d",_count),"",1e0,-1e4,1e4);
	//RooPolynomial bkg(Form("bkg%d",_count),"",*mass,RooArgSet(a0,a1,a2));//2nd orderpoly
	RooPolynomial bkg(Form("bkg%d",_count),"",*mass,RooArgSet(a0,a1));//linear
	RooGenericPdf peakbg(Form("peakbg%d",_count),"",Form("(%s)",npfit.Data()),RooArgSet(*mass));
	RooRealVar nsig(Form("nsig%d",_count),"",1,0,1e8);
	RooRealVar nbkg(Form("nbkg%d",_count),"",1,0,1e5);
	RooRealVar npeakbg(Form("npeakbg%d",_count),"",1,0,1e5);
	RooAddPdf* model = new RooAddPdf(Form("model%d",_count),"",RooArgList(bkg,sig),RooArgList(nbkg,nsig));
	if(npfit != "1") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(bkg,sig,peakbg),RooArgList(nbkg,nsig,npeakbg));
	//mean.setConstant();
	sigma1.setConstant();
	sigma2.setConstant();
	sig1frac.setConstant();
	RooFitResult* fitResult = model->fitTo(*ds,Save());
	//RooFitResult* fitResult = model->fitTo(*ds,Save(),Minos());

	//ds->plotOn(frame,Name(Form("ds%d",_count)),Binning(nbinsmasshisto),MarkerSize(1.55),MarkerStyle(20),LineColor(1),LineWidth(4));
	ds->plotOn(frame,Name(Form("ds%d",_count)),Binning(nbinsmasshisto),MarkerSize(1.55),MarkerStyle(20),MarkerColor(0),LineColor(1),LineWidth(4),LineColor(0));//draw an transparent hist
	if(npfit != "1") model->plotOn(frame,Name(Form("peakbg%d",_count)),Components(peakbg),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),FillStyle(3005),FillColor(kGreen+4),LineStyle(1),LineColor(kGreen+4),LineWidth(4));
	if(npfit != "1") model->plotOn(frame,Name(Form("peakbgF%d",_count)),Components(peakbg),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("F"),FillStyle(3005),FillColor(kGreen+4),LineStyle(1),LineColor(kGreen+4),LineWidth(4));
	model->plotOn(frame,Name(Form("bkg%d",_count)),Components(bkg),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineStyle(7),LineColor(4),LineWidth(4));
	model->plotOn(frame,Name(Form("sig%d",_count)),Components(sig),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
	model->plotOn(frame,Name(Form("sigF%d",_count)),Components(sig),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("F"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
	model->plotOn(frame,Name(Form("model%d",_count)),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineColor(2),LineWidth(4));
	//ds->plotOn(frame,Name(Form("ds%d",_count)),Binning(nbinsmasshisto),MarkerSize(1.55),MarkerStyle(20),LineColor(1),LineWidth(4));
	//frame->SetMaximum(h->GetBinContent(h->GetMaximumBin())*1.8);
	frame->SetMaximum((h->GetBinContent(h->GetMaximumBin())+h->GetBinError(h->GetMaximumBin()))*1.8);
	frame->Draw();
	h->Draw("same e");
    c->RedrawAxis();

	mass->setRange("signal",5,6);
	RooAbsReal* sigIntegral = sig.createIntegral(*mass,NormSet(*mass),Range("signal"));
	double sigIntegralErr = sigIntegral->getPropagatedError(*fitResult);
	RooAbsReal* bkgIntegral = bkg.createIntegral(*mass,NormSet(*mass),Range("signal"));
	double bkgIntegralErr = bkgIntegral->getPropagatedError(*fitResult);

	cout<<"nsig: "<<nsig.getVal()<<endl;
	//cout<<"nsig: "<<model->getParameters(*mass)->getRealValue("nsig")<<endl;
	cout<<"nsig error: "<<nsig.getError()<<endl;
	cout<<"sig integral: "<<sigIntegral->getVal()<<endl;
	cout<<"sig integral error: "<<sigIntegralErr<<endl;
	cout<<"nbkg: "<<nbkg.getVal()<<endl;
	//cout<<"nbkg: "<<model->getParameters(*mass)->getRealValue("nbkg")<<endl;
	cout<<"nbkg error: "<<nbkg.getError()<<endl;
	cout<<"bkg integral: "<<bkgIntegral->getVal()<<endl;
	cout<<"bkg integral error: "<<bkgIntegralErr<<endl;
	//cout<<"#expected events: "<<model->expectedEvents(RooArgSet(*mass))<<endl;
	//cout<<"model integral: "<<model->getNormIntegral(RooArgSet(*mass))->getVal()<<endl;
	//fitResult->Print("v");

	//RooHist* datahist = new RooHist();
	//datahist = frame->getHist("ds");
	//TGraphAsymmErrors* datagraph = static_cast<TGraphAsymmErrors*>(datahist);
	//RooCurve* modelcurve = new RooCurve();
	//modelcurve = frame->getCurve("model");

	Double_t yield = nsig.getVal();
	Double_t yieldErr = nsig.getError();
    TH1D* fh = (TH1D*)h->Clone("fh");
	double nexpected = model->expectedEvents(RooArgSet(*mass));
    double dataArr[nbinsmasshisto]; double dataErrArr[nbinsmasshisto]; double fitArr[nbinsmasshisto];
	double val = 0;
    for(int i = 0; i < nbinsmasshisto; i++){
        dataArr[i] = h->GetBinContent(i+1);
        dataErrArr[i] = h->GetBinError(i+1);
		mass->setVal(h->GetBinCenter(i+1));
		val = model->getVal(RooArgSet(*mass))*1./nbinsmasshisto*nexpected;
        fitArr[i] = val;
        fh->SetBinContent(i+1, fitArr[i]);
        fh->SetBinError(i+1, sqrt(fitArr[i]));
    }
	cout<<"frame->chiSquare: "<<frame->chiSquare(Form("model%d",_count),Form("ds%d",_count),0)<<endl;
	//cout<<fitResult->floatParsFinal().getSize()<<endl;
	//cout<<"chi2: "<<frame->chiSquare(Form("model%d",_count),Form("ds%d",_count),fitResult->floatParsFinal().getSize())<<endl;
	//RooChi2Var chi2_lowstat("chi2_lowstat","chi2",*model,*dh);
	//cout<<chi2_lowstat.getVal()<<endl;
    double chi2Std = 0;
    double chi2Neyman = 0;
    double chi2Peason = 0;
    double chi2BakerCousins = 0;
    chi2Cal(dataArr, dataErrArr, fitArr, nbinsmasshisto, chi2Std, chi2Neyman, chi2Peason, chi2BakerCousins);
    printf("chi2 Standard: %f\n",chi2Std);
    printf("chi2 Neyman: %f\n",chi2Neyman);
    printf("chi2 Peason: %f\n",chi2Peason);
    printf("chi2 Baker & Cousins: %f\n",chi2BakerCousins);

	TLegend *leg = new TLegend(0.525,0.40,0.85,0.75,NULL,"brNDC"); 
    if(drawOpt == 1) {
		leg = new TLegend(0.525,0.57,0.85,0.80,NULL,"brNDC");
	}
	leg->SetBorderSize(0);
	leg->SetTextSize(0.055);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	//leg->AddEntry(frame->findObject(Form("ds%d",_count),"Data","pl");
    leg->AddEntry(h,"Data","pl");
	leg->AddEntry(frame->findObject(Form("model%d",_count)),"Fit","l");
	leg->AddEntry(frame->findObject(Form("sig%d",_count)),"Signal","f");
	leg->AddEntry(frame->findObject(Form("bkg%d",_count)),"Combinatorial","l");
	if(npfit != "1") leg->AddEntry(frame->findObject(Form("peakbg%d",_count)),"B #rightarrow J/#psi X","f");

	TLatex* texcms = new TLatex(0.22,0.87,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);
	texcms->SetTextSize(0.075);
	texcms->SetLineWidth(2);
	
	TLatex* texB = new TLatex(0.225,0.74,"B^{0}_{s}");
	texB->SetNDC();
	texB->SetTextFont(42);
	texB->SetTextSize(0.055);
	texB->SetLineWidth(2);

	// preliminary setting
	texcms = new TLatex(0.21,0.88,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);
	texcms->SetTextSize(0.06);
	texcms->SetLineWidth(2);
    TLatex* texpre = new TLatex(0.21,0.83,"Preliminary");
    texpre->SetNDC();
    texpre->SetTextAlign(13);
    texpre->SetTextFont(52);
    texpre->SetTextSize(0.035);
    texpre->SetLineWidth(2);
    TLatex* texsup = new TLatex(0.21,0.795,"Supplementary");
    texsup->SetNDC();
    texsup->SetTextAlign(13);
    texsup->SetTextFont(52);
    texsup->SetTextSize(0.035);
    texsup->SetLineWidth(2);
	texB = new TLatex(0.225,0.68,"B^{0}_{s}");
	texB->SetNDC();
	texB->SetTextFont(62);
	texB->SetTextSize(0.07);
	texB->SetLineWidth(2);
	// preliminary setting

	TLatex* texCol;
	if(collisionsystem=="pp"||collisionsystem=="PP"||collisionsystem=="ppInc"||collisionsystem=="PbPbInc") texCol= new TLatex(0.95,0.94, Form("28.0 pb^{-1} (%s 5.02 TeV)","pp"));
	else texCol= new TLatex(0.945,0.94, Form("351 #mub^{-1} (%s 5.02 TeV)","PbPb"));
	texCol->SetNDC();
	texCol->SetTextAlign(32);
	texCol->SetTextSize(0.055);
	texCol->SetTextFont(42);
	
	int nDOF = nbinsmasshisto-(fitResult->floatParsFinal().getSize());
	float nChi2 = chi2BakerCousins/(nbinsmasshisto-(fitResult->floatParsFinal().getSize()));
	int nDigit_chi2BakerCousins = 2;
	int nDigit_nChi2 = 2;
	chi2BakerCousins = roundToNdigit(chi2BakerCousins);
	nChi2 = roundToNdigit(nChi2);
	nDigit_chi2BakerCousins = sigDigitAfterDecimal(chi2BakerCousins);
	nDigit_nChi2 = sigDigitAfterDecimal(nChi2);
    TLatex* texChi = new TLatex(0.55,0.50, Form("#chi^{2}/nDOF: %.*f/%d = %.*f", nDigit_chi2BakerCousins, chi2BakerCousins, nDOF, nDigit_nChi2, nChi2));
    texChi->SetNDC();
    texChi->SetTextAlign(12);
    texChi->SetTextSize(0.04);
    texChi->SetTextFont(42);

	double width = 0.05;
	double BmassH = BSUBS_MASS + width;
	double BmassL = BSUBS_MASS - width;
	mass->setRange("signal",BmassL,BmassH);
	bkgIntegral = bkg.createIntegral(*mass,NormSet(*mass),Range("signal"));
	bkgIntegralErr = bkgIntegral->getPropagatedError(*fitResult);	
	cout<<"bkg integral: "<<bkgIntegral->getVal()<<endl;
	cout<<"bkg integral error: "<<bkgIntegralErr<<endl;
	Double_t bkgd = nbkg.getVal();
	bkgd = bkgd*bkgIntegral->getVal();
	Double_t SB = yield/bkgd;
	Double_t Significance =  yield/TMath::Sqrt(bkgd+yield);
	int nDigit_Significance = 3;
	Significance = roundToNdigit(Significance);
	nDigit_Significance = sigDigitAfterDecimal(Significance);
	TLatex* texSig = new TLatex(0.55,0.54,Form("Significance = %.*f", nDigit_Significance, Significance));
	cout<<"Significance = "<<Significance<<endl;
	texSig->SetNDC();
	texSig->SetTextFont(42);
	texSig->SetTextSize(0.04);
	texSig->SetLineWidth(2);

	int nDigit_yield = 3;
	yield = roundToNdigit(yield);
	nDigit_yield = sigDigitAfterDecimal(yield);
    TLatex* texYield = new TLatex(0.55,0.44,Form("Yield = %.*f", nDigit_yield, yield));
    texYield->SetNDC();
    texYield->SetTextFont(42);
    texYield->SetTextSize(0.04);
    texYield->SetLineWidth(2);

	cMC->cd();
	leg->Draw("same");
	texcms->Draw();
	texB->Draw();
	c->cd();
	leg->Draw("same");
	texcms->Draw();
	texpre->Draw();
	texsup->Draw();
	texB->Draw();
	texCol->Draw();
    //if(1) {
    if(drawOpt == 1) {
		texChi->Draw();
		texSig->Draw("SAME");
		texYield->Draw("SAME");
	}
	outframe = frame;
    outputw->import(*model);
	return fitResult;
}

void clean0(TH1D* h)
{
	for (int i=1;i<=h->GetNbinsX();i++)
	{
		if(h->GetBinContent(i)==0) h->SetBinError(i,1);
	}
}

double ErrorOnSigma(double width, double errwidth, double smear, double errsmearing){
    double squarederroronsigma=(1+smear)*(1+smear)*errwidth*errwidth+width*width*errsmearing*errsmearing;
    double erroronsigma=TMath::Sqrt(squarederroronsigma);
    return erroronsigma;
}
