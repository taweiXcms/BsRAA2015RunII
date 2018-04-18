sed 's/BDTStage1_pt10to15/BDTStage1_pt7to15/g' fitB.C > tmp
mv tmp fitB.C
sed 's/BDTStage1_pt10to15/BDTStage1_pt7to15/g' doAnalysis.sh > tmp
mv tmp doAnalysis.sh
sed 's/_10_15_varStage1_/_7_15_varStage1_/g' doAnalysis.sh > tmp
mv tmp doAnalysis.sh
#sed 's/_skimBpt15inf//g' doAnalysis.sh > tmp
#mv tmp doAnalysis.sh
sed 's/{10,15}/{7,15}/g' parameters.h > tmp
mv tmp parameters.h
