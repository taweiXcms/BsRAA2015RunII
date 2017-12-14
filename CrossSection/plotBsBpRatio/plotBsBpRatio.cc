#include "../uti.h"
double xVal[100];
double xErr[100];
double BpyVal[100];
double BpyStaErr[100];
double BpySysErr[100];
double BsyVal[100];
double BsyStaErr[100];
double BsySysErr[100];
double raaRatio[100];
double raaRatioStaErr[100];
double raaRatioSysErr[100];
using namespace std;

void plotBsBpRatio(){
	TFile* Bpf = new TFile("outputRAA.root");
	TGraphAsymmErrors* BpgNucl = (TGraphAsymmErrors*)Bpf->Get("gNuclearModification");
	TH1D* BphNucl = (TH1D*)Bpf->Get("hNuclearModification");
	TFile* Bsf = new TFile("../ROOTfiles/outputRAA.root");
	TGraphAsymmErrors* BsgNucl = (TGraphAsymmErrors*)Bsf->Get("gNuclearModification");
	TH1D* BshNucl = (TH1D*)Bsf->Get("hNuclearModification");
	int _nBins = BphNucl->GetNbinsX();
	for(int i = 0; i < _nBins; i ++){
		double x, y;
		BpgNucl->GetPoint(i,x,y);
		xVal[i] = x;
		BpyVal[i] = y;
		BpyStaErr[i] = BphNucl->GetBinError(i+1);
		BpySysErr[i] = BpgNucl->GetErrorYhigh(i);
		xErr[i] = BpgNucl->GetErrorXhigh(i);
		BsgNucl->GetPoint(i,x,y);
		BsyVal[i] = y;
		BsyStaErr[i] = BshNucl->GetBinError(i+1);
		BsySysErr[i] = BsgNucl->GetErrorYhigh(i);	
		raaRatio[i] = BsyVal[i]/BpyVal[i];
		raaRatioStaErr[i] = sqrt(BpyStaErr[i]/BpyVal[i]*BpyStaErr[i]/BpyVal[i] + BsyStaErr[i]/BsyVal[i]*BsyStaErr[i]/BsyVal[i])*raaRatio[i];
		raaRatioSysErr[i] = sqrt(BpySysErr[i]/BpyVal[i]*BpySysErr[i]/BpyVal[i] + BsySysErr[i]/BsyVal[i]*BsySysErr[i]/BsyVal[i])*raaRatio[i];
	}
	
	TH1D* hRAAratio = new TH1D("hRAAratio","",_nBins);
    TGraphAsymmErrors* gRAAratio = new TGraphAsymmErrors(_nBins,xVal,raaRatio,xErr,xErr,raaRatioErr,raaRatioErr);
    RAAratio->SetFillColor(kAzure+7);
    RAAratio->SetFillColorAlpha(kAzure+7, 0.5);
    RAAratio->SetLineWidth(0);
    RAAratio->SetMarkerSize(1.2);
    RAAratio->SetMarkerStyle(21);
    RAAratio->SetLineColor(0);
    RAAratio->SetMarkerColor(kAzure-1);
	RAAratio->Draw();
	RAAratio->Draw("5same");

	for(int i = 0; i < _nBins; i ++){
		cout<<xVal[i]<<endl;
		cout<<xErr[i]<<endl;
		cout<<BpyVal[i]<<endl;
		cout<<BpySysErr[i]<<endl;
		cout<<BsyVal[i]<<endl;
		cout<<BsySysErr[i]<<endl;
		cout<<raaRatioSysErr[i]<<endl;
	}
}
