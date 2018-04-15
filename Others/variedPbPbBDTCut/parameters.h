const int nBins=1;
double ptBins[nBins+1] = {15,50};
//const int nBins=2;
//double ptBins[nBins+1] = {7,15,50};
const int nBins750=3;
double ptBins750[nBins750+1] = {7,15,20,50};
const int nBins750_acc=4;
double ptBins750_acc[nBins750_acc+1] = {7,12,15,20,50};
//const int nBins750=5;
//double ptBins750[nBins750+1] = {7,10,15,20,30,50};
const int nBins1050=4;
double ptBins1050[nBins1050+1] = {10,15,20,30,50};
const int nBins1250=4;
double ptBins1250[nBins1250+1] = {12,15,20,30,50};

const int nBinsInc=1;
double ptBinsInc[nBinsInc+1] = {15,50};

const int nBinsFine=43;
double ptBinsFine[nBinsFine+1]={7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};

const int nBinsReweight=5;
double ptBinsReweight[nBinsReweight+1] = {7,10,15,20,30,50};
//const int nBinsReweight=35;
//double ptBinsReweight[nBinsReweight+1]={15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
//const int nBinsReweight=43;
//double ptBinsReweight[nBinsReweight+1]={7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
//const int nBinsReweight=55;
//double ptBinsReweight[nBinsReweight+1]={5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};

const int nBinsY=4;
double ptBinsY[nBinsY+1] = {0.0, 0.5, 1.0, 1.5, 2.4};

TCut weightGpt_pp = "(0.675236 + 0.035587*Gpt + -0.000358*Gpt*Gpt)";
TCut weightBgenpt_pp = "(0.675236 + 0.035587*Bgenpt + -0.000358*Bgenpt*Bgenpt)";
TCut weightHiBin_pp = "1";
TCut weightPVz_pp = "1";
TCut weightGpt_PbPb = "(0.675091 + 0.035578*Gpt + -0.000359*Gpt*Gpt)";
TCut weightBgenpt_PbPb = "(0.675091 + 0.035578*Bgenpt + -0.000359*Bgenpt*Bgenpt)";
TCut weightHiBin_PbPb = "(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))";
TCut weightPVz_PbPb = "(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))";
TString weightgen_pp = "pthatweight*"+TString(weightGpt_pp);
TString weightmc_pp  = "HLT_HIL1DoubleMu0ForPPRef_v1*pthatweight*"+TString(weightBgenpt_pp);
TString weightgen_PbPb = "pthatweight*"+TString(weightGpt_PbPb);
TString weightmc_PbPb = "(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)*pthatweight*"+TString(weightBgenpt_PbPb)+"*"+TString(weightHiBin_PbPb)+"*"+TString(weightPVz_PbPb);
TString weightgen="1";
TString weightmc="1";
TString weightdata="1";

const int nBinsCent=4;
double ptBinsCent[nBinsCent+1] = {0.*2,10*2.,30.*2,50.*2,100*2};
double TAA[nBinsCent] = {23.22, 11.51, 3.819, 0.4395};
double npart[nBinsCent] = {358.8, 226.7, 109.2, 21.87};
//https://twiki.cern.ch/twiki/pub/CMS/HiCentrality2016/AN-15-080_temp_20160802.pdf
//https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideHeavyIonCentrality?rev=100#Ncoll_Npart_5_TeV
//https://twiki.cern.ch/twiki/pub/CMS/HI2015DailyMeetings/Ncoll_Npart_04Dec2015.pdf

const int BIN_NUM= 1196;
const int HMIN=1;
const int HMAX=300;

const double binsize=((double)(HMAX)-(double)(HMIN))/(double)(BIN_NUM);
Double_t BRchain=3.118974e-5; //Bs->JpsiPhi = 0.107%, Jpsi->mumu = 5.961%, Phi->KK = 48.9%

double sf_pp[2] = {145556.43/137477.84, 161234.79/158888.15, };
//double sf_pbpb[2] = {10784.59/10554.81, 28120.78/28645.82, };
double sf_pbpb[2] = {28120.78/28645.82, };
double sf_pp_750[3] = {145556.43/137477.84, 82656.10/80783.33, 78578.69/78104.83, };
double sf_pp_750_acc[4] = {70450.42/65157.74, 75106.01/72320.10, 82656.10/80783.33, 78578.69/78104.83, };
double sf_pp_CutBase[2] = {101167.78/95546.77, 144104.49/142131.81, };
double sf_pp_PbPbBDT[2] = {50097.28/47324.82, 109065.05/107287.96, };
double sf_pp_Y[4] = {75549.42/74848.71, 78204.01/77269.31, 80739.83/77530.53, 72297.97/66717.44, };
