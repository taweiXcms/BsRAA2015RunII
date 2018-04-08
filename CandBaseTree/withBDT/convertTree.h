#define MAX_XB       20000
#define MAX_GEN      6000

//EvtInfo

float BDTStage1_pt7to15[MAX_XB];
float BDTStage1_pt15to50[MAX_XB];
float pthat;
float pthatweight;
int hiBin;
int pBeamScrapingFilter;
int pPAprimaryVertexFilter;
int pclusterCompatibilityFilter;
int pprimaryVertexFilter;
int phfCoincFilter3;
int HLT_HIL1DoubleMu0_v1;
int HLT_HIL1DoubleMu0ForPPRef_v1;
int HLT_HIL1DoubleMu0_part1_v1;
int HLT_HIL1DoubleMu0_part2_v1;
int HLT_HIL1DoubleMu0_part3_v1;

void setBDTBranchAddress(TTree* nt, bool ispp, bool isdata)
{
    nt->SetBranchAddress("BDTStage1_pt7to15",BDTStage1_pt7to15);
    nt->SetBranchAddress("BDTStage1_pt15to50",BDTStage1_pt15to50);
}

void setHiBranchAddress(TTree* nt, bool ispp, bool isdata)
{
	if(!isdata){
	    nt->SetBranchAddress("pthat",&pthat);
	    nt->SetBranchAddress("pthatweight",&pthatweight);
	}
	if(!ispp)
        nt->SetBranchAddress("hiBin",&hiBin);		
}

