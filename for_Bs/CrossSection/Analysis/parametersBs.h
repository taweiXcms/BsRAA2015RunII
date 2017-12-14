/// Parameters are defined here..
const int Nfirststep=30;
const int Nsecondstep=14;
const int NLxy = 26 ;
const int NChi2 = 60 ;
const int NPt = 16 ;


const int SignalRange_min   = 5200 ;
const int SignalRange_max   = 5360 ;
const int SidebandRange_min = 5160 ;
const int SidebandRange_max = 5400 ;
const int HistRange_min     = 5000 ;
const int HistRange_max     = 5800 ;
double cut1_significance[Nfirststep],cut1[Nfirststep],cut2_significance[Nsecondstep],cut2[Nsecondstep];  ///cos cut
double cut1_eff[Nfirststep], cut2_eff[Nsecondstep];
double cut1_purity[Nfirststep], cut2_purity[Nsecondstep];
double cut1_lxy[NLxy],cut1_lxy_significance[NLxy],cut1_lxy_eff[NLxy],cut1_lxy_purity[NLxy];            ///Lxy
double cut1_chi2[NChi2],cut1_chi2_significance[NChi2],cut1_chi2_eff[NChi2],cut1_chi2_purity[NChi2];        ///Chi2
double cut1_pt[NPt],cut1_pt_significance[NPt],cut1_pt_eff[NPt],cut1_pt_purity[NPt];                /// Pt
double cut1_combination[NLxy],cut1_comb_significance[NLxy],cut1_comb_eff[NLxy],cut1_comb_purity[NLxy]; /// combination

TCut signalcut   = "B_mass >5200 &&  B_mass< 5360" ;
TCut Lxycut      = "B_Lxy_MinA0 > 0.2";
TCut sidebandcut = "B_mass <5160 || B_mass >5400";
