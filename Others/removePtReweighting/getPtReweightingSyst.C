#include "TFile.h"
#include "TH1.h"
#include "iostream"
using namespace std;
void getPtReweightingSyst(){
	TFile* fppOrigin = new TFile("../../CrossSection/ROOTfiles/MCstudiesPP.root");
	TH1D* hppOrigin = (TH1D*)fppOrigin->Get("hEff");
	TFile* fppAlt = new TFile("ROOTfiles/MCstudiesPP.root");
	TH1D* hppAlt = (TH1D*)fppAlt->Get("hEff");
	TFile* fpbpbOrigin = new TFile("../../CrossSection/ROOTfiles/MCstudiesPbPb.root");
	TH1D* hpbpbOrigin = (TH1D*)fpbpbOrigin->Get("hEff");
	TFile* fpbpbAlt = new TFile("ROOTfiles/MCstudiesPbPb.root");
	TH1D* hpbpbAlt = (TH1D*)fpbpbAlt->Get("hEff");
	TFile* fppOrigin_1050 = new TFile("../../CrossSection/ROOTfiles/MCstudiesPP_1050.root");
	TH1D* hppOrigin_1050 = (TH1D*)fppOrigin_1050->Get("hEff");
	TFile* fppAlt_1050 = new TFile("ROOTfiles/MCstudiesPP_1050.root");
	TH1D* hppAlt_1050 = (TH1D*)fppAlt_1050->Get("hEff");

	printf("Origin: %f, Alt: %f\n",hppOrigin->GetBinContent(1), hppAlt->GetBinContent(1));
	printf("double ptshape_pp[1] = {%f}\n",abs(hppOrigin->GetBinContent(1)-hppAlt->GetBinContent(1))/hppOrigin->GetBinContent(1)*100);
	printf("Origin: %f, Alt: %f\n",hpbpbOrigin->GetBinContent(1), hpbpbAlt->GetBinContent(1));
	printf("double ptshape_PbPb[1] = {%f}\n",abs(hpbpbOrigin->GetBinContent(1)-hpbpbAlt->GetBinContent(1))/hpbpbOrigin->GetBinContent(1)*100);
	printf("Origin: %f, Alt: %f\n",hppOrigin_1050->GetBinContent(1), hppAlt_1050->GetBinContent(1));
	printf("Origin: %f, Alt: %f\n",hppOrigin_1050->GetBinContent(2), hppAlt_1050->GetBinContent(2));
	printf("Origin: %f, Alt: %f\n",hppOrigin_1050->GetBinContent(3), hppAlt_1050->GetBinContent(3));
	printf("Origin: %f, Alt: %f\n",hppOrigin_1050->GetBinContent(4), hppAlt_1050->GetBinContent(4));
	printf("double ptshape_pp_1050[4] = {%f, %f, %f, %f}\n",abs(hppOrigin_1050->GetBinContent(1)-hppAlt_1050->GetBinContent(1))/hppOrigin_1050->GetBinContent(1)*100, abs(hppOrigin_1050->GetBinContent(2)-hppAlt_1050->GetBinContent(2))/hppOrigin_1050->GetBinContent(2)*100, abs(hppOrigin_1050->GetBinContent(3)-hppAlt_1050->GetBinContent(3))/hppOrigin_1050->GetBinContent(3)*100, abs(hppOrigin_1050->GetBinContent(4)-hppAlt_1050->GetBinContent(4))/hppOrigin_1050->GetBinContent(4)*100);
}
