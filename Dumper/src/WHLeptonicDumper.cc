
#include "HggAnalyzer/Dumper/interface/WHLeptonicDumper.h"
#include "HggAnalyzer/Dumper/interface/THistService.h"

#include <cstdlib>
#include <iostream>

using namespace std;

WHLeptonicDumper::WHLeptonicDumper(string filename, string type): DiphotonBase(filename, "WHLeptonicTag", type) 
{
    Initialization();
}

void
WHLeptonicDumper::Initialization()
{
    _tree -> SetBranchAddress("n_ele",                     &_n_ele                      );
    _tree -> SetBranchAddress("ele1_Pt",                   &_ele1_Pt                    );
    _tree -> SetBranchAddress("ele1_Eta",                  &_ele1_Eta                   );
    _tree -> SetBranchAddress("ele1_Phi",                  &_ele1_Phi                   );
    _tree -> SetBranchAddress("ele1_E",                    &_ele1_E                     );
    _tree -> SetBranchAddress("n_mu",                      &_n_mu                       );
    _tree -> SetBranchAddress("mu1_Pt",                    &_mu1_Pt                     );
    _tree -> SetBranchAddress("mu1_Eta",                   &_mu1_Eta                    );
    _tree -> SetBranchAddress("mu1_Phi",                   &_mu1_Phi                    );
    _tree -> SetBranchAddress("mu1_E",                     &_mu1_E                      );
    _tree -> SetBranchAddress("n_jets",                    &_n_jets                     );
    _tree -> SetBranchAddress("jet1_Pt",                   &_jet1_Pt                    );
    _tree -> SetBranchAddress("jet1_deepbtag",             &_jet1_deepbtag              );
    _tree -> SetBranchAddress("jet2_deepbtag",             &_jet2_deepbtag              );
    _tree -> SetBranchAddress("met_Pt",                    &_met_Pt                     );
    _tree -> SetBranchAddress("met_Phi",                   &_met_Phi                    );
    if (isSignal()) {
        _tree -> SetBranchAddress("VhasNeu",                   &_VhasNeu                    );
        _tree -> SetBranchAddress("VhasLep",                   &_VhasLep                    );
        _tree -> SetBranchAddress("VhasHad",                   &_VhasHad                    );
    }
//    _intree -> SetBranchAddress("", );

}

void
WHLeptonicDumper::SetGlobalScale(double scale)
{
    _scale = scale;
}

