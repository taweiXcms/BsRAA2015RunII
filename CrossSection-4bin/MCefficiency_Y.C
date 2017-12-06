#include "uti.h"
#include "parameters.h"

Double_t setparam0=100.;
Double_t setparam1=1.865;
Double_t setparam2=0.03;
Double_t setparam10=0.005;
Double_t setparam8=0.1;
Double_t setparam9=0.1;
Double_t fixparam1=1.865;
Double_t minhisto=	1.7;
Double_t maxhisto=2.0;
Double_t nbinsmasshisto=60;
Double_t binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString weightfunctiongen = "1";
TString weightfunctionreco = "1";
Float_t hiBinMin,hiBinMax,centMin,centMax;

int _nBins = nBinsY;
double *_ptBins = ptBinsY;

void MCefficiency_Y(int isPbPb=0, TString inputmc="", TString selmcgen="", TString selmcgenacceptance="", TString cut_recoonly="", TString cut="", TString label="", TString outputfile="", int PbPbweight=1, Float_t centmin=0., Float_t centmax=100.)
{ 
	if(label=="ppInc"){
		_nBins = nBinsInc;
		_ptBins = ptBinsInc;
	}

	std::string str = label.Data();
	std::size_t found = str.find("Fine");
	//if(label=="ppFine"||label=="PbPbFine"){
	if (found!=std::string::npos){
		_nBins = nBinsFine;
		_ptBins = ptBinsFine;
	}

	hiBinMin = centmin*2;
	hiBinMax = centmax*2;
	centMin = centmin;
	centMax = centmax;

	if(isPbPb==1)
	{
		selmcgen = selmcgen+Form("&&hiBin>=%f&&hiBin<=%f",hiBinMin,hiBinMax);
		selmcgenacceptance=selmcgenacceptance+Form("&&hiBin>=%f&&hiBin<=%f",hiBinMin,hiBinMax);
		cut=cut+Form("&&hiBin>=%f&&hiBin<=%f",hiBinMin,hiBinMax);
		cut_recoonly=cut_recoonly+Form("&&hiBin>=%f&&hiBin<=%f",hiBinMin,hiBinMax);
	}

	printf("############## input parameters\n");
	std::cout<<"selmcgen = "<<selmcgen<<std::endl;
	std::cout<<"selmcgenacceptance = "<<selmcgenacceptance<<std::endl;
	std::cout<<"cut = "<<cut<<std::endl;
	std::cout<<"cut_recoonly = "<<cut_recoonly<<std::endl;
	std::cout<<"PbPbweight = "<<PbPbweight<<std::endl;
	printf("############## input parameters\n");

	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	gStyle->SetEndErrorSize(0);
	gStyle->SetMarkerStyle(20);

	TFile* infMC = new TFile(inputmc.Data());
	TTree* ntMC = (TTree*)infMC->Get("ntphi");
	TTree* ntGen = (TTree*)infMC->Get("ntGen");

	ntMC->AddFriend(ntGen);
	ntMC->AddFriend("ntSkim");
	ntMC->AddFriend("ntHlt");
	ntMC->AddFriend("ntHi");
	ntMC->AddFriend("BDTStage1_pt15to50");

	ntGen->AddFriend(ntMC);
	ntGen->AddFriend("ntSkim");
	ntGen->AddFriend("ntHlt");
	ntGen->AddFriend("ntHi");
	ntGen->AddFriend("BDTStage1_pt15to50");

	// weigths
	TCut weighpthat = "1";
	TCut weightGpt = "1";
	TCut weightBgenpt = "1";
	TCut weightHiBin = "1";
	TCut weightPVz = "1";
	if(PbPbweight==0) {
		weighpthat = "pthatweight";
		weightGpt = "(pow(10, -0.365511 + 0.030289*Gpt + -0.000691*Gpt*Gpt + 0.000005*Gpt*Gpt*Gpt))";
		weightBgenpt = "(pow(10, -0.365511 + 0.030289*Bgenpt + -0.000691*Bgenpt*Bgenpt + 0.000005*Bgenpt*Bgenpt*Bgenpt))";
		weightHiBin = "1";
		weightPVz = "1";
	}
	if(PbPbweight==1) {
		weighpthat = "pthatweight";
		weightGpt = "(pow(10, -0.244653 + 0.016404*Gpt + -0.000199*Gpt*Gpt + 0.000000*Gpt*Gpt*Gpt))";
		weightBgenpt = "(pow(10, -0.244653 + 0.016404*Bgenpt + -0.000199*Bgenpt*Bgenpt + 0.000000*Bgenpt*Bgenpt*Bgenpt))";
		weightHiBin = "(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))";
		weightPVz = "(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))";
	}

	TH1D* hPtMC = new TH1D("hPtMC","",_nBins,_ptBins);
	TH1D* hPtMCrecoonly = new TH1D("hPtMCrecoonly","",_nBins,_ptBins);
	TH1D* hPtGen = new TH1D("hPtGen","",_nBins,_ptBins);
	TH1D* hPtGenAcc = new TH1D("hPtGenAcc","",_nBins,_ptBins);
	TH1D* hPtGenAccWeighted = new TH1D("hPtGenAccWeighted","",_nBins,_ptBins);
	ntMC->Project("hPtMC","abs(By)",
		TCut(weighpthat)*TCut(weightBgenpt)*TCut(weightHiBin)*TCut(weightPVz)*(TCut(cut.Data())&&"(Bgen==23333)"));
	ntMC->Project("hPtMCrecoonly","abs(By)",
		TCut(weighpthat)*TCut(weightBgenpt)*TCut(weightHiBin)*TCut(weightPVz)*(TCut(cut_recoonly.Data())&&"(Bgen==23333)"));
	ntGen->Project("hPtGen","abs(Gy)",
		TCut(weighpthat)*TCut(weightGpt)*(TCut(selmcgen.Data())));
	ntGen->Project("hPtGenAcc","abs(Gy)",
		TCut(weighpthat)*TCut(weightGpt)*(TCut(selmcgenacceptance.Data())));
	ntGen->Project("hPtGenAccWeighted","abs(Gy)",
		TCut(weighpthat)*TCut(weightGpt)*TCut(weightHiBin)*TCut(weightPVz)*(TCut(selmcgenacceptance.Data())));

	TH1D* hPthat = new TH1D("hPthat","",100,0,500);
	TH1D* hPthatweight = new TH1D("hPthatweight","",100,0,500);
	ntMC->Project("hPthat","pthat","1");
	ntMC->Project("hPthatweight","pthat",TCut("1"));

	////// tag & probe scaling factor
	for(int i = 0; i < 1; i++){printf("%.2f, ", hPtMC->GetBinContent(i+1));}printf("\n");//check entries
	//double sf_pp[1] = {127693.52/125760.88, };
	//double sf_pp[1] = {126033.04/124022.37, }; // only pthatweight
    double sf_pp[4] = {50364.37/50031.72, 52376.56/51902.39, 52078.31/50299.20, 42381.87/39570.54, };//double tnpUnc_pp[4] = {3.142683, 3.199027, 3.902916, 3.952208, };
	//double sf_pbpb[1] = {20506.70/20890.91, };
	//double sf_pbpb[1] = {43815.89/44553.57, }; // only pthatweight
	double sf_pbpb[4] = {20506.70/20890.91, 1., 1., 1.};
	for(int i = 0; i < 1; i++){
		if(label == "pp"){
			hPtMC->SetBinContent(i+1, hPtMC->GetBinContent(i+1)*sf_pp[i]);
			hPtMCrecoonly->SetBinContent(i+1, hPtMCrecoonly->GetBinContent(i+1)*sf_pp[i]);
		}
		if(label == "PbPb"){
			hPtMC->SetBinContent(i+1, hPtMC->GetBinContent(i+1)*sf_pbpb[i]);
			hPtMCrecoonly->SetBinContent(i+1, hPtMCrecoonly->GetBinContent(i+1)*sf_pbpb[i]);
		}
	}
	for(int i = 0; i < 1; i++){printf("%.2f, ", hPtMC->GetBinContent(i+1));}printf("\n");//check entries
	////// tag & probe scaling factor

	divideBinWidth(hPtMC);
	divideBinWidth(hPtMCrecoonly);
	divideBinWidth(hPtGen);
	divideBinWidth(hPtGenAcc);
	divideBinWidth(hPtGenAccWeighted);

	hPtMC->Sumw2();
	hPtMCrecoonly->Sumw2();
	hPtGen->Sumw2();
	hPtGenAcc->Sumw2();
	hPtGenAccWeighted->Sumw2();
	//Acceptance
	TH1D* hEffAcc = (TH1D*)hPtGenAcc->Clone("hEffAcc");
	hEffAcc->Sumw2();
	hEffAcc->Divide(hEffAcc,hPtGen,1,1,"b");
	//Selection
	TH1D* hEffSelection = (TH1D*)hPtMC->Clone("hEffSelection");
	hEffSelection->Sumw2();
	hEffSelection->Divide(hEffSelection,hPtGenAccWeighted,1,1,"b");
	//Acc * Eff
	TH1D* hEff = (TH1D*)hEffSelection->Clone("hEff");
	hEff->Sumw2();
	hEff->Multiply(hEff,hEffAcc,1,1);
	//Acc * Eff (one shot)
	TH1D* hEffOneShot = (TH1D*)hPtMC->Clone("hEffOneShot");
	hEffOneShot->Sumw2();
	hEffOneShot->Divide(hEffOneShot,hPtGen,1,1,"b");

	////// Draw hEff, hEffAcc
	TH2F* hemptyEff=new TH2F("hemptyEff","",50,_ptBins[0]-5.,_ptBins[_nBins]+5.,10.,0,0.6);  
	hemptyEff->GetXaxis()->CenterTitle();
	hemptyEff->GetYaxis()->CenterTitle();
	hemptyEff->GetYaxis()->SetTitle("#alpha x #epsilon");
	hemptyEff->GetXaxis()->SetTitle("|y| (GeV/c)");
	hemptyEff->GetXaxis()->SetTitleOffset(0.9);
	hemptyEff->GetYaxis()->SetTitleOffset(0.95);
	hemptyEff->GetXaxis()->SetTitleSize(0.05);
	hemptyEff->GetYaxis()->SetTitleSize(0.05);
	hemptyEff->GetXaxis()->SetTitleFont(42);
	hemptyEff->GetYaxis()->SetTitleFont(42);
	hemptyEff->GetXaxis()->SetLabelFont(42);
	hemptyEff->GetYaxis()->SetLabelFont(42);
	hemptyEff->GetXaxis()->SetLabelSize(0.035);
	hemptyEff->GetYaxis()->SetLabelSize(0.035);  
	hemptyEff->SetMaximum(1.0);
	hemptyEff->SetMinimum(0.);
	hemptyEff->Draw();
	TH2F* hemptyEffAcc=(TH2F*)hemptyEff->Clone("hemptyEffAcc");
	hemptyEffAcc->SetYTitle("#alpha");

	TCanvas*canvasEff=new TCanvas("canvasEff","canvasEff",1000.,500);
	canvasEff->Divide(2,1);
	canvasEff->cd(1);
	hemptyEffAcc->Draw();
	hEffAcc->Draw("same");
	canvasEff->cd(2);
	hemptyEff->Draw();
	hEff->Draw("same");
	canvasEff->SaveAs(Form("plotEff_Y/canvasEff_study%s.pdf",Form(label.Data())));

	////// Draw hPthat, hPthatweight
	TH2F* hemptyPthat=new TH2F("hemptyPthat","",50,0.,300.,10,1e-5,1e9);  
	hemptyPthat->GetXaxis()->CenterTitle();
	hemptyPthat->GetYaxis()->CenterTitle();
	hemptyPthat->GetYaxis()->SetTitle("Entries");
	hemptyPthat->GetXaxis()->SetTitle("pthat");
	hemptyPthat->GetXaxis()->SetTitleOffset(0.9);
	hemptyPthat->GetYaxis()->SetTitleOffset(0.95);
	hemptyPthat->GetXaxis()->SetTitleSize(0.05);
	hemptyPthat->GetYaxis()->SetTitleSize(0.05);
	hemptyPthat->GetXaxis()->SetTitleFont(42);
	hemptyPthat->GetYaxis()->SetTitleFont(42);
	hemptyPthat->GetXaxis()->SetLabelFont(42);
	hemptyPthat->GetYaxis()->SetLabelFont(42);
	hemptyPthat->GetXaxis()->SetLabelSize(0.035);
	hemptyPthat->GetYaxis()->SetLabelSize(0.035);  
	hemptyPthat->SetMaximum(1.0);
	hemptyPthat->SetMinimum(0.);
	TH2F* hemptyPthatWeighted=(TH2F*)hemptyPthat->Clone("hemptyPthatWeighted");
	hemptyPthatWeighted->GetXaxis()->SetTitle("pthat reweighted");

	TCanvas*canvasPthat=new TCanvas("canvasPthat","canvasPthat",1000.,500);
	canvasPthat->Divide(2,1);
	canvasPthat->cd(1);
	gPad->SetLogy();
	hemptyPthat->Draw("same");
	hPthat->Draw("same");
	canvasPthat->cd(2);
	gPad->SetLogy();
	hemptyPthatWeighted->Draw();
	hPthatweight->Draw("same");
	canvasPthat->SaveAs(Form("plotEff_Y/canvasPthat_%s.pdf",Form(label.Data())));

	////// Draw hPtMC, hPtGen
	TH2F* hemptySpectra=new TH2F("hemptySpectra","",50,0.,130.,10,1,1e5);  
	hemptySpectra->GetXaxis()->CenterTitle();
	hemptySpectra->GetYaxis()->CenterTitle();
	hemptySpectra->GetYaxis()->SetTitle("Entries");
	hemptySpectra->GetXaxis()->SetTitle("|y|");
	hemptySpectra->GetXaxis()->SetTitleOffset(0.9);
	hemptySpectra->GetYaxis()->SetTitleOffset(0.95);
	hemptySpectra->GetXaxis()->SetTitleSize(0.05);
	hemptySpectra->GetYaxis()->SetTitleSize(0.05);
	hemptySpectra->GetXaxis()->SetTitleFont(42);
	hemptySpectra->GetYaxis()->SetTitleFont(42);
	hemptySpectra->GetXaxis()->SetLabelFont(42);
	hemptySpectra->GetYaxis()->SetLabelFont(42);
	hemptySpectra->GetXaxis()->SetLabelSize(0.035);
	hemptySpectra->GetYaxis()->SetLabelSize(0.035);  

	TCanvas*canvasSpectra=new TCanvas("canvasSpectra","canvasSpectra",1000.,500);
	canvasSpectra->Divide(2,1);
	canvasSpectra->cd(1);
	gPad->SetLogy();
	hemptySpectra->Draw();
	hPtMC->Draw("same");
	canvasSpectra->cd(2);
	gPad->SetLogy();
	hemptySpectra->Draw();
	hPtGen->Draw("same");
	canvasSpectra->SaveAs(Form("plotEff_Y/canvasSpectra_%s.pdf",Form(label.Data())));

	//### 1D histogram
	//hEffAcc = hPtGenAcc / hPtGen
	//hEffSelection = hPtMC / hPtMC
	//hEff = hEffSelection * hEffAcc
	//hEffOneShot = hPtMC / hPtGen

	TString text;
	if (isPbPb) { text="350.68 #mub^{-1} (5.02 TeV PbPb)";}
	else {text="25.8 pb^{-1} (5.02 TeV pp)";}
	TLatex* texlumi = new TLatex(0.9,0.92,text.Data());
	texlumi->SetNDC();
	texlumi->SetTextAlign(31);
	texlumi->SetTextFont(42);
	texlumi->SetTextSize(0.038);
	texlumi->SetLineWidth(2);

	TString texper="%";
	TLatex* texCent = new TLatex(0.5,0.815,Form("Centrality %.0f - %.0f%s",centMin,centMax,texper.Data()));
	texCent->SetNDC();
	texCent->SetTextFont(42);
	texCent->SetTextSize(0.05);

	TLatex* texY = new TLatex(0.5,0.750,"10. < p_{T} < 50.");
	texY->SetNDC();
	texY->SetTextFont(42);
	texY->SetTextSize(0.05);
	texY->SetLineWidth(2);

	TLatex* texCms = new TLatex(0.08,0.95, "CMS Preliminary");
	texCms->SetNDC();
	texCms->SetTextAlign(13);
	texCms->SetTextSize(0.038);
	texCms->SetTextFont(62);

	TCanvas*canvas1D=new TCanvas("canvas1D","",600,600);
	canvas1D->cd();
	gPad->SetLogy(0);
	hemptyEff->GetXaxis()->SetTitle("|y|");
	hEff->SetLineColor(2);
	hEff->SetMarkerColor(2);

	hemptySpectra->SetYTitle("Entries of hPtMC");
	hemptySpectra->Draw(); 
	hPtMC->Draw("same");
	if(isPbPb) texCent->Draw();
	texY->Draw(); texCms->Draw(); texlumi->Draw();
	canvas1D->SaveAs(Form("plotEff_Y/canvas1DhPtMC_%s.pdf",Form(label.Data())));
	canvas1D->Clear();

	hemptySpectra->SetYTitle("Entries of hPtMCrecoonly");
	hemptySpectra->Draw(); 
	hPtMCrecoonly->Draw("same");
	if(isPbPb) texCent->Draw();
	texY->Draw(); texCms->Draw(); texlumi->Draw();
	canvas1D->SaveAs(Form("plotEff_Y/canvas1DhPtMCrecoonly_%s.pdf",Form(label.Data())));
	canvas1D->Clear();

	hemptySpectra->SetYTitle("Entries of hPtGen");
	hemptySpectra->Draw(); 
	hPtGen->Draw("same");
	if(isPbPb) texCent->Draw();
	texY->Draw(); texCms->Draw(); texlumi->Draw();
	canvas1D->SaveAs(Form("plotEff_Y/canvas1DhPtGen_%s.pdf",Form(label.Data())));
	canvas1D->Clear();

	hemptySpectra->SetYTitle("Entries of hPtGenAcc");
	hemptySpectra->Draw(); 
	hPtGenAcc->Draw("same");
	if(isPbPb) texCent->Draw();
	texY->Draw(); texCms->Draw(); texlumi->Draw();
	canvas1D->SaveAs(Form("plotEff_Y/canvas1DhPtGenAcc_%s.pdf",Form(label.Data())));
	canvas1D->Clear();

	hemptyEff->SetYTitle("hPtGenAcc/hPtGen");
	hemptyEff->Draw(); 
	hEffAcc->Draw("same");
	if(isPbPb) texCent->Draw();
	texY->Draw(); texCms->Draw(); texlumi->Draw();
	canvas1D->SaveAs(Form("plotEff_Y/canvas1DhEffAcc_%s.pdf",Form(label.Data())));
	canvas1D->Clear();

	hemptyEff->SetYTitle("hPtMC/hPtGenAccWeighted");
	hemptyEff->Draw(); 
	hEffSelection->Draw("same");
	if(isPbPb) texCent->Draw();
	texY->Draw(); texCms->Draw(); texlumi->Draw();
	canvas1D->SaveAs(Form("plotEff_Y/canvas1DhEffSelection_%s.pdf",Form(label.Data())));
	canvas1D->Clear();

	hemptyEff->SetYTitle("#alpha x #epsilon");
	hemptyEff->Draw();
	hEff->Draw("same");
	if(isPbPb) texCent->Draw();
	texY->Draw(); texCms->Draw(); texlumi->Draw();
	canvas1D->SaveAs(Form("plotEff_Y/canvas1DhEff_%s.pdf",Form(label.Data())));
	canvas1D->SaveAs(Form("plotEff_Y/canvas1DhEff_%s.C",Form(label.Data())));
	canvas1D->Clear();

	hemptyEff->SetYTitle("hPtMC/hPtGen");
	hemptyEff->Draw(); 
	hEffOneShot->Draw("same");
	if(isPbPb) texCent->Draw();
	texY->Draw(); texCms->Draw(); texlumi->Draw();
	canvas1D->SaveAs(Form("plotEff_Y/canvas1DhEffOneShot_%s.pdf",Form(label.Data())));
	canvas1D->Clear();

	TFile *fout=new TFile(outputfile.Data(),"recreate");
	fout->cd();
	hPtGen->Write();
	hEffAcc->Write();
	hEffOneShot->Write();
	hEffSelection->Write();
	hEff->Write();
	hPtMC->Write();
	fout->Close();  

}

int main(int argc, char *argv[])
{
	if((argc !=12))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 12)
		MCefficiency_Y(atoi(argv[1]),argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],atoi(argv[9]),atof(argv[10]),atof(argv[11]));
	return 0;
}




