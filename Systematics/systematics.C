#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TLine.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TFile.h>
const int nPtBins=1;
double PtBins[nPtBins+1] = {15.,50.};
const int nPtBinsOpt2=4;
double PtBinsOpt2[nPtBinsOpt2+1] = {10.,15.,20.,30.,50.};
// =============================================================================================================
// B meson decay
// =============================================================================================================
double BRUncertainty	= 7.57;// from PDG sqrt((0.08/1.07)^2+(0.033/5.961)^2+(0.5/48.9)^2) = 0.07566508149

// =============================================================================================================
// pp uncertainty
// =============================================================================================================
// Normalization uncertainty
double ppLumiUncertainty = 2.3;     // B+ paper
double ppTrackingEfficiency	= 4*2; // single track systematics from D* studies
double PbPbTrackingEfficiency = 6*2; // from charged particle analysis, paper
double ppAlignment = 2.8;              // alignment systematic from pp 13 TeV analysis
double PbPbAlignment = 2.8;            // alignment systematic from pp 13 TeV analysis
double ppLifetime = 0.3;               // from 13 TeV analysis
double PbPbLifetime = 0.3;             // from 13 TeV analysis
TH1D*  ppSignalExtraction;
TH1D*  ppMesonSelection;
TH1D*  ppTagAndProbe;
TH1D*  ppAccUnc;
TH1D*  ppPtShape;
TFile* ppMCEfffile = new TFile("../CrossSection/ROOTfiles/MCstudiesPP.root");
TH1D* ppEff = (TH1D*)ppMCEfffile->Get("hEff");

// =============================================================================================================
// PbPb uncertainty
// =============================================================================================================
// Normalization uncertainty
double PbPbNMBUncertainty	= 2;		// B+ paper
double TAAUncertainty0to100	= 8.9;	    // B+ paper
double TAAUncertainty0to100HI = 2.8;	// B+ paper 
double TAAUncertainty0to100LO = 3.4;	// B+ paper 
double TAAUncertainty0to10	= 1.7;		// B+ paper
TH1D*  PbPbSignalExtraction;			               
TH1D*  PbPbMesonSelection;				               
TH1D*  PbPbTagAndProbe;				                
TH1D*  PbPbAccUnc;
TH1D*  PbPbPtShape;
TFile* PbPbMCEfffile = new TFile("../CrossSection/ROOTfiles/MCstudiesPbPb.root");
TH1D* PbPbEff = (TH1D*)PbPbMCEfffile->Get("hEff");
// RAA uncertainty, for systematic that can cancel such as PDF variation
TH1D*  RAASignalExtraction;

bool initialized = 0;
void initializationPP(int SysOpt=0)
{
	ppMesonSelection = new TH1D("ppMesonSelection","",nPtBins,PtBins);
	ppMesonSelection->SetBinContent(1, 12.4);

	ppSignalExtraction = new TH1D("ppSignalExtraction","",nPtBins,PtBins);
	ppSignalExtraction->SetBinContent(1, 0.75);

	ppTagAndProbe = new TH1D("ppTagAndProbe","",nPtBins,PtBins); 
	ppAccUnc = new TH1D("ppAccUnc","",nPtBins,PtBins);
	ppPtShape = new TH1D("ppPtShape","",nPtBins,PtBins);
	double tnpUnc_pp[1] = {3.154493, };
	//double tnpUnc_pp[1] = {3.172913, }; // only pthatweight
	double AccUnc_pp[nPtBins] = {2.649775};
	double ptshape_pp[1] = {(1.555731e-01-1.514180e-01)/1.555731e-01*100};
	for(int i = 0; i < nPtBins; i++){
		ppTagAndProbe->SetBinContent(i+1,tnpUnc_pp[i]);
		ppAccUnc->SetBinContent(i+1,AccUnc_pp[i]);
		ppPtShape->SetBinContent(i+1,ptshape_pp[i]);
	}
	if(SysOpt==2){
		ppTagAndProbe = new TH1D("ppTagAndProbeOpt2","",nPtBinsOpt2,PtBinsOpt2); 
		double tnpUnc_ppOpt2[4] = {4.225170, 3.354476, 3.025281, 2.829637, };
		for(int i = 0; i < nPtBinsOpt2; i++){
			ppTagAndProbe->SetBinContent(i+1,tnpUnc_ppOpt2[i]);
		}
	}
}

