#include "TFile.h"
#include "TH1.h"
#include <iostream>
void getCutSyst(){
	TFile* fnorm = new TFile("../ROOTfiles/CrossSectionPP.root");
	TFile* fCutBase = new TFile("../ROOTfiles/CrossSectionPP_CUTBASE.root");
	TFile* fPbPbBDT = new TFile("../ROOTfiles/CrossSectionPP_PbPbBDT.root");
	TH1D* hnorm = (TH1D*)fnorm->Get("hPtSigma");
	TH1D* hCutBase = (TH1D*)fCutBase->Get("hPtSigma");
	TH1D* hPbPbBDT = (TH1D*)fPbPbBDT->Get("hPtSigma");
	float bnorm = hnorm->GetBinContent(1);
	float bCutBase = hCutBase->GetBinContent(1);
	float bPbPbBDT = hPbPbBDT->GetBinContent(1);
	printf("norm: %f, CutBase: %f(%f), PbPbBDT: %f(%f)\n", bnorm, bCutBase, abs(bnorm-bCutBase)/bnorm, bPbPbBDT, abs(bnorm-bPbPbBDT)/bnorm);
}
