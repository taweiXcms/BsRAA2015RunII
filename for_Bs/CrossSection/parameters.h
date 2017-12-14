const int nBins=4;
double ptBins[nBins+1] = {5.,10.,15.,20.,60};
//const int nBins=1;//Bs0 PbPb
//double ptBins[nBins+1] = {15.,60};//Bs0 PbPb 

const int nBinsInc=1;
//double ptBinsInc[nBinsInc+1] = {7.,50.};
double ptBinsInc[nBinsInc+1] = {5.,60.};
//Bs0 PbPb 
//double ptBinsInc[nBinsInc+1] = {15.,60.};

//const int nBinsFine=43;
const int nBinsFine=55;
//Bs0 PbPb 
//const int nBinsFine=40;
//double ptBinsFine[nBinsFine+1] = {7., 8., 9., 10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50.};
double ptBinsFine[nBinsFine+1] = {5.,6.,7., 8., 9., 10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50.,51.,52.,53.,54.,55.,56.,57.,58.,59.,60.};
//Bs0 PbPb 
//double ptBinsFine[nBinsFine+1] = {10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50.,51.,52.,53.,54.,55.,56.,57.,58.,59.,60.};

const int nBinsY=4;
double ptBinsY[nBins+1] = {0.0, 0.5, 1.0, 1.5, 2.4};
//const int nBinsY=1;
//double ptBinsY[nBins+1] = {0.0, 2.4};

const int nBinsCent=4;
double ptBinsCent[nBinsCent+1] = {0.*2,10*2.,30.*2,50.*2,100*2};
double TAA[nBinsCent] = {23.22, 11.51, 3.819, 0.4395};
double npart[nBinsCent] = {358.8, 226.7, 109.2, 21.87};
//https://twiki.cern.ch/twiki/pub/CMS/HiCentrality2016/AN-15-080_temp_20160802.pdf
//https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideHeavyIonCentrality?rev=100#Ncoll_Npart_5_TeV
//https://twiki.cern.ch/twiki/pub/CMS/HI2015DailyMeetings/Ncoll_Npart_04Dec2015.pdf

//const int nBinsReweight=1;//Bs0 PbPb 
//double ptBinsReweight[nBinsReweight+1]={15.,60};//Bs0 PbPb 
const int nBinsReweight=4;
double ptBinsReweight[nBinsReweight+1]={5.,10.,15.,20.,60};
//const int nBinsReweight=5;
//double ptBinsReweight[nBinsReweight+1]={7.,10.,15.,20.,30.,50};

const int BIN_NUM= 1197;
const int HMIN=1;
const int HMAX=300;
//const int BIN_NUM= 221;
//const int HMIN=5;
//const int HMAX=60;

const double binsize=((double)(HMAX)-(double)(HMIN))/(double)(BIN_NUM);
//Double_t BRchain=6.09604e-5; //6.09604e-5
Double_t BRchain=3.1189e-5;


