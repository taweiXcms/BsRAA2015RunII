#include "utilities.h"

//double luminosity=34.6*1e-3;//need to be changed for 2015 pp and PbPb datas!
//double luminosity=25.57;// for 2015 pp  datas!
double luminosity=13.14;// for 2015  PbPb datas!
double setparam0=100.;
double setparam1=5.367;
double setparam2=0.02;
double setparam3=0.03;
double fixparam1=5.367;

//lxplus
//TString inputdata="/afs/cern.ch/work/w/wangj/public/nt_20140727_PAMuon_HIRun2013_Merged_y24_Using03090319Bfinder.root";
//TString inputmc="/afs/cern.ch/work/w/wangj/public/nt_20140801_mixed_fromQMBFinder_Phi.root";
//pp//
//TString inputdata="/data/wangj/Data2015/Bntuple/pp/ntB_EvtBase_20160420_BfinderData_pp_20160419_bPt0jpsiPt0tkPt0p5.root";
//TString inputmc="/afs/cern.ch/work/c/cdozen/UP_BFINDER/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Bntuple/test.root";

//PbPb
TString inputdata="/data/wangj/Data2015/Bntuple/PbPb/Bntuple_BfinderData_PbPb_20160406_bPt5jpsiPt0tkPt0p8_BpB0BsX_skimhlt.root";
//TString inputmc="/data/wangj/MC2015/Bntuple/PbPb/ntB_Pythia8_BsToJpsiPhi_TuneCUEP8M1_5020GeV_BPHMod_filter_GEN_SIM_PU_20151105.root";
//TString inputmc="/afs/cern.ch/work/c/cdozen/UP_BFINDER/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Bntuple/test_step3_deneme_PbPb.root";
//TString inputmc="/afs/cern.ch/work/c/cdozen/UP_BFINDER/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Bntuple/test_step3_10M_PbPb.root";
//TString inputmc="/afs/cern.ch/work/c/cdozen/UP_BFINDER/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Bntuple/test_step3_3K_PbPb.root";
TString inputmc="/afs/cern.ch/work/c/cdozen/UP_BFINDER/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Bntuple/PMC_PbPb_21062017.root";

//TString inputmc="/afs/cern.ch/work/c/cdozen/BFINDER/updatedversion/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Bntuple_original/afterloop_test_reco_pp.root";
//TString inputmc="/afs/cern.ch/work/c/cdozen/BFINDER/updatedversion/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Bntuple_original/BsMC_test_pp.root";//
const int nBins = 4; Double_t ptBins[nBins+1] = {5,10.,15.,20.,60};
TString weight = "1"; 

//TString cut="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&Btrk1Pt>0.9&&Bchi2cl>1.32e-02&&(Bd0/Bd0Err)>3.41&&cos(Bdtheta)>-3.46e-01&&Bmu1pt>1.5&&Bmu2pt>1.5&&Blxy>0.025";
//TString cut= "abs(PVz)<15&&TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1highPurity && abs(Btrk1Eta)<2.4 && Btrk1Pt>0.5 && Bchi2cl>0.005 && ((Bpt>5 && Bpt<10 && Btrk1Pt>0.75 && Bchi2cl>0.032 && (BsvpvDistance/BsvpvDisErr)>0 && cos(Bdtheta)>0.99 && abs(Btrk1Eta)<2.4)|| (Bpt>10 && Bpt<20&& Btrk1Pt>0.88 && Bchi2cl>0.005 && (BsvpvDistance/BsvpvDisErr)>0 && cos(Bdtheta)>0.97 && abs(Btrk1Eta)<2.39) || (Bpt>20 && Bpt<30 && Btrk1Pt>0.84 && Bchi2cl>0.014 && (BsvpvDistance/BsvpvDisErr)>0 && cos(Bdtheta)>0.60 && abs(Btrk1Eta)<2.38) || (Bpt>30 && Bpt<80 && Btrk1Pt>1.06 && Bchi2cl>0.015 && (BsvpvDistance/BsvpvDisErr)>0 && cos(Bdtheta)>0.99 && abs(Btrk1Eta)<2.37))" ;
//pp//Bs0//loose cuts
//TString cut="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&Btrk1Pt>0.7&&Bchi2cl>1.32e-02&&(Bd0/Bd0Err)>3.41&&cos(Bdtheta)>-3.46e-01&&Bmu1pt>1.5&&Bmu2pt>1.2";
////////24/05/2017//
//TString cut="TMath::Abs(By)<2.4&&abs(Bmumumass-3.096916)<0.15&&Bmass>5.&&Bmass<6.&&Btrk1Pt>1.0&&Btrk2Pt>1.0&&Bchi2cl>3.71e-02&&(Bd0/Bd0Err)>2.&&cos(Bdtheta)>2.60e-01&&abs(Btktkmass-1.019455)<1.55e-02&&Bmu1pt>1.5&&Bmu2pt>1.5";
////Hyunchul updated cuts
TString cut = "TMath::Abs(By)<2.4&&abs(Bmumumass-3.09691 6)<0.15&&Bmass>5.&&Bmass<6.&&Btrk1Pt>1.5&&Btrk2Pt>1.5&& Bchi2cl>0.1&&(Bd0/Bd0Err)>5.&&cos(Bdtheta)>0.8&&Bmu1pt>1.5&&Bmu2pt>1.5&&TMath::Abs(Btktkmass-1.019455)<0.05&&Blxy>0.1 ";

