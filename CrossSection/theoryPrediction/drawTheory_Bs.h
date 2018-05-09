#include <iostream>
#include <fstream>
#include "TGraph.h"
Color_t colorTAMU_Bs = kOrange+8;
Style_t styleTAMU_Bs = 1001;
using namespace std;
void plotTheory_Bs()
{
	const int n = 1000;
	Int_t nbin=0;
	Float_t temp;
	Float_t aCx[n],aCy[n];
	Float_t bCx[n],bCy[n],bCye[n],bDummy[n];
	Float_t cCx[n],cCy[n],cCye[n],cDummy[n];

	// TAMU
	ifstream getdata("theoryPrediction/theorypre_Bs/TAMU_20180509.txt");
	if(!getdata.is_open()) {
		cout<<"Opening the file fails: TAMU"<<endl;
		return;
	}
	nbin=0;
	while(!getdata.eof())
	{
		getdata>>aCx[nbin]>>aCy[nbin];
		if(aCx[nbin] != 0 && aCy[nbin] != 0)
			nbin++;
	}
	Float_t* aTAMUB5TeVx = new Float_t[nbin];
	Float_t* aTAMUB5TeVxe = new Float_t[nbin];
	Float_t* aTAMUB5TeVy = new Float_t[nbin];
	Float_t* aTAMUB5TeVye = new Float_t[nbin];
	for(int i=0;i<nbin;i++)
	{
		aTAMUB5TeVx[i] = aCx[i];
		aTAMUB5TeVxe[i] = 0;
		aTAMUB5TeVy[i] = aCy[i];
		aTAMUB5TeVye[i] = 0.;
	}
	TGraphErrors* gTAMUB5TeV = new TGraphErrors(nbin, aTAMUB5TeVx, aTAMUB5TeVy, aTAMUB5TeVxe, aTAMUB5TeVye);
	gTAMUB5TeV->SetName("gTAMUB5TeV");
	gTAMUB5TeV->SetLineColor(colorTAMU_Bs);
	gTAMUB5TeV->SetFillColor(colorTAMU_Bs);
	gTAMUB5TeV->SetFillStyle(styleTAMU_Bs);
	gTAMUB5TeV->SetLineWidth(4);
	//gTAMUB5TeV->Draw("3 same");
	gTAMUB5TeV->Draw("L same");
}
