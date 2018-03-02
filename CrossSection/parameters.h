const int nBins=1;
double ptBins[nBins+1] = {15,50};
const int nBins1050=4;
double ptBins1050[nBins1050+1] = {10,15,20,30,50};
const int nBins1250=4;
double ptBins1250[nBins1250+1] = {12,15,20,30,50};

const int nBinsInc=1;
double ptBinsInc[nBinsInc+1] = {15,50};

const int nBinsFine=43;
double ptBinsFine[nBinsFine+1]={7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};

const int nBinsY=4;
double ptBinsY[nBinsY+1] = {0.0, 0.5, 1.0, 1.5, 2.4};

const int nBinsCent=4;
double ptBinsCent[nBinsCent+1] = {0.*2,10*2.,30.*2,50.*2,100*2};
double TAA[nBinsCent] = {23.22, 11.51, 3.819, 0.4395};
double npart[nBinsCent] = {358.8, 226.7, 109.2, 21.87};
//https://twiki.cern.ch/twiki/pub/CMS/HiCentrality2016/AN-15-080_temp_20160802.pdf
//https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideHeavyIonCentrality?rev=100#Ncoll_Npart_5_TeV
//https://twiki.cern.ch/twiki/pub/CMS/HI2015DailyMeetings/Ncoll_Npart_04Dec2015.pdf

//const int nBinsReweight=55;
//double ptBinsReweight[nBinsReweight+1]={5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
const int nBinsReweight=35;
double ptBinsReweight[nBinsReweight+1]={15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};

const int BIN_NUM= 1196;
const int HMIN=1;
const int HMAX=300;

const double binsize=((double)(HMAX)-(double)(HMIN))/(double)(BIN_NUM);
Double_t BRchain=3.118974e-5; //Bs->JpsiPhi = 0.107%, Jpsi->mumu = 5.961%, Phi->KK = 48.9%

double sf_pp[1] = {119686.05/117898.04, };//double tnpUnc_pp[1] = {3.147406, };
double sf_pbpb[1] = {21860.34/22269.45, };//double tnpUnc_pbpb[1] = {3.781974, };
double sf_pp_CutBase[1] = {116417.11/114755.92, };//double tnpUnc_pp[1] = {3.129503, };
double sf_pp_PbPbBDT[1] = {80328.34/78973.13, };//double tnpUnc_pp[1] = {3.209350, };
double sf_pp_1050[4] = {68030.65/64700.21, 59901.56/58501.56, 45686.18/45225.95, 14098.30/14170.53, };//double tnpUnc_pp[4] = {4.217616, 3.332084, 3.026775, 2.829370, };
double sf_pbpb_1050[4] = {4687.34/4600.66, 8635.69/8703.54, 9672.27/9902.20, 3552.38/3663.71, };//double tnpUnc_pbpb[4] = {5.085416, 4.104846, 3.632042, 3.432807, };
double sf_pp_Y[4] = {33975.57/33956.17, 34076.91/34002.09, 30596.26/29856.15, 21037.31/20083.64, };//double tnpUnc_pp[4] = {2.759583, 2.812627, 3.654588, 3.622256, };
double sf_pbpb_Y[4] = {7814.71/8051.89, 6645.95/6847.15, 4419.34/4458.37, 2980.34/2912.05, };//double tnpUnc_pbpb[4] = {3.574174, 3.528321, 4.191115, 4.557102, };
