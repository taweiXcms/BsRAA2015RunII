#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
#include "TFile.h"
#include "format.h"

string ifname = "BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_20171119_bPt0jpsiPt0tkPt0p5_Bs.root";
string ofname = "BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_20171119_bPt0jpsiPt0tkPt0p5_BS_BDTStage1_pt15to50.root";
TString weightfile = "TMVA_BDT_pp_15_50_varStage1.weights.xml";

//string ifname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_00_03_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs"; 
//string ifname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_03_06_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//string ifname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_06_09_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//string ifname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_09_12_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//string ifname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_12_15_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//string ifname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_15_30_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//string ifname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_30_inf_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//string ofname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_00_03_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_BS_BDTStage1_pt15to50.root"; 
//string ofname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_03_06_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_BS_BDTStage1_pt15to50.root";
//string ofname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_06_09_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_BS_BDTStage1_pt15to50.root";
//string ofname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_09_12_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_BS_BDTStage1_pt15to50.root";
//string ofname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_12_15_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_BS_BDTStage1_pt15to50.root";
//string ofname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_15_30_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_BS_BDTStage1_pt15to50.root";
//string ofname = "BfinderMC_PbPb_Pythia8_BJpsiMM_ptJpsi_30_inf_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_BS_BDTStage1_pt15to50.root";
//TString weightfile = "TMVA_BDT_PbPb_15_50_varStage1.weights.xml";

TString methodName = Form("BDT method");
string mvaName = "BDTStage1_pt15to50";

