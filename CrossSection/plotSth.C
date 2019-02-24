#include "fitB.h"
using namespace std;

const int nVar = 2;
string vexp[nVar] = {"Bmumumass", "Btktkmass"};
string vname[nVar] = {"Bmumumass", "Btktkmass"};
string vxaxis[nVar] = {"mumu mass (GeV)", "KK mass (GeV)"};
int vbins[nVar] = {100, 140};
float vbinmin[nVar] = {2.9, 0.98};
float vbinmax[nVar] = {3.4, 1.08};

int _nBins = nBins;
double *_ptBins = ptBins;
TLegend* aLegend(double x1, double y1, double x2, double y2);
void settex(TLatex *tex);
void plotSth(int usePbPb = 0, TString inputdata = "", TString inputmc = "", TString varExp = "", TString trgselection = "",  TString trgselectionmc = "", TString cut = "", TString cutmcgen = "", int isMC = 0, Double_t luminosity = 1., int doweight = 0, TString collsyst = "", TString outputfile = "", TString outplotf = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100., int MCvsMC = 0)
{
	collisionsystem=collsyst;
	if(varExp == "Bpt750"){
		_nBins = nBins750;
		_ptBins = ptBins750;
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
		selmc = Form("%s&&%s",trgselectionmc.Data(),cut.Data());
	}
	else
	{
		if(!MCvsMC){
			seldata = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
			selmc = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselectionmc.Data(),cut.Data(),hiBinMin,hiBinMax);
		}
		if(MCvsMC){
			seldata = Form("%s&&%s",trgselection.Data(),cut.Data());
			selmc = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselectionmc.Data(),cutmcgen.Data(),hiBinMin,hiBinMax);
		}
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
	TTree* ntMC;

	nt = (TTree*)inf->Get("ntphi");
	//nt->AddFriend("ntHlt");
	//nt->AddFriend("ntHi");
	//nt->AddFriend("ntSkim");
	//nt->AddFriend("BDTStage1_pt15to50");

	ntMC = (TTree*)infMC->Get("ntphi");
	//ntMC->AddFriend("ntHlt");
	//ntMC->AddFriend("ntHi");
	//ntMC->AddFriend("ntSkim");
	//ntMC->AddFriend("BDTStage1_pt15to50");

	TF1 *total;
	TString outputf;
	//outputf = Form("%s",outputfile.Data());
	//TFile* outf = new TFile(outputf.Data(),"recreate");
	//outf->cd();

	weightgen = weightgen_pp;
	weightmc  = weightmc_pp;
	if(usePbPb){
		weightgen = weightgen_PbPb;
		weightmc = weightmc_PbPb;
	}

    TString _prefix = "";
    TString _isMC = "data";
    if(isMC) _isMC = "mc";
    TString _isPbPb = "pp";
    if(usePbPb) _isPbPb = "PbPb";
    TString _postfix = "";
    if(weightdata!="1") _postfix = "_EFFCOR";

	for(int i=0;i<_nBins;i++)
	{
		TCanvas* c= new TCanvas(Form("c%d",i),"",600,600);
	    TLatex* tex1 = new TLatex(0.518,0.82,Form("%.0f < p_{T} < %.0f GeV/c",_ptBins[i],_ptBins[i+1]));
	    TLatex* tex2 = new TLatex(0.735,0.75,"|y| < 2.4");
	    TLatex* tex3 = new TLatex(0.62, 0.67,"Data");
	    TLatex* tex4 = new TLatex(0.62, 0.67,"MC");
	    TLatex* tex5 = new TLatex(0.70, 0.67,(usePbPb)? "PbPb" : "pp");
		setTex(tex1);
		setTex(tex2);
		setTex(tex3);
		setTex(tex4);
		setTex(tex5);
		tex3->SetTextSize(0.07);

		TLatex* texcms = new TLatex(0.21,0.88,"CMS");
		texcms->SetNDC();
		texcms->SetTextAlign(13);
		texcms->SetTextFont(62);
		texcms->SetTextSize(0.06);
		texcms->SetLineWidth(2);
		TLatex* texpre = new TLatex(0.21,0.83,"Internal");
		texpre->SetNDC();
		texpre->SetTextAlign(13);
		texpre->SetTextFont(52);
		texpre->SetTextSize(0.05);
		texpre->SetLineWidth(2);

		TLegend *leg;

		for(int v = 0; v < nVar; v++){
	    	_count++;
			h   = new TH1D(Form("h%d",_count),  "", vbins[v], vbinmin[v], vbinmax[v]);
			hMC = new TH1D(Form("hMC%d",_count),"", vbins[v], vbinmin[v], vbinmax[v]);
			if(!MCvsMC){
				nt->Project(Form("h%d",_count), vexp[v].c_str(), Form("(%s&&%s>%f&&%s<%f)*(1/%s)", seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
			}
			if(MCvsMC){
				nt->Project(Form("h%d",_count), vexp[v].c_str(), Form("%s*(%s&&%s>%f&&%s<%f)", weightmc_pp.Data(), Form("%s&&Bgen==23333",seldata.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
			}
			ntMC->Project(Form("hMC%d",_count), vexp[v].c_str(), Form("%s*(%s&&%s>%f&&%s<%f)", weightmc.Data(), Form("%s&&Bgen==23333",selmc.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
			hMC->Scale(h->Integral()/hMC->Integral());
			h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
			setHist(h);
			setHist(hMC);
		    h->SetXTitle(vxaxis[v].c_str());
		    hMC->SetXTitle(vxaxis[v].c_str());

			TString sigfunc = "[0]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])";
			TF1 *f = new TF1(Form("f%d",v),sigfunc.Data());
			f->SetParameter(0,h->Integral()*h->GetBinWidth(0));
			f->SetParameter(1,h->GetMean());
			f->SetParameter(2,h->GetRMS());
			h->Fit(Form("f%d",v));
    		TF1* t = (TF1*)h->GetFunction(Form("f%d",v))->Clone();
		    h->GetFunction(Form("f%d",v))->Delete();
			t->SetLineWidth(4);
			TLatex* texMean; 
			TLatex* texWidth; 
			texMean = new TLatex(0.65,0.58,Form("Mean = %f", f->GetParameter(1)));
			texWidth = new TLatex(0.65,0.52,Form("Width = %f", f->GetParameter(2)));
			settex(texMean);
			settex(texWidth);

//			h->SetMarkerColor(kGreen);
//			h->SetLineColor(kGreen);
			h->SetMarkerColor(kBlack);
			h->SetLineColor(kBlack);
		    h->SetMarkerStyle(20);
			h->SetMarkerSize(1.25);
			h->Draw("e");
			t->SetLineColor(kViolet);
			t->Draw("same");
		    leg = aLegend(0.62,0.65,0.85,0.7);
			leg->AddEntry(h,Form("%s data", _isPbPb.Data()), "p");
			leg->Draw("same");
		    tex1->Draw();
		    tex2->Draw();
			texMean->Draw("same");
			texWidth->Draw("same");
			texcms->Draw();
			texpre->Draw();
			if(!MCvsMC){
		    	c->SaveAs(Form("%s%s/%s_%s_0_%s.pdf",outplotf.Data(),_prefix.Data(),"data",_isPbPb.Data(),vname[v].c_str()));
		    	c->SaveAs(Form("%s%s/%s_%s_0_%s.png",outplotf.Data(),_prefix.Data(),"data",_isPbPb.Data(),vname[v].c_str()));
			}

			TF1 *fMC = new TF1(Form("fMC%d",v),sigfunc.Data());
			fMC->SetParameter(0,hMC->Integral()*hMC->GetBinWidth(0));
			fMC->SetParameter(1,hMC->GetMean());
			fMC->SetParameter(2,hMC->GetRMS());
			hMC->Fit(Form("fMC%d",v));
		    TF1* tMC = (TF1*)hMC->GetFunction(Form("fMC%d",v))->Clone();
    		hMC->GetFunction(Form("fMC%d",v))->Delete();
			tMC->SetLineWidth(4);
			TLatex* texMCMean; 
			TLatex* texMCWidth; 
			texMCMean = new TLatex(0.65,0.58,Form("Mean = %f", f->GetParameter(1)));
			texMCWidth = new TLatex(0.65,0.52,Form("Width = %f", f->GetParameter(2)));
			settex(texMCMean);
			settex(texMCWidth);

			hMC->SetMarkerColor(kBlue);
			hMC->SetMarkerColor(kBlue);
			hMC->SetLineColor(kRed);
		    hMC->SetMarkerStyle(21);
			hMC->SetMarkerSize(1.25);
			hMC->Draw("e");
			tMC->SetLineColor(kRed);
			tMC->Draw("same");
		    leg = aLegend(0.62,0.65,0.85,0.7);
			leg->AddEntry(hMC,Form("%s MC", _isPbPb.Data()), "p");
			leg->Draw("same");
		    tex1->Draw();
		    tex2->Draw();
			texMCMean->Draw("same");
			texMCWidth->Draw("same");
			texcms->Draw();
			texpre->Draw();
			if(!MCvsMC){
		        c->SaveAs(Form("%s%s/%s_%s_0_%s.pdf",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),vname[v].c_str()));
		        c->SaveAs(Form("%s%s/%s_%s_0_%s.png",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),vname[v].c_str()));
			}

            h->Draw("e");
			hMC->Draw("same hist");
//			t->Draw("same");
//			tMC->Draw("same");
//		    leg = aLegend(0.65,0.45,0.85,0.7);
		    leg = aLegend(0.65,0.55,0.85,0.7);
			if(!MCvsMC){
			    leg->AddEntry(h,Form("%s data", _isPbPb.Data()),"p");
			    leg->AddEntry(hMC,Form("%s MC", _isPbPb.Data()),"l");
			}
			if(MCvsMC){
			    leg->AddEntry(h,"pp MC","p");
			    leg->AddEntry(hMC,"PbPb MC","p");
			}
//		    leg->AddEntry(t,"Data fit","ll");
//		    leg->AddEntry(tMC,"MC fit","ll");
			leg->Draw("same");
		    tex1->Draw();
		    tex2->Draw();
			texcms->Draw();
			texpre->Draw();
			if(!MCvsMC){
		        c->SaveAs(Form("%s%s/%s_%s_0_%s.pdf",outplotf.Data(),_prefix.Data(),"mixed",_isPbPb.Data(),vname[v].c_str()));
		        c->SaveAs(Form("%s%s/%s_%s_0_%s.png",outplotf.Data(),_prefix.Data(),"mixed",_isPbPb.Data(),vname[v].c_str()));
			}
			if(MCvsMC){
		        c->SaveAs(Form("%s%s/%s_%s_0_%s.pdf",outplotf.Data(),_prefix.Data(),"mcvsmc_pp",_isPbPb.Data(),vname[v].c_str()));
		        c->SaveAs(Form("%s%s/%s_%s_0_%s.png",outplotf.Data(),_prefix.Data(),"mcvsmc_pp",_isPbPb.Data(),vname[v].c_str()));
			}
		}
	}  
	//outf->Close();
}

void settex(TLatex *tex){
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
}

TLegend* aLegend(double x1, double y1, double x2, double y2){
	TLegend* leg = new TLegend(x1,y1,x2,y2,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.055);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	return leg;
}

int main(int argc, char *argv[])
{
	if(argc==20)
	{
		plotSth(atoi(argv[1]), argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], atoi(argv[9]), atof(argv[10]), atoi(argv[11]), argv[12], argv[13], argv[14], argv[15], atoi(argv[16]), atof(argv[17]), atof(argv[18]), atoi(argv[19]));
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
	return 0;
}
