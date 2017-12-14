//--------------------
// c++ headers
//--------------------
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <iomanip>  // needed to use manipulators with parameters (precision, width)
//--------------------
//Specific headers
//--------------------
#include "TLine.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLorentzVector.h"
#include <vector>
#include "TApplication.h"
#include "TChain.h"
#include "TFile.h"
#include "TF1.h"
#include "TFitResult.h"
#include <vector>
#include "TGraph.h"
#include "TCut.h"
#include "TStyle.h"
#include "parameters.h"
#include "Significance.h"


///Atlas Style

#include "Rtypes.h"

#include "style/AtlasUtils.C"
#include "style/AtlasStyle.C"
#include "style/AtlasLabels.C"
///end atlas style
using namespace std;
double GetSignificance(double signal,double bgr)
{
    double sgnfc =  signal/sqrt(signal+bgr);
    return sgnfc;


}

void DrawgeneralPlot(int Nfirststep,vector <float> cut1_purity,vector <float> cut1,TString mystring, TString yaxis,TString type, float rapiditymin=0., float rapiditymax=0.)
{


    TString name1=type+"_"+mystring+"_"+yaxis;
//TString name2="|cos(#theta^{' }K)|  vs Purity";

    TString Canvname=mystring+Form("_%.2f_%.2f_",rapiditymin,rapiditymax)+"_"+yaxis;

    TString pngout;
    TString Macroout;
    pngout=Canvname+".png";
    Macroout=Canvname+".C";
    TGraph *lxygraph=new TGraph(Nfirststep,&(cut1[0]),&(cut1_purity[0]));
    cout<<"array size :"<<Nfirststep<<endl;
    lxygraph->SetTitle(name1);

    lxygraph->SetMarkerStyle(20);
    lxygraph->SetMarkerColor(kRed);
    lxygraph->GetXaxis()->SetLabelFont(42);
    lxygraph->GetXaxis()->SetLabelSize(0.035);
    lxygraph->GetXaxis()->SetTitleSize(0.035);
    lxygraph->GetXaxis()->SetTitleFont(42);
    lxygraph->GetXaxis()->SetTitle(mystring);
    lxygraph->GetYaxis()->SetLabelFont(42);
    lxygraph->GetYaxis()->SetLabelSize(0.035);
    lxygraph->GetYaxis()->SetTitleSize(0.015);
    lxygraph->GetYaxis()->SetTitleOffset(2.5);
    lxygraph->GetYaxis()->SetTitleFont(42);
    lxygraph->GetYaxis()->SetTitle(yaxis);

    TString graphname="TGraph" +mystring+"_"+yaxis;
    TCanvas *Canv3=new TCanvas(Canvname,Canvname,800,600);
    Canv3->Divide(1,1);
    Canv3->cd(1);

    lxygraph->Draw();

    ATLASLabel(0.2,0.9,"Preliminary");
    myText(       0.70,  0.85, 1, "#sqrt{s}= 13 TeV");
    myText(       0.70, 0.75, 1, Form("%.2f<|#eta_{B^{+}}|<%.2f",rapiditymin,rapiditymax));
    myText(       0.70, 0.65, 1, "#chi^{2} /Ndof< 4");
    myText(       0.70, 0.55, 1, "9000<Pt(B^{+})<15000 MeV");
   // myMarkerText( 0.55, 0.65, 1, kRed, "Data 2015",1.3);
    //ATLASLabel(0.2,0.2,"Work in progress");
    Canv3->Update();
    Canv3->SaveAs(pngout);
    Canv3->SaveAs(Macroout);
    Canv3->Clear();
    cout<<"canvas are produced and cleared ...."<<endl;
}

