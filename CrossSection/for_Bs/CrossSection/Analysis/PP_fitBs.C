#include "utilities.h"
#include "TStyle.h"
//double luminosity=34.6*1e-3;//need to be changed for 2015 pp and PbPb datas!
//double luminosity=25.57;//need to be changed for 2015 pp and PbPb datas!
double luminosity=27.87;//for 2015 pp 
double setparam0=100.;
double setparam1=5.36;
double setparam2=0.02;
double setparam3=0.06;
double fixparam1=5.367;

 //MC// double setparam2=0.005;
 //MC//double setparam3=0.01;


//pp // 
TString inputdata="/data/wangj/Data2015/Bntuple/pp/ntB_EvtBase_20160420_BfinderData_pp_20160419_bPt0jpsiPt0tkPt0p5.root";

//pp mc//
//TString inputmc="/afs/cern.ch/work/c/cdozen/UP_BFINDER/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Bntuple/looper/loop_Bs0_pthat5_bstojpsiphi_pp.root";
//NP bg // 
TString inputmc="/afs/cern.ch/work/c/cdozen/UP_BFINDER/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Bntuple/looper/NPfiles/loop_BJpsiMM_pp_NP.root";

//const int nBins = 4; Double_t ptBins[nBins+1] = {5.,10.,20.,40.,80};
//const int nBins = 3; Double_t ptBins[nBins+1] = {5.,15.,25.,80};
//const int nBins = 4; Double_t ptBins[nBins+1] = {5.,10.,15.,20.,60.};// larger then 60 we don't have any entries
//const int nBins = 3; Double_t ptBins[nBins+1] = {5.,10.,15.,60.};// larger then 60 we don't have any entries
const int nBins = 1; Double_t ptBins[nBins+1] = {15.,60.};// larger then 60 we don't have any entries
TString weight = "1"; 
//GM cuts
//TString cut = "TMath::Abs(By)<2.4&&abs(Bmumumass-3.096916)<0.15&&Bmass>5.&&Bmass<6.&&Btrk1Pt>0.7&&Btrk2Pt>0.7&&Bchi2cl>3.71e-02&&(Bd0/Bd0Err)>2.&&cos(Bdtheta)>2.60e-01&&abs(Btktkmass-1.019455)<1.55e-02&&Bmu1pt>1.5&&Bmu2pt>1.5";//Ginnocen Bscuts
//for pp //
TString cut="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8))&& ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1highPurity&&Bmass>5&&Bmass<6&&Btrk1Pt>0.7&&Btrk2Pt>0.7&&Bchi2cl>1.32e-02&&(Bd0/Bd0Err)>2.&&cos(Bdtheta)>2.60e-01&&Bmu1pt>1.5&&Bmu2pt>1.5&&Blxy>0.025&&abs(Btktkmass-1.019455)<1.55e-02";

//TString seldata = Form("%s",cut.Data());
TString selmc = Form("%s",cut.Data());
TString selmcgen = "TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0";
TString seldata_2y=Form("%s",cut.Data());
//TString cut_recoonly="1";
//TString weight = "27.493+Bpt*(-0.218769)";
TString selmcgenacceptance="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0&& ((TMath::Abs(Gmu1eta)<1.2 && Gmu1pt>3.5) || (TMath::Abs(Gmu1eta)>1.2 && TMath::Abs(Gmu1eta)<2.1 && Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta))) || (TMath::Abs(Gmu1eta)>2.1 && TMath::Abs(Gmu1eta)<2.4 && Gmu1pt>1.8)) && ((TMath::Abs(Gmu2eta)<1.2 && Gmu2pt>3.5) || (TMath::Abs(Gmu2eta)>1.2 && TMath::Abs(Gmu2eta)<2.1 && Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta))) || (TMath::Abs(Gmu2eta)>2.1 && TMath::Abs(Gmu2eta)<2.4 && Gmu2pt>1.8)) && Gtk1pt>0.5 && TMath::Abs(Gtk1eta)<2.4";
//detector acceptance: muon and track pt acceptance 
//void fitBs(TString infname="",bool doweight = 1)


