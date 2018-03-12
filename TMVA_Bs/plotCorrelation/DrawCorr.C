#include "TFile.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TH2.h"
#include "iostream"
using namespace std;
TString coll = "pp";
TFile* fin = new TFile();
void plot(TString th2name);
void DrawCorr(){
	fin = new TFile(Form("../myTMVA/ROOT/TMVA_%s_15_50_varStage1.root", coll.Data()));
	plot("CorrelationMatrixS");
	plot("CorrelationMatrixB");
	coll = "PbPb";
	fin = new TFile(Form("../myTMVA/ROOT/TMVA_%s_15_50_varStage1.root", coll.Data()));
	plot("CorrelationMatrixS");
	plot("CorrelationMatrixB");
}
void plot(TString th2name){
	TCanvas *c = new TCanvas(Form("%s_%s", th2name.Data(), coll.Data()),"",1000,600);
	TH2F* hcor = (TH2F*)fin->Get(Form("dataset/%s",th2name.Data()));
	c->SetLeftMargin(0.27);
	c->SetRightMargin(0.15);
	c->SetTopMargin(0.10);
	c->SetBottomMargin(0.20);
	hcor->Draw("colz text");
	c->SaveAs(Form("%s_%s.pdf", th2name.Data(), coll.Data()));
}

