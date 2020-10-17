#ifndef __WHLEPTONICDUMPER__
#define __WHLEPTONICDUMPER__

#include "HggAnalyzer/Dumper/interface/DiphotonBase.h"
#include "TLorentzVector.h"
#include <vector>

class WHLeptonicDumper : protected DiphotonBase 
{

    public:

        WHLeptonicDumper(std::string filename, std::string type, std::string pufilename);
        void Dumper(std::string outdir, std::string vhtype = "", bool is_data_driven = false);
        void SetGlobalScale(double scale = 1.);


    private:

        void Initialization();
        std::vector<std::pair<TLorentzVector, float>> SetJetsInfo();

        float _n_ele         ; 
        float _ele1_Pt       ; 
        float _ele1_Eta      ; 
        float _ele1_Phi      ; 
        float _ele1_E        ;
        float _ele1_losseId  ;
        float _n_mu          ; 
        float _mu1_Pt        ; 
        float _mu1_Eta       ; 
        float _mu1_Phi       ; 
        float _mu1_E         ; 
        float _n_jets        ; 
        float _jet1_Pt       ; 
        float _jet1_Eta      ; 
        float _jet1_Phi      ; 
        float _jet1_E        ; 
        float _jet1_deepbtag ; 
        float _jet2_Pt       ; 
        float _jet2_Eta      ; 
        float _jet2_Phi      ; 
        float _jet2_E        ; 
        float _jet2_deepbtag ; 
        float _jet3_Pt       ; 
        float _jet3_Eta      ; 
        float _jet3_Phi      ; 
        float _jet3_E        ; 
        float _jet3_deepbtag ; 
        float _jet4_Pt       ; 
        float _jet4_Eta      ; 
        float _jet4_Phi      ; 
        float _jet4_E        ; 
        float _jet4_deepbtag ; 
        float _jet5_Pt       ; 
        float _jet5_Eta      ; 
        float _jet5_Phi      ; 
        float _jet5_E        ; 
        float _jet5_deepbtag ; 
        float _jet6_Pt       ; 
        float _jet6_Eta      ; 
        float _jet6_Phi      ; 
        float _jet6_E        ; 
        float _jet6_deepbtag ; 
        float _jet7_Pt       ; 
        float _jet7_Eta      ; 
        float _jet7_Phi      ; 
        float _jet7_E        ; 
        float _jet7_deepbtag ; 
        float _jet8_Pt       ; 
        float _jet8_Eta      ; 
        float _jet8_Phi      ; 
        float _jet8_E        ; 
        float _jet8_deepbtag ; 
        float _jet9_Pt       ; 
        float _jet9_Eta      ; 
        float _jet9_Phi      ; 
        float _jet9_E        ; 
        float _jet9_deepbtag ; 
        float _jet10_Pt      ; 
        float _jet10_Eta     ; 
        float _jet10_Phi     ; 
        float _jet10_E       ; 
        float _jet10_deepbtag; 
        float _jet11_Pt      ; 
        float _jet11_Eta     ; 
        float _jet11_Phi     ; 
        float _jet11_E       ; 
        float _jet11_deepbtag; 
        float _jet12_Pt      ; 
        float _jet12_Eta     ; 
        float _jet12_Phi     ; 
        float _jet12_E       ; 
        float _jet12_deepbtag; 
        float _jet13_Pt      ; 
        float _jet13_Eta     ; 
        float _jet13_Phi     ; 
        float _jet13_E       ; 
        float _jet13_deepbtag; 
        float _jet14_Pt      ; 
        float _jet14_Eta     ; 
        float _jet14_Phi     ; 
        float _jet14_E       ; 
        float _jet14_deepbtag; 
        float _jet15_Pt      ; 
        float _jet15_Eta     ; 
        float _jet15_Phi     ; 
        float _jet15_E       ; 
        float _jet15_deepbtag;
        float _met_Pt        ; 
        float _met_Phi       ;
        float _met_sumEt     ; 
        float _VhasNeu       ; 
        float _VhasLep       ; 
        float _VhasHad       ;
        float _ele_iso       ;
        float _mu1_iso       ;

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
        float f_dphi_dipho       ; 
        float f_cosdphi_dipho    ; 
        float f_lep_pt           ; 
        float f_lep_eta          ;
        float f_dr_pho1_lep      ; 
        float f_dr_pho2_lep      ; 
        float f_met              ; 
        float f_met_sumEt        ; 
        float f_lnu_mt           ; 
        float f_dphi_dipho_lnu   ; 
        float f_pt_balance       ;
        float f_njet             ; 
        float f_max_jet_pt       ; 
        float f_max_jet_dCSV     ; 
        float f_min_dphi_jet_lnu ; 
        float f_leptonType       ;
        float f_whlep_class      ; 

        double _scale            ;


};

#endif
