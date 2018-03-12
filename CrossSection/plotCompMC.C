#include "fitB.h"
using namespace std;

struct plotStruct{
    TString var;
    TString text;
    bool setlogY;
    bool setlogX;
    int nBins;
    double min;
    double max;
};

double inf = 9999;
const int nVar = 21;
struct plotStruct plotSetting[nVar] = {
    {"Bpt",                         "Bpt",          1, 0, 50, 15, 50}, 
    {"abs(By)",                     "By",           1, 0, 50, 0.0, 2.4}, 
    {"Btrk1Pt",                     "Btrk1Pt",      1, 1, 50, 0.8, 30}, 
    {"Btrk2Pt",                     "Btrk2Pt",      1, 1, 50, 0.8, 30}, 
//    {"Btrk1Pt",                     "Btrk1Pt",      1, 1, 50, 0.0, 10}, 
//    {"Btrk2Pt",                     "Btrk2Pt",      1, 1, 50, 0.0, 10}, 
    {"abs(Btrk1Eta)",               "Btrk1Eta",     1, 0, 50, 0.0, 2.6}, 
    {"abs(Btrk2Eta)",               "Btrk2Eta",     1, 0, 50, 0.0, 2.6}, 
    {"abs(Btrk1Dxy/Btrk1D0Err)",    "Btrk1Dxy",     1, 0, 50, 0, 30}, 
    {"abs(Btrk2Dxy/Btrk1D0Err)",    "Btrk2Dxy",     1, 0, 50, 0, 30}, 
    {"abs(Btktkmass-1.019455)",     "Btktkmass",    1, 0, 50, 0, 0.015}, 
    {"abs(Bmumumass-3.096916)",     "Bmumumass",    1, 0, 50, 0, 0.2},
    {"BsvpvDistance/BsvpvDisErr",   "Bsvpv",        1, 0, 50, 0, 200}, 
    {"Balpha",                      "Balpha",       1, 0, 50, 0, 0.3}, 
    {"Bd0/Bd0Err",                  "Bd0",          0, 0, 50, 0, 10000}, 
    {"cos(Bdtheta)",                "cosBtheta",    0, 0, 50, -1, 1}, 
    {"Bchi2cl",                     "Bchi2cl",      0, 0, 50, 0, 1}, 
    {"Btktkpt",                     "Btktkpt",      0, 0, 50, 0, 40}, 
    {"abs(Btktketa)",               "Btktketa",     0, 0, 50, 0, 2.6}, 
    {"Bmu1pt",                      "Bmu1pt",       0, 0, 50, 0, 40}, 
    {"Bmu1pt",                      "Bmu2pt",       0, 0, 50, 0, 40}, 
    {"BDTStage1_pt15to50",          "BDT",      0, 0, 50, -1, 1},
    {"BDTStage1_pt15to50",          "PbPbBDT",      0, 0, 50, -1, 1},
};

