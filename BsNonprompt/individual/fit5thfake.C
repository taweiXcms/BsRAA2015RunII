#include <TCanvas.h>
#include <TPad.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TLine.h>
#include <TBox.h>
#include <TCut.h>
#include <TMath.h>
#include <TStyle.h>
#include <TF1.h>
#include <TH1.h>
#include <TFile.h>
#include <TApplication.h>
using namespace std;
double minhisto = 4.6;
double maxhisto = 5.6;


TString infilepp = "/data/cdzn/NP_Background/pp/BJpsiMM_pp_NP.root";
//TString infilePbPb = "/data/cdzn/NP_Background/PbPb/BJpsiMM_PbPb_nonprompt_09_12.root";                                                                                                                                                                   
//TString infilePbPb = "/data/cdzn/NP_Background/PbPb/BJpsiMM_PbPb_nonprompt_12_15.root";
//TString infilePbPb = "/data/cdzn/NP_Background/PbPb/BJpsiMM_PbPb_nonprompt_15_30.root";
//TString infilePbPb = "/data/cdzn/NP_Background/PbPb/BJpsiMM_PbPb_nonprompt_30.root";
 TString infilePbPb = "/data/cdzn/NP_Background/PbPb/BJpsiMM_PbPb_nonprompt_merged.root";

bool ispp = false;
//bool ispp = true;

