//### Code to calculate the acceptance systematics
//### Code for step 2 - Get the Ratio
//### Author : Hyunchul Kim, Gian Innocenti Michele
//### hyunchul.kim@cern.ch March 11 2017 Cleaned

#include <iostream>
#include <TF1.h>
#include <TH1.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TPaveText.h>
#include <TStyle.h>

// set pt bins (same for analysis binning)
const int nBins = 4;

// set y bins (same for analysis binning)
const int nBinsy = 4;

// pp or PbPb
string label;

void FakeInput_Bs(bool ispp=1){
    gStyle->SetOptFit(0);

	if(ispp) label = "pp";
	else label = "PbPb";
// call the root files including raw yield from data and MC (for pt and y binning)
    TFile *foutDataPt   = new TFile("../Inputfileforreweighting/hPtSpectrumSaveHistBplusPP_750_acc.root","read");
    TFile *foutDatay    = new TFile("../Inputfileforreweighting/hPtSpectrumSaveHistBplusPP_Y.root","read");
    TFile *foutMCPt     = new TFile("../Inputfileforreweighting/MCstudiesPP_750_acc.root","read");
    TFile *foutMCy      = new TFile("../Inputfileforreweighting/MCstudiesPP_Y.root","read");
	if(ispp==0){
	    foutDataPt   = new TFile("../Inputfileforreweighting/hPtSpectrumSaveHistBplusPP_750_acc.root","read");
	    foutDatay    = new TFile("../Inputfileforreweighting/hPtSpectrumSaveHistBplusPP_Y.root","read");
	    foutMCPt     = new TFile("../Inputfileforreweighting/MCstudiesPP_750_acc.root","read");
	    foutMCy      = new TFile("../Inputfileforreweighting/MCstudiesPP_Y.root","read");
	}

// call the histogram of raw yied from each file
    TH1D*hPtMC   = (TH1D*)foutMCPt->Get("hPtMC");
    TH1D*hPtData = (TH1D*)foutDataPt->Get("hPt");
    TH1D*hyMC        = (TH1D*)foutMCy->Get("hPtMC");
    TH1D*hyData  = (TH1D*)foutDatay->Get("hPt");

// should be apply sumw2
	hPtMC->Sumw2();
	hPtData->Sumw2();
	hyMC->Sumw2();
	hyData->Sumw2();

// set the name of each histogram, because originally all the histogram's name was "hPt"
	hPtMC->SetName("hPtMC");
	hPtData->SetName("hPtData");
	hyMC->SetName("hyMC");
	hyData->SetName("hyData");

// For the comparison, we scaled each histogram by the integral of each histogram
	hPtMC->Scale(1./hPtMC->Integral());
	hPtData->Scale(1./hPtData->Integral());
	hyMC->Scale(1./hyMC->Integral());
	hyData->Scale(1./hyData->Integral());

// call the histogram with same structure of "hPtData(hyData)", by clone it
	TH1D*hReweightDataOverMC_Pt=(TH1D*)hPtData->Clone("hReweightDataOverMC_Pt");
	TH1D*hReweightDataOverMC_y=(TH1D*)hyData->Clone("hReweightDataOverMC_y");

// Get the ratio of raw yield (Data/MC)
	hReweightDataOverMC_Pt->Divide(hPtData,hPtMC,1,1,"B");
	hReweightDataOverMC_y->Divide(hyData,hyMC,1,1,"B");

// Prove whether input file is right or not in one canvas, if remove line 65-71, values of stat box in plots is changed because of unknown problem
	TCanvas*c=new TCanvas("c","c",800,500);
	c->Divide(2,2);
	c->cd(1);hPtData->Draw();
	c->cd(2);hPtMC->Draw();
	c->cd(3);hyData->Draw();
	c->cd(4);hyMC->Draw();
	c->SaveAs(Form("prova_Bs_%s.pdf", label.c_str()));

// call the output file and save the histograms until now
	TFile*fout=new TFile(Form("InputFilesMCData_Bs_%s.root",label.c_str()),"recreate");
	fout->cd();
	hPtData->Write();
	hPtMC->Write();
	hyData->Write();
	hyMC->Write();
	hReweightDataOverMC_Pt->Write();
	hReweightDataOverMC_y->Write();
	fout->Close();

	std::cout << "### Data/MC ratio is saved in root file. ###" << std::endl;

// call the resulted file from last step
	TFile* fin = new TFile(Form("InputFilesMCData_Bs_%s.root", label.c_str()),"read");

// call the saved histogram (raw yield from Data and MC and Data/MC ratio)
	hPtData=(TH1D*)fin->Get("hPtData");
	hPtMC=(TH1D*)fin->Get("hPtMC");
	hyData=(TH1D*)fin->Get("hyData");
	hyMC=(TH1D*)fin->Get("hyMC");
	hReweightDataOverMC_Pt=(TH1D*)fin->Get("hReweightDataOverMC_Pt");
	hReweightDataOverMC_y=(TH1D*)fin->Get("hReweightDataOverMC_y");

// set the fitting function for pt and y ratio
	TF1 *fRfitft_Bspt = new TF1("fRfitft_Bspt","[0]+x*[1]",10.0,50.0);//Bs, pt dependence
	//TF1 *fRfitft_Bsy = new TF1("fRfitft_Bsy","[0]*pow((x-0.0),2)+[1]",-2.865,1.935);
	TF1 *fRfitft_Bsy = new TF1("fRfitft_Bsy","[0]*pow(x,2)+[1]",0,2.4);//Bs, y dependence

// call histogram for parameter fit
	TH1D* hParafitft_Bspt = new TH1D("hParafitft_Bspt","",2,0,2);
	TH1D* hParafitft_Bsy  = new TH1D("hParafitft_Bsy","",2,0,2);

	TCanvas* canvas11 = new TCanvas("canvas11","",600,600);
	canvas11->cd();

	TLegend* leg11 = new TLegend(0.20,0.70,0.45,0.85);
	leg11->AddEntry(hPtData,"Data","lep");
	leg11->AddEntry(hPtMC,"MC","f");
	leg11->SetFillColor(kWhite);
	leg11->SetBorderSize(0);

	TPaveText* pt11 = new TPaveText(0.22,0.62,0.27,0.67,"NDC");
	pt11->SetFillColor(0);
	pt11->SetTextSize(0.05);
	pt11->SetBorderSize(0);
	pt11->AddText("B_{s}");

	hPtMC->GetYaxis()->SetTitle("Proportion of uncorrected B_{s} dN/dp_{T} (Data/MC)");
	hPtMC->GetXaxis()->SetTitle("p_{T}");
    hPtMC->GetXaxis()->CenterTitle();
    hPtMC->GetYaxis()->CenterTitle();
    hPtMC->GetXaxis()->SetTitleOffset(0.9);
    hPtMC->GetYaxis()->SetTitleOffset(1.1);
    hPtMC->GetXaxis()->SetTitleSize(0.05);
    hPtMC->GetYaxis()->SetTitleSize(0.045);
    hPtMC->GetXaxis()->SetTitleFont(42);
    hPtMC->GetYaxis()->SetTitleFont(42);
    hPtMC->GetXaxis()->SetLabelFont(42);
    hPtMC->GetYaxis()->SetLabelFont(42);
    hPtMC->GetXaxis()->SetLabelSize(0.035);
    hPtMC->GetYaxis()->SetLabelSize(0.035);
	hPtMC->SetMinimum(0);
	hPtMC->SetMaximum(0);
	hPtMC->SetFillColor(kPink+6);
	//hPtMC->SetFillStyle(3004);
	hPtMC->SetLineWidth(1);
	hPtMC->SetLineColor(kBlack);
	hPtMC->Draw("hist");
	hPtData->SetMarkerStyle(21);
	hPtData->SetMarkerSize(1.0);
	hPtData->SetLineWidth(1);
	hPtData->SetLineColor(kBlack);
	hPtData->Draw("samepe");
	leg11->Draw();
	pt11->Draw();
	canvas11->SaveAs(Form("AccSys_CompNormUncorYield_Bs_%s.pdf", label.c_str()));

	hReweightDataOverMC_Pt->SetMinimum(0.6);
	hReweightDataOverMC_Pt->SetMaximum(1.8);
	hReweightDataOverMC_Pt->Draw("p");
	hReweightDataOverMC_Pt->SetMarkerStyle(20);
	hReweightDataOverMC_Pt->SetMarkerSize(1.5);
	hReweightDataOverMC_Pt->SetLineWidth(1.0);
	hReweightDataOverMC_Pt->SetLineColor(kBlack);
	hReweightDataOverMC_Pt->GetYaxis()->SetTitle("Ratio of uncorrected B_{s} dN/dp_{T} (Data/MC)");
	hReweightDataOverMC_Pt->GetXaxis()->SetTitle("p_{T}");
    hReweightDataOverMC_Pt->GetXaxis()->CenterTitle();
    hReweightDataOverMC_Pt->GetYaxis()->CenterTitle();
    hReweightDataOverMC_Pt->GetXaxis()->SetTitleOffset(0.9);
    hReweightDataOverMC_Pt->GetYaxis()->SetTitleOffset(1.1);
    hReweightDataOverMC_Pt->GetXaxis()->SetTitleSize(0.05);
    hReweightDataOverMC_Pt->GetYaxis()->SetTitleSize(0.05);
    hReweightDataOverMC_Pt->GetXaxis()->SetTitleFont(42);
    hReweightDataOverMC_Pt->GetYaxis()->SetTitleFont(42);
    hReweightDataOverMC_Pt->GetXaxis()->SetLabelFont(42);
    hReweightDataOverMC_Pt->GetYaxis()->SetLabelFont(42);
    hReweightDataOverMC_Pt->GetXaxis()->SetLabelSize(0.035);
    hReweightDataOverMC_Pt->GetYaxis()->SetLabelSize(0.035);

	fRfitft_Bspt->SetLineColor(kRed);
	fRfitft_Bspt->SetLineWidth(2.0);
	std::cout << "##### Fit with fRfitft_Bspt \"[0]+x*[1]\" #############" << std::string(20,'#') << std::endl; 
	hReweightDataOverMC_Pt->Fit("fRfitft_Bspt"); 
	std::cout << std::string(76,'#') << std::endl;
	hParafitft_Bspt->SetBinContent(1,fRfitft_Bspt->GetParameter(0));
	hParafitft_Bspt->SetBinContent(2,fRfitft_Bspt->GetParameter(1));

	pt11->Clear();
	pt11 = new TPaveText(0.22,0.80,0.27,0.85,"NDC");
	pt11->SetFillColor(0);
	pt11->SetTextSize(0.05);
	pt11->SetBorderSize(0);
	pt11->AddText("B_{s}");
	pt11->Draw();
	canvas11->SaveAs(Form("AccSys_RatioNormUncorYield_Bs_%s.pdf", label.c_str()));

	for (int i=0;i<nBins;i++) {
		std::cout << i << ": " << hReweightDataOverMC_Pt->GetBinContent(i+1) << " , " << hReweightDataOverMC_Pt->GetBinError(i+1) << std::endl;
	}

	leg11->Clear();
	leg11->AddEntry(hyData,"Data","lep");
	leg11->AddEntry(hyMC,"MC","f");
	leg11->SetFillColor(kWhite);
	leg11->SetBorderSize(0);

	pt11->Clear();
	pt11->AddText("B_{s}");

	hyMC->GetYaxis()->SetTitle("Proportion of uncorrected B_{s} dN/dy_{CM} (Data/MC)");
	hyMC->GetXaxis()->SetTitle("y_{CM}");
    hyMC->GetXaxis()->CenterTitle();
    hyMC->GetYaxis()->CenterTitle();
    hyMC->GetXaxis()->SetTitleOffset(0.9);
    hyMC->GetYaxis()->SetTitleOffset(1.1);
    hyMC->GetXaxis()->SetTitleSize(0.05);
    hyMC->GetYaxis()->SetTitleSize(0.045);
    hyMC->GetXaxis()->SetTitleFont(42);
    hyMC->GetYaxis()->SetTitleFont(42);
    hyMC->GetXaxis()->SetLabelFont(42);
    hyMC->GetYaxis()->SetLabelFont(42);
    hyMC->GetXaxis()->SetLabelSize(0.035);
    hyMC->GetYaxis()->SetLabelSize(0.035);
	hyMC->SetMinimum(0);
	hyMC->SetMaximum(0);
	hyMC->SetFillColor(kPink+6);
	//hyMC->SetFillStyle(3004);
	hyMC->SetLineWidth(1);
	hyMC->SetLineColor(kBlack);
	hyMC->Draw("hist");
	hyData->SetMarkerStyle(21);
	hyData->SetMarkerSize(1.0);
	hyData->SetLineWidth(1);
	hyData->SetLineColor(kBlack);
	hyData->Draw("samepe");
	leg11->Draw();
	pt11->Clear();
	pt11 = new TPaveText(0.22,0.62,0.27,0.67,"NDC");
	pt11->SetFillColor(0);
	pt11->SetTextSize(0.05);
	pt11->SetBorderSize(0);
	pt11->AddText("B_{s}");
	pt11->Draw();
	canvas11->SaveAs(Form("AccSys_CompNormUncorYield_Bsy_%s.pdf", label.c_str()));

	hReweightDataOverMC_y->SetMinimum(0.6);
	hReweightDataOverMC_y->SetMaximum(1.8);
	hReweightDataOverMC_y->Draw("p");
	hReweightDataOverMC_y->SetMarkerStyle(20);
	hReweightDataOverMC_y->SetMarkerSize(1.5);
	hReweightDataOverMC_y->SetLineWidth(1.0);
	hReweightDataOverMC_y->SetLineColor(kBlack);
	hReweightDataOverMC_y->GetYaxis()->SetTitle("Ratio of uncorrected B^{s} dN/dy_{CM} (Data/MC)");
	hReweightDataOverMC_y->GetXaxis()->SetTitle("y_{CM}");
    hReweightDataOverMC_y->GetXaxis()->CenterTitle();
    hReweightDataOverMC_y->GetYaxis()->CenterTitle();
    hReweightDataOverMC_y->GetXaxis()->SetTitleOffset(0.9);
    hReweightDataOverMC_y->GetYaxis()->SetTitleOffset(1.1);
    hReweightDataOverMC_y->GetXaxis()->SetTitleSize(0.05);
    hReweightDataOverMC_y->GetYaxis()->SetTitleSize(0.05);
    hReweightDataOverMC_y->GetXaxis()->SetTitleFont(42);
    hReweightDataOverMC_y->GetYaxis()->SetTitleFont(42);
    hReweightDataOverMC_y->GetXaxis()->SetLabelFont(42);
    hReweightDataOverMC_y->GetYaxis()->SetLabelFont(42);
    hReweightDataOverMC_y->GetXaxis()->SetLabelSize(0.035);
    hReweightDataOverMC_y->GetYaxis()->SetLabelSize(0.035);

	fRfitft_Bsy->SetLineColor(kRed);
	fRfitft_Bsy->SetLineWidth(2.0);
	std::cout << "##### Fit with fRfitft_Bsy  \"[0]*pow(x,2)+[1]\" ######" << std::string(20,'#') << std::endl; 
	hReweightDataOverMC_y->Fit("fRfitft_Bsy"); 
	std::cout << std::string(76,'#') << std::endl;
	hParafitft_Bsy->SetBinContent(1,fRfitft_Bsy->GetParameter(0));
	hParafitft_Bsy->SetBinContent(2,fRfitft_Bsy->GetParameter(1));

	pt11->Clear();
	pt11 = new TPaveText(0.22,0.80,0.27,0.85,"NDC");
	pt11->SetFillColor(0);
	pt11->SetTextSize(0.05);
	pt11->SetBorderSize(0);
	pt11->AddText("B_{s}");
	pt11->Draw();
	canvas11->SaveAs(Form("AccSys_RatioNormUncorYield_Bsy_%s.pdf", label.c_str()));

	for (int i=0;i<nBinsy;i++) {
		std::cout << i << ": " << hReweightDataOverMC_y->GetBinContent(i+1) << " , " << hReweightDataOverMC_y->GetBinError(i+1) << std::endl;
	}

	TFile* fout2 = new TFile(Form("FunctionsReweighting_Bs_%s.root", label.c_str()),"recreate");
	fout2->cd();
	hPtData->Write();
	hPtMC->Write();
	hReweightDataOverMC_Pt->Write();
	hyData->Write();
	hyMC->Write();
	hReweightDataOverMC_y->Write();
	fRfitft_Bsy->Write();
	fRfitft_Bspt->Write();
	hParafitft_Bspt->Write();
	hParafitft_Bsy->Write();
	fout2->Close();
}
