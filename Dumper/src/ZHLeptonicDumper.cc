
#include "HggAnalyzer/Dumper/interface/ZHLeptonicDumper.h"
#include "HggAnalyzer/Dumper/interface/THistService.h"

#include <cstdlib>
#include <iostream>

using namespace std;

ZHLeptonicDumper::ZHLeptonicDumper(string filename, string type): DiphotonBase(filename, "ZHLeptonicTag", type) 
{
    Initialization();
}

void
ZHLeptonicDumper::Initialization()
{
    _tree -> SetBranchAddress("n_ele",                     &_n_ele                      );
    _tree -> SetBranchAddress("ele1_Pt",                   &_ele1_Pt                    );
    _tree -> SetBranchAddress("ele1_Eta",                  &_ele1_Eta                   );
    _tree -> SetBranchAddress("ele1_Phi",                  &_ele1_Phi                   );
    _tree -> SetBranchAddress("ele1_E",                    &_ele1_E                     );
    _tree -> SetBranchAddress("ele2_Pt",                   &_ele2_Pt                    );
    _tree -> SetBranchAddress("ele2_Eta",                  &_ele2_Eta                   );
    _tree -> SetBranchAddress("ele2_Phi",                  &_ele2_Phi                   );
    _tree -> SetBranchAddress("ele2_E",                    &_ele2_E                     );
    _tree -> SetBranchAddress("n_mu",                      &_n_mu                       );
    _tree -> SetBranchAddress("mu1_Pt",                    &_mu1_Pt                     );
    _tree -> SetBranchAddress("mu1_Eta",                   &_mu1_Eta                    );
    _tree -> SetBranchAddress("mu1_Phi",                   &_mu1_Phi                    );
    _tree -> SetBranchAddress("mu1_E",                     &_mu1_E                      );
    _tree -> SetBranchAddress("mu2_Pt",                    &_mu2_Pt                     );
    _tree -> SetBranchAddress("mu2_Eta",                   &_mu2_Eta                    );
    _tree -> SetBranchAddress("mu2_Phi",                   &_mu2_Phi                    );
    _tree -> SetBranchAddress("mu2_E",                     &_mu2_E                      );
    _tree -> SetBranchAddress("n_jets",                    &_n_jets                     );
    _tree -> SetBranchAddress("jet1_Pt",                   &_jet1_Pt                    );
    _tree -> SetBranchAddress("jet1_deepbtag",             &_jet1_deepbtag              );
    _tree -> SetBranchAddress("jet2_deepbtag",             &_jet2_deepbtag              );
    //new
    //_tree -> SetBranchAddress("max_jet_dCSV",             &_max_jet_dCSV               );
    if (isSignal()) {
        _tree -> SetBranchAddress("VhasNeu",                   &_VhasNeu                    );
        _tree -> SetBranchAddress("VhasLep",                   &_VhasLep                    );
        _tree -> SetBranchAddress("VhasHad",                   &_VhasHad                    );
    }
//    _intree -> SetBranchAddress("", );

}

void
ZHLeptonicDumper::SetGlobalScale(double scale)
{
    _scale = scale;
}

