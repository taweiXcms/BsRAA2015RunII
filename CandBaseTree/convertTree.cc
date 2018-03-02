#include <TTree.h>
#include <TFile.h>
#include "convertTree.h"
TString fname;
bool ispp;
bool isdata;
void convertTree(){
//	fname = "Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_BDT15to50v2";
//	ispp = 1; isdata = 1;
//	fname = "Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_BDT15to50v2";
//	ispp = 1; isdata = 0;
//	fname = "Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_PbPbBDT15to50v2";
//	ispp = 1; isdata = 1;
	fname = "Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_PbPbBDT15to50v2";
	ispp = 1; isdata = 0;
//	fname = "Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT15to50v2";
//	ispp = 0; isdata = 1;
//	fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50v2";
//	ispp = 0; isdata = 0;
	TFile *inf = new TFile(Form("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/%s.root",fname.Data()));
	TTree* ntphi = (TTree*)inf->Get("ntphi");
	TTree* ntGen = (TTree*)inf->Get("ntGen");
	TTree* ntHi = (TTree*)inf->Get("ntHi");
	TTree* ntHlt = (TTree*)inf->Get("ntHlt");
	TTree* ntSkim = (TTree*)inf->Get("ntSkim");
	TTree* BDTStage1_pt15to50 = (TTree*)inf->Get("BDTStage1_pt15to50");
	TFile *outf = new TFile(Form("%s_candWise.root",fname.Data()),"recreate");
	TTree* newntphi = new TTree("ntphi","");
	TTree* newntGen = new TTree("ntGen","");
	setBDTBranchAddress(BDTStage1_pt15to50, ispp, isdata);
	setHiBranchAddress(ntHi, ispp, isdata);
	setSkimBranchAddress(ntSkim, ispp, isdata);
	setHltBranchAddress(ntHlt, ispp, isdata);
	setBranchAddress(ntphi, ispp, isdata);
	setGenBranchAddress(ntGen, ispp, isdata);
	buildBranch(newntphi, ispp, isdata);
	buildGenBranch(newntGen, ispp, isdata);
    int nentries = ntphi->GetEntries();
    for(int n=0; n<nentries; n++){
        ntphi->GetEntry(n);
        ntGen->GetEntry(n);
        ntHi->GetEntry(n);
        ntHlt->GetEntry(n);
        ntSkim->GetEntry(n);
        BDTStage1_pt15to50->GetEntry(n);
        for(int b=0; b<Bsize; b++){
			fillVal(b, ispp, isdata);
            newntphi->Fill();
        }
        for(int g=0; g<Gsize; g++){
			fillGenVal(g, ispp, isdata);
            newntGen->Fill();
        }
    }
	outf->Write();
	outf->Close();
}
