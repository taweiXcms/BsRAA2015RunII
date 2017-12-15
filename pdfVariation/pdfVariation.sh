#!/bin/bash

CENTPbPbMIN=0
CENTPbPbMAX=100

#
DOSAVEHISTPP=0
DOSAVEHISTPbPb=0

#
DOFITDEFAULT=1
DOFITDEFAULTNEWPbPb=0

DOFITINCREASEWIDPP=0
DOFITINCREASEWIDPbPb=0

DOFITDECREASEWIDPP=0
DOFITDECREASEWIDPbPb=0

DOFITPOLY2PP=0
DOFITPOLY2PbPb=0

DOFITEXPO2PP=0
DOFITEXPO2PbPb=0

##

INPUTMCPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_BDT15to50.root"
INPUTDATAPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_BDT15to50.root"
INPUTMCPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50.root"
INPUTDATAPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT15to50.root"

##

ISMCPP=0
ISDOWEIGHTPP=0
SELGENPP="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0"
CUTPP="TMath::Abs(By)<2.4 && TMath::Abs(Bmumumass-3.096916)<0.15 && ((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Bmu1TrgMatchFilterE>0 && Bmu2TrgMatchFilterE>0 && Btrk1highPurity && Btrk2highPurity && abs(Btrk1Eta)<2.4 && abs(Btrk2Eta)<2.4 && Btrk1Pt > 0.5 && Btrk2Pt > 0.5 && BDTStage1_pt15to50 > 0.209775"
CUTPP=${CUTPP}" && abs(PVz)<15 && pBeamScrapingFilter && pPAprimaryVertexFilter"
TRGPP="(HLT_HIL1DoubleMu0_v1)"
LABELPP="PP"

ISMCPbPb=0
ISDOWEIGHTPbPb=0
SELGENPbPb="TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0"
CUTPbPb="TMath::Abs(By)<2.4 && TMath::Abs(Bmumumass-3.096916)<0.15 && ((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Bmu1TrgMatchFilterE>0 && Bmu2TrgMatchFilterE>0 && Btrk1highPurity && Btrk2highPurity && abs(Btrk1Eta)<2.4 && abs(Btrk2Eta)<2.4 && Btrk1Pt > 0.8 && Btrk2Pt > 0.8 && BDTStage1_pt15to50 > 0.303985"
CUTPbPb=${CUTPbPb}" && abs(PVz)<15 && pclusterCompatibilityFilter && pprimaryVertexFilter && phfCoincFilter3"
TRGPbPb="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)"
LABELPbPb="PbPb"


if [ $DOSAVEHISTPP -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe 
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "$CUTPP" "$ISMCPP" "$ISDOWEIGHTPP" "$LABELPP"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPbPb -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe 
./saveMasshisto.exe "$INPUTDATAPbPb" "$INPUTMCPbPb" "$TRGPbPb" "$CUTPbPb" "$ISMCPbPb" "$ISDOWEIGHTPbPb" "$LABELPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm saveMasshisto.exe
fi

if [ $DOFITDEFAULT -eq 1 ]; then
g++ fitBdefault.C $(root-config --cflags --libs) -g -o fitBdefault.exe 
./fitBdefault.exe "$LABELPP" 
rm fitBdefault.exe
fi

if [ $DOFITDEFAULTNEWPbPb -eq 1 ]; then
g++ fitDdefaultnew.C $(root-config --cflags --libs) -g -o fitDdefaultnew.exe 
./fitDdefaultnew.exe "$LABELPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDdefaultnew.exe
fi

if [ $DOFITINCREASEWIDPP -eq 1 ]; then
g++ fitDincreasewid.C $(root-config --cflags --libs) -g -o fitDincreasewid.exe 
./fitDincreasewid.exe "$LABELPP"
rm fitDincreasewid.exe
fi

if [ $DOFITINCREASEWIDPbPb -eq 1 ]; then
g++ fitDincreasewid.C $(root-config --cflags --libs) -g -o fitDincreasewid.exe 
./fitDincreasewid.exe "$LABELPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDincreasewid.exe
fi

if [ $DOFITDECREASEWIDPP -eq 1 ]; then
g++ fitDdecreasewid.C $(root-config --cflags --libs) -g -o fitDdecreasewid.exe 
./fitDdecreasewid.exe "$LABELPP"
rm fitDdecreasewid.exe
fi

if [ $DOFITDECREASEWIDPbPb -eq 1 ]; then
g++ fitDdecreasewid.C $(root-config --cflags --libs) -g -o fitDdecreasewid.exe 
./fitDdecreasewid.exe "$LABELPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDdecreasewid.exe
fi

if [ $DOFITPOLY2PP -eq 1 ]; then
g++ fitDpoly2.C $(root-config --cflags --libs) -g -o fitDpoly2.exe 
./fitDpoly2.exe "$LABELPP"
rm fitDpoly2.exe
fi

if [ $DOFITPOLY2PbPb -eq 1 ]; then
g++ fitDpoly2.C $(root-config --cflags --libs) -g -o fitDpoly2.exe 
./fitDpoly2.exe "$LABELPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDpoly2.exe
fi

if [ $DOFITEXPO2PP -eq 1 ]; then
g++ fitDexpo2.C $(root-config --cflags --libs) -g -o fitDexpo2.exe 
./fitDexpo2.exe "$LABELPP"
rm fitDexpo2.exe
fi

if [ $DOFITEXPO2PbPb -eq 1 ]; then
g++ fitDexpo2.C $(root-config --cflags --libs) -g -o fitDexpo2.exe 
./fitDexpo2.exe "$LABELPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDexpo2.exe
fi
