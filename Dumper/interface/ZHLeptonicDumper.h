#ifndef __ZHLEPTONICDUMPER__
#define __ZHLEPTONICDUMPER__

#include "HggAnalyzer/Dumper/interface/DiphotonBase.h"

class ZHLeptonicDumper : protected DiphotonBase 
{

    public:

        ZHLeptonicDumper(std::string filename, std::string treename);
        void Dumper(std::string outdir, std::string vhtype = "", bool is_data_driven = false);
        void SetGlobalScale(double scale = 1.);


    private:

        void Initialization();

        float _n_ele         ; 
        float _ele1_Pt       ; 
        float _ele1_Eta      ; 
        float _ele1_Phi      ; 
        float _ele1_E        ;
        float _ele2_Pt       ; 
        float _ele2_Eta      ; 
        float _ele2_Phi      ; 
        float _ele2_E        ; 
        float _n_mu          ; 
        float _mu1_Pt        ; 
        float _mu1_Eta       ; 
        float _mu1_Phi       ; 
        float _mu1_E         ;
        float _mu2_Pt        ; 
        float _mu2_Eta       ; 
        float _mu2_Phi       ; 
        float _mu2_E         ; 
        float _n_jets        ; 
        float _jet1_Pt       ; 
        float _jet1_deepbtag ; 
        float _jet2_deepbtag ; 
        float _VhasNeu       ; 
        float _VhasLep       ; 
        float _VhasHad       ;
        float _max_jet_dCSV  ;

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
        float f_lep1_pt          ; 
        float f_lep2_pt          ; 
        float f_lep1_eta         ; 
        float f_lep2_eta         ; 
        float f_dr_pho1_lep1     ; 
        float f_dr_pho1_lep2     ; 
        float f_dr_pho2_lep1     ; 
        float f_dr_pho2_lep2     ;
        float f_dilep_mass       ;
        float f_dilep_pt         ;
        float f_theta            ;
        float f_njet             ;
        float f_jet1_pt          ; 
        float f_jet1_csv         ; 
        float f_jet2_csv         ; 
        float f_leptonType       ;
        float f_max_jet_dCSV     ; 
        float f_dphi_dipho_dilep ; 
        float f_pt_balance       ; 
        float f_dilep_dphi       ; 
        float f_dilep_cosphi     ; 
        float f_cosThetaStar     ; 

        double _scale;


};

#endif
