#include "TFile.h"
#include "ProdMVAVal.cc"
void individual(){
	TString fname;
	TString inf;
	TString ouf;
	string coll;

// PbPb samples
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight";
fname = "Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged";
inf = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/"+fname+".root";

//coll = "pp";
coll = "PbPb";
ptmin = 15; ptmax = 50;
ouf = fname+Form("_%s_BDT%.0fto%.0f_20180223MVA.root",coll.c_str(),ptmin,ptmax);
makeoutput(inf,ouf,coll,"BDT",1);
}