void fitBs_pp_original(TString infname="",Bool_t doweight = false)
{
  gStyle->SetMarkerStyle(20);
  void clean0(TH1D *h); 
  TF1* fit(TTree *nt, TTree *ntMC, Double_t ptmin, Double_t ptmax);  
// if (doweight==0) weight="1";
  // if (infname=="") infname=inputdata.Data();
  //TFile *inf = new TFile(infname.Data());
   if (!doweight) weight="1"; 
   TFile *inf = new TFile(inputdata.Data());
   TTree *nt = (TTree*) inf->Get("ntphi");

   TFile *infMC = new TFile(inputmc.Data());
   TTree *ntGen = (TTree*)infMC->Get("ntGen");
   TTree *ntMC = (TTree*)infMC->Get("ntphi");
   ntGen->AddFriend(ntMC);

   TH1D *hPt = new TH1D("hPt","",nBins,ptBins);
   TH1D *hPtMC = new TH1D("hPtMC","",nBins,ptBins);
   TH1D *hPtGen = new TH1D("hPtGen","",nBins,ptBins);
   TH1D *hRecoTruth = new TH1D("hRecoTruth","",nBins,ptBins);
   TH1D *hPtGenAcc = new TH1D("hPtGenAcc","",nBins,ptBins);   
   
  TLatex* texlumi = new TLatex(0.9,0.92," 27.87 pb^{-1} (5.03 TeV pp)");
  texlumi->SetNDC();
  texlumi->SetTextAlign(31);
  texlumi->SetTextFont(42);
  texlumi->SetTextSize(0.038);
  texlumi->SetLineWidth(2);
 
  TLatex* texY = new TLatex(0.5,0.750,"|y| < 2.4");
  texY->SetNDC();
  texY->SetTextFont(42);
  texY->SetTextSize(0.05);
  texY->SetLineWidth(2);
 
  TLatex* texCms = new TLatex(0.08,0.95, "CMS Internal") ;// Preliminary");
  texCms->SetNDC();
  texCms->SetTextAlign(13);
  texCms->SetTextSize(0.038);
  texCms->SetTextFont(62);
 
TH1D *hPtGenAll = new TH1D("hPtGenAll","",nBins,ptBins);
   

    for (int i=0;i<nBins;i++)
   {
      TF1 *f = fit(nt,ntMC,ptBins[i],ptBins[i+1]);
      double yield = f->Integral(5,6)/0.04;
      double yieldErr = f->Integral(5,6)/0.04*f->GetParError(0)/f->GetParameter(0);
      hPt->SetBinContent(i+1,yield/(ptBins[i+1]-ptBins[i]));
      hPt->SetBinError(i+1,yieldErr/(ptBins[i+1]-ptBins[i]));
   }
    

   //const int nBins = 4;
   //double ptBins[nBins+1] = {5,10,20,40,80};
   TCanvas *c=  new TCanvas("cResult","",600,600);
   c->SetLogy();
   hPt->SetXTitle("B^{0}_{s} p_{T} (GeV/c)");
   hPt->SetYTitle("Uncorrected B^{0}_{s} dN/dp_{T}");
   hPt->SetLineColor(2);
   hPt->SetMarkerColor(2);
   hPt->Sumw2();
   hPt->Draw();
   texlumi->Draw();
   texY->Draw();
   texCms->Draw();
   //hRecoTruth->Draw("same hist");
   //hRecoTruth->Draw("same");
   //c->SaveAs(Form("ResultBs/hPtResult_pp.pdf"));
   c->SaveAs(Form("ResultBs/hPtResult_MC_pp.pdf"));

   ntMC->Project("hPtMC","Bpt",TCut(weight)*(TCut(selmc.Data()))&&"(Bgen==23333)");
   ntMC->Project("hRecoTruth","Bpt",TCut(seldata_2y.Data())&&"(Bgen==23333)");
   ntGen->Project("hPtGen","Gpt",TCut(weight)*(TCut(selmcgen.Data())));
   ntGen->Project("hPtGenAcc","Gpt",TCut(weight)*(TCut(selmcgenacceptance.Data())));
   divideBinWidth(hRecoTruth);
   divideBinWidth(hPtMC);
   divideBinWidth(hPtGen);
   divideBinWidth(hPtGenAcc);
  // divideBinWidth(hPtGenAll);
   //Eff*Acc
   hPtMC->Sumw2();
   hPtMC->SetLineColor(2);
   hPtMC->SetMarkerColor(2);
   hPtMC->GetYaxis()->SetTitleOffset(1.2);
   TH1D *hEffAcc = (TH1D*)hPtMC->Clone("hEffAcc");
   hEffAcc->Sumw2();
   hEffAcc->Divide(hPtGen);
   hEffAcc->SetLineColor(2);
   hEffAcc->SetMarkerColor(2);
   hEffAcc->SetYTitle("#epsilon x #alpha");
   hEffAcc->GetYaxis()->SetTitleSize(0.05);
   hEffAcc->SetXTitle("B^{0}_{s} p_{T} (GeV/c)");
   hEffAcc->GetYaxis()->SetTitleOffset(0.9);
   hEffAcc->GetXaxis()->SetTitleSize(0.05);
   //Eff
   TH1D* hEff = (TH1D*)hRecoTruth->Clone("hEff"); 
   hEff->Sumw2();
   hEff->Divide(hPtGenAcc);
   hEff->SetLineColor(2);
   hEff->SetMarkerColor(2);
   hEff->SetYTitle("#epsilon");
   hEff->GetYaxis()->SetTitleSize(0.05);
   hEff->GetYaxis()->SetTitleOffset(0.9);
   hEff->SetXTitle("B^{0}_{s} p_{T} (GeV/c)");
   hEff->GetXaxis()->SetTitleSize(0.05);
   //Acc
   ////TH1D* hAcc = (TH1D*)hPtGenAll->Clone("hAcc");
   //hAcc->Sumw2();
   //hAcc->Divide(hAcc,hPtGen,1,1,"b");
   
   TH1D* hAcc = (TH1D*)hPtGenAcc->Clone("hAcc");
   hAcc->Sumw2();
   hAcc->Divide(hAcc,hPtGen,1,1,"b");
   hAcc->SetLineColor(2);
   hAcc->SetMarkerColor(2);
   hAcc->SetYTitle("#alpha");
   hAcc->GetYaxis()->SetTitleSize(0.05);
   hAcc->GetYaxis()->SetTitleOffset(0.9);
   hAcc->SetXTitle("B^{0}_{s} p_{T} (GeV/c)");
   hAcc->GetXaxis()->SetTitleSize(0.05);

  // TH1D* hEffSelection = (TH1D*)hPtMC->Clone("hEffSelection");
   // hEffSelection->Sumw2();
    //hEffSelection->Divide(hEffSelection,hRecoTruth,1,1,"b");

  TH1D *hPtCor = (TH1D*)hPt->Clone("hPtCor");
  hPtCor->Divide(hEffAcc);
  TCanvas *cCor=  new TCanvas("cCorResult","",600,600);
  cCor->SetLogy();
  hPtCor->SetYTitle("Correctd B^{0}_{s} dN/dp_{T}");
  hPtCor->GetYaxis()->SetTitleOffset(1.2);
  hPtCor->SetLineColor(2);
  hPtCor->SetMarkerColor(2);
  hPtCor->Draw();
  texlumi->Draw();
  texY->Draw();
  texCms->Draw();
  //hPtGen->Draw("same");
 // cCor->SaveAs(Form("ResultBs/PtCor_pp.pdf"));
  cCor->SaveAs(Form("ResultBs/PtCor_MC_pp.pdf"));

  TH1D *hPtSigma= (TH1D*)hPtCor->Clone("hPtSigma");
  double BRchain=3.1189e-5;
  hPtSigma->Scale(1./(2*luminosity*BRchain));
  hPtSigma->SetYTitle("d#sigma/dp_{T} (B^{0}_{s}) (pb/GeV)");
  hPtSigma->GetYaxis()->SetTitleOffset(1.2);
  hPtSigma->SetLineColor(2);
  hPtSigma->SetMarkerColor(2);
  TCanvas *cSigma=  new TCanvas("cSigma","",600,600);
  cSigma->SetLogy();
  hPtSigma->Draw();
  texlumi->Draw();
  texY->Draw();
  texCms->Draw();
  cSigma->SaveAs(Form("ResultBs/PtSigma_MC_pp.pdf"));
  //cSigma->SaveAs(Form("ResultBs/PtSigma_pp.pdf"));
  
  
  TCanvas*canvas=new TCanvas("canvas","canvas",1000.,400);
  canvas->Divide(3,1);
  canvas->cd(1);
  gPad->SetLogy();
  hPtGen->Draw();
  texlumi->Draw();
  texY->Draw();
  texCms->Draw();
  canvas->cd(2);
  gPad->SetLogy();
  hPtMC->Draw();
  texlumi->Draw();
  texY->Draw();
  texCms->Draw();
  canvas->cd(3);
  hEffAcc->Draw();
  texlumi->Draw();
  texY->Draw();
  texCms->Draw();
  


  TFile *outf = new TFile("ResultBs/mc_pp.root","recreate");
  //TFile *outf = new TFile("ResultBs/fitBs_pp.root","recreate");
  outf->cd();
  hPt->Write();
  hPtMC->Write();
  hEffAcc->Write();
  hEff->Write();
  //hEffSelection->Write();
  hAcc->Write();
  hPtCor->Write();
  hPtSigma->Write();
  outf->Close();
  delete outf;

}


