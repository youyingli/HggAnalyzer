
#include "HggAnalyzer/Dumper/interface/ZHLeptonicDumper.h"
#include "HggAnalyzer/Dumper/interface/THistService.h"

#include "TMVA/Reader.h"

#include <cstdlib>
#include <iostream>

using namespace std;

ZHLeptonicDumper::ZHLeptonicDumper(string filename, string type, string pufilename): DiphotonBase(filename, "ZHLeptonicTag", type, pufilename) 
{
    Initialization();
}

void
ZHLeptonicDumper::Initialization()
{
    _tree -> SetBranchAddress("n_ele",                     &_n_ele                      );
    _tree -> SetBranchAddress("ele1_Charge",               &_ele1_Charge                );
    _tree -> SetBranchAddress("ele1_Pt",                   &_ele1_Pt                    );
    _tree -> SetBranchAddress("ele1_Eta",                  &_ele1_Eta                   );
    _tree -> SetBranchAddress("ele1_Phi",                  &_ele1_Phi                   );
    _tree -> SetBranchAddress("ele1_E",                    &_ele1_E                     );
    _tree -> SetBranchAddress("ele2_Charge",               &_ele2_Charge                );
    _tree -> SetBranchAddress("ele2_Pt",                   &_ele2_Pt                    );
    _tree -> SetBranchAddress("ele2_Eta",                  &_ele2_Eta                   );
    _tree -> SetBranchAddress("ele2_Phi",                  &_ele2_Phi                   );
    _tree -> SetBranchAddress("ele2_E",                    &_ele2_E                     );
    _tree -> SetBranchAddress("n_mu",                      &_n_mu                       );
    _tree -> SetBranchAddress("mu1_Charge",                &_mu1_Charge                 );
    _tree -> SetBranchAddress("mu1_Pt",                    &_mu1_Pt                     );
    _tree -> SetBranchAddress("mu1_Eta",                   &_mu1_Eta                    );
    _tree -> SetBranchAddress("mu1_Phi",                   &_mu1_Phi                    );
    _tree -> SetBranchAddress("mu1_E",                     &_mu1_E                      );
    _tree -> SetBranchAddress("mu1_Charge",                &_mu2_Charge                 );
    _tree -> SetBranchAddress("mu2_Pt",                    &_mu2_Pt                     );
    _tree -> SetBranchAddress("mu2_Eta",                   &_mu2_Eta                    );
    _tree -> SetBranchAddress("mu2_Phi",                   &_mu2_Phi                    );
    _tree -> SetBranchAddress("mu2_E",                     &_mu2_E                      );
    _tree -> SetBranchAddress("n_jets",                    &_n_jets                     );
    _tree -> SetBranchAddress("jet1_Pt",                   &_jet1_Pt                    );
    _tree -> SetBranchAddress("jet1_Eta",                  &_jet1_Eta                   );
    _tree -> SetBranchAddress("jet1_Phi",                  &_jet1_Phi                   );
    _tree -> SetBranchAddress("jet1_E",                    &_jet1_E                     );
    _tree -> SetBranchAddress("jet1_deepbtag",             &_jet1_deepbtag              );
    _tree -> SetBranchAddress("jet2_Pt",                   &_jet2_Pt                    );
    _tree -> SetBranchAddress("jet2_Eta",                  &_jet2_Eta                   );
    _tree -> SetBranchAddress("jet2_Phi",                  &_jet2_Phi                   );
    _tree -> SetBranchAddress("jet2_E",                    &_jet2_E                     );
    _tree -> SetBranchAddress("jet2_deepbtag",             &_jet2_deepbtag              );
    _tree -> SetBranchAddress("jet3_Pt",                   &_jet3_Pt                    );
    _tree -> SetBranchAddress("jet3_Eta",                  &_jet3_Eta                   );
    _tree -> SetBranchAddress("jet3_Phi",                  &_jet3_Phi                   );
    _tree -> SetBranchAddress("jet3_E",                    &_jet3_E                     );
    _tree -> SetBranchAddress("jet3_deepbtag",             &_jet3_deepbtag              );
    _tree -> SetBranchAddress("jet4_Pt",                   &_jet4_Pt                    );
    _tree -> SetBranchAddress("jet4_Eta",                  &_jet4_Eta                   );
    _tree -> SetBranchAddress("jet4_Phi",                  &_jet4_Phi                   );
    _tree -> SetBranchAddress("jet4_E",                    &_jet4_E                     );
    _tree -> SetBranchAddress("jet4_deepbtag",             &_jet4_deepbtag              );
    _tree -> SetBranchAddress("jet5_Pt",                   &_jet5_Pt                    );
    _tree -> SetBranchAddress("jet5_Eta",                  &_jet5_Eta                   );
    _tree -> SetBranchAddress("jet5_Phi",                  &_jet5_Phi                   );
    _tree -> SetBranchAddress("jet5_E",                    &_jet5_E                     );
    _tree -> SetBranchAddress("jet5_deepbtag",             &_jet5_deepbtag              );
    _tree -> SetBranchAddress("jet6_Pt",                   &_jet6_Pt                    );
    _tree -> SetBranchAddress("jet6_Eta",                  &_jet6_Eta                   );
    _tree -> SetBranchAddress("jet6_Phi",                  &_jet6_Phi                   );
    _tree -> SetBranchAddress("jet6_E",                    &_jet6_E                     );
    _tree -> SetBranchAddress("jet6_deepbtag",             &_jet6_deepbtag              );
    _tree -> SetBranchAddress("jet7_Pt",                   &_jet7_Pt                    );
    _tree -> SetBranchAddress("jet7_Eta",                  &_jet7_Eta                   );
    _tree -> SetBranchAddress("jet7_Phi",                  &_jet7_Phi                   );
    _tree -> SetBranchAddress("jet7_E",                    &_jet7_E                     );
    _tree -> SetBranchAddress("jet7_deepbtag",             &_jet7_deepbtag              );
    _tree -> SetBranchAddress("jet8_Pt",                   &_jet8_Pt                    );
    _tree -> SetBranchAddress("jet8_Eta",                  &_jet8_Eta                   );
    _tree -> SetBranchAddress("jet8_Phi",                  &_jet8_Phi                   );
    _tree -> SetBranchAddress("jet8_E",                    &_jet8_E                     );
    _tree -> SetBranchAddress("jet8_deepbtag",             &_jet8_deepbtag              );
    _tree -> SetBranchAddress("jet9_Pt",                   &_jet9_Pt                    );
    _tree -> SetBranchAddress("jet9_Eta",                  &_jet9_Eta                   );
    _tree -> SetBranchAddress("jet9_Phi",                  &_jet9_Phi                   );
    _tree -> SetBranchAddress("jet9_E",                    &_jet9_E                     );
    _tree -> SetBranchAddress("jet9_deepbtag",             &_jet9_deepbtag              );
    _tree -> SetBranchAddress("jet10_Pt",                  &_jet10_Pt                   );
    _tree -> SetBranchAddress("jet10_Eta",                 &_jet10_Eta                  );
    _tree -> SetBranchAddress("jet10_Phi",                 &_jet10_Phi                  );
    _tree -> SetBranchAddress("jet10_E",                   &_jet10_E                    );
    _tree -> SetBranchAddress("jet10_deepbtag",            &_jet10_deepbtag             );
    _tree -> SetBranchAddress("jet11_Pt",                  &_jet11_Pt                   );
    _tree -> SetBranchAddress("jet11_Eta",                 &_jet11_Eta                  );
    _tree -> SetBranchAddress("jet11_Phi",                 &_jet11_Phi                  );
    _tree -> SetBranchAddress("jet11_E",                   &_jet11_E                    );
    _tree -> SetBranchAddress("jet11_deepbtag",            &_jet11_deepbtag             );
    _tree -> SetBranchAddress("jet12_Pt",                  &_jet12_Pt                   );
    _tree -> SetBranchAddress("jet12_Eta",                 &_jet12_Eta                  );
    _tree -> SetBranchAddress("jet12_Phi",                 &_jet12_Phi                  );
    _tree -> SetBranchAddress("jet12_E",                   &_jet12_E                    );
    _tree -> SetBranchAddress("jet12_deepbtag",            &_jet12_deepbtag             );
    _tree -> SetBranchAddress("jet13_Pt",                  &_jet13_Pt                   );
    _tree -> SetBranchAddress("jet13_Eta",                 &_jet13_Eta                  );
    _tree -> SetBranchAddress("jet13_Phi",                 &_jet13_Phi                  );
    _tree -> SetBranchAddress("jet13_E",                   &_jet13_E                    );
    _tree -> SetBranchAddress("jet13_deepbtag",            &_jet13_deepbtag             );
    _tree -> SetBranchAddress("jet14_Pt",                  &_jet14_Pt                   );
    _tree -> SetBranchAddress("jet14_Eta",                 &_jet14_Eta                  );
    _tree -> SetBranchAddress("jet14_Phi",                 &_jet14_Phi                  );
    _tree -> SetBranchAddress("jet14_E",                   &_jet14_E                    );
    _tree -> SetBranchAddress("jet14_deepbtag",            &_jet14_deepbtag             );
    _tree -> SetBranchAddress("jet15_Pt",                  &_jet15_Pt                   );
    _tree -> SetBranchAddress("jet15_Eta",                 &_jet15_Eta                  );
    _tree -> SetBranchAddress("jet15_Phi",                 &_jet15_Phi                  );
    _tree -> SetBranchAddress("jet15_E",                   &_jet15_E                    );
    _tree -> SetBranchAddress("jet15_deepbtag",            &_jet15_deepbtag             );

    //new
    //_tree -> SetBranchAddress("maxJetDeepCSV",             &_maxJetDeepCSV              );
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

vector<pair<TLorentzVector, float>>
ZHLeptonicDumper::SetJetsInfo()
{

    vector<pair<TLorentzVector, float>> jets_info;
    if (_n_jets >0) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet1_Pt, _jet1_Eta, _jet1_Phi, _jet1_E);
        jets_info.push_back( make_pair(jet_p4, _jet1_deepbtag) );
    }

    if (_n_jets >1) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet2_Pt, _jet2_Eta, _jet2_Phi, _jet2_E);
        jets_info.push_back( make_pair(jet_p4, _jet2_deepbtag) );
    }

    if (_n_jets >2) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet3_Pt, _jet3_Eta, _jet3_Phi, _jet3_E);
        jets_info.push_back( make_pair(jet_p4, _jet3_deepbtag) );
    }

    if (_n_jets >3) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet4_Pt, _jet4_Eta, _jet4_Phi, _jet4_E);
        jets_info.push_back( make_pair(jet_p4, _jet4_deepbtag) );
    }

    if (_n_jets >4) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet5_Pt, _jet5_Eta, _jet5_Phi, _jet5_E);
        jets_info.push_back( make_pair(jet_p4, _jet5_deepbtag) );
    }

    if (_n_jets >5) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet6_Pt, _jet6_Eta, _jet6_Phi, _jet6_E);
        jets_info.push_back( make_pair(jet_p4, _jet6_deepbtag) );
    }

    if (_n_jets >6) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet7_Pt, _jet7_Eta, _jet7_Phi, _jet7_E);
        jets_info.push_back( make_pair(jet_p4, _jet7_deepbtag) );
    }

    if (_n_jets >7) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet8_Pt, _jet8_Eta, _jet8_Phi, _jet8_E);
        jets_info.push_back( make_pair(jet_p4, _jet7_deepbtag) );
    }

    if (_n_jets >8) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet9_Pt, _jet9_Eta, _jet9_Phi, _jet9_E);
        jets_info.push_back( make_pair(jet_p4, _jet9_deepbtag) );
    }

    if (_n_jets >9) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet10_Pt, _jet10_Eta, _jet10_Phi, _jet10_E);
        jets_info.push_back( make_pair(jet_p4, _jet10_deepbtag) );
    }

    if (_n_jets >10) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet11_Pt, _jet11_Eta, _jet11_Phi, _jet11_E);
        jets_info.push_back( make_pair(jet_p4, _jet11_deepbtag) );
    }

    if (_n_jets >11) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet12_Pt, _jet12_Eta, _jet12_Phi, _jet12_E);
        jets_info.push_back( make_pair(jet_p4, _jet12_deepbtag) );
    }

    if (_n_jets >12) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet13_Pt, _jet13_Eta, _jet13_Phi, _jet13_E);
        jets_info.push_back( make_pair(jet_p4, _jet13_deepbtag) );
    }

    if (_n_jets >13) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet14_Pt, _jet14_Eta, _jet14_Phi, _jet14_E);
        jets_info.push_back( make_pair(jet_p4, _jet14_deepbtag) );
    }

    if (_n_jets >14) {
        TLorentzVector jet_p4;
        jet_p4.SetPtEtaPhiE(_jet15_Pt, _jet15_Eta, _jet15_Phi, _jet15_E);
        jets_info.push_back( make_pair(jet_p4, _jet15_deepbtag) );
    }

    return jets_info;

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
    outTree->Branch("dphi_dipho"           , &f_dphi_dipho            ,  "dphi_dipho/F"           );
    outTree->Branch("cosdphi_dipho"        , &f_cosdphi_dipho         ,  "cosdphi_dipho/F"        );
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
    outTree->Branch("max_jet_pt"           , &f_max_jet_pt            ,  "max_jet_pt/F"           );
    outTree->Branch("max_jet_dCSV"         , &f_max_jet_dCSV          ,  "max_jet_dCSV/F"         );
    outTree->Branch("leptonType"           , &f_leptonType            ,  "leptonType/F"           );

    //Old
    outTree->Branch("theta"                , &f_theta                 ,  "theta/F"                );

    //Could
    outTree->Branch("dphi_dipho_dilep"     , &f_dphi_dipho_dilep      ,  "dphi_dipho_dilep/F"     );
    outTree->Branch("pt_balance"           , &f_pt_balance            ,  "pt_balance/F"           );
    outTree->Branch("dphi_dilep"           , &f_dphi_dilep            ,  "dphi_dilep/F"           );
    outTree->Branch("cosdphi_dilep"        , &f_cosdphi_dilep         ,  "cosdphi_dilep/F"        );
    outTree->Branch("cosThetaStar"         , &f_cosThetaStar          ,  "cosThetaStar/F"         );

    outTree->Branch("mva1"                   , &f_mva1                    ,  "mva1/F"                  );
    outTree->Branch("mva2"                   , &f_mva2                    ,  "mva2/F"                  );
    outTree->Branch("mva3"                   , &f_mva3                    ,  "mva3/F"                  );
    outTree->Branch("mva4"                   , &f_mva4                    ,  "mva4/F"                  );

    TMVA::Reader tmvareader( "!Color:!Silent" );
    tmvareader.AddVariable(  "pho1_eta"           , & f_pho1_eta             );
    tmvareader.AddVariable(  "pho2_eta"           , & f_pho2_eta             );
    tmvareader.AddVariable(  "pho1_ptoM"          , & f_pho1_ptoM            );
    tmvareader.AddVariable(  "pho2_ptoM"          , & f_pho2_ptoM            );
    tmvareader.AddVariable(  "min_phoId"          , & f_min_phoId            );
    tmvareader.AddVariable(  "max_phoId"          , & f_max_phoId            );
    //tmvareader.AddVariable(  "pho1_psv"           , & f_pho1_psv             );
    //tmvareader.AddVariable(  "pho2_psv"           , & f_pho2_psv             );
    tmvareader.AddVariable(  "cosdphi_dipho"      , & f_cosdphi_dipho        );
    tmvareader.AddVariable(  "lep1_pt"            , & f_lep1_pt              );
    tmvareader.AddVariable(  "lep2_pt"            , & f_lep2_pt              );
    tmvareader.AddVariable(  "lep1_eta"           , & f_lep1_eta             );
    tmvareader.AddVariable(  "lep2_eta"           , & f_lep2_eta             );
    tmvareader.AddVariable(  "dr_pho1_lep1"       , & f_dr_pho1_lep1         );
    tmvareader.AddVariable(  "dr_pho1_lep2"       , & f_dr_pho1_lep2         );
    tmvareader.AddVariable(  "dr_pho2_lep1"       , & f_dr_pho2_lep1         );
    tmvareader.AddVariable(  "dr_pho2_lep2"       , & f_dr_pho2_lep2         );
    tmvareader.AddVariable(  "dilep_mass"         , & f_dilep_mass           );
    tmvareader.AddVariable(  "cosdphi_dilep"      , & f_cosdphi_dilep        );
    tmvareader.AddVariable(  "dphi_dipho_dilep"   , & f_dphi_dipho_dilep     );
    tmvareader.AddVariable(  "pt_balance"         , & f_pt_balance           );
    tmvareader.AddVariable(  "njet"               , & f_njet                 );
    tmvareader.AddVariable(  "max_jet_pt"         , & f_max_jet_pt           );
    tmvareader.AddVariable(  "max_jet_dCSV"       , & f_max_jet_dCSV         );
    tmvareader.AddSpectator( "leptonType", &f_leptonType );

    tmvareader.BookMVA( "BDT", TString( getenv("CMSSW_BASE") ) + "/src/HggAnalyzer/Dumper/data/TMVA_ZHLeptonicTag_BDT_ULv1.weights.xml" );

    Dumper::THistService th;

    th.AddNewTH1(  "h1_Mgg"                     ,25  ,100. ,180.   );
    th.AddNewTH1(  "h1_pho1_pt"                 ,30  ,20.  ,260.   );
    th.AddNewTH1(  "h1_pho1_ptoM"               ,25  ,0.   ,2.5    );
    th.AddNewTH1(  "h1_pho1_eta"                ,30  ,-3.  ,3.     );
    th.AddNewTH1(  "h1_pho1_idmva"              ,40  ,-1.  ,1.     );
    th.AddNewTH1(  "h1_pho1_psv"                , 2  ,0    ,2.     );
    th.AddNewTH1(  "h1_pho2_pt"                 ,30  ,20.  ,140.   );
    th.AddNewTH1(  "h1_pho2_ptoM"               ,25  ,0.   ,1.     );
    th.AddNewTH1(  "h1_pho2_eta"                ,30  ,-3.  ,3.     );
    th.AddNewTH1(  "h1_pho2_idmva"              ,40  ,-1.  ,1.     );
    th.AddNewTH1(  "h1_pho2_psv"                , 2  ,0    ,2.     );
    th.AddNewTH1(  "h1_min_phoId"               ,40  ,-1   ,1.     );
    th.AddNewTH1(  "h1_max_phoId"               ,40  ,-1   ,1.     );
    th.AddNewTH1(  "h1_dphi_dipho"              ,20  ,0.   ,3.2    );
    th.AddNewTH1(  "h1_dipho_pt"                ,30  ,0.   ,375.   );
    th.AddNewTH1(  "h1_cosdphi_dipho"           ,40  ,-1.  ,1.     );
    th.AddNewTH1(  "h1_lep1_pt"                 ,25  ,0.   ,100.   );
    th.AddNewTH1(  "h1_lep2_pt"                 ,25  ,0.   ,100.   );
    th.AddNewTH1(  "h1_lep1_eta"                ,30  ,-3.  ,3.     );
    th.AddNewTH1(  "h1_lep2_eta"                ,30  ,-3.  ,3.     );
    th.AddNewTH1(  "h1_dr_pho1_lep1"            ,25  ,0.2  ,4      );
    th.AddNewTH1(  "h1_dr_pho2_lep1"            ,25  ,0.2  ,4      );
    th.AddNewTH1(  "h1_dr_pho1_lep2"            ,25  ,0.2  ,4      );
    th.AddNewTH1(  "h1_dr_pho2_lep2"            ,25  ,0.2  ,4      );
    th.AddNewTH1(  "h1_dilep_mass"              ,30  ,60   ,120    );
    th.AddNewTH1(  "h1_dilep_pt"                ,20  ,0    ,200    );
    th.AddNewTH1(  "h1_theta"                   ,32  ,0    ,3.2    );
    th.AddNewTH1(  "h1_njet"                    ,10  ,0.   ,10.    );
    th.AddNewTH1(  "h1_max_jet_pt"              ,20  ,0.   ,300.   );
    th.AddNewTH1(  "h1_max_jet_dCSV"            ,10  ,0.   ,1.     );
    th.AddNewTH1(  "h1_ZHLeptonic_MVA"          ,21  ,-0.55 ,0.4   );
    th.AddNewTH1(  "h1_nvtx"                    ,60  ,0.   ,60.    );
    th.AddNewTH1(  "h1_rho"                     ,60  ,0.   ,60.    );
    th.AddNewTH1(  "h1_dphi_dipho_dilep"        ,16  ,0.   ,3.2    );
    th.AddNewTH1(  "h1_pt_balance"              ,11  ,-10. ,1.     );
    th.AddNewTH1(  "h1_dphi_dilep"              ,16  ,-3.2 ,3.2    );
    th.AddNewTH1(  "h1_cosdphi_dilep"           ,20  ,-1.  ,1      );
    th.AddNewTH1(  "h1_cosThetaStar"            ,20  ,0.   ,1      );


    for (int i = 0; i < _tree->GetEntries(); i ++) {
        _tree->GetEntry(i);
        //if (!PassSafetyCuts()) continue;

        TLorentzVector pho1P4 = Photon1P4();
        TLorentzVector pho2P4 = Photon2P4();
        TLorentzVector diphoP4 = pho1P4 + pho2P4;

        TLorentzVector lep1P4, lep2P4;

        if (_n_mu == 2) {

            lep1P4.SetPtEtaPhiE(_mu1_Pt, _mu1_Eta, _mu1_Phi, _mu1_E);
            lep2P4.SetPtEtaPhiE(_mu2_Pt, _mu2_Eta, _mu2_Phi, _mu2_E);

            f_leptonType  = 13.;

        } else if (_n_ele == 2) {

            lep1P4.SetPtEtaPhiE(_ele1_Pt, _ele1_Eta, _ele1_Phi, _ele1_E);
            lep2P4.SetPtEtaPhiE(_ele2_Pt, _ele2_Eta, _ele2_Phi, _ele2_E);

            f_leptonType  = 11.;

        }

        if (f_leptonType != 11. && f_leptonType != 13.) continue;

        int Njets = 0;
        float max_jet_pt   = 0;
        float max_jet_dCSV = 0;
        auto jets = SetJetsInfo();
        for (unsigned int i = 0; i < jets.size(); i++) {
            Njets++;
            if ( max_jet_pt < jets[i].first.Pt() ) max_jet_pt = jets[i].first.Pt();
            if ( max_jet_dCSV < jets[i].second ) max_jet_dCSV = jets[i].second;
        }

        auto dilepP4 = lep1P4 + lep2P4;
        auto dipho_dilep_P4 = diphoP4 + dilepP4;


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
        f_pho1_psv        = Photon1PSV()                                  ; 
        f_pho2_psv        = Photon2PSV()                                  ; 
        f_dipho_pt        = diphoP4.Pt()                                  ; 
        f_dphi_dipho      = pho1P4.DeltaPhi(pho2P4)                       ; 
        f_cosdphi_dipho   = cos(f_dphi_dipho)                             ;

        f_lep1_pt         = lep1P4.Pt()                                   ;
        f_lep2_pt         = lep2P4.Pt()                                   ;
        f_lep1_eta        = lep1P4.Eta()                                  ;
        f_lep2_eta        = lep2P4.Eta()                                  ;
        f_dr_pho1_lep1    = lep1P4.DeltaR(pho1P4)                         ;
        f_dr_pho1_lep2    = lep2P4.DeltaR(pho1P4)                         ;
        f_dr_pho2_lep1    = lep1P4.DeltaR(pho2P4)                         ;
        f_dr_pho2_lep2    = lep2P4.DeltaR(pho2P4)                         ;
        f_dilep_mass      = dilepP4.M()                                   ;
        f_dilep_pt        = dilepP4.Pt()                                  ;
        f_theta           = diphoP4.Angle(dilepP4.Vect())                 ; 

        f_njet            = Njets                                         ; 
        f_max_jet_pt      = max_jet_pt                                    ;
        f_max_jet_dCSV    = max_jet_dCSV                                  ;
        //f_mva             =    ;

        ///new
        f_dphi_dipho_dilep  = fabs( diphoP4.DeltaPhi(dilepP4) );
        f_pt_balance        = (diphoP4.Pt() - dilepP4.Pt()) / diphoP4.Pt();
        f_dphi_dilep        = fabs( lep1P4.DeltaPhi( lep2P4 ) );
        f_cosdphi_dilep     = cos( f_dphi_dilep );

        diphoP4.Boost( -dipho_dilep_P4.BoostVector() );
        f_cosThetaStar = -1. * diphoP4.CosTheta();

        f_mva = tmvareader.EvaluateMVA( "BDT" ); 

        outTree->Fill();
        
        if( !isSignal() )
            if(f_mass > 120. && f_mass < 130.)
              continue;

        th.Get1DPlot("h1_Mgg"                 )->Fill(f_mass               ,f_weight);
        th.Get1DPlot("h1_pho1_pt"             )->Fill(pho1P4.Pt()          ,f_weight);
        th.Get1DPlot("h1_pho1_ptoM"           )->Fill(f_pho1_ptoM          ,f_weight);
        th.Get1DPlot("h1_pho1_eta"            )->Fill(f_pho1_eta           ,f_weight);
        th.Get1DPlot("h1_pho1_idmva"          )->Fill(f_pho1_idmva         ,f_weight);
        th.Get1DPlot("h1_pho1_psv"            )->Fill(f_pho1_psv           ,f_weight);
        th.Get1DPlot("h1_pho2_pt"             )->Fill(pho2P4.Pt()          ,f_weight);
        th.Get1DPlot("h1_pho2_ptoM"           )->Fill(f_pho2_ptoM          ,f_weight);
        th.Get1DPlot("h1_pho2_eta"            )->Fill(f_pho2_eta           ,f_weight);
        th.Get1DPlot("h1_pho2_idmva"          )->Fill(f_pho2_idmva         ,f_weight);
        th.Get1DPlot("h1_pho2_psv"            )->Fill(f_pho2_psv           ,f_weight);
        th.Get1DPlot("h1_min_phoId"           )->Fill(f_min_phoId          ,f_weight);
        th.Get1DPlot("h1_max_phoId"           )->Fill(f_max_phoId          ,f_weight);
        th.Get1DPlot("h1_dphi_dipho"          )->Fill(f_dphi_dipho         ,f_weight);
        th.Get1DPlot("h1_dipho_pt"            )->Fill(f_dipho_pt           ,f_weight);
        th.Get1DPlot("h1_cosdphi_dipho"       )->Fill(f_cosdphi_dipho      ,f_weight);
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
        th.Get1DPlot("h1_max_jet_pt"          )->Fill(f_max_jet_pt         ,f_weight);
        th.Get1DPlot("h1_max_jet_dCSV"        )->Fill(f_max_jet_dCSV       ,f_weight);
        th.Get1DPlot("h1_ZHLeptonic_MVA"      )->Fill(f_mva                ,f_weight);
        th.Get1DPlot("h1_nvtx"                )->Fill(_nvtx                ,f_weight);
        th.Get1DPlot("h1_rho"                 )->Fill(_rho                 ,f_weight);

        //New
        th.Get1DPlot("h1_dphi_dipho_dilep"    )->Fill(f_dphi_dipho_dilep   ,f_weight);
        th.Get1DPlot("h1_pt_balance"          )->Fill(f_pt_balance         ,f_weight);
        th.Get1DPlot("h1_dphi_dilep"          )->Fill(f_dphi_dilep         ,f_weight);
        th.Get1DPlot("h1_cosdphi_dilep"       )->Fill(f_cosdphi_dilep      ,f_weight);
        th.Get1DPlot("h1_cosThetaStar"        )->Fill(fabs(f_cosThetaStar) ,f_weight);

    }

    th.OverFlowMerge( "h1_ZHLeptonic_MVA" );
    th.UnderFlowMerge( "h1_ZHLeptonic_MVA" );

    outfile->Write();
    th.Close();
    outfile->Close();



}