void
ZHLeptonicDumper::Dumper(string outdir, string vhtype, bool is_data_driven)
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
    outTree->Branch("lep1_pt"              , &f_lep1_pt               ,  "lep1_pt/F"              );
    outTree->Branch("lep2_pt"              , &f_lep2_pt               ,  "lep2_pt/F"              );
    outTree->Branch("lep1_eta"             , &f_lep1_eta              ,  "lep1_eta/F"             );
    outTree->Branch("lep2_eta"             , &f_lep2_eta              ,  "lep2_eta/F"             );
    outTree->Branch("dr_pho1_lep1"         , &f_dr_pho1_lep1          ,  "dr_pho1_lep1/F"         );
    outTree->Branch("dr_pho1_lep2"         , &f_dr_pho1_lep2          ,  "dr_pho1_lep2/F"         );
    outTree->Branch("dr_pho2_lep1"         , &f_dr_pho2_lep1          ,  "dr_pho2_lep1/F"         );
    outTree->Branch("dr_pho2_lep2"         , &f_dr_pho2_lep2          ,  "dr_pho2_lep2/F"         );
    outTree->Branch("dilep_mass"           , &f_dilep_mass            ,  "dilep_mass/F"           );
    outTree->Branch("dilep_pt"             , &f_dilep_pt              ,  "dilep_pt/F"             );
    outTree->Branch("njet"                 , &f_njet                  ,  "njet/F"                 );
    outTree->Branch("jet1_pt"              , &f_jet1_pt               ,  "jet1_pt/F"              );
    outTree->Branch("leptonType"           , &f_leptonType            ,  "leptonType/F"           );

    //Old
    outTree->Branch("theta"                , &f_theta                 ,  "theta/F"                );
    outTree->Branch("jet1_csv"             , &f_jet1_csv              ,  "jet1_csv/F"             );
    outTree->Branch("jet2_csv"             , &f_jet2_csv              ,  "jet2_csv/F"             );

    //Could
    outTree->Branch("max_jet_dCSV"         , &f_max_jet_dCSV          ,  "max_jet_dCSV/F"         );
    outTree->Branch("dphi_dipho_dilep"     , &f_dphi_dipho_dilep      ,  "dphi_dipho_dilep/F"     );
    outTree->Branch("pt_balance"           , &f_pt_balance            ,  "pt_balance/F"           );
    outTree->Branch("dilep_dphi"           , &f_dilep_dphi            ,  "dilep_dphi/F"           );
    outTree->Branch("dilep_cosphi"         , &f_dilep_cosphi          ,  "dilep_cosphi/F"         );
    outTree->Branch("cosThetaStar"         , &f_cosThetaStar          ,  "cosThetaStar/F"         );

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
    th.AddNewTH1("h1_lep1_pt"                 ,25  ,0.   ,100.   );
    th.AddNewTH1("h1_lep2_pt"                 ,25  ,0.   ,100.   );
    th.AddNewTH1("h1_lep1_eta"                ,30  ,-3.  ,3.     );
    th.AddNewTH1("h1_lep2_eta"                ,30  ,-3.  ,3.     );
    th.AddNewTH1("h1_dr_pho1_lep1"            ,25  ,0.2  ,4      );
    th.AddNewTH1("h1_dr_pho2_lep1"            ,25  ,0.2  ,4      );
    th.AddNewTH1("h1_dr_pho1_lep2"            ,25  ,0.2  ,4      );
    th.AddNewTH1("h1_dr_pho2_lep2"            ,25  ,0.2  ,4      );
    th.AddNewTH1("h1_dilep_mass"              ,30  ,60   ,120    );
    th.AddNewTH1("h1_dilep_pt"                ,20  ,0    ,200    );
    th.AddNewTH1("h1_theta"                   ,32  ,0    ,3.2    );
    th.AddNewTH1("h1_njet"                    ,10  ,0.   ,10.    );
    th.AddNewTH1("h1_lead_jetPt"              ,20  ,0.   ,300.   );
    th.AddNewTH1("h1_lead_jetb"               ,10  ,0.   ,1.     );
    th.AddNewTH1("h1_nvtx"                    ,60  ,0.   ,60.    );
    th.AddNewTH1("h1_rho"                     ,60  ,0.   ,60.    );
    th.AddNewTH1("h1_max_jet_dCSV"            ,10  ,0.   ,1.     );
    th.AddNewTH1("h1_dphi_dipho_dilep"        ,16  ,0.   ,3.2    );
    th.AddNewTH1("h1_pt_balance"              ,11  ,-10. ,1.     );
    th.AddNewTH1("h1_dilep_dphi"              ,16  ,-3.2 ,3.2    );
    th.AddNewTH1("h1_dilep_cosphi"            ,20  ,-1.  ,1      );
    th.AddNewTH1("h1_cosThetaStar"            ,20  ,0.   ,1      );


    for (int i = 0; i < _tree->GetEntries(); i ++) {
        _tree->GetEntry(i);

        TLorentzVector pho1P4 = Photon1P4();
        TLorentzVector pho2P4 = Photon2P4();
        TLorentzVector diphoP4 = pho1P4 + pho2P4;

        TLorentzVector dipho_dilep_P4;

        if (_n_ele >= 2) {

            TLorentzVector ele1P4, ele2P4;
            ele1P4.SetPtEtaPhiE(_ele1_Pt, _ele1_Eta, _ele1_Phi, _ele1_E);
            ele2P4.SetPtEtaPhiE(_ele2_Pt, _ele2_Eta, _ele2_Phi, _ele2_E);

            auto dieleP4 = ele1P4 + ele2P4;
            dipho_dilep_P4 = diphoP4 + dieleP4;

            f_lep1_pt      = ele1P4.Pt();
            f_lep2_pt      = ele2P4.Pt();
            f_lep1_eta     = ele1P4.Eta();
            f_lep2_eta     = ele2P4.Eta();

            f_dr_pho1_lep1 = ele1P4.DeltaR(pho1P4);
            f_dr_pho1_lep2 = ele2P4.DeltaR(pho1P4);
            f_dr_pho2_lep1 = ele1P4.DeltaR(pho2P4);
            f_dr_pho2_lep2 = ele2P4.DeltaR(pho2P4);

            f_dilep_mass   = dieleP4.M();
            f_dilep_pt     = dieleP4.Pt();
            f_theta        = diphoP4.Angle(dieleP4.Vect());

            f_leptonType  = 11.;

            ///new

            f_dphi_dipho_dilep  = fabs( diphoP4.DeltaPhi(dieleP4) );
            f_pt_balance        = (diphoP4.Pt() - dieleP4.Pt()) / diphoP4.Pt();
            f_dilep_dphi        = fabs( ele1P4.DeltaPhi( ele2P4 ) );
            f_dilep_cosphi      = cos( f_dilep_dphi );



        } else {

            TLorentzVector mu1P4, mu2P4;
            mu1P4.SetPtEtaPhiE(_mu1_Pt, _mu1_Eta, _mu1_Phi, _mu1_E);
            mu2P4.SetPtEtaPhiE(_mu2_Pt, _mu2_Eta, _mu2_Phi, _mu2_E);
            
            auto dimuP4 = mu1P4 + mu2P4;
            dipho_dilep_P4 = diphoP4 + dimuP4;
            
            f_lep1_pt      = mu1P4.Pt();
            f_lep2_pt      = mu2P4.Pt();
            f_lep1_eta     = mu1P4.Eta();
            f_lep2_eta     = mu2P4.Eta();

            f_dr_pho1_lep1 = mu1P4.DeltaR(pho1P4);
            f_dr_pho1_lep2 = mu2P4.DeltaR(pho1P4);
            f_dr_pho2_lep1 = mu1P4.DeltaR(pho2P4);
            f_dr_pho2_lep2 = mu2P4.DeltaR(pho2P4);
                                                                               
            f_dilep_mass   = dimuP4.M();
            f_dilep_pt     = dimuP4.Pt();
            f_theta       = diphoP4.Angle(dimuP4.Vect());
                                                                               
            f_leptonType  = 13.;
                                                                               
            ///new
                                                                               
            f_dphi_dipho_dilep  = fabs( diphoP4.DeltaPhi(dimuP4) );
            f_pt_balance        = (diphoP4.Pt() - dimuP4.Pt()) / diphoP4.Pt();
            f_dilep_dphi        = fabs( mu1P4.DeltaPhi( mu2P4 ) );
            f_dilep_cosphi      = cos( f_dilep_dphi );


        }

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
        f_jet1_csv        = _jet1_deepbtag > -1.? _jet1_deepbtag : -2.    ; 
        f_jet1_pt         = _jet1_Pt > 0 ? _jet1_Pt : -50.                ; 
        //f_mva             =    ;
        
        //f_max_jet_dCSV  = event.maxJetDeepCSV
        
        diphoP4.Boost( -dipho_dilep_P4.BoostVector() );
        f_cosThetaStar = -1. * diphoP4.CosTheta();

        outTree->Fill();
        
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
        th.Get1DPlot("h1_lep1_pt"             )->Fill(f_lep1_pt            ,f_weight);
        th.Get1DPlot("h1_lep2_pt"             )->Fill(f_lep2_pt            ,f_weight);
        th.Get1DPlot("h1_lep1_eta"            )->Fill(f_lep1_eta           ,f_weight);
        th.Get1DPlot("h1_lep2_eta"            )->Fill(f_lep2_eta           ,f_weight);
        th.Get1DPlot("h1_dr_pho1_lep1"        )->Fill(f_dr_pho1_lep1       ,f_weight);
        th.Get1DPlot("h1_dr_pho1_lep2"        )->Fill(f_dr_pho1_lep2       ,f_weight);
        th.Get1DPlot("h1_dr_pho2_lep1"        )->Fill(f_dr_pho2_lep1       ,f_weight);
        th.Get1DPlot("h1_dr_pho2_lep2"        )->Fill(f_dr_pho2_lep2       ,f_weight);
        th.Get1DPlot("h1_dilep_mass"          )->Fill(f_dilep_mass         ,f_weight);
        th.Get1DPlot("h1_dilep_pt"            )->Fill(f_dilep_pt           ,f_weight);
        th.Get1DPlot("h1_theta"               )->Fill(f_theta              ,f_weight);
        th.Get1DPlot("h1_njet"                )->Fill(f_njet               ,f_weight);
        th.Get1DPlot("h1_lead_jetPt"          )->Fill(f_jet1_pt            ,f_weight);
        th.Get1DPlot("h1_lead_jetb"           )->Fill(f_jet1_csv           ,f_weight);
        th.Get1DPlot("h1_nvtx"                )->Fill(_nvtx                ,f_weight);
        th.Get1DPlot("h1_rho"                 )->Fill(_rho                 ,f_weight);

        //New
        th.Get1DPlot("h1_max_jet_dCSV"        )->Fill(f_max_jet_dCSV       ,f_weight);
        th.Get1DPlot("h1_dphi_dipho_dilep"    )->Fill(f_dphi_dipho_dilep   ,f_weight);
        th.Get1DPlot("h1_pt_balance"          )->Fill(f_pt_balance         ,f_weight);
        th.Get1DPlot("h1_dilep_dphi"          )->Fill(f_dilep_dphi         ,f_weight);
        th.Get1DPlot("h1_dilep_cosphi"        )->Fill(f_dilep_cosphi       ,f_weight);
        th.Get1DPlot("h1_cosThetaStar"        )->Fill(fabs(f_cosThetaStar) ,f_weight);

    }

    outfile->Write();
    th.Close();
    outfile->Close();



}