void initializationPbPbCent0100(int SysOpt=0)
{
	PbPbMesonSelection = new TH1D("PbPbMesonSelection","",nPtBins,PtBins);
	PbPbMesonSelection->SetBinContent(1, 31.1);

	PbPbSignalExtraction = new TH1D("PbPbSignalExtraction","",nPtBins,PtBins);
	PbPbSignalExtraction->SetBinContent(1, 2.4);

	PbPbTagAndProbe = new TH1D("PbPbTagAndProbe","",nPtBins,PtBins);
	PbPbAccUnc = new TH1D("PbPbAccUnc","",nPtBins,PtBins);
	PbPbPtShape = new TH1D("PbPbPtShape","",nPtBins,PtBins);
	double tnpUnc_pbpb[1] = {3.789687, };
	//double tnpUnc_pbpb[1] = {3.818009, }; // only pthatweight
	double AccUnc_PbPb[nPtBins] = {3.012407};
    double ptshape_PbPb[1] = {(4.513338e-02-4.291407e-02)/4.513338e-02*100};
	for(int i = 0; i < nPtBins; i++){
		PbPbTagAndProbe->SetBinContent(i+1,tnpUnc_pbpb[i]);
		PbPbAccUnc->SetBinContent(i+1,AccUnc_PbPb[i]);
		PbPbPtShape->SetBinContent(i+1,ptshape_PbPb[i]);
	}
}

void initializationRAA(int SysOpt=0)
{
	RAASignalExtraction = new TH1D("RAASignalExtraction","",nPtBins,PtBins);
	RAASignalExtraction->SetBinContent(1,	0.5);
}

void initializationPbPbCent010(int SysOpt=0)
{
	PbPbMesonSelection = new TH1D("PbPbMesonSelection","",nPtBins,PtBins);
	PbPbMesonSelection->SetBinContent(1,		0.);

	PbPbSignalExtraction = new TH1D("PbPbSignalExtraction","",nPtBins,PtBins);
	PbPbSignalExtraction->SetBinContent(1,	0.);

	PbPbTagAndProbe = new TH1D("PbPbTagAndProbe","",nPtBins,PtBins);
	PbPbTagAndProbe->SetBinContent(1,		10.0);
}

void initialization(double centL=0,double centH=100,int SysOpt=0){
	initializationPP(SysOpt);
	initializationRAA(SysOpt);
	if (centL==0&&centH==100) initializationPbPbCent0100(SysOpt);
	if (centL==0&&centH==10) initializationPbPbCent010(SysOpt);
	initialized=1;
}

// =============================================================================================================
// RAA systematics
// =============================================================================================================
float normalizationUncertaintyForRAA(bool TAAhi = 1, double centL=0,double centH=100)
{
	double sys = 0;
	sys+=ppLumiUncertainty*ppLumiUncertainty;
	sys+=PbPbNMBUncertainty*PbPbNMBUncertainty;
	if (centL==0&&centH==10) {
		// 0-10%
		sys+=TAAUncertainty0to10*TAAUncertainty0to10;
	} else {
		// 0-100%a
		if(TAAhi == 1)
			sys+=TAAUncertainty0to100LO*TAAUncertainty0to100LO;
		if(TAAhi == 0)
			sys+=TAAUncertainty0to100HI*TAAUncertainty0to100HI;
	}
	return sqrt(sys);
}

float systematicsForRAA(double pt, double centL=0, double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized && centL==0&&centH==100) initialization(centL,centH,SysOpt);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH,SysOpt);

	double sys=0;

	if (pt<7) return 0;
	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	if (stage==1) return sqrt(sys);

	//sys+= RAASignalExtraction->GetBinContent(RAASignalExtraction->FindBin(pt))*
	//      RAASignalExtraction->GetBinContent(RAASignalExtraction->FindBin(pt));
	sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt))*
		PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt));
	sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt))*
		ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt));

	if (stage==2) return sqrt(sys);

	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))*
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))*
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));

	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;

	sys+= ppPtShape->GetBinContent(ppPtShape->FindBin(pt))*
		ppPtShape->GetBinContent(ppPtShape->FindBin(pt));
	sys+= PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt))*
		PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt));

	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	if (stage==3) return sqrt(sys);

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));

	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));
	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));

	return sqrt(sys);
}

float systematicsForRAA_Correlated(double pt, double centL=0, double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized && centL==0&&centH==100) initialization(centL,centH,SysOpt);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH,SysOpt);

	double sys=0;

	if (pt<7) return 0;
	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt))*
		PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt));
	sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt))*
		ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt));

	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))*
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))*
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));

	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	return sqrt(sys);
}

