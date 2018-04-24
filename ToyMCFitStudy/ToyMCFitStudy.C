/////////////////////////////////////////////////////////////////////////
//
// 'VALIDATION AND MC STUDIES' RooFit tutorial macro #801
// 
// A Toy Monte Carlo study that perform cycles of
// event generation and fittting
//
// 
/////////////////////////////////////////////////////////////////////////

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooMCStudy.h"
#include "RooPlot.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH2.h"
#include "RooFitResult.h"
#include "TStyle.h"
#include "TDirectory.h"

#include "RooWorkspace.h"
#include "RooPolynomial.h"
#include "RooGenericPdf.h"
#include "RooHist.h"
#include "TFile.h"
#include "TF1.h"
#include "TF2.h"
#include "TGraphAsymmErrors.h"
#include "TLatex.h"

using namespace RooFit ;
using namespace std;

TString npfit = "";
void RunTheCode(bool ispp = 1, int _count = 1, int varSet = 1);
void ToyMCFitStudy(){
	int varSet = 1;
//	varSet = 2;
//	varSet = 3;
//	varSet = 4;
	varSet = 5;
	RunTheCode(1, 1, varSet);
	RunTheCode(1, 2, varSet);
	RunTheCode(0, 1, varSet);
	RunTheCode(0, 2, varSet);
}

