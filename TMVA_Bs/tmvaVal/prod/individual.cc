#include "TFile.h"
#include "ProdMVAVal.cc"
void individual(){
	ptmin = 15;
    ptmax = 50;
	TString fname;
	TString inf;
	TString ouf;
	string coll;

//pp signal MC
//fname = "Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pthat0_Bpt5p0_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs";
//fname = "Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pthat5_Bpt5p0_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs";
//fname = "Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pthat10_Bpt5p0_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs";
//fname = "Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pthat15_Bpt5p0_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs";
//fname = "Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pthat30_Bpt5p0_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs";
//fname = "Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pthat50_Bpt5p0_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs";
//inf = "../../../../samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_PthatX/"+fname+".root";
//pp non-prompt MC
//fname = "Bntuple20171209_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_20171128_bPt0jpsiPt0tkPt0p0_Bs";
//fname = "Bntuple20171209_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs";
//pp prompt MC
//fname = "Bntuple20171209_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_20171128_bPt0jpsiPt0tkPt0p0_Bs";
//fname = "Bntuple20171209_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs";
//inf = "../../../../samples/"+fname+".root";
//ouf = fname+"_BDT.root";
//coll = "pp";

//PbPb prompt MC
//fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_00_03_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_03_06_ext_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_03_06_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_06_09_ext_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_06_09_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_09_12_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_12_15_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_15_30_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_30_Inf_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//inf = "../../../../samples/Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsiX/"+fname+".root";
//ouf = fname+"_BDT.root";
//coll = "PbPb";

//pp signal with PbPb BDT
//fname = "Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_BDT15to50";
//fname = "Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_BDT15to50";
//inf = "../../../../samples/"+fname+".root";
//ouf = fname+"_PbPb_BDT.root";
//coll = "PbPb";
makeoutput(inf,ouf,coll,"BDT",1);
}
