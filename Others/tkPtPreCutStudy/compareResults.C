#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TLine.h"
#include "iostream"
#include "TLatex.h"
using namespace std;
bool ispp = 1;
TString coll = "PP";
int ntrial = 6;
void compareResults(){
	TCanvas* c = new TCanvas("c","c",600,600);
	if(!ispp){
		coll = "PbPb";
	}
	TFile* f0 = new TFile(Form("tkPtPreCutStudy-norm/ROOTfiles/CrossSection%s.root",coll.Data()));
	TFile* f[ntrial];
	f[0] = new TFile(Form("tkPtPreCutStudy-pt0p60p9/ROOTfiles/CrossSection%s.root",coll.Data()));
	f[1] = new TFile(Form("tkPtPreCutStudy-pt0p71p0/ROOTfiles/CrossSection%s.root",coll.Data()));
	f[2] = new TFile(Form("tkPtPreCutStudy-pt0p81p1/ROOTfiles/CrossSection%s.root",coll.Data()));
	f[3] = new TFile(Form("tkPtPreCutStudy-pt0p91p2/ROOTfiles/CrossSection%s.root",coll.Data()));
	f[4] = new TFile(Form("tkPtPreCutStudy-pt1p01p3/ROOTfiles/CrossSection%s.root",coll.Data()));
	f[5] = new TFile(Form("tkPtPreCutStudy-pt1p11p4/ROOTfiles/CrossSection%s.root",coll.Data()));
	TH1D* h0 = (TH1D*)f0->Get("hPtSigma");
	TH1D* h[ntrial];
	for(int i=0; i<ntrial; i++){
		h[i] = (TH1D*)f[i]->Get("hPtSigma");
		h[i]->SetName(Form("hPtSigma%d",i+1));
	}
	
	TH1D* hdiff = new TH1D("hdiff","",ntrial,0.55,1.15);
	if(!ispp){
		hdiff = new TH1D("hdiff","",ntrial,0.85,1.45);
	}
	hdiff->Sumw2();
	TH1D* hnorm = (TH1D*)hdiff->Clone("hnorm"); 
	TH1D* hvary = (TH1D*)hdiff->Clone("hvary");
	for(int i=0; i<ntrial; i++){
		hnorm->SetBinContent(i+1,h0->GetBinContent(1));
		hvary->SetBinContent(i+1,h[i]->GetBinContent(1));
		hnorm->SetBinError(i+1,h0->GetBinError(1)); //remove error, assumming they are 100% correlated
		//hvary->SetBinError(i+1,h[i]->GetBinError(1));
		float diff = (h[i]->GetBinContent(1)-h0->GetBinContent(1))/h0->GetBinContent(1);
		cout<<"vary: "<<h[i]->GetBinContent(1)<<endl;
		cout<<"norm: "<<h0->GetBinContent(1)<<endl;
		cout<<"diff: "<<diff<<endl;
	}
	hdiff = (TH1D*)hvary->Clone();
	hdiff->Add(hnorm,-1);
	hdiff->Divide(hnorm);
	hdiff->SetMaximum(1);
	hdiff->SetMinimum(-1);
	c->SetLeftMargin(0.18);
	hdiff->SetYTitle("(varied-nominal)/nominal");
	hdiff->GetYaxis()->SetTitleOffset(1.4);
	hdiff->SetXTitle("track pt cut (GeV)");
	hdiff->Draw("pe");
	TLine* line = new TLine(hdiff->GetBinLowEdge(1), 0., hdiff->GetBinLowEdge(ntrial)+hdiff->GetBinWidth(ntrial), 0.);
    line->SetLineStyle(9);
    line->SetLineWidth(0);
    line->SetLineColor(4);
    line->Draw();
    TLatex* tex = new TLatex(0.25,0.90,Form("%s",coll.Data()));
    tex->SetNDC();
    tex->SetTextAlign(13);
    tex->SetTextFont(62);
    tex->SetTextSize(0.075);
    tex->SetLineWidth(2);
	tex->Draw();
	c->SaveAs(Form("%s_result.pdf",coll.Data()));
}