void RunTheCode(bool ispp, int _count, int varSet)
{
	gStyle->SetOptStat(0);
	//gStyle->SetOptFit(0);
	gStyle->SetStatW(0.3);                
	// Set width of stat-box (fraction of pad size)
	gStyle->SetStatH(0.2);                
	// Set height of stat-box (fraction of pad size)
	gStyle->SetTitleX(0.5);

	npfit = "1.238105*TMath::Gaus(Bmass,5.067665,0.015902)/(sqrt(2*3.14159)*0.015902)+30.054860*TMath::Erf((Bmass-5.142158)/-0.114983)+30.054860+10.468093*(0.390932*TMath::Gaus(Bmass,5.375549,0.166548)/(sqrt(2*3.14159)*0.166548)+(1-0.390932)*TMath::Gaus(Bmass,5.375549,0.040095)/(sqrt(2*3.14159)*0.040095))";
	if(!ispp) npfit = "1.299998*TMath::Gaus(Bmass,6.099828,-0.242801)/(sqrt(2*3.14159)*-0.242801)+8.186179*TMath::Erf((Bmass-5.000000)/-0.205218)+8.186179+1.263652*(0.426611*TMath::Gaus(Bmass,5.383307,0.249980)/(sqrt(2*3.14159)*0.249980)+(1-0.426611)*TMath::Gaus(Bmass,5.383307,0.037233)/(sqrt(2*3.14159)*0.037233))";
	TString colsys = "pp";
	if(!ispp) colsys = "PbPb";
	//get from input
	TString inputdata = "hPtSpectrumSaveHistBplusPP_roofit.root";
	if(!ispp) inputdata = "hPtSpectrumSaveHistBplusPbPb_roofit.root";
	TFile* inf = new TFile(inputdata.Data());
	RooWorkspace* inputw = new RooWorkspace();
	inputw = (RooWorkspace*)inf->Get("w");	

	double meanVal = inputw->var(Form("mean%d",_count))->getVal();
	double sigma1Val = inputw->var(Form("sigma1%d",_count))->getVal();
	double sigma2Val = inputw->var(Form("sigma2%d",_count))->getVal();
	double sig1fracVal = inputw->var(Form("sig1frac%d",_count))->getVal();
	double a0Val = inputw->var(Form("a0%d",_count))->getVal();
	double a1Val = inputw->var(Form("a1%d",_count))->getVal();
	//double a2Val = inputw->var(Form("a2%d",_count))->getVal();
	double nsigVal = inputw->var(Form("nsig%d",_count))->getVal();
	double nbkgVal = inputw->var(Form("nbkg%d",_count))->getVal();
	//double npeakbgVal = inputw->var(Form("npeakbg%d",_count))->getVal();
	double meanError = inputw->var(Form("mean%d",_count))->getError();
	double sigma1Error = inputw->var(Form("sigma1%d",_count))->getError();
	double sigma2Error = inputw->var(Form("sigma2%d",_count))->getError();
	double sig1fracError = inputw->var(Form("sig1frac%d",_count))->getError();
	double a0Error = inputw->var(Form("a0%d",_count))->getError();
	double a1Error = inputw->var(Form("a1%d",_count))->getError();
	//double a2Error = inputw->var(Form("a2%d",_count))->getError();
	double nsigError = inputw->var(Form("nsig%d",_count))->getError();
	double nbkgError = inputw->var(Form("nbkg%d",_count))->getError();
	//double npeakbgError = inputw->var(Form("npeakbg%d",_count))->getError();

	double parWidth = 1.0;
	printf("%f %f %f\n",meanVal,meanVal-parWidth*meanError,meanVal+parWidth*meanError);
	printf("%f %f %f\n",sigma1Val,sigma1Val-parWidth*sigma1Error,sigma1Val+parWidth*sigma1Error);
	printf("%f %f %f\n",sigma2Val,sigma2Val-parWidth*sigma2Error,sigma2Val+parWidth*sigma2Error);
	printf("%f %f %f\n",sig1fracVal,sig1fracVal-parWidth*sig1fracError,sig1fracVal+parWidth*sig1fracError);
	printf("%f %f %f\n",a0Val,a0Val-parWidth*a0Error,a0Val+parWidth*a0Error);
	printf("%f %f %f\n",a1Val,a1Val-parWidth*a1Error,a1Val+parWidth*a1Error);
	//printf("%f %f %f\n",a2Val,a2Val-parWidth*a2Error,a2Val+parWidth*a2Error);
	printf("%f %f %f\n",nsigVal,nsigVal-parWidth*nsigError,nsigVal+parWidth*nsigError);
	printf("%f %f %f\n",nbkgVal,nbkgVal-parWidth*nbkgError,nbkgVal+parWidth*nbkgError);
	//printf("%f %f %f\n",npeakbgVal,npeakbgVal-parWidth*npeakbgError,npeakbgVal+parWidth*npeakbgError);
	//return;

	RooRealVar mass("Bmass","Bmass",5,6); mass.setBins(50);
	RooRealVar mean(Form("mean%d",_count),"",meanVal,5.,6.) ;
	RooRealVar sigma1(Form("sigma1%d",_count),"",sigma1Val,0.01,0.1) ;
	RooRealVar sigma2(Form("sigma2%d",_count),"",sigma2Val,0.01,0.1) ;
	RooGaussian sig1(Form("sig1%d",_count),"",mass,mean,sigma1);
	RooGaussian sig2(Form("sig2%d",_count),"",mass,mean,sigma2);
	RooRealVar sig1frac(Form("sig1frac%d",_count),"",sig1fracVal,0.,1.);
	RooAddPdf sig(Form("sig%d",_count),"",RooArgList(sig1,sig2),sig1frac);
	RooRealVar a0(Form("a0%d",_count),"",a0Val,0,1e6);
	RooRealVar a1(Form("a1%d",_count),"",a1Val,-1e4,1e4);
	//RooRealVar a2(Form("a2%d",_count),"",a2Val,-1e4,1e4);
	//RooPolynomial bkg(Form("bkg%d",_count),"",mass,RooArgSet(a0,a1,a2));
	RooPolynomial bkg(Form("bkg%d",_count),"",mass,RooArgSet(a0,a1));
	//RooGenericPdf peakbg(Form("peakbg%d",_count),"",Form("(%s)",npfit.Data()),RooArgSet(mass));
	RooRealVar nsig(Form("nsig%d",_count),"",nsigVal,0,1e8);
	RooRealVar nbkg(Form("nbkg%d",_count),"",nbkgVal,0,1e5);
	//RooRealVar npeakbg(Form("npeakbg%d",_count),"",npeakbgVal,0,1e5);
	//RooAddPdf model(Form("model%d",_count),"",RooArgList(bkg,sig,peakbg),RooArgList(nbkg,nsig,npeakbg));
	RooAddPdf model(Form("model%d",_count),"",RooArgList(bkg,sig),RooArgList(nbkg,nsig));
	sigma1.setConstant();
	sigma2.setConstant();
	sig1frac.setConstant();

	TCanvas *c1 = new TCanvas("c1","c1",600,600);
	RooPlot* frame = mass.frame(Title(Form("%s_PDF", colsys.Data())));
	model.plotOn(frame,Name(Form("model%d",_count)),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineColor(2),LineWidth(4));
	frame->Draw();

	// C r e a t e   m o d e l
	// -----------------------

	// Declare observable x
	//	RooRealVar x("x","x",0,10) ;
	//	x.setBins(40) ;
	//
	//	// Create two Gaussian PDFs g1(x,mean1,sigma) anf g2(x,mean2,sigma) and their parameters
	//	RooRealVar mean("mean","mean of gaussians",5,0,10) ;
	//	RooRealVar sigma1("sigma1","width of gaussians",0.5) ;
	//	RooRealVar sigma2("sigma2","width of gaussians",1) ;
	//
	//	RooGaussian sig1("sig1","Signal component 1",x,mean,sigma1) ;  
	//	RooGaussian sig2("sig2","Signal component 2",x,mean,sigma2) ;  
	//
	//	// Build Chebychev polynomial p.d.f.  
	//	RooRealVar a0("a0","a0",0.5,0.,1.) ;
	//	RooRealVar a1("a1","a1",-0.2,-1,1.) ;
	//	RooChebychev bkg("bkg","Background",x,RooArgSet(a0,a1)) ;
	//
	//	// Sum the signal components into a composite signal p.d.f.
	//	RooRealVar sig1frac("sig1frac","fraction of component 1 in signal",0.8,0.,1.) ;
	//	RooAddPdf sig("sig","Signal",RooArgList(sig1,sig2),sig1frac) ;
	//
	//	// Sum the composite signal and background 
	//	RooRealVar nbkg("nbkg","number of background events,",150,0,1000) ;
	//	RooRealVar nsig("nsig","number of signal events",150,0,1000) ;
	//	RooAddPdf  model("model","g1+g2+a",RooArgList(bkg,sig),RooArgList(nbkg,nsig)) ;

	// C r e a t e   m a n a g e r
	// ---------------------------

	// Instantiate RooMCStudy manager on model with x as observable and given choice of fit options
	//
	// The Silence() option kills all messages below the PROGRESS level, leaving only a single message
	// per sample executed, and any error message that occur during fitting
	//
	// The Extended() option has two effects: 
	//    1) The extended ML term is included in the likelihood and 
	//    2) A poisson fluctuation is introduced on the number of generated events 
	//
	// The FitOptions() given here are passed to the fitting stage of each toy experiment.
	// If Save() is specified, the fit result of each experiment is saved by the manager  
	//
	// A Binned() option is added in this example to bin the data between generation and fitting
	// to speed up the study at the expemse of some precision

	//RooMCStudy* mcstudy = new RooMCStudy(model,mass,Binned(0),Silence(),Extended(),
	RooMCStudy* mcstudy = new RooMCStudy(model,mass,Binned(),Silence(),Extended(),
			FitOptions(Save(kTRUE),PrintEvalErrors(0))) ;


	// G e n e r a t e   a n d   f i t   e v e n t s
	// ---------------------------------------------

	// Generate and fit 1000 samples of Poisson(nExpected) events
	mcstudy->generateAndFit(5000) ;



	// E x p l o r e   r e s u l t s   o f   s t u d y 
	// ------------------------------------------------

	// Make plots of the distributions of mean, the error on mean and the pull of mean
	RooRealVar* target = new RooRealVar();
	RooPlot* frame1 = new RooPlot();
	RooPlot* frame2 = new RooPlot();
	RooPlot* frame3 = new RooPlot();
	RooPlot* frame4 = new RooPlot();
	TString postfix = "";
	TString title = "";
	if(_count == 1) postfix += "_7_15";
	if(_count == 2) postfix += "_15_50";
	
	if(varSet==1){
		title = "signal Gauss mean";
		postfix += "_mean";
		target = &mean;
		frame1 = mcstudy->plotParam(*target,Bins(50),Range(5.345,5.390)) ;
		frame3 = mcstudy->plotPull(*target,Bins(50),FitGauss(),Range(-8,8)) ;
		frame4 = mcstudy->plotNLL(Bins(50)) ;
		if(ispp)
		    frame2 = mcstudy->plotError(*target,Bins(50),Range(0.000,0.0035)) ;
		else
		    frame2 = mcstudy->plotError(*target,Bins(50),Range(0.000,0.020)) ;
	}
	if(varSet==2){
		title = "bg 0th order coeff";
		postfix += "_a0";
		target = &a0;
		if(ispp){
			frame1 = mcstudy->plotParam(*target,Bins(50),Range(950.,1100.)) ;
			frame2 = mcstudy->plotError(*target,Bins(50)) ;
			frame3 = mcstudy->plotPull(*target,Bins(50),FitGauss()) ;
		}
		else{
			if(_count==1){
				frame1 = mcstudy->plotParam(*target,Bins(50),Range(0.,200000.)) ;
				frame2 = mcstudy->plotError(*target,Bins(50),Range(0.,1200000.)) ;
				frame2 = mcstudy->plotError(*target,Bins(50)) ;
				frame3 = mcstudy->plotPull(*target,Bins(50),FitGauss(),Range(-1,0.3)) ;
			}
			else{
				frame1 = mcstudy->plotParam(*target,Bins(50),Range(500.,1500.)) ;
				frame2 = mcstudy->plotError(*target,Bins(50),Range(-200.,4000.)) ;
				frame3 = mcstudy->plotPull(*target,Bins(50),FitGauss(),Range(-0.15,0.05)) ;
			}
		}
		frame4 = mcstudy->plotNLL(Bins(50)) ;
	}
	if(varSet==3){
		title = "bg 1st order coeff";
		postfix += "_a1";
		target = &a1;
		if(ispp){
			frame1 = mcstudy->plotParam(*target,Bins(50)) ;
			frame2 = mcstudy->plotError(*target,Bins(50)) ;
			frame3 = mcstudy->plotPull(*target,Bins(50),FitGauss()) ;
			frame4 = mcstudy->plotNLL(Bins(50)) ;
		}
		else{
			if(_count==1){
				frame1 = mcstudy->plotParam(*target,Bins(50)) ;
				frame2 = mcstudy->plotError(*target,Bins(50)) ;
				frame3 = mcstudy->plotPull(*target,Bins(50),FitGauss(),Range(-0.2,1.8)) ;
				frame4 = mcstudy->plotNLL(Bins(50)) ;
			}
			else{
				frame1 = mcstudy->plotParam(*target,Bins(50),Range(-140.,-120.)) ;
				frame2 = mcstudy->plotError(*target,Bins(50),Range(-100.,18000.)) ;
				frame3 = mcstudy->plotPull(*target,Bins(50),FitGauss(),Range(-0.1,0.2)) ;
				frame4 = mcstudy->plotNLL(Bins(50)) ;
			}
		}
	}
	if(varSet==4){
		title = "# of signal";
		postfix += "_nsig";
		target = &nsig;
		frame1 = mcstudy->plotParam(*target,Bins(50)) ;
		frame2 = mcstudy->plotError(*target,Bins(50)) ;
		if(ispp)
			frame2 = mcstudy->plotError(*target,Bins(50)) ;
		else
			frame2 = mcstudy->plotError(*target,Bins(50),Range(0.,6.)) ;
		frame3 = mcstudy->plotPull(*target,Bins(50),FitGauss()) ;
		frame4 = mcstudy->plotNLL(Bins(50)) ;
	}
	if(varSet==5){
		title = "# of background";
		postfix += "_nbkg";
		target = &nbkg;
		frame1 = mcstudy->plotParam(*target,Bins(50)) ;
		frame2 = mcstudy->plotError(*target,Bins(50)) ;
		frame3 = mcstudy->plotPull(*target,Bins(50),FitGauss()) ;
		frame4 = mcstudy->plotNLL(Bins(50)) ;
	}
	
	// Do customize fit
	bool doCusFit = 0;
	TF1* f;
	if(doCusFit){
		RooHist* datahist = new RooHist();
		cout<<frame3->getHist(Form("h_fitParData_model%d",_count))<<endl;
		datahist = frame3->getHist(Form("h_fitParData_model%d",_count));
		TGraphAsymmErrors* datagraph = static_cast<TGraphAsymmErrors*>(datahist);
		datagraph->SetTitle("");
		datagraph->GetXaxis()->SetTitle("Pull");
		f = new TF1("f","[0]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])");
		f->SetParName(1,"mean");
		f->SetParName(2,"width");
		f->SetParLimits(8,0.01,0.1);
		f->SetParLimits(7,0,1);
		f->SetParameter(0,10);
		f->SetParameter(1,0);
		f->SetParameter(2,1);
		//f->SetParLimits(0,0,1e2);
		f->SetParLimits(1,-5,5);
		f->SetParLimits(2,0,5);
		f->SetLineWidth(4);
		//datagraph->Fit("f");
		frame3->SetMaximum(datagraph->GetHistogram()->GetMaximum()*1.3);
	}

	// plot setting
	frame1->SetTitle(title.Data());
	frame2->SetTitle("");
	frame3->SetTitle("");
	frame4->SetTitle("");
	frame1->GetXaxis()->SetTitle("mean");
	frame2->GetXaxis()->SetTitle("Error");
	frame3->GetXaxis()->SetTitle("Pull");
	frame1->GetYaxis()->SetTitle("Entries");
	frame2->GetYaxis()->SetTitle("Entries");
	frame3->GetYaxis()->SetTitle("Entries");
	frame4->GetYaxis()->SetTitle("Entries");
	frame1->GetXaxis()->SetNdivisions(505);
	frame2->GetXaxis()->SetNdivisions(505);
	frame3->GetXaxis()->SetNdivisions(505);
	frame4->GetXaxis()->SetNdivisions(505);

	// Draw all plots on a canvas
	gStyle->SetPalette(1) ;
	gStyle->SetOptStat(0) ;
	TCanvas* c = new TCanvas("rf801_mcstudy","rf801_mcstudy",900,900) ;
	c->SetRightMargin(0.3);
	c->Divide(2,2) ;
	//gPad->SetLogy();
	c->cd(1) ; gPad->SetLeftMargin(0.153) ; gPad->SetRightMargin(0.12) ; frame1->GetYaxis()->SetTitleOffset(1.35) ; frame1->Draw() ;
	//gPad->SetLogy();
	c->cd(2) ; gPad->SetLeftMargin(0.153) ; gPad->SetRightMargin(0.12) ; frame2->GetYaxis()->SetTitleOffset(1.35) ; frame2->Draw() ;
	//gPad->SetLogy();
	c->cd(3) ; gPad->SetLeftMargin(0.153) ; gPad->SetRightMargin(0.12) ; frame3->GetYaxis()->SetTitleOffset(1.35) ; frame3->Draw() ;
	if(doCusFit) f->Draw("same");// Draw cugstomized fit function
	//gPad->SetLogy();
	c->cd(4) ; gPad->SetLeftMargin(0.153) ; gPad->SetRightMargin(0.12) ; frame4->GetYaxis()->SetTitleOffset(1.35) ; frame4->Draw() ;

	// Make some histograms from the parameter dataset
	//TH1* hh_cor_a0_s1f = mcstudy->fitParDataSet().createHistogram("hh",a1,YVar(sig1frac)) ;
	//TH1* hh_cor_a0_a1  = mcstudy->fitParDataSet().createHistogram("hh",a0,YVar(a1)) ;

	// Access some of the saved fit results from individual toys
	//TH2* corrHist000 = mcstudy->fitResult(0)->correlationHist("c000") ;
	//TH2* corrHist127 = mcstudy->fitResult(127)->correlationHist("c127") ;
	//TH2* corrHist953 = mcstudy->fitResult(953)->correlationHist("c953") ;

	// Make RooMCStudy object available on command line after
	// macro finishes
	gDirectory->Add(mcstudy) ;
	c1->SaveAs(Form("PDF_%s%s.pdf",colsys.Data(),postfix.Data()));
	c->SaveAs(Form("results_%s%s.pdf",colsys.Data(),postfix.Data()));
}
