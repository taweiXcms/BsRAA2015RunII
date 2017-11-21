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

double minhisto = 5.0;
double maxhisto = 5.6;

TString infilepp = "/data/cdzn/NP_Background/pp/BJpsiMM_pp_NP.root";
//TString infilePbPb = "/data/cdzn/NP_Background/PbPb/BJpsiMM_PbPb_nonprompt_09_12.root";                                                                                                                                                                   
//TString infilePbPb = "/data/cdzn/NP_Background/PbPb/BJpsiMM_PbPb_nonprompt_12_15.root";
 TString infilePbPb = "/data/cdzn/NP_Background/PbPb/BJpsiMM_PbPb_nonprompt_15_30.root";
//TString infilePbPb = "/data/cdzn/NP_Background/PbPb/BJpsiMM_PbPb_nonprompt_30.root";
// TString infilePbPb = "/data/cdzn/NP_Background/PbPb/BJpsiMM_PbPb_nonprompt_merged.root";

//bool ispp = true;
bool ispp = true;

void fitAll(){
	TFile* outf;
	if(ispp) outf = new TFile(Form("plotspp/fitNP_pp.root"), "recreate");
	else outf = new TFile(Form("plotsPbPb/fitNP_PbPb.root"), "recreate");

	gStyle->SetOptStat(0);
	TFile* inf;
	if(ispp) inf = new TFile(infilepp.Data());
	else inf = new TFile(infilePbPb.Data());
	
	//TH1D* Bnosig = (TH1D*)inf->Get("BmassBs_nosig");
	TH1D* cp0 = (TH1D*)inf->Get("BmassBsPiK");
	TH1D* cp1 = (TH1D*)inf->Get("BmassBsKK");
	TH1D* cp2 = (TH1D*)inf->Get("BmassBsKKfake_binfo");
	TH1D* cp3 = (TH1D*)inf->Get("BmassBsXpipi");
	TH1D* cp4 = (TH1D*)inf->Get("BmassBsKKX");
	TH1D* h = (TH1D*)cp1->Clone();
	h->Add(cp0);
	h->Add(cp2);
	h->Add(cp3);
	h->Add(cp4);
	h->GetXaxis()->SetRangeUser(minhisto, maxhisto);
	TH1D* hempty = new TH1D("", "", 50, minhisto, maxhisto);
	TCanvas* c = new TCanvas("c", "", 600, 600);
	c->cd();
	
TString iNP= "3.12764e1*TMath::Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*TMath::Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2) +2.11124e2+[0]";
TF1 *f = new TF1(Form("f"),"[0]*([7]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*TMath::Gaus(x,[12],[8])/(sqrt(2*3.14159)*[8]))+ [3]+[4]*x+[5]*x*x + [11]*("+iNP+")");


  /*  //error fn
        f->SetParLimits(0, 1e0, 1e4);
        f->SetParLimits(1, 4.9, 5.4);
        f->SetParLimits(2, -10, 0.1);
        f->SetParameter(0,200);
        f->SetParameter(1,5.20);
        f->SetParameter(2,-2);

        f->SetParLimits(3, 1e-2, 1e4);
        f->SetParLimits(4, 0, 1);
        f->SetParLimits(5, 4.9, 5.4);
        f->SetParLimits(6,0.005,0.5);
        f->SetParLimits(7,0.005,0.5);
        f->SetParameter(3,1e1);
        f->SetParameter(4,0.5);
        f->SetParameter(5,5.20);
        f->SetParameter(6,0.05);
        f->SetParameter(7,0.05);
*/
//        f->SetParLimits(9, 0, 1e5);
//        f->SetParLimits(10, -500,  100);
//        f->SetParameter(9,1e3);
//        f->SetParameter(10,-1);
        f->SetParLimits(4,-1000,0);
        f->SetParLimits(2,0.01,0.5);
        f->SetParLimits(8,0.01,1.0);
        f->SetParLimits(7,0,1);
        f->SetParameter(0,100);
        f->SetParameter(1,5.25);
        f->SetParameter(2,0.002);
        f->SetParameter(8,0.003);
        f->SetParameter(1,5.25);
        f->SetParLimits(11,0,1000);
        f->SetParLimits(12,5.2,5.4);

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
	cp0->SetMarkerColor(kRed);
	cp0->SetMarkerStyle(21);
	cp0->Draw("same e");

	cp1->SetMarkerColor(kBlue);
	cp1->SetMarkerStyle(22);
	cp1->Draw("same e");
 
	cp2->SetMarkerColor(kYellow);
	cp2->SetMarkerStyle(23);
	cp2->Draw("same e");


	cp3->SetMarkerColor(kMagenta);
	cp3->SetMarkerStyle(24);
	cp3->Draw("same e");

	cp4->SetMarkerColor(kGreen);
	cp4->SetMarkerStyle(25);
	cp4->Draw("same e");

        h->Draw("same e");
	f->Draw("same");

	TLegend* leg = new TLegend(0.57,0.56,0.64,0.86,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.03);
	leg->SetTextFont(32);
	leg->SetFillStyle(0);
	leg->AddEntry(h,"Peaking background stack:","p");
        leg->AddEntry(cp0,"B_{s}^{0} to Jpsi PiK","p");
        leg->AddEntry(cp1,"B_{s}^{0} to Jpsi KK (not phi)","p");
        leg->AddEntry(cp2,"B_{s}^{0} to Jpsi K (B+) and K","p");
        leg->AddEntry(cp3,"B_{s}^{0} to Jpsi pipi","p");
        leg->AddEntry(cp4,"B_{s}^{0} to Jpsi KKX","p");
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
	if(ispp) c->SaveAs(Form("plotspp/fitNP_pp.png"));
	else c->SaveAs(Form("plotsPbPb/fitNP_PbPb.png"));
}

