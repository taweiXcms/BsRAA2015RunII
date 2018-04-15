#include <TTree.h>
#include <TFile.h>
#include "convertTree.h"
TString fname;
bool ispp;
bool isdata;
void convertTree(){
// PbPb
//  fname = "Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT7to50_BDT15to50_20180223MVA";
//  ispp = 0; isdata = 1;
//  fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_BDT15to50_20180223MVA";
//  ispp = 0; isdata = 0;
	TFile *inf = new TFile(Form("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/%s.root",fname.Data()));
	TTree* ntphi = (TTree*)inf->Get("ntphi");
	TTree* ntGen = (TTree*)inf->Get("ntGen");
	TTree* ntHi = (TTree*)inf->Get("ntHi");
	TTree* ntHlt = (TTree*)inf->Get("ntHlt");
	TTree* ntSkim = (TTree*)inf->Get("ntSkim");
	TTree* BDTStage1_pt7to15 = (TTree*)inf->Get("BDTStage1_pt7to15");
	TTree* BDTStage1_pt15to50 = (TTree*)inf->Get("BDTStage1_pt15to50");
	TTree* BDTStage1_pt15to50_20180223MVA = (TTree*)inf->Get("BDTStage1_pt15to50_20180223MVA");
	BDTStage1_pt7to15->AddFriend(BDTStage1_pt15to50);
	BDTStage1_pt7to15->AddFriend(BDTStage1_pt15to50_20180223MVA);
	TFile *outf = new TFile(Form("%s_candWise.root",fname.Data()),"recreate");
	TTree* newntphi = new TTree("ntphi","");
	TTree* newntGen = new TTree("ntGen","");
	setBDTBranchAddress(BDTStage1_pt7to15, ispp, isdata);
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
        BDTStage1_pt7to15->GetEntry(n);
        BDTStage1_pt15to50->GetEntry(n);
        BDTStage1_pt15to50_20180223MVA->GetEntry(n);
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
