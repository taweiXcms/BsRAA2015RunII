#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "iostream"
#include "iomanip"
#define MAX_XB       20000
using namespace std;
bool isMC = 0;//drop events w/o gen match
bool mFromfinder = 0;
bool skimevents=0;//drop events w/o reco cand.

//string inFileNames[] = {"/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs.root"};
string inFileNames[] = {"/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs.root"};

int nFiles = sizeof(inFileNames)/sizeof(string);
void addtochain(TChain* root){
	for (int i=0; i<nFiles; i++) {
		root->Add(inFileNames[i].c_str());
	}	    
}

TChain* nt;
TChain* ntGen;
TChain* ntHlt; 
TChain* ntHi;
TChain* ntSkim;

int skimmer()
{
	if(mFromfinder){
		nt= new TChain("Dfinder/ntphi");
		ntGen = new TChain("Dfinder/ntGen");
		ntHlt = new TChain("hltanalysis/HltTree");
		ntHi = new TChain("hiEvtAnalyzer/HiTree");
		ntSkim = new TChain("skimanalysis/HltTree");
	}
	else{
		nt= new TChain("ntphi");
		ntGen = new TChain("ntGen");
		ntHlt = new TChain("ntHlt");
		ntHi = new TChain("ntHi");
		ntSkim = new TChain("ntSkim");
	}
	addtochain(nt);
	addtochain(ntGen);
	addtochain(ntHlt);
	addtochain(ntHi);
	addtochain(ntSkim);

	cout<<" -- Check evt no. for three trees"<<endl;
	cout<<"    "<<nt->GetEntries()<<", "<<ntGen->GetEntries()<<", "<<ntHlt->GetEntries()<<", "<<ntHi->GetEntries()<<", "<<ntSkim->GetEntries()<<endl;
	if(nt->GetEntries()!=ntHlt->GetEntries())
	{
		cout<<"    Error: Event numbers are different in three trees."<<endl;
		return 0;
	}

	Int_t fCurrent = -1;
	int     RunNo;
	int     EvtNo;
	int     LumiNo;
	int     Bsize;
	float   Bgen[MAX_XB];
	nt->SetBranchAddress("Bsize",&Bsize);
	nt->SetBranchAddress("RunNo",&RunNo);
	nt->SetBranchAddress("EvtNo",&EvtNo);
	nt->SetBranchAddress("LumiNo",&LumiNo);
    nt->SetBranchAddress("Bgen",Bgen);

	TString ofname="test.root";
	TFile* outf = TFile::Open(ofname,"recreate");
	TTree* nt_new = nt->CloneTree(0);
	TTree* ntGen_new = ntGen->CloneTree(0);
	TTree* ntHlt_new = ntHlt->CloneTree(0);
	TTree* ntHi_new = ntHi->CloneTree(0);
	TTree* ntSkim_new = ntSkim->CloneTree(0);
	ntHlt_new->SetName("ntHlt");
	ntHi_new->SetName("ntHi");
	ntSkim_new->SetName("ntSkim");
	int HLT_HIL1DoubleMu0ForPPRef_v1;
    TBranch* newBr_HLT_HIL1DoubleMu0ForPPRef_v1 = ntHlt_new->Branch("HLT_HIL1DoubleMu0ForPPRef_v1", &HLT_HIL1DoubleMu0ForPPRef_v1, "HLT_HIL1DoubleMu0ForPPRef_v1/I");

	Long64_t nentries = nt->GetEntries();
	cout<<" -- Event reading"<<endl;
//	nentries = 80000;
	for(Long64_t i=0;i<nentries;i++)
	{
		if(i%100000==0) cout<<setiosflags(ios::left)<<"    "<<setw(8)<<i<<" / "<<nentries<<endl;

		Long64_t centry = nt->LoadTree(i);
		if (centry < 0) break;
		if (nt->GetTreeNumber() != fCurrent) {
			fCurrent = nt->GetTreeNumber();
			cout << "[INFO] Changed to Tree number: " << inFileNames[fCurrent] << endl;
		}

		nt->GetEntry(i);
		ntGen->GetEntry(i);
		ntHlt->GetEntry(i);
		ntHi->GetEntry(i);
		ntSkim->GetEntry(i);
		HLT_HIL1DoubleMu0ForPPRef_v1 = 0;

		bool flag = false;	
		if(Bsize > 0){
			if(!isMC){
				flag = true;
			}	
			else{
		        for(int d=0; d<Bsize; d++){
					if(Bgen[d]==23333){
						flag = true;
						break;
					}
				}
			}
		}
		if(!skimevents || flag)
		{
			nt_new->Fill();
			ntHlt_new->Fill(); 
			ntHi_new->Fill(); 
			ntSkim_new->Fill(); 
			ntGen_new->Fill();
			newBr_HLT_HIL1DoubleMu0ForPPRef_v1->Fill();
		} 
	}
	outf->Write();
	cout<<" -- Writing new trees done"<<endl;
	outf->Close();

	return 1;  
}