void setSkimBranchAddress(TTree* nt, bool ispp, bool isdata)
{
	if(ispp){
    	nt->SetBranchAddress("pBeamScrapingFilter",&pBeamScrapingFilter);
	    nt->SetBranchAddress("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
	}
	else{
	    nt->SetBranchAddress("pclusterCompatibilityFilter",&pclusterCompatibilityFilter);
    	nt->SetBranchAddress("pprimaryVertexFilter",&pprimaryVertexFilter);
	    nt->SetBranchAddress("phfCoincFilter3",&phfCoincFilter3);
	}
}

void setHltBranchAddress(TTree* nt, bool ispp, bool isdata)
{
	if(ispp){
	    nt->SetBranchAddress("HLT_HIL1DoubleMu0_v1",&HLT_HIL1DoubleMu0_v1);
   		nt->SetBranchAddress("HLT_HIL1DoubleMu0ForPPRef_v1",&HLT_HIL1DoubleMu0ForPPRef_v1);
	}
	if(!ispp){
	    nt->SetBranchAddress("HLT_HIL1DoubleMu0_v1",&HLT_HIL1DoubleMu0_v1);
	    nt->SetBranchAddress("HLT_HIL1DoubleMu0_part1_v1",&HLT_HIL1DoubleMu0_part1_v1);
    	nt->SetBranchAddress("HLT_HIL1DoubleMu0_part2_v1",&HLT_HIL1DoubleMu0_part2_v1);
	    nt->SetBranchAddress("HLT_HIL1DoubleMu0_part3_v1",&HLT_HIL1DoubleMu0_part3_v1);
	}
}

int      RunNo;
int      EvtNo;
int      LumiNo;
int      Bsize;
int      Jsize;
float    PVx;
float    PVy;
float    PVz;
float    PVxE;
float    PVyE;
float    PVzE;
float    PVnchi2;
float    PVchi2;
float    BSx;
float    BSy;
float    BSz;
float    BSxErr;
float    BSyErr;
float    BSzErr;
float    BSdxdz;
float    BSdydz;
float    BSdxdzErr;
float    BSdydzErr;
float    BSWidthX;
float    BSWidthXErr;
float    BSWidthY;
float    BSWidthYErr;

//BInfo
int       Bindex[MAX_XB];
int       Btype[MAX_XB];
float     Bmass[MAX_XB];
float     Bmass_unfitted[MAX_XB];
float     Bpt[MAX_XB];
float     Beta[MAX_XB];
float     Bphi[MAX_XB];
float     By[MAX_XB];
float     BvtxX[MAX_XB];
float     BvtxY[MAX_XB];
float     Bd0[MAX_XB];
float     Bd0Err[MAX_XB];
float     Bdxyz[MAX_XB];
float     BdxyzErr[MAX_XB];
float     Bchi2ndf[MAX_XB];
float     Bchi2cl[MAX_XB];
float     Bdtheta[MAX_XB];
float     Blxy[MAX_XB];
float     BlxyBS[MAX_XB];
float     BlxyBSErr[MAX_XB];
float     BMaxDoca[MAX_XB];
float     Balpha[MAX_XB];
float     BsvpvDistance[MAX_XB];
float     BsvpvDisErr[MAX_XB];
float     BsvpvDistance_2D[MAX_XB];
float     BsvpvDisErr_2D[MAX_XB];
int       Bisbestchi2[MAX_XB];

//BInfo.muonInfo
float     Bmu1pt[MAX_XB];
float     Bmu2pt[MAX_XB];
float     Bmu1p[MAX_XB];
float     Bmu2p[MAX_XB];
float     Bmu1eta[MAX_XB];
float     Bmu2eta[MAX_XB];
float     Bmu1phi[MAX_XB];
float     Bmu2phi[MAX_XB];
float     Bmu1y[MAX_XB];
float     Bmu2y[MAX_XB];
float     Bmu1dzPV[MAX_XB];
float     Bmu2dzPV[MAX_XB];
float     Bmu1dxyPV[MAX_XB];
float     Bmu2dxyPV[MAX_XB];
float     Bmu1normchi2[MAX_XB];
float     Bmu2normchi2[MAX_XB];
float     Bmu1Chi2ndf[MAX_XB];
float     Bmu2Chi2ndf[MAX_XB];
int       Bmu1muqual[MAX_XB];
int       Bmu2muqual[MAX_XB];
bool      Bmu1TrackerMuArbitrated[MAX_XB];
bool      Bmu2TrackerMuArbitrated[MAX_XB];
bool      Bmu1isTrackerMuon[MAX_XB];
bool      Bmu2isTrackerMuon[MAX_XB];
bool      Bmu1isGlobalMuon[MAX_XB];
bool      Bmu2isGlobalMuon[MAX_XB];
bool      Bmu1TMOneStationTight[MAX_XB];
bool      Bmu2TMOneStationTight[MAX_XB];
int       Bmu1striphit[MAX_XB];
int       Bmu2striphit[MAX_XB];
int       Bmu1pixelhit[MAX_XB];
int       Bmu2pixelhit[MAX_XB];
int       Bmu1trackerhit[MAX_XB];
int       Bmu2trackerhit[MAX_XB];
int       Bmu1InPixelLayer[MAX_XB];
int       Bmu2InPixelLayer[MAX_XB];
int       Bmu1InStripLayer[MAX_XB];
int       Bmu2InStripLayer[MAX_XB];
int       Bmu1InTrackerLayer[MAX_XB];
int       Bmu2InTrackerLayer[MAX_XB];
int       Bmu1TrkQuality[MAX_XB];
int       Bmu2TrkQuality[MAX_XB];
float     Bmu1TrgMatchFilterE[MAX_XB];
float     Bmu1TrgMatchFilterPt[MAX_XB];
float     Bmu1TrgMatchFilterEta[MAX_XB];
float     Bmu1TrgMatchFilterPhi[MAX_XB];
float     Bmu2TrgMatchFilterE[MAX_XB];
float     Bmu2TrgMatchFilterPt[MAX_XB];
float     Bmu2TrgMatchFilterEta[MAX_XB];
float     Bmu2TrgMatchFilterPhi[MAX_XB];

//BInfo.mumuInfo
float     Bmumumass[MAX_XB];
float     Bmumueta[MAX_XB];
float     Bmumuphi[MAX_XB];
float     Bmumuy[MAX_XB];
float     Bmumupt[MAX_XB];

//BInfo.ujInfo
float     Bujmass[MAX_XB];
float     BujvProb[MAX_XB];
float     Bujpt[MAX_XB];
float     Bujeta[MAX_XB];
float     Bujphi[MAX_XB];
float     Bujy[MAX_XB];
float     Bujlxy[MAX_XB];

//BInfo.trkInfo
int       Btrk1Idx[MAX_XB];
int       Btrk2Idx[MAX_XB];
float     Btrk1Pt[MAX_XB];
float     Btrk2Pt[MAX_XB];
float     Btrk1Eta[MAX_XB];
float     Btrk2Eta[MAX_XB];
float     Btrk1Phi[MAX_XB];
float     Btrk2Phi[MAX_XB];
float     Btrk1PtErr[MAX_XB];
float     Btrk2PtErr[MAX_XB];
float     Btrk1EtaErr[MAX_XB];
float     Btrk2EtaErr[MAX_XB];
float     Btrk1PhiErr[MAX_XB];
float     Btrk2PhiErr[MAX_XB];
float     Btrk1Y[MAX_XB];
float     Btrk2Y[MAX_XB];
float     Btrk1Dz[MAX_XB];
float     Btrk2Dz[MAX_XB];
float     Btrk1Dxy[MAX_XB];
float     Btrk2Dxy[MAX_XB];
float     Btrk1D0[MAX_XB];
float     Btrk2D0[MAX_XB];
float     Btrk1D0Err[MAX_XB];
float     Btrk2D0Err[MAX_XB];
float     Btrk1PixelHit[MAX_XB];
float     Btrk2PixelHit[MAX_XB];
float     Btrk1StripHit[MAX_XB];
float     Btrk2StripHit[MAX_XB];
float     Btrk1nPixelLayer[MAX_XB];
float     Btrk2nPixelLayer[MAX_XB];
float     Btrk1nStripLayer[MAX_XB];
float     Btrk2nStripLayer[MAX_XB];
float     Btrk1Chi2ndf[MAX_XB];
float     Btrk2Chi2ndf[MAX_XB];
float     Btrk1MVAVal[MAX_XB];
float     Btrk2MVAVal[MAX_XB];
int       Btrk1Algo[MAX_XB];
int       Btrk2Algo[MAX_XB];
bool      Btrk1highPurity[MAX_XB];
bool      Btrk2highPurity[MAX_XB];
int       Btrk1Quality[MAX_XB];
int       Btrk2Quality[MAX_XB];

//BInfo.tktkInfo
float     Btktkmass[MAX_XB];
float     BtktkmassKK[MAX_XB];
float     BtktkvProb[MAX_XB];
float     Btktkpt[MAX_XB];
float     Btktketa[MAX_XB];
float     Btktkphi[MAX_XB];
float     Btktky[MAX_XB];
float     Bdoubletmass[MAX_XB];
float     Bdoubletpt[MAX_XB];
float     Bdoubleteta[MAX_XB];
float     Bdoubletphi[MAX_XB];
float     Bdoublety[MAX_XB];

//BInfo.genInfo
float     Bgen[MAX_XB];
int       BgenIndex[MAX_XB];
float     Bgenpt[MAX_XB];
float     Bgeneta[MAX_XB];
float     Bgenphi[MAX_XB];
float     Bgeny[MAX_XB];
int       BgencollisionId[MAX_XB];

void setBranchAddress(TTree* nt, bool ispp, bool isdata)
{
    //EvtInfo
    nt->SetBranchAddress("RunNo",&RunNo);
    nt->SetBranchAddress("EvtNo",&EvtNo);
    nt->SetBranchAddress("LumiNo",&LumiNo);
    nt->SetBranchAddress("PVx",&PVx);
    nt->SetBranchAddress("PVy",&PVy);
    nt->SetBranchAddress("PVz",&PVz);
    nt->SetBranchAddress("PVxE",&PVxE);
    nt->SetBranchAddress("PVyE",&PVyE);
    nt->SetBranchAddress("PVzE",&PVzE);
    nt->SetBranchAddress("PVnchi2",&PVnchi2);
    nt->SetBranchAddress("PVchi2",&PVchi2);
    nt->SetBranchAddress("BSx",&BSx);
    nt->SetBranchAddress("BSy",&BSy);
    nt->SetBranchAddress("BSz",&BSz);
    nt->SetBranchAddress("BSxErr",&BSxErr);
    nt->SetBranchAddress("BSyErr",&BSyErr);
    nt->SetBranchAddress("BSzErr",&BSzErr);
    nt->SetBranchAddress("BSdxdz",&BSdxdz);
    nt->SetBranchAddress("BSdydz",&BSdydz);
    nt->SetBranchAddress("BSdxdzErr",&BSdxdzErr);
    nt->SetBranchAddress("BSdydzErr",&BSdydzErr);
    nt->SetBranchAddress("BSWidthX",&BSWidthX);
    nt->SetBranchAddress("BSWidthXErr",&BSWidthXErr);
    nt->SetBranchAddress("BSWidthY",&BSWidthY);
    nt->SetBranchAddress("BSWidthYErr",&BSWidthYErr);
    
	nt->SetBranchAddress("Bsize",&Bsize);
	//BInfo
	nt->SetBranchAddress("Bindex",Bindex);
	nt->SetBranchAddress("Btype",Btype);
	nt->SetBranchAddress("Bmass",Bmass);
	nt->SetBranchAddress("Bmass_unfitted",Bmass_unfitted);
	nt->SetBranchAddress("Bpt",Bpt);
	nt->SetBranchAddress("Beta",Beta);
	nt->SetBranchAddress("Bphi",Bphi);
	nt->SetBranchAddress("By",By);
	nt->SetBranchAddress("BvtxX",BvtxX);
	nt->SetBranchAddress("BvtxY",BvtxY);
	nt->SetBranchAddress("Bd0",Bd0);
	nt->SetBranchAddress("Bd0Err",Bd0Err);
	nt->SetBranchAddress("Bdxyz",Bdxyz);
	nt->SetBranchAddress("BdxyzErr",BdxyzErr);
	nt->SetBranchAddress("Bchi2ndf",Bchi2ndf);
	nt->SetBranchAddress("Bchi2cl",Bchi2cl);
	nt->SetBranchAddress("Bdtheta",Bdtheta);
	nt->SetBranchAddress("Blxy",Blxy);
	nt->SetBranchAddress("BlxyBS",BlxyBS);
	nt->SetBranchAddress("BlxyBSErr",BlxyBSErr);
	nt->SetBranchAddress("Balpha",Balpha);
	nt->SetBranchAddress("BsvpvDistance",BsvpvDistance);
	nt->SetBranchAddress("BsvpvDisErr",BsvpvDisErr);
	nt->SetBranchAddress("BsvpvDistance_2D",BsvpvDistance_2D);
	nt->SetBranchAddress("BsvpvDisErr_2D",BsvpvDisErr_2D);
	nt->SetBranchAddress("BMaxDoca",BMaxDoca);
	nt->SetBranchAddress("Bisbestchi2",Bisbestchi2);

	//BInfo.trkInfo
	nt->SetBranchAddress("Btrk1Idx",Btrk1Idx);
	nt->SetBranchAddress("Btrk2Idx",Btrk2Idx);
	nt->SetBranchAddress("Btrk1Pt",Btrk1Pt);
	nt->SetBranchAddress("Btrk2Pt",Btrk2Pt);
	nt->SetBranchAddress("Btrk1Eta",Btrk1Eta);  
	nt->SetBranchAddress("Btrk2Eta",Btrk2Eta);  
	nt->SetBranchAddress("Btrk1Phi",Btrk1Phi);  
	nt->SetBranchAddress("Btrk2Phi",Btrk2Phi);  
	nt->SetBranchAddress("Btrk1PtErr",Btrk1PtErr);  
	nt->SetBranchAddress("Btrk2PtErr",Btrk2PtErr);
	nt->SetBranchAddress("Btrk1EtaErr",Btrk1EtaErr);
	nt->SetBranchAddress("Btrk2EtaErr",Btrk2EtaErr);
	nt->SetBranchAddress("Btrk1PhiErr",Btrk1PhiErr);
	nt->SetBranchAddress("Btrk2PhiErr",Btrk2PhiErr);
	nt->SetBranchAddress("Btrk1Y",Btrk1Y);  
	nt->SetBranchAddress("Btrk2Y",Btrk2Y);  
	nt->SetBranchAddress("Btrk1Dz",Btrk1Dz);
	nt->SetBranchAddress("Btrk2Dz",Btrk2Dz);
	nt->SetBranchAddress("Btrk1Dxy",Btrk1Dxy);
	nt->SetBranchAddress("Btrk2Dxy",Btrk2Dxy);
	nt->SetBranchAddress("Btrk1D0",Btrk1D0);
	nt->SetBranchAddress("Btrk2D0",Btrk2D0);
	nt->SetBranchAddress("Btrk1D0Err",Btrk1D0Err);
	nt->SetBranchAddress("Btrk2D0Err",Btrk2D0Err);
	nt->SetBranchAddress("Btrk1PixelHit",Btrk1PixelHit);
	nt->SetBranchAddress("Btrk2PixelHit",Btrk2PixelHit);
	nt->SetBranchAddress("Btrk1StripHit",Btrk1StripHit);
	nt->SetBranchAddress("Btrk2StripHit",Btrk2StripHit);
	nt->SetBranchAddress("Btrk1nPixelLayer",Btrk1nPixelLayer);
	nt->SetBranchAddress("Btrk2nPixelLayer",Btrk2nPixelLayer);
	nt->SetBranchAddress("Btrk1nStripLayer",Btrk1nStripLayer);
	nt->SetBranchAddress("Btrk2nStripLayer",Btrk2nStripLayer);
	nt->SetBranchAddress("Btrk1Chi2ndf",Btrk1Chi2ndf);
	nt->SetBranchAddress("Btrk2Chi2ndf",Btrk2Chi2ndf);
	nt->SetBranchAddress("Btrk1MVAVal",Btrk1MVAVal);
	nt->SetBranchAddress("Btrk2MVAVal",Btrk2MVAVal);
	nt->SetBranchAddress("Btrk1Algo",Btrk1Algo);
	nt->SetBranchAddress("Btrk2Algo",Btrk2Algo);
	nt->SetBranchAddress("Btrk1highPurity",Btrk1highPurity);
	nt->SetBranchAddress("Btrk2highPurity",Btrk2highPurity);
	nt->SetBranchAddress("Btrk1Quality",Btrk1Quality);
	nt->SetBranchAddress("Btrk2Quality",Btrk2Quality);

	//BInfo.tktkInfo
	nt->SetBranchAddress("Btktkmass",Btktkmass);
	nt->SetBranchAddress("BtktkmassKK",BtktkmassKK);
	nt->SetBranchAddress("BtktkvProb",BtktkvProb);
	nt->SetBranchAddress("Btktkpt",Btktkpt);
	nt->SetBranchAddress("Btktketa",Btktketa);
	nt->SetBranchAddress("Btktkphi",Btktkphi);
	nt->SetBranchAddress("Btktky",Btktky);
	nt->SetBranchAddress("Bdoubletmass",Bdoubletmass);
	nt->SetBranchAddress("Bdoubletpt",Bdoubletpt);
	nt->SetBranchAddress("Bdoubleteta",Bdoubleteta);  
	nt->SetBranchAddress("Bdoubletphi",Bdoubletphi);  
	nt->SetBranchAddress("Bdoublety",Bdoublety);

	//BInfo.muonInfo
	nt->SetBranchAddress("Bmu1pt",Bmu1pt);
	nt->SetBranchAddress("Bmu2pt",Bmu2pt);
	nt->SetBranchAddress("Bmu1p",Bmu1p);
	nt->SetBranchAddress("Bmu2p",Bmu2p);
	nt->SetBranchAddress("Bmu1eta",Bmu1eta);
	nt->SetBranchAddress("Bmu2eta",Bmu2eta);
	nt->SetBranchAddress("Bmu1phi",Bmu1phi);
	nt->SetBranchAddress("Bmu2phi",Bmu2phi);
	nt->SetBranchAddress("Bmu1y",Bmu1y);
	nt->SetBranchAddress("Bmu2y",Bmu2y);
	nt->SetBranchAddress("Bmu1dzPV",Bmu1dzPV);
	nt->SetBranchAddress("Bmu2dzPV",Bmu2dzPV);
	nt->SetBranchAddress("Bmu1dxyPV",Bmu1dxyPV);
	nt->SetBranchAddress("Bmu2dxyPV",Bmu2dxyPV);
	nt->SetBranchAddress("Bmu1normchi2",Bmu1normchi2);
	nt->SetBranchAddress("Bmu2normchi2",Bmu2normchi2);
	nt->SetBranchAddress("Bmu1Chi2ndf",Bmu1Chi2ndf);
	nt->SetBranchAddress("Bmu2Chi2ndf",Bmu2Chi2ndf);
	nt->SetBranchAddress("Bmu1muqual",Bmu1muqual);
	nt->SetBranchAddress("Bmu2muqual",Bmu2muqual);
	nt->SetBranchAddress("Bmu1TrackerMuArbitrated",Bmu1TrackerMuArbitrated);
	nt->SetBranchAddress("Bmu2TrackerMuArbitrated",Bmu2TrackerMuArbitrated);
	nt->SetBranchAddress("Bmu1isTrackerMuon",Bmu1isTrackerMuon);
	nt->SetBranchAddress("Bmu2isTrackerMuon",Bmu2isTrackerMuon);
	nt->SetBranchAddress("Bmu1isGlobalMuon",Bmu1isGlobalMuon);
	nt->SetBranchAddress("Bmu2isGlobalMuon",Bmu2isGlobalMuon);
	nt->SetBranchAddress("Bmu1TMOneStationTight",Bmu1TMOneStationTight);
	nt->SetBranchAddress("Bmu2TMOneStationTight",Bmu2TMOneStationTight);
	nt->SetBranchAddress("Bmu1striphit",Bmu1striphit);
	nt->SetBranchAddress("Bmu2striphit",Bmu2striphit);
	nt->SetBranchAddress("Bmu1pixelhit",Bmu1pixelhit);
	nt->SetBranchAddress("Bmu2pixelhit",Bmu2pixelhit);
	nt->SetBranchAddress("Bmu1trackerhit",Bmu1trackerhit);
	nt->SetBranchAddress("Bmu2trackerhit",Bmu2trackerhit);
	nt->SetBranchAddress("Bmu1InPixelLayer",Bmu1InPixelLayer);
	nt->SetBranchAddress("Bmu2InPixelLayer",Bmu2InPixelLayer);
	nt->SetBranchAddress("Bmu1InStripLayer",Bmu1InStripLayer);
	nt->SetBranchAddress("Bmu2InStripLayer",Bmu2InStripLayer);
	nt->SetBranchAddress("Bmu1InTrackerLayer",Bmu1InTrackerLayer);
	nt->SetBranchAddress("Bmu2InTrackerLayer",Bmu2InTrackerLayer);
	nt->SetBranchAddress("Bmu1TrkQuality",Bmu1TrkQuality);
	nt->SetBranchAddress("Bmu2TrkQuality",Bmu2TrkQuality);
	nt->SetBranchAddress("Bmu1TrgMatchFilterE"  ,Bmu1TrgMatchFilterE);
	nt->SetBranchAddress("Bmu1TrgMatchFilterPt" ,Bmu1TrgMatchFilterPt);
	nt->SetBranchAddress("Bmu1TrgMatchFilterEta",Bmu1TrgMatchFilterEta);
	nt->SetBranchAddress("Bmu1TrgMatchFilterPhi",Bmu1TrgMatchFilterPhi);
	nt->SetBranchAddress("Bmu2TrgMatchFilterE"  ,Bmu2TrgMatchFilterE);
	nt->SetBranchAddress("Bmu2TrgMatchFilterPt" ,Bmu2TrgMatchFilterPt);
	nt->SetBranchAddress("Bmu2TrgMatchFilterEta",Bmu2TrgMatchFilterEta);
	nt->SetBranchAddress("Bmu2TrgMatchFilterPhi",Bmu2TrgMatchFilterPhi);
	nt->SetBranchAddress("Bmumumass",Bmumumass);
	nt->SetBranchAddress("Bmumueta",Bmumueta);
	nt->SetBranchAddress("Bmumuphi",Bmumuphi);
	nt->SetBranchAddress("Bmumuy",Bmumuy);
	nt->SetBranchAddress("Bmumupt",Bmumupt);
	nt->SetBranchAddress("Bujmass",Bujmass);
	nt->SetBranchAddress("BujvProb",BujvProb);
	nt->SetBranchAddress("Bujpt",Bujpt);
	nt->SetBranchAddress("Bujeta",Bujeta);
	nt->SetBranchAddress("Bujphi",Bujphi);
	nt->SetBranchAddress("Bujy",Bujy);
	nt->SetBranchAddress("Bujlxy",Bujlxy);

	//BInfo.genInfo
	nt->SetBranchAddress("Bgen",Bgen);
	nt->SetBranchAddress("BgenIndex",BgenIndex);
	nt->SetBranchAddress("Bgenpt",Bgenpt);
	nt->SetBranchAddress("Bgeneta",Bgeneta);
	nt->SetBranchAddress("Bgenphi",Bgenphi);
	nt->SetBranchAddress("Bgeny",Bgeny);
    nt->SetBranchAddress("BgencollisionId",BgencollisionId);
}

float __BDTStage1_pt7to15;
float __BDTStage1_pt15to50;

//BInfo
int       __Bindex;
int       __Btype;
float     __Bmass;
float     __Bmass_unfitted;
float     __Bpt;
float     __Beta;
float     __Bphi;
float     __By;
float     __BvtxX;
float     __BvtxY;
float     __Bd0;
float     __Bd0Err;
float     __Bdxyz;
float     __BdxyzErr;
float     __Bchi2ndf;
float     __Bchi2cl;
float     __Bdtheta;
float     __Blxy;
float     __BlxyBS;
float     __BlxyBSErr;
float     __BMaxDoca;
float     __Balpha;
float     __BsvpvDistance;
float     __BsvpvDisErr;
float     __BsvpvDistance_2D;
float     __BsvpvDisErr_2D;
int       __Bisbestchi2;

//BInfo.muonInfo
float     __Bmu1pt;
float     __Bmu2pt;
float     __Bmu1p;
float     __Bmu2p;
float     __Bmu1eta;
float     __Bmu2eta;
float     __Bmu1phi;
float     __Bmu2phi;
float     __Bmu1y;
float     __Bmu2y;
float     __Bmu1dzPV;
float     __Bmu2dzPV;
float     __Bmu1dxyPV;
float     __Bmu2dxyPV;
float     __Bmu1normchi2;
float     __Bmu2normchi2;
float     __Bmu1Chi2ndf;
float     __Bmu2Chi2ndf;
int       __Bmu1muqual;
int       __Bmu2muqual;
bool      __Bmu1TrackerMuArbitrated;
bool      __Bmu2TrackerMuArbitrated;
bool      __Bmu1isTrackerMuon;
bool      __Bmu2isTrackerMuon;
bool      __Bmu1isGlobalMuon;
bool      __Bmu2isGlobalMuon;
bool      __Bmu1TMOneStationTight;
bool      __Bmu2TMOneStationTight;
int       __Bmu1striphit;
int       __Bmu2striphit;
int       __Bmu1pixelhit;
int       __Bmu2pixelhit;
int       __Bmu1trackerhit;
int       __Bmu2trackerhit;
int       __Bmu1InPixelLayer;
int       __Bmu2InPixelLayer;
int       __Bmu1InStripLayer;
int       __Bmu2InStripLayer;
int       __Bmu1InTrackerLayer;
int       __Bmu2InTrackerLayer;
int       __Bmu1TrkQuality;
int       __Bmu2TrkQuality;
float     __Bmu1TrgMatchFilterE;
float     __Bmu1TrgMatchFilterPt;
float     __Bmu1TrgMatchFilterEta;
float     __Bmu1TrgMatchFilterPhi;
float     __Bmu2TrgMatchFilterE;
float     __Bmu2TrgMatchFilterPt;
float     __Bmu2TrgMatchFilterEta;
float     __Bmu2TrgMatchFilterPhi;

//BInfo.mumuInfo
float     __Bmumumass;
float     __Bmumueta;
float     __Bmumuphi;
float     __Bmumuy;
float     __Bmumupt;

//BInfo.ujInfo
float     __Bujmass;
float     __BujvProb;
float     __Bujpt;
float     __Bujeta;
float     __Bujphi;
float     __Bujy;
float     __Bujlxy;

//BInfo.trkInfo
int       __Btrk1Idx;
int       __Btrk2Idx;
float     __Btrk1Pt;
float     __Btrk2Pt;
float     __Btrk1Eta;
float     __Btrk2Eta;
float     __Btrk1Phi;
float     __Btrk2Phi;
float     __Btrk1PtErr;
float     __Btrk2PtErr;
float     __Btrk1EtaErr;
float     __Btrk2EtaErr;
float     __Btrk1PhiErr;
float     __Btrk2PhiErr;
float     __Btrk1Y;
float     __Btrk2Y;
float     __Btrk1Dz;
float     __Btrk2Dz;
float     __Btrk1Dxy;
float     __Btrk2Dxy;
float     __Btrk1D0;
float     __Btrk2D0;
float     __Btrk1D0Err;
float     __Btrk2D0Err;
float     __Btrk1PixelHit;
float     __Btrk2PixelHit;
float     __Btrk1StripHit;
float     __Btrk2StripHit;
float     __Btrk1nPixelLayer;
float     __Btrk2nPixelLayer;
float     __Btrk1nStripLayer;
float     __Btrk2nStripLayer;
float     __Btrk1Chi2ndf;
float     __Btrk2Chi2ndf;
float     __Btrk1MVAVal;
float     __Btrk2MVAVal;
int       __Btrk1Algo;
int       __Btrk2Algo;
bool      __Btrk1highPurity;
bool      __Btrk2highPurity;
int       __Btrk1Quality;
int       __Btrk2Quality;

//BInfo.tktkInfo
float     __Btktkmass;
float     __BtktkmassKK;
float     __BtktkvProb;
float     __Btktkpt;
float     __Btktketa;
float     __Btktkphi;
float     __Btktky;
float     __Bdoubletmass;
float     __Bdoubletpt;
float     __Bdoubleteta;
float     __Bdoubletphi;
float     __Bdoublety;

//BInfo.genInfo
float     __Bgen;
int       __BgenIndex;
float     __Bgenpt;
float     __Bgeneta;
float     __Bgenphi;
float     __Bgeny;
int       __BgencollisionId;

void buildBranch(TTree* nt, bool ispp, bool isdata)
{
    nt->Branch("BDTStage1_pt7to15",&__BDTStage1_pt7to15);
    nt->Branch("BDTStage1_pt15to50",&__BDTStage1_pt15to50);
	if(!isdata){
    	nt->Branch("pthat",&pthat);
    	nt->Branch("pthatweight",&pthatweight);
	}
	if(!ispp)
    	nt->Branch("hiBin",&hiBin);
	if(ispp){
	    nt->Branch("pBeamScrapingFilter",&pBeamScrapingFilter);
		nt->Branch("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
	}
	else{
		nt->Branch("pclusterCompatibilityFilter",&pclusterCompatibilityFilter);
	    nt->Branch("pprimaryVertexFilter",&pprimaryVertexFilter);
		nt->Branch("phfCoincFilter3",&phfCoincFilter3);
	}
	if(ispp){
		nt->Branch("HLT_HIL1DoubleMu0_v1",&HLT_HIL1DoubleMu0_v1);
		nt->Branch("HLT_HIL1DoubleMu0ForPPRef_v1",&HLT_HIL1DoubleMu0ForPPRef_v1);
	}
	if(!ispp){
		nt->Branch("HLT_HIL1DoubleMu0_v1",&HLT_HIL1DoubleMu0_v1);
		nt->Branch("HLT_HIL1DoubleMu0_part1_v1",&HLT_HIL1DoubleMu0_part1_v1);
		nt->Branch("HLT_HIL1DoubleMu0_part2_v1",&HLT_HIL1DoubleMu0_part2_v1);
		nt->Branch("HLT_HIL1DoubleMu0_part3_v1",&HLT_HIL1DoubleMu0_part3_v1);
	}

    //EvtInfo
    nt->Branch("RunNo",&RunNo);
    nt->Branch("EvtNo",&EvtNo);
    nt->Branch("LumiNo",&LumiNo);
    nt->Branch("PVx",&PVx);
    nt->Branch("PVy",&PVy);
    nt->Branch("PVz",&PVz);
    nt->Branch("PVxE",&PVxE);
    nt->Branch("PVyE",&PVyE);
    nt->Branch("PVzE",&PVzE);
    nt->Branch("PVnchi2",&PVnchi2);
    nt->Branch("PVchi2",&PVchi2);
    nt->Branch("BSx",&BSx);
    nt->Branch("BSy",&BSy);
    nt->Branch("BSz",&BSz);
    nt->Branch("BSxErr",&BSxErr);
    nt->Branch("BSyErr",&BSyErr);
    nt->Branch("BSzErr",&BSzErr);
    nt->Branch("BSdxdz",&BSdxdz);
    nt->Branch("BSdydz",&BSdydz);
    nt->Branch("BSdxdzErr",&BSdxdzErr);
    nt->Branch("BSdydzErr",&BSdydzErr);
    nt->Branch("BSWidthX",&BSWidthX);
    nt->Branch("BSWidthXErr",&BSWidthXErr);
    nt->Branch("BSWidthY",&BSWidthY);
    nt->Branch("BSWidthYErr",&BSWidthYErr);
    
	nt->Branch("Bsize",&Bsize);
	//BInfo
	nt->Branch("Bindex",&__Bindex,"Bindex/I");
	nt->Branch("Btype",&__Btype,"Btype/I");
	nt->Branch("Bmass",&__Bmass,"Bmass/F");
	nt->Branch("Bmass_unfitted",&__Bmass_unfitted,"Bmass_unfitted/F");
	nt->Branch("Bpt",&__Bpt,"Bpt/F");
	nt->Branch("Beta",&__Beta,"Beta/F");
	nt->Branch("Bphi",&__Bphi,"Bphi/F");
	nt->Branch("By",&__By,"By/F");
	nt->Branch("BvtxX",&__BvtxX,"BvtxX/F");
	nt->Branch("BvtxY",&__BvtxY,"BvtxY/F");
	nt->Branch("Bd0",&__Bd0,"Bd0/F");
	nt->Branch("Bd0Err",&__Bd0Err,"Bd0Err/F");
	nt->Branch("Bdxyz",&__Bdxyz,"Bdxyz/F");
	nt->Branch("BdxyzErr",&__BdxyzErr,"BdxyzErr/F");
	nt->Branch("Bchi2ndf",&__Bchi2ndf,"Bchi2ndf/F");
	nt->Branch("Bchi2cl",&__Bchi2cl,"Bchi2cl/F");
	nt->Branch("Bdtheta",&__Bdtheta,"Bdtheta/F");
	nt->Branch("Blxy",&__Blxy,"Blxy/F");
	nt->Branch("BlxyBS",&__BlxyBS,"BlxyBS/F");
	nt->Branch("BlxyBSErr",&__BlxyBSErr,"BlxyBSErr/F");
	nt->Branch("Balpha",&__Balpha,"Balpha/F");
	nt->Branch("BsvpvDistance",&__BsvpvDistance,"BsvpvDistance/F");
	nt->Branch("BsvpvDisErr",&__BsvpvDisErr,"BsvpvDisErr/F");
	nt->Branch("BsvpvDistance_2D",&__BsvpvDistance_2D,"BsvpvDistance_2D/F");
	nt->Branch("BsvpvDisErr_2D",&__BsvpvDisErr_2D,"BsvpvDisErr_2D/F");
	nt->Branch("BMaxDoca",&__BMaxDoca,"BMaxDoca/F");
	nt->Branch("Bisbestchi2",&__Bisbestchi2,"Bisbestchi2/I");

	//BInfo.trkInfo
	nt->Branch("Btrk1Idx",&__Btrk1Idx,"Btrk1Idx/I");
	nt->Branch("Btrk2Idx",&__Btrk2Idx,"Btrk2Idx/I");
	nt->Branch("Btrk1Pt",&__Btrk1Pt,"Btrk1Pt/F");
	nt->Branch("Btrk2Pt",&__Btrk2Pt,"Btrk2Pt/F");
	nt->Branch("Btrk1Eta",&__Btrk1Eta,"Btrk1Eta/F");  
	nt->Branch("Btrk2Eta",&__Btrk2Eta,"Btrk2Eta/F");  
	nt->Branch("Btrk1Phi",&__Btrk1Phi,"Btrk1Phi/F");  
	nt->Branch("Btrk2Phi",&__Btrk2Phi,"Btrk2Phi/F");  
	nt->Branch("Btrk1PtErr",&__Btrk1PtErr,"Btrk1PtErr/F");  
	nt->Branch("Btrk2PtErr",&__Btrk2PtErr,"Btrk2PtErr/F");
	nt->Branch("Btrk1EtaErr",&__Btrk1EtaErr,"Btrk1EtaErr/F");
	nt->Branch("Btrk2EtaErr",&__Btrk2EtaErr,"Btrk2EtaErr/F");
	nt->Branch("Btrk1PhiErr",&__Btrk1PhiErr,"Btrk1PhiErr/F");
	nt->Branch("Btrk2PhiErr",&__Btrk2PhiErr,"Btrk2PhiErr/F");
	nt->Branch("Btrk1Y",&__Btrk1Y,"Btrk1Y/F");  
	nt->Branch("Btrk2Y",&__Btrk2Y,"Btrk2Y/F");  
	nt->Branch("Btrk1Dz",&__Btrk1Dz,"Btrk1Dz/F");
	nt->Branch("Btrk2Dz",&__Btrk2Dz,"Btrk2Dz/F");
	nt->Branch("Btrk1Dxy",&__Btrk1Dxy,"Btrk1Dxy/F");
	nt->Branch("Btrk2Dxy",&__Btrk2Dxy,"Btrk2Dxy/F");
	nt->Branch("Btrk1D0",&__Btrk1D0,"Btrk1D0/F");
	nt->Branch("Btrk2D0",&__Btrk2D0,"Btrk2D0/F");
	nt->Branch("Btrk1D0Err",&__Btrk1D0Err,"Btrk1D0Err/F");
	nt->Branch("Btrk2D0Err",&__Btrk2D0Err,"Btrk2D0Err/F");
	nt->Branch("Btrk1PixelHit",&__Btrk1PixelHit,"Btrk1PixelHit/F");
	nt->Branch("Btrk2PixelHit",&__Btrk2PixelHit,"Btrk2PixelHit/F");
	nt->Branch("Btrk1StripHit",&__Btrk1StripHit,"Btrk1StripHit/F");
	nt->Branch("Btrk2StripHit",&__Btrk2StripHit,"Btrk2StripHit/F");
	nt->Branch("Btrk1nPixelLayer",&__Btrk1nPixelLayer,"Btrk1nPixelLayer/F");
	nt->Branch("Btrk2nPixelLayer",&__Btrk2nPixelLayer,"Btrk2nPixelLayer/F");
	nt->Branch("Btrk1nStripLayer",&__Btrk1nStripLayer,"Btrk1nStripLayer/F");
	nt->Branch("Btrk2nStripLayer",&__Btrk2nStripLayer,"Btrk2nStripLayer/F");
	nt->Branch("Btrk1Chi2ndf",&__Btrk1Chi2ndf,"Btrk1Chi2ndf/F");
	nt->Branch("Btrk2Chi2ndf",&__Btrk2Chi2ndf,"Btrk2Chi2ndf/F");
	nt->Branch("Btrk1MVAVal",&__Btrk1MVAVal,"Btrk1MVAVal/F");
	nt->Branch("Btrk2MVAVal",&__Btrk2MVAVal,"Btrk2MVAVal/F");
	nt->Branch("Btrk1Algo",&__Btrk1Algo,"Btrk1Algo/I");
	nt->Branch("Btrk2Algo",&__Btrk2Algo,"Btrk2Algo/I");
	nt->Branch("Btrk1highPurity",&__Btrk1highPurity,"Btrk1highPurity/O");
	nt->Branch("Btrk2highPurity",&__Btrk2highPurity,"Btrk2highPurity/O");
	nt->Branch("Btrk1Quality",&__Btrk1Quality,"Btrk1Quality/I");
	nt->Branch("Btrk2Quality",&__Btrk2Quality,"Btrk2Quality/I");

	//BInfo.tktkInfo
	nt->Branch("Btktkmass",&__Btktkmass,"Btktkmass/F");
	nt->Branch("BtktkmassKK",&__BtktkmassKK,"BtktkmassKK/F");
	nt->Branch("BtktkvProb",&__BtktkvProb,"BtktkvProb/F");
	nt->Branch("Btktkpt",&__Btktkpt,"Btktkpt/F");
	nt->Branch("Btktketa",&__Btktketa,"Btktketa/F");
	nt->Branch("Btktkphi",&__Btktkphi,"Btktkphi/F");
	nt->Branch("Btktky",&__Btktky,"Btktky/F");
	nt->Branch("Bdoubletmass",&__Bdoubletmass,"Bdoubletmass/F");
	nt->Branch("Bdoubletpt",&__Bdoubletpt,"Bdoubletpt/F");
	nt->Branch("Bdoubleteta",&__Bdoubleteta,"Bdoubleteta/F");  
	nt->Branch("Bdoubletphi",&__Bdoubletphi,"Bdoubletphi/F");  
	nt->Branch("Bdoublety",&__Bdoublety,"Bdoublety/F");

	//BInfo.muonInfo
	nt->Branch("Bmu1pt",&__Bmu1pt,"Bmu1pt/F");
	nt->Branch("Bmu2pt",&__Bmu2pt,"Bmu2pt/F");
	nt->Branch("Bmu1p",&__Bmu1p,"Bmu1p/F");
	nt->Branch("Bmu2p",&__Bmu2p,"Bmu2p/F");
	nt->Branch("Bmu1eta",&__Bmu1eta,"Bmu1eta/F");
	nt->Branch("Bmu2eta",&__Bmu2eta,"Bmu2eta/F");
	nt->Branch("Bmu1phi",&__Bmu1phi,"Bmu1phi/F");
	nt->Branch("Bmu2phi",&__Bmu2phi,"Bmu2phi/F");
	nt->Branch("Bmu1y",&__Bmu1y,"Bmu1y/F");
	nt->Branch("Bmu2y",&__Bmu2y,"Bmu2y/F");
	nt->Branch("Bmu1dzPV",&__Bmu1dzPV,"Bmu1dzPV/F");
	nt->Branch("Bmu2dzPV",&__Bmu2dzPV,"Bmu2dzPV/F");
	nt->Branch("Bmu1dxyPV",&__Bmu1dxyPV,"Bmu1dxyPV/F");
	nt->Branch("Bmu2dxyPV",&__Bmu2dxyPV,"Bmu2dxyPV/F");
	nt->Branch("Bmu1normchi2",&__Bmu1normchi2,"Bmu1normchi2/F");
	nt->Branch("Bmu2normchi2",&__Bmu2normchi2,"Bmu2normchi2/F");
	nt->Branch("Bmu1Chi2ndf",&__Bmu1Chi2ndf,"Bmu1Chi2ndf/F");
	nt->Branch("Bmu2Chi2ndf",&__Bmu2Chi2ndf,"Bmu2Chi2ndf/F");
	nt->Branch("Bmu1muqual",&__Bmu1muqual,"Bmu1muqual/I");
	nt->Branch("Bmu2muqual",&__Bmu2muqual,"Bmu2muqual/I");
	nt->Branch("Bmu1TrackerMuArbitrated",&__Bmu1TrackerMuArbitrated,"Bmu1TrackerMuArbitrated/O");
	nt->Branch("Bmu2TrackerMuArbitrated",&__Bmu2TrackerMuArbitrated,"Bmu2TrackerMuArbitrated/O");
	nt->Branch("Bmu1isTrackerMuon",&__Bmu1isTrackerMuon,"Bmu1isTrackerMuon/O");
	nt->Branch("Bmu2isTrackerMuon",&__Bmu2isTrackerMuon,"Bmu2isTrackerMuon/O");
	nt->Branch("Bmu1isGlobalMuon",&__Bmu1isGlobalMuon,"Bmu1isGlobalMuon/O");
	nt->Branch("Bmu2isGlobalMuon",&__Bmu2isGlobalMuon,"Bmu2isGlobalMuon/O");
	nt->Branch("Bmu1TMOneStationTight",&__Bmu1TMOneStationTight,"Bmu1TMOneStationTight/O");
	nt->Branch("Bmu2TMOneStationTight",&__Bmu2TMOneStationTight,"Bmu2TMOneStationTight/O");
	nt->Branch("Bmu1striphit",&__Bmu1striphit,"Bmu1striphit/I");
	nt->Branch("Bmu2striphit",&__Bmu2striphit,"Bmu2striphit/I");
	nt->Branch("Bmu1pixelhit",&__Bmu1pixelhit,"Bmu1pixelhit/I");
	nt->Branch("Bmu2pixelhit",&__Bmu2pixelhit,"Bmu2pixelhit/I");
	nt->Branch("Bmu1trackerhit",&__Bmu1trackerhit,"Bmu1trackerhit/I");
	nt->Branch("Bmu2trackerhit",&__Bmu2trackerhit,"Bmu2trackerhit/I");
	nt->Branch("Bmu1InPixelLayer",&__Bmu1InPixelLayer,"Bmu1InPixelLayer/I");
	nt->Branch("Bmu2InPixelLayer",&__Bmu2InPixelLayer,"Bmu2InPixelLayer/I");
	nt->Branch("Bmu1InStripLayer",&__Bmu1InStripLayer,"Bmu1InStripLayer/I");
	nt->Branch("Bmu2InStripLayer",&__Bmu2InStripLayer,"Bmu2InStripLayer/I");
	nt->Branch("Bmu1InTrackerLayer",&__Bmu1InTrackerLayer,"Bmu1InTrackerLayer/I");
	nt->Branch("Bmu2InTrackerLayer",&__Bmu2InTrackerLayer,"Bmu2InTrackerLayer/I");
	nt->Branch("Bmu1TrkQuality",&__Bmu1TrkQuality,"Bmu1TrkQuality/I");
	nt->Branch("Bmu2TrkQuality",&__Bmu2TrkQuality,"Bmu2TrkQuality/I");
	nt->Branch("Bmu1TrgMatchFilterE"  ,&__Bmu1TrgMatchFilterE,  "Bmu1TrgMatchFilterE/F");
	nt->Branch("Bmu1TrgMatchFilterPt" ,&__Bmu1TrgMatchFilterPt, "Bmu1TrgMatchFilterPt/F");
	nt->Branch("Bmu1TrgMatchFilterEta",&__Bmu1TrgMatchFilterEta,"Bmu1TrgMatchFilterEta/F");
	nt->Branch("Bmu1TrgMatchFilterPhi",&__Bmu1TrgMatchFilterPhi,"Bmu1TrgMatchFilterPhi/F");
	nt->Branch("Bmu2TrgMatchFilterE"  ,&__Bmu2TrgMatchFilterE,  "Bmu2TrgMatchFilterE/F");
	nt->Branch("Bmu2TrgMatchFilterPt" ,&__Bmu2TrgMatchFilterPt, "Bmu2TrgMatchFilterPt/F");
	nt->Branch("Bmu2TrgMatchFilterEta",&__Bmu2TrgMatchFilterEta,"Bmu2TrgMatchFilterEta/F");
	nt->Branch("Bmu2TrgMatchFilterPhi",&__Bmu2TrgMatchFilterPhi,"Bmu2TrgMatchFilterPhi/F");
	nt->Branch("Bmumumass",&__Bmumumass,"Bmumumass/F");
	nt->Branch("Bmumueta",&__Bmumueta,"Bmumueta/F");
	nt->Branch("Bmumuphi",&__Bmumuphi,"Bmumuphi/F");
	nt->Branch("Bmumuy",&__Bmumuy,"Bmumuy/F");
	nt->Branch("Bmumupt",&__Bmumupt,"Bmumupt/F");
	nt->Branch("Bujmass",&__Bujmass,"Bujmass/F");
	nt->Branch("BujvProb",&__BujvProb,"BujvProb/F");
	nt->Branch("Bujpt",&__Bujpt,"Bujpt/F");
	nt->Branch("Bujeta",&__Bujeta,"Bujeta/F");
	nt->Branch("Bujphi",&__Bujphi,"Bujphi/F");
	nt->Branch("Bujy",&__Bujy,"Bujy/F");
	nt->Branch("Bujlxy",&__Bujlxy,"Bujlxy/F");

	//BInfo.genInfo
	nt->Branch("Bgen",&__Bgen,"Bgen/F");
	nt->Branch("BgenIndex",&__BgenIndex,"BgenIndex/I");
	nt->Branch("Bgenpt",&__Bgenpt,"Bgenpt/F");
	nt->Branch("Bgeneta",&__Bgeneta,"Bgeneta/F");
	nt->Branch("Bgenphi",&__Bgenphi,"Bgenphi/F");
	nt->Branch("Bgeny",&__Bgeny,"Bgeny/F");
    nt->Branch("BgencollisionId",&__BgencollisionId,"BgencollisionId/I");
}

void fillVal(int i, bool ispp, bool isdata){
	__BDTStage1_pt7to15 = BDTStage1_pt7to15[i];
	__BDTStage1_pt15to50 = BDTStage1_pt15to50[i];

	//BInfo
	__Bindex = Bindex[i];
	__Btype = Btype[i];
	__Bmass = Bmass[i];
	__Bmass_unfitted = Bmass_unfitted[i];
	__Bpt = Bpt[i];
	__Beta = Beta[i];
	__Bphi = Bphi[i];
	__By = By[i];
	__BvtxX = BvtxX[i];
	__BvtxY = BvtxY[i];
	__Bd0 = Bd0[i];
	__Bd0Err = Bd0Err[i];
	__Bdxyz = Bdxyz[i];
	__BdxyzErr = BdxyzErr[i];
	__Bchi2ndf = Bchi2ndf[i];
	__Bchi2cl = Bchi2cl[i];
	__Bdtheta = Bdtheta[i];
	__Blxy = Blxy[i];
	__BlxyBS = BlxyBS[i];
	__BlxyBSErr = BlxyBSErr[i];
	__BMaxDoca = BMaxDoca[i];
	__Balpha = Balpha[i];
	__BsvpvDistance = BsvpvDistance[i];
	__BsvpvDisErr = BsvpvDisErr[i];
	__BsvpvDistance_2D = BsvpvDistance_2D[i];
	__BsvpvDisErr_2D = BsvpvDisErr_2D[i];
	__Bisbestchi2 = Bisbestchi2[i];

	//BInfo.muonInfo
	__Bmu1pt = Bmu1pt[i];
	__Bmu2pt = Bmu2pt[i];
	__Bmu1p = Bmu1p[i];
	__Bmu2p = Bmu2p[i];
	__Bmu1eta = Bmu1eta[i];
	__Bmu2eta = Bmu2eta[i];
	__Bmu1phi = Bmu1phi[i];
	__Bmu2phi = Bmu2phi[i];
	__Bmu1y = Bmu1y[i];
	__Bmu2y = Bmu2y[i];
	__Bmu1dzPV = Bmu1dzPV[i];
	__Bmu2dzPV = Bmu2dzPV[i];
	__Bmu1dxyPV = Bmu1dxyPV[i];
	__Bmu2dxyPV = Bmu2dxyPV[i];
	__Bmu1normchi2 = Bmu1normchi2[i];
	__Bmu2normchi2 = Bmu2normchi2[i];
	__Bmu1Chi2ndf = Bmu1Chi2ndf[i];
	__Bmu2Chi2ndf = Bmu2Chi2ndf[i];
	__Bmu1muqual = Bmu1muqual[i];
	__Bmu2muqual = Bmu2muqual[i];
	__Bmu1TrackerMuArbitrated = Bmu1TrackerMuArbitrated[i];
	__Bmu2TrackerMuArbitrated = Bmu2TrackerMuArbitrated[i];
	__Bmu1isTrackerMuon = Bmu1isTrackerMuon[i];
	__Bmu2isTrackerMuon = Bmu2isTrackerMuon[i];
	__Bmu1isGlobalMuon = Bmu1isGlobalMuon[i];
	__Bmu2isGlobalMuon = Bmu2isGlobalMuon[i];
	__Bmu1TMOneStationTight = Bmu1TMOneStationTight[i];
	__Bmu2TMOneStationTight = Bmu2TMOneStationTight[i];
	__Bmu1striphit = Bmu1striphit[i];
	__Bmu2striphit = Bmu2striphit[i];
	__Bmu1pixelhit = Bmu1pixelhit[i];
	__Bmu2pixelhit = Bmu2pixelhit[i];
	__Bmu1trackerhit = Bmu1trackerhit[i];
	__Bmu2trackerhit = Bmu2trackerhit[i];
	__Bmu1InPixelLayer = Bmu1InPixelLayer[i];
	__Bmu2InPixelLayer = Bmu2InPixelLayer[i];
	__Bmu1InStripLayer = Bmu1InStripLayer[i];
	__Bmu2InStripLayer = Bmu2InStripLayer[i];
	__Bmu1InTrackerLayer = Bmu1InTrackerLayer[i];
	__Bmu2InTrackerLayer = Bmu2InTrackerLayer[i];
	__Bmu1TrkQuality = Bmu1TrkQuality[i];
	__Bmu2TrkQuality = Bmu2TrkQuality[i];
	__Bmu1TrgMatchFilterE = Bmu1TrgMatchFilterE[i];
	__Bmu1TrgMatchFilterPt = Bmu1TrgMatchFilterPt[i];
	__Bmu1TrgMatchFilterEta = Bmu1TrgMatchFilterEta[i];
	__Bmu1TrgMatchFilterPhi = Bmu1TrgMatchFilterPhi[i];
	__Bmu2TrgMatchFilterE = Bmu2TrgMatchFilterE[i];
	__Bmu2TrgMatchFilterPt = Bmu2TrgMatchFilterPt[i];
	__Bmu2TrgMatchFilterEta = Bmu2TrgMatchFilterEta[i];
	__Bmu2TrgMatchFilterPhi = Bmu2TrgMatchFilterPhi[i];

	//BInfo.mumuInfo
	__Bmumumass = Bmumumass[i];
	__Bmumueta = Bmumueta[i];
	__Bmumuphi = Bmumuphi[i];
	__Bmumuy = Bmumuy[i];
	__Bmumupt = Bmumupt[i];

	//BInfo.ujInfo
	__Bujmass = Bujmass[i];
	__BujvProb = BujvProb[i];
	__Bujpt = Bujpt[i];
	__Bujeta = Bujeta[i];
	__Bujphi = Bujphi[i];
	__Bujy = Bujy[i];
	__Bujlxy = Bujlxy[i];

	//BInfo.trkInfo
	__Btrk1Idx = Btrk1Idx[i];
	__Btrk2Idx = Btrk2Idx[i];
	__Btrk1Pt = Btrk1Pt[i];
	__Btrk2Pt = Btrk2Pt[i];
	__Btrk1Eta = Btrk1Eta[i];
	__Btrk2Eta = Btrk2Eta[i];
	__Btrk1Phi = Btrk1Phi[i];
	__Btrk2Phi = Btrk2Phi[i];
	__Btrk1PtErr = Btrk1PtErr[i];
	__Btrk2PtErr = Btrk2PtErr[i];
	__Btrk1EtaErr = Btrk1EtaErr[i];
	__Btrk2EtaErr = Btrk2EtaErr[i];
	__Btrk1PhiErr = Btrk1PhiErr[i];
	__Btrk2PhiErr =Btrk2PhiErr[i];
	__Btrk1Y = Btrk1Y[i];
	__Btrk2Y = Btrk2Y[i];
	__Btrk1Dz = Btrk1Dz[i];
	__Btrk2Dz = Btrk2Dz[i];
	__Btrk1Dxy = Btrk1Dxy[i];
	__Btrk2Dxy = Btrk2Dxy[i];
	__Btrk1D0 = Btrk1D0[i];
	__Btrk2D0 = Btrk2D0[i];
	__Btrk1D0Err = Btrk1D0Err[i];
	__Btrk2D0Err = Btrk2D0Err[i];
	__Btrk1PixelHit = Btrk1PixelHit[i];
	__Btrk2PixelHit = Btrk2PixelHit[i];
	__Btrk1StripHit = Btrk1StripHit[i];
	__Btrk2StripHit = Btrk2StripHit[i];
	__Btrk1nPixelLayer = Btrk1nPixelLayer[i];
	__Btrk2nPixelLayer = Btrk2nPixelLayer[i];
	__Btrk1nStripLayer = Btrk1nStripLayer[i];
	__Btrk2nStripLayer = Btrk2nStripLayer[i];
	__Btrk1Chi2ndf = Btrk1Chi2ndf[i];
	__Btrk2Chi2ndf = Btrk2Chi2ndf[i];
	__Btrk1MVAVal = Btrk1MVAVal[i];
	__Btrk2MVAVal = Btrk2MVAVal[i];
	__Btrk1Algo = Btrk1Algo[i];
	__Btrk2Algo = Btrk2Algo[i];
	__Btrk1highPurity = Btrk1highPurity[i];
	__Btrk2highPurity = Btrk2highPurity[i];
	__Btrk1Quality = Btrk1Quality[i];
	__Btrk2Quality = Btrk2Quality[i];

	//BInfo.tktkInfo
	__Btktkmass = Btktkmass[i];
	__BtktkmassKK = BtktkmassKK[i];
	__BtktkvProb = BtktkvProb[i];
	__Btktkpt = Btktkpt[i];
	__Btktketa = Btktketa[i];
	__Btktkphi = Btktkphi[i];
	__Btktky = Btktky[i];
	__Bdoubletmass = Bdoubletmass[i];
	__Bdoubletpt = Bdoubletpt[i];
	__Bdoubleteta = Bdoubleteta[i];
	__Bdoubletphi = Bdoubletphi[i];
	__Bdoublety = Bdoublety[i];

	//BInfo.genInfo
	__Bgen = Bgen[i];
	__BgenIndex = BgenIndex[i];
	__Bgenpt = Bgenpt[i];
	__Bgeneta = Bgeneta[i];
	__Bgenphi = Bgenphi[i];
	__Bgeny = Bgeny[i];
    __BgencollisionId = BgencollisionId[i];
}

int     Gsize;
float   Gy[MAX_GEN];
float   Geta[MAX_GEN];
float   Gphi[MAX_GEN];
float   Gpt[MAX_GEN];
int     GpdgId[MAX_GEN];
int     GisSignal[MAX_GEN];
int     GcollisionId[MAX_GEN];
float   Gmu1pt[MAX_GEN];
float   Gmu2pt[MAX_GEN];
float   Gmu1p[MAX_GEN];
float   Gmu2p[MAX_GEN];
float   Gmu1eta[MAX_GEN];
float   Gmu2eta[MAX_GEN];
float   Gmu1phi[MAX_GEN];
float   Gmu2phi[MAX_GEN];
float   Gtk1pt[MAX_GEN];
float   Gtk2pt[MAX_GEN];
float   Gtk1eta[MAX_GEN];
float   Gtk2eta[MAX_GEN];
float   Gtk1phi[MAX_GEN];
float   Gtk2phi[MAX_GEN];

void setGenBranchAddress(TTree* nt, bool ispp, bool isdata)
{
	nt->SetBranchAddress("Gsize",&Gsize);
	nt->SetBranchAddress("Gy",Gy);
	nt->SetBranchAddress("Geta",Geta);
	nt->SetBranchAddress("Gphi",Gphi);
	nt->SetBranchAddress("Gpt",Gpt);
	nt->SetBranchAddress("GpdgId",GpdgId);
	nt->SetBranchAddress("GisSignal",GisSignal);
	nt->SetBranchAddress("GcollisionId",GcollisionId);
	nt->SetBranchAddress("Gmu1eta",Gmu1eta);
	nt->SetBranchAddress("Gmu1phi",Gmu1phi);
	nt->SetBranchAddress("Gmu1pt",Gmu1pt);
	nt->SetBranchAddress("Gmu1p",Gmu1p);
	nt->SetBranchAddress("Gmu2eta",Gmu2eta);
	nt->SetBranchAddress("Gmu2phi",Gmu2phi);
	nt->SetBranchAddress("Gmu2pt",Gmu2pt);
	nt->SetBranchAddress("Gmu2p",Gmu2p);
	nt->SetBranchAddress("Gtk1pt",Gtk1pt);
	nt->SetBranchAddress("Gtk1eta",Gtk1eta);
	nt->SetBranchAddress("Gtk1phi",Gtk1phi);
	nt->SetBranchAddress("Gtk2pt",Gtk2pt);
	nt->SetBranchAddress("Gtk2eta",Gtk2eta);
	nt->SetBranchAddress("Gtk2phi",Gtk2phi);
}

float   __Gy;
float   __Geta;
float   __Gphi;
float   __Gpt;
int     __GpdgId;
int     __GisSignal;
int     __GcollisionId;
float   __Gmu1pt;
float   __Gmu2pt;
float   __Gmu1p;
float   __Gmu2p;
float   __Gmu1eta;
float   __Gmu2eta;
float   __Gmu1phi;
float   __Gmu2phi;
float   __Gtk1pt;
float   __Gtk2pt;
float   __Gtk1eta;
float   __Gtk2eta;
float   __Gtk1phi;
float   __Gtk2phi;

void buildGenBranch(TTree* nt, bool ispp, bool isdata)
{
	if(!isdata){
    	nt->Branch("pthat",&pthat);	
    	nt->Branch("pthatweight",&pthatweight);	
	}
	if(!ispp)
    	nt->Branch("hiBin",&hiBin);
	nt->Branch("Gsize",&Gsize);
	nt->Branch("Gy",&__Gy,"Gy/F");
	nt->Branch("Geta",&__Geta,"Geta/F");
	nt->Branch("Gphi",&__Gphi,"Gphi/F");
	nt->Branch("Gpt",&__Gpt,"Gpt/F");
	nt->Branch("GpdgId",&__GpdgId,"GpdgId/I");
	nt->Branch("GisSignal",&__GisSignal,"GisSignal/I");
	nt->Branch("GcollisionId",&__GcollisionId,"GcollisionId/I");
	nt->Branch("Gmu1eta",&__Gmu1eta,"Gmu1eta/F");
	nt->Branch("Gmu1phi",&__Gmu1phi,"Gmu1phi/F");
	nt->Branch("Gmu1pt",&__Gmu1pt,"Gmu1pt/F");
	nt->Branch("Gmu1p",&__Gmu1p,"Gmu1p/F");
	nt->Branch("Gmu2eta",&__Gmu2eta,"Gmu2eta/F");
	nt->Branch("Gmu2phi",&__Gmu2phi,"Gmu2phi/F");
	nt->Branch("Gmu2pt",&__Gmu2pt,"Gmu2pt/F");
	nt->Branch("Gmu2p",&__Gmu2p,"Gmu2p/F");
	nt->Branch("Gtk1pt",&__Gtk1pt,"Gtk1pt/F");
	nt->Branch("Gtk1eta",&__Gtk1eta,"Gtk1eta/F");
	nt->Branch("Gtk1phi",&__Gtk1phi,"Gtk1phi/F");
	nt->Branch("Gtk2pt",&__Gtk2pt,"Gtk2pt/F");
	nt->Branch("Gtk2eta",&__Gtk2eta,"Gtk2eta/F");
	nt->Branch("Gtk2phi",&__Gtk2phi,"Gtk2phi/F");
}

void fillGenVal(int i, bool ispp, bool isdata){
	__Gy = Gy[i];
	__Geta = Geta[i];
	__Gphi = Gphi[i];
	__Gpt = Gpt[i];
	__GpdgId = GpdgId[i];
	__GisSignal = GisSignal[i];
	__GcollisionId = GcollisionId[i];
	__Gmu1pt = Gmu1pt[i];
	__Gmu2pt = Gmu2pt[i];
	__Gmu1p = Gmu1p[i];
	__Gmu2p = Gmu2p[i];
	__Gmu1eta = Gmu1eta[i];
	__Gmu2eta = Gmu2eta[i];
	__Gmu1phi = Gmu1phi[i];
	__Gmu2phi = Gmu2phi[i];
	__Gtk1pt = Gtk1pt[i];
	__Gtk2pt = Gtk2pt[i];
	__Gtk1eta = Gtk1eta[i];
	__Gtk2eta = Gtk2eta[i];
	__Gtk1phi = Gtk1phi[i];
	__Gtk2phi = Gtk2phi[i];
}

