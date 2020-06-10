#ifndef __WHLEPTONICDUMPER__
#define __WHLEPTONICDUMPER__

#include "HggAnalyzer/Dumper/interface/DiphotonBase.h"

class WHLeptonicDumper : protected DiphotonBase 
{

    public:

        WHLeptonicDumper(std::string filename, std::string treename);
        void Dumper(std::string outdir, std::string vhtype = "", bool is_data_driven = false);
        void SetGlobalScale(double scale = 1.);


    private:

        void Initialization();

        float _n_ele         ; 
        float _ele1_Pt       ; 
        float _ele1_Eta      ; 
        float _ele1_Phi      ; 
        float _ele1_E        ; 
        float _n_mu          ; 
        float _mu1_Pt        ; 
        float _mu1_Eta       ; 
        float _mu1_Phi       ; 
        float _mu1_E         ; 
        float _n_jets        ; 
        float _jet1_Pt       ; 
        float _jet1_deepbtag ; 
        float _jet2_deepbtag ; 
        float _met_Pt        ; 
        float _met_Phi       ; 
        float _VhasNeu       ; 
        float _VhasLep       ; 
        float _VhasHad       ;

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
        float f_pho1_psv         ; 
        float f_pho2_psv         ; 
        float f_dipho_pt         ; 
        float f_dipho_deltaphi   ; 
        float f_dipho_cosphi     ; 
        float f_njet             ; 
        float f_nele             ; 
        float f_nmu              ; 
        float f_mtlnu            ; 
        float f_dr_pho1_lep      ; 
        float f_dr_pho2_lep      ; 
        float f_theta            ; 
        float f_met              ; 
        float f_lnupt            ; 
        float f_dphi_lep_met     ; 
        float f_dphi_dipho_lepmet; 
        float f_lep_pt           ; 
        float f_lep_eta          ; 
        float f_jet1_csv         ; 
        float f_jet2_csv         ; 
        float f_jet1_pt          ; 
        float f_leptonType       ; 


        double _scale;


};

#endif
