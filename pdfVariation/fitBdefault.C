#include "uti.h"
#include "parameters.h"
#define BSUBS_MASS 5.36682
using namespace std;

void clean0 (TH1F* h);
int    drawOpt=0;
double _ErrCor=1;
TString npfit="1";
TString iNP =npfit;

double setparam0=100.;
double setparam1=BSUBS_MASS;
double setparam2=0.02;
double setparam3=0.06;
double fixparam1=BSUBS_MASS;

Double_t minhisto=5.00;
Double_t maxhisto=6.00;
Double_t nbinsmasshisto=50;
Double_t binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString collisionsystem;
TString infname;
Float_t centmin,centmax;

void fitBdefault(TString collsyst="PbPb", Float_t centMin=0, Float_t centMax=100, TString outputfile="outfMasshisto/mass")
{
  collisionsystem = collsyst;
  infname = outputfile;
  centmin = centMin;
  centmax = centMax;

  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);

  TF1* fit(Float_t ptmin, Float_t ptmax);
  ofstream fout(Form("outYield/default_%s_cent_%.0f_%.0f.dat",collsyst.Data(),centmin,centmax));
  ofstream falpha(Form("outAlpha/default_%s_cent_%.0f_%.0f.dat",collsyst.Data(),centmin,centmax));
  for(int i=0;i<nBins;i++)
    {
      TF1* f = fit(ptBins[i],ptBins[i+1]);
      Float_t yield = f->Integral(minhisto,maxhisto)/binwidthmass;
      fout<<ptBins[i]<<" "<<ptBins[i+1]<<" "<<yield<<endl;
      falpha<<ptBins[i]<<" "<<ptBins[i+1]<<" "<<f->GetParameter(6)<<" "<<f->GetParError(6)<<endl;
    }
  falpha.close();
  fout.close();
}

