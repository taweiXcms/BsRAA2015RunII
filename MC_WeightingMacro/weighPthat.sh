#!/bin/bash

#BtoD MC
sed '1iconst int nBins=6; float pthatBin[nBins]={0,5,10,15,30,50}; float ptBin[nBins]={0,0,0,0,0,0}; float crosssec[nBins+1]={1.448e+07, 1.421e+07, 5.230e+06, 1.803e+06, 2.005e+05, 3.143e+04}; int genSignal[1]={6};' weighPthat.C > weighPthat_tmp.C ## new MC
INPUTFILE="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs.root"
OUTPUTFILE="Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight.root"
#INPUTFILE="/afs/lns.mit.edu/user/tawei/scratch/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs.root"
#OUTPUTFILE="Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight.root"

###

cp "$INPUTFILE" "$OUTPUTFILE"
g++ weighPthat_tmp.C $(root-config --cflags --libs) -g -o weighPthat_tmp.exe 
./weighPthat_tmp.exe "$INPUTFILE" "$OUTPUTFILE"
rm weighPthat_tmp.exe

rm weighPthat_tmp.C
