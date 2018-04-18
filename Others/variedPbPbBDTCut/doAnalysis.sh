CENTPbPbMIN=0
CENTPbPbMAX=100
LABELPbPb="PbPb"
ISMCPbPb=0
ISDOWEIGHTPbPb=1
NPFIT_PbPb="1"
NPROOFIT_PbPb="1"
INPUTMCPbPbCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_candWise.root"
INPUTDATAPbPbCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT7to50_candWise.root"
TRGPbPb="(HLT_HIL1DoubleMu0_v1||HLT_HIL1DoubleMu0_part1_v1||HLT_HIL1DoubleMu0_part2_v1||HLT_HIL1DoubleMu0_part3_v1)"
TRGPbPbMC="(HLT_HIL1DoubleMu0_v1||HLT_HIL1DoubleMu0_part1_v1||HLT_HIL1DoubleMu0_part2_v1||HLT_HIL1DoubleMu0_part3_v1)"
SELGENPbPb="TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0"
SELGENPbPbACCPbPb="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0&&((TMath::Abs(Gmu1eta)<1.2&&Gmu1pt>3.5)||(TMath::Abs(Gmu1eta)>1.2&&TMath::Abs(Gmu1eta)<2.1&&Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta)))||(TMath::Abs(Gmu1eta)>2.1&&TMath::Abs(Gmu1eta)<2.4&&Gmu1pt>1.8))&&((TMath::Abs(Gmu2eta)<1.2&&Gmu2pt>3.5)||(TMath::Abs(Gmu2eta)>1.2&&TMath::Abs(Gmu2eta)<2.1&&Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta)))||(TMath::Abs(Gmu2eta)>2.1&&TMath::Abs(Gmu2eta)<2.4&&Gmu2pt>1.8))&&Gtk1pt>0.&&Gtk2pt>0.&&TMath::Abs(Gtk1eta)<2.4&&TMath::Abs(Gtk2eta)<2.4"
BASECUTPbPb="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.&&Btrk2Pt>0.&&abs(Btktkmass-1.019455)<0.015"
BASECUTPbPb=${BASECUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3"

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe
#g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe

#cutValArr=("+0.00" "+0.01" "-0.01")
#folderArr=("0p00" "p0p01" "m0p01")
#cutValArr=("+0.02" "-0.02")
#folderArr=("p0p02" "m0p02")
#cutValArr=("+0.03" "-0.03")
#folderArr=("p0p03" "m0p03")
#cutValArr=("+0.04" "-0.04")
#folderArr=("p0p04" "m0p04")
#cutValArr=("+0.05" "-0.05")
#folderArr=("p0p05" "m0p05")
#cutValArr=("+0.06" "-0.06")
#folderArr=("p0p06" "m0p06")
#cutValArr=("+0.07" "-0.07")
#folderArr=("p0p07" "m0p07")
#cutValArr=("+0.08" "-0.08")
#folderArr=("p0p08" "m0p08")
#cutValArr=("+0.09" "-0.09")
#folderArr=("p0p09" "m0p09")
cutValArr=("+0.10" "-0.10")
folderArr=("p0p10" "m0p10")
nVar=${#cutValArr[@]}
i=0
while ((i<$nVar))
do
echo 
cutValMod=${cutValArr[i]}
OUTPUTFOLDER="Var"${folderArr[i]}
echo $cutValMod $OUTPUTFOLDER
mkdir $OUTPUTFOLDER
CUTPbPb=${BASECUTPbPb}"&&(BDTStage1_pt15to50>(0.254413"${cutValMod}"))"
root -b -q 'roofitB.C++('1','0','\"$INPUTDATAPbPbCANDWISE\"','\"$INPUTMCPbPbCANDWISE\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFOLDER/output.root\"','\"$OUTPUTFOLDER\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
#./fitB.exe 1 0 "$INPUTDATAPbPbCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFOLDER/output.root" "$OUTPUTFOLDER" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"

./MCefficiency.exe 1 "$INPUTMCPbPbCANDWISE" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$CUTPbPb" "$CUTPbPb&&$TRGPbPbMC" "Bpt" "Gpt" "$LABELPbPb" "$OUTPUTFOLDER/eff.root" "$OUTPUTFOLDER" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"aa

i=$(($i+1))
done

#rm fitB.exe
#rm MCefficiency.exe
#rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
