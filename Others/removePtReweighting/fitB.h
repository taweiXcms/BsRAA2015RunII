#include "uti.h"
#include "parameters.h"
using namespace std;
#define BSUBS_MASS 5.36682

void clean0 (TH1D* h);
int    drawOpt=0;
double _ErrCor=1;

double setparam0=100.;
double setparam1=BSUBS_MASS;
double setparam2=0.02;
double setparam3=0.06;
double fixparam1=BSUBS_MASS;

double minhisto=5.00;
double maxhisto=6.00;
int nbinsmasshisto=50;
double binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString weight="1";
TString weightgen="1";
TString weightmc="1";
TString weightdata="1";
TString seldata;
TString selmc;
TString selmcgen;
TString collisionsystem;
Float_t hiBinMin,hiBinMax,centMin,centMax;
static Int_t _count=0;
TF1 *fit(TCanvas* c, TH1D* h, TH1D* hMCSignal, Double_t ptmin, Double_t ptmax, int isMC, bool isPbPb, TF1* &total,Float_t centmin, Float_t centmax, TString npfit)
{
	cout<<"total data: "<<h->GetEntries()<<endl;
	c->cd();
	TString iNP = npfit;
	TF1 *f = new TF1(Form("f%d",_count),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*x*x+[11]*("+iNP+")");
	//TF1 *f = new TF1(Form("f%d",_count),"[0]*([7]*exp(-0.5*((x-[1])/[2])^2)/(sqrt(2*3.14159)*[2])+(1-[7])*exp(-0.5*((x-[1])/[8])^2)/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*x*x+[11]*("+iNP+")");
	if(npfit == "1") f = new TF1(Form("f%d",_count),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*x*x");
	//if(npfit == "1") f = new TF1(Form("f%d",_count),"[0]*([7]*exp(-0.5*((x-[1])/[2])^2)/(sqrt(2*3.14159)*[2])+(1-[7])*exp(-0.5*((x-[1])/[8])^2)/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*x*x");
	f->SetNpx(5000);
	f->SetLineWidth(4);
	//clean0(h);

	f->SetParLimits(2,0.01,0.1);
	f->SetParLimits(8,0.01,0.1);
	f->SetParLimits(7,0,1);
	f->SetParameter(0,setparam0);
	f->SetParameter(1,setparam1);
	f->SetParameter(2,setparam2);
	f->SetParameter(8,setparam3);
	f->FixParameter(6,0);//unused
	f->FixParameter(9,0);//unused
	f->FixParameter(10,0);//unused

	if(weightdata != "1"){
		int maxb = h->GetMaximumBin();
		double _max = h->GetBinContent(maxb);
		double _maxE = h->GetBinError(maxb);
		_ErrCor = (_maxE/_max)/(1/sqrt(_max));
		f->SetParLimits(0,0,1e5);
		f->SetParLimits(4,-1e5,1e5);
		f->SetParLimits(11,0,1e4);
	}

	f->FixParameter(1,fixparam1);
	f->FixParameter(3,0);
	f->FixParameter(4,0);
	f->FixParameter(5,0);
	f->FixParameter(11,0);
	hMCSignal->Fit(Form("f%d",_count),"q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"q","",minhisto,maxhisto);
	f->ReleaseParameter(1);
	hMCSignal->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"L m","",minhisto,maxhisto);

	f->ReleaseParameter(3);
	f->ReleaseParameter(4);
	f->ReleaseParameter(5);
	f->ReleaseParameter(11);
	f->SetParLimits(11,0,1000);
	f->FixParameter(1,f->GetParameter(1));
	f->FixParameter(2,f->GetParameter(2));
	f->FixParameter(7,f->GetParameter(7));
	f->FixParameter(8,f->GetParameter(8));
	h->Fit(Form("f%d",_count),"q","",minhisto,maxhisto);
	h->Fit(Form("f%d",_count),"q","",minhisto,maxhisto);
	f->ReleaseParameter(1); 
	h->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	TFitResultPtr fitResult = h->Fit(Form("f%d",_count),"L m s","",minhisto,maxhisto);

	TF1 *background = new TF1(Form("background%d",_count),"[0]+[1]*x+[2]*x*x");
	background->SetParameter(0,f->GetParameter(3));
	background->SetParameter(1,f->GetParameter(4));
	background->SetParameter(2,f->GetParameter(5));
	background->SetRange(minhisto,maxhisto);
	background->SetLineColor(4);
	background->SetLineStyle(7);
	background->SetLineWidth(4);

	TF1 *Bkpi = new TF1(Form("fBkpi%d",_count),"[0]*("+iNP+")");
	Bkpi->SetParameter(0,f->GetParameter(11));
	Bkpi->SetRange(minhisto,maxhisto);
	Bkpi->SetLineStyle(1);
	Bkpi->SetFillStyle(3005);
	Bkpi->SetLineColor(kGreen+4);
	Bkpi->SetFillColor(kGreen+4);
	Bkpi->SetLineWidth(4);

	TF1 *mass = new TF1(Form("fmass%d",_count),"[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))");
	//TF1 *mass = new TF1(Form("fmass%d",_count),"[0]*([3]*exp(-0.5*((x-[1])/[2])^2)/(sqrt(2*3.14159)*[2])+(1-[3])*exp(-0.5*((x-[1])/[4])^2)/(sqrt(2*3.14159)*[4]))");
	mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8));
	mass->SetParError(0,f->GetParError(0));
	mass->SetParError(1,f->GetParError(1));
	mass->SetParError(2,f->GetParError(2));
	mass->SetParError(3,f->GetParError(7));
	mass->SetParError(4,f->GetParError(8));
	mass->SetRange(minhisto,maxhisto);
	//mass->SetRange(5.16,5.40);
	mass->SetFillColor(kOrange-3);
	mass->SetLineColor(kOrange-3);
	mass->SetFillStyle(3002);
	mass->SetLineWidth(4);
	mass->SetLineStyle(7);

	h->SetXTitle("m_{B} (GeV/c^{2})");
	h->SetYTitle("Events / (20 MeV/c^{2})");
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
	h->SetMarkerStyle(20);
	h->SetLineColor(1);
	h->SetLineWidth(4);
	h->SetStats(0);
	h->GetXaxis()->SetNdivisions(-50205);
	//h->SetMaximum((h->GetBinContent(h->GetMaximumBin())+h->GetBinError(h->GetMaximumBin()))*1.4);
	h->SetMaximum((h->GetBinContent(h->GetMaximumBin()))*1.8);
	h->Draw("e");
	if(npfit != "1"){
		//Bkpi->SetRange(5.00,5.60);
		Bkpi->Draw("same");
	}
	background->Draw("same");   
	mass->Draw("same");
	f->Draw("same");
	c->RedrawAxis();

	//accessing fir results
	//https://root.cern.ch/root/html/ROOT__Fit__FitResult.html
	//TFitResultPtr fr = h->Fit(Form("f%d",_count),"L m s e","",minhisto,maxhisto);
	//Int_t fitStatus = fr;
	//printf("fit result status: %d\n", fitStatus);
	//printf("Central val: %f\n", fr->GetParams()[0]);
	//printf("HESSE err: %f (%.2f%)\n" , fr->GetErrors()[0], fr->GetErrors()[0]/fr->GetParams()[0]*100);
	//printf("Minos err: %f (%.2f%), %f (%.2f%)\n", fr->LowerError(0), -fr->LowerError(0)/fr->GetParams()[0]*100, fr->UpperError(0), fr->UpperError(0)/fr->GetParams()[0]*100);
	//printf("diff in %: (%.2f%), (%.2f%)\n", -fr->LowerError(0)/fr->GetParams()[0]*100-fr->GetErrors()[0]/fr->GetParams()[0]*100, fr->UpperError(0)/fr->GetParams()[0]*100-fr->GetErrors()[0]/fr->GetParams()[0]*100);a

	//print out chi2 calculations
	Double_t yield = mass->Integral(minhisto,maxhisto)/binwidthmass;
	Double_t yieldErr = mass->Integral(minhisto,maxhisto)/binwidthmass*mass->GetParError(0)/mass->GetParameter(0);
	TH1D* fh = (TH1D*)h->Clone("fh");
	double dataArr[nbinsmasshisto]; double dataErrArr[nbinsmasshisto]; double fitArr[nbinsmasshisto]; 
	for(int i = 0; i < nbinsmasshisto; i++){
		dataArr[i] = h->GetBinContent(i+1);
		dataErrArr[i] = h->GetBinError(i+1);
		fitArr[i] = f->Eval(h->GetBinCenter(i+1));
		fh->SetBinContent(i+1, fitArr[i]);
		fh->SetBinError(i+1, sqrt(fitArr[i]));
	}
	printf("f->GetNDF: %d, f->GetChisquare: %f\n", f->GetNDF(), f->GetChisquare());
	printf("h->Chisquare(f): %f, h->Chisquare(f,'L'): %f \n", h->Chisquare(f), h->Chisquare(f,"L"));
	printf("h->Chi2Test(fh): %f\n", h->Chi2Test(fh, "UU CHI2"));
	printf("2*fitResult->MinFcnValue(): %f\n", 2*fitResult->MinFcnValue());
	printf("f->GetProb: %f, TMath::Prob: %f\n", f->GetProb(), TMath::Prob(f->GetChisquare(), f->GetNDF()));
    double chi2Std = 0;
    double chi2Neyman = 0;
    double chi2Peason = 0;
    double chi2BakerCousins = 0;
	chi2Cal(dataArr, dataErrArr, fitArr, nbinsmasshisto, chi2Std, chi2Neyman, chi2Peason, chi2BakerCousins);
    printf("chi2 Standard: %f\n",chi2Std);
    printf("chi2 Neyman: %f\n",chi2Neyman);
    printf("chi2 Peason: %f\n",chi2Peason);
    printf("chi2 Baker & Cousins: %f\n",chi2BakerCousins);

	TLegend *leg = new TLegend(0.525,0.46,0.85,0.75,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.055);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	leg->AddEntry(h,"Data","pl");
	leg->AddEntry(f,"Fit","l");
	leg->AddEntry(mass,"Signal","f");
	leg->AddEntry(background,"Combinatorial","l");
	if(npfit != "1") leg->AddEntry(Bkpi,"B #rightarrow J/#psi X","f");
	leg->Draw("same");

	TLatex* texcms = new TLatex(0.22,0.87,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);
	texcms->SetTextSize(0.075);
	texcms->SetLineWidth(2);
	//texcms->Draw();

	TLatex* texB = new TLatex(0.225,0.74,"B_{s}");
	texB->SetNDC();
	texB->SetTextFont(42);
	texB->SetTextSize(0.055);
	texB->SetLineWidth(2);
	//texB->Draw();

	// preliminary setting
	texcms = new TLatex(0.21,0.88,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);
	texcms->SetTextSize(0.055);
	texcms->SetLineWidth(2);
	texcms->Draw();
	texcms = new TLatex(0.21,0.825,"Preliminary");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);
	texcms->SetTextSize(0.055);
	texcms->SetLineWidth(2);
	texcms->Draw();
	texB = new TLatex(0.225,0.68,"B_{s}");
	texB->SetNDC();
	texB->SetTextFont(42);
	texB->SetTextSize(0.055);
	texB->SetLineWidth(2);
	texB->Draw();
	// preliminary setting

	TLatex* texCol;
	if(collisionsystem=="pp"||collisionsystem=="PP"||collisionsystem=="ppInc"||collisionsystem=="PbPbInc") texCol= new TLatex(0.95,0.94, Form("28.0 pb^{-1} (%s 5.02 TeV)","pp"));
	else texCol= new TLatex(0.945,0.94, Form("351 #mub^{-1} (%s 5.02 TeV)","PbPb"));
	texCol->SetNDC();
	texCol->SetTextAlign(32);
	texCol->SetTextSize(0.055);
	texCol->SetTextFont(42);
	texCol->Draw();

	TLatex* texChi = new TLatex(0.55,0.37, Form("#chi^{2}/nDOF: %.2f/%d = %.2f", chi2BakerCousins, f->GetNDF(), chi2BakerCousins/f->GetNDF()));
	texChi->SetNDC();
	texChi->SetTextAlign(12);
	texChi->SetTextSize(0.04);
	texChi->SetTextFont(42);
	if(drawOpt == 1) texChi->Draw();

	double width = 0.05;
	double BmassH = BSUBS_MASS + width;
	double BmassL = BSUBS_MASS - width;
	Double_t bkgd = background->Integral(BmassL,BmassH)/binwidthmass;
	Double_t SB = yield/bkgd;
	Double_t Significance =  yield/TMath::Sqrt(bkgd+yield);
	TLatex* texSig = new TLatex(0.55,0.42,Form("Significance = %.3f",Significance));
	texSig->SetNDC();
	texSig->SetTextFont(42);
	texSig->SetTextSize(0.04);
	texSig->SetLineWidth(2);
	if(drawOpt == 1) texSig->Draw("SAME");

	TLatex* texYield = new TLatex(0.55,0.30,Form("Yield = %.3f",yield));
	texYield->SetNDC();
	texYield->SetTextFont(42);
	texYield->SetTextSize(0.04);
	texYield->SetLineWidth(2);
	if(drawOpt == 1) texYield->Draw("SAME");

	TF1* t = (TF1*)h->GetFunction(Form("f%d",_count))->Clone();
	h->GetFunction(Form("f%d",_count))->Delete();
	t->Draw("same");
	h->Draw("e same");
	h->Write();
	hMCSignal->Write();

	total=f;
	return mass;
}

void clean0(TH1D* h)
{
	for (int i=1;i<=h->GetNbinsX();i++)
	{
		if(h->GetBinContent(i)==0) h->SetBinError(i,1);
	}
}

double ErrorOnSigma(double width, double errwidth, double smear, double errsmearing){
	double squarederroronsigma=(1+smear)*(1+smear)*errwidth*errwidth+width*width*errsmearing*errsmearing;
	double erroronsigma=TMath::Sqrt(squarederroronsigma);
	return erroronsigma;
}