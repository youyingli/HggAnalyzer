
#include "HggAnalyzer/Dumper/interface/VHMetDumper.h"
#include "HggAnalyzer/Dumper/interface/THistService.h"

#include "TF1.h"

#include <cstdlib>
#include <iostream>

using namespace std;

VHMetDumper::VHMetDumper(string filename, string type): DiphotonBase(filename, "VHMetTag", type) 
{
    Initialization();
}

void
VHMetDumper::Initialization()
{
    _tree -> SetBranchAddress("n_ele",                     &_n_ele                      );
    _tree -> SetBranchAddress("n_mu",                      &_n_mu                       );
    _tree -> SetBranchAddress("n_jets",                    &_n_jets                     );
    _tree -> SetBranchAddress("jet1_Pt",                   &_jet1_Pt                    );
    _tree -> SetBranchAddress("maxJetDeepCSV",             &_maxJetDeepCSV              );
    _tree -> SetBranchAddress("met_Pt",                    &_met_Pt                     );
    _tree -> SetBranchAddress("met_Phi",                   &_met_Phi                    );
    _tree -> SetBranchAddress("met_sumEt",                 &_met_sumEt                  );
    _tree -> SetBranchAddress("met_Sig",                   &_met_Sig                    );
    _tree -> SetBranchAddress("met_RealSig",               &_met_RealSig                );
    _tree -> SetBranchAddress("minDeltaPhiJetMet",         &_minDeltaPhiJetMet          );
    if (isSignal()) {
        _tree -> SetBranchAddress("VhasNeu",                   &_VhasNeu                    );
        _tree -> SetBranchAddress("VhasLep",                   &_VhasLep                    );
        _tree -> SetBranchAddress("VhasHad",                   &_VhasHad                    );
    }
//    _intree -> SetBranchAddress("", );

}

void
VHMetDumper::SetGlobalScale(double scale)
{
    _scale = scale;
}

