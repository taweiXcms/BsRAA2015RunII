#!/bin/bash

CENTPbPbMIN=0
CENTPbPbMAX=100

#
DOSAVEHISTPP=1
DOSAVEHISTPbPb=0
DOSAVEHISTPPMB=0
DOSAVEHISTPbPbMB=0

#
DOFITDEFAULTNEWPP=0
DOFITDEFAULTNEWPbPb=0
DOFITDEFAULTNEWPPMB=0
DOFITDEFAULTNEWPbPbMB=0

DOFITINCREASEWIDPP=0
DOFITINCREASEWIDPbPb=0
DOFITINCREASEWIDPPMB=0
DOFITINCREASEWIDPbPbMB=0

DOFITDECREASEWIDPP=0
DOFITDECREASEWIDPbPb=0
DOFITDECREASEWIDPPMB=0
DOFITDECREASEWIDPbPbMB=0

DOFITPOLY2PP=0
DOFITPOLY2PbPb=0
DOFITPOLY2PPMB=0
DOFITPOLY2PbPbMB=0

DOFITEXPO2PP=0
DOFITEXPO2PbPb=0
DOFITEXPO2PPMB=0
DOFITEXPO2PbPbMB=0

##

INPUTMCPP="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_BDT15to50.root"
INPUTDATAPP="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_BDT15to50.root"
INPUTMCPbPb="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50.root"
INPUTDATAPbPb="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT15to50.root"

##

ISMCPP=0
ISDOWEIGHTPP=0
SELGENPP="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))"
CUTPP="Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>2.0&&Dtrk2Pt>2.0&&(DsvpvDistance/DsvpvDisErr)>3.5&&(DlxyBS/DlxyBSErr)>2.5&&Dchi2cl>0.05&&Dalpha<0.12&&Dtrk1PtErr/Dtrk1Pt<0.1&&Dtrk2PtErr/Dtrk2Pt<0.1&&abs(Dtrk1Eta)<2.0&&abs(Dtrk2Eta)<2.0&&Dtrk1OriginalAlgo>3&&Dtrk1OriginalAlgo<=8&&Dtrk2OriginalAlgo>3&&Dtrk2OriginalAlgo<=8&&(Dtrk1PixelHit+Dtrk1StripHit)>=11&&(Dtrk2PixelHit+Dtrk2StripHit)>=11&&(Dtrk1Chi2ndf/(Dtrk1nStripLayer+Dtrk1nPixelLayer)<0.15)&&(Dtrk2Chi2ndf/(Dtrk2nStripLayer+Dtrk2nPixelLayer)<0.15)"
TRGPP="((HLT_DmesonPPTrackingGlobal_Dpt15_v1&&Dpt>20&&Dpt<40)||(HLT_DmesonPPTrackingGlobal_Dpt30_v1&&Dpt>40&&Dpt<60)||(HLT_DmesonPPTrackingGlobal_Dpt50_v1&&Dpt>60))"
LABELPP="PP"

ISMCPbPb=0
ISDOWEIGHTPbPb=0
SELGENPbPb="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))"
CUTPbPb="Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>8.5&&Dtrk2Pt>8.5&&Dtrk1PtErr/Dtrk1Pt<0.1&&Dtrk2PtErr/Dtrk2Pt<0.1&&abs(Dtrk1Eta)<2.0&&abs(Dtrk2Eta)<2.0&&(Dtrk1PixelHit+Dtrk1StripHit)>=11&&(Dtrk2PixelHit+Dtrk2StripHit)>=11&&(Dtrk1Chi2ndf/(Dtrk1nStripLayer+Dtrk1nPixelLayer)<0.15)&&(Dtrk2Chi2ndf/(Dtrk2nStripLayer+Dtrk2nPixelLayer)<0.15)&&((DlxyBS/DlxyBSErr)>1.5&&Dalpha<0.12&&((Dpt>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<5&&(DsvpvDistance/DsvpvDisErr)>5.46&&Dchi2cl>0.196)||(Dpt>5&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/DsvpvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<20&&(DsvpvDistance/DsvpvDisErr)>3.71&&Dchi2cl>0.056)||(Dpt>20&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.25&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>2.97&&Dchi2cl>0.050)))"
TRGPbPb="((HLT_HIDmesonHITrackingGlobal_Dpt20_v1&&Dpt>20&&Dpt<40)||(HLT_HIDmesonHITrackingGlobal_Dpt40_v1&&Dpt>40&&Dpt<60)||(HLT_HIDmesonHITrackingGlobal_Dpt60_v1&&Dpt>60))"
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

if [ $DOFITDEFAULTNEWPP -eq 1 ]; then
g++ fitDdefaultnew.C $(root-config --cflags --libs) -g -o fitDdefaultnew.exe 
./fitDdefaultnew.exe "$LABELPP" 
rm fitDdefaultnew.exe
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

#
rm parameters.h