//TString cut="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8))&& ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1highPurity&&Bmass>5&&Bmass<6&&Btrk1Pt>0.7&&Btrk2Pt>0.7&&Bchi2cl>1.32e-02&&(Bd0/Bd0Err)>2.&&cos(Bdtheta)>2.60e-01&&Bmu1pt>1.5&&Bmu2pt>1.5&&Blxy>0.025&&abs(Btktkmass-1.019455)<1.55e-02";
//PbPb Cuts:
//TString cut="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1highPurity && Btrk1Pt>0.8 && Bchi2cl>0.005";  
TString selmc = Form("%s",cut.Data());
//TString selmcgen = "TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal==6";
TString selmcgen = "TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0";
TString seldata_2y=Form("%s",cut.Data());

//pp//
//TString selmcgenacceptance="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal==6&& ((TMath::Abs(Gmu1eta)<1.2 && Gmu1pt>3.5) || (TMath::Abs(Gmu1eta)>1.2 && TMath::Abs(Gmu1eta)<2.1 && Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta))) || (TMath::Abs(Gmu1eta)>2.1 && TMath::Abs(Gmu1eta)<2.4 && Gmu1pt>1.8)) && ((TMath::Abs(Gmu2eta)<1.2 && Gmu2pt>3.5) || (TMath::Abs(Gmu2eta)>1.2 && TMath::Abs(Gmu2eta)<2.1 && Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta))) || (TMath::Abs(Gmu2eta)>2.1 && TMath::Abs(Gmu2eta)<2.4 && Gmu2pt>1.8)) && Gtk1pt>0.5 && TMath::Abs(Gtk1eta)<2.4";
TString selmcgenacceptance= "TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0";//&&((TMath::Abs(Gmu1eta)<1.2 && Gmu1pt>3.5) || (TMath::Abs(Gmu1eta)>1.2 && TMath::Abs(Gmu1eta)<2.1 && Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta))) || (TMath::Abs(Gmu1eta)>2.1 && TMath::Abs(Gmu1eta)<2.4 && Gmu1pt>1.8)) && ((TMath::Abs(Gmu2eta)<1.2 && Gmu2pt>3.5) || (TMath::Abs(Gmu2eta)>1.2 && TMath::Abs(Gmu2eta)<2.1 && Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta))) || (TMath::Abs(Gmu2eta)>2.1 && TMath::Abs(Gmu2eta)<2.4 && Gmu2pt>1.8)) && Gtk1pt>0.5 && TMath::Abs(Gtk1eta)<2.4 ";

//TString weight = "27.493+Bpt*(-0.218769)";

