//const int nBins=2;
//double ptBins[nBins+1] = {7,15,50};
const int nBins=1;
double ptBins[nBins+1] = {7,50};
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

double sf_pp[1] = {127693.52/125760.88, };
//double sf_pp[1] = {126033.04/124022.37, }; // only pthatweight
double sf_pbpb[1] = {20506.70/20890.91, };
//double sf_pbpb[1] = {43815.89/44553.57, }; // only pthatweight
double sf_pp_1050[4] = {69507.58/66042.97, 62732.74/61234.12, 49566.28/49053.79, 15394.50/15472.96, };//double tnpUnc_pp[4] = {4.225170, 3.354476, 3.025281, 2.829637, };
double sf_pp_1250[4] = {46684.27/44737.63, 62732.74/61234.12, 49566.28/49053.79, 15394.50/15472.96, };
double sf_pp_Y[4] = {50364.37/50031.72, 52376.56/51902.39, 52078.31/50299.20, 42381.87/39570.54, };//double tnpUnc_pp[4] = {3.142683, 3.199027, 3.902916, 3.952208, };
