DOSAVEHISTPP_DECAYLENGTH=0
DOSAVEHISTPbPb_DECAYLENGTH=0
DOSAVEHISTPP_CHI2=0
DOSAVEHISTPbPb_CHI2=0
DOSAVEHISTPP_COSTHETA=0
DOSAVEHISTPbPb_COSTHETA=0
DOSAVEHISTPP_TRKPT=0
DOSAVEHISTPbPb_TRKPT=0
DOSAVEHISTPP_TRKETA=0
DOSAVEHISTPbPb_TRKETA=0
DOSAVEHISTPP_BDT=0
DOSAVEHISTPbPb_BDT=0

DOFITPP_DECAYLENGTH=0
DOFITPbPb_DECAYLENGTH=0
DOFITPP_CHI2=0
DOFITPbPb_CHI2=0
DOFITPP_COSTHETA=0
DOFITPbPb_COSTHETA=0
DOFITPP_TRKPT=0
DOFITPbPb_TRKPT=0
DOFITPP_TRKETA=0
DOFITPbPb_TRKETA=0
DOFITPP_BDT=1
DOFITPbPb_BDT=1

DORATIO_DECAYLENGTH=0
DORATIO_CHI2=0
DORATIO_COSTHETA=0
DORATIO_TRKPT=0
DORATIO_TRKETA=0
DORATIO_BDT=1

VARBINS=10

LABEL_DECAYLENGTH="Decaylength"
VAR_DECAYLENGTH="(BsvpvDistance/BsvpvDisErr)"
VARMIN_PP_DECAYLENGTH=3.5
VARMAX_PP_DECAYLENGTH=7.5
VARMIN_PBPB_DECAYLENGTH=3.5
VARMAX_PBPB_DECAYLENGTH=7.5
VARSIGN_DECAYLENGTH=1
TEX_DECAYLENGTH="Decay length sig"

LABEL_CHI2="Chi2"
VAR_CHI2="Bchi2cl"
VARMIN_PP_CHI2=0.005
VARMAX_PP_CHI2=0.045
VARMIN_PBPB_CHI2=0.005
VARMAX_PBPB_CHI2=0.045
VARSIGN_CHI2=1
TEX_CHI2="Vtx prob"

LABEL_COSTHETA="costheta"
VAR_COSTHETA="cos(Bdtheta)"
VARMIN_PP_COSTHETA=-1
VARMAX_PP_COSTHETA=0.8
VARMIN_PBPB_COSTHETA=-1
VARMAX_PBPB_COSTHETA=0.8
VARSIGN_COSTHETA=1
TEX_COSTHETA="Cosine(#theta)"

LABEL_TRKPT="Btrk1Pt"
VAR_TRKPT="Btrk1Pt"
VARMIN_PP_TRKPT=1.2
VARMAX_PP_TRKPT=2.2
VARMIN_PBPB_TRKPT=1.2
VARMAX_PBPB_TRKPT=2.2
VARSIGN_TRKPT=1
TEX_TRKPT="trk pt"

LABEL_TRKETA="abs(Btrk1Eta)"
VAR_TRKETA="abs(Btrk1Eta)"
VARMIN_PP_TRKETA=2.1
VARMAX_PP_TRKETA=2.4
VARMIN_PBPB_TRKETA=2.1
VARMAX_PBPB_TRKETA=2.4
VARSIGN_TRKETA=0
TEX_TRKETA="trk eta"

LABEL_BDT="BDT"
VAR_BDT="BDTStage1_pt15to50"
VARMIN_PP_BDT=0.19
VARMAX_PP_BDT=0.21
VARMIN_PBPB_BDT=0.29
VARMAX_PBPB_BDT=0.31
VARSIGN_BDT=1
TEX_BDT="BDT"

########### pp settings ###########
INPUTMCPP="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_BDT15to50.root"
#INPUTMCPP="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_PthatX/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pthat0_Bpt5p0_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_BDT15to50.root"
INPUTDATAPP="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_BDT15to50.root"
TRGPP="(HLT_HIL1DoubleMu0_v1)"
TRGPPMC="(HLT_HIL1DoubleMu0ForPPRef_v1)"
FILTERCUTPP="TMath::Abs(By)<2.4 && TMath::Abs(Bmumumass-3.096916)<0.15 && ((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Bmu1TrgMatchFilterE>0 && Bmu2TrgMatchFilterE>0 && Btrk1highPurity && Btrk2highPurity && abs(Btrk1Eta)<2.4 && abs(Btrk2Eta)<2.4"
FILTERCUTPP_FIDUCIAL="Bpt>15 && Bpt<50"

MATCHEDCUTPP="Bgen==23333"
LABELPP="PP"
WEIGHTPP="pthatweight*(pow(10, -0.365511 + 0.030289*Bgenpt + -0.000691*Bgenpt*Bgenpt + 0.000005*Bgenpt*Bgenpt*Bgenpt))*((Bpt>7&&Bpt<8)*1.183134 + (Bpt>8&&Bpt<9)*1.140837 + (Bpt>9&&Bpt<10)*1.106397 + (Bpt>10&&Bpt<11)*1.080467 + (Bpt>11&&Bpt<12)*1.064683 + (Bpt>12&&Bpt<13)*1.051482 + (Bpt>13&&Bpt<14)*1.043229 + (Bpt>14&&Bpt<15)*1.036500 + (Bpt>15&&Bpt<16)*1.031066 + (Bpt>16&&Bpt<17)*1.026698 + (Bpt>17&&Bpt<18)*1.023079 + (Bpt>18&&Bpt<19)*1.021113 + (Bpt>19&&Bpt<20)*1.017171 + (Bpt>20&&Bpt<21)*1.016944 + (Bpt>21&&Bpt<22)*1.015072 + (Bpt>22&&Bpt<23)*1.011511 + (Bpt>23&&Bpt<24)*1.009411 + (Bpt>24&&Bpt<25)*1.008404 + (Bpt>25&&Bpt<26)*1.008083 + (Bpt>26&&Bpt<27)*1.007391 + (Bpt>27&&Bpt<28)*1.005159 + (Bpt>28&&Bpt<29)*1.003844 + (Bpt>29&&Bpt<30)*1.001041 + (Bpt>30&&Bpt<31)*1.001455 + (Bpt>31&&Bpt<32)*0.999298 + (Bpt>32&&Bpt<33)*0.997391 + (Bpt>33&&Bpt<34)*0.997792 + (Bpt>34&&Bpt<35)*0.995770 + (Bpt>35&&Bpt<36)*0.995824 + (Bpt>36&&Bpt<37)*0.993744 + (Bpt>37&&Bpt<38)*0.995328 + (Bpt>38&&Bpt<39)*0.991632 + (Bpt>39&&Bpt<40)*0.992715 + (Bpt>40&&Bpt<41)*0.988014 + (Bpt>41&&Bpt<42)*0.990041 + (Bpt>42&&Bpt<43)*0.988710 + (Bpt>43&&Bpt<44)*0.986858 + (Bpt>44&&Bpt<45)*0.986602 + (Bpt>45&&Bpt<46)*0.988457 + (Bpt>46&&Bpt<47)*0.984507 + (Bpt>47&&Bpt<48)*0.985602 + (Bpt>48&&Bpt<49)*0.983699 + (Bpt>49&&Bpt<50)*0.982575)"
#WEIGHTPP="pthatweight*(pow(10, -0.365511 + 0.030289*Bgenpt + -0.000691*Bgenpt*Bgenpt + 0.000005*Bgenpt*Bgenpt*Bgenpt))*((Bpt>10&&Bpt<12)*22823.31/21305.33 + (Bpt>12&&Bpt<15)*46684.27/44737.63 + (Bpt>15&&Bpt<20)*62732.74/61234.12 + (Bpt>20&&Bpt<30)*49566.28/49053.79 + (Bpt>30&&Bpt<50)*15394.50/15472.96)"
#WEIGHTPP="pthatweight*(pow(10, -0.365511 + 0.030289*Bgenpt + -0.000691*Bgenpt*Bgenpt + 0.000005*Bgenpt*Bgenpt*Bgenpt))"
#WEIGHTPP="pthatweight"
#WEIGHTPP="1"
PTTHRESHOLDPP=0
NPFIT_PP="??"

ADDCUTPP_DECAYLENGTH="(Bchi2cl > 0.05 && cos(Bdtheta) > 0.2)"
ADDCUTPP_CHI2="((BsvpvDistance/BsvpvDisErr)>4. && cos(Bdtheta) > 0.2)"
ADDCUTPP_COSTHETA="((BsvpvDistance/BsvpvDisErr)>4. && Bchi2cl > 0.005)"
ADDCUTPP_TRKPT="((BsvpvDistance/BsvpvDisErr)>4. && Bchi2cl > 0.005 && cos(Bdtheta) > 0.2)"
ADDCUTPP_TRKETA="((BsvpvDistance/BsvpvDisErr)>4. && Bchi2cl > 0.005 && cos(Bdtheta) > 0.2)"
ADDCUTPP_BDT="1"
NOMINALPP_DECAYLENGTH="(BsvpvDistance/BsvpvDisErr)>3.5"
NOMINALPP_CHI2="Bchi2cl > 0.1"
NOMINALPP_COSTHETA="cos(Bdtheta) > 0.2"
NOMINALPP_TRKPT="Btrk1Pt>1."
NOMINALPP_TRKETA="abs(Btrk1Eta)<2.4"
NOMINALPP_BDT="BDTStage1_pt15to50 > 0.209775"

########### PbPb settings ###########
INPUTMCPbPb="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50.root"
INPUTDATAPbPb="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT15to50.root"
TRGPbPb="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)"
TRGPbPbMC="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)"
FILTERCUTPbPb="TMath::Abs(By)<2.4 && TMath::Abs(Bmumumass-3.096916)<0.15 && ((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Bmu1TrgMatchFilterE>0 && Bmu2TrgMatchFilterE>0 && Btrk1highPurity && Btrk2highPurity && abs(Btrk1Eta)<2.4 && abs(Btrk2Eta)<2.4"
FILTERCUTPbPb_FIDUCIAL="Bpt>15 && Bpt<50"

MATCHEDCUTPbPb="Bgen==23333"
LABELPbPb="PbPb"
WEIGHTPbPb="pthatweight*(pow(10, -0.244653 + 0.016404*Bgenpt + -0.000199*Bgenpt*Bgenpt + 0.000000*Bgenpt*Bgenpt*Bgenpt))*(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))*(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))*(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))*(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))*((Bpt>10&&Bpt<11)*1.073184 + (Bpt>11&&Bpt<12)*1.034963 + (Bpt>12&&Bpt<13)*1.042868 + (Bpt>13&&Bpt<14)*1.027138 + (Bpt>14&&Bpt<15)*0.998933 + (Bpt>15&&Bpt<16)*1.007170 + (Bpt>16&&Bpt<17)*0.999765 + (Bpt>17&&Bpt<18)*0.987217 + (Bpt>18&&Bpt<19)*0.982895 + (Bpt>19&&Bpt<20)*0.988963 + (Bpt>20&&Bpt<21)*0.978554 + (Bpt>21&&Bpt<22)*0.981872 + (Bpt>22&&Bpt<23)*0.980659 + (Bpt>23&&Bpt<24)*0.973200 + (Bpt>24&&Bpt<25)*0.975354 + (Bpt>25&&Bpt<26)*0.974546 + (Bpt>26&&Bpt<27)*0.973232 + (Bpt>27&&Bpt<28)*0.976584 + (Bpt>28&&Bpt<29)*0.973318 + (Bpt>29&&Bpt<30)*0.968904 + (Bpt>30&&Bpt<31)*0.972373 + (Bpt>31&&Bpt<32)*0.968238 + (Bpt>32&&Bpt<33)*0.969184 + (Bpt>33&&Bpt<34)*0.975367 + (Bpt>34&&Bpt<35)*0.968537 + (Bpt>35&&Bpt<36)*0.973958 + (Bpt>36&&Bpt<37)*0.966428 + (Bpt>37&&Bpt<38)*0.968374 + (Bpt>38&&Bpt<39)*0.967941 + (Bpt>39&&Bpt<40)*0.964551 + (Bpt>40&&Bpt<41)*0.962934 + (Bpt>41&&Bpt<42)*0.970475 + (Bpt>42&&Bpt<43)*0.967707 + (Bpt>43&&Bpt<44)*0.969794 + (Bpt>44&&Bpt<45)*0.968380 + (Bpt>45&&Bpt<46)*0.966173 + (Bpt>46&&Bpt<47)*0.970380 + (Bpt>47&&Bpt<48)*0.970467 + (Bpt>48&&Bpt<49)*0.966409 + (Bpt>49&&Bpt<50)*0.977722)"
#WEIGHTPbPb="pthatweight*(pow(10, -0.244653 + 0.016404*Bgenpt + -0.000199*Bgenpt*Bgenpt + 0.000000*Bgenpt*Bgenpt*Bgenpt))*(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))*(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))*(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))*(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))"
#WEIGHTPbPb="pthatweight*(pow(10, -0.244653 + 0.016404*Bgenpt + -0.000199*Bgenpt*Bgenpt + 0.000000*Bgenpt*Bgenpt*Bgenpt))*(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))*(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))"
PTTHRESHOLDPbPb=0
NPFIT_PbPb="??"

ADDCUTPbPb_DECAYLENGTH="(Bchi2cl > 0.2 && cos(Bdtheta) > 0.2 && Btrk1Pt>1.5)"
ADDCUTPbPb_CHI2="((BsvpvDistance/BsvpvDisErr)>6. && cos(Bdtheta) > 0.2 && Btrk1Pt>1.)"
ADDCUTPbPb_COSTHETA="((BsvpvDistance/BsvpvDisErr)>6. && Bchi2cl > 0.2)"
ADDCUTPbPb_TRKPT="((BsvpvDistance/BsvpvDisErr)>6. && Bchi2cl > 0.2 && cos(Bdtheta) > 0.2)"
ADDCUTPbPb_TRKETA="((BsvpvDistance/BsvpvDisErr)>6. && Bchi2cl > 0.2 && cos(Bdtheta) > 0.2)"
ADDCUTPbPb_BDT="1"
NOMINALPbPb_DECAYLENGTH="(BsvpvDistance/BsvpvDisErr)>5."
NOMINALPbPb_CHI2="Bchi2cl > 0.1"
NOMINALPbPb_COSTHETA="cos(Bdtheta) > 0.2"
NOMINALPbPb_TRKPT="Btrk1Pt>1.8"
NOMINALPbPb_TRKETA="abs(Btrk1Eta)<2.4"
NOMINALPbPb_BDT="BDTStage1_pt15to50 > 0.303985"

#### Saving histograms
if [ $DOSAVEHISTPP_DECAYLENGTH -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_DECAYLENGTH}" 0 "1" "$LABELPP" "$NOMINALPP_DECAYLENGTH" "$LABEL_DECAYLENGTH" "$VAR_DECAYLENGTH" "$VARBINS" "$VARMIN_PP_DECAYLENGTH" "$VARMAX_PP_DECAYLENGTH" "$VARSIGN_DECAYLENGTH" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_DECAYLENGTH}" "1" "$WEIGHTPP" "$LABELPP" "$NOMINALPP_DECAYLENGTH" "$LABEL_DECAYLENGTH" "$VAR_DECAYLENGTH" "$VARBINS" "$VARMIN_PP_DECAYLENGTH" "$VARMAX_PP_DECAYLENGTH" "$VARSIGN_DECAYLENGTH" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPbPb_DECAYLENGTH -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPbPb" "$INPUTMCPbPb" "$TRGPbPb" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${ADDCUTPbPb_DECAYLENGTH}" 0 "1" "$LABELPbPb" "$NOMINALPbPb_DECAYLENGTH" "$LABEL_DECAYLENGTH" "$VAR_DECAYLENGTH" "$VARBINS" "$VARMIN_PBPB_DECAYLENGTH" "$VARMAX_PBPB_DECAYLENGTH" "$VARSIGN_DECAYLENGTH" "$PTTHRESHOLDPbPb"
./saveMasshisto.exe "$INPUTMCPbPb" "$INPUTMCPbPb" "$TRGPbPbMC" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${MATCHEDCUTPbPb}&&${ADDCUTPbPb_DECAYLENGTH}" "1" "$WEIGHTPbPb" "$LABELPbPb" "$NOMINALPbPb_DECAYLENGTH" "$LABEL_DECAYLENGTH" "$VAR_DECAYLENGTH" "$VARBINS" "$VARMIN_PBPB_DECAYLENGTH" "$VARMAX_PBPB_DECAYLENGTH" "$VARSIGN_DECAYLENGTH" "$PTTHRESHOLDPbPb"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPP_CHI2 -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_CHI2}" 0 "1" "$LABELPP" "$NOMINALPP_CHI2" "$LABEL_CHI2" "$VAR_CHI2" "$VARBINS" "$VARMIN_PP_CHI2" "$VARMAX_PP_CHI2" "$VARSIGN_CHI2" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_CHI2}" "1" "$WEIGHTPP" "$LABELPP" "$NOMINALPP_CHI2" "$LABEL_CHI2" "$VAR_CHI2" "$VARBINS" "$VARMIN_PP_CHI2" "$VARMAX_PP_CHI2" "$VARSIGN_CHI2" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPbPb_CHI2 -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPbPb" "$INPUTMCPbPb" "$TRGPbPb" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${ADDCUTPbPb_CHI2}" 0 "1" "$LABELPbPb" "$NOMINALPbPb_CHI2" "$LABEL_CHI2" "$VAR_CHI2" "$VARBINS" "$VARMIN_PBPB_CHI2" "$VARMAX_PBPB_CHI2" "$VARSIGN_CHI2" "$PTTHRESHOLDPbPb"
./saveMasshisto.exe "$INPUTMCPbPb" "$INPUTMCPbPb" "$TRGPbPbMC" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${MATCHEDCUTPbPb}&&${ADDCUTPbPb_CHI2}" "1" "$WEIGHTPbPb" "$LABELPbPb" "$NOMINALPbPb_CHI2" "$LABEL_CHI2" "$VAR_CHI2" "$VARBINS" "$VARMIN_PBPB_CHI2" "$VARMAX_PBPB_CHI2" "$VARSIGN_CHI2" "$PTTHRESHOLDPbPb"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPP_COSTHETA -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_COSTHETA}" 0 "1" "$LABELPP" "$NOMINALPP_COSTHETA" "$LABEL_COSTHETA" "$VAR_COSTHETA" "$VARBINS" "$VARMIN_PP_COSTHETA" "$VARMAX_PP_COSTHETA" "$VARSIGN_COSTHETA" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_COSTHETA}" "1" "$WEIGHTPP" "$LABELPP" "$NOMINALPP_COSTHETA" "$LABEL_COSTHETA" "$VAR_COSTHETA" "$VARBINS" "$VARMIN_PP_COSTHETA" "$VARMAX_PP_COSTHETA" "$VARSIGN_COSTHETA" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPbPb_COSTHETA -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPbPb" "$INPUTMCPbPb" "$TRGPbPb" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${ADDCUTPbPb_COSTHETA}" 0 "1" "$LABELPbPb" "$NOMINALPbPb_COSTHETA" "$LABEL_COSTHETA" "$VAR_COSTHETA" "$VARBINS" "$VARMIN_PBPB_COSTHETA" "$VARMAX_PBPB_COSTHETA" "$VARSIGN_COSTHETA" "$PTTHRESHOLDPbPb"
./saveMasshisto.exe "$INPUTMCPbPb" "$INPUTMCPbPb" "$TRGPbPbMC" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${MATCHEDCUTPbPb}&&${ADDCUTPbPb_COSTHETA}" "1" "$WEIGHTPbPb" "$LABELPbPb" "$NOMINALPbPb_COSTHETA" "$LABEL_COSTHETA" "$VAR_COSTHETA" "$VARBINS" "$VARMIN_PBPB_COSTHETA" "$VARMAX_PBPB_COSTHETA" "$VARSIGN_COSTHETA" "$PTTHRESHOLDPbPb"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPP_TRKPT -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_TRKPT}" 0 "1" "$LABELPP" "$NOMINALPP_TRKPT" "$LABEL_TRKPT" "$VAR_TRKPT" "$VARBINS" "$VARMIN_PP_TRKPT" "$VARMAX_PP_TRKPT" "$VARSIGN_TRKPT" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_TRKPT}" "1" "$WEIGHTPP" "$LABELPP" "$NOMINALPP_TRKPT" "$LABEL_TRKPT" "$VAR_TRKPT" "$VARBINS" "$VARMIN_PP_TRKPT" "$VARMAX_PP_TRKPT" "$VARSIGN_TRKPT" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPbPb_TRKPT -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPbPb" "$INPUTMCPbPb" "$TRGPbPb" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${ADDCUTPbPb_TRKPT}" 0 "1" "$LABELPbPb" "$NOMINALPbPb_TRKPT" "$LABEL_TRKPT" "$VAR_TRKPT" "$VARBINS" "$VARMIN_PBPB_TRKPT" "$VARMAX_PBPB_TRKPT" "$VARSIGN_TRKPT" "$PTTHRESHOLDPbPb"
./saveMasshisto.exe "$INPUTMCPbPb" "$INPUTMCPbPb" "$TRGPbPbMC" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${MATCHEDCUTPbPb}&&${ADDCUTPbPb_TRKPT}" "1" "$WEIGHTPbPb" "$LABELPbPb" "$NOMINALPbPb_TRKPT" "$LABEL_TRKPT" "$VAR_TRKPT" "$VARBINS" "$VARMIN_PBPB_TRKPT" "$VARMAX_PBPB_TRKPT" "$VARSIGN_TRKPT" "$PTTHRESHOLDPbPb"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPP_TRKETA -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_TRKETA}" 0 "1" "$LABELPP" "$NOMINALPP_TRKETA" "$LABEL_TRKETA" "$VAR_TRKETA" "$VARBINS" "$VARMIN_PP_TRKETA" "$VARMAX_PP_TRKETA" "$VARSIGN_TRKETA" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_TRKETA}" "1" "$WEIGHTPP" "$LABELPP" "$NOMINALPP_TRKETA" "$LABEL_TRKETA" "$VAR_TRKETA" "$VARBINS" "$VARMIN_PP_TRKETA" "$VARMAX_PP_TRKETA" "$VARSIGN_TRKETA" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPbPb_TRKETA -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPbPb" "$INPUTMCPbPb" "$TRGPbPb" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${ADDCUTPbPb_TRKETA}" 0 "1" "$LABELPbPb" "$NOMINALPbPb_TRKETA" "$LABEL_TRKETA" "$VAR_TRKETA" "$VARBINS" "$VARMIN_PBPB_TRKETA" "$VARMAX_PBPB_TRKETA" "$VARSIGN_TRKETA" "$PTTHRESHOLDPbPb"
./saveMasshisto.exe "$INPUTMCPbPb" "$INPUTMCPbPb" "$TRGPbPbMC" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${MATCHEDCUTPbPb}&&${ADDCUTPbPb_TRKETA}" "1" "$WEIGHTPbPb" "$LABELPbPb" "$NOMINALPbPb_TRKETA" "$LABEL_TRKETA" "$VAR_TRKETA" "$VARBINS" "$VARMIN_PBPB_TRKETA" "$VARMAX_PBPB_TRKETA" "$VARSIGN_TRKETA" "$PTTHRESHOLDPbPb"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPP_BDT -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_BDT}" 0 "1" "$LABELPP" "$NOMINALPP_BDT" "$LABEL_BDT" "$VAR_BDT" "$VARBINS" "$VARMIN_PP_BDT" "$VARMAX_PP_BDT" "$VARSIGN_BDT" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_BDT}" "1" "$WEIGHTPP" "$LABELPP" "$NOMINALPP_BDT" "$LABEL_BDT" "$VAR_BDT" "$VARBINS" "$VARMIN_PP_BDT" "$VARMAX_PP_BDT" "$VARSIGN_BDT" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPbPb_BDT -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPbPb" "$INPUTMCPbPb" "$TRGPbPb" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${ADDCUTPbPb_BDT}" 0 "1" "$LABELPbPb" "$NOMINALPbPb_BDT" "$LABEL_BDT" "$VAR_BDT" "$VARBINS" "$VARMIN_PBPB_BDT" "$VARMAX_PBPB_BDT" "$VARSIGN_BDT" "$PTTHRESHOLDPbPb"
./saveMasshisto.exe "$INPUTMCPbPb" "$INPUTMCPbPb" "$TRGPbPbMC" "${FILTERCUTPbPb}&&${FILTERCUTPbPb_FIDUCIAL}&&${MATCHEDCUTPbPb}&&${ADDCUTPbPb_BDT}" "1" "$WEIGHTPbPb" "$LABELPbPb" "$NOMINALPbPb_BDT" "$LABEL_BDT" "$VAR_BDT" "$VARBINS" "$VARMIN_PBPB_BDT" "$VARMAX_PBPB_BDT" "$VARSIGN_BDT" "$PTTHRESHOLDPbPb"
rm saveMasshisto.exe
fi

#### Fitting on saved histograms
if [ $DOFITPP_DECAYLENGTH -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPP" "$NOMINALPP_DECAYLENGTH" "$LABEL_DECAYLENGTH" "$VARBINS" "$VARMIN_PP_DECAYLENGTH" "$VARMAX_PP_DECAYLENGTH" "$TEX_DECAYLENGTH" "$VARSIGN_DECAYLENGTH" "$NPFIT_PP"
rm fitD.exe
fi

if [ $DOFITPbPb_DECAYLENGTH -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPbPb" "$NOMINALPbPb_DECAYLENGTH" "$LABEL_DECAYLENGTH" "$VARBINS" "$VARMIN_PBPB_DECAYLENGTH" "$VARMAX_PBPB_DECAYLENGTH" "$TEX_DECAYLENGTH" "$VARSIGN_DECAYLENGTH" "$NPFIT_PbPb"
rm fitD.exe
fi

if [ $DOFITPP_CHI2 -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPP" "$NOMINALPP_CHI2" "$LABEL_CHI2" "$VARBINS" "$VARMIN_PP_CHI2" "$VARMAX_PP_CHI2" "$TEX_CHI2" "$VARSIGN_CHI2" "$NPFIT_PP"
rm fitD.exe
fi

if [ $DOFITPbPb_CHI2 -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPbPb" "$NOMINALPbPb_CHI2" "$LABEL_CHI2" "$VARBINS" "$VARMIN_PBPB_CHI2" "$VARMAX_PBPB_CHI2" "$TEX_CHI2" "$VARSIGN_CHI2" "$NPFIT_PbPb"
rm fitD.exe
fi

if [ $DOFITPP_COSTHETA -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPP" "$NOMINALPP_COSTHETA" "$LABEL_COSTHETA" "$VARBINS" "$VARMIN_PP_COSTHETA" "$VARMAX_PP_COSTHETA" "$TEX_COSTHETA" "$VARSIGN_COSTHETA" "$NPFIT_PP"
rm fitD.exe
fi

if [ $DOFITPbPb_COSTHETA -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPbPb" "$NOMINALPbPb_COSTHETA" "$LABEL_COSTHETA" "$VARBINS" "$VARMIN_PBPB_COSTHETA" "$VARMAX_PBPB_COSTHETA" "$TEX_COSTHETA" "$VARSIGN_COSTHETA" "$NPFIT_PbPb"
rm fitD.exe
fi

if [ $DOFITPP_TRKPT -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPP" "$NOMINALPP_TRKPT" "$LABEL_TRKPT" "$VARBINS" "$VARMIN_PP_TRKPT" "$VARMAX_PP_TRKPT" "$TEX_TRKPT" "$VARSIGN_TRKPT" "$NPFIT_PP"
rm fitD.exe
fi

if [ $DOFITPbPb_TRKPT -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPbPb" "$NOMINALPbPb_TRKPT" "$LABEL_TRKPT" "$VARBINS" "$VARMIN_PBPB_TRKPT" "$VARMAX_PBPB_TRKPT" "$TEX_TRKPT" "$VARSIGN_TRKPT" "$NPFIT_PbPb"
rm fitD.exe
fi

if [ $DOFITPP_TRKETA -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPP" "$NOMINALPP_TRKETA" "$LABEL_TRKETA" "$VARBINS" "$VARMIN_PP_TRKETA" "$VARMAX_PP_TRKETA" "$TEX_TRKETA" "$VARSIGN_TRKETA" "$NPFIT_PP"
rm fitD.exe
fi

if [ $DOFITPbPb_TRKETA -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPbPb" "$NOMINALPbPb_TRKETA" "$LABEL_TRKETA" "$VARBINS" "$VARMIN_PBPB_TRKETA" "$VARMAX_PBPB_TRKETA" "$TEX_TRKETA" "$VARSIGN_TRKETA" "$NPFIT_PbPb"
rm fitD.exe
fi

if [ $DOFITPP_BDT -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPP" "$NOMINALPP_BDT" "$LABEL_BDT" "$VARBINS" "$VARMIN_PP_BDT" "$VARMAX_PP_BDT" "$TEX_BDT" "$VARSIGN_BDT" "$NPFIT_PP"
rm fitD.exe
fi

if [ $DOFITPbPb_BDT -eq 1 ]; then
g++ fitD.C $(root-config --cflags --libs) -g -o fitD.exe
./fitD.exe "$LABELPbPb" "$NOMINALPbPb_BDT" "$LABEL_BDT" "$VARBINS" "$VARMIN_PBPB_BDT" "$VARMAX_PBPB_BDT" "$TEX_BDT" "$VARSIGN_BDT" "$NPFIT_PbPb"
rm fitD.exe
fi

#### Plotting the double ratio (PbPb/pp) of double ratio (data/mc)
if [ $DORATIO_DECAYLENGTH -eq 1 ]; then
g++ plotRatioDoubleratio.C $(root-config --cflags --libs) -g -o plotRatioDoubleratio.exe
./plotRatioDoubleratio.exe "$LABEL_DECAYLENGTH" "$TEX_DECAYLENGTH"
rm plotRatioDoubleratio.exe
fi

if [ $DORATIO_CHI2 -eq 1 ]; then
g++ plotRatioDoubleratio.C $(root-config --cflags --libs) -g -o plotRatioDoubleratio.exe
./plotRatioDoubleratio.exe "$LABEL_CHI2" "$TEX_CHI2"
rm plotRatioDoubleratio.exe
fi

if [ $DORATIO_COSTHETA -eq 1 ]; then
g++ plotRatioDoubleratio.C $(root-config --cflags --libs) -g -o plotRatioDoubleratio.exe
./plotRatioDoubleratio.exe "$LABEL_COSTHETA" "$TEX_COSTHETA"
rm plotRatioDoubleratio.exe
fi

if [ $DORATIO_TRKPT -eq 1 ]; then
g++ plotRatioDoubleratio.C $(root-config --cflags --libs) -g -o plotRatioDoubleratio.exe
./plotRatioDoubleratio.exe "$LABEL_TRKPT" "$TEX_TRKPT"
rm plotRatioDoubleratio.exe
fi

if [ $DORATIO_TRKETA -eq 1 ]; then
g++ plotRatioDoubleratio.C $(root-config --cflags --libs) -g -o plotRatioDoubleratio.exe
./plotRatioDoubleratio.exe "$LABEL_TRKETA" "$TEX_TRKETA"
rm plotRatioDoubleratio.exe
fi

if [ $DORATIO_BDT -eq 1 ]; then
g++ plotRatioDoubleratio.C $(root-config --cflags --libs) -g -o plotRatioDoubleratio.exe
./plotRatioDoubleratio.exe "$LABEL_BDT" "$TEX_BDT"
rm plotRatioDoubleratio.exe
fi