float systematicsForRAA_UnCorrelated(double pt, double centL=0, double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized && centL==0&&centH==100) initialization(centL,centH,SysOpt);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH,SysOpt);

	double sys=0;

	if (pt<7) return 0;
	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;

	sys+= ppPtShape->GetBinContent(ppPtShape->FindBin(pt))*
		ppPtShape->GetBinContent(ppPtShape->FindBin(pt));
	sys+= PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt))*
		PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt));

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));

	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));
	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));

	return sqrt(sys);
}

// =============================================================================================================
// cross-section systematics for pp
// =============================================================================================================
float normalizationUncertaintyForPP()
{
	return sqrt((BRUncertainty*BRUncertainty)+(ppLumiUncertainty*ppLumiUncertainty));
}

float systematicsPP(double pt, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized) initialization(SysOpt);
	double sys=0;

	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	if (stage==1) return sqrt(sys);

	sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt))* 
		ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt));

	if (stage==2) return sqrt(sys);

	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))* 
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= ppPtShape->GetBinContent(ppPtShape->FindBin(pt))*
		ppPtShape->GetBinContent(ppPtShape->FindBin(pt));

	if (stage==3) return sqrt(sys);

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));

	return sqrt(sys);
}

float systematicsPP_Correlated(double pt, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized) initialization(SysOpt);
	double sys=0;
	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt))* 
		ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt));
	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))* 
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));

	return sqrt(sys);
}

float systematicsPP_UnCorrelated(double pt, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized) initialization(SysOpt);
	double sys=0;
	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= ppPtShape->GetBinContent(ppPtShape->FindBin(pt))*
		ppPtShape->GetBinContent(ppPtShape->FindBin(pt));
	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));

	return sqrt(sys);
}

// =============================================================================================================
// cross-section systematics for PbPb
// =============================================================================================================
float normalizationUncertaintyForPbPb(bool TAAhi=1, double centL=0,double centH=100)
{
	double sys = ((BRUncertainty*BRUncertainty)+(PbPbNMBUncertainty*PbPbNMBUncertainty));
	if (centL==0&&centH==10) {
		// 0-10%
		sys+=TAAUncertainty0to10*TAAUncertainty0to10;
	} else {
		// 0-100%
		if(TAAhi == 1)
			sys+=TAAUncertainty0to100HI*TAAUncertainty0to100HI;
		if(TAAhi == 0)
			sys+=TAAUncertainty0to100LO*TAAUncertainty0to100LO;
	}   
	return sqrt(sys);
}

float systematicsPbPb(double pt, bool TAAhi = 1, double centL=0,double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized && centL==0&&centH==100) initialization(centL,centH,SysOpt);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH,SysOpt);

	double sys=0;

	sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt))* 
		PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt));

	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))* 
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));

	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;

	sys+= PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt))*
		PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt));

	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));

	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));

	return sqrt(sys);
}

float systematicsPbPb_Correlated(double pt, bool TAAhi = 1, double centL=0, double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized && centL==0&&centH==100) initialization(centL,centH,SysOpt);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH,SysOpt);
	double sys=0;

	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))* 
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));

	sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt))* 
		PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt));

	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	return sqrt(sys);
}

float systematicsPbPb_UnCorrelated(double pt, bool TAAhi = 1, double centL=0, double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized && centL==0&&centH==100) initialization(centL,centH,SysOpt);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH,SysOpt);
	double sys=0;

	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;

	sys+= PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt))*
		PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt));

	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));

	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));

	return sqrt(sys);
}

// =============================================================================================================
// Drawer
// =============================================================================================================
void drawSys(double x1,double y1, double x2,double y2, int color = 1)
{
	TLine *l1 = new TLine(x1,y1/100.,x2,y2/100.);
	TLine *l2 = new TLine(x1,-y1/100.,x2,-y2/100.);
	l1->SetLineWidth(2);
	l2->SetLineWidth(2);
	l1->SetLineColor(color);
	l2->SetLineColor(color);
	l1->Draw();
	l2->Draw();
}

