#include "Significance.h"

Significance::Significance()
{
    //ctor
    signalcut   = "B_mass >5200 &&  B_mass< 5360" ;
    Lxycut      = "B_Lxy_MinA0 > 0.2";
    sidebandcut = "B_mass <5160 || B_mass >5400";
    initial_value =0;
    factor=1.0;

    /// get and set
    ///first get your tree ..
    MCTree  = (TTree*)f1->Get("BplusBestChiSlimSkim");
    DataTree = (TTree*)f2->Get("BplusBestChiSlimSkim");
}

Significance::~Significance()
{
    //dtor
}
