#!/bin/bash
#source clean.sh
CENTPbPbMIN=0
CENTPbPbMAX=100

DOANALYSISPP_FONLL=0
DOANALYSISPP_FIT=0
DOANALYSISPP_FITONSAVED=0
DOANALYSISPP_ROOFIT=0
DOANALYSISPP_ROOFITONSAVED=0
DOANALYSISPP_MCSTUDY=0
DOANALYSISPP_CROSS=0

DOANALYSISPbPb_FIT=0
DOANALYSISPbPb_FITONSAVED=0
DOANALYSISPbPb_ROOFIT=0
DOANALYSISPbPb_ROOFITONSAVED=0
DOANALYSISPbPb_MCSTUDY=0
DOANALYSISPbPb_CROSS=0
DORAA=0
DORAARATIO=0

## PP MONTE CARLO
INPUTMCPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50.root"
INPUTMCPPCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_candWise.root"

## PP DATA 
INPUTDATAPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_BDT7to50.root"
INPUTDATAPPCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_BDT7to50_candWise.root"

## PbPb MONTE CARLO
INPUTMCPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50.root"
INPUTMCPbPbCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_candWise.root"

## PbPb DATA 
INPUTDATAPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT7to50.root"
INPUTDATAPbPbCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT7to50_candWise.root"

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
SELGENPPACCPP="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0&&((TMath::Abs(Gmu1eta)<1.2&&Gmu1pt>3.5)||(TMath::Abs(Gmu1eta)>1.2&&TMath::Abs(Gmu1eta)<2.1&&Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta)))||(TMath::Abs(Gmu1eta)>2.1&&TMath::Abs(Gmu1eta)<2.4&&Gmu1pt>1.8))&&((TMath::Abs(Gmu2eta)<1.2&&Gmu2pt>3.5)||(TMath::Abs(Gmu2eta)>1.2&&TMath::Abs(Gmu2eta)<2.1&&Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta)))||(TMath::Abs(Gmu2eta)>2.1&&TMath::Abs(Gmu2eta)<2.4&&Gmu2pt>1.8))&&Gtk1pt>0.&&Gtk2pt>0.&&TMath::Abs(Gtk1eta)<2.4&&TMath::Abs(Gtk2eta)<2.4"
BASECUTPP="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.&&Btrk2Pt>0.&&abs(Btktkmass-1.019455)<0.015"
CUTPP=${BASECUTPP}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>0.191055)||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>0.208973))"
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
NPFIT_PP="1"
#NPFIT_PP="1.238105*Gaus(x,5.067665,0.015902)/(sqrt(2*3.14159)*0.015902)+30.054860*TMath::Erf((x-5.142158)/-0.114983)+30.054860+10.468093*(0.390932*Gaus(x,5.375549,0.166548)/(sqrt(2*3.14159)*0.166548)+(1-0.390932)*Gaus(x,5.375549,0.040095)/(sqrt(2*3.14159)*0.040095))"
NPROOFIT_PP="1"
#NPROOFIT_PP="1.238105*TMath::Gaus(Bmass,5.067665,0.015902)/(sqrt(2*3.14159)*0.015902)+30.054860*TMath::Erf((Bmass-5.142158)/-0.114983)+30.054860+10.468093*(0.390932*TMath::Gaus(Bmass,5.375549,0.166548)/(sqrt(2*3.14159)*0.166548)+(1-0.390932)*TMath::Gaus(Bmass,5.375549,0.040095)/(sqrt(2*3.14159)*0.040095))"


if [ $DOANALYSISPP_FONLL -eq 1 ]; then      
g++ Bplusdsigmadpt.cc $(root-config --cflags --libs) -g -o Bplusdsigmadpt.exe 
./Bplusdsigmadpt.exe "$FONLLDATINPUT" "$FONLLOUTPUTFILE" "$LABELPP"
rm Bplusdsigmadpt.exe
fi 