void clean0(TH1D *h)
{
   for (int i=1;i<=h->GetNbinsX();i++)
   {
      if (h->GetBinContent(i)==0) h->SetBinError(i,1);
   }
}


TF1 *fit(TTree *nt,TTree *ntMC,double ptmin,double ptmax)
{   
   //cout<<cut.Data()<<endl;
   static int count=0;
   count++;
   TCanvas *c= new TCanvas(Form("c%d",count),"",600,600);
   TH1D *h = new TH1D(Form("h%d",count),"",24,5.03,5.99);
   TH1D *hMC = new TH1D(Form("hMC%d",count),"",24,5.03,5.99);
   // Fit function
  
  TString iNP="Gaus(x,5.36800e+00,5.77122e-02)/(sqrt(2*3.14159)*abs(5.77122e-02))";
 // TString iNP="[0]*TMath::Erf((x-[1])/[2]) + [0] + [9]+[10]*x ";  
 //TString iNP="3.12764e1*Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2) +2.11124e2";
   TF1 *f = new TF1(Form("f%d",count),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+ [3]+[4]*x+[5]*x*x + [11]*("+iNP+")");
   
   nt->Project(Form("h%d",count),"Bmass",Form("%s&&Bpt>%f&&Bpt<%f",seldata_2y.Data(),ptmin,ptmax));   
   ntMC->Project(Form("hMC%d",count),"Bmass",Form("%s&&Bpt>%f&&Bpt<%f",Form("%s&&Bgen==23333",selmc.Data()),ptmin,ptmax));   
   
   clean0(h);

   //TH1D *hraw = new TH1D(Form("hraw%d",count),"",24,5.03,5.99);
   //clean0(hraw);
   //hraw = (TH1D*)h->Clone(Form("hraw%d",count));

   h->Draw();
   hMC->Draw();
   hMC->SetXTitle("M_{B^{0}_{s}} (GeV/c^{2})");
   hMC->SetYTitle("Entries / (40 MeV/c^{2})");
   hMC->GetXaxis()->CenterTitle();
   hMC->GetYaxis()->CenterTitle(); 
   f->SetParLimits(4,-1000,0);
   f->SetParLimits(2,0.01,0.05);
   f->SetParLimits(8,0.01,0.05);
   f->SetParLimits(7,0,1);
   f->SetParameter(0,setparam0);
   f->SetParameter(1,setparam1);
   f->SetParameter(2,setparam2);
   f->SetParameter(8,setparam3);
   f->FixParameter(1,fixparam1);
   f->SetParLimits(11,0,1000);
   //f->SetParameter(11,10);
   //f->FixParameter(11,0);
   f->FixParameter(9,0);
   h->GetEntries();
   hMC->GetEntries();

   hMC->Fit(Form("f%d",count),"q","",5,6);
   hMC->Fit(Form("f%d",count),"q","",5,6);
   f->ReleaseParameter(1);
   hMC->Fit(Form("f%d",count),"L q","",5,6);
   hMC->Fit(Form("f%d",count),"L q","",5,6);
   hMC->Fit(Form("f%d",count),"L q","",5,6);
   hMC->Fit(Form("f%d",count),"L m","",5,6);

   f->FixParameter(1,f->GetParameter(1));
   f->FixParameter(2,f->GetParameter(2));
   f->FixParameter(7,f->GetParameter(7));
   f->FixParameter(8,f->GetParameter(8));
  //MC icin h lerin tamamini kapa 
   h->Fit(Form("f%d",count),"q","",5,6);
   h->Fit(Form("f%d",count),"q","",5,6);
   f->ReleaseParameter(1);
   h->Fit(Form("f%d",count),"L q","",5,6);
   h->Fit(Form("f%d",count),"L q","",5,6);
   h->Fit(Form("f%d",count),"L q","",5,6);
   h->Fit(Form("f%d",count),"L m","",5,6);
   h->SetMarkerSize(0.8);
   h->SetMarkerStyle(20);

   cout <<"data Num. of Entries :" <<h->GetEntries()<<endl;
   cout <<"MC Num. of Entries : " <<hMC->GetEntries()<<endl;

   // function for background shape plotting. take the fit result from f
   TF1 *background = new TF1(Form("background%d",count),"[0]+[1]*x+[2]*x*x");
   background->SetParameter(0,f->GetParameter(3));
   background->SetParameter(1,f->GetParameter(4));
   background->SetParameter(2,f->GetParameter(5));
   background->SetParameter(3,f->GetParameter(6));
   background->SetLineColor(4);
   background->SetRange(5,6);
   background->SetLineStyle(2);
   
   // function for signal shape plotting. take the fit result from f
  TF1 *Bkpi = new TF1(Form("fBkpi%d",count),"[0]*("+iNP+")");
   Bkpi->SetParameter(0,f->GetParameter(11));
   Bkpi->SetLineColor(kGreen+1);
   Bkpi->SetFillColor(kGreen+1);
   Bkpi->SetRange(5.00,5.28);
   //Bkpi->SetRange(5.00,6.00);
   Bkpi->SetLineStyle(1);
   Bkpi->SetFillStyle(3004);

   // function for signal shape plotting. take the fit result from f
   TF1 *mass = new TF1(Form("fmass%d",count),"[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))");
   mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8));
   mass->SetParError(0,f->GetParError(0));
   mass->SetParError(1,f->GetParError(1));
   mass->SetParError(2,f->GetParError(2));
   mass->SetParError(7,f->GetParError(7));
   mass->SetParError(8,f->GetParError(8));
   mass->SetLineColor(2);
   mass->SetLineStyle(2);
