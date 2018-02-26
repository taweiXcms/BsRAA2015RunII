#!/bin/bash
#source clean.sh
CENTPbPbMIN=0
CENTPbPbMAX=100

DOANALYSISPP_FONLL=0
DOANALYSISPP_FITNP=0
DOANALYSISPP_FIT=0
DOANALYSISPP_FITONSAVED=0
DOANALYSISPP_ROOFIT=0
DOANALYSISPP_ROOFITONSAVED=0
DOANALYSISPP_MCSTUDY=0
DOANALYSISPP_CROSS=0

DOANALYSISPbPb_FITNP=0
DOANALYSISPbPb_FIT=0
DOANALYSISPbPb_FITONSAVED=0
DOANALYSISPbPb_ROOFIT=0
DOANALYSISPbPb_ROOFITONSAVED=0
DOANALYSISPbPb_MCSTUDY=0
DOANALYSISPbPb_CROSS=0
DORAA=0
DORAARATIO=0

### pp 4-bin result
DOANALYSISPP_FONLL_1050=0
DOANALYSISPP_FIT_1050=0
DOANALYSISPP_FITONSAVED_1050=0
DOANALYSISPP_ROOFIT_1050=0
DOANALYSISPP_ROOFITONSAVED_1050=0
DOANALYSISPP_MCSTUDY_1050=0
DOANALYSISPP_CROSS_1050=0

### pp cut base MVA (GA)
DOANALYSISPP_FIT_GA=0
DOANALYSISPP_FITONSAVED_GA=0
DOANALYSISPP_ROOFIT_GA=0
DOANALYSISPP_ROOFITONSAVED_GA=0
DOANALYSISPP_MCSTUDY_GA=0
DOANALYSISPP_CROSS_GA=0

### pp sample with PbPb MVA (BDT)
DOANALYSISPP_FIT_PbPbBDT=0
DOANALYSISPP_FITONSAVED_PbPbBDT=0
DOANALYSISPP_ROOFIT_PbPbBDT=0
DOANALYSISPP_ROOFITONSAVED_PbPbBDT=0
DOANALYSISPP_MCSTUDY_PbPbBDT=0
DOANALYSISPP_CROSS_PbPbBDT=0

### Rapidity result
DOANALYSISPP_FIT_Y=0
DOANALYSISPP_FITONSAVED_Y=0
DOANALYSISPP_MCSTUDY_Y=0

### Reweighting
DOPTREWEIGHT=0

### Cross checks
DOClosure=0
DOCOMPARE=0
SAVEMVAPP=0
SAVEMVAPbPb=0
PLOTMVA=0

### Project some varibles
PROJECTVAR=1

### MC pp PbPb comparison
DOVARCOMPARE_MC=0

### Data - MC comparison
DOVARCOMPARE_PP=0

### Checking prompt background structure
CHECKPROMPT=0

## PP MONTE CARLO
#INPUTMCPP="/data/HeavyFlavourRun2/MC2015/Bntuple/pp/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_BDT15to50.root"
INPUTMCPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_BDT15to50.root"
INPUTMCPPCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_BDT15to50_candWise.root"
INPUTMCPP_PbPbBDT="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_PbPbBDT15to50.root"
INPUTMCPP_PbPbBDTCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_PbPbBDT15to50_candWise.root"

## PP DATA 
#INPUTDATAPP="/data/HeavyFlavourRun2/Data2015/Bntuple/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_BDT15to50.root"
INPUTDATAPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_BDT15to50.root"
INPUTDATAPPCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_BDT15to50_candWise.root"
INPUTDATAPP_PbPbBDT="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_PbPbBDT15to50.root"
INPUTDATAPP_PbPbBDTCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_PbPbBDT15to50_candWise.root"

## PbPb MONTE CARLO
#INPUTMCPbPb="/data/HeavyFlavourRun2/MC2015/Bntuple/PbPb/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50.root"
INPUTMCPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50.root"
INPUTMCPbPbCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50_candWise.root"

## PbPb DATA 
#INPUTDATAPbPb="/data/HeavyFlavourRun2/Data2015/Bntuple/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT15to50.root"
INPUTDATAPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT15to50.root"
INPUTDATAPbPbCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT15to50_candWise.root"

## ANALYSIS PP TRIGGERED
FONLLDATINPUT="pp_Bplus_5p03TeV_y2p4"
FONLLOUTPUTFILE="ROOTfiles/fonllOutput_pp_Bplus_5p03TeV_y2p4.root"
FONLLOUTPUTFILEREWEIGHT="ROOTfiles/fonllOutput_pp_Bplus_5p03TeV_y2p4_reweightBin.root"
OUTPUTFILERAA="ROOTfiles/outputRAA.root"

