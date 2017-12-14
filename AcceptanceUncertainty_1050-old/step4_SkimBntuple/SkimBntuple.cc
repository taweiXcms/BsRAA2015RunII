#include <iostream>
#include <branchStruct.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLorentzVector.h>
#include <TGraphAsymmErrors.h>
using namespace std;

TString inputmc;

void SkimBntuple(bool ispp=1){
	string label = "";
	if(ispp){
		label = "pp"; 
		inputmc = "/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_BDT15to50.root";
    }
	else{
		label = "PbPb";
		inputmc = "/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50.root";
	}
    TFile* infMC = new TFile(inputmc.Data());
    TTree* ntKp = (TTree*)infMC->Get("ntphi");
    TTree* ntHlt = (TTree*)infMC->Get("ntHlt");
    TTree* ntSkim = (TTree*)infMC->Get("ntSkim");
    TTree* ntHi = (TTree*)infMC->Get("ntHi");
    TTree* mvaTree = (TTree*)infMC->Get("BDTStage1_pt15to50");
    TTree* ntGen = (TTree*)infMC->Get("ntGen");
	ntKp->AddFriend("ntSkim");
	ntKp->AddFriend("ntHlt");
	ntKp->AddFriend("ntGen");
	ntKp->AddFriend("BDTStage1_pt15to50");
	setAddressTree(ntKp, ntHlt, ntSkim, ntHi, mvaTree, ntGen, ispp);
	int nevents_total = ntKp->GetEntries();

	TFile *fOut= new TFile(Form("results_%s.root", label.c_str()), "recreate"); 
	TTree* ExclBAna  = new TTree("ExclBAna","Skim Bntuple");
	double pt, y, weight;
	bool passAcc;
	double wAll = 0;
	double wPass = 0;
	ExclBAna->Branch("pt",&pt,"pt/D");
	ExclBAna->Branch("y",&y,"y/D");
	ExclBAna->Branch("weight",&weight,"weight/D");
	ExclBAna->Branch("passAcc",&passAcc,"passAcc/O");

    for(int entry=0; entry<nevents_total; entry++){
    	ntKp->GetEntry(entry);
    	ntHlt->GetEntry(entry);
    	ntSkim->GetEntry(entry);
    	ntHi->GetEntry(entry);
    	mvaTree->GetEntry(entry);
    	ntGen->GetEntry(entry);
	    for(int g=0; g<Gsize; g++){
			if(TMath::Abs(Gy[g])<2.4&&abs(GpdgId[g])==531&&GisSignal[g]>0&&Gpt[g]>=10&&Gpt[g]<=50){
				pt = Gpt[g];
				y = Gy[g];
				weight = 0;
				passAcc = 0;
				if(ispp){
                    weight = pthatweight*(pow(10, -0.365511 + 0.030289*Gpt[g] + -0.000691*Gpt[g]*Gpt[g] + 0.000005*Gpt[g]*Gpt[g]*Gpt[g]));
				} 
				else{
                    weight = pthatweight*(pow(10, -0.244653 + 0.016404*Gpt[g] + -0.000199*Gpt[g]*Gpt[g] + 0.000000*Gpt[g]*Gpt[g]*Gpt[g]));
				}		
				wAll += weight;

					if(    ((TMath::Abs(Gmu1eta[g])<1.2 && Gmu1pt[g]>3.5) 
						|| (TMath::Abs(Gmu1eta[g])>1.2 && TMath::Abs(Gmu1eta[g])<2.1 && Gmu1pt[g]>(5.77-1.8*TMath::Abs(Gmu1eta[g]))) 
						|| (TMath::Abs(Gmu1eta[g])>2.1 && TMath::Abs(Gmu1eta[g])<2.4 && Gmu1pt[g]>1.8)) 
						&& ((TMath::Abs(Gmu2eta[g])<1.2 && Gmu2pt[g]>3.5) 
						|| (TMath::Abs(Gmu2eta[g])>1.2 && TMath::Abs(Gmu2eta[g])<2.1 && Gmu2pt[g]>(5.77-1.8*TMath::Abs(Gmu2eta[g]))) 
						|| (TMath::Abs(Gmu2eta[g])>2.1 && TMath::Abs(Gmu2eta[g])<2.4 && Gmu2pt[g]>1.8)) 
						&& TMath::Abs(Gtk1eta[g])<2.4 && TMath::Abs(Gtk2eta[g])<2.4 
						&& ((ispp && Gtk1pt[g]>0.5 && Gtk2pt[g]>0.5) || (!ispp && Gtk1pt[g]>0.8 && Gtk2pt[g]>0.8))
					)
					{
					passAcc = 1;
					wPass += weight;
					}
				ExclBAna->Fill();
			}
		}//Gsize loop
	}//Evt loop
	cout<<"wAll: "<<wAll<<endl;
	cout<<"wPass: "<<wPass<<endl;
    fOut->Write();
    fOut->Close();
}
