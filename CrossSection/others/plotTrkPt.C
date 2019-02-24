#include "../uti.h"

//TString file = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_candWise.root";
//TString file = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_BDT7to50_candWise.root";
TString file = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_candWise.root";
//TString file = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT7to50_candWise.root";
void plotTrkPt(){

	TFile* inf = new TFile(file.Data());
	TTree* nt = (TTree*)inf->Get("ntphi");
    TCanvas* c = new TCanvas("c","",600,600);
	TH1D *h = new TH1D("h","",100,0,0.5);
	nt->Project("h", "Btrk1Pt");
	h->SetLabelSize(0.035);
	h->Draw();
	c->SaveAs("test.pdf");
	
}