void
VHMetDumper::Dumper(string outdir, string vhtype, bool is_data_driven)
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
    outTree->Branch("dipho_pt"             , &f_dipho_pt              ,  "dipho_pt/F"             );
    outTree->Branch("dipho_deltaphi"       , &f_dipho_deltaphi        ,  "dipho_deltaphi/F"       );
    outTree->Branch("dipho_cosphi"         , &f_dipho_cosphi          ,  "dipho_cosphi/F"         );
    outTree->Branch("njet"                 , &f_njet                  ,  "njet/F"                 );
    outTree->Branch("jet1_pt"              , &f_jet1_pt               ,  "jet1_pt/F"              );
    outTree->Branch("max_jet_dCSV"         , &f_max_jet_dCSV          ,  "max_jet_dCSV/F"         );
    outTree->Branch("met"                  , &f_met                   ,  "met/F"                  );
    outTree->Branch("met_sumEt"            , &f_met_sumEt             ,  "met_sumEt/F"            );
    outTree->Branch("met_Sig"              , &f_met_Sig               ,  "met_Sig/F"              );
    outTree->Branch("met_significance"     , &f_met_significance      ,  "met_significance/F"     );
    outTree->Branch("min_dPhi_jet_met"     , &f_min_dPhi_jet_met      ,  "min_dPhi_jet_met/F"     );
    outTree->Branch("dPhi_dipho_met"       , &f_dPhi_dipho_met        ,  "dPhi_dipho_met/F"       );
    outTree->Branch("pt_balance"           , &f_pt_balance            ,  "pt_balance/F"           );

    Dumper::THistService th;

    th.AddNewTH1("h1_Mgg"                     ,40  ,100. ,180.   );
    th.AddNewTH1("h1_lead_phoPt"              ,30  ,20.  ,260.   );
    th.AddNewTH1("h1_leadPho_PToM"            ,25  ,0.   ,2.5    );
    th.AddNewTH1("h1_lead_phoEta"             ,30  ,-3.  ,3.     );
    th.AddNewTH1("h1_lead_phoId_mva"          ,40  ,-1.  ,1.     );
    th.AddNewTH1("h1_subl_phoPt"              ,30  ,20.  ,140.   );
    th.AddNewTH1("h1_sublPho_PToM"            ,25  ,0.   ,1.     );
    th.AddNewTH1("h1_subl_phoEta"             ,30  ,-3.  ,3.     );
    th.AddNewTH1("h1_subl_phoId_mva"          ,40  ,-1.  ,1.     );
    th.AddNewTH1("h1_min_phoId"               ,40  ,-1   ,1.     );
    th.AddNewTH1("h1_max_phoId"               ,40  ,-1   ,1.     );
    th.AddNewTH1("h1_dipho_pt"                ,30  ,0.   ,375.   );
    th.AddNewTH1("h1_dipho_dphi"              ,20  ,0.   ,3.2    );
    th.AddNewTH1("h1_dipho_cosphi"            ,40  ,-1.  ,1.     );
    th.AddNewTH1("h1_njet"                    ,10  ,0.   ,10.    );
    th.AddNewTH1("h1_lead_jetPt"              ,30  ,0.   ,300.   );
    th.AddNewTH1("h1_max_jet_dCSV"            ,40  ,0.   ,1.     );
    th.AddNewTH1("h1_met"                     ,40  ,0.   ,300.   );
    th.AddNewTH1("h1_met_sumEt"               ,50  ,0.   ,5000.  );
    th.AddNewTH1("h1_met_Sig"                 ,40  ,0.   ,10.    );
    th.AddNewTH1("h1_met_significance"        ,40  ,0.   ,15.    );
    th.AddNewTH1("h1_dPhi_dipho_met"          ,36  ,2    ,3.2    );
    th.AddNewTH1("h1_min_dPhi_jet_met"        ,32  ,0.   ,3.2    );
    th.AddNewTH1("h1_pt_balance"              ,50  ,-9.  ,1.     );
    th.AddNewTH1("h1_nvtx"                    ,60  ,0.   ,60.    );
    th.AddNewTH1("h1_rho"                     ,60  ,0.   ,60.    );

    //Data driven 
    th.AddNewTH1("h1_max_phoId_unpre_raw"             ,51  ,-0.7 ,1.   );
    th.AddNewTH1("h1_max_phoId_unpre"                 ,51  ,-0.7 ,1.   );
    th.AddNewTH1("h1_phoId_mva_fake"                  ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_phoId_mva_prompt"                ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_isOneFake_preselection_minPhoID" ,2   ,0.   ,2.   );
    th.AddNewTH1("h1_isOneFake_sideband_minPhoID"     ,2   ,0.   ,2.   );
    th.AddNewTH1("h1_max_phoID_check"                 ,51  ,-0.7 ,1.   );
                                                                                                                        
    th.AddNewTH1("h1_phoId_mva_fake_Pt_0_40"          ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_phoId_mva_fake_Pt_40_50"         ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_phoId_mva_fake_Pt_50_70"         ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_phoId_mva_fake_Pt_70_90"         ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_phoId_mva_fake_Pt_90_inf"        ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_phoId_mva_fake_Eta_0_5"          ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_phoId_mva_fake_Eta_5_10"         ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_phoId_mva_fake_Eta_10_15"        ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_phoId_mva_fake_Eta_15_20"        ,57  ,-0.9 ,1.   );
    th.AddNewTH1("h1_phoId_mva_fake_Eta_20_25"        ,57  ,-0.9 ,1.   );
                                                                                                                        
    TF1 f_IDMVA("f_IDMVA", "[0] + [1]*x + [2]*x^2 + [3]*x^3 + [4]*x^4 + [5]*x^5 + [6]*x^6 + [7]*x^7", -1.0, 1.0);
    f_IDMVA.SetParameter( 0, 0.0107376  );
    f_IDMVA.SetParameter( 1, -0.00894819);
    f_IDMVA.SetParameter( 2, 0.022018   );
    f_IDMVA.SetParameter( 3, -0.0414607 );
    f_IDMVA.SetParameter( 4, -0.0393888 );
    f_IDMVA.SetParameter( 5, 0.110712   );
    f_IDMVA.SetParameter( 6, 0.0855843  );
    f_IDMVA.SetParameter( 7, -0.134681  );

    //Correlation check
    th.AddNewTH2("h2_fphotonID_pho1_pt"          , 40, -1, 1, 42, 20   ,300. );
    th.AddNewTH2("h2_fphotonID_pho2_pt"          , 40, -1, 1, 36, 20   ,200. );
    th.AddNewTH2("h2_fphotonID_pho1_eta"         , 40, -1, 1, 30, -3.  ,3.   );
    th.AddNewTH2("h2_fphotonID_pho2_eta"         , 40, -1, 1, 30, -3.  ,3.   );
    th.AddNewTH2("h2_fphotonID_pho1_ptoM"        , 40, -1, 1, 25, 0.   ,2.0  );
    th.AddNewTH2("h2_fphotonID_pho2_ptoM"        , 40, -1, 1, 28, 0.   ,0.7  );
    th.AddNewTH2("h2_fphotonID_dipho_cosphi"     , 40, -1, 1, 40, -1.  ,1.   );
    th.AddNewTH2("h2_fphotonID_njet"             , 40, -1, 1, 10, 0.   ,10.  );
    th.AddNewTH2("h2_fphotonID_jet1_pt"          , 40, -1, 1, 30, 0.   ,300. );
    th.AddNewTH2("h2_fphotonID_max_jet_dCSV"     , 40, -1, 1, 40, 0.   ,1.   );
    th.AddNewTH2("h2_fphotonID_met"              , 40, -1, 1, 40, 0.   ,200. );
    th.AddNewTH2("h2_fphotonID_met_sumEt"        , 40, -1, 1, 40, 0.   ,4000.);
    th.AddNewTH2("h2_fphotonID_met_significance" , 40, -1, 1, 40, 0.   ,15.  );
    th.AddNewTH2("h2_fphotonID_min_dPhi_jet_met" , 40, -1, 1, 32, 0.   ,3.2  );
    th.AddNewTH2("h2_fphotonID_dPhi_dipho_met"   , 40, -1, 1, 36, 2.   ,3.2  );
    th.AddNewTH2("h2_fphotonID_pt_balance"       , 40, -1, 1, 36, -11. ,1    );

    th.AddNewTH2("h2_pphotonID_pho1_pt"          , 40, -1, 1, 42, 20   ,300. );
    th.AddNewTH2("h2_pphotonID_pho2_pt"          , 40, -1, 1, 36, 20   ,200. );
    th.AddNewTH2("h2_pphotonID_pho1_eta"         , 40, -1, 1, 30, -3.  ,3.   );
    th.AddNewTH2("h2_pphotonID_pho2_eta"         , 40, -1, 1, 30, -3.  ,3.   );
    th.AddNewTH2("h2_pphotonID_pho1_ptoM"        , 40, -1, 1, 25, 0.   ,2.0  );
    th.AddNewTH2("h2_pphotonID_pho2_ptoM"        , 40, -1, 1, 25, 0.   ,0.7  );
    th.AddNewTH2("h2_pphotonID_dipho_cosphi"     , 40, -1, 1, 40, -1.  ,1.   );
    th.AddNewTH2("h2_pphotonID_njet"             , 40, -1, 1, 10, 0.   ,10.  );
    th.AddNewTH2("h2_pphotonID_jet1_pt"          , 40, -1, 1, 30, 0.   ,300. );
    th.AddNewTH2("h2_pphotonID_max_jet_dCSV"     , 40, -1, 1, 40, 0.   ,1.   );
    th.AddNewTH2("h2_pphotonID_met"              , 40, -1, 1, 40, 0.   ,200. );
    th.AddNewTH2("h2_pphotonID_met_sumEt"        , 40, -1, 1, 40, 0.   ,4000.);
    th.AddNewTH2("h2_pphotonID_met_significance" , 40, -1, 1, 40, 0.   ,15.  );
    th.AddNewTH2("h2_pphotonID_min_dPhi_jet_met" , 40, -1, 1, 32, 0.   ,3.2  );
    th.AddNewTH2("h2_pphotonID_dPhi_dipho_met"   , 40, -1, 1, 36, 2.   ,3.2  );
    th.AddNewTH2("h2_pphotonID_pt_balance"       , 40, -1, 1, 36, -11. ,1    );


    for (int i = 0; i < _tree->GetEntries(); i ++) {
        _tree->GetEntry(i);

        TLorentzVector pho1P4 = Photon1P4();
        TLorentzVector pho2P4 = Photon2P4();
        TLorentzVector diphoP4 = pho1P4 + pho2P4;

        if (_n_ele != 0. || _n_mu != 0.) continue;

        if (vhtype != "") {
            if (vhtype == "zh_dilep" or vhtype == "wh_lep") {
                if (_VhasLep != 1) continue;
            } else if (vhtype == "zh_met") {
                if (_VhasNeu != 1) continue;
            } else if (vhtype == "zh_had" || vhtype == "wh_had") {
                if (_VhasHad != 1) continue;
            }
        }

        f_mass             = _dipho_mass                                   ; 
        f_weight           = Weight() * _scale                             ; 
        f_pho1_eta         = pho1P4.Eta()                                  ; 
        f_pho2_eta         = pho2P4.Eta()                                  ; 
        f_pho1_ptoM        = _dipho_lead_ptoM                              ; 
        f_pho2_ptoM        = _dipho_sublead_ptoM                           ; 
        f_pho1_idmva       = _dipho_leadIDMVA                              ; 
        f_pho2_idmva       = _dipho_subleadIDMVA                           ; 
        f_min_phoId        = min(f_pho1_idmva, f_pho2_idmva)               ; 
        f_max_phoId        = max(f_pho1_idmva, f_pho2_idmva)               ; 
        f_dipho_pt         = diphoP4.Pt()                                  ; 
        f_dipho_deltaphi   = pho1P4.DeltaPhi(pho2P4)                       ; 
        f_dipho_cosphi     = cos(f_dipho_deltaphi)                         ; 
        f_njet             = _n_jets                                       ; 
        f_jet1_pt          = _jet1_Pt > 0 ? _jet1_Pt : -50.                ;
        f_max_jet_dCSV     = _maxJetDeepCSV                                ;
        f_met              = _met_Pt                                       ;
        f_met_sumEt        = _met_sumEt                                    ;
        f_met_Sig          = _met_Sig                                      ;
        f_met_significance = _met_RealSig                                  ;
        f_min_dPhi_jet_met = _minDeltaPhiJetMet                            ;
        f_dPhi_dipho_met   = fabs( TVector2::Phi_mpi_pi(diphoP4.Phi() - _met_Phi) );
        f_pt_balance       = (diphoP4.Pt() - _met_Pt)/diphoP4.Pt()         ;


        if (f_dPhi_dipho_met < 2.) continue;

        // ---------------- Data driven start -------------------------------------------
        
        //Check the QCD/Photon + Jets occupancy rate in sideband
        if (f_max_phoId > -0.7 && f_min_phoId < -0.7)
            th.Get1DPlot("h1_max_phoID_check")->Fill(f_max_phoId, f_weight);


        if (isGJets()) {

            if (!isPhoton2Prompt()) {

                //Check fake photon ID with other variables
                th.Get2DPlot("h2_fphotonID_pho1_pt"          )->Fill( f_pho2_idmva, pho1P4.Pt()          );
                th.Get2DPlot("h2_fphotonID_pho2_pt"          )->Fill( f_pho2_idmva, pho2P4.Pt()          );
                th.Get2DPlot("h2_fphotonID_pho1_eta"         )->Fill( f_pho2_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_fphotonID_pho2_eta"         )->Fill( f_pho2_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_fphotonID_pho1_ptoM"        )->Fill( f_pho2_idmva, f_pho1_ptoM          );
                th.Get2DPlot("h2_fphotonID_pho2_ptoM"        )->Fill( f_pho2_idmva, f_pho2_ptoM          );
                th.Get2DPlot("h2_fphotonID_dipho_cosphi"     )->Fill( f_pho2_idmva, f_dipho_cosphi       );
                th.Get2DPlot("h2_fphotonID_njet"             )->Fill( f_pho2_idmva, f_njet               );
                th.Get2DPlot("h2_fphotonID_jet1_pt"          )->Fill( f_pho2_idmva, f_jet1_pt            );
                th.Get2DPlot("h2_fphotonID_max_jet_dCSV"     )->Fill( f_pho2_idmva, f_max_jet_dCSV       );
                th.Get2DPlot("h2_fphotonID_met"              )->Fill( f_pho2_idmva, f_met                );
                th.Get2DPlot("h2_fphotonID_met_sumEt"        )->Fill( f_pho2_idmva, f_met_sumEt          );
                th.Get2DPlot("h2_fphotonID_met_significance" )->Fill( f_pho2_idmva, f_met_significance   );
                th.Get2DPlot("h2_fphotonID_min_dPhi_jet_met" )->Fill( f_pho2_idmva, f_min_dPhi_jet_met   );
                th.Get2DPlot("h2_fphotonID_dPhi_dipho_met"   )->Fill( f_pho2_idmva, f_dPhi_dipho_met     );
                th.Get2DPlot("h2_fphotonID_pt_balance"       )->Fill( f_pho2_idmva, f_pt_balance         );

                //Fake photon ID distribution for fitting
                th.Get1DPlot("h1_phoId_mva_fake")->Fill( f_pho2_idmva, f_weight );

                if (fabs(pho2P4.Pt()) < 40.) {
                    th.Get1DPlot("h1_phoId_mva_fake_Pt_0_40")->Fill( f_pho2_idmva, f_weight );
                } else if (fabs(pho2P4.Pt()) < 50.) {
                    th.Get1DPlot("h1_phoId_mva_fake_Pt_40_50")->Fill( f_pho2_idmva, f_weight );
                } else if (fabs(pho2P4.Pt()) < 70.) {
                    th.Get1DPlot("h1_phoId_mva_fake_Pt_50_70")->Fill( f_pho2_idmva, f_weight );
                } else if (fabs(pho2P4.Pt()) < 90.) {
                    th.Get1DPlot("h1_phoId_mva_fake_Pt_70_90")->Fill( f_pho2_idmva, f_weight );
                } else if (fabs(pho2P4.Pt()) < 9999.) {
                    th.Get1DPlot("h1_phoId_mva_fake_Pt_90_inf")->Fill( f_pho2_idmva, f_weight );
                }

                if (fabs(pho2P4.Eta()) < 0.5) {
                    th.Get1DPlot("h1_phoId_mva_fake_Eta_0_5")->Fill( f_pho2_idmva, f_weight );
                } else if (fabs(pho2P4.Eta()) < 1.0) {
                    th.Get1DPlot("h1_phoId_mva_fake_Eta_5_10")->Fill( f_pho2_idmva, f_weight );
                } else if (fabs(pho2P4.Eta()) < 1.5) {
                    th.Get1DPlot("h1_phoId_mva_fake_Eta_10_15")->Fill( f_pho2_idmva, f_weight );
                } else if (fabs(pho2P4.Eta()) < 2.0) {
                    th.Get1DPlot("h1_phoId_mva_fake_Eta_15_20")->Fill( f_pho2_idmva, f_weight );
                } else if (fabs(pho2P4.Eta()) < 2.5) {
                    th.Get1DPlot("h1_phoId_mva_fake_Eta_20_25")->Fill( f_pho2_idmva, f_weight );
                }

            } else if (!isPhoton1Prompt()) {

                th.Get2DPlot("h2_fphotonID_pho1_pt"          )->Fill( f_pho1_idmva, pho1P4.Pt()          );
                th.Get2DPlot("h2_fphotonID_pho2_pt"          )->Fill( f_pho1_idmva, pho2P4.Pt()          );
                th.Get2DPlot("h2_fphotonID_pho1_eta"         )->Fill( f_pho1_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_fphotonID_pho2_eta"         )->Fill( f_pho1_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_fphotonID_pho1_ptoM"        )->Fill( f_pho1_idmva, f_pho1_ptoM          );
                th.Get2DPlot("h2_fphotonID_pho2_ptoM"        )->Fill( f_pho1_idmva, f_pho2_ptoM          );
                th.Get2DPlot("h2_fphotonID_dipho_cosphi"     )->Fill( f_pho1_idmva, f_dipho_cosphi       );
                th.Get2DPlot("h2_fphotonID_njet"             )->Fill( f_pho1_idmva, f_njet               );
                th.Get2DPlot("h2_fphotonID_jet1_pt"          )->Fill( f_pho1_idmva, f_jet1_pt            );
                th.Get2DPlot("h2_fphotonID_max_jet_dCSV"     )->Fill( f_pho1_idmva, f_max_jet_dCSV       );
                th.Get2DPlot("h2_fphotonID_met"              )->Fill( f_pho1_idmva, f_met                );
                th.Get2DPlot("h2_fphotonID_met_sumEt"        )->Fill( f_pho1_idmva, f_met_sumEt          );
                th.Get2DPlot("h2_fphotonID_met_significance" )->Fill( f_pho1_idmva, f_met_significance   );
                th.Get2DPlot("h2_fphotonID_min_dPhi_jet_met" )->Fill( f_pho1_idmva, f_min_dPhi_jet_met   );
                th.Get2DPlot("h2_fphotonID_dPhi_dipho_met"   )->Fill( f_pho1_idmva, f_dPhi_dipho_met     );
                th.Get2DPlot("h2_fphotonID_pt_balance"       )->Fill( f_pho1_idmva, f_pt_balance         );

                th.Get1DPlot("h1_phoId_mva_fake")->Fill( f_pho1_idmva, f_weight );

                if (fabs(pho1P4.Pt()) < 40.) {
                    th.Get1DPlot("h1_phoId_mva_fake_Pt_0_40")->Fill( f_pho1_idmva, f_weight );
                } else if (fabs(pho1P4.Pt()) < 50.) {
                    th.Get1DPlot("h1_phoId_mva_fake_Pt_40_50")->Fill( f_pho1_idmva, f_weight );
                } else if (fabs(pho1P4.Pt()) < 70.) {
                    th.Get1DPlot("h1_phoId_mva_fake_Pt_50_70")->Fill( f_pho1_idmva, f_weight );
                } else if (fabs(pho1P4.Pt()) < 90.) {
                    th.Get1DPlot("h1_phoId_mva_fake_Pt_70_90")->Fill( f_pho1_idmva, f_weight );
                } else if (fabs(pho1P4.Pt()) < 9999.) {
                    th.Get1DPlot("h1_phoId_mva_fake_Pt_90_inf")->Fill( f_pho1_idmva, f_weight );
                }

                if (fabs(pho1P4.Eta()) < 0.5) {
                    th.Get1DPlot("h1_phoId_mva_fake_Eta_0_5")->Fill( f_pho1_idmva, f_weight );
                } else if (fabs(pho1P4.Eta()) < 1.0) {
                    th.Get1DPlot("h1_phoId_mva_fake_Eta_5_10")->Fill( f_pho1_idmva, f_weight );
                } else if (fabs(pho1P4.Eta()) < 1.5) {
                    th.Get1DPlot("h1_phoId_mva_fake_Eta_10_15")->Fill( f_pho1_idmva, f_weight );
                } else if (fabs(pho1P4.Eta()) < 2.0) {
                    th.Get1DPlot("h1_phoId_mva_fake_Eta_15_20")->Fill( f_pho1_idmva, f_weight );
                } else if (fabs(pho1P4.Eta()) < 2.5) {
                    th.Get1DPlot("h1_phoId_mva_fake_Eta_20_25")->Fill( f_pho1_idmva, f_weight );
                }
 
            } else if (isPhoton1Prompt()) {

                th.Get2DPlot("h2_pphotonID_pho1_pt"          )->Fill( f_pho1_idmva, pho1P4.Pt()          );
                th.Get2DPlot("h2_pphotonID_pho2_pt"          )->Fill( f_pho1_idmva, pho2P4.Pt()          );
                th.Get2DPlot("h2_pphotonID_pho1_eta"         )->Fill( f_pho1_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_pphotonID_pho2_eta"         )->Fill( f_pho1_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_pphotonID_pho1_ptoM"        )->Fill( f_pho1_idmva, f_pho1_ptoM          );
                th.Get2DPlot("h2_pphotonID_pho2_ptoM"        )->Fill( f_pho1_idmva, f_pho2_ptoM          );
                th.Get2DPlot("h2_pphotonID_dipho_cosphi"     )->Fill( f_pho1_idmva, f_dipho_cosphi       );
                th.Get2DPlot("h2_pphotonID_njet"             )->Fill( f_pho1_idmva, f_njet               );
                th.Get2DPlot("h2_pphotonID_jet1_pt"          )->Fill( f_pho1_idmva, f_jet1_pt            );
                th.Get2DPlot("h2_pphotonID_max_jet_dCSV"     )->Fill( f_pho1_idmva, f_max_jet_dCSV       );
                th.Get2DPlot("h2_pphotonID_met"              )->Fill( f_pho1_idmva, f_met                );
                th.Get2DPlot("h2_pphotonID_met_sumEt"        )->Fill( f_pho1_idmva, f_met_sumEt          );
                th.Get2DPlot("h2_pphotonID_met_significance" )->Fill( f_pho1_idmva, f_met_significance   );
                th.Get2DPlot("h2_pphotonID_min_dPhi_jet_met" )->Fill( f_pho1_idmva, f_min_dPhi_jet_met   );
                th.Get2DPlot("h2_pphotonID_dPhi_dipho_met"   )->Fill( f_pho1_idmva, f_dPhi_dipho_met     );
                th.Get2DPlot("h2_pphotonID_pt_balance"       )->Fill( f_pho1_idmva, f_pt_balance         );

                th.Get1DPlot("h1_phoId_mva_prompt")->Fill( f_pho1_idmva, f_weight );

            } else if (isPhoton2Prompt()) {

                th.Get2DPlot("h2_pphotonID_pho1_pt"          )->Fill( f_pho2_idmva, pho1P4.Pt()          );
                th.Get2DPlot("h2_pphotonID_pho2_pt"          )->Fill( f_pho2_idmva, pho2P4.Pt()          );
                th.Get2DPlot("h2_pphotonID_pho1_eta"         )->Fill( f_pho2_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_pphotonID_pho2_eta"         )->Fill( f_pho2_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_pphotonID_pho1_ptoM"        )->Fill( f_pho2_idmva, f_pho1_ptoM          );
                th.Get2DPlot("h2_pphotonID_pho2_ptoM"        )->Fill( f_pho2_idmva, f_pho2_ptoM          );
                th.Get2DPlot("h2_pphotonID_dipho_cosphi"     )->Fill( f_pho2_idmva, f_dipho_cosphi       );
                th.Get2DPlot("h2_pphotonID_njet"             )->Fill( f_pho2_idmva, f_njet               );
                th.Get2DPlot("h2_pphotonID_jet1_pt"          )->Fill( f_pho2_idmva, f_jet1_pt            );
                th.Get2DPlot("h2_pphotonID_max_jet_dCSV"     )->Fill( f_pho2_idmva, f_max_jet_dCSV       );
                th.Get2DPlot("h2_pphotonID_met"              )->Fill( f_pho2_idmva, f_met                );
                th.Get2DPlot("h2_pphotonID_met_sumEt"        )->Fill( f_pho2_idmva, f_met_sumEt          );
                th.Get2DPlot("h2_pphotonID_met_significance" )->Fill( f_pho2_idmva, f_met_significance   );
                th.Get2DPlot("h2_pphotonID_min_dPhi_jet_met" )->Fill( f_pho2_idmva, f_min_dPhi_jet_met   );
                th.Get2DPlot("h2_pphotonID_dPhi_dipho_met"   )->Fill( f_pho2_idmva, f_dPhi_dipho_met     );
                th.Get2DPlot("h2_pphotonID_pt_balance"       )->Fill( f_pho2_idmva, f_pt_balance         );

                th.Get1DPlot("h1_phoId_mva_prompt")->Fill( f_pho2_idmva, f_weight );
            }

            if (f_max_phoId > -0.7 && f_min_phoId < -0.7) {
 
                if (f_pho1_idmva > f_pho2_idmva) {
                    if (!isPhoton2Prompt()) {
                        th.Get1DPlot("h1_isOneFake_sideband_minPhoID")->Fill( 1., f_weight );
                    } else { 
                        th.Get1DPlot("h1_isOneFake_sideband_minPhoID")->Fill( 0., f_weight );
                    }
                } else {
                    if (!isPhoton1Prompt()) {
                        th.Get1DPlot("h1_isOneFake_sideband_minPhoID")->Fill( 1., f_weight );
                    } else {
                        th.Get1DPlot("h1_isOneFake_sideband_minPhoID")->Fill( 0., f_weight );
                    }
                }
            }
                                                                                                              
            if (f_max_phoId > -0.7 && f_min_phoId > -0.7) {
                                                                                                              
                if (f_pho1_idmva > f_pho2_idmva) {
                    if (!isPhoton2Prompt()) {
                        th.Get1DPlot("h1_isOneFake_preselection_minPhoID")->Fill( 1., f_weight );
                    } else { 
                        th.Get1DPlot("h1_isOneFake_preselection_minPhoID")->Fill( 0., f_weight );
                    }
                } else {
                    if (!isPhoton1Prompt()) {
                        th.Get1DPlot("h1_isOneFake_preselection_minPhoID")->Fill( 1., f_weight );
                    } else {
                        th.Get1DPlot("h1_isOneFake_preselection_minPhoID")->Fill( 0., f_weight );
                    }
                }
            }

        }


        if (is_data_driven && isData()) {
            if (f_max_phoId < -0.7 || f_min_phoId > -0.7) continue;

            f_min_phoId = f_IDMVA.GetRandom(-0.7, f_max_phoId);
            f_weight   *= f_IDMVA.Integral(-0.7, f_max_phoId) / f_IDMVA.Integral(-0.9, -0.7);
                                                                                                
        } else {
            if (f_max_phoId < -0.7 || f_min_phoId < -0.7) continue;
        }

        th.Get1DPlot("h1_max_phoId_unpre_raw"      )->Fill(f_max_phoId   ,is_data_driven ? 1. : f_weight );
        th.Get1DPlot("h1_max_phoId_unpre"          )->Fill(f_max_phoId   ,f_weight );


        if (f_pho1_ptoM < 0.333333 || f_pho2_ptoM < 0.2) continue;
        if (f_met < 50.) continue;

        outTree->Fill();
        
        if( !isSignal() )
            if(f_mass > 120. && f_mass < 130.)
              continue;

        th.Get1DPlot("h1_Mgg"                )->Fill(f_mass                 ,f_weight);
        //th.Get1DPlot("h1_vhmet_mva"          )->Fill(_mva                  [0]     ,_weight[0])
        th.Get1DPlot("h1_lead_phoPt"         )->Fill(pho1P4.Pt()            ,f_weight);
        th.Get1DPlot("h1_leadPho_PToM"       )->Fill(f_pho1_ptoM            ,f_weight);
        th.Get1DPlot("h1_lead_phoEta"        )->Fill(f_pho1_eta             ,f_weight);
        th.Get1DPlot("h1_lead_phoId_mva"     )->Fill(f_pho1_idmva           ,f_weight);
        th.Get1DPlot("h1_subl_phoPt"         )->Fill(pho2P4.Pt()            ,f_weight);
        th.Get1DPlot("h1_sublPho_PToM"       )->Fill(f_pho2_ptoM            ,f_weight);
        th.Get1DPlot("h1_subl_phoEta"        )->Fill(f_pho2_eta             ,f_weight);
        th.Get1DPlot("h1_subl_phoId_mva"     )->Fill(f_pho2_idmva           ,f_weight);
        th.Get1DPlot("h1_min_phoId"          )->Fill(f_min_phoId            ,f_weight);
        th.Get1DPlot("h1_max_phoId"          )->Fill(f_max_phoId            ,f_weight);
        th.Get1DPlot("h1_dipho_dphi"         )->Fill(fabs(f_dipho_deltaphi) ,f_weight);
        th.Get1DPlot("h1_dipho_cosphi"       )->Fill(f_dipho_cosphi         ,f_weight);
        th.Get1DPlot("h1_dipho_pt"           )->Fill(f_dipho_pt             ,f_weight);
        th.Get1DPlot("h1_njet"               )->Fill(f_njet                 ,f_weight);
        th.Get1DPlot("h1_lead_jetPt"         )->Fill(f_jet1_pt              ,f_weight);
        th.Get1DPlot("h1_max_jet_dCSV"       )->Fill(f_max_jet_dCSV         ,f_weight);
        th.Get1DPlot("h1_met"                )->Fill(f_met                  ,f_weight);
        th.Get1DPlot("h1_met_sumEt"          )->Fill(f_met_sumEt            ,f_weight);
        th.Get1DPlot("h1_met_Sig"            )->Fill(f_met_Sig              ,f_weight);
        th.Get1DPlot("h1_met_significance"   )->Fill(f_met_significance     ,f_weight);
        th.Get1DPlot("h1_min_dPhi_jet_met"   )->Fill(f_min_dPhi_jet_met     ,f_weight);
        th.Get1DPlot("h1_dPhi_dipho_met"     )->Fill(f_dPhi_dipho_met       ,f_weight);
        th.Get1DPlot("h1_pt_balance"         )->Fill(f_pt_balance           ,f_weight);
        th.Get1DPlot("h1_nvtx"               )->Fill(_nvtx                  ,f_weight);
        th.Get1DPlot("h1_rho"                )->Fill(_rho                   ,f_weight);

    }

    outfile->Write();
    th.Close();
    outfile->Close();

}
