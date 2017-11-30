// -*- C++ -*-
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cut.h
 * Author: candan
 *
 * Created on August 31, 2017, 12:57 PM
 */

#ifndef CUTS_H
#define CUTS_H


//for pp //
TCut mycut="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&"
"((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || "
"(abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8))&& ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && "
"abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && "
"Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && "
"Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 "
"&& Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1highPurity&&Bmass>5&&Bmass<6&&Btrk1Pt>0.7&&Btrk2Pt>0.7&&"
"Bchi2cl>1.32e-02&&(Bd0/Bd0Err)>2.&&cos(Bdtheta)>2.60e-01&&Blxy>0.025&&abs(Btktkmass-1.019455)<1.55e-02";

//Event InfoFinder
TLorentzVector* b4P = new TLorentzVector;;

b4P->SetPtEtaPhiM(BInfo->pt[j],BInfo->eta[j],BInfo->phi[j],BInfo->mass[j]);
float By =b4P->Rapidity();
//1st muon
b4P->SetPtEtaPhiM(MuonInfo->pt[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]],MuonInfo->eta[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]],MuonInfo->phi[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]],MUON_MASS);  
Float_t mu1px,mu1py,mu1pz,mu1E;
mu1px = b4P->Px();
mu1py = b4P->Py();
mu1pz = b4P->Pz();
mu1E = b4P->E();


//2nd muon 
b4P->SetPtEtaPhiM(MuonInfo->pt[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]],MuonInfo->eta[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]],MuonInfo->phi[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]],MUON_MASS);
Float_t mu2px,mu2py,mu2pz,mu2E;
mu2px = b4P->Px();
mu2py = b4P->Py();
mu2pz = b4P->Pz();
mu2E = b4P->E();    

//Bmumu mass      
b4P->SetPxPyPzE(mu1px+mu2px,mu1py+mu2py,mu1pz+mu2pz,mu1E+mu2E); 
float Bmumumass= b4P->Mag(); 

//Bmu1pt ve Bmu1eta cut 
float Bmu1pt = MuonInfo->pt[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
float Bmu1eta = MuonInfo->eta[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]; 
float Bmu2pt = MuonInfo->pt[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];
float Bmu2eta = MuonInfo->eta[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];


///Bmu1TMOneStationTight & Bmu2TMOneStationTight  boolen

bool Bmu1TMOneStationTight = MuonInfo->TMOneStationTight[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];  
bool Bmu2TMOneStationTight = MuonInfo->TMOneStationTight[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];

//Bmu1InPixelLayer && Bmu2InPixelLayer       
int Bmu1InPixelLayer = MuonInfo->i_nPixelLayer[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]; 
int Bmu2InPixelLayer= MuonInfo->i_nPixelLayer[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];   

//Bmu1InStripLayer && Bmu2InStripLayer 
int Bmu1InStripLayer = MuonInfo->i_nStripLayer[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
int Bmu2InStripLayer = MuonInfo->i_nStripLayer[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]; 

//Bmu1dxyPV && Bmu2dxyPV
float Bmu1dxyPV = MuonInfo->dxyPV[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];                                                                           
float Bmu2dxyPV = MuonInfo->dxyPV[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];

//Bmu1dzPV && Bmu2dzPV
float Bmu1dzPV = MuonInfo->dzPV[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];                                                                             
float Bmu2dzPV = MuonInfo->dzPV[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];

//Bmu1isGlobalMuon && Bmu2isGlobalMuon
bool Bmu1isGlobalMuon= MuonInfo->isGlobalMuon[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];                                                               
bool Bmu2isGlobalMuon= MuonInfo->isGlobalMuon[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]; 

bool Btrk1highPurity = TrackInfo->highPurity[BInfo->rftk1_index[j]]; 
bool Btrk2highPurity = TrackInfo->highPurity[BInfo->rftk2_index[j]]; 

float Bmu1TrgMatchFilterE = MuonInfo->MuTrgMatchFilterTrgObjE[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];
float Bmu2TrgMatchFilterE = MuonInfo->MuTrgMatchFilterTrgObjE[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]*MuonInfo->MuTrgMatchFilterSize+0];

//Bmass
float Bmass = BInfo->mass[j];
float Bpt = BInfo->pt[j];

float Btrk1Pt = TrackInfo->pt[BInfo->rftk1_index[j]];  
float Btrk2Pt = TrackInfo->pt[BInfo->rftk2_index[j]];
float Btrk1Eta = TrackInfo->eta[BInfo->rftk1_index[j]];  
float Btrk2Eta = TrackInfo->eta[BInfo->rftk2_index[j]];

//Bchi2cl
float Bchi2cl= TMath::Prob(BInfo->vtxchi2[j],BInfo->vtxdof[j]);
//(Bd0/Bd0Err)
float Bd0= TMath::Sqrt((BInfo->vtxX[j]-EvtInfo->PVx)*(BInfo->vtxX[j]-EvtInfo->PVx)+(BInfo->vtxY[j]-EvtInfo->PVy)*(BInfo->vtxY[j]-EvtInfo->PVy));                                                                                                                                    
float Bd0Err = TMath::Sqrt(BInfo->vtxXErr[j]*BInfo->vtxXErr[j]+BInfo->vtxYErr[j]*BInfo->vtxYErr[j]);

//Blxy
float Blxy = ((BInfo->vtxX[j]-EvtInfo->PVx)*b4P->Px() + (BInfo->vtxY[j]-EvtInfo->PVy)*b4P->Py())/BInfo->pt[j]; 

//Btktkmass
//first track:

b4P->SetPtEtaPhiM(TrackInfo->pt[BInfo->rftk2_index[j]],TrackInfo->eta[BInfo->rftk2_index[j]],TrackInfo->phi[BInfo->rftk2_index[j]],KAON_MASS);       
float  tk1px = b4P->Px();
float  tk1py = b4P->Py();
float  tk1pz = b4P->Pz();
float  tk1E = b4P->E();

//2nd track
b4P->SetPtEtaPhiM(TrackInfo->pt[BInfo->rftk1_index[j]],TrackInfo->eta[BInfo->rftk1_index[j]],TrackInfo->phi[BInfo->rftk1_index[j]],KAON_MASS);
float   tk2px = b4P->Px();
float   tk2py = b4P->Py();
float   tk2pz = b4P->Pz();
float   tk2E = b4P->E();

//Btktkmass
b4P->SetPxPyPzE(tk1px+tk2px,tk1py+tk2py,tk1pz+tk2pz,tk1E+tk2E);                     
float Btktkmass = b4P->Mag();

//cos(Bdtheta)
TVector3* bP = new TVector3;
TVector3* bVtx = new TVector3;
bP->SetPtEtaPhi(BInfo->pt[j],BInfo->eta[j]*0,BInfo->phi[j]);
bVtx->SetXYZ(BInfo->vtxX[j]-EvtInfo->PVx,
		BInfo->vtxY[j]-EvtInfo->PVy,
		BInfo->vtxZ[j]*0-EvtInfo->PVz*0);
float Bdtheta = bP->Angle(*bVtx);


#endif /* CUTS_H */

