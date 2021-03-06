#include "../uti.h"
#include "../parameters.h"
#include "TLegendEntry.h"
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

int _nBins = nBins;
double *_ptBins = ptBins;
void plotBsBpRatio(){
	TFile* Bpf = new TFile("outputRAA_Bp.root");
	TGraphAsymmErrors* BpgNucl = (TGraphAsymmErrors*)Bpf->Get("gNuclearModification");
	TH1D* BphNucl = (TH1D*)Bpf->Get("hNuclearModification");
	TFile* Bsf = new TFile("outputRAA_Bs.root");
	TGraphAsymmErrors* BsgNucl = (TGraphAsymmErrors*)Bsf->Get("gNuclearModification");
	TH1D* BshNucl = (TH1D*)Bsf->Get("hNuclearModification");
	int _nBins = BphNucl->GetNbinsX();
	for(int i = 0; i < _nBins; i ++){
		double x, y;
		BpgNucl->GetPoint(i,x,y);
		xVal[i] = x;
		BpyVal[i] = y;
		BpyStaErr[i] = BphNucl->GetBinError(i+1)/BpyVal[i];
		BpySysErr[i] = BpgNucl->GetErrorYhigh(i)/BpyVal[i];
		xErr[i] = BpgNucl->GetErrorXhigh(i);
		BsgNucl->GetPoint(i,x,y);
		BsyVal[i] = y;
		BsyStaErr[i] = BshNucl->GetBinError(i+1)/BsyVal[i];
		BsySysErr[i] = BsgNucl->GetErrorYhigh(i)/BsyVal[i];	
		raaRatio[i] = BsyVal[i]/BpyVal[i];
		raaRatioStaErr[i] = sqrt(BpyStaErr[i]/BpyVal[i]*BpyStaErr[i]/BpyVal[i] + BsyStaErr[i]/BsyVal[i]*BsyStaErr[i]/BsyVal[i])*raaRatio[i];
		raaRatioSysErr[i] = sqrt(BpySysErr[i]/BpyVal[i]*BpySysErr[i]/BpyVal[i] + BsySysErr[i]/BsyVal[i]*BsySysErr[i]/BsyVal[i])*raaRatio[i];
	}
    TCanvas*canvasRAA=new TCanvas("canvasRAA","canvasRAA",600,600);
    canvasRAA->cd();

    TH2F* hemptyEff=new TH2F("hemptyEff","",50,_ptBins[0]-10,_ptBins[_nBins]+10,10.,0,3);
    hemptyEff->GetXaxis()->CenterTitle();
    hemptyEff->GetYaxis()->CenterTitle();
    hemptyEff->GetYaxis()->SetTitle("B_{s} R_{AA} / B^{+} R_{AA}");
    hemptyEff->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    hemptyEff->GetXaxis()->SetTitleOffset(1.0);
    hemptyEff->GetYaxis()->SetTitleOffset(1.1);
    hemptyEff->GetXaxis()->SetTitleSize(0.05);
    hemptyEff->GetYaxis()->SetTitleSize(0.05);
    hemptyEff->GetXaxis()->SetTitleFont(42);
    hemptyEff->GetYaxis()->SetTitleFont(42);
    hemptyEff->GetXaxis()->SetLabelFont(42);
    hemptyEff->GetYaxis()->SetLabelFont(42);
    hemptyEff->GetXaxis()->SetLabelSize(0.04);
    hemptyEff->GetYaxis()->SetLabelSize(0.04);
    hemptyEff->SetMaximum(2);
    hemptyEff->SetMinimum(0.);
    hemptyEff->Draw();

    TGraphAsymmErrors* gRAAratio = new TGraphAsymmErrors(_nBins,xVal,raaRatio,xErr,xErr,raaRatioSysErr,raaRatioSysErr);
    gRAAratio->SetFillColor(kAzure+7);
    gRAAratio->SetFillColorAlpha(kAzure+7, 0.5);
    gRAAratio->SetLineWidth(0);
    gRAAratio->SetMarkerSize(1.2);
    gRAAratio->SetMarkerStyle(21);
    gRAAratio->SetLineColor(0);
    gRAAratio->SetMarkerColor(kAzure-1);

	TH1D* hRAAratio = new TH1D("hRAAratio","",_nBins,_ptBins);
	for(int i = 0; i < _nBins; i++){
		hRAAratio->SetBinContent(i+1,raaRatio[i]);
		hRAAratio->SetBinError(i+1,raaRatioStaErr[i]);
	}
    hRAAratio->SetLineWidth(3);
    hRAAratio->SetLineColor(kAzure-1);
    hRAAratio->SetMarkerColor(kAzure-1);
    hRAAratio->SetMarkerStyle(21);
    hRAAratio->SetMarkerSize(1.2);

	TLegend *legendSigma=new TLegend(0.16,0.78,0.50,0.90,"");
    legendSigma->SetBorderSize(0);
    legendSigma->SetLineColor(0);
    legendSigma->SetFillColor(0);
    legendSigma->SetFillStyle(1001);
    legendSigma->SetTextFont(42);
    legendSigma->SetTextSize(0.04);

	TLegendEntry *ent_B;
	ent_B = legendSigma->AddEntry(hRAAratio,"B_{s}/B^{+} R_{AA} ratio","p");
	ent_B->SetTextFont(42);
	ent_B->SetLineColor(4);
	ent_B->SetMarkerColor(4);
	ent_B->SetTextSize(0.038);
    legendSigma->Draw();

    TLine *line = new TLine(_ptBins[0]-10,1,_ptBins[_nBins]+10,1);
    line->SetLineStyle(2);
    line->SetLineWidth(2);
    line->Draw();

    TLatex * texY = new TLatex(0.81,0.17,"|y| < 2.4");
    texY->SetNDC();
    texY->SetTextColor(1);
    texY->SetTextFont(42);
    texY->SetTextSize(0.04);
    texY->SetLineWidth(2);
    texY->Draw();

    TLatex* texlumi = new TLatex(0.18,0.96,"28.0 pb^{-1} (pp 5.02 TeV) + 351 #mub^{-1} (PbPb 5.02 TeV)");
    texlumi->SetNDC();
    texlumi->SetTextFont(42);
    texlumi->SetTextSize(0.038);
    texlumi->SetLineWidth(2);
    texlumi->Draw();

    //TLatex* texB = new TLatex(0.77,0.21,"B^{#plus}+B^{#minus}");
    TLatex* texB = new TLatex(0.81,0.22,"B_{s}");
    texB->SetNDC();
    texB->SetTextFont(62);
    texB->SetTextSize(0.08);
    texB->SetLineWidth(2);
    //texB->Draw();

    TLatex* texcms = new TLatex(0.18,0.93,"CMS");
    texcms->SetNDC();
    texcms->SetTextAlign(13);
    texcms->SetTextFont(62);//61
    texcms->SetTextSize(0.06);
    texcms->SetLineWidth(2);
    texcms->Draw();

    TLatex* texpre = new TLatex(0.32,0.93,"Preliminary");
    texpre->SetNDC();
    texpre->SetTextAlign(13);
    texpre->SetTextFont(62);
    texpre->SetTextSize(0.06);
    texpre->SetLineWidth(2);
    texpre->Draw();

	gRAAratio->Draw("5same");
	hRAAratio->Draw("same p");
	canvasRAA->SaveAs("BsBpRatio.pdf");

	for(int i = 0; i < _nBins; i ++){
		cout<<"=========="<<endl;
		cout<<"xVal: "<<xVal[i]<<endl;
		cout<<"xErr: "<<xErr[i]<<endl;
		cout<<"BpyVal: "<<BpyVal[i]<<endl;
		cout<<"BpyStaErr: "<<BpyStaErr[i]<<endl;
		cout<<"BpySysErr: "<<BpySysErr[i]<<endl;
		cout<<"BsyVal: "<<BsyVal[i]<<endl;
		cout<<"BsyStaErr: "<<BsyStaErr[i]<<endl;
		cout<<"BsySysErr: "<<BsySysErr[i]<<endl;
		cout<<"raaRatio: "<<raaRatio[i]<<endl;
		cout<<"raaRatioStaErr: "<<raaRatioStaErr[i]<<endl;
		cout<<"raaRatioSysErr: "<<raaRatioSysErr[i]<<endl;
		cout<<"raaRatioStaErr(%): "<<raaRatioStaErr[i]/raaRatio[i]<<endl;
		cout<<"raaRatioSysErr(%): "<<raaRatioSysErr[i]/raaRatio[i]<<endl;
	}
}