void DrawCosPlot(int Nfirststep,vector <float> cut1_purity,vector <float> cut1,TString mystring, TString yaxis,TString type)
{


    TString name1=type+"_"+mystring+"_"+yaxis;
//TString name2="|cos(#theta^{' }K)|  vs Purity";

    TString Canvname=mystring+"_"+yaxis;

    TString pngout;
    TString Macroout;
    pngout=Canvname+".png";
    Macroout=Canvname+".C";
    TGraph *lxygraph=new TGraph(Nfirststep,&(cut1[0]),&(cut1_purity[0]));
    cout<<"array size :"<<Nfirststep<<endl;
    lxygraph->SetTitle(name1);

    lxygraph->SetMarkerStyle(20);
    lxygraph->SetMarkerColor(kRed);
    lxygraph->GetXaxis()->SetLabelFont(42);
    lxygraph->GetXaxis()->SetLabelSize(0.035);
    lxygraph->GetXaxis()->SetTitleSize(0.035);
    lxygraph->GetXaxis()->SetTitleFont(42);
    lxygraph->GetXaxis()->SetTitle(mystring);
    lxygraph->GetYaxis()->SetLabelFont(42);
    lxygraph->GetYaxis()->SetLabelSize(0.035);
    lxygraph->GetYaxis()->SetTitleSize(0.015);
    lxygraph->GetYaxis()->SetTitleOffset(2.5);
    lxygraph->GetYaxis()->SetTitleFont(42);
    lxygraph->GetYaxis()->SetTitle(yaxis);

    TString graphname="TGraph" +mystring+"_"+yaxis;
    TCanvas *Canv3=new TCanvas(Canvname,Canvname,800,600);
    Canv3->Divide(1,1);
    Canv3->cd(1);

    lxygraph->Draw();

    ATLASLabel(0.2,0.9,"Preliminary");
    myText(       0.60, 0.75, 1, "#sqrt{s}= 13 TeV");
    myText(       0.60, 0.65, 1, "#chi^{2} /Ndof< 4");
    myText(       0.60, 0.55, 1, "9000<Pt(K^{+})<13000 MeV");
   // myMarkerText( 0.55, 0.65, 1, kRed, "Data 2015",1.3);
    //ATLASLabel(0.2,0.2,"Work in progress");
    Canv3->Update();
    Canv3->SaveAs(pngout);
    Canv3->SaveAs(Macroout);
    Canv3->Clear();
    cout<<"canvas are produced and cleared ...."<<endl;
}
//Significance  Ptsign;
void Deneme(TTree* DataTree, TTree* MCTree, Significance*  Ptsign)
{

    cout<<"Signalcut : "<<Ptsign->signalcut<<endl;
    cout<<"Sideband cut : "<<Ptsign->sidebandcut<<endl;
    /// define your histograms
    /// Default histograms for uncut values :
    TH1F *hist_BPlus_sig                  = new TH1F("hist_BPlus_sig"              , "B^{+} Mass MC"               , 100, HistRange_min, HistRange_max);
    TH1F *hist_BPlus_all                  = new TH1F("hist_BPlus_all"              , "B^{+} Mass all"              , 100, HistRange_min, HistRange_max);
    TH1F *hist_BPlus_data                 = new TH1F("hist_BPlus_data"             , "B^{+} Mass data signal"      , 100, HistRange_min, HistRange_max);
    TH1F *hist_BPlus_data_sideband        = new TH1F("hist_BPlus_data_sideband"    , "B^{+} Mass data sideband"    , 100, HistRange_min, HistRange_max);
/// Fill your histograms in the signal region and sideband
    DataTree->Draw("B_mass >> hist_BPlus_data"         ,Ptsign->signalcut   ,"goff"); /// Signal region in DATA
    MCTree->Draw  ("B_mass >> hist_BPlus_sig"          ,Ptsign->signalcut   ,"goff"); /// Signal region in MC
    DataTree->Draw("B_mass >> hist_BPlus_all"          ,""                  ,"goff"); /// All in DATA
    DataTree->Draw("B_mass >> hist_BPlus_data_sideband", Ptsign->sidebandcut,"goff"); /// Sideband of DATA

    /// get signal and sideband
    double NData        = hist_BPlus_data->Integral();
    double NMC          = hist_BPlus_sig->Integral() ;
    double NAll         = hist_BPlus_all->Integral() ;
    double Nsideband    = hist_BPlus_data_sideband->Integral();
    double Nbgr         = (hist_BPlus_all->Integral()  - hist_BPlus_sig->Integral());
    /// scale sideband
    cout<<"Nsideband : " <<hist_BPlus_data_sideband->Integral()<<" Nbgr : "<< Nbgr<<endl;
    // double Scale_sb1             = (Nbgr/Nsideband); ///Scale sideband wrt bckground
    ///Now sideband substraction technique ;
    double ScaleFactor_sideband   = (double)(SignalRange_max-SignalRange_min)/ ((SidebandRange_min-HistRange_min)+(HistRange_max-SidebandRange_max))    ;//160.0/560.0 ;//Nbgr /Nsideband;/// scale factor for sideband
    cout<<"scale sideband: "<<ScaleFactor_sideband<<endl;

    hist_BPlus_data_sideband->Scale(ScaleFactor_sideband);
    Nsideband   = hist_BPlus_data_sideband->Integral();//*ScaleFactor_sideband;
    Nbgr =Nsideband;
    double True_signal= NData-Nsideband;
    double signal_without_cut=True_signal;
    double bg_without_cut = Nbgr;
    double ScaleFactor     =True_signal/NMC; ///scale the signal from data to MC
    cout<<"True signal : "<<True_signal<< " MC : "<<NMC<<endl;
    hist_BPlus_sig->Scale(ScaleFactor); ///Scale MC wrt data for signal range..
    if(DEBUG) cout<< "our Scale Factor signal is : "<< ScaleFactor<<endl;
    if(DEBUG)
    {
        cout<<"///** Before Scale**----------------------------------------//"<<endl;
        cout<<"NData_signal : "<< setw(11)<<NData    /*<<" +- "<< setw(11)<<GetIntegralError(hist_BPlus_data)*/<<endl;
        cout<<"NMC_signal   : "<< setw(11)<<NMC      /*<<" +- "<< setw(11)<<GetIntegralError(hist_BPlus_sig)*/<<endl;
        cout<<"NAll (s+b)   : "<< setw(11)<<NAll     /*<<" +- "<< setw(11)<<GetIntegralError(hist_BPlus_all)*/<<endl;
        cout<<"Nsideband    : "<< setw(11)<<Nsideband/*<<" +- "<< setw(11)<<GetIntegralError(hist_BPlus_data_sideband)*/<<endl;
        cout<<"Nbgr         : "<< setw(11)<<Nbgr     /*<<" +- "<< setw(11)
            <<sqrt(GetIntegralError(hist_BPlus_all)*GetIntegralError(hist_BPlus_all)+GetIntegralError(hist_BPlus_data)*GetIntegralError(hist_BPlus_data))*/ <<endl;
        cout<<"N_sig/Sqrt(Nsig+N_bg) = "<< setw(11)<<GetSignificance(True_signal,Nbgr)<<endl;
//
    }

    /// Now cut loops

///Eta Range : 0.0 ,0.50,1.0,1.50,2.25   abs value of B_rapidity


    for(int j=0; j<4; j++) ///Eta _loop _
    {
        float rapiditymin[]= {0.0 ,0.50,1.0,1.50,2.25 };

        TCut rapidity_cut=Form("abs(B_rapidity) > %.2f && abs(B_rapidity) < %.2f ",rapiditymin[j],rapiditymin[j+1]);

        ///First cut range
        for(int i=0; i<Ptsign->cutrange; i++)
        {
            //float   mycutval[]={}
            double  carpan=Ptsign->factor;
            double  myfactor=Ptsign->initial_value+i*carpan;
            /// now change the lxy and cos cuts :
            ///chi^2/NDF < 4 && pT(K) > 1500.
            /**
                        Could you please check efficiencies of
                        L_xy and angle cuts after above selection?
            */
              TCut Lxy_cut=Form("B_Lxy_MinA0 > %f",myfactor);
          //  TCut cos_cut=Form("abs(cos_ThetaPrimeK)< %.2f", myfactor);
       //     TCut cos_cut=Form("cos_ThetaStarK > %.2f", myfactor);
            TCut pt_cut=Form("B_trk_pT > %.2f",myfactor);
         //   TCut pt_cut="B_trk_pT > 1500"; ///fix the pt cut
            (Ptsign->VCut).push_back(myfactor);
            TCut firstPtbin ="B_pT >9000 && B_pT<13000";
            TCut fixedchi2 ="B_chi2_ndof < 4.0 " ;
            //TCut firstPtbin ="B_pT >13000";
            /// Total cut PtBin(B+)+fixedChi2+signalCut+mycut;

            TCut totalcut_sideband = firstPtbin+ fixedchi2 + Ptsign->signalcut+pt_cut+rapidity_cut;
            TCut totalcut_signal   = firstPtbin + fixedchi2 + Ptsign->signalcut + pt_cut+rapidity_cut ;


            /*
            TCut totalcut_sideband =  fixedchi2 + Ptsign->signalcut+pt_cut+cos_cut;
            TCut totalcut_signal   =  fixedchi2 + Ptsign->signalcut + pt_cut+cos_cut ;

            */
            /*
            TCut totalcut_sideband =  fixedchi2 + Ptsign->signalcut+pt_cut+Lxy_cut;
            TCut totalcut_signal   =  fixedchi2 + Ptsign->signalcut + pt_cut+Lxy_cut ;
             */

            cout<< totalcut_sideband<<endl;
            cout<< totalcut_signal<<endl;

            ///now cuts :

            TH1F* hist_BPlus_cut_sig              = new TH1F("hist_BPlus_cut_sig"          , "B^{+} Mass MC_cut"           , 100, HistRange_min, HistRange_max);
            TH1F *hist_BPlus_cut_all              = new TH1F("hist_BPlus_cut_all"          , "B^{+} Mass all_cut"          , 100, HistRange_min, HistRange_max);
            TH1F *hist_BPlus_cut_data             = new TH1F("hist_BPlus_cut_data"         , "B^{+} Mass data signal_cut"  , 100, HistRange_min, HistRange_max);
            TH1F *hist_BPlus_data_cut_sideband    = new TH1F("hist_BPlus_data_cut_sideband", "B^{+} Mass data sideband_cut", 100, HistRange_min, HistRange_max);
            cout<<"Doing Cut"<<endl;

            /// cut
            DataTree->Draw("B_mass >> hist_BPlus_cut_data"         , totalcut_signal  ,"goff");  /// Signal region in DATA
            MCTree->Draw  ("B_mass >> hist_BPlus_cut_sig"          , totalcut_signal  ,"goff"); /// Signal region in MC
            DataTree->Draw("B_mass >> hist_BPlus_cut_all"          ,""                ,"goff");  /// All in DATA
            DataTree->Draw("B_mass >> hist_BPlus_data_cut_sideband", totalcut_sideband,"goff");  /// Sideband of DATA



            hist_BPlus_data_cut_sideband->Scale(ScaleFactor_sideband);
            hist_BPlus_cut_sig->Scale(ScaleFactor); ///Scale MC wrt data for signal range..

            NData       = hist_BPlus_cut_data->Integral();
            NMC         = hist_BPlus_cut_sig->Integral() ;
            NAll        = hist_BPlus_cut_all->Integral() ;
            Nsideband   = hist_BPlus_data_cut_sideband->Integral();
            True_signal = NMC;//NData-Nsideband;
            Nbgr        = Nsideband;//NData- True_signal;
            if(DEBUG)
            {
                cout<<"///** After cut**----------------------------------------//"<<endl;
                cout<<"NData_signal : "<< setw(11)<<NData   /* <<" +- "<< setw(11)<<GetIntegralError(hist_BPlus_data)*/<<endl;
                cout<<"NMC_signal   : "<< setw(11)<<NMC     /* <<" +- "<< setw(11)<<GetIntegralError(hist_BPlus_sig)*/<<endl;
                cout<<"NAll (s+b)   : "<< setw(11)<<NAll     /*<<" +- "<< setw(11)<<GetIntegralError(hist_BPlus_all)*/<<endl;
                cout<<"Nsideband    : "<< setw(11)<<Nsideband/*<<" +- "<< setw(11)<<GetIntegralError(hist_BPlus_data_sideband)*/<<endl;
                cout<<"Nbgr         : "<< setw(11)<<Nbgr     /*<<" +- "*/<<endl;
                cout<<"N_sig/Sqrt(Nsig+N_bg) = "<< setw(11)<<GetSignificance(True_signal,Nbgr)<<endl;
//
            }

            ///fill the result :
            float   result= GetSignificance(True_signal,Nbgr);
            (Ptsign->VSignificance).push_back(result);
            float   efficiency= True_signal/signal_without_cut;
            (Ptsign->VEfficiency).push_back(efficiency);
            float   purity= True_signal/(True_signal+Nbgr);
            (Ptsign->VPurity).push_back(purity);
            float ef_pur=efficiency*purity;
            cout<<Ptsign->VPurity.size()<<endl;
            //    result =ef_pur;
            cout<<"Significance: "<<result<<endl;
            cout<<"efficiency : "<<efficiency<<endl;
            cout<<"purity : "<<purity<<endl;
            cout<<"Eff * purity = "<<efficiency*purity<<endl;

            ///Now we are done delete the histogram objects

            hist_BPlus_cut_sig->Delete()              ;
            hist_BPlus_cut_all->Delete()              ;
            hist_BPlus_cut_data->Delete()             ;
            hist_BPlus_data_cut_sideband->Delete()    ;
            cout<<"end of inner loop .."<<endl;
        }

        DrawgeneralPlot((Ptsign->VSignificance).size(),(Ptsign->VSignificance),(Ptsign->VCut),"pt","Significance","PtCut",rapiditymin[j],rapiditymin[j+1]);
       // DrawCosPlot((Ptsign->VSignificance).size(),(Ptsign->VSignificance),(Ptsign->VCut),"abs(Costheta_prime)","Significance","CosCut");
       // DrawCosPlot((Ptsign->VSignificance).size(),(Ptsign->VSignificance),(Ptsign->VCut),"Costheta_star","Significance","CosCut");
   //     DrawCosPlot((Ptsign->VSignificance).size(),(Ptsign->VSignificance),(Ptsign->VCut),"Lxy","Significance","LxyCut");
        Ptsign->ClearVectors();
    }///Main Rapidity Loop
    hist_BPlus_sig->Delete()                  ;
    hist_BPlus_all->Delete()                  ;
    hist_BPlus_data->Delete()                 ;
    hist_BPlus_data_sideband->Delete()        ;
}