void BfinderProdTMVA(){
	TFile* inf = TFile::Open(ifname.c_str());
	TTree* root = (TTree*)inf->Get("Bfinder/root");
	TTree* hltanalysis = (TTree*)inf->Get("hltanalysis/HltTree");
	TTree* hiEvtAnalyzer = (TTree*)inf->Get("hiEvtAnalyzer/HiTree");
	TTree* skimanalysis = (TTree*)inf->Get("skimanalysis/HltTree");
	EvtInfoBranches     *EvtInfo = new EvtInfoBranches;
	VtxInfoBranches     *VtxInfo = new VtxInfoBranches;
	MuonInfoBranches    *MuonInfo = new MuonInfoBranches;
	TrackInfoBranches   *TrackInfo = new TrackInfoBranches;
	BInfoBranches       *BInfo = new BInfoBranches;
	GenInfoBranches     *GenInfo = new GenInfoBranches;
	EvtInfo->setbranchadd(root);
	VtxInfo->setbranchadd(root);
	MuonInfo->setbranchadd(root);
	TrackInfo->setbranchadd(root);
	BInfo->setbranchadd(root);
	GenInfo->setbranchadd(root);
	TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );
	Float_t         __Btrk1Pt;
	Float_t         __Btrk2Pt;
	Float_t         __Btrk1Eta;
	Float_t         __Btrk2Eta;
	Float_t         __Btrk1Dxy_Over_Btrk1D0Err;
	Float_t         __Btrk2Dxy_Over_Btrk2D0Err;
	Float_t         __Btktkmass_abs;
	Float_t         __BsvpvDistance_Over_BsvpvDisErr;
	Float_t         __Balpha;
	reader->AddVariable("Btrk1Pt", &__Btrk1Pt);
	reader->AddVariable("Btrk2Pt", &__Btrk2Pt);
	reader->AddVariable("Btrk1Eta", &__Btrk1Eta);
	reader->AddVariable("Btrk2Eta", &__Btrk2Eta);
	reader->AddVariable("Btrk1Dxy/Btrk1D0Err", &__Btrk1Dxy_Over_Btrk1D0Err);
	reader->AddVariable("Btrk2Dxy/Btrk2D0Err", &__Btrk2Dxy_Over_Btrk2D0Err);
	reader->AddVariable("abs(Btktkmass-1.019455)", &__Btktkmass_abs);
	reader->AddVariable("BsvpvDistance/BsvpvDisErr", &__BsvpvDistance_Over_BsvpvDisErr);
	reader->AddVariable("Balpha", &__Balpha);
	reader->BookMVA( methodName, weightfile );

	Long64_t nentries = root->GetEntries();
	int startEntries = 0;
	int endEntries = nentries;
	TLorentzVector* b4P = new TLorentzVector;
	float tk1px,tk1py,tk1pz,tk1E;
	float tk2px,tk2py,tk2pz,tk2E;
	float MVAVal[MAX_XB];
	int _size = 0;

	TFile* otf = TFile::Open(ofname.c_str(),"recreate");
	TTree* mvaTree = new TTree(mvaName.c_str(),"");
	mvaTree->Branch("BInfo.size", &_size, "BInfo.size/I");
    mvaTree->Branch(mvaName.c_str(), MVAVal, Form("%s[BInfo.size]/F", mvaName.c_str()));
	TTree* new_root = root->CloneTree(0);
    TTree* new_hltanalysis = hltanalysis->CloneTree(0);
	new_hltanalysis->SetName("hltanalysis");
    TTree* new_hiEvtAnalyzer = hiEvtAnalyzer->CloneTree(0);
	new_hiEvtAnalyzer->SetName("hiEvtAnalyzer");
    TTree* new_skimanalysis = skimanalysis->CloneTree(0);
	new_skimanalysis->SetName("skimanalysis");
    TBranch* newBr_HLT_MVAVal = new_root->Branch("BInfo.MVAVal", MVAVal, "BInfo.MVAVal[BInfo.size]/F");
	for(Int_t i=startEntries;i<endEntries;i++){
		root->GetEntry(i);	
		_size = BInfo->size;
		for(int j=0;j<BInfo->size;j++){
			b4P->SetPtEtaPhiM(TrackInfo->pt[BInfo->rftk2_index[j]],TrackInfo->eta[BInfo->rftk2_index[j]],TrackInfo->phi[BInfo->rftk2_index[j]],KAON_MASS);
			tk1px = b4P->Px();
			tk1py = b4P->Py();
			tk1pz = b4P->Pz();
			tk1E = b4P->E();
			b4P->SetPtEtaPhiM(TrackInfo->pt[BInfo->rftk1_index[j]],TrackInfo->eta[BInfo->rftk1_index[j]],TrackInfo->phi[BInfo->rftk1_index[j]],KAON_MASS);
			tk2px = b4P->Px();
			tk2py = b4P->Py();
			tk2pz = b4P->Pz();
			tk2E = b4P->E();
			b4P->SetPxPyPzE(tk1px+tk2px,
					tk1py+tk2py,
					tk1pz+tk2pz,
					tk1E+tk2E);
			__Btrk1Pt = TrackInfo->pt[BInfo->rftk1_index[j]];
			__Btrk2Pt = TrackInfo->pt[BInfo->rftk2_index[j]];
			__Btrk1Eta = TrackInfo->eta[BInfo->rftk1_index[j]];
			__Btrk2Eta = TrackInfo->eta[BInfo->rftk2_index[j]];
			__Btrk1Dxy_Over_Btrk1D0Err = TrackInfo->dxyPV[BInfo->rftk1_index[j]]/TrackInfo->d0error[BInfo->rftk1_index[j]];
			__Btrk2Dxy_Over_Btrk2D0Err = TrackInfo->dxyPV[BInfo->rftk2_index[j]]/TrackInfo->d0error[BInfo->rftk2_index[j]];
			__Btktkmass_abs = fabs(b4P->Mag()-1.019455);
			__BsvpvDistance_Over_BsvpvDisErr = BInfo->svpvDistance[j]/BInfo->svpvDisErr[j];
			__Balpha = BInfo->alpha[j];
			MVAVal[j] = reader->EvaluateMVA(methodName);
		}	
		mvaTree->Fill();
    	new_root->Fill();
		new_hltanalysis->Fill();
		new_hiEvtAnalyzer->Fill();
		new_skimanalysis->Fill();
	}
	mvaTree->Write();
    new_root->Write();
	new_hltanalysis->Write();
	new_hiEvtAnalyzer->Write();
	new_skimanalysis->Write();
}
