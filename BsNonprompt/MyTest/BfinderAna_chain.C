#include "format.h"
#include "BfinderAna.h"
using namespace std;
Bool_t istest = false;
void printDa(GenInfoBranches *GenInfo, int idx, int space);
int getBAncestor(GenInfoBranches *GenInfo, int idx, int BancestorId);
int matcher(BInfoBranches *BInfo, TrackInfoBranches *TrackInfo, MuonInfoBranches *MuonInfo, GenInfoBranches *GenInfo, int j, float BId, float MId, float tk1Id, float tk2Id, bool twoTks);
int BfinderAna_chain(
		TString infile="/data/HeavyFlavourRun2/BfinderRun2/MC_official/BfinderMC_pp_BJpsiMM_5p02TeV_TuneCUETP8M1_20171128_bPt0jpsiPt0tkPt0p0_Bs_BDTStage1_pt15to50.root",
		TString outfile="BJpsiMM_pp_NP.root",
		Bool_t REAL=false,
		Bool_t isPbPb=false,
		Int_t startEntries=0,
		Int_t endEntries=-1 ,
		Bool_t skim=false,
		Bool_t gskim=true,
		Bool_t checkMatching=false,
		Bool_t iseos=false,
		Bool_t SkimHLTtree=false)
{
	cout<<endl;
	if(REAL) cout<<"--- Processing - REAL DATA";
	else cout<<"--- Processing - MC";
	if(isPbPb) cout<<" - PbPb";
	else cout<<" - pp";
	cout<<endl;

	TString ifname;
	if(iseos) ifname = Form("root://eoscms.cern.ch//eos/cms%s",infile.Data());
	else ifname = infile;
	/** 
	  TFile* f = TFile::Open(ifname);
	  TTree* root = (TTree*)f->Get("Bfinder/root");
	  TTree* hltroot = (TTree*)f->Get("hltanalysis/HltTree");
	  TTree* skimroot = (TTree*)f->Get("skimanalysis/HltTree");
	  TTree* hiroot = (TTree*)f->Get("hiEvtAnalyzer/HiTree");
	  */

	/// chain
	TChain *ch1   = new TChain("root","BRoot");
	TChain* ch2   = new TChain("hltanalysis","HltAna" );
	TChain* ch3   = new TChain("skimanalysis","SkimHlt");
	TChain* ch4   = new TChain("hiEvtAnalyzer","HiAna");

	ch1->Add(infile);
	ch2->Add(infile);
	ch3->Add(infile);
	ch4->Add(infile);

	/// end of chain 

	EvtInfoBranches     *EvtInfo = new EvtInfoBranches;
	VtxInfoBranches     *VtxInfo = new VtxInfoBranches;
	MuonInfoBranches    *MuonInfo = new MuonInfoBranches;
	TrackInfoBranches   *TrackInfo = new TrackInfoBranches;
	BInfoBranches       *BInfo = new BInfoBranches;
	GenInfoBranches     *GenInfo = new GenInfoBranches;
	/// 
	setHltBranch(ch2, isPbPb);
	setHiTreeBranch(ch4);
	EvtInfo->setbranchadd(ch1);
	VtxInfo->setbranchadd(ch1);
	MuonInfo->setbranchadd(ch1);
	TrackInfo->setbranchadd(ch1);
	BInfo->setbranchadd(ch1);
	GenInfo->setbranchadd(ch1);
	/** 
	  setHltBranch(hltroot);
	  setHiTreeBranch(hiroot);

	  EvtInfo->setbranchadd(root);
	  VtxInfo->setbranchadd(root);
	  MuonInfo->setbranchadd(root);
	  TrackInfo->setbranchadd(root);
	  BInfo->setbranchadd(root);
	  GenInfo->setbranchadd(root);
	  */
	/// Long64_t nentries = root->GetEntries();  /// 
	Long64_t nentries = ch1->GetEntries(); /// 
	if(endEntries>nentries || endEntries == -1) endEntries = nentries;
	TFile *outf = TFile::Open(Form("%s", outfile.Data()),"recreate");

	cout<<"--- Check the number of events for four trees"<<endl;
	/** 
	  cout<<root->GetEntries()<<" "<<hltroot->GetEntries()<<" "<<hiroot->GetEntries();
	  cout<<" "<<skimroot->GetEntries()<<endl;
	  cout<<endl;
	  */
	///
	cout << ch1->GetEntries() << " " << ch2->GetEntries() << " " << ch3->GetEntries();
	cout << " " << ch4->GetEntries() << endl;
	cout << endl;
	//
	double min = 4.6;
	double max = 6.0;
	int nbin = (max-min)*50;
	/// Define Histograms
	TH1D* hBpt = new TH1D("hBpt","hBpt", 50, 0, 100);                             //All B particles histogram.(Bs,B0.B+...)
	TH1D* Bmass = new TH1D("Bmass","Bmass", nbin, min, max);                             //All B particles histogram.(Bs,B0.B+...)
	//TH1D* Bmass_nosig = new TH1D("Bmass_nosig","Bmass_nosig", nbin, min, max);

	TH1D* BmassBs = new TH1D("BmassBs","BmassBs", nbin, min, max);                      //Bs signal
	TH1D* BmassBs_nosig = new TH1D("BmassBs_nosig","BmassBs_nosig", nbin, min, max);

	TH1D* BmassBsPiK = new TH1D("BmassBsPiK","BmassBsPiK", nbin, min, max);              //1.fake X -> J/psi + Pi-  K+ (pi misconsider as K)
	//TH1D* BmassBsXPiK = new TH1D("BmassBsXPiK","BmassBsXPiK", nbin, min, max);           //else 1.fake

	TH1D* BmassBsKK = new TH1D("BmassBsKK","BmassBsKK", nbin, min, max);                 //2nd fake is Bs -> J/psi + K+ K- (not make phi meson)
	// TH1D* BmassBsXKK = new TH1D("BmassBsXKK","BmassBsXKK", nbin, min, max);              // else 2ndk fake

	//    TH1D* BmassBsKKfake = new TH1D("BmassBsKKfake","BmassBsKKfake", nbin, min, max);     //3. fake B+ -> J/psi + K+ (and added K-)
	TH1D* BmassBsKKfake_binfo = new TH1D("BmassBsKKfake_binfo","BmassBsKKfake_binfo", nbin, min, max);//else 3. fake B+ -> J/psi + K+ (and added K-)

	TH1D* BmassBsXpipi = new TH1D("BmassBsXpipi","BmassBsXpipi", nbin, min, max);       //4th fake is X -> J/psi + pion+ pion- (mis-c    onsider as pion)

	TH1D* BmassBsKKX = new TH1D("BmassBsKKX","BmassBsKKX", nbin, min, max);             //5th fake is Bs -> J/psi + kaon+ + kaon- + something

	Bmass->SetMinimum(0);
	//Bmass_nosig->SetMinimum(0);

	BmassBs->SetMinimum(0);
	BmassBs_nosig->SetMinimum(0);

	BmassBsPiK->SetMinimum(0);
	//BmassBsXPiK->SetMinimum(0);

	BmassBsKK->SetMinimum(0);
	// BmassBsXKK->SetMinimum(0);

	//  BmassBsKKfake->SetMinimum(0);
	BmassBsKKfake_binfo->SetMinimum(0);

	BmassBsXpipi->SetMinimum(0);
	BmassBsKKX->SetMinimum(0);

	std::map<int,int> BtypeCountBpK;
	std::map<int,int> BtypeCountB0K;
	cout<<"--- Processing events"<<endl;
	for(Int_t i=startEntries;i<endEntries;i++)
	{
		/** 
		  root->GetEntry(i);
		  hltroot->GetEntry(i);
		  skimroot->GetEntry(i);
		  hiroot->GetEntry(i);
		  */
		/// 
		ch1->GetEntry(i);
		ch2->GetEntry(i);
		ch3->GetEntry(i);
		ch4->GetEntry(i);

		if(i%100000==0) cout<<setw(7)<<i<<" / "<<endEntries<<endl;
		if(checkMatching)
		{
			if(((int)Bf_HLT_Event!=EvtInfo->EvtNo||(int)Bf_HLT_Run!=EvtInfo->RunNo||(int)Bf_HLT_LumiBlock!=EvtInfo->LumiNo) ||
					((int)Bf_HiTree_Evt!=EvtInfo->EvtNo||(int)Bf_HiTree_Run!=EvtInfo->RunNo||(int)Bf_HiTree_Lumi!=EvtInfo->LumiNo))
			{
				cout<<"Error: not matched "<<i<<" | (Hlt,Bfr,Hi) | ";
				cout<<"EvtNo("<<Bf_HLT_Event<<","<<EvtInfo->EvtNo<<","<<Bf_HiTree_Evt<<") ";
				cout<<"RunNo("<<Bf_HLT_Run<<","<<EvtInfo->RunNo<<","<<Bf_HiTree_Run<<") ";
				cout<<"LumiNo("<<Bf_HLT_LumiBlock<<","<<EvtInfo->LumiNo<<","<<Bf_HiTree_Lumi<<")"<<endl;
				continue;
			}
		}
		//Do oyur analysis here
		//example: checking GenInfo


		for(int j=0;j<GenInfo->size;j++){
			if( int(GenInfo->pdgId[j]/100)%100 == 5){
				//                  cout<<GenInfo->pdgId[j]<<endl;
				//      	    if(GenInfo->da1[j] != -1)
				//		    if(GenInfo->nDa[j]==3)
				//		    if(abs(GenInfo->pdgId[GenInfo->da1[j]]) == 443 || abs(GenInfo->pdgId[GenInfo->da2[j]]) == 211 || abs(GenInfo->pdgId[GenInfo->da3[j]])==321 ){
				//                 cout<<"dau1=="<<abs(GenInfo->pdgId[GenInfo->da1[j]]) <<"dau2=="<< abs(GenInfo->pdgId[GenInfo->da2[j]])<< "dau3=="<< abs(GenInfo->pdgId[GenInfo->da3[j]])<<endl;// printDa(GenInfo, j, 1);
				//                   }


				if(abs(GenInfo->pdgId[j])==531)
					if(GenInfo->da1[j] != -1)
						if(abs(GenInfo->pdgId[GenInfo->da1[j]]) == 443)
							if(abs(GenInfo->pdgId[GenInfo->da2[j]]) == 333)
							{
								// printDa(GenInfo, j, 1);
							}

				if(abs(GenInfo->pdgId[j])==531)
					if(GenInfo->da1[j] != -1)
						if(abs(GenInfo->pdgId[GenInfo->da1[j]]) == 443)
							if((abs(GenInfo->pdgId[GenInfo->da2[j]])/100)%100 == 3)
							{
								//   printDa(GenInfo, j, 1);
							}

				if(abs(GenInfo->pdgId[j])==511)
					if(GenInfo->da1[j] != -1)
						if(abs(GenInfo->pdgId[GenInfo->da1[j]]) == 443)
							if((abs(GenInfo->pdgId[GenInfo->da2[j]])/100)%100 == 3)
							{
								//printDa(GenInfo, j, 1);
							}

			}
		}

		bool isBsig = false;
		for(int j=0;j<BInfo->size;j++){
			int rtk1idx = BInfo->rftk1_index[j];
			int rtk2idx = BInfo->rftk2_index[j];
			int rmu1idx = BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]];
			int rmu2idx = BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]];
			int gtk1idx =  TrackInfo->geninfo_index[BInfo->rftk1_index[j]];
			int gtk2idx =  TrackInfo->geninfo_index[BInfo->rftk2_index[j]];
			int gmu1idx =  MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]];
			int gmu2idx =  MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]];

			//some recon cut
			bool cut = false;

			if(
					BInfo->mass[j] > min && BInfo->mass[j] < max && BInfo->pt[j] > 10 && BInfo->pt[j] < 1000
					&& fabs(BInfo->eta[j]) < 2.4
			  ){
				cut = true;
			}


			//identify B sig //all B particles
			hBpt->Fill(BInfo->pt[j]);
			Bmass->Fill(BInfo->mass[j]);
			bool isBsig = false;
			/*
			   if(gmu1idx != -1 && gmu2idx != -1)
			   if(abs(GenInfo->pdgId[gmu1idx]) == 13 && abs(GenInfo->pdgId[gmu2idx]) == 13)
			   if((GenInfo->mo1[gmu1idx]) != -1 && (GenInfo->mo1[gmu2idx]) != -1 && GenInfo->mo1[gmu1idx] == GenInfo->mo1[gmu2idx])
			   if(abs(GenInfo->pdgId[GenInfo->mo1[gmu1idx]]) == 443 && abs(GenInfo->pdgId[GenInfo->mo1[gmu2idx]]) == 443)
			   if(GenInfo->mo1[GenInfo->mo1[gmu1idx]] != -1)
			   if(gtk1idx != -1)
			   if(GenInfo->mo1[gtk1idx] != -1)
			   if(GenInfo->mo1[gtk1idx] == GenInfo->mo1[GenInfo->mo1[gmu1idx]] && abs(GenInfo->pdgId[GenInfo->mo1[gtk1idx]]) == 531 && abs(GenInfo->pdgId[gtk1idx]) == 321)
			   isBsig = true;
			   */
			//  if(!isBsig) Bmass_nosig->Fill(BInfo->mass[j]);

			///identify jpsi + ?
			if(gmu1idx == -1 || gmu2idx == -1)  continue ;
			if(abs(GenInfo->pdgId[gmu1idx]) != 13 && abs(GenInfo->pdgId[gmu2idx]) != 13) continue;
			if((GenInfo->mo1[gmu1idx]) == -1 || (GenInfo->mo1[gmu2idx]) == -1 || GenInfo->mo1[gmu1idx] != GenInfo->mo1[gmu2idx]) continue;
			if(abs(GenInfo->pdgId[GenInfo->mo1[gmu1idx]]) == 443 && abs(GenInfo->pdgId[GenInfo->mo1[gmu2idx]]) == 443)
			{
				//cout<<"found jpsi"<<endl;
				if(gtk1idx == -1 || gtk2idx == -1) continue; //check if we have 2 track
				//reco / truth matched...
				int mmu1idx  = GenInfo->mo1[gmu1idx];
				int mmu2idx  = GenInfo->mo1[gmu2idx];
				int mjpsiidx = GenInfo->mo1[mmu1idx];
				int mtk1idx  = GenInfo->mo1[gtk1idx];            /// track1 mother
				int mtk2idx  = GenInfo->mo1[gtk2idx];            /// track2 mother
				int mtk1pdg  = GenInfo->pdgId[mtk1idx];          /// get tr1 mother pdgid
				int mtk2pdg  = GenInfo->pdgId[mtk2idx];          /// tr2 moth pdgid
				int tk1pdg   = GenInfo->pdgId[gtk1idx];          /// track1 pdgid
				int tk2pdg   = GenInfo->pdgId[gtk2idx];          /// track2 pdg id
				//matching end /// check reco muon ancestor
				int bidx     = GenInfo->mo1[mmu1idx];            /// B meson id (Mother of Mother of Muon id)
				if(bidx==-1) continue;
				int JpsiPDG  = GenInfo->pdgId[mmu1idx];          /// Mother of Muon PDG
				int NDaughters = GenInfo->nDa[bidx];             /// Number of Daughters of B meson
				int MMtrk1   = GenInfo->mo1[mtk1idx];            /// Mother of Mother of track1
				int MMtrk2   = GenInfo->mo1[mtk2idx];            /// Mother of Mother of track2
				int Bpdg     = GenInfo->pdgId[bidx];             /// B meson Pdg (Grandmother of muon mother of Jpsi)
				int Bda1id   = GenInfo->da1[bidx];               /// 1. dau id
				int bda1pdg  = GenInfo->pdgId[Bda1id];           /// 1. dau pdg
				int Bda2id   = GenInfo->da2[bidx];               /// 2. dau id
				int bda2pdg  = GenInfo->pdgId[Bda2id];           /// 2. dau pdgid
				int Bda3id   = GenInfo->da3[bidx];               /// 3. dau id
				int bda3pdg  = GenInfo->pdgId[Bda3id];           /// 3.dau pdgid
				int bda4idx  = GenInfo->da4[bidx];               /// 4. dau id
				int bda4pdg  = GenInfo->pdgId[bda4idx];          /// 4. dau  pdgid



				//******************************************************************************************************************************///
				//                    ///  Our Signal
				//                                        ///  B+ to jpsi K- K+
				///******************************************************************************************************************************///

				if(mtk1idx != -1 && mtk2idx != -1 )
				{
					int MMtk1pdg = GenInfo->pdgId[MMtrk1];              /// get tr1 grmother pdgid
					int MMtk2pdg = GenInfo->pdgId[MMtrk2];              /// tr2 grmoth pdgid

					if( MMtrk1 == mjpsiidx           &&                 //Jpsi mom= trk1 grandmom
							abs(MMtk1pdg) == 531          &&                 // trk 1 in grandmom pdgId 531
							MMtrk2 == mjpsiidx            &&                 // jpsi mom= trk2 grandmom
							abs(MMtk2pdg) == 531          &&                 // 2. trk grandmom pdgId 531
							abs(tk1pdg) == 321            &&                 // trk1 is pion
							abs(tk2pdg) == 321            &&                 // 2. trk kaon  (OR)
							NDaughters ==2                &&                 //Number of daughter 2
							mtk1pdg==333                  &&                 // trk1 mom pdgId=333 (phi)
							mtk2pdg==333                  &&                 //trk2 mom pdgId=333(phi)
							mtk1idx==mtk2idx)
					{

						BmassBs->Fill(BInfo->mass[j]);                  //Bs signal

					}
					else{ /// not signal

						BmassBs_nosig->Fill(BInfo->mass[j]);           /// Bs no signal
					}
				}

				//// DONE Signal.

				//******************************************************************************************************************************///
				////1st Fake is X -> J/psi + pion- + kaon+ (here pion- mis-consider as kaon)
				///******************************************************************************************************************************///


				if(mtk1idx != -1 && mtk2idx != -1 ){                   /// check if we have tracks mothers
					if( mtk1idx == mjpsiidx        &&                   // jpsi mother = trk1 mother
							mtk2idx == mjpsiidx     &&                   // jpsi mother = trk2 mother
							(gtk1idx == Bda3id || gtk1idx == Bda2id) && (gtk2idx == Bda2id || gtk2idx == Bda3id) &&
							((abs(tk1pdg) == 211    &&                   // trk1 is pion?
							  abs(tk2pdg) == 321 )    ||                   // 2. trk kaon  (OR)
							 (abs(tk1pdg) == 321     &&                   // trk1 is kaon
							  abs(tk2pdg) == 211 ))                        // trk 2 pion
					  ){

						BmassBsPiK->Fill(BInfo->mass[j]);              /// 1st Fake Jpsi+pi+K
					}
					//else{

					//BmassBsXPiK->Fill(BInfo->mass[j]); ///
					// }

				}
				//DONE 1st FAKE
				//
				////******************************************************************************************************************************///
				// // /// 2nd fake is Bs -> J/psi + K+ K- (not make phi meson)
				// //******************************************************************************************************************************///
				if(mtk1idx != -1 && mtk2idx != -1 ){                   /// check if we have tracks mothers
					if( mtk1idx == mjpsiidx        &&                   // jpsi mother = trk1 mother
							abs(mtk1pdg) == 531        &&                   // trk1 mother pdgId 531
							mtk2idx == mjpsiidx        &&                   // jpsi mother = trk2 mother
							(gtk1idx == Bda3id || gtk1idx == Bda2id) && (gtk2idx == Bda2id || gtk2idx == Bda3id) &&
							abs(mtk2pdg) == 531        &&                   //trk2 mother pdgId  531
							abs(tk1pdg) == 321         &&                   // trk1 is kaon
							abs(tk1pdg) == 321                              // trk1 is kaon
					  ){

						BmassBsKK->Fill(BInfo->mass[j]); /// 2nd Fake Jpsi+K+K(not make phi)
					}

				}
				//DONE 2nd FAKE
				//// //******************************************************************************************************************************///
				// /// 3rd fake is B+ -> J/psi + K+ (and added K-)   :
				//// ///  Jpsi and K+ mother must be B+ ..  //mass peak must be 400 MeV forward from B+ mass B+ mass is around 5.27 +K (~400MeV) (enj/momentum/etc.) the mass peak must be around 5.6-6.0
				//// //******************************************************************************************************************************///

				if (mtk1idx != -1 && mtk2idx != -1) {
					if (abs(Bpdg) == 521) {
						if (NDaughters ==2)
							if (abs(bda2pdg) == 321 &&
									mtk1idx == mjpsiidx &&
									mtk1idx == bidx &&
									mtk2idx == bidx &&
									(gtk1idx == Bda2id || gtk2idx == Bda2id) &&
									Bda3id == -1 &&
									abs(tk2pdg) == 321 &&
									abs(tk1pdg) == 321)
							{
								BmassBsKKfake_binfo->Fill(BInfo->mass[j]);
							}
					}
				}
				/////DONE ---- 3rd fake
				//******************************************************************************************************************************///
				///// 4th fake is X -> J/psi + pion+ pion- (mis-consider as pion)
				///// note:  there is also Bs0 -> Jpsi pi pi  decay channel ..
				///// http://pdglive.lbl.gov/Particle.action?init=0&node=S086
				////******************************************************************************************************************************///

				if(mtk1idx != -1 && mtk2idx != -1 ){                         /// check if we have tracks mothers
					if (NDaughters==3)
						if( mtk1idx == mjpsiidx      &&                        // trk1 mom = jpsi mom
								mtk2idx == mjpsiidx      &&                        // trk2 mom = jpsi mom
								(gtk1idx == Bda3id || gtk1idx == Bda2id) && (gtk2idx == Bda2id || gtk2idx == Bda3id) &&
								abs(tk1pdg) == 211       &&                        // trk1is  pion
								abs(tk2pdg) == 211                                 /// trk 2 is pion
						  ){

							BmassBsXpipi->Fill(BInfo->mass[j]);
						}
				}
				/////DONE 4th FAKE
				//
				//******************************************************************************************************************************///
				/////   5th fake is Bs -> J/psi + kaon+ + kaon- + something
				/////  a-) first choose jpsi mother is Bs
				/////   b-) then Bs must have 4 or more children etc..
				/////   c-) Second and third children must be Kaon ..
				////******************************************************************************************************************************
				if(mtk1idx != -1 && mtk2idx != -1 ){                       /// check if we have tracks mothers
					if (NDaughters<4) continue ;
					//cout << "daughters: " << NDaughters << "   childs:/ mothers: " << mtk1pdg << " " << Bpdg <<
					//       " jpsi: "     << JpsiPDG    << " " << bda1pdg << " track1: " << tk1pdg << " " << bda2pdg <<
					//        " track2: "   << tk2pdg     << " " << bda3pdg << " track4: " << bda4pdg << "  " << endl;
					//if (abs(bda4pdg)!=111) continue;
					if( mtk1idx == mjpsiidx             &&                   ///trk1 mom = jpsi mom
							mtk2idx == mjpsiidx              &&                   /// trk2 mom = jpsi mom
							abs(mtk1pdg) == 531              &&                   // trk 1 mom pdgId 531
							abs(mtk2pdg) == 531              &&                   /// trk2 mom pdgId 531
							abs(tk1pdg) == 321               &&                   /// trk1 is K
							abs(tk2pdg) == 321               &&                     /// trk 2 is K
							(gtk1idx == Bda3id || gtk1idx == Bda2id) && (gtk2idx == Bda2id || gtk2idx == Bda3id) 
					  )
					{
						BmassBsKKX->Fill(BInfo->mass[j]);
					}
				}
				///DONE 5th FAKE/////////////////////////////////
			} /// jpsi end
		}

	}
	//cout<<"Bp + K type count========="<<endl;
	std::map<int,int>::iterator BtypeCountBpKIt;
	for(BtypeCountBpKIt = BtypeCountBpK.begin(); BtypeCountBpKIt != BtypeCountBpK.end(); BtypeCountBpKIt++){
		//cout<<"Ktype: "<<BtypeCountBpKIt->first<<" Count: "<<BtypeCountBpKIt->second<<endl;
	}

	// cout<<"B0 + K type count========="<<endl;
	std::map<int,int>::iterator BtypeCountB0KIt;
	for(BtypeCountB0KIt = BtypeCountB0K.begin(); BtypeCountB0KIt != BtypeCountB0K.end(); BtypeCountB0KIt++){
		//cout<<"Ktype: "<<BtypeCountB0KIt->first<<" Count: "<<BtypeCountB0KIt->second<<endl;
	}
	outf->Write();
	cout<<"--- Writing finished"<<endl;
	outf->Close();

	cout<<"--- In/Output files"<<endl;
	cout<<ifname<<endl;
	cout<<outfile<<endl;
	cout<<endl;

	return 1;
}