// =============================================================================================================
// Plot systematics for RAA
// =============================================================================================================
void plotSystematicsRAA(double centL=0,double centH=100)
{
	TCanvas*canvas=new TCanvas("canvas","canvas",600,600);//550,500
	canvas->cd();
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetBorderSize(2);
	canvas->SetLeftMargin(0.185);//0.200
	canvas->SetRightMargin(0.045);
	canvas->SetTopMargin(0.080);
	canvas->SetBottomMargin(0.150);
	canvas->SetFrameBorderMode(0);
	canvas->SetLogx();

	TH2F* hempty=new TH2F("hempty","",50,5,60.,10.,-0.8,0.8);
	hempty->GetXaxis()->CenterTitle();
	hempty->GetYaxis()->CenterTitle();
	hempty->GetYaxis()->SetTitle("Systematical Uncertainty");
	hempty->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	hempty->GetXaxis()->SetTitleOffset(1.40);//0.9
	hempty->GetYaxis()->SetTitleOffset(1.45);//1.
	hempty->GetXaxis()->SetTitleSize(0.05);//0.045
	hempty->GetYaxis()->SetTitleSize(0.05);//0.045
	hempty->GetXaxis()->SetTitleFont(42);
	hempty->GetYaxis()->SetTitleFont(42);
	hempty->GetXaxis()->SetLabelFont(42);
	hempty->GetYaxis()->SetLabelFont(42);
	hempty->GetXaxis()->SetLabelSize(0.050);//0.035
	hempty->GetYaxis()->SetLabelSize(0.050);//0.035  
	hempty->GetXaxis()->SetLabelOffset(0.01);
	hempty->Draw();

	drawSys(6,0, 6,normalizationUncertaintyForRAA(centL,centH),2);
	drawSys(6,normalizationUncertaintyForRAA(centL,centH), 6.5,normalizationUncertaintyForRAA(centL,centH),2);
	drawSys(6.5,0, 6.5,normalizationUncertaintyForRAA(centL,centH),2);

	drawSys(PtBins[0],0, PtBins[0],systematicsForRAA(PtBins[0],centL,centH,0,0),1);
	drawSys(PtBins[nPtBins],0, PtBins[nPtBins],systematicsForRAA(PtBins[nPtBins],centL,centH,0,0),1);

	for (double i=PtBins[0];i<=PtBins[nPtBins];i+=0.1)
	{      
		drawSys(i,systematicsForRAA(i,centL,centH,0,0), i+0.1,systematicsForRAA(i+0.1,centL,centH,0,0),1);
		drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,2)*systematicsForRAA(i,centL,centH,0,2))-(systematicsForRAA(i,centL,centH,0,1)*systematicsForRAA(i,centL,centH,0,1))),
				i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,2)*systematicsForRAA(i+0.1,centL,centH,0,2))-(systematicsForRAA(i+0.1,centL,centH,0,1)*systematicsForRAA(i+0.1,centL,centH,0,1))),4);
		drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,3)*systematicsForRAA(i,centL,centH,0,3))-(systematicsForRAA(i,centL,centH,0,2)*systematicsForRAA(i,centL,centH,0,2))),
				i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,3)*systematicsForRAA(i+0.1,centL,centH,0,3))-(systematicsForRAA(i+0.1,centL,centH,0,2)*systematicsForRAA(i+0.1,centL,centH,0,2))),kGreen+2);
		drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,0)*systematicsForRAA(i,centL,centH,0,0))-(systematicsForRAA(i,centL,centH,0,3)*systematicsForRAA(i,centL,centH,0,3))),
				i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,0)*systematicsForRAA(i+0.1,centL,centH,0,0))-(systematicsForRAA(i+0.1,centL,centH,0,3)*systematicsForRAA(i+0.1,centL,centH,0,3))),kMagenta);
	}

	TH1D *h1 = new TH1D("h1","",100,0,1);
	h1->SetLineWidth(2); h1->SetLineColor(1);
	TH1D *h2 = new TH1D("h2","",100,0,1);
	h2->SetLineWidth(2); h2->SetLineColor(2);
	TH1D *h4 = new TH1D("h4","",100,0,1);
	h4->SetLineWidth(2); h4->SetLineColor(4);
	TH1D *h5 = new TH1D("h5","",100,0,1);
	h5->SetLineWidth(2); h5->SetLineColor(kGreen+2);
	TH1D *h6 = new TH1D("h6","",100,0,1);
	h6->SetLineWidth(2); h6->SetLineColor(kMagenta);
	TH1D *h7 = new TH1D("h7","",100,0,1);
	h7->SetLineWidth(2); h7->SetLineColor(kYellow);

	TLatex* texlumi = new TLatex(0.19,0.936,"25.8 pb^{-1} (5.02 TeV pp) + 350.68 #mub^{-1} (5.02 TeV PbPb)");
	texlumi->SetNDC();
	//texlumi->SetTextAlign(31);
	texlumi->SetTextFont(42);
	texlumi->SetTextSize(0.036);
	texlumi->SetLineWidth(2);
	texlumi->Draw();
	TLatex* texcms = new TLatex(0.22,0.90,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);//61
	texcms->SetTextSize(0.06);
	texcms->SetLineWidth(2);
	texcms->Draw();
	TLatex* texpre = new TLatex(0.22,0.84,"Performance");
	texpre->SetNDC();
	texpre->SetTextAlign(13);
	texpre->SetTextFont(52);
	texpre->SetTextSize(0.04);
	texpre->SetLineWidth(2);
	texpre->Draw();

	TLatex * texY = new TLatex(0.5,0.8324607,"B^{+} R_{AA}, |y| < 2.4");//0.2612903,0.8425793
	texY->SetNDC();
	texY->SetTextColor(1);
	texY->SetTextFont(42);
	texY->SetTextSize(0.045);
	texY->SetLineWidth(2);
	texY->Draw();

	TString texper="%";
	TLatex * tlatexeff2 = new TLatex(0.5268456,0.7678883,Form("Centrality %.0f-%.0f%s",centL,centH,texper.Data()));//0.2612903,0.8425793
	tlatexeff2->SetNDC();
	tlatexeff2->SetTextColor(1);
	tlatexeff2->SetTextFont(42);
	tlatexeff2->SetTextSize(0.045);
	tlatexeff2->SetLineWidth(2);
	tlatexeff2->Draw();

	TLegend *leg = new TLegend(0.2147651,0.1762653,0.7818792,0.3717277);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->SetTextSize(0.04);
	leg->AddEntry(h2,"Overall Normalization (N_{MB}, Lumi)","l");
	leg->AddEntry(h1,"Total Systematics","l");
	leg->AddEntry(h4,"Signal Extraction","l");
	leg->AddEntry(h5,"B Meson Selection and Correction","l");
	leg->AddEntry(h6,"Tag and Probe","l");
	leg->Draw();
	canvas->SaveAs(Form("SystematicSummaryPbPb_Cent%d.pdf",(int)centH));
	canvas->SaveAs(Form("SystematicSummaryPbPb_Cent%d.png",(int)centH));
}

