#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
#include "../../prefilter.h"
#define MAX_XB       20000

void ProdMVAVal_candWise(string colsys = "pp", float ptMin = 5, float ptMax = 7, string mvatype = "MLP", int varStage = 5, TString inputS = "", TString inputB = ""){
    std::size_t found = mvatype.find("Cuts");
    if (found!=std::string::npos) return;

	void makeoutput(TString infname, TString ofname, string colsys, string mvatype, int varStage);

	isPbPb = (colsys=="pp") ? 0 : 1;
	ptmin = ptMin;
	ptmax = ptMax;

	TString outfile1 =Form("MVAfiles/%s_%s_%.0f_%.0f_varStage%d_DATA.root",mvatype.c_str(),colsys.c_str(),ptMin,ptMax,varStage) ;
	makeoutput(inputB,outfile1,colsys,mvatype,varStage);
	TString outfile2 =Form("MVAfiles/%s_%s_%.0f_%.0f_varStage%d_MC.root",mvatype.c_str(),colsys.c_str(),ptMin,ptMax,varStage) ;
	makeoutput(inputS,outfile2,colsys,mvatype,varStage);
}
void makeoutput(TString infname, TString ofname, string colsys, string mvatype, int varStage){
	// Read the input tree
	TFile *inf = new TFile(infname);
	TTree *t = (TTree*)inf->Get("ntphi");
	Int_t           Bsize;
	Float_t         Btrk1Pt;   
	Float_t         Btrk2Pt;   
	Float_t         Btrk1Eta;   
	Float_t         Btrk2Eta;   
	Float_t         Bchi2cl;   
	Float_t         BsvpvDistance;   
	Float_t         BsvpvDisErr;   
	Float_t         Bdtheta;   
	Float_t         By;   
	Float_t         Btktkmass;      
	Float_t         Btktky;      
	Float_t         Blxy;      
	Float_t	        Btrk1Dxy;
	Float_t         Btrk1D0Err;
	Float_t	        Btrk2Dxy;
	Float_t         Btrk2D0Err;
	Float_t         Bd0;      
	Float_t         Bd0Err;      
	Float_t         Btktkpt;
	Float_t         Btktketa;
	Float_t         Balpha;
	Float_t         Bmu1pt;      
	Float_t         Bmu2pt;      

	t->SetBranchAddress("Bsize", &Bsize);
	t->SetBranchAddress("Btrk1Pt", &Btrk1Pt);
	t->SetBranchAddress("Btrk2Pt", &Btrk2Pt);
	t->SetBranchAddress("Btrk1Eta", &Btrk1Eta);
	t->SetBranchAddress("Btrk2Eta", &Btrk2Eta);
	t->SetBranchAddress("Bchi2cl", &Bchi2cl);
	t->SetBranchAddress("BsvpvDistance", &BsvpvDistance);
	t->SetBranchAddress("BsvpvDisErr", &BsvpvDisErr);
	t->SetBranchAddress("Bdtheta", &Bdtheta);
	t->SetBranchAddress("By", &By);
	t->SetBranchAddress("Btktkmass", &Btktkmass);
	t->SetBranchAddress("Btktky", &Btktky);
	t->SetBranchAddress("Blxy", &Blxy);
	t->SetBranchAddress("Btrk1Dxy", &Btrk1Dxy);
	t->SetBranchAddress("Btrk1D0Err", &Btrk1D0Err);
	t->SetBranchAddress("Btrk2Dxy", &Btrk2Dxy);
	t->SetBranchAddress("Btrk2D0Err", &Btrk2D0Err);
	t->SetBranchAddress("Bd0", &Bd0);
	t->SetBranchAddress("Bd0Err", &Bd0Err);
	t->SetBranchAddress("Btktkpt", &Btktkpt);
	t->SetBranchAddress("Btktketa", &Btktketa);
	t->SetBranchAddress("Balpha", &Balpha);
	t->SetBranchAddress("Bmu1pt", &Bmu1pt);
	t->SetBranchAddress("Bmu2pt", &Bmu2pt);

	// Declare the TMVA reader
	TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );
	TString weightfile = Form("../../myTMVA/dataset/weights/TMVA_%s_%s_%.0f_%.0f_varStage%d.weights.xml",mvatype.c_str(),colsys.c_str(),ptmin,ptmax,varStage);
	TString methodName = Form("%s method",mvatype.c_str());
	Float_t         __Btrk1Pt;
	Float_t         __Btrk2Pt;   
	Float_t         __Btrk1Eta;
	Float_t         __Btrk2Eta;   
	Float_t         __Bchi2cl;   
	Float_t         __BsvpvDistance_Over_BsvpvDisErr;
	Float_t         __Bdtheta_cos;   
	Float_t         __By;   
	Float_t         __Btktkmass_abs;      
	Float_t         __Btktky;      
	Float_t         __Blxy;      
	Float_t         __Btrk1Dxy_Over_Btrk1D0Err;
	Float_t         __Btrk2Dxy_Over_Btrk2D0Err;
	Float_t         __Bd0_Over_Bd0Err;      
	Float_t         __Btktkpt;
	Float_t         __Btktketa;
	Float_t         __Balpha;
	Float_t         __Bmu1pt;      
	Float_t         __Bmu2pt;      
	if(varStage>=1){
		reader->AddVariable("Btrk1Pt", &__Btrk1Pt);
		reader->AddVariable("Btrk2Pt", &__Btrk2Pt);
		reader->AddVariable("Btrk1Eta", &__Btrk1Eta);
		reader->AddVariable("Btrk2Eta", &__Btrk2Eta);
		reader->AddVariable("Btrk1Dxy/Btrk1D0Err", &__Btrk1Dxy_Over_Btrk1D0Err);
		reader->AddVariable("Btrk2Dxy/Btrk2D0Err", &__Btrk2Dxy_Over_Btrk2D0Err);
		reader->AddVariable("abs(Btktkmass-1.019455)", &__Btktkmass_abs);
		reader->AddVariable("BsvpvDistance/BsvpvDisErr", &__BsvpvDistance_Over_BsvpvDisErr);
		reader->AddVariable("Balpha", &__Balpha);
	}
	if(varStage>=2){
		reader->AddVariable("Bd0/Bd0Err", &__Bd0_Over_Bd0Err);
		reader->AddVariable("cos(Bdtheta)", &__Bdtheta_cos);
	}
	if(varStage>=3){
		reader->AddVariable("Bchi2cl", &__Bchi2cl);
		reader->AddVariable("Blxy", &__Blxy);
		reader->AddVariable("Btktkpt", &__Btktkpt);
		reader->AddVariable("By", &__By);
		reader->AddVariable("Btktketa", &__Btktketa);
		//reader->AddVariable("Btktky", &__Btktky);
		//reader->AddVariable("Bmu1pt", &__Bmu1pt);
		//reader->AddVariable("Bmu2pt", &__Bmu2pt);
	}
	reader->BookMVA( methodName, weightfile );	

	TFile *outf = new TFile(ofname,"recreate");

	string varname = Form("%sStage%d_pt%.0fto%.0f",mvatype.c_str(),varStage,ptmin,ptmax);
	TTree *mvaTree = new TTree(varname.c_str(),varname.c_str());
	float MVAVal;
	mvaTree->Branch("Bsize",&Bsize,"Bsize/I");
	mvaTree->Branch(varname.c_str(),  &MVAVal,  Form("%s/F",varname.c_str()));
	for(int i=0;i<t->GetEntries();i++)
	{
		t->GetEntry(i);
		if(i%1000000==0) cout <<i<<" / "<<t->GetEntries()<<endl;
		__Btrk1Pt = Btrk1Pt;   
		__Btrk2Pt = Btrk2Pt;   
		__Btrk1Eta = Btrk1Eta;   
		__Btrk2Eta = Btrk2Eta;   
		__Bchi2cl = Bchi2cl;   
		__BsvpvDistance_Over_BsvpvDisErr = BsvpvDistance/BsvpvDisErr;   
		__Bdtheta_cos = cos(Bdtheta);   
		__By = By;   
		__Btktkmass_abs = fabs(Btktkmass-1.019455);      
		__Btktky = Btktky;      
		__Blxy = Blxy;      
		__Btrk1Dxy_Over_Btrk1D0Err = Btrk1Dxy/Btrk1D0Err;
		__Btrk2Dxy_Over_Btrk2D0Err = Btrk2Dxy/Btrk2D0Err;
		__Bd0_Over_Bd0Err = Bd0/Bd0Err;      
		__Btktkpt = Btktkpt;
		__Btktketa = Btktketa;
		__Balpha = Balpha;
		__Bmu1pt = Bmu1pt;      
		__Bmu2pt = Bmu2pt;      
		MVAVal = reader->EvaluateMVA(methodName);
		mvaTree->Fill();
	}
	outf->cd();
	outf->Write();
	outf->Close();
}