LABELPP="pp"
LUMIPP=27.748 # paper 20170224
#28.0*0.991
ISMCPP=0
ISDOWEIGHTPP=0
SELGENPP="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0"
SELGENPPACCPP="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0&&((TMath::Abs(Gmu1eta)<1.2&&Gmu1pt>3.5)||(TMath::Abs(Gmu1eta)>1.2&&TMath::Abs(Gmu1eta)<2.1&&Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta)))||(TMath::Abs(Gmu1eta)>2.1&&TMath::Abs(Gmu1eta)<2.4&&Gmu1pt>1.8))&&((TMath::Abs(Gmu2eta)<1.2&&Gmu2pt>3.5)||(TMath::Abs(Gmu2eta)>1.2&&TMath::Abs(Gmu2eta)<2.1&&Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta)))||(TMath::Abs(Gmu2eta)>2.1&&TMath::Abs(Gmu2eta)<2.4&&Gmu2pt>1.8))&&Gtk1pt>0.5&&Gtk2pt>0.5&&TMath::Abs(Gtk1eta)<2.4&&TMath::Abs(Gtk2eta)<2.4"
BASECUTPP="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.5&&Btrk2Pt>0.5"
CUTPP=${BASECUTPP}"&&BDTStage1_pt15to50>0.209775"
CUTPP=${CUTPP}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
RECOONLYPP=$CUTPP
TRGPP="(HLT_HIL1DoubleMu0_v1)"
TRGPPMC="(HLT_HIL1DoubleMu0ForPPRef_v1)"
OUTPUTFILEPPSAVEHIST="ROOTfiles/hPtSpectrumSaveHistBplusPP.root"
OUTPUTFILEPP="ROOTfiles/hPtSpectrumBplusPP.root"
OUTPUTFILEPPSAVEHIST_ROOFIT="ROOTfiles/hPtSpectrumSaveHistBplusPP_roofit.root"
OUTPUTFILEPP_ROOFIT="ROOTfiles/hPtSpectrumBplusPP_roofit.root"
OUTPUTFILEMCSTUDYPP="ROOTfiles/MCstudiesPP.root"
OUTPUTFILEPlotPP="ROOTfiles/CrossSectionPP.root"
OUTPUTFILEPPDATA="ROOTfiles/data_pp.root"
OUTPUTFILEPPMC="ROOTfiles/mc_pp.root"

#SETTING for NP fit
INPUTMCPP_NP="??"
CUTPP_NP="1"
OUTPUTFILEPP_NP="ROOTfiles/NPFitPP.root"
#NPFIT_PP="1"
NPFIT_PP="1.238105*Gaus(x,5.067665,0.015902)/(sqrt(2*3.14159)*0.015902)+30.054860*TMath::Erf((x-5.142158)/-0.114983)+30.054860+10.468093*(0.390932*Gaus(x,5.375549,0.166548)/(sqrt(2*3.14159)*0.166548)+(1-0.390932)*Gaus(x,5.375549,0.040095)/(sqrt(2*3.14159)*0.040095))"
#NPROOFIT_PP="1"
NPROOFIT_PP="1.238105*TMath::Gaus(Bmass,5.067665,0.015902)/(sqrt(2*3.14159)*0.015902)+30.054860*TMath::Erf((Bmass-5.142158)/-0.114983)+30.054860+10.468093*(0.390932*TMath::Gaus(Bmass,5.375549,0.166548)/(sqrt(2*3.14159)*0.166548)+(1-0.390932)*TMath::Gaus(Bmass,5.375549,0.040095)/(sqrt(2*3.14159)*0.040095))"


if [ $DOANALYSISPP_FONLL -eq 1 ]; then      
g++ Bplusdsigmadpt.cc $(root-config --cflags --libs) -g -o Bplusdsigmadpt.exe 
./Bplusdsigmadpt.exe "$FONLLDATINPUT" "$FONLLOUTPUTFILE" "$LABELPP"
rm Bplusdsigmadpt.exe
fi 

if [ $DOANALYSISPP_FITNP -eq 1 ]; then      
g++ fitNP.C $(root-config --cflags --libs) -g -o fitNP.exe 
./fitNP.exe 0 "$INPUTMCPP_NP" "$INPUTMCPP_NP" "1" "$CUTPP_NP" "$SELGENPP" 1 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP_NP"
rm fitNP.exe
fi 