//MC icin bu kismin tamamini kapa
   //cout <<mass->Integral(5.0,6.0)<<" "<<mass->IntegralError(5.0,6.0)<<endl;
   h->SetMarkerStyle(24);
   h->SetStats(0);
   h->Draw("e");
   h->SetXTitle("M_B^{0}_{s} (GeV/c^{2})");
   h->SetYTitle("Entries / (40 MeV/c^{2})");
   h->GetXaxis()->CenterTitle();
   h->GetYaxis()->CenterTitle();
   h->SetTitleOffset(1.,"Y");
   h->SetAxisRange(0,h->GetMaximum()*1.4,"Y");
  
   Bkpi->Draw("same");
   
   background->Draw("same");   
   mass->SetRange(5,6);
   mass->Draw("same");
   mass->SetLineStyle(2);
   mass->SetFillStyle(3004);
   mass->SetFillColor(2);
   f->Draw("same");

   double yield = mass->Integral(5,6)/0.040;
   double yieldErr = mass->Integral(5,6)/0.04*mass->GetParError(0)/mass->GetParameter(0);


   TLegend* leg0 = myLegend(0.1,0.83,0.52,0.90);
   leg0->AddEntry(h,"CMS Internal","");
   leg0->Draw();
   TLegend* leg1 = myLegend(0.11,0.78,0.52,0.82);
   leg1->AddEntry(h,"pp #sqrt{s}= 5.02 TeV","");
   leg1->Draw();
   TLegend* leg2 = myLegend(0.50,0.64,0.87,0.90);
   leg2->AddEntry(h,"|y| < 2.4","");
   leg2->AddEntry(h,Form("%.0f< p_{T}^{B} <%.0f GeV/c",ptmin,ptmax),"");
   leg2->AddEntry(h,"Data","pl");
   leg2->AddEntry(f,"Fit","l");
   leg2->AddEntry(mass,"Signal","f");
   leg2->AddEntry(background,"Comb. Background","l");
   leg2->AddEntry(Bkpi,"Non-prompt J/#psi","f");
   leg2->Draw();
   TLegend *leg3 = myLegend(0.40,0.50,0.89,0.64);
   leg3->AddEntry(h,"B^{0}_{s} meson","");
   leg3->AddEntry(h,Form("M_{B}=%.2f #pm %.2f MeV/c^{2}",mass->GetParameter(1)*1000.,mass->GetParError(1)*1000.),"");
   leg3->AddEntry(h,Form("N_{B}=%.0f #pm %.0f", yield, yieldErr),"");
   leg3->Draw();




  /*// Draw the legend:)   
   TLegend *leg = myLegend(0.50,0.5,0.86,0.92);
   leg->AddEntry(h,"CMS Preliminary","");
   leg->AddEntry(h,"p+p #sqrt{s_{NN}} = 5.02 TeV","");
   leg->AddEntry(h,Form("%.0f < p_{T}^{B} < %.0f GeV/c",ptmin,ptmax),"");
   leg->AddEntry(h,"Data","pl");
   leg->AddEntry(f,"Fit","l");
   leg->AddEntry(mass,"Signal","f");
   leg->AddEntry(background,"Combinatorial Background","l");
//   leg->AddEntry(Bkpi,"Non-prompt J/#psi","f");
   leg->Draw();
   TLegend *leg2 = myLegend(0.44,0.33,0.89,0.50);
   leg2->AddEntry(h,"B meson","");
   leg2->AddEntry(h,Form("M_{B}= %.2f #pm %.2f MeV/c^{2}",mass->GetParameter(1)*1000.,mass->GetParError(1)*1000.),"");
   leg2->AddEntry(h,Form("N_{B}= %.0f #pm %.0f", yield, yieldErr),"");
   leg2->Draw();
*/
  // c->SaveAs(Form("ResultBs/BMass_pp_%d.pdf",count));
   c->SaveAs(Form("ResultBs/BMass_MC_pp_%d.pdf",count));


   return mass;
}

