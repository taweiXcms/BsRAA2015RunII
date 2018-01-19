#include "fitB.h"
using namespace std;

const int nVar = 2;
string vexp[nVar] = {"Bmumumass", "Btktkmass"};
string vname[nVar] = {"Bmumumass", "Btktkmass"};
string vxaxis[nVar] = {"mumu mass (GeV)", "KK mass (GeV)"};
int vbins[nVar] = {50, 50};
float vbinmin[nVar] = {2.8, 0.96};
float vbinmax[nVar] = {3.4, 1.1};

int _nBins = nBins;
double *_ptBins = ptBins;
void setHist(TH1D* h, int v){
	h->SetXTitle(vxaxis[v].c_str());
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
	h->SetMarkerStyle(2);
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
void plotSth(int usePbPb = 0, int fitOnSaved = 0, TString inputdata = "", TString inputmc = "", TString varExp = "", TString trgselection = "",  TString cut = "", TString cutmcgen = "", int isMC = 0, Double_t luminosity = 1., int doweight = 0, TString collsyst = "", TString outputfile = "", TString outplotf = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100.)
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

	if(!isPbPb)
	{
		seldata = Form("%s&&%s",trgselection.Data(),cut.Data());
		selmc = Form("%s",cut.Data());
		selmcgen = Form("%s",cutmcgen.Data());
	}
	else
	{
		seldata = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
		selmc = Form("%s&&hiBin>=%f&&hiBin<=%f",cut.Data(),hiBinMin,hiBinMax);
		selmcgen = Form("%s&&hiBin>=%f&&hiBin<=%f",cutmcgen.Data(),hiBinMin,hiBinMax);
	}

	gStyle->SetTextSize(0.05);
	gStyle->SetTextFont(42);
	gStyle->SetPadRightMargin(0.043);
	gStyle->SetPadLeftMargin(0.18);
	gStyle->SetPadTopMargin(0.1);
	gStyle->SetPadBottomMargin(0.145);
	gStyle->SetTitleX(.0f);

	TFile* inf = new TFile(inputdata.Data());
	TFile* infMC = new TFile(inputmc.Data());

	TH1D* h;
	TH1D* hMC;

	TTree* nt;
	TTree* ntGen;
	TTree* ntMC;

	if(fitOnSaved == 0){
		nt = (TTree*)inf->Get("ntphi");
		nt->AddFriend("ntHlt");
		nt->AddFriend("ntHi");
		nt->AddFriend("ntSkim");
		nt->AddFriend("BDTStage1_pt15to50");
	
		ntGen = (TTree*)infMC->Get("ntGen");
		ntGen->AddFriend("ntHlt");
		ntGen->AddFriend("ntHi");
	
		ntMC = (TTree*)infMC->Get("ntphi");
		ntMC->AddFriend("ntHlt");
		ntMC->AddFriend("ntHi");
		ntMC->AddFriend("ntSkim");
		ntMC->AddFriend("BDTStage1_pt15to50");
		ntMC->AddFriend(ntGen);
	}

	TF1 *total;
	TString outputf;
	outputf = Form("%s",outputfile.Data());
	TFile* outf = new TFile(outputf.Data(),"recreate");
	outf->cd();

    weightgen = "pthatweight*(pow(10, -0.365511 + 0.030289*Gpt + -0.000691*Gpt*Gpt + 0.000005*Gpt*Gpt*Gpt))";
    weightmc  = "HLT_HIL1DoubleMu0ForPPRef_v1*pthatweight*(pow(10, -0.365511 + 0.030289*Bgenpt + -0.000691*Bgenpt*Bgenpt + 0.000005*Bgenpt*Bgenpt*Bgenpt))";
	if(usePbPb){
		weightgen = "pthatweight*(pow(10, -0.244653 + 0.016404*Gpt + -0.000199*Gpt*Gpt + 0.000000*Gpt*Gpt*Gpt))";
		weightmc = "(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)*pthatweight*(pow(10, -0.244653 + 0.016404*Bgenpt + -0.000199*Bgenpt*Bgenpt + 0.000000*Bgenpt*Bgenpt*Bgenpt))*(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))*(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))";
	}

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
    	count++;
		TCanvas* c= new TCanvas(Form("c%d",count),"",600,600);
	    TLatex* tex1 = new TLatex(0.518,0.82,Form("%.0f < p_{T} < %.0f GeV/c",_ptBins[i],_ptBins[i+1]));
	    TLatex* tex2 = new TLatex(0.735,0.75,"|y| < 2.4");
	    TLatex* tex3 = new TLatex(0.25, 0.8,"Data");
	    TLatex* tex4 = new TLatex(0.25, 0.8,"MC");
		setTex(tex1);
		setTex(tex2);
		setTex(tex3);
		setTex(tex4);
		tex3->SetTextSize(0.07);

		for(int v = 0; v < nVar; v++){
			count = i;
			h   = new TH1D(Form("h-%d",count),  "", vbins[v], vbinmin[v], vbinmax[v]);
			hMC = new TH1D(Form("hMC-%d",count),"", vbins[v], vbinmin[v], vbinmax[v]);
			setHist(h, v);
			setHist(hMC, v);
			nt->Project(Form("h-%d",count),     vexp[v].c_str(), Form("(%s&&%s>%f&&%s<%f)*(1/%s)", seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
			ntMC->Project(Form("hMC-%d",count), vexp[v].c_str(), Form("%s*(%s&&%s>%f&&%s<%f)", weightmc.Data(), Form("%s&&Bgen==23333",selmc.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
			h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
			hMC->Scale(1/hMC->Integral());
			hMC->SetAxisRange(0,hMC->GetMaximum()*1.4*1.2,"Y");
	    	TLatex* tex;

			h->Draw("p");
		    tex1->Draw();
		    tex2->Draw();
		    tex3->Draw();
	        c->SaveAs(Form("%s%s/%s_%s_%d_%s.pdf",outplotf.Data(),_prefix.Data(),"data",_isPbPb.Data(),count,vname[v].c_str()));

			hMC->Draw("p");
		    tex1->Draw();
		    tex2->Draw();
		    tex4->Draw();
	        c->SaveAs(Form("%s%s/%s_%s_%d_%s.pdf",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),count,vname[v].c_str()));
		}
	}  
	outf->Close();
}

int main(int argc, char *argv[])
{
	if(argc==19)
	{
		plotSth(atoi(argv[1]), atoi(argv[2]), argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], atoi(argv[9]), atof(argv[10]), atoi(argv[11]), argv[12], argv[13], argv[14], argv[15], atoi(argv[16]), atof(argv[17]), atof(argv[18]));
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
	return 0;
}