void fitBsMC(TString infname="",Bool_t doweight = false)
{
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
 //  TH1D *hPtGenAll = new TH1D("hPtGenAll","",nBins,ptBins);
   

    for (int i=0;i<nBins;i++)
   {
      TF1 *f = fit(nt,ntMC,ptBins[i],ptBins[i+1]);
      double yield = f->Integral(5,6)/0.04;
      double yieldErr = f->Integral(5,6)/0.04*f->GetParError(0)/f->GetParameter(0);
      hPt->SetBinContent(i+1,yield/(ptBins[i+1]-ptBins[i]));
      hPt->SetBinError(i+1,yieldErr/(ptBins[i+1]-ptBins[i]));
   }
    

   TCanvas *c=  new TCanvas("cResult","",600,600);
   c->SetLogy();
   hPt->SetXTitle("B_{s} p_{T} (GeV/c)");
   hPt->SetYTitle("Uncorrected B_{s} dN/dp_{T}");
   hPt->Sumw2();
   hPt->Draw();
   //hRecoTruth->Draw("same hist");
   c->SaveAs(Form("ResultBs_MC/hPtResultMC_PbPb_21062017.pdf"));

   ntMC->Project("hPtMC","Bpt",TCut(weight)*(selmc.Data())&&"(Bgen==23333)");
   ntMC->Project("hRecoTruth","Bpt",TCut(seldata_2y.Data())&&"(Bgen==23333)");
   ntGen->Project("hPtGen","Gpt",TCut(weight)*(selmcgen.Data()));
   //ntGen->Project("hPtGenAll","Gpt",TCut(weight)*(selmc.Data()));
   ntGen->Project("hPtGenAcc","Gpt",TCut(weight)*(TCut(selmcgenacceptance.Data())));
   divideBinWidth(hRecoTruth);
   divideBinWidth(hPtMC);
   divideBinWidth(hPtGen);
   divideBinWidth(hPtGenAcc);
   //divideBinWidth(hPtGenAll);
   //Eff*Acc
   hPtMC->Sumw2();
   TH1D *hEffAcc = (TH1D*)hPtMC->Clone("hEffAcc");
   hEffAcc->Sumw2();
   hEffAcc->Divide(hPtGen);
   //Eff
   TH1D* hEff = (TH1D*)hRecoTruth->Clone("hEff"); 
   hEff->Sumw2();
   hEff->Divide(hPtGenAcc);
   //Acc
   //TH1D* hEffAcc = (TH1D*)hPtGenAll->Clone("hEffAcc");
   //hEffAcc->Sumw2();
   //hEffAcc->Divide(hEffAcc,hPtGen,1,1,"b");
   
   TH1D* hAcc = (TH1D*)hPtGenAcc->Clone("hAcc");
   hAcc->Sumw2();
   hAcc->Divide(hAcc,hPtGen,1,1,"b");

  // TH1D* hEffSelection = (TH1D*)hPtMC->Clone("hEffSelection");
  //  hEffSelection->Sumw2();
  //  hEffSelection->Divide(hEffSelection,hRecoTruth,1,1,"b");

  TH1D *hPtCor = (TH1D*)hPt->Clone("hPtCor");
  hPtCor->Divide(hEffAcc);
  TCanvas *cCor=  new TCanvas("cCorResult","",600,600);
  cCor->SetLogy();
  hPtCor->SetYTitle("Correctd B_{s} dN/dp_{T}");
  hPtCor->Draw();
  //hPtGen->Draw("same");
  cCor->SaveAs(Form("ResultBs_MC/PtCorMC_PbPb_21062017.pdf"));

  TH1D *hPtSigma= (TH1D*)hPtCor->Clone("hPtSigma");
  //double BRchain=2.89977e-5;
  double BRchain=3.1189e-5;
  hPtSigma->Scale(1./(2*luminosity*BRchain));
  hPtSigma->SetYTitle("d#sigma/dp_{T} (B_{s})");
  TCanvas *cSigma=  new TCanvas("cSigma","",600,600);
  cSigma->SetLogy();
  hPtSigma->Draw();
  cSigma->SaveAs(Form("ResultBs_MC/PtSigmaMC_PbPb_21062017.pdf"));

   TCanvas*canvas=new TCanvas("canvas","canvas",1000.,400);
    canvas->Divide(3,1);
    canvas->cd(1);
    gPad->SetLogy();
    hPtGen->Draw();
    canvas->cd(2);
    gPad->SetLogy();
    hPtMC->Draw();
    canvas->cd(3);
    hEffAcc->Draw();
    
  //TFile *outf = new TFile("ResultBs/fitBsMC_PbPb.root","recreate");
  TFile *outf = new TFile("ResultBs_MC/fitBs_PbPb_MC_21062017.root","recreate");
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
   TF1 *f = new TF1(Form("f%d",count),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+ [3]+[4]*x+[5]*x*x + [11]*("+iNP+")");
   
   nt->Project(Form("h%d",count),"Bmass",Form("%s&&Bpt>%f&&Bpt<%f",seldata_2y.Data(),ptmin,ptmax));   
   ntMC->Project(Form("hMC%d",count),"Bmass",Form("%s&&Bpt>%f&&Bpt<%f",Form("%s&&Bgen==23333",selmc.Data()),ptmin,ptmax)); 
   clean0(h);

   //TH1D *hraw = new TH1D(Form("hraw%d",count),"",24,5.03,5.99);
   //clean0(hraw);
   //hraw = (TH1D*)h->Clone(Form("hraw%d",count));

   hMC->Draw();
/*   f->SetParLimits(4,-1000,0);
// f->SetParLimits(4,0.01,0.05);
   f->SetParLimits(2,0.01,0.05);
   f->SetParLimits(8,0.01,0.05);
   f->SetParLimits(7,0,1);
   f->SetParameter(0,setparam0);
   f->SetParameter(1,setparam1);
   f->SetParameter(2,setparam2);
   f->SetParameter(8,setparam3);
   f->FixParameter(1,fixparam1);
   f->SetParLimits(11,0,1000);
   f->SetParameter(11,10);
   f->FixParameter(11,0);
   f->FixParameter(9,0);
  */ hMC->GetEntries();

   /*hMC->Fit(Form("f%d",count),"q","",5,6);
   hMC->Fit(Form("f%d",count),"q","",5,6);
   //f->ReleaseParameter(1);
   hMC->Fit(Form("f%d",count),"L q","",5,6);
   hMC->Fit(Form("f%d",count),"L q","",5,6);
   hMC->Fit(Form("f%d",count),"L q","",5,6);
   hMC->Fit(Form("f%d",count),"L m","",5,6);

   f->FixParameter(1,f->GetParameter(1));
   f->FixParameter(2,f->GetParameter(2));
   f->FixParameter(7,f->GetParameter(7));
   f->FixParameter(8,f->GetParameter(8));
  */ cout <<"MC Num. of Entries : " <<hMC->GetEntries()<<endl;

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
   TF1 *mass = new TF1(Form("fmass%d",count),"[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))");
   mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8));
   mass->SetParError(0,f->GetParError(0));
   mass->SetParError(1,f->GetParError(1));
   mass->SetParError(2,f->GetParError(2));
   mass->SetParError(7,f->GetParError(7));
   mass->SetParError(8,f->GetParError(8));
   mass->SetLineColor(2);
   mass->SetLineStyle(2);

  //cout <<mass->Integral(0,1.2)<<" "<<mass->IntegralError(0,1.2)<<endl;
   
   /*hMC->SetMarkerStyle(24);
   hMC->SetStats(0);
   hMC->Draw("e");
   hMC->SetXTitle("M_{B} (GeV/c^{2})");
   hMC->SetYTitle("Entries / (40 MeV/c^{2})");
   hMC->GetXaxis()->CenterTitle();
   hMC->GetYaxis()->CenterTitle();
 *///  hMC->SetTitleOffset(1.,"Y");
   //hMC->SetAxisRange(0,h->GetMaximum()*1.4,"Y");
 
   //background->Draw("same");   
   mass->SetRange(5,6);
   //mass->Draw("same");
   mass->SetLineStyle(2);
   mass->SetFillStyle(3004);
   mass->SetFillColor(2);
   //f->Draw("same");

   double yield = mass->Integral(5,6)/0.040;
   double yieldErr = mass->Integral(5,6)/0.04*mass->GetParError(0)/mass->GetParameter(0);


   // Draw the legend:)   
   TLegend *leg = myLegend(0.50,0.5,0.80,0.92);
   leg->AddEntry(h,"CMS Preliminary","");
   leg->AddEntry(h,"p+p #sqrt{s_{NN}} = 5.02 TeV","");
   leg->AddEntry(h,Form("%.0f < p_{T}^{B} < %.0f GeV/c",ptmin,ptmax),"");
   leg->AddEntry(h,"Data","pl");
   //leg->AddEntry(f,"Fit","l");
   //leg->AddEntry(mass,"Signal","f");
   //leg->AddEntry(background,"Combinatorial Background","l");
   leg->Draw();
   TLegend *leg2 = myLegend(0.44,0.33,0.89,0.50);
   leg2->AddEntry(h,"B meson","");
   leg2->AddEntry(h,Form("M_{B}= %.2f #pm %.2f MeV/c^{2}",mass->GetParameter(1)*1000.,mass->GetParError(1)*1000.),"");
   leg2->AddEntry(h,Form("N_{B}= %.0f #pm %.0f", yield, yieldErr),"");
  // leg2->Draw();

   c->SaveAs(Form("ResultBs_MC/BMassMC_PbPb_21062017_%d.pdf",count));


   return mass;
}


