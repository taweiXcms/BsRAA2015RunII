#include "TTree.h"
#define MAX_XB       20000
#define MAX_GEN      6000
//pp
int     pBeamScrapingFilter;
int     pPAprimaryVertexFilter;
int     HLT_HIL1DoubleMu0ForPPRef_v1;
//pbpb
int     pclusterCompatibilityFilter;
int     pprimaryVertexFilter;
int     phfCoincFilter3;
int     HLT_HIL1DoubleMu0_v1;
int     HLT_HIL1DoubleMu0_part1_v1;
int     HLT_HIL1DoubleMu0_part2_v1;
int     HLT_HIL1DoubleMu0_part3_v1;
int     hiBin;
//common
float   BDTStage1_pt15to50[MAX_XB]; 
float   pthatweight;
int     Gsize;
float   Gpt[MAX_GEN];
float   Gy[MAX_GEN];
int     GpdgId[MAX_GEN];   
int     GisSignal[MAX_GEN];
int     Bsize;
float   Bgen[MAX_XB];
float   Bgenpt[MAX_XB];
float   PVz;
float   Bpt[MAX_XB];
float   By[MAX_XB];
float   Bmumumass[MAX_XB];
float   Btktkmass[MAX_XB];
float   Bmass[MAX_XB];
float   Bmu1pt[MAX_XB];
float   Bmu2pt[MAX_XB];
float   Bmu1p[MAX_XB];
float   Bmu2p[MAX_XB];
float   Bmu1eta[MAX_XB];
float   Bmu2eta[MAX_XB];
bool    Bmu1TMOneStationTight[MAX_XB];
bool    Bmu2TMOneStationTight[MAX_XB];
int     Bmu1InPixelLayer[MAX_XB];
int     Bmu2InPixelLayer[MAX_XB];
int     Bmu1InStripLayer[MAX_XB];
int     Bmu2InStripLayer[MAX_XB];
float   Bmu1dxyPV[MAX_XB];
float   Bmu2dxyPV[MAX_XB];
float   Bmu1dzPV[MAX_XB];
float   Bmu2dzPV[MAX_XB];
bool    Bmu1isGlobalMuon[MAX_XB];
bool    Bmu2isGlobalMuon[MAX_XB];
float   Bmu1TrgMatchFilterE[MAX_XB];
float   Bmu2TrgMatchFilterE[MAX_XB];
bool    Btrk1highPurity[MAX_XB];
float   Btrk1Eta[MAX_XB];
float   Btrk1Pt[MAX_XB];
bool    Btrk2highPurity[MAX_XB];
float   Btrk2Eta[MAX_XB];
float   Btrk2Pt[MAX_XB];
float   Bchi2cl[MAX_XB];
float   BsvpvDistance[MAX_XB];
float   BsvpvDisErr[MAX_XB];
float   Bdtheta[MAX_XB];
float   Btrk1Dxy[MAX_XB];
float   Btrk1D0Err[MAX_XB];
float   Btrk2Dxy[MAX_XB];
float   Btrk2D0Err[MAX_XB];
float   Balpha[MAX_XB];