void printDa(GenInfoBranches *GenInfo, int idx, int space){
	if(idx != -1){
		int indent = space;
		while(indent != 0){
			printf("   ");
			indent -= 1;
		}
		printf("%d %f\n",GenInfo->pdgId[idx], GenInfo->pt[idx]);
		if(GenInfo->da1[idx]!=-1){
			printDa(GenInfo, GenInfo->da1[idx], space+1);
		}
		if(GenInfo->da2[idx]!=-1){
			printDa(GenInfo, GenInfo->da2[idx], space+1);
		}
		if(GenInfo->da3[idx]!=-1){
			printDa(GenInfo, GenInfo->da3[idx], space+1);
		}
		if(GenInfo->da4[idx]!=-1){
			printDa(GenInfo, GenInfo->da4[idx], space+1);
		}
	}
}
int getBAncestor(GenInfoBranches *GenInfo, int idx, int BancestorId){
	if(GenInfo->mo1[idx] == -1) return -1;
	else if(abs(GenInfo->pdgId[GenInfo->mo1[idx]]) == BancestorId) return GenInfo->mo1[idx];
	else return getBAncestor(GenInfo, GenInfo->mo1[idx], BancestorId);
}

int matcher(BInfoBranches *BInfo, TrackInfoBranches *TrackInfo, MuonInfoBranches *MuonInfo, GenInfoBranches *GenInfo, int j, float BId, float MId, float tk1Id, float tk2Id, bool twoTks){
	int mGenIdxTk1=-1;
	int mGenIdxTk2=-1;
	int bGenIdxTk1=-1;
	int bGenIdxTk2=-1;
	int bGenIdxMu1=-1;
	int bGenIdxMu2=-1;
	int Bgen = -1;
	// tk1
	if(TrackInfo->geninfo_index[BInfo->rftk1_index[j]]>-1)
	{
		int level =0;
		if(abs(GenInfo->pdgId[TrackInfo->geninfo_index[BInfo->rftk1_index[j]]])==tk1Id)
		{
			level = 1;
			if(GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk1_index[j]]]>-1)
			{
				if(!twoTks)//one trk channel
				{
					mGenIdxTk1=0;
					if(abs(GenInfo->pdgId[GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk1_index[j]]]])==BId)
					{
						level = 3;
						bGenIdxTk1=GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk1_index[j]]];
					}
				}
				else//two trk channel
				{
					if(abs(GenInfo->pdgId[GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk1_index[j]]]])==MId)
					{
						level = 2;
						if(GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk1_index[j]]]]>-1)
						{
							if(abs(GenInfo->pdgId[GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk1_index[j]]]]])==BId)
							{
								level = 3;
								bGenIdxTk1=GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk1_index[j]]]];
							}
						}
						mGenIdxTk1=GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk1_index[j]]];
					}
				}
			}
		}
		Bgen=level;
	}

	//tk2
	if(!twoTks)//one trk channel
	{
		Bgen+=30;
		mGenIdxTk2=0;
		bGenIdxTk2=0;
	}
	else//two trk channel
	{
		if(TrackInfo->geninfo_index[BInfo->rftk2_index[j]]>-1)
		{
			int level =0;
			if(abs(GenInfo->pdgId[TrackInfo->geninfo_index[BInfo->rftk2_index[j]]])==tk2Id)
			{
				level = 1;
				if(GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk2_index[j]]]>-1)
				{
					if(abs(GenInfo->pdgId[GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk2_index[j]]]])==MId)
					{
						level = 2;
						if(GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk2_index[j]]]]>-1)
						{
							if(abs(GenInfo->pdgId[GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk2_index[j]]]]])==BId)
							{
								level = 3;
								bGenIdxTk2 = GenInfo->mo1[GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk2_index[j]]]];
							}
						}
						mGenIdxTk2 = GenInfo->mo1[TrackInfo->geninfo_index[BInfo->rftk2_index[j]]];
					}
				}
			}
			Bgen+=(level*10);
		}
	}

	//mu1
	//cout<<MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]<<endl;
	if(MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]>-1)
	{
		int level =0;
		if(abs(GenInfo->pdgId[MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]])==13)
		{
			level=1;
			if(GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]]>-1)
			{
				if(GenInfo->pdgId[GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]]]==443)
				{
					//ujGenIdxMu1 = GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]];
					level=2;
					if(GenInfo->mo1[GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]]]>-1)
					{
						if(abs(GenInfo->pdgId[GenInfo->mo1[GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]]]])==BId)
						{
							//nonprompt=1;
							level = 3;
							bGenIdxMu1=GenInfo->mo1[GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu1_index[BInfo->rfuj_index[j]]]]];
						}
					}
					else
					{
						//prompt=1;
					}
				}
			}
		}
		Bgen+=(level*100);
	}


	//mu2
	if(MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]>-1)
	{
		int level =0;
		if(abs(GenInfo->pdgId[MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]])==13)
		{
			level = 1;
			if(GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]]>-1)
			{
				if(GenInfo->pdgId[GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]]]==443)
				{
					//ujGenIdxMu2 = GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]];
					level = 2;
					if(GenInfo->mo1[GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]]]>-1)
					{
						if(abs(GenInfo->pdgId[GenInfo->mo1[GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]]]])==BId)
						{
							level = 3;
							bGenIdxMu2=GenInfo->mo1[GenInfo->mo1[MuonInfo->geninfo_index[BInfo->uj_rfmu2_index[BInfo->rfuj_index[j]]]]];
						}
					}
				}
			}
		}
		Bgen+=(level*1000);
	}
	int level=0;
	if(mGenIdxTk1!=-1 && mGenIdxTk2!=-1)
	{
		if(!twoTks) level=1;
		else
		{
			if(mGenIdxTk1==mGenIdxTk2) level=1;
		}
	}
	if(bGenIdxMu1!=-1 && bGenIdxMu1==bGenIdxMu2 && bGenIdxMu1==bGenIdxTk1)
	{
		if(!twoTks)
		{
			level=2;
		}
		else if(bGenIdxMu1==bGenIdxTk2)
		{
			level=2;
		}
	}
	Bgen+=(level*10000);
	return Bgen;
}
