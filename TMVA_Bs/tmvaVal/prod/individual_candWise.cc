#include "TFile.h"
#include "ProdMVAVal_candWise.cc"
void individual_candWise(){
	ptmin = 15;
    ptmax = 50;
	TString fname;
	TString inf;
	TString ouf;
	string coll;

//pp non-prompt MC
//fname = "Bntuple20180316_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs";
//pp prompt MC
//fname = "Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs";
//fname = "Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs";
//inf = "../../../../samples/"+fname+"_candWise.root";
//ouf = fname+"_BDT.root";
//coll = "pp";

//PbPb prompt MC
//fname = "Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_03_06_ext_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs";
//inf = "../../../../samples/Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsiX/"+fname+"_candWise.root";
//ouf = fname+"_BDT.root";
//coll = "PbPb";

//pp signal with PbPb BDT
//fname = "Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight";
//fname = "Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs";
//inf = "../../../../samples/"+fname+"_candWise.root";
//ouf = fname+"_PbPb_BDT.root";
//coll = "PbPb";
makeoutput(inf,ouf,coll,"BDT",1);
}
