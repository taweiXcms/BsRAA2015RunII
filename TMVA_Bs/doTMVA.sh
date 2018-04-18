#!/bin/bash

DOTMVA=0
PRODMVAVALUE=0
DOMERGE=0
DOREADXML=1
PLOTROC=0
GETCUTVAL=0
EffB=0.00001
#
OUTPUTDIR="test"
## The file specify here is for merging, not for TMVA training which are specify in prefilter.h
inputMCs=(
"/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight.root"
"/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight.root"
)
#"/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_candWise_skimBpt15inf.root"
inputDatas=(
"/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs.root"
"/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged.root"
)
#"/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_candWise_skimBpt15inf.root"
if [ ! -d $OUTPUTDIR ]; then
    mkdir $OUTPUTDIR
fi

# if working on several ptbins, BDT.C need to be changed
PTBIN=(7 15 50)
#PTBIN=(7 15)
#PTBIN=(15 50)

RAA=(1. 1.)
COLSYST=('pp' 'PbPb')
isPbPb=(0 1)
#MVA=('CutsGA' 'CutsSA' 'BDT' 'MLP' 'DNN')
MVA=('BDT')
nvIni=0
nVAR=1

##
MVAStr=''
nPT=$((${#PTBIN[@]}-1))
nMVA=${#MVA[@]}
nCOL=${#COLSYST[@]}

k=0
while ((k<$nMVA-1))
do
	MVAStr=${MVAStr}${MVA[k]}','
    k=$(($k+1))
done
MVAStr=${MVAStr}${MVA[k]}
echo "MVA methods: "$MVAStr

FOLDERS=("myTMVA/ROOT" "tmvaVal/MVAfiles" "readxml/plots" "plotROC/plotsROC")
for i in ${FOLDERS[@]}
do
    if [ ! -d $i ]; then
        mkdir $i
    fi
done

# TMVAClassification.C #
v=$nvIni
if [ $DOTMVA -eq 1 ]; then
    while ((v<$nVAR))
	do
    	j=0
    	while ((j<$nCOL))
    	do
        	i=0
	        while ((i<$nPT))
    	    do
				cd myTMVA/
				echo "-- Processing pT bin: ${PTBIN[i]} - ${PTBIN[i+1]} GeV/c"
				root -l -b -q 'TMVAClassification.C++('${isPbPb[j]}','${PTBIN[i]}','${PTBIN[i+1]}','$(($v+1))',''"'$MVAStr'"'')'
				rm TMVAClassification_C.d TMVAClassification_C.so TMVAClassification_C_ACLiC_dict_rdict.pcm
				k=0
				while ((k<$nMVA))
				do
					mv dataset/weights/TMVAClassification_${MVA[k]}.weights.xml dataset/weights/TMVA_${MVA[k]}_${COLSYST[j]}_${PTBIN[i]}_${PTBIN[i+1]}_varStage$(($v+1)).weights.xml
					mv dataset/weights/TMVAClassification_${MVA[k]}.class.C dataset/weights/TMVA_${MVA[k]}_${COLSYST[j]}_${PTBIN[i]}_${PTBIN[i+1]}_varStage$(($v+1)).class.C
					k=$(($k+1))
				done
				cd ..
				i=$(($i+1))    
			done
			j=$(($j+1))
    	done    
		v=$(($v+1))
    done
fi

# ProdMVAVal.cc
if [ $PRODMVAVALUE -eq 1 ]; then
    cd tmvaVal
    j=0
    while ((j<$nCOL))
    do
        inputMC=${inputMCs[${isPbPb[j]}]}
        inputData=${inputDatas[${isPbPb[j]}]}
        i=0
        while ((i<$nPT))
        do
            k=0
            while ((k<$nMVA))
            do
	            s=nvIni
	            while ((s<$nVAR))
    	        do
                    root -l -b -q 'ProdMVAVal.cc++('\"${COLSYST[j]}\"','${PTBIN[i]}','${PTBIN[i+1]}','\"${MVA[k]}\"','$(($s+1))',"'$inputMC'","'$inputData'")'
                    rm ProdMVAVal_cc_ACLiC_dict_rdict.pcm ProdMVAVal_cc.d ProdMVAVal_cc.so
#                    root -l -b -q 'ProdMVAVal_candWise.cc++('\"${COLSYST[j]}\"','${PTBIN[i]}','${PTBIN[i+1]}','\"${MVA[k]}\"','$(($s+1))',"'$inputMC'","'$inputData'")'
#                    rm ProdMVAVal_candWise_cc_ACLiC_dict_rdict.pcm ProdMVAVal_candWise_cc.d ProdMVAVal_candWise_cc.so
        	        s=$(($s+1))
	            done
                k=$(($k+1))
            done
            i=$(($i+1))
        done
        j=$(($j+1))
    done
    cd ../
fi

# mergeBDT.C 
if [ $DOMERGE -eq 1 ]; then
	cd tmvaVal/MVAfiles 
	j=0
	while ((j<$nCOL))
	do
		outputMC=`echo $inputMC | awk -F'/' '{ print $NF }' | sed s/.root/_BDT${PTBIN[0]}to${PTBIN[$nPT]}.root/g`
		outputData=`echo $inputData | awk -F'/' '{ print $NF }' | sed s/.root/_BDT${PTBIN[0]}to${PTBIN[$nPT]}.root/g`
		outputMC="${OUTPUTDIR}/${outputMC}"
		outputData="${OUTPUTDIR}/${outputData}"
		inputMC=${inputMCs[${isPbPb[j]}]}
		inputData=${inputDatas[${isPbPb[j]}]}
	    if [ -f $outputMC ]; then
	        echo "  Error: Targed merged file exists: $outputMC"
	    else
	        hadd ../../$outputMC $inputMC *_${COLSYST[j]}_*_varStage*_MC.root 
	    fi
	    if [ -f $outputData ]; then
	        echo "  Error: Targed merged file exists: $outputData"
	    else
	        hadd ../../$outputData $inputData *_${COLSYST[j]}_*_varStage*_DATA.root
	    fi
	    j=$(($j+1))
	done
	cd -
fi

# readxml.cc 
if [ $DOREADXML -eq 1 ]; then
	cd readxml/
	j=0
	while ((j<$nCOL))
	do
		inputMC=${inputMCs[${isPbPb[j]}]}
		inputData=${inputDatas[${isPbPb[j]}]}
	    i=0
	    while ((i<$nPT))
	    do
#            root -b -q "calRatio.cc++("\"${inputMC}\"","\"${inputData}\"","${isPbPb[j]}","\"${MVA[k]}\"","${PTBIN[i]}","${PTBIN[i+1]}","${RAA[i]}","\"${COLSYST[j]}_pT_${PTBIN[i]}_${PTBIN[i+1]}.h\"")"
#            rm calRatio_cc.d calRatio_cc.so calRatio_cc_ACLiC_dict_rdict.pcm
			cp ${COLSYST[j]}"_pT_"${PTBIN[i]}"_"${PTBIN[i+1]}".h" pred_temp.h
	        k=0
	        while ((k<$nMVA))
	        do
	            s=nvIni
	            while ((s<$nVAR))
		        do
		            root -b -q "readxml.cc++("${isPbPb[j]}","\"${MVA[k]}\"","$(($s+1))","${PTBIN[i]}","${PTBIN[i+1]}","${RAA[i]}")"
                    rm readxml_cc.d readxml_cc.so readxml_cc_ACLiC_dict_rdict.pcm
	    	        s=$(($s+1))
	            done
	            k=$(($k+1))
	        done
	        i=$(($i+1))
	    done
	    j=$(($j+1))
	done
	cd -
fi

# getCutGivenEffB.cc
if [ $GETCUTVAL -eq 1 ]; then
	cd plotROC
	j=0
	while ((j<$nCOL))
	do
	    i=0
	    while ((i<$nPT))
	    do
	        k=0
	        while ((k<$nMVA))
	        do
	            s=nvIni
	            while ((s<$nVAR))
		        do
                	root -l -b -q 'getCutGivenEffB.cc++('\"${MVA[k]}\"','\"${COLSYST[j]}\"','${PTBIN[i]}','${PTBIN[i+1]}','$(($s+1))','$EffB')'
    	            rm getCutGivenEffB_cc.d getCutGivenEffB_cc.so getCutGivenEffB_cc_ACLiC_dict_rdict.pcm
	    	        s=$(($s+1))
	            done
	            k=$(($k+1))
	        done
	        i=$(($i+1))
	    done
	    j=$(($j+1))
	done
	cd -	
fi

# plotROC_MethodWise.cc and plotROC_StageWise.cc
if [ $PLOTROC -eq 1 ]; then
	cd plotROC
	j=0
	while ((j<$nCOL))
	do
    	i=0
		while ((i<$nPT))
    	do
			k=0
			while ((k<$nMVA))
			do
				root -l -b -q 'plotROC_MethodWise.cc++('\"${MVA[k]}\"','\"${COLSYST[j]}\"','${PTBIN[i]}','${PTBIN[i+1]}','${nvIni}','${nVAR}','0')'
				root -l -b -q 'plotROC_MethodWise.cc++('\"${MVA[k]}\"','\"${COLSYST[j]}\"','${PTBIN[i]}','${PTBIN[i+1]}','${nvIni}','${nVAR}','1')'
				rm plotROC_MethodWise_cc_ACLiC_dict_rdict.pcm  plotROC_MethodWise_cc.d  plotROC_MethodWise_cc.so
			    k=$(($k+1))
			done
			s=nvIni
			while ((s<$nVAR))
			do
				root -l -b -q 'plotROC_StageWise.cc++('\"${MVAStr}\"','\"${COLSYST[j]}\"','${PTBIN[i]}','${PTBIN[i+1]}','$(($s+1))','0')'
				root -l -b -q 'plotROC_StageWise.cc++('\"${MVAStr}\"','\"${COLSYST[j]}\"','${PTBIN[i]}','${PTBIN[i+1]}','$(($s+1))','1')'
				rm plotROC_StageWise_cc_ACLiC_dict_rdict.pcm  plotROC_StageWise_cc.d  plotROC_StageWise_cc.so
			    s=$(($s+1))
			done
		    i=$(($i+1))
		done
		j=$(($j+1))
	done
	cd ../
fi