int _nBins = nBins;
double *_ptBins = ptBins;
void setHist(TH1D* h, int v){
	h->SetXTitle(plotSetting[v].var);
	//h->SetYTitle("Events / (20 MeV/c^{2})");
	h->GetXaxis()->CenterTitle();
	h->GetYaxis()->CenterTitle();
	h->GetXaxis()->SetTitleOffset(1.0);
	h->GetYaxis()->SetTitleOffset(1.4);
	h->GetXaxis()->SetTitleSize(0.055);
	h->GetYaxis()->SetTitleSize(0.055);
	h->GetXaxis()->SetTitleFont(42);
	h->GetYaxis()->SetTitleFont(42);
	h->GetXaxis()->SetLabelFont(42);
	h->GetYaxis()->SetLabelFont(42);
	h->GetXaxis()->SetLabelSize(0.055);
	h->GetYaxis()->SetLabelSize(0.055);
	h->SetMarkerSize(1.55);
//	h->SetMarkerStyle(2);
	h->SetMarkerColor(4);
	//h->SetLineColor(1);
	h->SetLineWidth(4);
	h->SetStats(0);
	h->GetXaxis()->SetNdivisions(-50205);
}
void setTex(TLatex* tex){
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.055);
	tex->SetLineWidth(2);
}
void plotCompMC(int usePbPb = 0, TString inputmc_pp = "", TString inputmc_PbPb = "", TString varExp = "", TString trgselection_pp = "",  TString trgselection_PbPb = "", TString cut_pp = "", TString cut_PbPb = "", int isMC = 0, int vini = 1, int vend = 0, TString collsyst = "", TString outputfile = "", TString outplotf = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100.)
{
	collisionsystem=collsyst;
	if(varExp == "Bpt1050"){
		_nBins = nBins1050;
		_ptBins = ptBins1050;
		varExp = "Bpt";
	}
	if(varExp == "abs(By)"){
		_nBins = nBinsY;
		_ptBins = ptBinsY;
	}
	if(collisionsystem=="ppInc"||collisionsystem=="PbPbInc"){
		_nBins = nBinsInc;
		_ptBins = ptBinsInc;
	}

	hiBinMin = centmin*2;
	hiBinMax = centmax*2;
	centMin = centmin;
	centMax = centmax;

	if (!(usePbPb==1||usePbPb==0)) std::cout<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!, you are using a non valid isPbPb option"<<std::endl;
	bool isPbPb=(bool)(usePbPb);

	TString selmc_pp   = Form("%s&&%s",trgselection_pp.Data(),cut_pp.Data());
	TString selmc_PbPb = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection_PbPb.Data(),cut_PbPb.Data(),hiBinMin,hiBinMax);

	gStyle->SetTextSize(0.05);
	gStyle->SetTextFont(42);
	gStyle->SetPadRightMargin(0.043);
	gStyle->SetPadLeftMargin(0.18);
	gStyle->SetPadTopMargin(0.1);
	gStyle->SetPadBottomMargin(0.145);
	gStyle->SetTitleX(.0f);

	TFile* inf_pp   = new TFile(inputmc_pp.Data());
	TFile* inf_PbPb = new TFile(inputmc_PbPb.Data());

	TH1D* h_pp;
	TH1D* h_PbPb;

	TTree* nt_pp;
	TTree* nt_PbPb;

	nt_pp = (TTree*)inf_pp->Get("ntphi");
	nt_pp->AddFriend("ntHlt");
	nt_pp->AddFriend("ntHi");
	nt_pp->AddFriend("ntSkim");
	nt_pp->AddFriend("BDTStage1_pt15to50");

	nt_PbPb = (TTree*)inf_PbPb->Get("ntphi");
	nt_PbPb->AddFriend("ntHlt");
	nt_PbPb->AddFriend("ntHi");
	nt_PbPb->AddFriend("ntSkim");
	nt_PbPb->AddFriend("BDTStage1_pt15to50");

	TF1 *total;
	TString outputf;
	outputf = Form("%s",outputfile.Data());
	TFile* outf = new TFile(outputf.Data(),"recreate");
	outf->cd();

    TString weightmc_pp  = "HLT_HIL1DoubleMu0ForPPRef_v1*pthatweight*(pow(10, -0.365511 + 0.030289*Bgenpt + -0.000691*Bgenpt*Bgenpt + 0.000005*Bgenpt*Bgenpt*Bgenpt))";
	TString weightmc_PbPb = "(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)*pthatweight*(pow(10, -0.244653 + 0.016404*Bgenpt + -0.000199*Bgenpt*Bgenpt + 0.000000*Bgenpt*Bgenpt*Bgenpt))*(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))*(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))";

    TString _prefix = "";
    TString _isMC = "data";
    if(isMC) _isMC = "mc";
    TString _isPbPb = "pp";
    if(usePbPb) _isPbPb = "PbPb";
    TString _postfix = "";
    if(weightdata!="1") _postfix = "_EFFCOR";

	static Int_t count=0;
	for(int i=0;i<_nBins;i++)
	{
		TCanvas* c= new TCanvas(Form("c%d",count),"",600,600);
	    TLatex* tex1 = new TLatex(0.518,0.82,Form("%.0f < p_{T} < %.0f GeV/c",_ptBins[i],_ptBins[i+1]));
	    TLatex* tex2 = new TLatex(0.735,0.75,"|y| < 2.4");
	    TLatex* tex3 = new TLatex(0.25, 0.8,"MC");
		setTex(tex1);
		setTex(tex2);
		setTex(tex3);
		tex3->SetTextSize(0.07);
		TLegend* leg; 

		for(int v = vini; v < vend; v++){
			count++;
			h_pp   = new TH1D(Form("h_pp%d",count),  "", plotSetting[v].nBins, plotSetting[v].min, plotSetting[v].max);
			h_PbPb = new TH1D(Form("h_PbPb%d",count),"", plotSetting[v].nBins, plotSetting[v].min, plotSetting[v].max);
			setHist(h_pp, v);
			setHist(h_PbPb, v);
			h_pp->SetMarkerColor(3);
			h_pp->SetLineColor(3);
			
			nt_pp->Project(Form("h_pp%d",count), plotSetting[v].var.Data(), Form("%s*(%s&&%s>%f&&%s<%f)", weightmc_pp.Data(), Form("%s&&Bgen==23333",selmc_pp.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
			nt_PbPb->Project(Form("h_PbPb%d",count), plotSetting[v].var.Data(), Form("%s*(%s&&%s>%f&&%s<%f)", weightmc_PbPb.Data(), Form("%s&&Bgen==23333",selmc_PbPb.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
			h_pp->Scale(1/h_pp->Integral());
			h_pp->SetAxisRange(0,h_pp->GetMaximum()*1.4*1.2,"Y");
			h_PbPb->Scale(1/h_PbPb->Integral());
			h_PbPb->SetAxisRange(0,h_PbPb->GetMaximum()*1.4*1.2,"Y");

			leg = myLegend(0.20,0.75,0.35,0.90);
			leg->SetTextSize(0.05);
			leg->AddEntry(h_pp,"pp MC","pl");
			leg->AddEntry(h_PbPb,"PbPb MC","pl");
			h_pp->Draw("pe");
			h_PbPb->Draw("same pe");
			leg->Draw("same");
		    tex1->Draw();
		    tex2->Draw();
		    //tex3->Draw();
	        c->SaveAs(Form("%s%s/%s_%s_%d_%s.pdf",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),i,plotSetting[v].text.Data()));
		}
	}  
	outf->Close();
}

int main(int argc, char *argv[])
{
	if(argc==19)
	{
		plotCompMC(atoi(argv[1]), argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], atoi(argv[9]), atoi(argv[10]), atoi(argv[11]), argv[12], argv[13], argv[14], argv[15], atoi(argv[16]), atof(argv[17]), atof(argv[18]));
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
	return 0;
}
