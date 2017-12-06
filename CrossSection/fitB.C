#include "uti.h"
#include "parameters.h"

double setparam0=100.;
double setparam1=5.36682;
double setparam2=0.02;
double setparam3=0.06;
double fixparam1=5.36682;

Double_t minhisto=5.00;
Double_t maxhisto=6.00;
Double_t nbinsmasshisto=50;
Double_t binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString weight;
TString weightgen;
TString weightdata;
TString seldata;
TString selmc;
TString selmceff;
TString selmcgen;
TString collisionsystem;
Float_t hiBinMin,hiBinMax,centMin,centMax;
double _ErrCor=1;

int _nBins = nBins;
double *_ptBins = ptBins;
double BmassAve = 5.36682;
double width = 0.05;
double BmassH = BmassAve + width;
double BmassL = BmassAve - width;
using namespace std;
void fitB(int usePbPb=0, TString inputdata="" , TString inputmc="", TString trgselection="",  TString cut="", TString cutmcgen="", int isMC=0, Double_t luminosity=1., int doweight=0, TString collsyst="", TString outputfile="", TString npfit="", int doDataCor = 0, Float_t centmin=0., Float_t centmax=100.)
{
	collisionsystem=collsyst;
	if(collisionsystem=="ppInc"||collisionsystem=="PbPbInc"){
		_nBins = nBinsInc;
		_ptBins = ptBinsInc;
	}

	hiBinMin = centmin*2;
	hiBinMax = centmax*2;
	centMin = centmin;
	centMax = centmax;

	double ErrorOnSigma(double width, double errwidth, double smear, double errsmearing);

	if (!(usePbPb==1||usePbPb==0)) std::cout<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!, you are using a non valid isPbPb option"<<std::endl;
	bool isPbPb=(bool)(usePbPb);

	if(!isPbPb)
	{
		seldata = Form("%s&&%s",trgselection.Data(),cut.Data());
		selmceff = Form("%s",cut.Data());
		selmcgen = Form("%s",cutmcgen.Data());
	}
	else
	{
		seldata = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
		selmceff = Form("%s&&hiBin>=%f&&hiBin<=%f",cut.Data(),hiBinMin,hiBinMax);
		selmcgen = Form("%s&&hiBin>=%f&&hiBin<=%f",cutmcgen.Data(),hiBinMin,hiBinMax);
	}

	selmc = Form("%s",cut.Data());

	gStyle->SetTextSize(0.05);
	gStyle->SetTextFont(42);
	gStyle->SetPadRightMargin(0.043);
	gStyle->SetPadLeftMargin(0.18);
	gStyle->SetPadTopMargin(0.1);
	gStyle->SetPadBottomMargin(0.145);
	gStyle->SetTitleX(.0f);

	void clean0 (TH1D* h);
	TF1* fit (TTree* nt, TTree* ntMC, double ptmin, double ptmax, int isMC,bool, TF1* &total,Float_t centmin, Float_t centmax, TString npfit);

	weightgen="1";
	weight="1";
	weightdata="1";
	// ignore this part
	if(doDataCor == 1){
		if(collisionsystem=="pp"||collisionsystem=="PP"||collisionsystem=="ppInc"||collisionsystem=="PbPbInc"){
			weightdata="(-6.098782e-02+4.106526e-04*Bpt+Bpt*Bpt*1.434530e-03+Bpt*Bpt*Bpt*-4.695382e-05+Bpt*Bpt*Bpt*Bpt*4.363289e-07)";
		}
		else{
			weightdata="( (hiBin>=0&& hiBin<20)*(3.117632e-02+-1.159784e-02*Bpt+Bpt*Bpt*1.219370e-03+Bpt*Bpt*Bpt*-2.963314e-05+Bpt*Bpt*Bpt*Bpt*2.301367e-07) + (hiBin>=20&&hiBin<60)*(4.379875e-02+-1.553269e-02*Bpt+Bpt*Bpt*1.603658e-03+Bpt*Bpt*Bpt*-3.987113e-05+Bpt*Bpt*Bpt*Bpt*3.104066e-07) + (hiBin>=60&&hiBin<100)*(6.381744e-02+-2.182311e-02*Bpt+Bpt*Bpt*2.237331e-03+Bpt*Bpt*Bpt*-6.150110e-05+Bpt*Bpt*Bpt*Bpt*5.475154e-07) + (hiBin>=100&&hiBin<=200)*(7.876289e-02+-2.580109e-02*Bpt+Bpt*Bpt*2.555978e-03+Bpt*Bpt*Bpt*-6.953917e-05+Bpt*Bpt*Bpt*Bpt*6.101012e-07) )";
		}
	}
	// ignore this part

	TFile* inf = new TFile(inputdata.Data());
	TFile* infMC = new TFile(inputmc.Data());

	TTree* nt = (TTree*)inf->Get("ntphi");
	nt->AddFriend("ntHlt");
	nt->AddFriend("ntHi");
	nt->AddFriend("ntSkim");
	nt->AddFriend("BDTStage1_pt15to50");

	TTree* ntGen = (TTree*)infMC->Get("ntGen");
	ntGen->AddFriend("ntHlt");
	ntGen->AddFriend("ntHi");

	TTree* ntMC = (TTree*)infMC->Get("ntphi");
	ntMC->AddFriend("ntHlt");
	ntMC->AddFriend("ntHi");
	ntMC->AddFriend("ntSkim");
	ntMC->AddFriend("BDTStage1_pt15to50");
	ntMC->AddFriend(ntGen);

	TH1D* hPt = new TH1D("hPt","",_nBins,_ptBins);
	TH1D* hPtRecoTruth = new TH1D("hPtRecoTruth","",_nBins,_ptBins);
	TH1D* hPtMC = new TH1D("hPtMC","",_nBins,_ptBins);
	TH1D* hPtGen = new TH1D("hPtGen","",_nBins,_ptBins);

	TH1D* hMean = new TH1D("hMean","",_nBins,_ptBins);                       
	TH1D* hSigmaGaus1 = new TH1D("hSigmaGaus1","",_nBins,_ptBins); 
	TH1D* hSigmaGaus2 = new TH1D("hSigmaGaus2","",_nBins,_ptBins); 
	TF1 *totalmass;

	TString outputf;
	outputf = Form("%s",outputfile.Data());
	TFile* outf = new TFile(outputf.Data(),"recreate");
	outf->cd();

	for(int i=0;i<_nBins;i++)
	{
		TF1* f = fit(nt,ntMC,_ptBins[i],_ptBins[i+1],isMC,isPbPb, totalmass,centmin, centmax, npfit);
		hMean->SetBinContent(i+1,f->GetParameter(1));
		hMean->SetBinError(i+1,f->GetParError(1));  
		double yield = f->Integral(minhisto,maxhisto)/binwidthmass;
		double yieldErr = f->Integral(minhisto,maxhisto)/binwidthmass*f->GetParError(0)/f->GetParameter(0);
        printf("yield: %f, yieldErr: %f\n", yield, yieldErr);
		yieldErr = yieldErr*_ErrCor;
		hPt->SetBinContent(i+1,yield/(_ptBins[i+1]-_ptBins[i]));
		hPt->SetBinError(i+1,yieldErr/(_ptBins[i+1]-_ptBins[i]));
	}  

	ntMC->Project("hPtMC","Bpt",TCut(weight)*(TCut(selmceff.Data())&&"(Bgen==23333)"));
	divideBinWidth(hPtMC);
	ntMC->Project("hPtRecoTruth","Bpt",TCut(selmceff.Data())&&"(Bgen==23333)");
	divideBinWidth(hPtRecoTruth);
	ntGen->Project("hPtGen","Gpt",TCut(weightgen)*(TCut(selmcgen.Data())));
	divideBinWidth(hPtGen);

	TCanvas* cPt =  new TCanvas("cPt","",600,600);
	cPt->SetLogy();
	hPt->SetXTitle("B_{s} p_{T} (GeV/c)");
	hPt->SetYTitle("Uncorrected dN(B_{s})/dp_{T}");
	hPt->Draw();
	if(isMC==1)
	{
		hPtMC->Draw("same hist");
		TLegend* legPt = myLegend(0.55,0.80,0.90,0.94);
		legPt->AddEntry(hPt,"Signal extraction","pl");
		legPt->AddEntry(hPtMC,"Matched reco","lf");
		legPt->Draw("same");  
	}
	hPtMC->Sumw2();
	TH1D* hEff = (TH1D*)hPtMC->Clone("hEff");
	hEff->SetTitle(";B_{s} p_{T} (GeV/c);Efficiency");
	hEff->Sumw2();
	hEff->Divide(hPtGen);
	TCanvas* cEff = new TCanvas("cEff","",600,600);
	hEff->Draw();

	TH1D* hPtCor = (TH1D*)hPt->Clone("hPtCor");
	hPtCor->SetTitle(";B_{s} p_{T} (GeV/c);Corrected dN(B_{s})/dp_{T}");
	hPtCor->Divide(hEff);
	TCanvas* cPtCor=  new TCanvas("cCorResult","",600,600);
	cPtCor->SetLogy();
	hPtCor->Draw();
	if(isMC==1)
	{
		hPtGen->Draw("same hist");
		TLegend* legPtCor = myLegend(0.55,0.80,0.90,0.94);
		legPtCor->AddEntry(hPtCor,"Corrected signal","pl");
		legPtCor->AddEntry(hPtGen,"Generated B_{s}","lf");
		legPtCor->Draw("same");  
	}

	TH1D* hPtSigma= (TH1D*)hPtCor->Clone("hPtSigma");
	hPtSigma->SetTitle(";B_{s} p_{T} (GeV/c);d#sigma(B_{s})/dp_{T} (pb/GeV)");
	hPtSigma->Scale(1./(2*luminosity*BRchain));
	TCanvas* cPtSigma=  new TCanvas("cPtSigma","",600,600);
	cPtSigma->SetLogy();
	hPtSigma->Draw();

	hPt->Write();
	hEff->Write();
	hMean->Write();
	hPtGen->Write();
	hPtMC->Write();
	hPtCor->Write();
	hPtSigma->Write();
	outf->Close();

}