void fit5thfake(){
	TFile* outf;
	if(ispp) outf = new TFile(Form("plotspp/fitNP_pp.root"), "recreate");
	else outf = new TFile(Form("plotsPbPb/fitNP_PbPb.root"), "recreate");

	gStyle->SetOptStat(0);
	TFile* inf;
	if(ispp) inf = new TFile(infilepp.Data());
	else inf = new TFile(infilePbPb.Data());
	
	//TH1D* Bnosig = (TH1D*)inf->Get("BmassBs_nosig");
	TH1D* cp4 = (TH1D*)inf->Get("BmassBsKKX");
	TH1D* h = (TH1D*)cp4->Clone();
	h->GetXaxis()->SetRangeUser(minhisto, maxhisto);
	TH1D* hempty = new TH1D("", "", 50, minhisto, maxhisto);
	TCanvas* c = new TCanvas("c", "", 600, 600);
	c->cd();
	
    //TF1* f = new TF1(Form("f"),"[0]*TMath::Erf((x-[1])/[2]) + [0] + [3]*([4]*Gaus(x,[5],[6])/(sqrt(2*3.14159)*[6])+(1-[4])*Gaus(x,[5],[7])/(sqrt(2*3.14159)*[7])) + [9]+[10]*x ");
//    TF1* f = new TF1(Form("f"),"[0]*TMath::Erf((x-[1])/[2]) + [0] + [3]*([4]*Gaus(x,[5],[6])/(sqrt(2*3.14159)*[6])+(1-[4])*Gaus(x,[5],[7])/(sqrt(2*3.14159)*[7]))");
TString iNP= "3.12764e1*TMath::Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*TMath::Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2) +2.11124e2+[0]";
TF1 *f = new TF1(Form("f"),"[0]*([7]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*TMath::Gaus(x,[12],[8])/(sqrt(2*3.14159)*[8]))+ [3]+[4]*x+[5]*x*x + [11]*("+iNP+")");


if(ispp){
        f->SetParLimits(4,-1000,0);
        f->SetParLimits(2,0.01,0.5);
        f->SetParLimits(8,0.01,1.0);
        f->SetParLimits(7,0,1);
        f->SetParameter(0,100);
        f->SetParameter(1,5.36);
        f->SetParameter(2,0.02);
        f->SetParameter(8,0.03);
        f->SetParLimits(11,0,1000);
        f->SetParLimits(12,5.2,5.4);
}else{
        f->SetParLimits(4,-1000,0);                                                                                                           
        f->SetParLimits(2,0.001,0.5);
        f->SetParLimits(8,0.001,1.0);
        f->SetParLimits(7,0,1);
        f->SetParameter(0,100);
        f->SetParameter(1,5.36);
        f->SetParameter(2,0.02);
        f->SetParameter(8,0.03);
        f->SetParLimits(11,0,1000);
        f->SetParLimits(12,5.,5.3);
}
        h->Fit(Form("f"),"q","",minhisto,maxhisto);
        h->Fit(Form("f"),"q","",minhisto,maxhisto);
        h->Fit(Form("f"),"L q","",minhisto,maxhisto);
        h->Fit(Form("f"),"L q","",minhisto,maxhisto);
        h->Fit(Form("f"),"L q","",minhisto,maxhisto);
        h->Fit(Form("f"),"L m","",minhisto,maxhisto);
        h->SetMarkerSize(0.8);
        h->SetMarkerStyle(20);

	//print out the fitted function
	printf(Form("%.6f*TMath::Erf((x-%.6f)/%.6f) + %.6f + %.6f*(%.6f*Gaus(x,%.6f,%.6f)/(sqrt(2*3.14159)*%.6f)+(1-%.6f)*Gaus(x,%.6f,%.6f)/(sqrt(2*3.14159)*%.6f)) \n", 
		f->GetParameter(0),
		f->GetParameter(1),
		f->GetParameter(2),
		f->GetParameter(0),
		f->GetParameter(3),
		f->GetParameter(4),
		f->GetParameter(5),
		f->GetParameter(6),
		f->GetParameter(6),
		f->GetParameter(4),
		f->GetParameter(5),
		f->GetParameter(7),
		f->GetParameter(7)
		));

        hempty->SetXTitle("m_{#mu#muKK} (GeV/c^{2})");
        hempty->SetYTitle("Entries / (5 MeV/c^{2})");
        hempty->GetXaxis()->CenterTitle();
        hempty->GetYaxis()->CenterTitle();
        hempty->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
        hempty->GetXaxis()->SetTitleOffset(1.2);
        hempty->GetYaxis()->SetTitleOffset(1.2);
        hempty->GetXaxis()->SetLabelOffset(0.004);
        hempty->GetYaxis()->SetLabelOffset(0.004);
        hempty->GetXaxis()->SetTitleSize(0.035);
        hempty->GetYaxis()->SetTitleSize(0.035);
        hempty->GetXaxis()->SetTitleFont(32);
        hempty->GetYaxis()->SetTitleFont(32);
        hempty->GetXaxis()->SetLabelFont(32);
        hempty->GetYaxis()->SetLabelFont(32);
        hempty->GetXaxis()->SetLabelSize(0.03);
        hempty->GetYaxis()->SetLabelSize(0.03);
        hempty->SetMarkerSize(0.01);
        hempty->SetMarkerStyle(20);
        hempty->SetStats(0);

        hempty->SetMaximum(h->GetMaximum()*1.2);
//	hempty->SetMaximum(Bnosig->GetMaximum()*1.2);
	hempty->Draw();
	//Bnosig->Draw("same e");

	cp4->SetMarkerColor(kGreen);
	cp4->SetMarkerStyle(25);
	cp4->Draw("same e");

        h->Draw("same e");
	f->Draw("same");
        TLegend* leg = new TLegend(0.67,0.75,0.75,0.86,NULL,"brNDC");
        //TLegend(0.57,0.56,0.64,0.86,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.03);
	leg->SetTextFont(32);
	leg->SetFillStyle(0);
	leg->AddEntry(h,"Peaking background stack:","p");
        leg->AddEntry(cp4,"5.case: B_{s}^{0} to Jpsi K K X","p");
	TLatex * tlatex;
	if(ispp) tlatex=new TLatex(0.58,0.90,"pp MC");
	else tlatex=new TLatex(0.58,0.90,"PbPb MC");
	tlatex->SetNDC();
	tlatex->SetTextColor(1);
	tlatex->SetTextFont(42);
	tlatex->SetTextSize(0.04);
	tlatex->Draw();
	leg->AddEntry(f,"Fit","l");
	leg->Draw("same");

	outf->cd();
	h->Write();
	f->Write();
	if(ispp) c->SaveAs(Form("plotspp/5thfitNP_pp.png"));
	else c->SaveAs(Form("plotsPbPb/5thfitNP_PbPb.png"));
}

