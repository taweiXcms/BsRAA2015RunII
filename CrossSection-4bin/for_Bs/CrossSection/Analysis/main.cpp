#include <iostream>
#define DEBUG 1
#define DOLXYANALYSIS 0
#define DOCOSANALYSIS 0
#define DOCHI2ANALYSIS 0
#define DOPTANALYSIS   0
#include "functions.h"
#include "TROOT.h"
using namespace std;

int main(int argc, char* argv[])

{
     gROOT->SetBatch();
  gROOT->LoadMacro("AtlasUtils.C");

     SetAtlasStyle();
gROOT->SetStyle("ATLAS");
//gROOT->ForceStyle();
    TApplication mainApp("mainApp", &argc, argv);

    if(DEBUG)  cout << "//************************************//" << endl;
    if(DEBUG)  cout << "  B+ Signal Significance Calculation" << endl;
    if(DEBUG)  cout << "//************************************//" << endl;

    TFile*  f1 = new TFile("../new_data/outf_mc_kplus_clean.root");
    //  TFile*  f2 = new TFile("data_outf.root");      ///DATA
    TFile*  f2 = new TFile("../new_data/outf_data_periodAllYear_clean.root");      ///DATA


    TTree* MCTree = (TTree*)f1->Get("BplusBestChiSlimSkim");
    TTree* DataTree= (TTree*)f2->Get("BplusBestChiSlimSkim");

    Significance  Pt_sign;
    Pt_sign.initial_value =1000;
    Pt_sign.factor=250; /// factor
    Pt_sign.cutrange=10;  /// how many steps

 Deneme(DataTree,MCTree,&Pt_sign);


    Significance  Cos_sign;
    Cos_sign.initial_value =0.05;
    Cos_sign.factor=0.05;
    Cos_sign.cutrange=20;
  //  Deneme(DataTree,MCTree,&Cos_sign);

    Significance  Costhstar_sign;
    Costhstar_sign.initial_value =-1;
    Costhstar_sign.factor=0.05;
    Costhstar_sign.cutrange=30;
 //Deneme(DataTree,MCTree,&Costhstar_sign);

     Significance  lxyc_sign;
    lxyc_sign.initial_value =-0.2;
    lxyc_sign.factor=0.05;
    lxyc_sign.cutrange=17;
    //Deneme(DataTree,MCTree,&lxyc_sign);

    mainApp.Run();

    return 0;
}
