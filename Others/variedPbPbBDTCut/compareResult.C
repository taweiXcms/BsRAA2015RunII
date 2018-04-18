#include "iostream"
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
using namespace std;
float readfile(TString folder);
void compareResult(){
//	TH1D* hCompare = new TH1D("hCompare","",21, -0.105, 0.105);
	TH1D* hCompare = new TH1D("hCompare","",11, -0.055, 0.055);
	hCompare->SetYTitle("extracted yield difference(%)");
	hCompare->SetXTitle("cut modified value");
	hCompare->SetMaximum(1);
	hCompare->SetMinimum(-1);
    hCompare->SetMarkerSize(2.);
    hCompare->SetMarkerStyle(33);
    hCompare->SetMarkerColor(kMagenta+2);
    hCompare->SetLineColor(kMagenta+2);
	TString folder = "";
	float nominal = readfile("Var0p00");	
	float varied = 0;
	int iBin = 1;
//	for(int i = 10; i > 0; i--){
	for(int i = 5; i > 0; i--){
		folder = Form("Varm0p%d%d",i/10,i%10);
		cout<<folder<<endl;	
		varied = readfile(folder);
		hCompare->SetBinContent(iBin, (varied-nominal)/nominal);
		iBin++;
	}
	
	folder = "Var0p00";
	cout<<folder<<endl;
	varied = readfile(folder);
	hCompare->SetBinContent(iBin, (varied-nominal)/nominal);
	iBin++;
//	for(int i = 1; i <= 10; i++){
	for(int i = 1; i <= 5; i++){
		folder = Form("Varp0p%d%d",i/10,i%10);
		cout<<folder<<endl;
		varied = readfile(folder);
		hCompare->SetBinContent(iBin, (varied-nominal)/nominal);
		iBin++;
	}
	TCanvas*c = new TCanvas("c","",600,600); c->cd();
	hCompare->Draw("p");
	c->SaveAs("result.pdf");

}
float readfile(TString folder){
	TFile* fitfile = new TFile(Form("%s/output.root",folder.Data()));
	TFile* efffile = new TFile(Form("%s/eff.root",folder.Data()));
	TH1D* hPt = (TH1D*)fitfile->Get("hPt");
	TH1D* hEff = (TH1D*)efffile->Get("hEff");
	float extYield = hPt->GetBinContent(1);
	float corYield = extYield/hEff->GetBinContent(1);
	printf("extYield: %f, corYield: %f\n", extYield, corYield);
	return corYield;
}
