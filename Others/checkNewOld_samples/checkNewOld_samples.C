#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TLine.h"
#include "iostream"
using namespace std;
void checkNewOld_samples(){
	TString fname = "";
	int opt = 4;
//	fname = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT7to50_BDT15to50_20180223MVA_candWise.root";
//	fname = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_BDT15to50_20180223MVA.root";
	fname = "test.root";
	TFile* inf = new TFile(fname.Data());	
	TTree* nt = (TTree*)inf->Get("ntphi");
	//nt->AddFriend("ntHlt");
	//nt->AddFriend("ntHi");
	//nt->AddFriend("ntSkim");
	//nt->AddFriend("BDTStage1_pt15to50");
	//nt->AddFriend("BDTStage1_pt15to50_20180223MVA");
	TString baseCut="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.&&Btrk2Pt>0.&&abs(Btktkmass-1.019455)<0.015";
	TString evtCut="abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3";
	TString optCut1 = "((Bpt>15&&Bpt<50&&BDTStage1_pt15to50>0.254413))";
	TString optCut2 = "((Bpt>15&&Bpt<50&&BDTStage1_pt15to50_20180223MVA>0.255746))";
	TString cut = baseCut+"&&"+evtCut+"&&"+optCut1;
//	TString cut = baseCut+"&&"+evtCut+"&&"+optCut2;
	TH1D* h = new TH1D("h","",50,5,6);
	h->Sumw2();
	if(opt==1){
		nt->Scan("Bmass",cut); 
	}
	else if(opt==2){
		nt->Project("h","Bmass",cut);
		TCanvas* c = new TCanvas("c","",600,600);
		h->SetMaximum((h->GetBinContent(h->GetMaximumBin()))*1.8);
		h->Draw("pe");
		c->SaveAs("test1.pdf");
		//c->SaveAs("test2.pdf");
	}
	else if(opt==3){
		TString ofname="test.root";
		TFile* outf = TFile::Open(ofname,"recreate");
		float Bmass;
		nt->SetBranchAddress("Bmass",&Bmass);
		TTree* nt_new = nt->CloneTree(0);		
		Long64_t nentries = nt->GetEntries();
		cout<<" -- Event reading"<<endl;
		const int nevt = 29;
		int evtList[nevt] = {
			//pas both
			5339113,
			7699252,
			10885967, 
			42199974, 
			42791637, 
			42849585, 
			45309459, 
			58498544, 
			58742340, 
			70997258, 
			74447441, 
			95435624, 
			96341606, 
			111099164,
			111838226,
			//pass new BDT
			8263858,
			8332868, 
			10360147, 
			42605349, 
			71718335, 
			75692500, 
			75804203, 
			79631824, 
			83898939, 
			92972117, 
			93226677, 
			//pass old BDT
			35840953,
			54642050,
			77310723,
		};

		for(Long64_t i=0;i<nevt;i++){
			nt->GetEntry(evtList[i]);
			cout<<"Bmass: "<<Bmass<<endl;
			nt_new->Fill();
		}
		outf->Write();
		outf->Close();
		cout<<" -- Writing new trees done"<<endl;
	}
	else if(opt==4){
		TH1D* h2 = new TH1D("h2","",50,5,6);
		h2->Sumw2();
		float Bmass;
		float Bpt;
		float Beta;
		float BDTStage1_pt15to50;
		float BDTStage1_pt15to50_20180223MVA;
		Int_t           Bsize;
		Float_t         Btrk1Pt;
		Float_t         Btrk2Pt;
		Float_t         Btrk1Eta;
		Float_t         Btrk2Eta;
		Float_t         Bchi2cl;
		Float_t         BsvpvDistance;
		Float_t         BsvpvDisErr;
		Float_t         Bdtheta;
		Float_t         By;
		Float_t         Btktkmass;
		Float_t         Btktky;
		Float_t         Blxy;
		Float_t         Btrk1Dxy;
		Float_t         Btrk1D0Err;
		Float_t         Btrk2Dxy;
		Float_t         Btrk2D0Err;
		Float_t         Bd0;
		Float_t         Bd0Err;
		Float_t         Btktkpt;
		Float_t         Btktketa;
		Float_t         Balpha;
		Float_t         Bmu1pt;
		Float_t         Bmu2pt;
		nt->SetBranchAddress("Bmass",&Bmass);
		nt->SetBranchAddress("Bpt",&Bpt);
		nt->SetBranchAddress("Beta", &Beta);
		nt->SetBranchAddress("BDTStage1_pt15to50",&BDTStage1_pt15to50);
		nt->SetBranchAddress("BDTStage1_pt15to50_20180223MVA",&BDTStage1_pt15to50_20180223MVA);
		nt->SetBranchAddress("Bsize", &Bsize);
		nt->SetBranchAddress("Btrk1Pt", &Btrk1Pt);
		nt->SetBranchAddress("Btrk2Pt", &Btrk2Pt);
		nt->SetBranchAddress("Btrk1Eta", &Btrk1Eta);
		nt->SetBranchAddress("Btrk2Eta", &Btrk2Eta);
		nt->SetBranchAddress("Bchi2cl", &Bchi2cl);
		nt->SetBranchAddress("BsvpvDistance", &BsvpvDistance);
		nt->SetBranchAddress("BsvpvDisErr", &BsvpvDisErr);
		nt->SetBranchAddress("Bdtheta", &Bdtheta);
		nt->SetBranchAddress("By", &By);
		nt->SetBranchAddress("Btktkmass", &Btktkmass);
		nt->SetBranchAddress("Btktky", &Btktky);
		nt->SetBranchAddress("Blxy", &Blxy);
		nt->SetBranchAddress("Btrk1Dxy", &Btrk1Dxy);
		nt->SetBranchAddress("Btrk1D0Err", &Btrk1D0Err);
		nt->SetBranchAddress("Btrk2Dxy", &Btrk2Dxy);
		nt->SetBranchAddress("Btrk2D0Err", &Btrk2D0Err);
		nt->SetBranchAddress("Bd0", &Bd0);
		nt->SetBranchAddress("Bd0Err", &Bd0Err);
		nt->SetBranchAddress("Btktkpt", &Btktkpt);
		nt->SetBranchAddress("Btktketa", &Btktketa);
		nt->SetBranchAddress("Balpha", &Balpha);
		nt->SetBranchAddress("Bmu1pt", &Bmu1pt);
		nt->SetBranchAddress("Bmu2pt", &Bmu2pt);
		Long64_t nentries = nt->GetEntries();
		//nt->Project("h2","Bmass","BDTStage1_pt15to50>0.254413");
		//nt->Project("h2","Bmass","BDTStage1_pt15to50_20180223MVA>0.255746");
		printf("mass  | pt     | eta    | tk1Pt | tk2Pt | tk1Eta | tk2Eta | tk1Dxy  | tk2Dxy  | abs(phi-PDG) | SVPV   | alpha   | Bd0     | cos(theta) | fit prob | \n");
		for(Long64_t i=0;i<nentries;i++){
			nt->GetEntry(i);
//			if(BDTStage1_pt15to50>0.254413 && BDTStage1_pt15to50_20180223MVA>0.255746){
//			if(BDTStage1_pt15to50>0.254413){
//			if(BDTStage1_pt15to50_20180223MVA>0.255746){
//			if(BDTStage1_pt15to50>0.254413 && BDTStage1_pt15to50_20180223MVA<0.255746){
//			if(BDTStage1_pt15to50_20180223MVA>0.255746 && BDTStage1_pt15to50<0.254413){
			if(1){
				printf("%5.3f | %6.3f | %6.3f | %5.3f | %5.3f | %6.3f | %6.3f | %7.3f | %7.3f | %5.8f   | %6.3f | %5.5f | %7.2f | %5.5f    | %6.3f   |\n", Bmass, Bpt, Beta, Btrk1Pt, Btrk2Pt, Btrk1Eta, Btrk2Eta, Btrk1Dxy/Btrk1D0Err, Btrk2Dxy/Btrk2D0Err, fabs(Btktkmass-1.019455), BsvpvDistance/BsvpvDisErr, Balpha, Bd0/Bd0Err, cos(Bdtheta), Bchi2cl);
//				printf("mass: %f, pt: %f, eta: %f\n", Bmass, Bpt, Beta);
//printf("tk1Pt: %f, tk2Pt: %f, tk1Eta: %f, tk2Eta: %f, tk1Dxy: %f, tk2Dxy: %f, |phi-PDG|: %f, SVPV: %f, alpha: %f, d0: %f, cos(theta): %f, fit prob: %f\n", Btrk1Pt, Btrk2Pt, Btrk1Eta, Btrk2Eta, Btrk1Dxy/Btrk1D0Err, Btrk2Dxy/Btrk2D0Err, fabs(Btktkmass-1.019455), BsvpvDistance/BsvpvDisErr, Balpha, Bd0/Bd0Err, cos(Bdtheta), Bchi2cl);
				h2->Fill(Bmass);
			}
		}
		TCanvas* c2 = new TCanvas("c2","",600,600);
		//h2->SetMaximum((h2->GetBinContent(h2->GetMaximumBin()))*1.8);
		h2->SetMaximum(14);
		TLine* l1 = new TLine(5.367-0.05,0,5.367-0.05,14);
		l1->SetLineWidth(2);
		l1->SetLineStyle(2);
		l1->SetLineColor(kGreen+1);
		TLine* l2 = new TLine(5.367+0.05,0,5.367+0.05,14);
		l2->SetLineWidth(2);
		l2->SetLineStyle(2);
		l2->SetLineColor(kGreen+1);
		h2->Draw("pe");
		l1->Draw();
		l2->Draw();
		c2->SaveAs("test.pdf");
		}


		}
