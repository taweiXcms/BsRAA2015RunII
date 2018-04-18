#include "TFile.h"
#include "ProdMVAVal.cc"
void individual(){
TString fname;
TString inf;
TString ouf;
string coll;

//pp non-prompt / prompt MC
//fname = "Bntuple20180316_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs";
//inf = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/"+fname+".root";

//pp signal with PbPb BDT
//fname = "Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight";
//fname = "Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs";
//inf = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/"+fname+".root";

//PbPb non-prompt / prompt MC
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM_ptJpsi_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//inf = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/"+fname+".root";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM_ptJpsi_00_03_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM_ptJpsi_03_06_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM_ptJpsi_03_06_ext_Hydjet_MB_20180314_bPt0tkPt0MuAll_B";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM_ptJpsi_06_09_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM_ptJpsi_06_09_ext_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM_ptJpsi_09_12_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM_ptJpsi_12_15_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM_ptJpsi_15_30_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM_ptJpsi_30_inf_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//inf = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BJpsiMM/"+fname+".root";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_00_03_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_03_06_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_03_06_ext_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_06_09_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_06_09_ext_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_09_12_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_12_15_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_15_30_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_30_Inf_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs";
//inf = "/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM/"+fname+".root";

//coll = "pp";
//coll = "PbPb";
ptmin = 7; ptmax = 15;
ouf = fname+Form("_%s_BDT%.0fto%.0f.root",coll.c_str(),ptmin,ptmax);
makeoutput(inf,ouf,coll,"BDT",1);
ptmin = 15; ptmax = 50;
ouf = fname+Form("_%s_BDT%.0fto%.0f.root",coll.c_str(),ptmin,ptmax);
makeoutput(inf,ouf,coll,"BDT",1);
}