if [ $DOANALYSISPP_FIT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPP" "$INPUTMCPP" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST" "plotFits" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST" "$OUTPUTFILEPPSAVEHIST" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP" "plotFitsOnSaved" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPPCANDWISE\"','\"$INPUTMCPPCANDWISE\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT\"','\"plotFits_roofit\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPP_ROOFIT\"','\"plotFitsOnSaved_roofit\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_MCSTUDY -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 0 "$INPUTMCPP" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP" "plotEff" "$ISDOWEIGHTPP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" "plotCrossSection" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_ROOFIT" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" "plotCrossSection" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
rm CrossSectionRatio.exe
fi

LABELPbPb="PbPb"
LUMIPbPb=13.1983052423 #paper 20170227
#NEW NMB from https://twiki.cern.ch/twiki/pub/CMS/HINUpsilonRaa2016/Jason_MinBiasCounting_2017-02-02.pdf
#2339717742. 2339717742*5.607/1e9 = 13.1187973794
#13.1187973794/0.99*0.996 = 13.1983052423
NMBEVT=2329685794.627413
ISMCPbPb=0
ISDOWEIGHTPbPb=1
SELGENPbPb="TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0"
SELGENPbPbACCPbPb="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0&&((TMath::Abs(Gmu1eta)<1.2&&Gmu1pt>3.5)||(TMath::Abs(Gmu1eta)>1.2&&TMath::Abs(Gmu1eta)<2.1&&Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta)))||(TMath::Abs(Gmu1eta)>2.1&&TMath::Abs(Gmu1eta)<2.4&&Gmu1pt>1.8))&&((TMath::Abs(Gmu2eta)<1.2&&Gmu2pt>3.5)||(TMath::Abs(Gmu2eta)>1.2&&TMath::Abs(Gmu2eta)<2.1&&Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta)))||(TMath::Abs(Gmu2eta)>2.1&&TMath::Abs(Gmu2eta)<2.4&&Gmu2pt>1.8))&&Gtk1pt>0.8&&Gtk2pt>0.8&&TMath::Abs(Gtk1eta)<2.4&&TMath::Abs(Gtk2eta)<2.4"
BASECUTPbPb="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.8&&Btrk2Pt>0.8"
CUTPbPb=${BASECUTPbPb}"&&BDTStage1_pt15to50>0.303985"
CUTPbPb=${CUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3"
RECOONLYPbPb=$CUTPbPb
TRGPbPb="(HLT_HIL1DoubleMu0_v1||HLT_HIL1DoubleMu0_part1_v1||HLT_HIL1DoubleMu0_part2_v1||HLT_HIL1DoubleMu0_part3_v1)"
TRGPbPbMC="(HLT_HIL1DoubleMu0_v1||HLT_HIL1DoubleMu0_part1_v1||HLT_HIL1DoubleMu0_part2_v1||HLT_HIL1DoubleMu0_part3_v1)"
OUTPUTFILEPbPbSAVEHIST="ROOTfiles/hPtSpectrumSaveHistBplusPbPb.root"
OUTPUTFILEPbPb="ROOTfiles/hPtSpectrumBplusPbPb.root"
OUTPUTFILEPbPbSAVEHIST_ROOFIT="ROOTfiles/hPtSpectrumSaveHistBplusPbPb_roofit.root"
OUTPUTFILEPbPb_ROOFIT="ROOTfiles/hPtSpectrumBplusPbPb_roofit.root"
OUTPUTFILEMCSTUDYPbPb="ROOTfiles/MCstudiesPbPb.root"
OUTPUTFILEPlotPbPb="ROOTfiles/CrossSectionPbPb.root"
OUTPUTFILEPbPbDATA="ROOTfiles/data_PbPb.root"
OUTPUTFILEPbPbMC="ROOTfiles/mc_PbPb.root"

#SETTING for NP fit
INPUTMCPbPb_NP="??"
CUTPbPb_NP="1"
OUTPUTFILEPbPb_NP="ROOTfiles/NPFitPbPb.root"
#NPFIT_PbPb="1"
NPFIT_PbPb="1.299998*Gaus(x,6.099828,-0.242801)/(sqrt(2*3.14159)*-0.242801)+8.186179*TMath::Erf((x-5.000000)/-0.205218)+8.186179+1.263652*(0.426611*Gaus(x,5.383307,0.249980)/(sqrt(2*3.14159)*0.249980)+(1-0.426611)*Gaus(x,5.383307,0.037233)/(sqrt(2*3.14159)*0.037233))" 
#NPROOFIT_PbPb="1"
NPROOFIT_PbPb="1.299998*TMath::Gaus(Bmass,6.099828,-0.242801)/(sqrt(2*3.14159)*-0.242801)+8.186179*TMath::Erf((Bmass-5.000000)/-0.205218)+8.186179+1.263652*(0.426611*TMath::Gaus(Bmass,5.383307,0.249980)/(sqrt(2*3.14159)*0.249980)+(1-0.426611)*TMath::Gaus(Bmass,5.383307,0.037233)/(sqrt(2*3.14159)*0.037233))" 

if [ $DOANALYSISPbPb_FITNP -eq 1 ]; then      
g++ fitNP.C $(root-config --cflags --libs) -g -o fitNP.exe 
./fitNP.exe 0 "$INPUTMCPbPb_NP" "$INPUTMCPbPb_NP" "1" "$CUTPbPb_NP" "$SELGENPbPb" 1 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPb_NP"
rm fitNP.exe
fi 

if [ $DOANALYSISPbPb_FIT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 0 "$INPUTDATAPbPb" "$INPUTMCPbPb" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPbSAVEHIST" "plotFits" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi 

if [ $DOANALYSISPbPb_FITONSAVED -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 1 "$OUTPUTFILEPbPbSAVEHIST" "$OUTPUTFILEPPSAVEHIST" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPb" "plotFitsOnSaved" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi 

if [ $DOANALYSISPbPb_ROOFIT -eq 1 ]; then      
root -b -q 'roofitB.C++('1','0','\"$INPUTDATAPbPbCANDWISE\"','\"$INPUTMCPbPbCANDWISE\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"plotFits_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPbPb_ROOFITONSAVED -eq 1 ]; then      
root -b -q 'roofitB.C++('1','1','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPb_ROOFIT\"','\"plotFitsOnSaved_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPbPb_MCSTUDY -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 1 "$INPUTMCPbPb" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC" "Bpt" "Gpt" "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb" "plotEff" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPbPb_CROSS -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPbPb" "$OUTPUTFILEMCSTUDYPbPb" "$OUTPUTFILEPlotPbPb" "plotCrossSection" 1 "$LABELPbPb" 0 0 "$LUMIPbPb" "0" "100"
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPbPb_ROOFIT" "$OUTPUTFILEMCSTUDYPbPb" "$OUTPUTFILEPlotPbPb" "plotCrossSection" 1 "$LABELPbPb" 0 0 "$LUMIPbPb" "0" "100"
rm CrossSectionRatio.exe
fi

if [ $DORAA -eq 1 ]; then
g++ NuclearModificationFactor.C $(root-config --cflags --libs) -g -o NuclearModificationFactor.exe
./NuclearModificationFactor.exe "$OUTPUTFILEPlotPP" "$OUTPUTFILEPlotPbPb" "$LABELPbPb" "$OUTPUTFILERAA" "plotRAA" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm NuclearModificationFactor.exe
fi

OUTPUTFILERAARATIO="plotBsBpRatio/outputRAA_Bs.root"
if [ $DORAARATIO -eq 1 ]; then
g++ NuclearModificationFactor.C $(root-config --cflags --libs) -g -o NuclearModificationFactor.exe
./NuclearModificationFactor.exe "$OUTPUTFILEPlotPP" "$OUTPUTFILEPlotPbPb" "$LABELPbPb" "$OUTPUTFILERAARATIO" "plotBsBpRatio" 1 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm NuclearModificationFactor.exe
fi

#########################################
### below are unrelated to main results
#########################################

### pp 4-bin result

FONLLOUTPUTFILE_1050="ROOTfiles/fonllOutput_pp_Bplus_5p03TeV_y2p4_1050.root"
OUTPUTFILEPPSAVEHIST_1050="ROOTfiles/hPtSpectrumSaveHistBplusPP_1050.root"
OUTPUTFILEPP_1050="ROOTfiles/hPtSpectrumBplusPP_1050.root"
OUTPUTFILEPPSAVEHIST_ROOFIT_1050="ROOTfiles/hPtSpectrumSaveHistBplusPP_roofit_1050.root"
OUTPUTFILEPP_ROOFIT_1050="ROOTfiles/hPtSpectrumBplusPP_roofit_1050.root"
OUTPUTFILEMCSTUDYPP_1050="ROOTfiles/MCstudiesPP_1050.root"
OUTPUTFILEPlotPP_1050="ROOTfiles/CrossSectionPP_1050.root"

if [ $DOANALYSISPP_FONLL_1050 -eq 1 ]; then      
g++ Bplusdsigmadpt.cc $(root-config --cflags --libs) -g -o Bplusdsigmadpt.exe 
./Bplusdsigmadpt.exe "$FONLLDATINPUT" "$FONLLOUTPUTFILE_1050" "$LABELPP" 2
rm Bplusdsigmadpt.exe
fi 

if [ $DOANALYSISPP_FIT_1050 -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPP" "$INPUTMCPP" "Bpt1050" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_1050" "plotFits_1050" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED_1050 -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST_1050" "$OUTPUTFILEPPSAVEHIST_1050" "Bpt1050" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP_1050" "plotFitsOnSaved_1050" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT_1050 -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPPCANDWISE\"','\"$INPUTMCPPCANDWISE\"','\"Bpt1050\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_1050\"','\"plotFits_roofit_1050\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED_1050 -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_1050\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_1050\"','\"Bpt1050\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPP_ROOFIT_1050\"','\"plotFitsOnSaved_roofit_1050\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_MCSTUDY_1050 -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 0 "$INPUTMCPP" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt1050" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_1050" "plotEff_1050" "$ISDOWEIGHTPP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS_1050 -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE_1050" "$OUTPUTFILEPP_1050" "$OUTPUTFILEMCSTUDYPP_1050" "$OUTPUTFILEPlotPP_1050" "plotCrossSection_1050" 0 "$LABELPP" 2 0 "$LUMIPP" "0" "100"
./CrossSectionRatio.exe "$FONLLOUTPUTFILE_1050" "$OUTPUTFILEPP_ROOFIT_1050" "$OUTPUTFILEMCSTUDYPP_1050" "$OUTPUTFILEPlotPP_1050" "plotCrossSection_1050" 0 "$LABELPP" 2 0 "$LUMIPP" "0" "100"
rm CrossSectionRatio.exe
fi


### pp cut base MVA (GA)

#CUTPPGA=${BASECUTPP}"&&Btrk1Pt>1.1853855433322771&&Btrk2Pt>0.47261988332982785&&abs(Btrk1Eta)<2.2102523477361786&&abs(Btrk2Eta)<2.239731094646741&&abs(Btrk1Dxy/Btrk1D0Err)>-1.343107180018156&&abs(Btrk2Dxy/Btrk2D0Err)>-0.81504321828465143&&abs(Btktkmass-1.019455)<0.012304449642086757&&BsvpvDistance/BsvpvDisErr>1.6538508008718509&&Balpha<2.28736667567639"
#CUTPPGA=${BASECUTPP}"&&Btrk1Pt>1.3486468575312338&&Btrk2Pt>0.99003619737011772&&abs(Btrk1Eta)<2.2390021911676503&&abs(Btrk2Eta)<2.1919242264088532&&abs(Btrk1Dxy/Btrk1D0Err)>0.13325600898808221&&abs(Btrk2Dxy/Btrk2D0Err)>-1.137760828578702&&abs(Btktkmass-1.019455)<0.016286614735555885&&BsvpvDistance/BsvpvDisErr>1.8390992253080078&&Balpha<3.0496767785458974"
#CUTPPGA=${BASECUTPP}"&&Btrk1Pt>1.2&&Btrk2Pt>1.2&&abs(Btrk1Eta)<2.2&&abs(Btrk2Eta)<2.2&&abs(Btrk1Dxy/Btrk1D0Err)>2.0&&abs(Btrk2Dxy/Btrk2D0Err)>2.0&&abs(Btktkmass-1.019455)<0.01&&BsvpvDistance/BsvpvDisErr>1.0&&Balpha<2.0"
CUTPPGA=${BASECUTPP}"&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&abs(Btrk1Dxy/Btrk1D0Err)>2.0&&abs(Btrk2Dxy/Btrk2D0Err)>2.0&&abs(Btktkmass-1.019455)<0.1&&BsvpvDistance/BsvpvDisErr>3.0&&Balpha<1.0"
CUTPPGA=${CUTPPGA}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
SELGENPPACCPPGA="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0&&((TMath::Abs(Gmu1eta)<1.2&&Gmu1pt>3.5)||(TMath::Abs(Gmu1eta)>1.2&&TMath::Abs(Gmu1eta)<2.1&&Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta)))||(TMath::Abs(Gmu1eta)>2.1&&TMath::Abs(Gmu1eta)<2.4&&Gmu1pt>1.8))&&((TMath::Abs(Gmu2eta)<1.2&&Gmu2pt>3.5)||(TMath::Abs(Gmu2eta)>1.2&&TMath::Abs(Gmu2eta)<2.1&&Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta)))||(TMath::Abs(Gmu2eta)>2.1&&TMath::Abs(Gmu2eta)<2.4&&Gmu2pt>1.8))&&Gtk1pt>1.&&Gtk2pt>1.&&TMath::Abs(Gtk1eta)<2.2&&TMath::Abs(Gtk2eta)<2.2"
OUTPUTFILEPPSAVEHIST_GA="ROOTfiles/hPtSpectrumSaveHistBplusPP_GA.root"
OUTPUTFILEPP_GA="ROOTfiles/hPtSpectrumBplusPP_GA.root"
OUTPUTFILEPPSAVEHIST_ROOFIT_GA="ROOTfiles/hPtSpectrumSaveHistBplusPP_roofit_GA.root"
OUTPUTFILEPP_ROOFIT_GA="ROOTfiles/hPtSpectrumBplusPP_roofit_GA.root"
OUTPUTFILEMCSTUDYPP_GA="ROOTfiles/MCstudiesPP_GA.root"
OUTPUTFILEPlotPP_GA="ROOTfiles/CrossSectionPP_GA.root"

if [ $DOANALYSISPP_FIT_GA -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPP" "$INPUTMCPP" "Bpt" "$TRGPP" "$CUTPPGA" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_GA" "plotFits_GA" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED_GA -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST_GA" "$OUTPUTFILEPPSAVEHIST_GA" "Bpt" "$TRGPP" "$CUTPPGA" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP_GA" "plotFitsOnSaved_GA" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT_GA -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPPCANDWISE\"','\"$INPUTMCPPCANDWISE\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPPGA\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_GA\"','\"plotFits_roofit_GA\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED_GA -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_GA\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_GA\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPPGA\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPP_ROOFIT_GA\"','\"plotFitsOnSaved_roofit_GA\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_MCSTUDY_GA -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 0 "$INPUTMCPP" "$SELGENPP" "$SELGENPPACCPPGA" "$RECOONLYPP" "$CUTPPGA&&$TRGPPMC" "Bpt" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_GA" "plotEff_GA" "$ISDOWEIGHTPP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS_GA -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_GA" "$OUTPUTFILEMCSTUDYPP_GA" "$OUTPUTFILEPlotPP_GA" "plotCrossSection_GA" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_ROOFIT_GA" "$OUTPUTFILEMCSTUDYPP_GA" "$OUTPUTFILEPlotPP_GA" "plotCrossSection_GA" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
rm CrossSectionRatio.exe
fi


### pp sample with PbPb MVA (BDT)

CUTPPPbPbBDT=${BASECUTPbPb}"&&BDTStage1_pt15to50>0.303985"
CUTPPPbPbBDT=${CUTPPPbPbBDT}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
OUTPUTFILEPPSAVEHIST_PbPbBDT="ROOTfiles/hPtSpectrumSaveHistBplusPP_PbPbBDT.root"
OUTPUTFILEPP_PbPbBDT="ROOTfiles/hPtSpectrumBplusPP_PbPbBDT.root"
OUTPUTFILEPPSAVEHIST_ROOFIT_PbPbBDT="ROOTfiles/hPtSpectrumSaveHistBplusPP_roofit_PbPbBDT.root"
OUTPUTFILEPP_ROOFIT_PbPbBDT="ROOTfiles/hPtSpectrumBplusPP_roofit_PbPbBDT.root"
OUTPUTFILEMCSTUDYPP_PbPbBDT="ROOTfiles/MCstudiesPP_PbPbBDT.root"
OUTPUTFILEPlotPP_PbPbBDT="ROOTfiles/CrossSectionPP_PbPbBDT.root"

if [ $DOANALYSISPP_FIT_PbPbBDT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPP_PbPbBDT" "$INPUTMCPP_PbPbBDT" "Bpt" "$TRGPP" "$CUTPPPbPbBDT" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_PbPbBDT" "plotFits_PbPbBDT" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED_PbPbBDT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST_PbPbBDT" "$OUTPUTFILEPPSAVEHIST_PbPbBDT" "Bpt" "$TRGPP" "$CUTPPPbPbBDT" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP_PbPbBDT" "plotFitsOnSaved_PbPbBDT" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT_PbPbBDT -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPP_PbPbBDTCANDWISE\"','\"$INPUTMCPP_PbPbBDTCANDWISE\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPPPbPbBDT\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_PbPbBDT\"','\"plotFits_roofit_PbPbBDT\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED_PbPbBDT -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_PbPbBDT\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_PbPbBDT\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPPPbPbBDT\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPP_ROOFIT_PbPbBDT\"','\"plotFitsOnSaved_roofit_PbPbBDT\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_MCSTUDY_PbPbBDT -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 0 "$INPUTMCPP_PbPbBDT" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPPPbPbBDT&&$TRGPPMC" "Bpt" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_PbPbBDT" "plotEff_PbPbBDT" "$ISDOWEIGHTPP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS_PbPbBDT -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_PbPbBDT" "$OUTPUTFILEMCSTUDYPP_PbPbBDT" "$OUTPUTFILEPlotPP_PbPbBDT" "plotCrossSection_PbPbBDT" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_ROOFIT_PbPbBDT" "$OUTPUTFILEMCSTUDYPP_PbPbBDT" "$OUTPUTFILEPlotPP_PbPbBDT" "plotCrossSection_PbPbBDT" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
rm CrossSectionRatio.exe
fi

### Rapidity result

OUTPUTFILEPPSAVEHIST_Y="ROOTfiles/hPtSpectrumSaveHistBplusPP_Y.root"
OUTPUTFILEPP_Y="ROOTfiles/hPtSpectrumBplusPP_Y.root"
OUTPUTFILEMCSTUDYPP_Y="ROOTfiles/MCstudiesPP_Y.root"
if [ $DOANALYSISPP_FIT_Y -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPP" "$INPUTMCPP" "abs(By)" "$TRGPP" "$CUTPP&&Bpt>15&&Bpt<50" "$SELGENPP&&Gpt>15&&Gpt<50" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_Y" "plotFits_Y" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED_Y -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST_Y" "$OUTPUTFILEPPSAVEHIST_Y" "abs(By)" "$TRGPP" "$CUTPP&&Bpt>15&&Bpt<50" "$SELGENPP&&Gpt>15&&Gpt<50" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP_Y" "plotFitsOnSaved_Y" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_MCSTUDY_Y -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 0 "$INPUTMCPP" "$SELGENPP&&Gpt>15&&Gpt<50" "$SELGENPPACCPP&&Gpt>15&&Gpt<50" "$RECOONLYPP&&Bpt>15&&Bpt<50" "$CUTPP&&$TRGPPMC&&Bpt>15&&Bpt<50" "abs(By)" "abs(Gy)" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_Y" "plotEff_Y" "$ISDOWEIGHTPP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

### Reweighting

if [ $DOPTREWEIGHT -eq 1 ]; then
#g++ Bplusdsigmadpt.cc $(root-config --cflags --libs) -g -o Bplusdsigmadpt.exe 
#./Bplusdsigmadpt.exe "$FONLLDATINPUT"  "$FONLLOUTPUTFILEREWEIGHT" "$LABELPP" 1
#rm Bplusdsigmadpt.exe
root -b -q weightMCpp.C++
rm weightMCpp_C.d weightMCpp_C.so weightMCpp_C_ACLiC_dict_rdict.pcm
root -b -q weightMCPbPb.C++
rm weightMCPbPb_C.d weightMCPbPb_C.so weightMCPbPb_C_ACLiC_dict_rdict.pcm
fi

### MEAN COMPARISON

if [ $DOCOMPARE -eq 1 ]; then
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$CUTPP"   "$SELGENPP"   0   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTFILEPPDATA" "plotOthers" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTMCPP"  "$INPUTMCPP"  "Bpt" "$TRGPPMC" "$CUTPP"   "$SELGENPP"   1   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTFILEPPMC" "plotOthers" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 0 "$INPUTDATAPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPb" "$CUTPbPb"   "$SELGENPbPb"   0   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPbDATA" "plotOthers" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 0 "$INPUTMCPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUTPbPb"   "$SELGENPbPb"   1   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPbMC" "plotOthers" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe

g++ comparison.C $(root-config --cflags --libs) -g -o comparison.exe 
./comparison.exe 
rm comparison.exe
fi

### MVA COMPARISON

if [ $SAVEMVAPP -eq 1 ]; then
g++ mvahisto.C $(root-config --cflags --libs) -g -o mvahisto.exe 
./mvahisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "$CUTPP" "$ISMCPP" "$ISDOWEIGHTPP" "$LABELPP"
rm mvahisto.exe
fi

if [ $SAVEMVAPbPb -eq 1 ]; then
g++ mvahisto.C $(root-config --cflags --libs) -g -o mvahisto.exe 
./mvahisto.exe "$INPUTDATAPbPb" "$INPUTMCPbPb" "$TRGPbPb" "$CUTPbPb" "$ISMCPbPb" "$ISDOWEIGHTPbPb" "$LABELPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm mvahisto.exe
fi

if [ $PLOTMVA -eq 1 ]; then
g++ fitBmva.C $(root-config --cflags --libs) -g -o fitBmva.exe 
./fitBmva.exe "$LABELPP" "$OUTPUTFILEPP" "$OUTPUTFILEPP_NP"
rm fitBmva.exe

g++ fitBmva.C $(root-config --cflags --libs) -g -o fitBmva.exe 
./fitBmva.exe "$LABELPbPb" "$OUTPUTFILEPbPb" "$OUTPUTFILEPbPb_NP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitBmva.exe
fi

### CLOSURE TEST

if [ $DOClosure -eq 1 ]; then      

OUTPUTFILEPPMCClosure="ROOTfiles/hPtSpectrumBplusPPMCClosure.root"
LUMIPPMCClosure=1
ISMCPPMCClosure=1
ISDOWEIGHTPPMCClosure=0
TRGPPMCClosure="1"
LABELPPMCClosure="PPMCClosure"

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTMCPP"  "$INPUTMCPP"  "Bpt" "$TRGPPMCClosure" "$CUTPP"   "$SELGENPP"   "$ISMCPPMCClosure"   "$LUMIPPMCClosure"   "$ISDOWEIGHTPPMCClosure"   "$LABELPPMCClosure"  "$OUTPUTFILEPPMCClosure" "plotClosure" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
g++ ClosureTest.C $(root-config --cflags --libs) -g -o ClosureTest.exe 
./ClosureTest.exe "$OUTPUTFILEPPMCClosure" "$LABELPP"

OUTPUTFILEPbPbMCClosure="ROOTfiles/hPtSpectrumBplusPbPbMCClosure.root"
LUMIPbPbMCClosure=1
ISMCPbPbMCClosure=1
ISDOWEIGHTPbPbMCClosure=0
TRGPbPbMCClosure="1"
LABELPbPbMCClosure="PbPbMCClosure"

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 0 "$INPUTMCPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMCClosure" "$CUTPbPb"   "$SELGENPbPb"   "$ISMCPbPbMCClosure"   "$LUMIPbPbMCClosure"   "$ISDOWEIGHTPbPbMCClosure"   "$LABELPbPbMCClosure"  "$OUTPUTFILEPbPbMCClosure" "plotClosure" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
g++ ClosureTest.C $(root-config --cflags --libs) -g -o ClosureTest.exe 
./ClosureTest.exe "$OUTPUTFILEPbPbMCClosure" "$LABELPbPb"
rm ClosureTest.exe

fi

### Project some varibles

if [ $PROJECTVAR -eq 1 ]; then      
g++ plotSth.C $(root-config --cflags --libs) -g -o plotSth.exe 
./plotSth.exe 0 "$INPUTDATAPP" "$INPUTMCPP" "Bpt" "$TRGPP" "$TRGPPMC" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST" "plotSth" "$NPFIT_PP" 0 "0" "100"
./plotSth.exe 1 "$INPUTDATAPbPb" "$INPUTMCPbPb" "Bpt" "$TRGPbPb" "$TRGPbPbMC" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPbSAVEHIST" "plotSth" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm plotSth.exe
fi 

### MC pp PbPb comparison

CUT="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.8&&Btrk2Pt>0.8"
_MCCUTPP=${CUT}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
_MCCUTPbPb=${CUT}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3"
if [ $DOVARCOMPARE_MC -eq 1 ]; then      
g++ plotCompMC.C $(root-config --cflags --libs) -g -o plotCompMC.exe 
./plotCompMC.exe 0 "$INPUTMCPP" "$INPUTMCPbPb" "Bpt" "$TRGPPMC" "$TRGPbPbMC" "$_MCCUTPP" "$_MCCUTPbPb" "$ISMCPP" 0 20 "$LABELPP" "$OUTPUTFILEPPSAVEHIST" "plotCompMC" "$NPFIT_PP" 0 "0" "100"
INPUTMCPP_PBPBBDT="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_PbPbBDT15to50.root"
./plotCompMC.exe 0 "$INPUTMCPP_PBPBBDT" "$INPUTMCPbPb" "Bpt" "$TRGPPMC" "$TRGPbPbMC" "$_MCCUTPP" "$_MCCUTPbPb" "$ISMCPP" 20 21 "$LABELPP" "$OUTPUTFILEPPSAVEHIST" "plotCompMC" "$NPFIT_PP" 0 "0" "100"
rm plotCompMC.exe
fi 

### Data - MC comparison

OUTPUTVARCOMPARE=""
if [ $DOVARCOMPARE_PP -eq 1 ]; then      
#rm plotFitsComp/*
g++ fitVariables.C $(root-config --cflags --libs) -g -o fitVariables.exe 
CUT=$CUTPP
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT"                   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 0
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 1
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 2
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 3
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 4
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 5
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 6
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 7
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 8
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 9
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 10
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 11
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 12
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 13
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 14
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 15
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 16
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 17
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 18
CUT="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.5&&Btrk2Pt>0.5"
CUT=${CUT}" && abs(PVz)<15 && pBeamScrapingFilter && pPAprimaryVertexFilter"
#CUT=${CUT}" && BDTStage1_pt15to50 > 0.0"
./fitVariables.exe 0 0 "$INPUTDATAPP"  "$INPUTMCPP"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 19
CUT=${CUT}"&&Btrk1Pt>0.8&&Btrk2Pt>0.8"
INPUTMCPP_PBPBBDT="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_PbPbBDT15to50.root"
INPUTDATAPP_PBPBBDT="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_PbPbBDT15to50.root"
./fitVariables.exe 0 0 "$INPUTDATAPP_PBPBBDT"  "$INPUTMCPP_PBPBBDT"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTVARCOMPARE" "$NPFIT_PP" 0 "0" "100" 20
rm fitVariables.exe
fi 

### Checking prompt background structure

if [ $CHECKPROMPT -eq 1 ]; then      
g++ fitPrompt.C $(root-config --cflags --libs) -g -o fitPrompt.exe 
INPUTPROMPTPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171209_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_ext_20171128_bPt0jpsiPt0tkPt0p0_Bs_BDT15to50.root"
CUT="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.5&&Btrk2Pt>0.5"
CUT=${CUT}" && abs(PVz)<15 && pBeamScrapingFilter && pPAprimaryVertexFilter"
./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPP"  "Bpt" "$TRGPPMC" "$CUT&&BDTStage1_pt15to50>0.209775"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "plotChecksPrompt/hPtSpectrumSaveHistBplusPP_BDTd4.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "BDTd4"
./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPP"  "Bpt" "$TRGPPMC" "$CUT&&BDTStage1_pt15to50>0.1"        "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "plotChecksPrompt/hPtSpectrumSaveHistBplusPP_BDT0p1.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "BDT0p1"
./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPP"  "Bpt" "$TRGPPMC" "$CUT&&BDTStage1_pt15to50>0.0"        "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "plotChecksPrompt/hPtSpectrumSaveHistBplusPP_BDT0p0.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "BDT0p0"
./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPP"  "Bpt" "$TRGPPMC" "$CUT&&BDTStage1_pt15to50>-0.1"       "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "plotChecksPrompt/hPtSpectrumSaveHistBplusPP_BDTm0p1.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "BDTm0p1"
./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPP"  "Bpt" "$TRGPPMC" "$CUT&&BDTStage1_pt15to50>-0.2"       "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "plotChecksPrompt/hPtSpectrumSaveHistBplusPP_BDTm0p2.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "BDTm0p2"

INPUTPROMPTPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs_BDT15to50.root"
CUT="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.8&&Btrk2Pt>0.8"
CUT=${CUT}" && abs(PVz)<15 && pclusterCompatibilityFilter && pprimaryVertexFilter && phfCoincFilter3"
./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUT&&BDTStage1_pt15to50>0.303985"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "plotChecksPrompt/hPtSpectrumSaveHistBplusPbPb_BDTd4.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDTd4"
./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUT&&BDTStage1_pt15to50>0.2"        "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "plotChecksPrompt/hPtSpectrumSaveHistBplusPbPb_BDT0p2.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDT0p2"
./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUT&&BDTStage1_pt15to50>0.1"        "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "plotChecksPrompt/hPtSpectrumSaveHistBplusPbPb_BDT0p1.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDT0p1"
./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUT&&BDTStage1_pt15to50>0.0"        "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "plotChecksPrompt/hPtSpectrumSaveHistBplusPbPb_BDT0p0.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDT0p0"
./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUT&&BDTStage1_pt15to50>-0.1"       "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "plotChecksPrompt/hPtSpectrumSaveHistBplusPbPb_BDTm0p1.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDTm0p1"

for f in 00_03 03_06 06_09 09_12 12_15 15_30 30_Inf
do
	SUBD="folder_PbPb_"$f
	INPUTPROMPTPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsiX/Bntuple20171120_bPt10_BfinderMC_PbPb_JpsiMM_ptJpsi_"$f"_Hydjet_MB_20171119_bPt10jpsiPt0tkPt0p8_Bs_BDT15to50.root"
	rm -r "plotChecksPrompt/"$SUBD
	mkdir "plotChecksPrompt/"$SUBD
	./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUT&&BDTStage1_pt15to50>0.303985"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "plotChecksPrompt/${SUBD}/hPtSpectrumSaveHistBplusPbPb_BDTd4.root" "plotChecksPrompt/${SUBD}" "$NPFIT_PbPb" 0 "0" "100" "BDTd4"
	./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUT&&BDTStage1_pt15to50>0.2"        "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "plotChecksPrompt/${SUBD}/hPtSpectrumSaveHistBplusPbPb_BDT0p2.root" "plotChecksPrompt/${SUBD}" "$NPFIT_PbPb" 0 "0" "100" "BDT0p2"
	./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUT&&BDTStage1_pt15to50>0.1"        "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "plotChecksPrompt/${SUBD}/hPtSpectrumSaveHistBplusPbPb_BDT0p1.root" "plotChecksPrompt/${SUBD}" "$NPFIT_PbPb" 0 "0" "100" "BDT0p1"
	./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUT&&BDTStage1_pt15to50>0.0"        "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "plotChecksPrompt/${SUBD}/hPtSpectrumSaveHistBplusPbPb_BDT0p0.root" "plotChecksPrompt/${SUBD}" "$NPFIT_PbPb" 0 "0" "100" "BDT0p0"
	./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPb"  "Bpt" "$TRGPbPbMC" "$CUT&&BDTStage1_pt15to50>-0.1"       "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "plotChecksPrompt/${SUBD}/hPtSpectrumSaveHistBplusPbPb_BDTm0p1.root" "plotChecksPrompt/${SUBD}" "$NPFIT_PbPb" 0 "0" "100" "BDTm0p1"
done

rm fitPrompt.exe
fi 
