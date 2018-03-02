bool isPbPb;
float ptmin;
float ptmax;
double luminosity;
TString inputSname, inputBname;
TString mycut, mycuts, mycutb, mycutg;
TString colsyst;
TString MVAtype;
TString npfile;
TString selgen = "TMath::Abs(Gy)<2.4 && abs(GpdgId)==531 && (GisSignal==6)";
TString kinematic_cuts = "Bmass>5 && Bmass<6";
TString prefilter = "TMath::Abs(By)<2.4 && TMath::Abs(Bmumumass-3.096916)<0.15 && ((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1highPurity && Btrk2highPurity && Bmu1TrgMatchFilterE>0 && Bmu2TrgMatchFilterE>0 && abs(Btrk1Eta)<2.4 && abs(Btrk2Eta)<2.4 && abs(Btktkmass-1.019455) < 0.015";
TString masssideband = "abs(Bmass-5.367)>0.2&&abs(Bmass-5.367)<0.3";

//////////pp section
double lum_pp=27.748;
TString inputSname_pp = "/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight.root";
TString inputBname_pp = "/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_AddDummyHLT_HIL1DoubleMu0ForPPRef_v1.root";
TString myTrg_pp = "(HLT_HIL1DoubleMu0_v1)";
TString myTrg_ppMC = "(HLT_HIL1DoubleMu0ForPPRef_v1)";
TString evtfilter_pp = "abs(PVz)<15 && pBeamScrapingFilter && pPAprimaryVertexFilter";
TString mycut_pp = evtfilter_pp + "&&" + kinematic_cuts + "&&" + prefilter;
TString mycuts_pp = Form("%s && Bgen==23333 && %s",mycut_pp.Data(), myTrg_ppMC.Data());
TString mycutb_pp = Form("%s && %s && %s",masssideband.Data(), mycut_pp.Data(), myTrg_pp.Data());
TString mycutg_pp = selgen;

///////PbPb section
double lum_PP=13.19;
TString inputSname_PP = "/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight.root";
TString inputBname_PP = "/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged.root";
TString myTrg_PP = "(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)"; 
TString myTrg_PPMC = "(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)"; 
TString evtfilter_PP = "abs(PVz)<15 && pclusterCompatibilityFilter && pprimaryVertexFilter && phfCoincFilter3"; 
TString mycut_PP = evtfilter_PP + "&&" + kinematic_cuts + "&&" + prefilter;
TString mycuts_PP = Form("%s && Bgen==23333 && %s",mycut_PP.Data(), myTrg_PPMC.Data());
TString mycutb_PP = Form("%s && %s && %s",masssideband.Data(), mycut_PP.Data(), myTrg_PP.Data()); 
TString mycutg_PP = selgen; 
