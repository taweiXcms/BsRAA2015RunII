#include "iostream"
#include "TStyle.h"
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TPad.h"
using namespace std;

TString fname = "";
TString baseCut = "TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.0&&Btrk2Pt>0.0";
TString evtCut="abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter";
TString hltCut="(HLT_HIL1DoubleMu0ForPPRef_v1)";
TString	BDTcut = "";
float bPDG = 5.36682;
TString var = "Bmass";
int bin = 100;
float bmin = 5.;
float bmax = 6.;
TString tktkvar = "abs(Btktkmass-1.019455)";
int tktkbin = 100;
float tktkbmin = 0.;
float tktkbmax = 0.05;
void settex(TLatex* tex);
TString bdtfile = "";
TString coll = "pp";
//TString coll = "PbPb";
int type = 0;
bool readfile = 0;

void kkmass(){
	gStyle->SetHistLineWidth(2);

	float ptmin = 7; float ptmax = 15; float cutvalpp = 0.191055; float cutvalpbpb = 0.213755;
	//float ptmin = 15; float ptmax = 50; float cutvalpp = 0.208973; float cutvalpbpb = 0.254413;
    fname = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs.root";
    bdtfile = Form("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/nominal/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more_evtWiseProd/tmvaVal/prod/Bntuple20180316_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs_%s_BDT%.0fto%.0f.root",coll.Data(),ptmin,ptmax);
    BDTcut = Form("abs(Btktkmass-1.019455)<0.015&&Btrk1highPurity&&Btrk2highPurity&&BDTStage1_pt%.0fto%.0f>%f",ptmin,ptmax,cutvalpp);
    if(coll == "PbPb") BDTcut = Form("abs(Btktkmass-1.019455)<0.015&&Btrk1highPurity&&Btrk2highPurity&&BDTStage1_pt%.0fto%.0f>%f",ptmin,ptmax,cutvalpbpb);

	// customized setting
	if(type==1){ 
		fname = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs.root";
		bdtfile = Form("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/nominal/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more_evtWiseProd/tmvaVal/prod/Bntuple20180316_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs_%s_BDT%.0fto%.0f.root",coll.Data(),ptmin,ptmax);
    	BDTcut = Form("abs(Btktkmass-1.019455)<0.015&&Btrk1highPurity&&Btrk2highPurity&&BDTStage1_pt%.0fto%.0f>%f",ptmin,ptmax,cutvalpp);
	    if(coll == "PbPb") BDTcut = Form("abs(Btktkmass-1.019455)<0.015&&Btrk1highPurity&&Btrk2highPurity&&BDTStage1_pt%.0fto%.0f>%f",ptmin,ptmax,cutvalpbpb);
	}

	BDTcut = Form("%s&&Bpt>%.0f&&Bpt<%.0f&&%s&&%s",BDTcut.Data(),ptmin,ptmax,evtCut.Data(),hltCut.Data());
	TCanvas* c = new TCanvas("c","c",1200,600);
    c->Divide(2,1); c->cd(1);

	TFile* f = new TFile(fname.Data());
	TTree* nt = (TTree*)f->Get("ntphi");
	nt->AddFriend("ntHlt");
	nt->AddFriend("ntHi");
	nt->AddFriend("ntSkim");
	TFile* fbdt = new TFile(bdtfile.Data());
	TTree* ntbdt = (TTree*)fbdt->Get(Form("BDTStage1_pt%.0fto%.0f",ptmin,ptmax));
	TString outputf = Form("plots/np_compare_%s_%.0f_%.0f_%d.root",coll.Data(),ptmin,ptmax,type);
    TFile* outf = new TFile();
	TH1D* f1 = new TH1D("f1","",bin,bmin,bmax);
	TH1D* f2 = new TH1D("f2","",bin,bmin,bmax);
	TH1D* f3 = new TH1D("f3","",bin,bmin,bmax);
	TH1D* f4 = new TH1D("f4","",bin,bmin,bmax);
	TH1D* f5 = new TH1D("f5","",bin,bmin,bmax);
	TH1D* tktkf1 = new TH1D("tktkf1","",tktkbin,tktkbmin,tktkbmax);
	TH1D* tktkf2 = new TH1D("tktkf2","",tktkbin,tktkbmin,tktkbmax);
	TH1D* tktkf3 = new TH1D("tktkf3","",tktkbin,tktkbmin,tktkbmax);
	TH1D* tktkf4 = new TH1D("tktkf4","",tktkbin,tktkbmin,tktkbmax);
	TH1D* tktkf5 = new TH1D("tktkf5","",tktkbin,tktkbmin,tktkbmax);
	Long64_t nentries = 1000000000;
	if(!readfile){
		nt->AddFriend(ntbdt);
		//nt->Project("f1",Form("%s",var.Data()),Form("%s&&%s",baseCut.Data(),BDTcut.Data()),"",nentries);
		nt->Project("f2",Form("%s",var.Data()),Form("Bgen==23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"",nentries);
		nt->Project("f3",Form("%s",var.Data()),Form("Bgen!=23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"",nentries);
		nt->Project("f4",Form("%s",var.Data()),Form("(int(Bgen/100)%s100==33)&&Bgen!=23333&&%s&&%s","%",baseCut.Data(),BDTcut.Data()),"",nentries);
		nt->Project("f5",Form("%s",var.Data()),Form("(int(Bgen/100)%s100==22)&&Bgen!=23333&&%s&&%s","%",baseCut.Data(),BDTcut.Data()),"",nentries);
		//nt->Project("tktkf1",Form("%s",tktkvar.Data()),Form("%s&&%s",baseCut.Data(),BDTcut.Data()),"",nentries);
		nt->Project("tktkf2",Form("%s",tktkvar.Data()),Form("Bgen==23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"",nentries);
		nt->Project("tktkf3",Form("%s",tktkvar.Data()),Form("Bgen!=23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"",nentries);
		nt->Project("tktkf4",Form("%s",tktkvar.Data()),Form("(int(Bgen/100)%s100==33)&&Bgen!=23333&&%s&&%s","%",baseCut.Data(),BDTcut.Data()),"",nentries);
		nt->Project("tktkf5",Form("%s",tktkvar.Data()),Form("(int(Bgen/100)%s100==22)&&Bgen!=23333&&%s&&%s","%",baseCut.Data(),BDTcut.Data()),"",nentries);
    	outf = new TFile(outputf.Data(),"recreate");
		outf->cd();
	}

	if(readfile){
	    outf = new TFile(outputf.Data());
		tktkf1 = (TH1D*)outf->Get("tktkf1");
		tktkf2 = (TH1D*)outf->Get("tktkf2");
		tktkf3 = (TH1D*)outf->Get("tktkf3");
		tktkf4 = (TH1D*)outf->Get("tktkf4");
		tktkf5 = (TH1D*)outf->Get("tktkf5");
		f1 = (TH1D*)outf->Get("f1");
		f2 = (TH1D*)outf->Get("f2");
		f3 = (TH1D*)outf->Get("f3");
		f4 = (TH1D*)outf->Get("f4");
		f5 = (TH1D*)outf->Get("f5");
	}

	tktkf2->SetMaximum(max(tktkf2->GetMaximum(), tktkf3->GetMaximum())*1.2);
	tktkf2->SetLineColor(kRed+1);
	tktkf3->SetLineColor(kGreen+3);
	tktkf4->SetLineColor(kBlue+2);
	tktkf5->SetLineColor(kYellow+1);
	tktkf2->SetXTitle(Form("%s",tktkvar.Data()));
	tktkf2->Draw("");
	tktkf3->Draw("same");
	tktkf4->Draw("same");
	tktkf5->Draw("same");
	TLegend *leg = new TLegend(0.3,0.75,0.75,0.9,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	//leg->AddEntry(f1,"All","l");
	leg->AddEntry(tktkf2,"Signal","l");
	leg->AddEntry(tktkf3,"Not Signal","l");
	leg->AddEntry(tktkf4,"Not Signal, mu matched Bs ","l");
	leg->AddEntry(tktkf5,"Not Signal, mu matched jpsi ","l");
	leg->Draw();
	if(0){
	//if(readfile){
		float inttktkf1 = tktkf1->Integral(1,int(tktkf2->GetRMS()*5/((tktkbmax-tktkbmin)/tktkbin)))/tktkf1->Integral();
		float inttktkf2 = tktkf2->Integral(1,int(tktkf2->GetRMS()*5/((tktkbmax-tktkbmin)/tktkbin)))/tktkf2->Integral();
		float inttktkf3 = tktkf3->Integral(1,int(tktkf2->GetRMS()*5/((tktkbmax-tktkbmin)/tktkbin)))/tktkf3->Integral();
		float inttktkf4 = tktkf4->Integral(1,int(tktkf2->GetRMS()*5/((tktkbmax-tktkbmin)/tktkbin)))/tktkf4->Integral();
		float inttktkf5 = tktkf5->Integral(1,int(tktkf2->GetRMS()*5/((tktkbmax-tktkbmin)/tktkbin)))/tktkf5->Integral();
		TLatex* tex = new TLatex(0.45,0.7,Form("rms=%.4f,%.4f",tktkf2->GetRMS(),tktkf3->GetRMS())); 
		settex(tex);
		tex->Draw();
		tex = new TLatex(0.45,0.65,Form("int(5*sig rms)=%.2f,%.2f",inttktkf2,inttktkf3)); 
		settex(tex);
		tex->Draw();
		tex = new TLatex(0.5,0.4,Form("%s",coll.Data())); 
		settex(tex);
		tex->SetTextSize(0.06);
		tex->Draw();
		cout<<tktkf1->GetRMS()<<endl;	cout<<tktkf2->GetRMS()<<endl;	cout<<tktkf3->GetRMS()<<endl;   cout<<tktkf4->GetRMS()<<endl;   cout<<tktkf5->GetRMS()<<endl;
		cout<<inttktkf1<<endl;	cout<<inttktkf2<<endl;	cout<<inttktkf3<<endl;  cout<<inttktkf4<<endl;  cout<<inttktkf5<<endl;
	}
	c->cd(2);
	f2->SetMaximum(max(f2->GetMaximum(), f3->GetMaximum())*1.2);
	f2->SetLineColor(kRed+1);
	f3->SetLineColor(kGreen+3);
	f4->SetLineColor(kBlue+2);
	f5->SetLineColor(kYellow+1);
	f2->SetXTitle(Form("%s",var.Data()));
	f2->Draw("");
	f3->Draw("same");
	f4->Draw("same");
	f5->Draw("same");
	if(0){
	//if(readfile){
		int sbin = int((bPDG-0.05-bmin)/((bmax-bmin)/bin));
		int ebin = int((bPDG+0.05-bmin)/((bmax-bmin)/bin));
		float intf1 = f1->Integral(sbin,ebin)/f1->Integral();
		float intf2 = f2->Integral(sbin,ebin)/f2->Integral();
		float intf3 = f3->Integral(sbin,ebin)/f3->Integral();
		float intf4 = f4->Integral(sbin,ebin)/f4->Integral();
		float intf5 = f5->Integral(sbin,ebin)/f5->Integral();
		cout<<f1->GetRMS()<<endl;	cout<<f2->GetRMS()<<endl;	cout<<f3->GetRMS()<<endl;	cout<<f4->GetRMS()<<endl;   cout<<f5->GetRMS()<<endl;
		cout<<intf1<<endl;	cout<<intf2<<endl;	cout<<intf3<<endl;	cout<<intf4<<endl;  cout<<intf5<<endl;
		TLatex* tex = new TLatex(0.5,0.65,Form("int(+-0.05)=%.2f,%.2f",intf2,intf3)); 
		settex(tex);
		tex->Draw();
		tex = new TLatex(0.5,0.6,Form("ratio=%.2f",intf3/intf2)); 
		settex(tex);
		tex->Draw();
	}
	if(!readfile){	
		f1->Write();
		f2->Write();
		f3->Write();
		f4->Write();
		f5->Write();
		tktkf1->Write();
		tktkf2->Write();
		tktkf3->Write();
		tktkf4->Write();
		tktkf5->Write();
	}
	c->SaveAs(Form("plots/np_compare_%s_%.0f_%.0f_%d.pdf",coll.Data(),ptmin,ptmax,type));
}
void settex(TLatex* tex){
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
}