void setAddressTree(TTree* ntKp, TTree* ntHlt, TTree* ntSkim, TTree* ntHi, TTree* mvaTree, TTree* ntGen, bool ispp){
	if(ispp){
		ntSkim->SetBranchAddress("pBeamScrapingFilter",&pBeamScrapingFilter);
		ntSkim->SetBranchAddress("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
		ntHlt->SetBranchAddress("HLT_HIL1DoubleMu0ForPPRef_v1",&HLT_HIL1DoubleMu0ForPPRef_v1);
	}
	else{
		ntSkim->SetBranchAddress("pclusterCompatibilityFilter",&pclusterCompatibilityFilter);
		ntSkim->SetBranchAddress("pprimaryVertexFilter",&pprimaryVertexFilter);
		ntSkim->SetBranchAddress("phfCoincFilter3",&phfCoincFilter3);
		ntHlt->SetBranchAddress("HLT_HIL1DoubleMu0_v1",&HLT_HIL1DoubleMu0_v1);
		ntHlt->SetBranchAddress("HLT_HIL1DoubleMu0_part1_v1",&HLT_HIL1DoubleMu0_part1_v1);
		ntHlt->SetBranchAddress("HLT_HIL1DoubleMu0_part2_v1",&HLT_HIL1DoubleMu0_part2_v1);
		ntHlt->SetBranchAddress("HLT_HIL1DoubleMu0_part3_v1",&HLT_HIL1DoubleMu0_part3_v1);
		ntHi->SetBranchAddress("hiBin",&hiBin);
	}
	mvaTree->SetBranchAddress("BDTStage1_pt15to50",BDTStage1_pt15to50);
	ntHi->SetBranchAddress("pthatweight",&pthatweight);
	ntGen->SetBranchAddress("Gsize",&Gsize);
    ntGen->SetBranchAddress("Gpt",Gpt);
    ntGen->SetBranchAddress("Gy",Gy);
    ntGen->SetBranchAddress("GpdgId",GpdgId);
    ntGen->SetBranchAddress("GisSignal",GisSignal);
	ntKp->SetBranchAddress("Bsize",&Bsize);
	ntKp->SetBranchAddress("Bgen",Bgen);
	ntKp->SetBranchAddress("Bgenpt",Bgenpt);
	ntKp->SetBranchAddress("PVz",&PVz);
	ntKp->SetBranchAddress("Bpt",Bpt);
	ntKp->SetBranchAddress("By",By);
	ntKp->SetBranchAddress("Bmumumass",Bmumumass);
	ntKp->SetBranchAddress("Btktkmass",Btktkmass);
	ntKp->SetBranchAddress("Bmass",Bmass);
	ntKp->SetBranchAddress("Bmu1pt",Bmu1pt);
	ntKp->SetBranchAddress("Bmu2pt",Bmu2pt);
	ntKp->SetBranchAddress("Bmu1p",Bmu1p);
	ntKp->SetBranchAddress("Bmu1p",Bmu1p);
	ntKp->SetBranchAddress("Bmu1eta",Bmu1eta);
	ntKp->SetBranchAddress("Bmu2eta",Bmu2eta);
	ntKp->SetBranchAddress("Bmu1TMOneStationTight",Bmu1TMOneStationTight);
	ntKp->SetBranchAddress("Bmu2TMOneStationTight",Bmu2TMOneStationTight);
	ntKp->SetBranchAddress("Bmu1InPixelLayer",Bmu1InPixelLayer);
	ntKp->SetBranchAddress("Bmu2InPixelLayer",Bmu2InPixelLayer);
	ntKp->SetBranchAddress("Bmu1InStripLayer",Bmu1InStripLayer);
	ntKp->SetBranchAddress("Bmu2InStripLayer",Bmu2InStripLayer);
	ntKp->SetBranchAddress("Bmu1dxyPV",Bmu1dxyPV);
	ntKp->SetBranchAddress("Bmu2dxyPV",Bmu2dxyPV);
	ntKp->SetBranchAddress("Bmu1dzPV",Bmu1dzPV);
	ntKp->SetBranchAddress("Bmu2dzPV",Bmu2dzPV);
	ntKp->SetBranchAddress("Bmu1isGlobalMuon",Bmu1isGlobalMuon);
	ntKp->SetBranchAddress("Bmu2isGlobalMuon",Bmu2isGlobalMuon);
	ntKp->SetBranchAddress("Bmu1TrgMatchFilterE",Bmu1TrgMatchFilterE);
	ntKp->SetBranchAddress("Bmu2TrgMatchFilterE",Bmu2TrgMatchFilterE);
	ntKp->SetBranchAddress("Btrk1highPurity",Btrk1highPurity);
	ntKp->SetBranchAddress("Btrk1Eta",Btrk1Eta);
	ntKp->SetBranchAddress("Btrk1Pt",Btrk1Pt);
	ntKp->SetBranchAddress("Btrk2highPurity",Btrk2highPurity);
	ntKp->SetBranchAddress("Btrk2Eta",Btrk1Eta);
	ntKp->SetBranchAddress("Btrk2Pt",Btrk2Pt);
	ntKp->SetBranchAddress("Bchi2cl",Bchi2cl);
	ntKp->SetBranchAddress("BsvpvDistance",BsvpvDistance);
	ntKp->SetBranchAddress("BsvpvDisErr",BsvpvDisErr);
	ntKp->SetBranchAddress("Bdtheta",Bdtheta);
	ntKp->SetBranchAddress("Btrk1Dxy",Btrk1Dxy);
	ntKp->SetBranchAddress("Btrk1D0Err",Btrk1D0Err);
	ntKp->SetBranchAddress("Btrk2Dxy",Btrk2Dxy);
	ntKp->SetBranchAddress("Btrk2D0Err",Btrk2D0Err);
	ntKp->SetBranchAddress("Balpha",Balpha);
}
