CENTPbPbMIN=0
CENTPbPbMAX=100
DOANALYSISPP_FIT=1
DOANALYSISPP_FITONSAVED=1
DOANALYSISPbPb_FIT=1
DOANALYSISPbPb_FITONSAVED=1

INPUTMCPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_candWise.root"
INPUTMCPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_candWise.root"
INPUTDATAPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_candWise.root"
INPUTDATAPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_candWise.root"

MVA1="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more"
MVA2="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more"
MVA1INPUTMCPP=${MVA1}"/tmvaVal/MVAfiles/BDT_pp_7_15_varStage1_MC.root"
MVA1INPUTDATAPP=${MVA1}"/tmvaVal/MVAfiles/BDT_pp_7_15_varStage1_DATA.root"
MVA1INPUTMCPbPb=${MVA1}"/tmvaVal/MVAfiles/BDT_PbPb_7_15_varStage1_MC.root"
MVA1INPUTDATAPbPb=${MVA1}"/tmvaVal/MVAfiles/BDT_PbPb_7_15_varStage1_DATA.root"
MVA2INPUTMCPP=${MVA2}"/tmvaVal/MVAfiles/BDT_pp_15_50_varStage1_MC.root"
MVA2INPUTDATAPP=${MVA2}"/tmvaVal/MVAfiles/BDT_pp_15_50_varStage1_DATA.root"
MVA2INPUTMCPbPb=${MVA2}"/tmvaVal/MVAfiles/BDT_PbPb_15_50_varStage1_MC.root"
MVA2INPUTDATAPbPb=${MVA2}"/tmvaVal/MVAfiles/BDT_PbPb_15_50_varStage1_DATA.root"

SELGENPP="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0"
CUTPP="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.&&Btrk2Pt>0.&&abs(Btktkmass-1.019455)<0.015&&Btrk1highPurity&&Btrk2highPurity&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>0.191055)||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>0.208973))"
CUTPP=${CUTPP}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
TRGPP="(HLT_HIL1DoubleMu0_v1)"
TRGPPMC="(HLT_HIL1DoubleMu0ForPPRef_v1)"
ISMCPP=0
ISDOWEIGHTPP=0
LABELPP="pp"
OUTPUTFILEPPSAVEHIST="ROOTfiles/hPtSpectrumSaveHistBplusPP.root"
OUTPUTFILEPP="ROOTfiles/hPtSpectrumBplusPP.root"
NPFIT_PP="1"

SELGENPbPb="TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0"
CUTPbPb="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.&&Btrk2Pt>0.&&abs(Btktkmass-1.019455)<0.015&&Btrk1highPurity&&Btrk2highPurity&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>0.213755)||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>0.254413))"
CUTPbPb=${CUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3"
TRGPbPb="(HLT_HIL1DoubleMu0_v1||HLT_HIL1DoubleMu0_part1_v1||HLT_HIL1DoubleMu0_part2_v1||HLT_HIL1DoubleMu0_part3_v1)"
TRGPbPbMC="(HLT_HIL1DoubleMu0_v1||HLT_HIL1DoubleMu0_part1_v1||HLT_HIL1DoubleMu0_part2_v1||HLT_HIL1DoubleMu0_part3_v1)"
ISMCPbPb=0
ISDOWEIGHTPbPb=1
LABELPbPb="PbPb"
OUTPUTFILEPbPbSAVEHIST="ROOTfiles/hPtSpectrumSaveHistBplusPbPb.root"
OUTPUTFILEPbPb="ROOTfiles/hPtSpectrumBplusPbPb.root"
NPFIT_PbPb="1"



if [ $DOANALYSISPP_FIT -eq 1 ]; then
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe
./fitB.exe 0 0 "$INPUTDATAPP" "$INPUTMCPP" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST" "plotFits" "$NPFIT_PP" 0 "0" "100" "$MVA1INPUTDATAPP" "$MVA1INPUTMCPP" "$MVA2INPUTDATAPP" "$MVA2INPUTMCPP"
rm fitB.exe
fi

if [ $DOANALYSISPP_FITONSAVED -eq 1 ]; then
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST" "$OUTPUTFILEPPSAVEHIST" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP" "plotFitsOnSaved" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi

if [ $DOANALYSISPbPb_FIT -eq 1 ]; then
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe
./fitB.exe 1 0 "$INPUTDATAPbPb" "$INPUTMCPbPb" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPbSAVEHIST" "plotFits" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX" "$MVA1INPUTDATAPbPb" "$MVA1INPUTMCPbPb" "$MVA2INPUTDATAPbPb" "$MVA2INPUTMCPbPb"
rm fitB.exe
fi

if [ $DOANALYSISPbPb_FITONSAVED -eq 1 ]; then
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe
./fitB.exe 1 1 "$OUTPUTFILEPbPbSAVEHIST" "$OUTPUTFILEPPSAVEHIST" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPb" "plotFitsOnSaved" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi
