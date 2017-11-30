#!/bin/bash
#source clean.sh
CENTPbPbMIN=0
CENTPbPbMAX=100
#Central point of the analysis

DOANALYSISPP_FONLL=1
DOANALYSISPP_FITNP=0
DOANALYSISPP_FIT=1
DOANALYSISPP_MCSTUDY=0
DOANALYSISPP_CROSS=1

DOANALYSISPbPb_FONLL=0
DOANALYSISPbPb_FITNP=0
DOANALYSISPbPb_FIT=0
DOANALYSISPbPb_MCSTUDY=0
DOANALYSISPbPb_CROSS=0
DORAA=0

#Rapidity RAA
DOANALYSISPP_FIT_Y=0
DOANALYSISPP_MCSTUDY_Y=0
DOANALYSISPbPb_FIT_Y=0
DOANALYSISPbPb_MCSTUDY_Y=0
DORAA_Y=0

#CENTRALITY RAA
DOANALYSISPP_FIT_INC=0
DOANALYSISPP_MCSTUDY_INC=0
DOANALYSISPbPb_FIT_CENT=0
DOANALYSISPbPb_MCSTUDY_CENT=0
DORAA_CENT=0

DOANALYSISPP_MCSTUDY_FINE=0
DOANALYSISPP_EFFFIT=0
DOANALYSISPP_FIT_INC_EFFCOR=0
DOANALYSISPbPb_MCSTUDY_FINE_HIBIN=0
DOANALYSISPbPb_EFFFIT=0
DOANALYSISPbPb_FIT_CENT_EFFCOR=0
DORAA_CENT_EFFCOR=0
DOANALYSISPP_FIT_EFFCOR=0
DOANALYSISPP_CROSS_EFFCOR=0

#systematic section
DOCOMPARE=0
DOSAVEHISTPP=0
DOSAVEHISTPbPb=0
DOVARIATION=0
DOClosure=0
SAVEMVAPP=0
SAVEMVAPbPb=0
PLOTMVA=0


## PP MONTE CARLO
#Bs0//
INPUTMCPP="/data/cdzn/Bsmeson2017/MC/Bntuple/pp/loop_Bs0_pthat5_bstojpsiphi_pp.root" 
#INPUTMCPP="/afs/cern.ch/work/c/cdozen/UP_BFINDER/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Bntuple/loop_MC_pp.root" 

#Bs0//
INPUTDATAPP="/data/wangj/Data2015/Bntuple/pp/ntB_EvtBase_20160420_BfinderData_pp_20160419_bPt0jpsiPt0tkPt0p5.root"

## PbPb MONTE CARLO
INPUTMCPbPb="/data/cdzn/Bsmeson2017/MC/Bntuple/PbPb/loop_Bs0_PbPb_MC_25072017_pthat10.root"
##PbPb data
INPUTDATAPbPb="/data/wangj/Data2015/Bntuple/PbPb/Bntuple_BfinderData_PbPb_20160406_bPt5jpsiPt0tkPt0p8_BpB0BsX_skimhlt.root"
## ANALYSIS PP TRIGGERED
#Bs0 
FONLLDATINPUT="pp_Bs_new_y2p4" #"pp_Bs1010101_5p03TeV_y2p4"  #fo_pp_Bs5_1to300_5p03TeV_y2p4.txt
FONLLOUTPUTFILE="ROOTfiles/fonllOutput_pp_Bs_new_y2p4.root"
OUTPUTFILERAA="ROOTfiles/outputRAA.root"

LABELPP="pp"
#LUMIPP=25.57 pre HardProbe2016
#B+
#LUMIPP=27.4
#Bs0#
LUMIPP=27.748
#25.8*0.991
#LUMIPP=27.45
#27.7*0.991
ISMCPP=0
ISDOWEIGHTPP=0
#Bs0#
SELGENPP="TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0"
#B+
#SELGENPP="TMath::Abs(Gy)<2.4&&abs(GpdgId)==521&&GisSignal==1"
#Bs0#
SELGENPPACCPP="TMath::Abs(Gy)<2.4 && abs(GpdgId)==531 && GisSignal>0 && ((TMath::Abs(Gmu1eta)<1.2 && Gmu1pt>3.5) || (TMath::Abs(Gmu1eta)>1.2 && TMath::Abs(Gmu1eta)<2.1 && Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta))) || (TMath::Abs(Gmu1eta)>2.1 && TMath::Abs(Gmu1eta)<2.4 && Gmu1pt>1.8)) && ((TMath::Abs(Gmu2eta)<1.2 && Gmu2pt>3.5) || (TMath::Abs(Gmu2eta)>1.2 && TMath::Abs(Gmu2eta)<2.1 && Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta))) || (TMath::Abs(Gmu2eta)>2.1 && TMath::Abs(Gmu2eta)<2.4 && Gmu2pt>1.8)) && Gtk1pt>0.7 && Gtk2pt>0.7 && TMath::Abs(Gtk1eta)<2.4 && TMath::Abs(Gtk2eta)<2.4"

CUTPP="TMath::Abs(By)<2.4 && TMath::Abs(Bmumumass-3.096916)<0.15 && ((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1highPurity && Btrk2highPurity && Bmass>5 && Bmass<6 && Btrk1Pt>0.7 && Btrk2Pt>0.7 && Bchi2cl>1.32e-02 && (Bd0/Bd0Err)>2. && cos(Bdtheta)>2.60e-01 && Bmu1pt>1.5 && Bmu2pt>1.5 && Blxy>0.025 && abs(Btktkmass-1.019455)<1.55e-02"



##BASECUTPP="abs(PVz)<15&&TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&& ((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && abs(By) < 2.4 && Btrk1highPurity && abs(Btrk1Eta)<2.4" # USED FOR MVA PREFILTER, UPDATE WITH CUTPP
RECOONLYPP=$CUTPP
TRGPP="(HLT_HIL1DoubleMu0_v1)"
TRGPPMC="(HLT_HIL1DoubleMu0ForPPRef_v1)"
#TRGPPMC="(1)"
OUTPUTFILEPP="ROOTfiles/hPtSpectrumBplusPP.root"
PREFIXPP="ROOTfiles/hPtSpectrumBplusPP" #IF YOU CHANGE OUTPUTFILEPP, CHANGE PREFIX PP ACCORDINGLY
OUTPUTFILEMCSTUDYPP="ROOTfiles/MCstudiesPP.root"
OUTPUTFILEPlotPP="ROOTfiles/CrossSectionPP.root"
OUTPUTFILEPPDATA="ROOTfiles/data_pp.root"
OUTPUTFILEPPMC="ROOTfiles/mc_pp.root"

#SETTING for NP fit
INPUTMCPP_NP="/data/cdzn/Bsmeson2017/NPfiles/loop_BJpsiMM_pp_NP.root"
#CUTPP_NP="abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&& ((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1Pt>1. && abs(Beta) < 2.4 && Bchi2cl > 0.005 && Btrk1highPurity && abs(Btrk1Eta)<2.4 && cos(Bdtheta) > 0.2 && (BsvpvDistance/BsvpvDisErr)>4.&&Bgen!=23333"
CUTPP_NP="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8))&& ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1highPurity&&Bmass>5&&Bmass<6&&Btrk1Pt>0.7&&Btrk2Pt>0.7&&Bchi2cl>1.32e-02&&(Bd0/Bd0Err)>2.&&cos(Bdtheta)>2.60e-01&&Bmu1pt>1.5&&Bmu2pt>1.5&&Blxy>0.025&&abs(Btktkmass-1.019455)<1.55e-02&&Bgen!=23333"
OUTPUTFILEPP_NP="ROOTfiles/NPFitPP.root"
#NPFIT_PP="TMath::Erf((x-5.144224e+00)/-1.322908e-02)+1"
#NPFIT_PP="213.355334*TMath::Erf((x-5.139684)/-0.049768) + 213.355334 + 14.620639*(0.856020*Gaus(x,5.351676,0.198591)/(sqrt(2*3.14159)*0.198591)+(1-0.856020)*Gaus(x,5.351676,0.035974)/(sqrt(2*3.14159)*0.035974))"
NPFIT_PP="3.12764e1*Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*Gaus(x,5.33166,1.5204e-1)+7.18255e1*TMath::Erf(-(x-5.14397)/6.43194e-2) + 7.18255e1"
#NPFIT_PP="3.12764e1*Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2) + 2.11124e2"

if [ $DOANALYSISPP_FONLL -eq 1 ]; then      
g++ Bplusdsigmadpt.cc $(root-config --cflags --libs) -g -o Bplusdsigmadpt.exe 
./Bplusdsigmadpt.exe "$FONLLDATINPUT"  "$FONLLOUTPUTFILE" "$LABELPP"
rm Bplusdsigmadpt.exe
fi 

if [ $DOANALYSISPP_FITNP -eq 1 ]; then      
g++ fitNP.C $(root-config --cflags --libs) -g -o fitNP.exe 
./fitNP.exe 0 "$INPUTMCPP_NP"  "$INPUTMCPP_NP"  "1" "$CUTPP_NP"   "$SELGENPP"   1   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTFILEPP_NP"
rm fitNP.exe
fi 

if [ $DOANALYSISPP_FIT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 "$INPUTDATAPP"  "$INPUTMCPP"  "$TRGPP" "$CUTPP"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTFILEPP" "$NPFIT_PP" 0
rm fitB.exe
fi 

if [ $DOANALYSISPP_MCSTUDY -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe  0 "$INPUTMCPP"  "$SELGENPP" "$SELGENPPACCPP"  "$RECOONLYPP" "$CUTPP&&$TRGPPMC"  "$LABELPP" "$OUTPUTFILEMCSTUDYPP" "$ISDOWEIGHTPP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
./CrossSectionRatio.exe "$FONLLOUTPUTFILE"  "$OUTPUTFILEPP" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" 0 "$LABELPP" 0 "$LUMIPP"
rm CrossSectionRatio.exe
fi

LABELPbPb="PbPb"

#LUMIPbPb=15.5665
#LUMIPbPb=15.17
#350.68(ub-1)*208*208/1000000=15.17

#N_MB = 148356846 lumi_MB_BrilCalc = 7.213*3 lumi_dimuon_BrilCalc = 345.1 TAA = 392.4/(70.*1e9)
#148356846*345.1/(7.213*3) = 2.366003e+09, 2.366003e+09*392.4/(70.*1e9) = 1.326314e+01

LUMIPbPb=13.18
#3.153359e+09*345.1/467.112 = 2329685794.627413, 2329685794.627413*392.4/(70.*1e9) = 13.06
#13.06/0.99*0.996

NMBEVT=2329685794.627413
ISMCPbPb=0
ISDOWEIGHTPbPb=0
SELGENPbPb="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0"
SELGENPbPbACCPbPb="TMath::Abs(Gy)<2.4 && abs(GpdgId)==531 && GisSignal>0 && ((TMath::Abs(Gmu1eta)<1.2 && Gmu1pt>3.5) || (TMath::Abs(Gmu1eta)>1.2 && TMath::Abs(Gmu1eta)<2.1 && Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta))) || (TMath::Abs(Gmu1eta)>2.1 && TMath::Abs(Gmu1eta)<2.4 && Gmu1pt>1.8)) && ((TMath::Abs(Gmu2eta)<1.2 && Gmu2pt>3.5) || (TMath::Abs(Gmu2eta)>1.2 && TMath::Abs(Gmu2eta)<2.1 && Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta))) || (TMath::Abs(Gmu2eta)>2.1 && TMath::Abs(Gmu2eta)<2.4 && Gmu2pt>1.8)) && Gtk1pt>1.5 && Gtk2pt>1.5 && TMath::Abs(Gtk1eta)<2.4 && TMath::Abs(Gtk2eta)<2.4"
#SELGENPbPbACCPbPb="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal==6&&((TMath::Abs(Gmu1eta)<1.2 && Gmu1pt>3.5) || (TMath::Abs(Gmu1eta)>1.2 && TMath::Abs(Gmu1eta)<2.1 && Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta))) || (TMath::Abs(Gmu1eta)>2.1 && TMath::Abs(Gmu1eta)<2.4 && Gmu1pt>1.8)) && ((TMath::Abs(Gmu2eta)<1.2 && Gmu2pt>3.5) || (TMath::Abs(Gmu2eta)>1.2 && TMath::Abs(Gmu2eta)<2.1 && Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta))) || (TMath::Abs(Gmu2eta)>2.1 && TMath::Abs(Gmu2eta)<2.4 && Gmu2pt>1.8)) && Gtk1pt>0.5 && TMath::Abs(Gtk1eta)<2.4"
RECOONLYPbPb="1"

#CUTPbPb="TMath::Abs(By)<2.4 && TMath::Abs(Bmumumass-3.096916)<0.15 && ((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1highPurity && Btrk2highPurity && Bmass>5 && Bmass<6 && Btrk1Pt>1.63 && Btrk2Pt>1.63 && Bchi2cl>0.0057 && (Bd0/Bd0Err)>5. && cos(Bdtheta)>0.993 && Bmu1pt>1.5 && Bmu2pt>1.5 && TMath::Abs(Btktkmass-1.019455)<0.05 && Blxy>0.0337"

CUTPbPb="TMath::Abs(By)<2.4&&abs(Bmumumass-3.09691 6)<0.15&&Bmass>5.&&Bmass<6.&&Btrk1Pt>1.63&&Btrk2Pt>1.63&& Bchi2cl>0.0057&&(Bd0/Bd0Err)>5.&&cos(Bdtheta)>0.993&&Bmu1pt>1.5&&Bmu2pt>1.5&&TMath::Abs(Btktkmass-1.019455)<0.05&&Blxy>0.0337";
TRGPbPb="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)"
#TRGPbPbMC="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)"
TRGPbPbMC="(1)"
OUTPUTFILEPbPb="ROOTfiles/hPtSpectrumBplusPbPb.root"
PREFIXPbPb="ROOTfiles/hPtSpectrumBplusPbPb" #IF YOU CHANGE OUTPUTFILEPbPb, CHANGE PREFIXPbPb ACCORDINGLY
OUTPUTFILEMCSTUDYPbPb="ROOTfiles/MCstudiesPbPb.root"
OUTPUTFILEPlotPbPb="ROOTfiles/CrossSectionPbPb.root"
OUTPUTFILEPbPbDATA="ROOTfiles/data_PbPb.root"
OUTPUTFILEPbPbMC="ROOTfiles/mc_PbPb.root"

#SETTING for NP fit
INPUTMCPbPb_NP="/data/cdzn/Bsmeson2017/NPfiles/loop_BJpsiMM_PbPb_12_15.root"
CUTPbPb_NP="TMath::Abs(By)<2.4&&abs(Bmumumass-3.09691 6)<0.15&&Bmass>5.&&Bmass<6.&&Btrk1Pt>1.63&&Btrk2Pt>1.63&& Bchi2cl>0.0057&&(Bd0/Bd0Err)>5.&&cos(Bdtheta)>0.993&&Bmu1pt>1.5&&Bmu2pt>1.5&&TMath::Abs(Btktkmass-1.019455)<0.05&&Blxy>0.0337&&Bgen!=23333";
#CUTPbPb_NP="pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&abs(PVz)<15&&TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && ( ((BsvpvDistance/BsvpvDisErr)>6. && Bmumupt>3 && Btrk1Pt>1. && Bpt > 10 && Bpt < 15 && abs(By) < 2.4 && Bchi2cl > 0.2 && cos(Bdtheta) > 0.2 && Btrk1highPurity && abs(Btrk1Eta)<2.4) || ((BsvpvDistance/BsvpvDisErr)>5. && Bmumupt>3 && Btrk1Pt>1.5 && Bpt > 15 && Bpt < 20 && abs(By) < 2.4 && Bchi2cl > 0.005 && cos(Bdtheta) > 0.2 && Btrk1highPurity && abs(Btrk1Eta)<2.4) || ((BsvpvDistance/BsvpvDisErr)>4. && Bmumupt>3 && Btrk1Pt>1.5 && Bpt > 20 && Bpt < 50 && abs(By) < 2.4 && Bchi2cl > 0.005 && cos(Bdtheta) > 0.2 && Btrk1highPurity && abs(Btrk1Eta)<2.4) || ((BsvpvDistance/BsvpvDisErr)>4. && Bmumupt>3 && Btrk1Pt>1.5 && Bpt > 50 && Bpt < 100 && abs(By) < 2.4 && Bchi2cl > 0.005 && cos(Bdtheta) > 0.2 && Btrk1highPurity && abs(Btrk1Eta)<2.4))&&Bgen!=23333"
OUTPUTFILEPbPb_NP="ROOTfiles/NPFitPbPb.root"
#NPFIT_PbPb="3.39711e1*Gaus(x,5.35002e0,3.87952e-2)*(x<5.35002e0)+(x>=5.35002e0)*3.39711e1*Gaus(x,5.35002e0,1.14232e-1)+2.16376e2*TMath::Erf(-(x-5.14189)/8.66243e-2) + 2.16376e2"
NPFIT_PbPb="Gaus(x,5.36800e+00,5.77122e-02)/(sqrt(2*3.14159)*abs(5.77122e-02))"
if [ $DOANALYSISPbPb_FITNP -eq 1 ]; then      
g++ fitNP.C $(root-config --cflags --libs) -g -o fitNP.exe 
./fitNP.exe 0 "$INPUTMCPbPb_NP"  "$INPUTMCPbPb_NP"  "1" "$CUTPbPb_NP"   "$SELGENPbPb"   1   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPb_NP"
rm fitNP.exe
fi 

if [ $DOANALYSISPbPb_FIT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 "$INPUTDATAPbPb"  "$INPUTMCPbPb"  "$TRGPbPb" "$CUTPbPb"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPb" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi 

if [ $DOANALYSISPbPb_MCSTUDY -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 1 "$INPUTMCPbPb"  "$SELGENPbPb" "$SELGENPbPbACCPbPb"  "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC"  "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPbPb_CROSS -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
./CrossSectionRatio.exe "$FONLLOUTPUTFILE"  "$OUTPUTFILEPbPb" "$OUTPUTFILEMCSTUDYPbPb" "$OUTPUTFILEPlotPbPb" 0 "$LABELPbPb" 0 "$LUMIPbPb"
rm CrossSectionRatio.exe
fi

if [ $DORAA -eq 1 ]; then
g++ NuclearModificationFactor.C $(root-config --cflags --libs) -g -o NuclearModificationFactor.exe
./NuclearModificationFactor.exe "$OUTPUTFILEPlotPP" "$OUTPUTFILEPlotPbPb"  "$LABELPbPb" "$OUTPUTFILERAA" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm NuclearModificationFactor.exe
fi


#######
#CENTRALITY RAPIDITY
#######
OUTPUTFILEPP_Y="ROOTfiles/hPtSpectrumBplusPP_Y.root"
if [ $DOANALYSISPP_FIT_Y -eq 1 ]; then
g++ fitBY.C $(root-config --cflags --libs) -g -o fitBY.exe
./fitBY.exe 0 "$INPUTDATAPP"  "$INPUTMCPP"  "$TRGPP" "$CUTPP&&Bpt>7"  "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTFILEPP_Y" "$NPFIT_PP" 0
rm fitBY.exe
fi

OUTPUTFILEPbPb_Y="ROOTfiles/hPtSpectrumBplusPbPb_Y.root"
if [ $DOANALYSISPbPb_FIT_Y -eq 1 ]; then      
g++ fitBY.C $(root-config --cflags --libs) -g -o fitBY.exe 
./fitBY.exe 1 "$INPUTDATAPbPb"  "$INPUTMCPbPb"  "$TRGPbPb" "$CUTPbPb&&Bpt>7"  "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPb_Y" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitBY.exe
fi 
pwd
OUTPUTFILEMCSTUDYPP_Y="ROOTfiles/MCstudiesPP_Y.root"
if [ $DOANALYSISPP_MCSTUDY_Y -eq 1 ]; then
g++ MCefficiencyY.C $(root-config --cflags --libs) -g -o MCefficiencyY.exe
./MCefficiencyY.exe  0 "$INPUTMCPP"  "$SELGENPP&&Gpt>7&&Gpt<50" "$SELGENPPACCPP&&Gpt>7&&Gpt<50"  "$RECOONLYPP" "$CUTPP&&$TRGPPMC"  "$LABELPP" "$OUTPUTFILEMCSTUDYPP_Y" "$ISDOWEIGHTPP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiencyY.exe
fi

OUTPUTFILEMCSTUDYPbPb_Y="ROOTfiles/MCstudiesPbPb_Y.root"
if [ $DOANALYSISPbPb_MCSTUDY_Y -eq 1 ]; then
g++ MCefficiencyY.C $(root-config --cflags --libs) -g -o MCefficiencyY.exe
./MCefficiencyY.exe 1 "$INPUTMCPbPb"  "$SELGENPbPb&&Gpt>7&&Gpt<50" "$SELGENPbPbACCPbPb&&Gpt>7&&Gpt<50"  "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC"  "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb_Y" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiencyY.exe
fi

OUTPUTFILERAA_Y="ROOTfiles/outputRAA_Y.root"
if [ $DORAA_Y -eq 1 ]; then
g++ NuclearModificationFactorY.C $(root-config --cflags --libs) -g -o NuclearModificationFactorY.exe
./NuclearModificationFactorY.exe "$OUTPUTFILEPP_Y" "$OUTPUTFILEPbPb_Y" "$OUTPUTFILEMCSTUDYPP_Y" "$OUTPUTFILEMCSTUDYPbPb_Y" "$LABELPbPb" "$OUTPUTFILERAA_Y" 0 "$LUMIPP" "$LUMIPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm NuclearModificationFactorY.exe
fi

#######
#CENTRALITY RAA
#######

OUTPUTFILEPP_INC="ROOTfiles/hPtSpectrumBplusPP_INC.root"
if [ $DOANALYSISPP_FIT_INC -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 "$INPUTDATAPP"  "$INPUTMCPP"  "$TRGPP" "$CUTPP"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "ppInc"  "$OUTPUTFILEPP_INC" "$NPFIT_PP" 0
rm fitB.exe
fi 

OUTPUTFILEMCSTUDYPP_INC="ROOTfiles/MCstudiesPP_INC.root"
if [ $DOANALYSISPP_MCSTUDY_INC -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe  0 "$INPUTMCPP"  "$SELGENPP" "$SELGENPPACCPP"  "$RECOONLYPP" "$CUTPP&&$TRGPPMC"  "ppInc" "$OUTPUTFILEMCSTUDYPP_INC" "$ISDOWEIGHTPP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

OUTPUTFILEPbPb_CENT="ROOTfiles/hPtSpectrumBplusPbPb_CENT.root"
if [ $DOANALYSISPbPb_FIT_CENT -eq 1 ]; then
g++ fitBCent.C $(root-config --cflags --libs) -g -o fitBCent.exe
./fitBCent.exe 1 "$INPUTDATAPbPb"  "$INPUTMCPbPb"  "$TRGPbPb" "$CUTPbPb&&Bpt>7"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPb_CENT" "$NPFIT_PbPb" 0
rm fitBCent.exe
fi

OUTPUTFILEMCSTUDYPbPb_CENT="ROOTfiles/MCstudiesPbPb_CENT.root"
if [ $DOANALYSISPbPb_MCSTUDY_CENT -eq 1 ]; then      
g++ MCefficiencyCent.C $(root-config --cflags --libs) -g -o MCefficiencyCent.exe 
#./MCefficiencyCent.exe 1 "$INPUTMCPbPb"  "$SELGENPbPb&&Gpt>7&&Gpt<50" "$SELGENPbPbACCPbPb&&Gpt>7&&Gpt<50"  "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC"  "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb_CENT" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
./MCefficiencyCent.exe 1 "$INPUTMCPbPb"  "$SELGENPbPb&&Gpt>7&&Gpt<50" "$SELGENPbPbACCPbPb&&Gpt>7&&Gpt<50"  "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC&&Bpt>7"  "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb_CENT" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiencyCent.exe
fi

OUTPUTFILERAA_CENT="ROOTfiles/outputRAA_CENT.root"
if [ $DORAA_CENT -eq 1 ]; then
g++ NuclearModificationFactorCent.C $(root-config --cflags --libs) -g -o NuclearModificationFactorCent.exe
./NuclearModificationFactorCent.exe "$OUTPUTFILEPP_INC" "$OUTPUTFILEPbPb_CENT" "$OUTPUTFILEMCSTUDYPP_INC" "$OUTPUTFILEMCSTUDYPbPb_CENT" "$LABELPbPb" "$OUTPUTFILERAA_CENT" 0 "$LUMIPP" "$NMBEVT" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm NuclearModificationFactorCent.exe
fi

OUTPUTFILEMCSTUDYPP_FINE="ROOTfiles/MCstudiesPP_Fine.root"
if [ $DOANALYSISPP_MCSTUDY_FINE -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe
./MCefficiency.exe  0 "$INPUTMCPP"  "$SELGENPP" "$SELGENPPACCPP"  "$RECOONLYPP" "$CUTPP&&$TRGPPMC"  "ppFine" "$OUTPUTFILEMCSTUDYPP_FINE" "$ISDOWEIGHTPP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_EFFFIT -eq 1 ]; then
g++ EfficiencyFit.C $(root-config --cflags --libs) -g -o EfficiencyFit.exe
./EfficiencyFit.exe  "$OUTPUTFILEMCSTUDYPP_FINE" "PP_Fine"
rm EfficiencyFit.exe
fi

OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN0to20="ROOTfiles/MCstudiesPbPb_Fine_hiBin0to20.root"
OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN20to60="ROOTfiles/MCstudiesPbPb_Fine_hiBin20to60.root"
OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN60to100="ROOTfiles/MCstudiesPbPb_Fine_hiBin60to100.root"
OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN100to200="ROOTfiles/MCstudiesPbPb_Fine_hiBin100to200.root"
if [ $DOANALYSISPbPb_MCSTUDY_FINE_HIBIN -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe
CentSel="hiBin>=0&&hiBin<20"
./MCefficiency.exe 1 "$INPUTMCPbPb"  "$SELGENPbPb&&$CentSel" "$SELGENPbPbACCPbPb&&$CentSel"  "$RECOONLYPbPb&&$CentSel" "$CUTPbPb&&$TRGPbPbMC&&$CentSel"  "PbPbFine_hiBin0to20" "$OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN0to20" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
CentSel="hiBin>=20&&hiBin<60"
./MCefficiency.exe 1 "$INPUTMCPbPb"  "$SELGENPbPb&&$CentSel" "$SELGENPbPbACCPbPb&&$CentSel"  "$RECOONLYPbPb&&$CentSel" "$CUTPbPb&&$TRGPbPbMC&&$CentSel"  "PbPbFine_hiBin20to60" "$OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN20to60" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
CentSel="hiBin>=60&&hiBin<100"
./MCefficiency.exe 1 "$INPUTMCPbPb"  "$SELGENPbPb&&$CentSel" "$SELGENPbPbACCPbPb&&$CentSel"  "$RECOONLYPbPb&&$CentSel" "$CUTPbPb&&$TRGPbPbMC&&$CentSel"  "PbPbFine_hiBin60to100" "$OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN60to100" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
CentSel="hiBin>=100&&hiBin<=200"
./MCefficiency.exe 1 "$INPUTMCPbPb"  "$SELGENPbPb&&$CentSel" "$SELGENPbPbACCPbPb&&$CentSel"  "$RECOONLYPbPb&&$CentSel" "$CUTPbPb&&$TRGPbPbMC&&$CentSel"  "PbPbFine_hiBin100to200" "$OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN100to200" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPbPb_EFFFIT -eq 1 ]; then
g++ EfficiencyFit.C $(root-config --cflags --libs) -g -o EfficiencyFit.exe
./EfficiencyFit.exe  "$OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN0to20" "PbPb_Fine_HIBIN0to20"
./EfficiencyFit.exe  "$OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN20to60" "PbPb_Fine_HIBIN20to60"
./EfficiencyFit.exe  "$OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN60to100" "PbPb_Fine_HIBIN60to100"
./EfficiencyFit.exe  "$OUTPUTFILEMCSTUDYPbPb_FINE_HIBIN100to200" "PbPb_Fine_HIBIN100to200"
rm EfficiencyFit.exe
fi

OUTPUTFILEPP_INC_EFFCOR="ROOTfiles/hPtSpectrumBplusPP_INC_EFFCOR.root"
if [ $DOANALYSISPP_FIT_INC_EFFCOR -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 "$INPUTDATAPP"  "$INPUTMCPP"  "$TRGPP" "$CUTPP"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "ppInc"  "$OUTPUTFILEPP_INC_EFFCOR" "$NPFIT_PP" 1
rm fitB.exe
fi 

OUTPUTFILEPbPb_CENT_EFFCOR="ROOTfiles/hPtSpectrumBplusPbPb_CENT_EFFCOR.root"
if [ $DOANALYSISPbPb_FIT_CENT_EFFCOR -eq 1 ]; then
g++ fitBCent.C $(root-config --cflags --libs) -g -o fitBCent.exe
./fitBCent.exe 1 "$INPUTDATAPbPb"  "$INPUTMCPbPb"  "$TRGPbPb" "$CUTPbPb&&Bpt>7"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPb_CENT_EFFCOR" "$NPFIT_PbPb" 1
rm fitBCent.exe
fi

OUTPUTFILERAA_CENT_EFFCOR="ROOTfiles/outputRAA_CENT_EFFCOR.root"
if [ $DORAA_CENT_EFFCOR -eq 1 ]; then
g++ NuclearModificationFactorCent.C $(root-config --cflags --libs) -g -o NuclearModificationFactorCent.exe
./NuclearModificationFactorCent.exe "$OUTPUTFILEPP_INC_EFFCOR" "$OUTPUTFILEPbPb_CENT_EFFCOR" "$OUTPUTFILEMCSTUDYPP_INC" "$OUTPUTFILEMCSTUDYPbPb_CENT" "$LABELPbPb" "$OUTPUTFILERAA_CENT_EFFCOR" 1 "$LUMIPP" "$NMBEVT" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm NuclearModificationFactorCent.exe
fi

###pp fit EFFCOR test
OUTPUTFILEPP_EFFCOR="ROOTfiles/hPtSpectrumBplusPP_EFFCOR.root"
if [ $DOANALYSISPP_FIT_EFFCOR -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 "$INPUTDATAPP"  "$INPUTMCPP"  "$TRGPP" "$CUTPP"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTFILEPP_EFFCOR" "$NPFIT_PP" 1
rm fitB.exe
fi 

OUTPUTFILEPlotPP_EFFCOR="ROOTfiles/CrossSectionPP_EFFCOR.root"
if [ $DOANALYSISPP_CROSS_EFFCOR -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
./CrossSectionRatio.exe "$FONLLOUTPUTFILE"  "$OUTPUTFILEPP_EFFCOR" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP_EFFCOR" 0 "$LABELPP" 1 "$LUMIPP"
rm CrossSectionRatio.exe
fi

#MEAN COMPARISON

if [ $DOCOMPARE -eq 1 ]; then
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 "$INPUTDATAPbPb"  "$INPUTMCPbPb"  "$TRGPbPb" "$CUTPbPb"   "$SELGENPbPb"   0   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPbDATA" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 "$INPUTMCPbPb"  "$INPUTMCPbPb"  "$TRGPbPbMC" "$CUTPbPb"   "$SELGENPbPb"   1   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPbMC" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 "$INPUTDATAPP"  "$INPUTMCPP"  "$TRGPP" "$CUTPP"   "$SELGENPP"   0   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTFILEPPDATA" "$NPFIT_PP" 0
rm fitB.exe

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 "$INPUTMCPP"  "$INPUTMCPP"  "$TRGPPMC" "$CUTPP"   "$SELGENPP"   1   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTFILEPPMC" "$NPFIT_PP" 0
rm fitB.exe

g++ comparison.C $(root-config --cflags --libs) -g -o comparison.exe 
./comparison.exe 
rm comparison.exe
fi


#FIT VARIATION

if [ $DOSAVEHISTPP -eq 1 ]; then
g++ savehisto.C $(root-config --cflags --libs) -g -o savehisto.exe 
./savehisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "$CUTPP" "$ISMCPP" "$ISDOWEIGHTPP" "$LABELPP"
rm savehisto.exe
fi

if [ $DOSAVEHISTPbPb -eq 1 ]; then
g++ savehisto.C $(root-config --cflags --libs) -g -o savehisto.exe 
./savehisto.exe "$INPUTDATAPbPb" "$INPUTMCPbPb" "$TRGPbPb" "$CUTPbPb" "$ISMCPbPb" "$ISDOWEIGHTPbPb" "$LABELPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm savehisto.exe
fi

if [ $DOVARIATION -eq 1 ]; then
g++ fitBvar.C $(root-config --cflags --libs) -g -o fitBvar.exe 
./fitBvar.exe "$LABELPP" "$PREFIXPP" "$OUTPUTFILEPP_NP"
rm fitBvar.exe

#g++ fitBvar.C $(root-config --cflags --libs) -g -o fitBvar.exe 
#./fitBvar.exe "$LABELPbPb" "$PREFIXPbPb" "$OUTPUTFILEPbPb_NP" "$CENTPbPbMIN" "$CENTPbPbMAX"
#rm fitBvar.exe
fi

# MVA COMPARISON

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
./fitBmva.exe "$LABELPP" "$PREFIXPP" "$OUTPUTFILEPP_NP"
rm fitBmva.exe

g++ fitBmva.C $(root-config --cflags --libs) -g -o fitBmva.exe 
CUTPP_NP="abs(PVz)<15&&TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&& ((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1Pt>1. && abs(Beta) < 2.4 && Bchi2cl > 0.005 && Btrk1highPurity && abs(Btrk1Eta)<2.4 && cos(Bdtheta) > 0.2 && (BsvpvDistance/BsvpvDisErr)>4.&&Bgen!=23333"
./fitBmva.exe "$LABELPbPb" "$PREFIXPbPb" "$OUTPUTFILEPbPb_NP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitBmva.exe
fi

if [ $DOClosure -eq 1 ]; then      

OUTPUTFILEPPMCClosure="ROOTfiles/hPtSpectrumBplusPPMCClosure.root"
LUMIPPMCClosure=1
ISMCPPMCClosure=1
ISDOWEIGHTPPMCClosure=0
TRGPPMCClosure="1"
LABELPPMCClosure="PPMCClosure"

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 "$INPUTMCPP"  "$INPUTMCPP"  "$TRGPPMCClosure" "$CUTPP"   "$SELGENPP"   "$ISMCPPMCClosure"   "$LUMIPPMCClosure"   "$ISDOWEIGHTPPMCClosure"   "$LABELPPMCClosure"  "$OUTPUTFILEPPMCClosure" "$NPFIT_PP" 0
g++ ClosureTest.C $(root-config --cflags --libs) -g -o ClosureTest.exe 
./ClosureTest.exe "$OUTPUTFILEPPMCClosure" "$LABELPP"

OUTPUTFILEPbPbMCClosure="ROOTfiles/hPtSpectrumBplusPbPbMCClosure.root"
LUMIPbPbMCClosure=1
ISMCPbPbMCClosure=1
ISDOWEIGHTPbPbMCClosure=0
TRGPbPbMCClosure="1"
LABELPbPbMCClosure="PbPbMCClosure"

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 "$INPUTMCPbPb"  "$INPUTMCPbPb"  "$TRGPbPbMCClosure" "$CUTPbPb"   "$SELGENPbPb"   "$ISMCPbPbMCClosure"   "$LUMIPbPbMCClosure"   "$ISDOWEIGHTPbPbMCClosure"   "$LABELPbPbMCClosure"  "$OUTPUTFILEPbPbMCClosure" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
g++ ClosureTest.C $(root-config --cflags --libs) -g -o ClosureTest.exe 
./ClosureTest.exe "$OUTPUTFILEPbPbMCClosure" "$LABELPbPb"

fi