TF1* fit(Float_t ptmin, Float_t ptmax)
{
  TCanvas* c = new TCanvas(Form("c_%.0f_%.0f",ptmin,ptmax),"",600,600);
  TFile* infile = new TFile(Form("%s_%s_cent_%.0f_%.0f_pt_%.0f_%.0f.root",infname.Data(),collisionsystem.Data(),centmin,centmax,ptmin,ptmax));
  TH1F* h = (TH1F*)infile->Get("h");                    h->SetName(Form("h_%.0f_%.0f",ptmin,ptmax));
  TH1F* hMCSignal = (TH1F*)infile->Get("hMCSignal");    hMCSignal->SetName(Form("hMCSignal_%.0f_%.0f",ptmin,ptmax));
  TF1* f = new TF1(Form("f_%.0f_%.0f",ptmin,ptmax),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*x*x+[11]*("+iNP+")");

	f->SetNpx(5000);
	f->SetLineWidth(4);
	clean0(h);
  
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
	
    TString weightdata="1";
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

	hMCSignal->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"q","",minhisto,maxhisto);
	f->ReleaseParameter(1);
	hMCSignal->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"L m","",minhisto,maxhisto);

	f->FixParameter(1,f->GetParameter(1));
	f->FixParameter(2,f->GetParameter(2));
	f->FixParameter(7,f->GetParameter(7));
	f->FixParameter(8,f->GetParameter(8));
	printf("Fixed para.:\n");
	printf("%f, %f, %f\n", f->GetParameter(2), f->GetParameter(7), f->GetParameter(8));
    h->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"q","",minhisto,maxhisto);
    h->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"q","",minhisto,maxhisto);
	//f->ReleaseParameter(1); // release the signal mean
    h->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"L q","",minhisto,maxhisto);
    h->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"L q","",minhisto,maxhisto);
    h->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"L q","",minhisto,maxhisto);
    h->Fit(Form("f_%.0f_%.0f",ptmin,ptmax),"L m","",minhisto,maxhisto);
	//accessing fir results
	//https://root.cern.ch/root/html/ROOT__Fit__FitResult.html
	//TFitResultPtr fr = h->Fit(Form("f%d",count),"L m s e","",minhisto,maxhisto);
	//Int_t fitStatus = fr;
	//printf("fit result status: %d\n", fitStatus);
	//printf("Central val: %f\n", fr->GetParams()[0]);
	//printf("HESSE err: %f (%.2f%)\n" , fr->GetErrors()[0], fr->GetErrors()[0]/fr->GetParams()[0]*100);
	//printf("Minos err: %f (%.2f%), %f (%.2f%)\n", fr->LowerError(0), -fr->LowerError(0)/fr->GetParams()[0]*100, fr->UpperError(0), fr->UpperError(0)/fr->GetParams()[0]*100);
	//printf("diff in %: (%.2f%), (%.2f%)\n", -fr->LowerError(0)/fr->GetParams()[0]*100-fr->GetErrors()[0]/fr->GetParams()[0]*100, fr->UpperError(0)/fr->GetParams()[0]*100-fr->GetErrors()[0]/fr->GetParams()[0]*100);

	TF1* background = new TF1(Form("background_%.0f_%.0f",ptmin,ptmax),"[0]+[1]*x+[2]*x*x");
	background->SetParameter(0,f->GetParameter(3));
	background->SetParameter(1,f->GetParameter(4));
	background->SetParameter(2,f->GetParameter(5));
	background->SetLineColor(4);
	background->SetRange(minhisto,maxhisto);
	background->SetLineStyle(7);
	background->SetLineWidth(4);

	TF1 *Bkpi = new TF1(Form("Bkpi_%.0f_%.0f",ptmin,ptmax),"[0]*("+iNP+")");
	Bkpi->SetParameter(0,f->GetParameter(11));
	Bkpi->SetRange(minhisto,maxhisto);
	Bkpi->SetLineStyle(1);
	Bkpi->SetFillStyle(3005);
	Bkpi->SetLineColor(kGreen+4);
	Bkpi->SetFillColor(kGreen+4);
	Bkpi->SetLineWidth(4);

	TF1 *mass = new TF1(Form("fmass_%.0f_%.0f",ptmin,ptmax),"[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))");
	mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8));
	mass->SetParError(0,f->GetParError(0));
	mass->SetParError(1,f->GetParError(1));
	mass->SetParError(2,f->GetParError(2));
	mass->SetParError(7,f->GetParError(7));
	mass->SetParError(8,f->GetParError(8));
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
	h->Draw("e");
	if(npfit != "1"){
		Bkpi->SetRange(5.00,5.60);
		Bkpi->Draw("same");
	}
	background->Draw("same");   
	//mass->SetRange(5.16,5.40);
	mass->Draw("same");
	Bkpi->Draw("same");
	f->Draw("same");
	c->RedrawAxis();

	Double_t yield = mass->Integral(minhisto,maxhisto)/binwidthmass;
	Double_t yieldErr = mass->Integral(minhisto,maxhisto)/binwidthmass*mass->GetParError(0)/mass->GetParameter(0);
	printf("NDF: %d, chi: %f, prob: %f, recal: %f\n", f->GetNDF(), f->GetChisquare(), f->GetProb(), TMath::Prob(f->GetChisquare(), f->GetNDF()));
	float _chi2 = 0;
	for(int i = 0; i < h->GetNbinsX(); i++){
		float _data = h->GetBinContent(i+1);
		float _fit = f->Eval(h->GetBinCenter(i+1));
		float _err = h->GetBinError(i+1);
		float _chi = (_data-_fit)*(_data-_fit)/_err/_err;
		//printf("%f, %f, %f, %f\n", _data, _fit, _err, _chi);
		_chi2 += _chi;
	}
	printf("self cal chi2: %f\n", _chi2);

	TLegend *leg = new TLegend(0.525,0.46,0.85,0.75,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.055);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	leg->AddEntry(h,"Data","pl");
	leg->AddEntry(f,"Fit","l");
	leg->AddEntry(mass,"Signal","f");
	leg->AddEntry(background,"Combinatorial","l");
	leg->Draw("same");

	TLatex* texcms = new TLatex(0.22,0.87,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);
	texcms->SetTextSize(0.075);
	texcms->SetLineWidth(2);
//	texcms->Draw();
	
	TLatex* texB = new TLatex(0.225,0.74,"B_{s}");
	texB->SetNDC();
	texB->SetTextFont(42);
	texB->SetTextSize(0.055);
	texB->SetLineWidth(2);
//	texB->Draw();