void
WHLeptonicDumper::Dumper(string outdir, string vhtype, bool is_data_driven)
{

    system(Form("mkdir -p %s", outdir.c_str()));

    string tag = "";
    if (vhtype != "") tag = "_" + vhtype;
    if (is_data_driven) tag = "_DD";

    TFile* outfile = TFile::Open( Form("%s/skim%s_%s", outdir.c_str(), tag.c_str(), _filename.c_str()), "recreate");
    TTree* outTree = new TTree("variables_skim", "");

    outTree->Branch("mass"                 , &f_mass                  ,  "mass/F"                 );
    outTree->Branch("mva"                  , &f_mva                   ,  "mva/F"                  );
    outTree->Branch("weight"               , &f_weight                ,  "weight/F"               );
    outTree->Branch("pho1_eta"             , &f_pho1_eta              ,  "pho1_eta/F"             );
    outTree->Branch("pho2_eta"             , &f_pho2_eta              ,  "pho2_eta/F"             );
    outTree->Branch("pho1_ptoM"            , &f_pho1_ptoM             ,  "pho1_ptoM/F"            );
    outTree->Branch("pho2_ptoM"            , &f_pho2_ptoM             ,  "pho2_ptoM/F"            );
    outTree->Branch("pho1_idmva"           , &f_pho1_idmva            ,  "pho1_idmva/F"           );
    outTree->Branch("pho2_idmva"           , &f_pho2_idmva            ,  "pho2_idmva/F"           );
    outTree->Branch("min_phoId"            , &f_min_phoId             ,  "min_phoId/F"            );
    outTree->Branch("max_phoId"            , &f_max_phoId             ,  "max_phoId/F"            );
    outTree->Branch("pho1_psv"             , &f_pho1_psv              ,  "pho1_psv/F"             );
    outTree->Branch("pho2_psv"             , &f_pho2_psv              ,  "pho2_psv/F"             );
    outTree->Branch("dipho_pt"             , &f_dipho_pt              ,  "dipho_pt/F"             );
    outTree->Branch("dipho_deltaphi"       , &f_dipho_deltaphi        ,  "dipho_deltaphi/F"       );
    outTree->Branch("dipho_cosphi"         , &f_dipho_cosphi          ,  "dipho_cosphi/F"         );
    outTree->Branch("njet"                 , &f_njet                  ,  "njet/F"                 );
    outTree->Branch("mtlnu"                , &f_mtlnu                 ,  "mtlnu/F"                );
    outTree->Branch("dr_pho1_lep"          , &f_dr_pho1_lep           ,  "dr_pho1_lep/F"          );
    outTree->Branch("dr_pho2_lep"          , &f_dr_pho2_lep           ,  "dr_pho2_lep/F"          );
    outTree->Branch("met"                  , &f_met                   ,  "met/F"                  );
    outTree->Branch("lep_pt"               , &f_lep_pt                ,  "lep_pt/F"               );
    outTree->Branch("lep_eta"              , &f_lep_eta               ,  "lep_eta/F"              );
    outTree->Branch("jet1_pt"              , &f_jet1_pt               ,  "jet1_pt/F"              );
    outTree->Branch("leptonType"           , &f_leptonType            ,  "leptonType/F"           );

    //Old
    outTree->Branch("theta"                , &f_theta                 ,  "theta/F"                );
    outTree->Branch("jet1_csv"             , &f_jet1_csv              ,  "jet1_csv/F"             );
    outTree->Branch("jet2_csv"             , &f_jet2_csv              ,  "jet2_csv/F"             );

    //Could
    outTree->Branch("lnupt"                , &f_lnupt                 ,  "lnupt/F"                );
    outTree->Branch("dphi_dipho_lepmet"    , &f_dphi_dipho_lepmet     ,  "dphi_dipho_lepmet/F"    );
    outTree->Branch("dphi_lep_met"         , &f_dphi_lep_met          ,  "dphi_lep_met/F"         );
//    outTree->Branch("met_sumEt"            , &f_met_sumEt            ,  "met_sumEt/F"           );
//    outTree->Branch("met_Sig"              , &f_met_Sig              ,  "met_Sig/F"           );
//    outTree->Branch("met_significance"     , &f_met_significance     ,  "met_significance/F"           );
//    outTree->Branch("max_jet_dCSV"         , &f_max_jet_dCSV         ,  "max_jet_dCSV/F"           );
//    outTree->Branch("pt_balance"           , &f_pt_balance           ,  "pt_balance/F"           );

    Dumper::THistService th;

    th.AddNewTH1("h1_Mgg"                     ,40  ,100. ,180.   );
    th.AddNewTH1("h1_lead_phoPt"              ,30  ,20.  ,260.   );
    th.AddNewTH1("h1_leadPho_PToM"            ,25  ,0.   ,2.5    );
    th.AddNewTH1("h1_lead_phoEta"             ,30  ,-3.  ,3.     );
    th.AddNewTH1("h1_lead_phoId_mva"          ,40  ,-1.  ,1.     );
    th.AddNewTH1("h1_pho1_psv"                , 2  ,0    ,2.     );
    th.AddNewTH1("h1_subl_phoPt"              ,30  ,20.  ,140.   );
    th.AddNewTH1("h1_sublPho_PToM"            ,25  ,0.   ,1.     );
    th.AddNewTH1("h1_subl_phoEta"             ,30  ,-3.  ,3.     );
    th.AddNewTH1("h1_subl_phoId_mva"          ,40  ,-1.  ,1.     );
    th.AddNewTH1("h1_pho2_psv"                , 2  ,0    ,2.     );
    th.AddNewTH1("h1_min_phoId"               ,40  ,-1   ,1.     );
    th.AddNewTH1("h1_max_phoId"               ,40  ,-1   ,1.     );
    th.AddNewTH1("h1_dipho_dphi"              ,20  ,0.   ,3.2    );
    th.AddNewTH1("h1_dipho_pt"                ,30  ,0.   ,375.   );
    th.AddNewTH1("h1_dipho_cosphi"            ,40  ,-1.  ,1.     );
    th.AddNewTH1("h1_njet"                    ,10  ,0.   ,10.    );
    th.AddNewTH1("h1_nele"                    ,3   ,0.   ,3.     );
    th.AddNewTH1("h1_nmu"                     ,3   ,0.   ,3.     );
    th.AddNewTH1("h1_lep_pt"                  ,25  ,0.   ,100.   );
    th.AddNewTH1("h1_lep_eta"                 ,30  ,-3.  ,3.     );
    th.AddNewTH1("h1_mt"                      ,30  ,0    ,180    );
    th.AddNewTH1("h1_dr_pho1_lep"             ,25  ,0.2  ,4      );
    th.AddNewTH1("h1_dr_pho2_lep"             ,25  ,0.2  ,4      );
    th.AddNewTH1("h1_theta"                   ,32  ,0    ,3.2    );
    th.AddNewTH1("h1_met"                     ,30  ,0.   ,150.   );
    th.AddNewTH1("h1_lead_jetPt"              ,30  ,0.   ,300.   );
    th.AddNewTH1("h1_lead_jetb"               ,40  ,0.   ,1.     );
    th.AddNewTH1("h1_subl_jetb"               ,40  ,0.   ,1.     );
    th.AddNewTH1("h1_nvtx"                    ,60  ,0.   ,60.    );
    th.AddNewTH1("h1_rho"                     ,60  ,0.   ,60.    );
    th.AddNewTH1("h1_diphoPtoWPt"             ,60  ,0.4  ,1.8    );
    th.AddNewTH1("h1_lnuPtoWPt"               ,60  ,0.4  ,1.8    );
    th.AddNewTH1("h1_lnupt"                   ,50  ,0.   ,200    );
    th.AddNewTH1("h1_dPhiLepMet"              ,32  ,0.   ,3.2    );
    th.AddNewTH1("h1_dPhi_Dipho_LepMet"       ,32  ,0.   ,3.2    );
    th.AddNewTH1("h1_pt_balance"              ,36  ,-11. ,1.0    );
    th.AddNewTH1("h1_Megamma"                 ,60  ,30.  ,150    );
    //th.AddNewTH1("h1_met_sumEt"               ,50  ,0.   ,5000.  );
    //th.AddNewTH1("h1_met_significance"        ,40  ,0.   ,15.    );
    //th.AddNewTH1("h1_max_jet_dCSV"            ,40  ,0.   ,1.     );


    for (int i = 0; i < _tree->GetEntries(); i ++) {
        _tree->GetEntry(i);

        TLorentzVector pho1P4 = Photon1P4();
        TLorentzVector pho2P4 = Photon2P4();
        TLorentzVector diphoP4 = pho1P4 + pho2P4;

        double ele_pt = -999.;
        double mu_pt  = -999.;


        if (_n_ele > 0.) ele_pt = _ele1_Pt;
        if (_n_mu  > 0.) mu_pt  = _mu1_Pt;


        if (ele_pt > mu_pt) {

            TLorentzVector eleP4;
            eleP4.SetPtEtaPhiE(_ele1_Pt, _ele1_Eta, _ele1_Phi, _ele1_E);

            f_mtlnu = sqrt(2. * eleP4.Et() * _met_Pt * (1 - cos(eleP4.Phi() - _met_Phi)));
            f_dr_pho1_lep = eleP4.DeltaR(pho1P4);
            f_dr_pho2_lep = eleP4.DeltaR(pho2P4);
            f_theta       = diphoP4.Angle(eleP4.Vect());
            f_lep_pt      = eleP4.Pt();
            f_lep_eta     = eleP4.Eta();
            f_leptonType  = 11.;

            TVector2 eleP2;
            TVector2 metP2;

            eleP2.SetMagPhi(_ele1_Pt, _ele1_Phi);
            metP2.SetMagPhi(_met_Pt, _met_Phi);

            auto V_P2 = eleP2 + metP2;
            auto H_P2 = diphoP4.Vect().XYvector();

            f_lnupt = V_P2.Mod();
            f_dphi_lep_met = eleP2.DeltaPhi(metP2);
            f_dphi_dipho_lepmet = H_P2.DeltaPhi(V_P2);


        } else {

            TLorentzVector muP4;
            muP4.SetPtEtaPhiE(_mu1_Pt, _mu1_Eta, _mu1_Phi, _mu1_E);
                                                                                           
            f_mtlnu = sqrt(2. * muP4.Et() * _met_Pt * (1 - cos(muP4.Phi() - _met_Phi)));
            f_dr_pho1_lep = muP4.DeltaR(pho1P4);
            f_dr_pho2_lep = muP4.DeltaR(pho2P4);
            f_theta       = diphoP4.Angle(muP4.Vect());
            f_lep_pt      = muP4.Pt();
            f_lep_eta     = muP4.Eta();
            f_leptonType  = 13.;
                                                                                           
            TVector2 muP2;
            TVector2 metP2;
                                                                                           
            muP2.SetMagPhi(_mu1_Pt, _mu1_Phi);
            metP2.SetMagPhi(_met_Pt, _met_Phi);
                                                                                           
            auto V_P2 = muP2 + metP2;
            auto H_P2 = diphoP4.Vect().XYvector();
                                                                                           
            f_lnupt = V_P2.Mod();
            f_dphi_lep_met = muP2.DeltaPhi(metP2);
            f_dphi_dipho_lepmet = H_P2.DeltaPhi(V_P2);


        }

        if(f_lep_pt < 15.) continue;
        if(_dipho_leadIDMVA < -0.4) continue;
        if(_dipho_subleadIDMVA < -0.4) continue;

        if (vhtype != "") {
            if (vhtype == "zh_dilep" or vhtype == "wh_lep") {
                if (_VhasLep != 1) continue;
            } else if (vhtype == "zh_met") {
                if (_VhasNeu != 1) continue;
            } else if (vhtype == "zh_had" || vhtype == "wh_had") {
                if (_VhasHad != 1) continue;
            }
        }



        f_mass            = _dipho_mass                                   ; 
        f_weight          = Weight() * _scale                             ; 
        f_pho1_eta        = pho1P4.Eta()                                  ; 
        f_pho2_eta        = pho2P4.Eta()                                  ; 
        f_pho1_ptoM       = _dipho_lead_ptoM                              ; 
        f_pho2_ptoM       = _dipho_sublead_ptoM                           ; 
        f_pho1_idmva      = _dipho_leadIDMVA                              ; 
        f_pho2_idmva      = _dipho_subleadIDMVA                           ; 
        f_min_phoId       = min(f_pho1_idmva, f_pho2_idmva)               ; 
        f_max_phoId       = max(f_pho1_idmva, f_pho2_idmva)               ; 
        f_pho1_psv        = isPhoton1Prompt()                             ; 
        f_pho2_psv        = isPhoton2Prompt()                             ; 
        f_dipho_pt        = diphoP4.Pt()                                  ; 
        f_dipho_deltaphi  = pho1P4.DeltaPhi(pho2P4)                       ; 
        f_dipho_cosphi    = cos(f_dipho_deltaphi)                         ; 
        f_njet            = _n_jets                                       ; 
        f_nele            = _n_ele                                        ; 
        f_nmu             = _n_mu                                         ; 
        f_met             = _met_Pt                                       ; 
        f_jet1_csv        = _jet1_deepbtag > -1.? _jet1_deepbtag : -2.    ; 
        f_jet2_csv        = _jet2_deepbtag > -1.? _jet2_deepbtag : -2.    ; 
        f_jet1_pt         = _jet1_Pt > 0 ? _jet1_Pt : -50.                ; 
        //f_mva             =    ; 

        outTree->Fill();
        //th1service.getPlot("h1_vh_bdt"         ).FillEntry(_mva                  [0]     ,_weight[0])
        //if _dipho_pt[0] < 75:
        //    th1service.getPlot("h1_vh_bdt1"         ).FillEntry(_mva                  [0]     ,_weight[0])
        //if _dipho_pt[0] > 75:
        //    th1service.getPlot("h1_vh_bdt0"         ).FillEntry(_mva                  [0]     ,_weight[0])
        //if _dipho_pt[0] > 150:
        //    th1service.getPlot("h1_vh_bdt2"         ).FillEntry(_mva                  [0]     ,_weight[0])
        //if _dipho_pt[0] < 150:
        //    th1service.getPlot("h1_vh_bdt3"         ).FillEntry(_mva                  [0]     ,_weight[0])
        
        if( !isSignal() )
            if(f_mass > 120. && f_mass < 130.)
              continue;


        th.Get1DPlot("h1_Mgg"                 )->Fill(f_mass               ,f_weight);
        th.Get1DPlot("h1_lead_phoPt"          )->Fill(pho1P4.Pt()          ,f_weight);
        th.Get1DPlot("h1_leadPho_PToM"        )->Fill(f_pho1_ptoM          ,f_weight);
        th.Get1DPlot("h1_lead_phoEta"         )->Fill(f_pho1_eta           ,f_weight);
        th.Get1DPlot("h1_lead_phoId_mva"      )->Fill(f_pho1_idmva         ,f_weight);
        th.Get1DPlot("h1_pho1_psv"            )->Fill(f_pho1_psv           ,f_weight);
        th.Get1DPlot("h1_subl_phoPt"          )->Fill(pho2P4.Pt()          ,f_weight);
        th.Get1DPlot("h1_sublPho_PToM"        )->Fill(f_pho2_ptoM          ,f_weight);
        th.Get1DPlot("h1_subl_phoEta"         )->Fill(f_pho2_eta           ,f_weight);
        th.Get1DPlot("h1_subl_phoId_mva"      )->Fill(f_pho2_idmva         ,f_weight);
        th.Get1DPlot("h1_pho2_psv"            )->Fill(f_pho2_psv           ,f_weight);
        th.Get1DPlot("h1_min_phoId"           )->Fill(f_min_phoId          ,f_weight);
        th.Get1DPlot("h1_max_phoId"           )->Fill(f_max_phoId          ,f_weight);
        th.Get1DPlot("h1_dipho_dphi"          )->Fill(f_dipho_deltaphi     ,f_weight);
        th.Get1DPlot("h1_dipho_pt"            )->Fill(f_dipho_pt           ,f_weight);
        th.Get1DPlot("h1_dipho_cosphi"        )->Fill(f_dipho_cosphi       ,f_weight);
        th.Get1DPlot("h1_njet"                )->Fill(f_njet               ,f_weight);
        th.Get1DPlot("h1_nele"                )->Fill(f_nele               ,f_weight);
        th.Get1DPlot("h1_nmu"                 )->Fill(f_nmu                ,f_weight);
        th.Get1DPlot("h1_lep_pt"              )->Fill(f_lep_pt             ,f_weight);
        th.Get1DPlot("h1_lep_eta"             )->Fill(f_lep_eta            ,f_weight);
        th.Get1DPlot("h1_mt"                  )->Fill(f_mtlnu              ,f_weight);
        th.Get1DPlot("h1_dr_pho1_lep"         )->Fill(f_dr_pho1_lep        ,f_weight);
        th.Get1DPlot("h1_dr_pho2_lep"         )->Fill(f_dr_pho2_lep        ,f_weight);
        th.Get1DPlot("h1_theta"               )->Fill(f_theta              ,f_weight);
        th.Get1DPlot("h1_met"                 )->Fill(f_met                ,f_weight);
        th.Get1DPlot("h1_lead_jetPt"          )->Fill(f_jet1_pt            ,f_weight);
        th.Get1DPlot("h1_lead_jetb"           )->Fill(f_jet1_csv           ,f_weight);
        th.Get1DPlot("h1_subl_jetb"           )->Fill(f_jet2_csv           ,f_weight);
        th.Get1DPlot("h1_nvtx"                )->Fill(_nvtx                ,f_weight);
        th.Get1DPlot("h1_rho"                 )->Fill(_rho                 ,f_weight);
        th.Get1DPlot("h1_lnupt"               )->Fill(f_lnupt              ,f_weight);
        th.Get1DPlot("h1_dPhiLepMet"          )->Fill(f_dphi_lep_met       ,f_weight);
        th.Get1DPlot("h1_dPhi_Dipho_LepMet"   )->Fill(f_dphi_dipho_lepmet  ,f_weight);


    }

    outfile->Write();
    th.Close();
    outfile->Close();



}