void clean0(TH1D* h)
{
	for (int i=1;i<=h->GetNbinsX();i++)
	{
		if(h->GetBinContent(i)==0) h->SetBinError(i,1);
	}
}

TF1 *fit(TTree *nt, TTree *ntMC, Double_t ptmin, Double_t ptmax, int isMC,bool isPbPb,TF1* &total,Float_t centmin, Float_t centmax, TString npfit)
{
	static Int_t count=0;
	count++;
	TCanvas* c= new TCanvas(Form("c%d",count),"",600,600);
	TH1D* h = new TH1D(Form("h-%d",count),"",nbinsmasshisto,minhisto,maxhisto);
	TH1D* hMCSignal = new TH1D(Form("hMCSignal-%d",count),"",nbinsmasshisto,minhisto,maxhisto);

	TString iNP = npfit;
	//TF1 *f = new TF1(Form("f%d",count),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*x*x+[11]*("+iNP+")");
	TF1 *f = new TF1(Form("f%d",count),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*x*x");
	f->SetNpx(5000);
	f->SetLineWidth(5);

	if(isMC==1) nt->Project(Form("h-%d",count),"Bmass",Form("%s*(%s&&Bpt>%f&&Bpt<%f)*(1/%s)","1",seldata.Data(),ptmin,ptmax,weightdata.Data()));   
	else nt->Project(Form("h-%d",count),"Bmass",Form("(%s&&Bpt>%f&&Bpt<%f)*(1/%s)",seldata.Data(),ptmin,ptmax,weightdata.Data()));   

	ntMC->Project(Form("hMCSignal-%d",count),"Bmass",Form("%s&&Bpt>%f&&Bpt<%f",Form("%s&&Bgen==23333",selmc.Data()),ptmin,ptmax));
	clean0(h);

	//h->Draw();
	f->SetParLimits(4,-1000,1000);
	f->SetParLimits(2,0.01,0.1);
	f->SetParLimits(8,0.01,0.1);
	f->SetParLimits(7,0,1);
	f->SetParLimits(11,0,1000);

	f->SetParameter(0,setparam0);
	f->SetParameter(1,setparam1);
	f->SetParameter(2,setparam2);
	f->SetParameter(8,setparam3);
	f->FixParameter(1,fixparam1);
	f->FixParameter(11,0);

	if(weightdata != "1"){
		int maxb = h->GetMaximumBin();
		double _max = h->GetBinContent(maxb);
		double _maxE = h->GetBinError(maxb);
		_ErrCor = (_maxE/_max)/(1/sqrt(_max));
		f->SetParLimits(0,0,1e5);
		f->SetParLimits(4,-1e5,1e5);
		f->SetParLimits(11,0,1e4);
	}
	h->GetEntries();

	hMCSignal->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
	f->ReleaseParameter(1);
	hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",count),"L m","",minhisto,maxhisto);

	f->FixParameter(1,f->GetParameter(1));
	f->FixParameter(2,f->GetParameter(2));
	f->FixParameter(7,f->GetParameter(7));
	f->FixParameter(8,f->GetParameter(8));
	//f->ReleaseParameter(11);
	printf("Fixed para.:\n");
	printf("%f, %f, %f\n", f->GetParameter(2), f->GetParameter(7), f->GetParameter(8));
	h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
	f->ReleaseParameter(1);
	h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"L m","",minhisto,maxhisto);
	if(weightdata != "1"){
		//      h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
		//      h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
		//      h->Fit(Form("f%d",count),"m","",minhisto,maxhisto);
	}

	TF1 *background = new TF1(Form("background%d",count),"[0]+[1]*x+[2]*x*x");
	background->SetParameter(0,f->GetParameter(3));
	background->SetParameter(1,f->GetParameter(4));
	background->SetParameter(2,f->GetParameter(5));
	background->SetLineColor(4);
	background->SetRange(minhisto,maxhisto);
	background->SetLineStyle(7);//paper
	background->SetLineWidth(9);

	TF1 *Bkpi = new TF1(Form("fBkpi%d",count),"[0]*("+iNP+")");
	Bkpi->SetParameter(0,f->GetParameter(11));
	Bkpi->SetRange(minhisto,maxhisto);
	Bkpi->SetLineStyle(1);
	Bkpi->SetFillStyle(3005);//paper
	Bkpi->SetLineColor(kGreen+4);//paper
	Bkpi->SetFillColor(kGreen+4);//paper
	Bkpi->SetLineWidth(9);

	TF1 *mass = new TF1(Form("fmass%d",count),"[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))");
	mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8));
	mass->SetParError(0,f->GetParError(0));
	mass->SetParError(1,f->GetParError(1));
	mass->SetParError(2,f->GetParError(2));
	mass->SetParError(7,f->GetParError(7));
	mass->SetParError(8,f->GetParError(8));
	mass->SetFillColor(kOrange-3);//paper
	mass->SetLineColor(kOrange-3);//paper
	mass->SetFillStyle(3002);//paper
	mass->SetLineWidth(9);
	mass->SetLineStyle(7);//paper

	//h->SetXTitle("m_{#mu#muK} (GeV/c^{2})");
	h->SetXTitle("m_{B} (GeV/c^{2})");
	h->SetYTitle("Events / (20 MeV/c^{2})");
	h->GetXaxis()->CenterTitle();
	h->GetYaxis()->CenterTitle();
	h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
	h->GetXaxis()->SetTitleOffset(0.9);
	h->GetYaxis()->SetTitleOffset(1.3);
	h->GetXaxis()->SetTitleSize(0.07);
	h->GetYaxis()->SetTitleSize(0.07);
	h->GetXaxis()->SetTitleFont(42);
	h->GetYaxis()->SetTitleFont(42);
	h->GetXaxis()->SetLabelFont(42);
	h->GetYaxis()->SetLabelFont(42);
	h->GetXaxis()->SetLabelSize(0.06);
	h->GetYaxis()->SetLabelSize(0.06);
	h->SetMarkerSize(1.55);
	h->SetMarkerStyle(20);
	h->SetLineColor(1);
	h->SetLineWidth(5);
	h->SetStats(0);
	h->GetXaxis()->SetNdivisions(-50205);
	h->Draw("e");
	//Bkpi->SetRange(5.00,5.60);
	//Bkpi->Draw("same");
	background->Draw("same");   
	//mass->SetRange(5.16,5.40);
	mass->Draw("same");
	f->Draw("same");
	c->RedrawAxis();

	Double_t yield = mass->Integral(minhisto,maxhisto)/binwidthmass;
	Double_t yieldErr = mass->Integral(minhisto,maxhisto)/binwidthmass*mass->GetParError(0)/mass->GetParameter(0);
	Double_t bkgd = background->Integral(BmassL,BmassH)/binwidthmass;
	Double_t SB = yield/bkgd;
	Double_t Significance =  yield/TMath::Sqrt(bkgd+yield);

	TH1D* htest = new TH1D(Form("htest-%d",count),"",nbinsmasshisto,minhisto,maxhisto);
	TString sideband = "(abs(Bmass-5.367)>0.2&&abs(Bmass-5.367)<0.3";
	nt->Project(Form("htest-%d",count),"Bmass",Form("%s&&%s&&Bpt>%f&&Bpt<%f)*(1/%s)",sideband.Data(),seldata.Data(),ptmin,ptmax,weightdata.Data()));
	std::cout<<"yield bkg sideband: "<<htest->GetEntries()<<std::endl;

	TLegend *leg = new TLegend(0.525,0.38,0.85,0.70,NULL,"brNDC");//paper
	leg->SetBorderSize(0);
	leg->SetTextSize(0.06);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	leg->AddEntry(h,"Data","pl");
	leg->AddEntry(f,"Fit","l");
	leg->AddEntry(mass,"Signal","f");
	leg->AddEntry(background,"Combinatorial","l");
	leg->Draw("same");

	TLatex* texChi = new TLatex(0.55,0.28, Form("#chi^{2}/nDOF: %.2f/%d = %.2f", f->GetChisquare(), f->GetNDF(), f->GetChisquare()/f->GetNDF()));
	texChi->SetNDC();
	texChi->SetTextAlign(12);
	texChi->SetTextSize(0.04);
	texChi->SetTextFont(42);
	texChi->Draw();
	printf("NDF: %d, chi: %f, prob: %f\n", f->GetNDF(), f->GetChisquare(), f->GetProb());

	TLatex* texcms = new TLatex(0.22,0.87,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);//61
	texcms->SetTextSize(0.08);
	texcms->SetLineWidth(2);
	texcms->Draw();

	TLatex* texB = new TLatex(0.22,0.73,"B_{s}");
	texB->SetNDC();
	texB->SetTextFont(42);
	texB->SetTextSize(0.07);
	texB->SetLineWidth(2);
	texB->Draw();

	TLatex* texCol;
	if(collisionsystem=="pp"||collisionsystem=="PP"||collisionsystem=="ppInc"||collisionsystem=="PbPbInc") texCol= new TLatex(0.945,0.94, Form("28.0 pb^{-1} (%s 5.02 TeV)","pp"));
	else texCol= new TLatex(0.94,0.93, Form("350.1 #mub^{-1} (%s 5.02 TeV)","PbPb"));
	texCol->SetNDC();
	texCol->SetTextAlign(32);
	texCol->SetTextSize(0.06);
	texCol->SetTextFont(42);
	texCol->Draw();

	TLatex* tex;

	tex = new TLatex(0.488,0.82,Form("%.0f < p_{T} < %.0f GeV/c",ptmin,ptmax));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.06);
	tex->SetLineWidth(2);
	tex->Draw();

	tex = new TLatex(0.725,0.75,"|y| < 2.4");
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.06);
	tex->SetLineWidth(2);
	tex->Draw();

	total=f;
	tex = new TLatex(0.55,0.33,Form("Significance = %.3f",Significance));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw("SAME");

	TF1* t = (TF1*)h->GetFunction(Form("f%d",count))->Clone();
	h->GetFunction(Form("f%d",count))->Delete();
	t->Draw("same");
	h->Draw("e same");
	h->Write();
	hMCSignal->Write();

	TString _postfix = "";
	if(weightdata!="1") _postfix = "_EFFCOR";
	if(isPbPb && isMC==0) 
		c->SaveAs(Form("plotFits/data_PbPb_%.0f_%.0f%s.pdf",ptmin,ptmax,_postfix.Data()));
	else if(isPbPb && isMC==1) 
		c->SaveAs(Form("plotFits/mc_PbPb_%.0f_%.0f%s.pdf",ptmin,ptmax,_postfix.Data()));
	else if(!isPbPb && isMC==0) 
		c->SaveAs(Form("plotFits/data_pp_%.0f_%.0f%s.pdf",ptmin,ptmax,_postfix.Data()));
	else 
		c->SaveAs(Form("plotFits/mc_pp_%.0f_%.0f%s.pdf",ptmin,ptmax,_postfix.Data()));

	return mass;
}

int main(int argc, char *argv[])
{
	if(argc==16)
	{
		fitB(atoi(argv[1]),argv[2], argv[3], argv[4], argv[5], argv[6], atoi(argv[7]), atof(argv[8]), atoi(argv[9]),argv[10],argv[11],argv[12],atoi(argv[13]),atof(argv[14]),atof(argv[15]));
		return 0;
	}
	else if(argc==14)
	{
		fitB(atoi(argv[1]), argv[2], argv[3], argv[4], argv[5], argv[6], atoi(argv[7]), atof(argv[8]), atoi(argv[9]),argv[10],argv[11], argv[12], atoi(argv[13]));
		return 0;
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
}

double ErrorOnSigma(double width, double errwidth, double smear, double errsmearing){
	double squarederroronsigma=(1+smear)*(1+smear)*errwidth*errwidth+width*width*errsmearing*errsmearing;
	double erroronsigma=TMath::Sqrt(squarederroronsigma);
	return erroronsigma;
}