// =============================================================================================================
// Plot systematics for cross section
// =============================================================================================================
void plotSystematicsPP()
{
	TCanvas*canvas=new TCanvas("canvas","canvas",600,600);//550,500
	canvas->cd();
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetBorderSize(2);
	canvas->SetLeftMargin(0.185);//0.200
	canvas->SetRightMargin(0.045);
	canvas->SetTopMargin(0.080);
	canvas->SetBottomMargin(0.150);
	canvas->SetFrameBorderMode(0);
	canvas->SetLogx();

	TH2F* hempty=new TH2F("hempty","",50,5,60.,10.,-0.8,0.8);
	hempty->GetXaxis()->CenterTitle();
	hempty->GetYaxis()->CenterTitle();
	hempty->GetYaxis()->SetTitle("Systematical Uncertainty");
	hempty->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	hempty->GetXaxis()->SetTitleOffset(1.40);//0.9
	hempty->GetYaxis()->SetTitleOffset(1.45);//1.
	hempty->GetXaxis()->SetTitleSize(0.05);//0.045
	hempty->GetYaxis()->SetTitleSize(0.05);//0.045
	hempty->GetXaxis()->SetTitleFont(42);
	hempty->GetYaxis()->SetTitleFont(42);
	hempty->GetXaxis()->SetLabelFont(42);
	hempty->GetYaxis()->SetLabelFont(42);
	hempty->GetXaxis()->SetLabelSize(0.050);//0.035
	hempty->GetYaxis()->SetLabelSize(0.050);//0.035  
	hempty->GetXaxis()->SetLabelOffset(0.01);
	hempty->Draw();

	drawSys(6,0, 6,normalizationUncertaintyForPP(),2);
	drawSys(6,normalizationUncertaintyForPP(), 6.5,normalizationUncertaintyForPP(),2);
	drawSys(6.5,0, 6.5,normalizationUncertaintyForPP(),2);

	drawSys(PtBins[0],0, PtBins[0],systematicsPP(PtBins[0]),1);
	drawSys(PtBins[nPtBins],0, PtBins[nPtBins],systematicsPP(PtBins[nPtBins]),1);

	for (double i=PtBins[0];i<PtBins[nPtBins];i+=0.1)
	{      
		drawSys(i,systematicsPP(i,0,0), i+0.1,systematicsPP(i+0.1,0,0),1);
		drawSys(i,sqrt((systematicsPP(i,0,2)*systematicsPP(i,0,2))-(systematicsPP(i,0,1)*systematicsPP(i,0,1))),
				i+0.1,sqrt((systematicsPP(i+0.1,0,2)*systematicsPP(i+0.1,0,2))-(systematicsPP(i+0.1,0,1)*systematicsPP(i+0.1,0,1))),4);
		drawSys(i,sqrt((systematicsPP(i,0,3)*systematicsPP(i,0,3))-(systematicsPP(i,0,2)*systematicsPP(i,0,2))),
				i+0.1,sqrt((systematicsPP(i+0.1,0,3)*systematicsPP(i+0.1,0,3))-(systematicsPP(i+0.1,0,2)*systematicsPP(i+0.1,0,2))),kGreen+2);
		drawSys(i,sqrt((systematicsPP(i,0,0)*systematicsPP(i,0,0))-(systematicsPP(i,0,3)*systematicsPP(i,0,3))),
				i+0.1,sqrt((systematicsPP(i+0.1,0,0)*systematicsPP(i+0.1,0,0))-(systematicsPP(i+0.1,0,3)*systematicsPP(i+0.1,0,3))),kMagenta);
	}

	TH1D *h1 = new TH1D("h1","",100,0,1);
	h1->SetLineWidth(2); h1->SetLineColor(1);
	TH1D *h2 = new TH1D("h2","",100,0,1);
	h2->SetLineWidth(2); h2->SetLineColor(2);
	TH1D *h4 = new TH1D("h4","",100,0,1);
	h4->SetLineWidth(2); h4->SetLineColor(4);
	TH1D *h5 = new TH1D("h5","",100,0,1);
	h5->SetLineWidth(2); h5->SetLineColor(kGreen+2);
	TH1D *h6 = new TH1D("h6","",100,0,1);
	h6->SetLineWidth(2); h6->SetLineColor(kMagenta);

	TLatex* texlumi = new TLatex(0.35,0.936,"25.8 pb^{-1} (5.02 TeV pp)");
	texlumi->SetNDC();
	//texlumi->SetTextAlign(31);
	texlumi->SetTextFont(42);
	texlumi->SetTextSize(0.045);
	texlumi->SetLineWidth(2);
	texlumi->Draw();
	TLatex* texcms = new TLatex(0.22,0.90,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);//61
	texcms->SetTextSize(0.06);
	texcms->SetLineWidth(2);
	texcms->Draw();
	TLatex* texpre = new TLatex(0.22,0.84,"Performance");
	texpre->SetNDC();
	texpre->SetTextAlign(13);
	texpre->SetTextFont(52);
	texpre->SetTextSize(0.04);
	texpre->SetLineWidth(2);
	texpre->Draw();

	TLatex * texY = new TLatex(0.5,0.8324607,"B^{+} d#sigma / dp_{T}, |y| < 2.4");//0.2612903,0.8425793
	texY->SetNDC();
	texY->SetTextColor(1);
	texY->SetTextFont(42);
	texY->SetTextSize(0.045);
	texY->SetLineWidth(2);
	texY->Draw();

	TLegend *leg = new TLegend(0.2147651,0.1762653,0.7818792,0.3717277);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->SetTextSize(0.04);
	leg->AddEntry(h2,"Overall Normalization (Lumi + BR)","l");
	leg->AddEntry(h1,"Total Systematics","l");
	leg->AddEntry(h4,"Signal Extraction","l");
	leg->AddEntry(h5,"B Meson Selection and Correction","l");
	leg->AddEntry(h6,"Tag and Probe","l");
	leg->Draw();

	canvas->SaveAs("SystematicSummaryPP.pdf");
	canvas->SaveAs("SystematicSummaryPP.png");
}

void plotNormalisationUnc(){
	std::cout<<"normalisation uncertainty RAA 0-100="<<normalizationUncertaintyForRAA(0,100)<<std::endl;
	std::cout<<"normalisation uncertainty RAA 0-10="<<normalizationUncertaintyForRAA(0,10)<<std::endl;
	std::cout<<"normalisation uncertainty pp="<<normalizationUncertaintyForPP()<<std::endl;
	std::cout<<"normalisation uncertainty PbPb 0-100="<<normalizationUncertaintyForPbPb(0,100)<<std::endl;
	std::cout<<"normalisation uncertainty PbPb 0-10="<<normalizationUncertaintyForPbPb(0,10)<<std::endl;
}
