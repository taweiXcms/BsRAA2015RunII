#include "iostream"
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TPad.h"
using namespace std;

bool ispp = 1;
TString fname = "";
TString baseCut = "TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.5&&Btrk2Pt>0.5";
TString evtCut="abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter";
TString hltCut="(HLT_HIL1DoubleMu0ForPPRef_v1)";
TString	BDTcut = "BDTStage1_pt15to50>0.209775";
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
TString bdtfile = "../../TMVA_Bs-20171122-d4-1550-nominal/tmvaVal/Bntuple20171209_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs_BDT.root";
int type = 3;
void kkmass(){
	if(!ispp) BDTcut = "BDTStage1_pt15to50>0.303985";
	if(type==1){
		bdtfile = "../../TMVA_Bs-20180223-d4-1550-nominal-tktkmass0p015/tmvaVal/prod/Bntuple20171209_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs_BDT.root";
		BDTcut = "BDTStage1_pt15to50>0.230537&&abs(Btktkmass-1.019455)<0.015";
	}
	if(type==2){
		bdtfile = "../../TMVA_Bs-20180223-d4-1550-nominal-tktkmass0p015-more/tmvaVal/prod/Bntuple20171209_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs_BDT.root";
		BDTcut = "BDTStage1_pt15to50>0.328975&&abs(Btktkmass-1.019455)<0.015";
	}
	if(type==3){
		bdtfile = "../../TMVA_Bs-20180223-d4-1550-nominal-tktkmass0p025/tmvaVal/prod/Bntuple20171209_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs_BDT.root";
		BDTcut = "BDTStage1_pt15to50>0.203605&&abs(Btktkmass-1.019455)<0.025";
	}
	if(type==4){
		bdtfile = "../../TMVA_Bs-20180223-d4-1550-nominal-tktkmass0p025-more/tmvaVal/prod/Bntuple20171209_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs_BDT.root";
		BDTcut = "BDTStage1_pt15to50>0.305686&&abs(Btktkmass-1.019455)<0.025";
	}
	if(type==5){
		bdtfile = "../../TMVA_Bs-20180223-d4-1550-nominal-tktkmass0p05/tmvaVal/prod/Bntuple20171209_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs_BDT.root";
		BDTcut = "BDTStage1_pt15to50>0.206883&&abs(Btktkmass-1.019455)<0.05";
	}
	if(type==6){
		bdtfile = "../../TMVA_Bs-20180223-d4-1550-nominal-tktkmass0p1/tmvaVal/prod/Bntuple20171209_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs_BDT.root";
		BDTcut = "BDTStage1_pt15to50>0.209775&&abs(Btktkmass-1.019455)<0.1";
	}
	BDTcut = Form("%s&&Bpt>15&&Bpt<50&&%s&&%s",BDTcut.Data(),evtCut.Data(),hltCut.Data());
	fname = "~/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171209_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs_BDT15to50.root";
	if(!ispp)fname = "~/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/";
	TCanvas* c = new TCanvas("c","c",1200,600);
    c->Divide(2,1); c->cd(1);
	TFile* f = new TFile(fname.Data());
	TTree* nt = (TTree*)f->Get("ntphi");
    nt->AddFriend("ntHlt");
    nt->AddFriend("ntHi");
    nt->AddFriend("ntSkim");
    nt->AddFriend("BDTStage1_pt15to50");
	//TFile* fbdt = new TFile(bdtfile.Data());
	//TTree* ntbdt = (TTree*)fbdt->Get("BDTStage1_pt15to50");
	//nt->AddFriend(ntbdt);
	TH1D* tktkf1 = new TH1D("tktkf1","",tktkbin,tktkbmin,tktkbmax);
	TH1D* tktkf2 = new TH1D("tktkf2","",tktkbin,tktkbmin,tktkbmax);
	TH1D* tktkf3 = new TH1D("tktkf3","",tktkbin,tktkbmin,tktkbmax);
	TH1D* f1 = new TH1D("f1","",bin,bmin,bmax);
	TH1D* f2 = new TH1D("f2","",bin,bmin,bmax);
	TH1D* f3 = new TH1D("f3","",bin,bmin,bmax);
	nt->Project("f1",Form("%s",var.Data()),Form("%s&&%s",baseCut.Data(),BDTcut.Data()),"");
	nt->Project("f2",Form("%s",var.Data()),Form("Bgen==23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"");
	nt->Project("f3",Form("%s",var.Data()),Form("Bgen!=23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"");
	nt->Project("tktkf1",Form("%s",tktkvar.Data()),Form("%s&&%s",baseCut.Data(),BDTcut.Data()),"");
	nt->Project("tktkf2",Form("%s",tktkvar.Data()),Form("Bgen==23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"");
	nt->Project("tktkf3",Form("%s",tktkvar.Data()),Form("Bgen!=23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"");
//	nt->Project("f1",Form("%s",var.Data()),Form("%s&&%s",baseCut.Data(),BDTcut.Data()),"",10000000);
//	nt->Project("f2",Form("%s",var.Data()),Form("Bgen==23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"",10000000);
//	nt->Project("f3",Form("%s",var.Data()),Form("Bgen!=23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"",10000000);
//	nt->Project("tktkf1",Form("%s",tktkvar.Data()),Form("%s&&%s",baseCut.Data(),BDTcut.Data()),"",10000000);
//	nt->Project("tktkf2",Form("%s",tktkvar.Data()),Form("Bgen==23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"",10000000);
//	nt->Project("tktkf3",Form("%s",tktkvar.Data()),Form("Bgen!=23333&&%s&&%s",baseCut.Data(),BDTcut.Data()),"",10000000);
	tktkf2->SetMaximum(max(tktkf2->GetMaximum(), tktkf3->GetMaximum())*1.2);
	tktkf1->SetLineWidth(2);
	tktkf2->SetLineWidth(2);
	tktkf3->SetLineWidth(2);
	tktkf2->SetLineColor(2);
	tktkf3->SetLineColor(4);
	tktkf2->SetXTitle(Form("%s",var.Data()));
	tktkf2->Draw("");
	tktkf3->Draw("same");
	TLegend *leg = new TLegend(0.45,0.75,0.75,0.9,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	//leg->AddEntry(f1,"Pass BDT","l");
	leg->AddEntry(tktkf2,"Signal pass BDT","l");
	leg->AddEntry(tktkf3,"Not Signal pass BDT","l");
	leg->Draw();
	TLatex* tex = new TLatex(0.45,0.7,Form("rms=%.4f,%.4f",tktkf2->GetRMS(),tktkf3->GetRMS())); 
	settex(tex);
	tex->Draw();
	float inttktkf1 = tktkf1->Integral(1,int(tktkf2->GetRMS()*5/((tktkbmax-tktkbmin)/tktkbin)))/tktkf1->Integral();
	float inttktkf2 = tktkf2->Integral(1,int(tktkf2->GetRMS()*5/((tktkbmax-tktkbmin)/tktkbin)))/tktkf2->Integral();
	float inttktkf3 = tktkf3->Integral(1,int(tktkf2->GetRMS()*5/((tktkbmax-tktkbmin)/tktkbin)))/tktkf3->Integral();
	tex = new TLatex(0.45,0.65,Form("int(5*sig rms)=%.2f,%.2f",inttktkf2,inttktkf3)); 
	settex(tex);
	tex->Draw();
	cout<<tktkf1->GetRMS()<<endl;	cout<<tktkf2->GetRMS()<<endl;	cout<<tktkf3->GetRMS()<<endl;
	cout<<inttktkf1<<endl;	cout<<inttktkf2<<endl;	cout<<inttktkf3<<endl;
	c->cd(2);
	f2->SetMaximum(max(f2->GetMaximum(), f3->GetMaximum())*1.2);
	f1->SetLineWidth(2);
	f2->SetLineWidth(2);
	f3->SetLineWidth(2);
	f2->SetLineColor(2);
	f3->SetLineColor(4);
	f2->SetXTitle(Form("%s",var.Data()));
	f2->Draw("");
	f3->Draw("same");
	int sbin = int((bPDG-0.05-bmin)/((bmax-bmin)/bin));
	int ebin = int((bPDG+0.05-bmin)/((bmax-bmin)/bin));
	float intf1 = f1->Integral(sbin,ebin)/f1->Integral();
	float intf2 = f2->Integral(sbin,ebin)/f2->Integral();
	float intf3 = f3->Integral(sbin,ebin)/f3->Integral();
	cout<<f1->GetRMS()<<endl;	cout<<f2->GetRMS()<<endl;	cout<<f3->GetRMS()<<endl;
	cout<<intf1<<endl;	cout<<intf2<<endl;	cout<<intf3<<endl;
	tex = new TLatex(0.5,0.65,Form("int(+-0.05)=%.2f,%.2f",intf2,intf3)); 
	settex(tex);
	tex->Draw();
	tex = new TLatex(0.5,0.6,Form("ratio=%.2f",intf3/intf2)); 
	settex(tex);
	tex->Draw();
	if(ispp) c->SaveAs(Form("np_compare_pp_%d.pdf",type));
	else c->SaveAs(Form("np_compare_pbpb_%d.pdf",type));
}
void settex(TLatex* tex){
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
}
