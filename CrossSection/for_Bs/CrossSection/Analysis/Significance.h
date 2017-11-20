#ifndef SIGNIFICANCE_H
#define SIGNIFICANCE_H
#include <vector>

///Root zamazingos
#include "TCut.h"
#include "TTree.h"
#include "TFile.h"
using namespace std;


class Significance
{
        private:

    public:
                /** Default constructor */
        Significance();
        /** Default destructor */
        virtual ~Significance();
        /** Public vectors */
        vector<float> VSignificance;
        vector<float> VPurity;
        vector<float> VEfficiency;
        vector<float> VCut;
        TCut signalcut   = "B_mass >5200 &&  B_mass< 5360" ;
        TCut Lxycut = "B_Lxy_MinA0 > 0.2";
        TCut sidebandcut= "B_mass <5160 || B_mass >5400";
        double initial_value=10.0;
        double factor=1.0;
        int cutrange=5;
       //  TFile*  f1;// = new TFile("/media/zack/vbox/Clean_Projects/new_data/outf_mc_kplus_clean.root");// MC
       //  TFile*  f2;// = new TFile("/media/zack/vbox/Clean_Projects/new_data/outf_data_periodAllYear_clean.root");      ///DATA
       // TTree *MCTree; //= (TTree*)f1->Get("BplusBestChiSlimSkim");
      //  TTree *DataTree;//= (TTree*)f2->Get("BplusBestChiSlimSkim");
      void ClearVectors();
    protected:

};

Significance::Significance()
{
    //ctor

}

Significance::~Significance()
{
    //dtor
}
void Significance::ClearVectors(){
VSignificance.clear();
VPurity.clear();
VEfficiency.clear();
VCut.clear();
cout<<"vectors are cleared :"<<endl;


}
#endif // SIGNIFICANCE_H