/**



    for (int i=0; i<Nfirststep ; i++ ) /// cosThetaStarK ///from -1 to 0.5 step 0.05
    {
        double myfactor=(-1.0+(0.05*i));
        if(DEBUG)  cout<<"first cut : "<<myfactor<<endl;
        cut1[i]=myfactor;
        SignalSignificance_withcuts(f1,f2,signalcut,sidebandcut,0,lxy_cut,myfactor,cut1_significance[i],cut1_eff[i],cut1_purity[i]);


    };
    ///calculate second cut results
    for (int i=0; i<Nsecondstep ; i++ ) ///CosThetaPrimeK ///from 1 to 0.3 abs with 0.05
    {
        double myfactor =(1.0-(i*0.05));
        if(DEBUG) cout<<"cut2 : "<<myfactor<<endl;
        cut2[i]=myfactor;
        SignalSignificance_withcuts(f1,f2,signalcut,sidebandcut,1,lxy_cut,myfactor,cut2_significance[i],cut2_eff[i],cut2_purity[i]);

    };


///İNSİDE :

    if(firstcut)
    {

        cos_cut=Form("abs(cos_ThetaPrimeK)< %f", mycut);
        if(lxy_cut){
            cos_cut=cos_cut+Lxycut;
        }
    }
    else
    {

        cos_cut=Form("cos_ThetaStarK > %f", mycut);
                if(lxy_cut){
            cos_cut=cos_cut+Lxycut;
        }
    }
    TCut totalcut_sideband = cos_cut + c_sideband;
    TCut totalcut_signal   = cos_cut + c_signalband ;
    cout<< totalcut_sideband<<endl;
    cout<< totalcut_signal<<endl;




*/



/**

    if(DOLXYANALYSIS)
    {


        double myfactor =-0.2;
        for (int i=0; i<NLxy ; i++ )
        {
            double carpan;
            if(i==0) carpan=0.;
            if(i<=6 && i>0)
            {
                carpan=0.05;
            }
            if(i<17 && i>6)  carpan=0.01;
            if(i>=17)  carpan=0.05;



            myfactor=myfactor+carpan;
            if(DEBUG) cout<<"cutlxy : "<<myfactor<<endl;
            cut1_lxy[i]=myfactor;
            SignalSignificance_withlxycuts(f1,f2,signalcut,sidebandcut,myfactor,cut1_lxy_significance[i],cut1_lxy_eff[i],cut1_lxy_purity[i]);
        };


*/
