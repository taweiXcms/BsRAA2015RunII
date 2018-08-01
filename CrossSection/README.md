Do
 'source doAnalysis.sh'
To run macros

Setting options in side doAnalysis.sh

```bash
DOANALYSISPP_ROOFITONSAVED = 1
```
Will run
```
roofitB.C
```
And gives paper figure 1-a and 2-a at
```
plotFits/plotFitsOnSaved_roofit/data_pp_1.pdf
plotFits/plotFitsOnSaved_roofit/data_pp_2.pdf
```

```bash
DOANALYSISPbPb_ROOFITONSAVED = 1
```
Will run
```
roofitB.C
```
And gives paper figure 1-b and 2-b at
```
plotFits/plotFitsOnSaved_roofit/data_PbPb_1.pdf
plotFits/plotFitsOnSaved_roofit/data_PbPb_2.pdf
```

```bash
DOANALYSISPP_CROSS_750 = 1
```
Will run
```
CrossSectionRatio.C
```
And gives paper figure 3
```
plotCrossSection/plotCrossSection_750/canvasSigmaBplusRatiopp.pdf
```

```bash
DOANALYSISPP_CROSS = 1
```
Will run
```
CrossSectionRatio.C
```
And give paper figure 4-a at
```
plotCrossSection/plotCrossSection/canvasSigmaBplusRatiopp_AddPbPb.pdf
```

```bash
DORAA = 1
```
Will run
```
NuclearModificationFactor.C
```
And give paper figure 4-b at
```
plotRAA/canvasRAAPbPb_0_100_BpRAA.pdf
```

```bash
DORAARATIO = 1
```
Will run
```bash
plotBsBpRatio/plotBsBpRatio.cc
```
And give paper figure 5 at
```bash
plotBsBpRatio/BsBpRatio.pdf
```