if [ $DOANALYSISPP_FIT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPPCANDWISE" "$INPUTMCPPCANDWISE" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST" "plotFits/plotFits" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST" "$OUTPUTFILEPPSAVEHIST" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP" "plotFits/plotFitsOnSaved" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPPCANDWISE\"','\"$INPUTMCPPCANDWISE\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT\"','\"plotFits/plotFits_roofit\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPP_ROOFIT\"','\"plotFits/plotFitsOnSaved_roofit\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_MCSTUDY -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
#./MCefficiency.exe 0 "$INPUTMCPP" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP" "plotEff/plotEff" "$ISDOWEIGHTPP" "0" "100"
./MCefficiency.exe 0 "$INPUTMCPPCANDWISE" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP" "plotEff/plotEff" "$ISDOWEIGHTPP" "0" "100"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" "plotCrossSection/plotCrossSection" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100" 0 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" "plotCrossSection/plotCrossSection" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100" 0 1
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_ROOFIT" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" "plotCrossSection/plotCrossSection" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100" 0
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_ROOFIT" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" "plotCrossSection/plotCrossSection" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100" 0 1
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
SELGENPbPbACCPbPb="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0&&((TMath::Abs(Gmu1eta)<1.2&&Gmu1pt>3.5)||(TMath::Abs(Gmu1eta)>1.2&&TMath::Abs(Gmu1eta)<2.1&&Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta)))||(TMath::Abs(Gmu1eta)>2.1&&TMath::Abs(Gmu1eta)<2.4&&Gmu1pt>1.8))&&((TMath::Abs(Gmu2eta)<1.2&&Gmu2pt>3.5)||(TMath::Abs(Gmu2eta)>1.2&&TMath::Abs(Gmu2eta)<2.1&&Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta)))||(TMath::Abs(Gmu2eta)>2.1&&TMath::Abs(Gmu2eta)<2.4&&Gmu2pt>1.8))&&Gtk1pt>0.&&Gtk2pt>0.&&TMath::Abs(Gtk1eta)<2.4&&TMath::Abs(Gtk2eta)<2.4"
BASECUTPbPb="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.&&Btrk2Pt>0.&&abs(Btktkmass-1.019455)<0.015"
CUTPbPb=${BASECUTPbPb}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>0.213755)||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>0.254413))"
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
NPFIT_PbPb="1"
#NPFIT_PbPb="1.299998*Gaus(x,6.099828,-0.242801)/(sqrt(2*3.14159)*-0.242801)+8.186179*TMath::Erf((x-5.000000)/-0.205218)+8.186179+1.263652*(0.426611*Gaus(x,5.383307,0.249980)/(sqrt(2*3.14159)*0.249980)+(1-0.426611)*Gaus(x,5.383307,0.037233)/(sqrt(2*3.14159)*0.037233))" 
NPROOFIT_PbPb="1"
#NPROOFIT_PbPb="1.299998*TMath::Gaus(Bmass,6.099828,-0.242801)/(sqrt(2*3.14159)*-0.242801)+8.186179*TMath::Erf((Bmass-5.000000)/-0.205218)+8.186179+1.263652*(0.426611*TMath::Gaus(Bmass,5.383307,0.249980)/(sqrt(2*3.14159)*0.249980)+(1-0.426611)*TMath::Gaus(Bmass,5.383307,0.037233)/(sqrt(2*3.14159)*0.037233))" 

if [ $DOANALYSISPbPb_FIT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 0 "$INPUTDATAPbPbCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPbSAVEHIST" "plotFits/plotFits" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi 

if [ $DOANALYSISPbPb_FITONSAVED -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 1 "$OUTPUTFILEPbPbSAVEHIST" "$OUTPUTFILEPbPbSAVEHIST" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPb" "plotFits/plotFitsOnSaved" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi 

if [ $DOANALYSISPbPb_ROOFIT -eq 1 ]; then      
root -b -q 'roofitB.C++('1','0','\"$INPUTDATAPbPbCANDWISE\"','\"$INPUTMCPbPbCANDWISE\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"plotFits/plotFits_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPbPb_ROOFITONSAVED -eq 1 ]; then      
root -b -q 'roofitB.C++('1','1','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPb_ROOFIT\"','\"plotFits/plotFitsOnSaved_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPbPb_MCSTUDY -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
#./MCefficiency.exe 1 "$INPUTMCPbPb" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC" "Bpt" "Gpt" "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb" "plotEff/plotEff" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
./MCefficiency.exe 1 "$INPUTMCPbPbCANDWISE" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC" "Bpt" "Gpt" "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb" "plotEff/plotEff" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPbPb_CROSS -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPbPb" "$OUTPUTFILEMCSTUDYPbPb" "$OUTPUTFILEPlotPbPb" "plotCrossSection/plotCrossSection" 1 "$LABELPbPb" 0 0 "$LUMIPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX" 0
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPbPb_ROOFIT" "$OUTPUTFILEMCSTUDYPbPb" "$OUTPUTFILEPlotPbPb" "plotCrossSection/plotCrossSection" 1 "$LABELPbPb" 0 0 "$LUMIPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX" 0
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
cd plotBsBpRatio
root -b -q plotBsBpRatio.cc
cd -
fi
