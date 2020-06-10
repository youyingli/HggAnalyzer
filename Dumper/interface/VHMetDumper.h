#ifndef __VHMETDUMPER__
#define __VHMETDUMPER__

#include "HggAnalyzer/Dumper/interface/DiphotonBase.h"

class VHMetDumper : protected DiphotonBase 
{

    public:

        VHMetDumper(std::string filename, std::string treename);
        void Dumper(std::string outdir, std::string vhtype = "", bool is_data_driven = false);
        void SetGlobalScale(double scale = 1.);


    private:

        void Initialization();

        float _n_ele             ; 
        float _n_mu              ; 
        float _n_jets            ; 
        float _jet1_Pt           ; 
        float _maxJetDeepCSV     ; 
        float _met_Pt            ; 
        float _met_Phi           ; 
        float _met_sumEt         ; 
        float _met_Sig           ; 
        float _met_RealSig       ; 
        float _minDeltaPhiJetMet ; 
        float _VhasNeu           ; 
        float _VhasLep           ; 
        float _VhasHad           ;


        float f_mass             ; 
        float f_mva              ; 
        float f_weight           ; 
        float f_pho1_eta         ; 
        float f_pho2_eta         ; 
        float f_pho1_ptoM        ; 
        float f_pho2_ptoM        ; 
        float f_pho1_idmva       ; 
        float f_pho2_idmva       ; 
        float f_min_phoId        ; 
        float f_max_phoId        ; 
        float f_dipho_pt         ; 
        float f_dipho_deltaphi   ; 
        float f_dipho_cosphi     ; 
        float f_njet             ; 
        float f_jet1_pt          ; 
        float f_max_jet_dCSV     ; 
        float f_met              ; 
        float f_met_sumEt        ; 
        float f_met_Sig          ; 
        float f_met_significance ; 
        float f_min_dPhi_jet_met ; 
        float f_dPhi_dipho_met   ; 
        float f_pt_balance       ; 

        double _scale;


};

#endif
