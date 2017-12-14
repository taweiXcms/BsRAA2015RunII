#include <stdio.h>
#include <math.h>
#include <TTree.h>
#include <TH1.h>
#include <TROOT.h>
#include <TFile.h>
#include <TF1.h>


double gaussianRandom(double average, double stdev);
void getfit();

// pp or PbPb
string label;

const int nBinsy=4;
double yBins[nBinsy+1] = {0.0, 0.5, 1.0, 1.5, 2.4};
double Ratylab[nBinsy];
double RatErrylab[nBinsy];
double RatToyylab[nBinsy];
double ay1,ay2;

TH1D* htest;
TH1D* hfity;
TF1* fsecpol;
TTree* ditTree;

void step3RunMCtoy_gaus_yvar_20141031(bool ispp=1) {
    if(ispp) label = "pp";
    else label = "PbPb";

    TFile* fIn = new TFile(Form("../step2_GettheRatio/FunctionsReweighting_Bs_%s.root", label.c_str()),"read");
    TH1D*hReweightDataOverMC_y=(TH1D*)fIn->Get("hReweightDataOverMC_y");
    TFile* fOut = new TFile(Form("gaus_try10k_yvar_%s.root", label.c_str()),"RECREATE");

	hfity = new TH1D("hfity","",nBinsy,yBins);
	htest = new TH1D("htest","",200,0.00,2.00);
	fsecpol = new TF1("fsecpol","[0]*pow((x),2)+[1]",-2.4,2.4);

    for (int i=0;i<nBinsy;i++) {
        Ratylab[i]=hReweightDataOverMC_y->GetBinContent(i+1);
        RatErrylab[i]=hReweightDataOverMC_y->GetBinError(i+1);
        //std::cout << Ratylab[i] << " , " << RatErrylab[i] << std::endl;
    }

	ditTree = new TTree("ditTree","Test tree");
	ditTree->Branch("ay1",&ay1,"ay1/D");
	ditTree->Branch("ay2",&ay2,"ay2/D");

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++){
		hfity->Clear();
        for (int count=0;count<nBinsy;count++) {
			RatToyylab[count]=gaussianRandom(Ratylab[count],RatErrylab[count]);
			//printf("%.17f\n", RatToyylab[count]);
			hfity->SetBinContent(count+1,RatToyylab[count]);
			hfity->SetBinError(count+1,RatErrylab[count]);
			if (count==0) htest->Fill(RatToyylab[count]);
		}
		getfit();
	}
	fOut->Write();
	fOut->Close();
}


double gaussianRandom(double average, double stdev) {
	double v1, v2, s, temp;

	do {
		v1 =  2 * ((double) rand() / RAND_MAX) - 1;
		v2 =  2 * ((double) rand() / RAND_MAX) - 1;
		s = v1 * v1 + v2 * v2;
	} while (s >= 1 || s == 0);

	s = sqrt( (-2 * log(s)) / s );
	temp = v1*s;
	temp = (stdev*temp)+average;
	return temp;
}

void getfit() {
	hfity->Fit("fsecpol","q");
	ay1=fsecpol->GetParameter(0);
	ay2=fsecpol->GetParameter(1);
	ditTree->Fill();
	return;
}