##
ISMCPPMB=0
ISDOWEIGHTPPMB=0
SELGENPPMB="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))"
CUTPPMB="Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<2.0&&abs(Dtrk2Eta)<2.0&&(DsvpvDistance/DsvpvDisErr)>3.5&&(DlxyBS/DlxyBSErr)>2.5&&Dchi2cl>0.05&&Dalpha<0.12"
TRGPPMB="(HLT_L1MinimumBiasHF1OR_part1_v1||HLT_L1MinimumBiasHF1OR_part2_v1||HLT_L1MinimumBiasHF1OR_part3_v1||HLT_L1MinimumBiasHF1OR_part4_v1||HLT_L1MinimumBiasHF1OR_part5_v1||HLT_L1MinimumBiasHF1OR_part6_v1||HLT_L1MinimumBiasHF1OR_part7_v1||HLT_L1MinimumBiasHF1OR_part8_v1||HLT_L1MinimumBiasHF1OR_part9_v1||HLT_L1MinimumBiasHF1OR_part10_v1||HLT_L1MinimumBiasHF1OR_part11_v1||HLT_L1MinimumBiasHF1OR_part12_v1||HLT_L1MinimumBiasHF1OR_part13_v1||HLT_L1MinimumBiasHF1OR_part14_v1||HLT_L1MinimumBiasHF1OR_part15_v1||HLT_L1MinimumBiasHF1OR_part16_v1||HLT_L1MinimumBiasHF1OR_part17_v1||HLT_L1MinimumBiasHF1OR_part18_v1||HLT_L1MinimumBiasHF1OR_part19_v1)"
LABELPPMB="PPMB"

ISMCPbPbMB=0
ISDOWEIGHTPbPbMB=0
SELGENPbPbMB="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))"
CUTPbPbMB="Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&((DlxyBS/DlxyBSErr)>1.5&&Dalpha<0.12&&((Dpt>1&&Dpt<2&&(DsvpvDistance/DsvpvDisErr)>6.0&&Dchi2cl>0.25)||(Dpt>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<5&&(DsvpvDistance/DsvpvDisErr)>5.46&&Dchi2cl>0.196)||(Dpt>5&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/DsvpvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<20&&(DsvpvDistance/DsvpvDisErr)>3.71&&Dchi2cl>0.056)||(Dpt>20&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.25&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>2.97&&Dchi2cl>0.050)))"
TRGPbPbMB="(HLT_HIL1MinimumBiasHF2AND_part1_v1||HLT_HIL1MinimumBiasHF2AND_part2_v1||HLT_HIL1MinimumBiasHF2AND_part3_v1)"
LABELPbPbMB="PbPbMB"

cp config/parametersLowpt.h parameters.h

if [ $DOSAVEHISTPPMB -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe 
./saveMasshisto.exe "$INPUTDATAPPMB" "$INPUTMCPPMB" "$TRGPPMB" "$CUTPPMB" "$ISMCPPMB" "$ISDOWEIGHTPPMB" "$LABELPPMB"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPbPbMB -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe 
./saveMasshisto.exe "$INPUTDATAPbPbMB" "$INPUTMCPbPbMB" "$TRGPbPbMB" "$CUTPbPbMB" "$ISMCPbPbMB" "$ISDOWEIGHTPbPbMB" "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm saveMasshisto.exe
fi

if [ $DOFITDEFAULTNEWPPMB -eq 1 ]; then
g++ fitDdefaultnew.C $(root-config --cflags --libs) -g -o fitDdefaultnew.exe 
./fitDdefaultnew.exe "$LABELPPMB"
rm fitDdefaultnew.exe
fi

if [ $DOFITDEFAULTNEWPbPbMB -eq 1 ]; then
g++ fitDdefaultnew.C $(root-config --cflags --libs) -g -o fitDdefaultnew.exe 
./fitDdefaultnew.exe "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDdefaultnew.exe
fi

if [ $DOFITINCREASEWIDPPMB -eq 1 ]; then
g++ fitDincreasewid.C $(root-config --cflags --libs) -g -o fitDincreasewid.exe 
./fitDincreasewid.exe "$LABELPPMB"
rm fitDincreasewid.exe
fi

if [ $DOFITINCREASEWIDPbPbMB -eq 1 ]; then
g++ fitDincreasewid.C $(root-config --cflags --libs) -g -o fitDincreasewid.exe 
./fitDincreasewid.exe "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDincreasewid.exe
fi

if [ $DOFITDECREASEWIDPPMB -eq 1 ]; then
g++ fitDdecreasewid.C $(root-config --cflags --libs) -g -o fitDdecreasewid.exe 
./fitDdecreasewid.exe "$LABELPPMB"
rm fitDdecreasewid.exe
fi

if [ $DOFITDECREASEWIDPbPbMB -eq 1 ]; then
g++ fitDdecreasewid.C $(root-config --cflags --libs) -g -o fitDdecreasewid.exe 
./fitDdecreasewid.exe "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDdecreasewid.exe
fi

if [ $DOFITPOLY2PPMB -eq 1 ]; then
g++ fitDpoly2.C $(root-config --cflags --libs) -g -o fitDpoly2.exe 
./fitDpoly2.exe "$LABELPPMB"
rm fitDpoly2.exe
fi

if [ $DOFITPOLY2PbPbMB -eq 1 ]; then
g++ fitDpoly2.C $(root-config --cflags --libs) -g -o fitDpoly2.exe 
./fitDpoly2.exe "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDpoly2.exe
fi

if [ $DOFITEXPO2PPMB -eq 1 ]; then
g++ fitDexpo2.C $(root-config --cflags --libs) -g -o fitDexpo2.exe 
./fitDexpo2.exe "$LABELPPMB"
rm fitDexpo2.exe
fi

if [ $DOFITEXPO2PbPbMB -eq 1 ]; then
g++ fitDexpo2.C $(root-config --cflags --libs) -g -o fitDexpo2.exe 
./fitDexpo2.exe "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDexpo2.exe
fi

#
rm parameters.h

##