// preliminary setting
texcms = new TLatex(0.22,0.87,"CMS");
texcms->SetNDC();
texcms->SetTextAlign(13);
texcms->SetTextFont(62);
texcms->SetTextSize(0.060);
texcms->SetLineWidth(2);
texcms->Draw();
texcms = new TLatex(0.22,0.81,"Preliminary");
texcms->SetNDC();
texcms->SetTextAlign(13);
texcms->SetTextFont(62);
texcms->SetTextSize(0.060);
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

    TLatex* texChi = new TLatex(0.55,0.37, Form("#chi^{2}/nDOF: %.2f/%d = %.2f", f->GetChisquare(), f->GetNDF(), f->GetChisquare()/f->GetNDF()));
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
	
  TLatex* texCms = new TLatex(0.18,0.93, "#scale[1.25]{CMS} Preliminary");
  texCms->SetNDC();
  texCms->SetTextAlign(12);
  texCms->SetTextSize(0.04);
  texCms->SetTextFont(42);
  texCms->Draw();
	
	
  TLatex* texPt = new TLatex(0.22,0.78,Form("%.1f < p_{T} < %.1f GeV/c",ptmin,ptmax));
  texPt->SetNDC();
  texPt->SetTextFont(42);
  texPt->SetTextSize(0.04);
  texPt->SetLineWidth(2);
  texPt->Draw();

  TLatex* texY = new TLatex(0.22,0.83,"|y| < 1.0");
  texY->SetNDC();
  texY->SetTextFont(42);
  texY->SetTextSize(0.04);
  texY->SetLineWidth(2);
  texY->Draw();

  TLatex* texYield = new TLatex(0.22,0.73,Form("N_{D} = %.0f #pm %.0f",yield,yieldErr));
  texYield->SetNDC();
  texYield->SetTextFont(42);
  texYield->SetTextSize(0.04);
  texYield->SetLineWidth(2);
  texYield->Draw();

  c->SaveAs(Form("plotFits/BMass_default_%s_cent_%.0f_%.0f_pt_%.0f_%.0f.pdf",collisionsystem.Data(),centmin,centmax,ptmin,ptmax));
  
  TCanvas* cPull = new TCanvas(Form("cPull_%.0f_%.0f",ptmin,ptmax),"",600,700);
  TH1F* hPull = (TH1F*)h->Clone("hPull");
  for(int i=0;i<h->GetNbinsX();i++)
    {
      Float_t nfit = f->Integral(h->GetBinLowEdge(i+1),h->GetBinLowEdge(i+1)+h->GetBinWidth(i+1))/h->GetBinWidth(i+1);
      if(h->GetBinError(i+1)==0)
        {
          hPull->SetBinContent(i+1,0.);
        }
      else hPull->SetBinContent(i+1,(h->GetBinContent(i+1)-nfit)/h->GetBinError(i+1));
      //hPull->SetBinError(i+1,0);
    }
  hPull->SetMinimum(-3.4);
  hPull->SetMaximum(3.4);
  hPull->SetYTitle("Pull");
  hPull->GetXaxis()->SetTitleOffset(1.);
  hPull->GetYaxis()->SetTitleOffset(0.65);
  hPull->GetXaxis()->SetLabelOffset(0.007);
  hPull->GetYaxis()->SetLabelOffset(0.007);
  hPull->GetXaxis()->SetTitleSize(0.12);
  hPull->GetYaxis()->SetTitleSize(0.12);
  hPull->GetXaxis()->SetLabelSize(0.1);
  hPull->GetYaxis()->SetLabelSize(0.1);
  hPull->GetYaxis()->SetNdivisions(504);
  TLine* lPull = new TLine(5.0, 0, 6.0, 0);
  lPull->SetLineWidth(1);
  lPull->SetLineStyle(7);
  lPull->SetLineColor(1);
  TPad* pFit = new TPad("pFit","",0,0.3,1,1);
  pFit->SetBottomMargin(0);
  pFit->Draw();
  pFit->cd();
  h->Draw("e");
  background->Draw("same");   
  mass->Draw("same");
  f->Draw("same");
  leg->Draw("same");
  texCms->Draw();
  texCol->Draw();
  texPt->Draw();
  texY->Draw();
  texYield->Draw();
  cPull->cd();
  
  
  TPad* pPull = new TPad("pPull","",0,0,1,0.3);
  pPull->SetTopMargin(0);
  pPull->SetBottomMargin(0.3);
  pPull->Draw();
  pPull->cd();
  hPull->Draw("e");
  lPull->Draw();
  cPull->cd();
  cPull->SaveAs(Form("plotFits/BMass_default_%s_cent_%.0f_%.0f_pt_%.0f_%.0f_Pull.pdf",collisionsystem.Data(),centmin,centmax,ptmin,ptmax));
  
  return mass;
}

void clean0(TH1F* h)
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

int main(int argc, char *argv[])
{
  if(argc==4)
    {
      fitBdefault(argv[1],atof(argv[2]),atof(argv[3]));
      return 0;
    }
  else if(argc==2)
    {
      fitBdefault(argv[1]);
      return 0;
    }
  else
    {
      std::cout << "Wrong number of inputs" << std::endl;
      return 1;
    }
}

