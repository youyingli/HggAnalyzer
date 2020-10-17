
#include "HggAnalyzer/Dumper/interface/VHMetDumper.h"
#include "HggAnalyzer/Dumper/interface/THistService.h"

#include "TF1.h"
#include "TMVA/Reader.h"

#include <cstdlib>
#include <iostream>

using namespace std;

VHMetDumper::VHMetDumper(string filename, string type, string pufilename): DiphotonBase(filename, "VHMetTag", type, pufilename) 
{
    Initialization();
}

void
VHMetDumper::Initialization()
{
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
    //_tree -> SetBranchAddress("maxJetDeepCSV",             &_maxJetDeepCSV              );
    _tree -> SetBranchAddress("met_Pt",                    &_met_Pt                     );
    _tree -> SetBranchAddress("met_Phi",                   &_met_Phi                    );
    _tree -> SetBranchAddress("met_sumEt",                 &_met_sumEt                  );
    _tree -> SetBranchAddress("met_Sig",                   &_met_Sig                    );
    _tree -> SetBranchAddress("met_RealSig",               &_met_RealSig                );
    //_tree -> SetBranchAddress("minDeltaPhiJetMet",         &_minDeltaPhiJetMet          );
    if (isSignal()) {
        _tree -> SetBranchAddress("VhasNeu",               &_VhasNeu                    );
        _tree -> SetBranchAddress("VhasLep",               &_VhasLep                    );
        _tree -> SetBranchAddress("VhasHad",               &_VhasHad                    );
    }
//    _intree -> SetBranchAddress("", );

}

void
VHMetDumper::SetGlobalScale(double scale)
{
    _scale = scale;
}

vector<pair<TLorentzVector, float>>
VHMetDumper::SetJetsInfo()
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
    outTree->Branch("max_jet_pt"           , &f_max_jet_pt            ,  "max_jet_pt/F"           );
    outTree->Branch("max_jet_dCSV"         , &f_max_jet_dCSV          ,  "max_jet_dCSV/F"         );
    outTree->Branch("met"                  , &f_met                   ,  "met/F"                  );
    outTree->Branch("met_sumEt"            , &f_met_sumEt             ,  "met_sumEt/F"            );
    outTree->Branch("met_Sig"              , &f_met_Sig               ,  "met_Sig/F"              );
    outTree->Branch("met_significance"     , &f_met_significance      ,  "met_significance/F"     );
    outTree->Branch("min_dphi_jet_met"     , &f_min_dphi_jet_met      ,  "min_dphi_jet_met/F"     );
    outTree->Branch("dphi_dipho_met"       , &f_dphi_dipho_met        ,  "dphi_dipho_met/F"       );
    outTree->Branch("pt_balance"           , &f_pt_balance            ,  "pt_balance/F"           );
    outTree->Branch("category"             , &f_category              ,  "category/F"             );

    TMVA::Reader tmvareader( "!Color:!Silent" );
    tmvareader.AddVariable( "pho1_eta"         , & f_pho1_eta            );
    tmvareader.AddVariable( "pho2_eta"         , & f_pho2_eta            );
    tmvareader.AddVariable( "pho1_ptoM"        , & f_pho1_ptoM           );
    tmvareader.AddVariable( "pho2_ptoM"        , & f_pho2_ptoM           );
    tmvareader.AddVariable( "min_phoId"        , & f_min_phoId           );
    tmvareader.AddVariable( "max_phoId"        , & f_max_phoId           );
    tmvareader.AddVariable( "dipho_cosphi"     , & f_dipho_cosphi        );
    tmvareader.AddVariable( "met"              , & f_met                 );
    tmvareader.AddVariable( "met_sumEt"        , & f_met_sumEt           );
    tmvareader.AddVariable( "dphi_dipho_met"   , & f_dphi_dipho_met      );
    tmvareader.AddVariable( "pt_balance"       , & f_pt_balance          );
    tmvareader.AddVariable( "njet"             , & f_njet                );
    tmvareader.AddVariable( "max_jet_pt"       , & f_max_jet_pt          );
    tmvareader.AddVariable( "max_jet_dCSV"     , & f_max_jet_dCSV        );
    tmvareader.AddVariable( "min_dphi_jet_met" , & f_min_dphi_jet_met    );
   
    tmvareader.BookMVA( "BDT", TString( getenv("CMSSW_BASE") ) + "/src/HggAnalyzer/Dumper/data/TMVA_VHMetTag_BDT_ULv1.weights.xml" );

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
    th.AddNewTH1("h1_max_jet_pt"              ,30  ,0.   ,300.   );
    th.AddNewTH1("h1_max_jet_dCSV"            ,40  ,0.   ,1.     );
    th.AddNewTH1("h1_met"                     ,40  ,0.   ,300.   );
    th.AddNewTH1("h1_met_sumEt"               ,50  ,0.   ,5000.  );
    th.AddNewTH1("h1_met_Sig"                 ,40  ,0.   ,10.    );
    th.AddNewTH1("h1_met_significance"        ,40  ,0.   ,15.    );
    th.AddNewTH1("h1_dphi_dipho_met"          ,36  ,2.   ,3.2    );
    th.AddNewTH1("h1_min_dphi_jet_met"        ,32  ,0.   ,3.2    );
    th.AddNewTH1("h1_pt_balance"              ,50  ,-9.  ,1.     );
    th.AddNewTH1("h1_VHMet_MVA"               ,50  ,-1   ,1.     );
    th.AddNewTH1("h1_nvtx"                    ,60  ,0.   ,60.    );
    th.AddNewTH1("h1_rho"                     ,60  ,0.   ,60.    );
    th.AddNewTH1("h1_category"                ,2   ,0.   ,2.     );


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
    //f_IDMVA.SetParameter( 0, 0.0107376  );
    //f_IDMVA.SetParameter( 1, -0.00894819);
    //f_IDMVA.SetParameter( 2, 0.022018   );
    //f_IDMVA.SetParameter( 3, -0.0414607 );
    //f_IDMVA.SetParameter( 4, -0.0393888 );
    //f_IDMVA.SetParameter( 5, 0.110712   );
    //f_IDMVA.SetParameter( 6, 0.0855843  );
    //f_IDMVA.SetParameter( 7, -0.134681  );

    f_IDMVA.SetParameter( 0, 0.0105043  );
    f_IDMVA.SetParameter( 1, -0.00937503);
    f_IDMVA.SetParameter( 2, 0.0223701  );
    f_IDMVA.SetParameter( 3, -0.0388629 );
    f_IDMVA.SetParameter( 4, -0.0391449 );
    f_IDMVA.SetParameter( 5, 0.101591   );
    f_IDMVA.SetParameter( 6, 0.0873913  );
    f_IDMVA.SetParameter( 7, -0.130212  );

    //Correlation check
    th.AddNewTH2("h2_fphotonID_pho1_pt"          , 40, -1, 1, 42, 20   ,300. );
    th.AddNewTH2("h2_fphotonID_pho2_pt"          , 40, -1, 1, 36, 20   ,200. );
    th.AddNewTH2("h2_fphotonID_pho1_eta"         , 40, -1, 1, 30, -3.  ,3.   );
    th.AddNewTH2("h2_fphotonID_pho2_eta"         , 40, -1, 1, 30, -3.  ,3.   );
    th.AddNewTH2("h2_fphotonID_pho1_ptoM"        , 40, -1, 1, 25, 0.   ,2.0  );
    th.AddNewTH2("h2_fphotonID_pho2_ptoM"        , 40, -1, 1, 28, 0.   ,0.7  );
    th.AddNewTH2("h2_fphotonID_dipho_cosphi"     , 40, -1, 1, 40, -1.  ,1.   );
    th.AddNewTH2("h2_fphotonID_njet"             , 40, -1, 1, 10, 0.   ,10.  );
    th.AddNewTH2("h2_fphotonID_max_jet_pt"       , 40, -1, 1, 30, 0.   ,300. );
    th.AddNewTH2("h2_fphotonID_max_jet_dCSV"     , 40, -1, 1, 40, 0.   ,1.   );
    th.AddNewTH2("h2_fphotonID_met"              , 40, -1, 1, 40, 0.   ,200. );
    th.AddNewTH2("h2_fphotonID_met_sumEt"        , 40, -1, 1, 40, 0.   ,4000.);
    th.AddNewTH2("h2_fphotonID_met_significance" , 40, -1, 1, 40, 0.   ,15.  );
    th.AddNewTH2("h2_fphotonID_min_dphi_jet_met" , 40, -1, 1, 32, 0.   ,3.2  );
    th.AddNewTH2("h2_fphotonID_dphi_dipho_met"   , 40, -1, 1, 36, 2.   ,3.2  );
    th.AddNewTH2("h2_fphotonID_pt_balance"       , 40, -1, 1, 36, -11. ,1    );

    th.AddNewTH2("h2_pphotonID_pho1_pt"          , 40, -1, 1, 42, 20   ,300. );
    th.AddNewTH2("h2_pphotonID_pho2_pt"          , 40, -1, 1, 36, 20   ,200. );
    th.AddNewTH2("h2_pphotonID_pho1_eta"         , 40, -1, 1, 30, -3.  ,3.   );
    th.AddNewTH2("h2_pphotonID_pho2_eta"         , 40, -1, 1, 30, -3.  ,3.   );
    th.AddNewTH2("h2_pphotonID_pho1_ptoM"        , 40, -1, 1, 25, 0.   ,2.0  );
    th.AddNewTH2("h2_pphotonID_pho2_ptoM"        , 40, -1, 1, 25, 0.   ,0.7  );
    th.AddNewTH2("h2_pphotonID_dipho_cosphi"     , 40, -1, 1, 40, -1.  ,1.   );
    th.AddNewTH2("h2_pphotonID_njet"             , 40, -1, 1, 10, 0.   ,10.  );
    th.AddNewTH2("h2_pphotonID_max_jet_pt"       , 40, -1, 1, 30, 0.   ,300. );
    th.AddNewTH2("h2_pphotonID_max_jet_dCSV"     , 40, -1, 1, 40, 0.   ,1.   );
    th.AddNewTH2("h2_pphotonID_met"              , 40, -1, 1, 40, 0.   ,200. );
    th.AddNewTH2("h2_pphotonID_met_sumEt"        , 40, -1, 1, 40, 0.   ,4000.);
    th.AddNewTH2("h2_pphotonID_met_significance" , 40, -1, 1, 40, 0.   ,15.  );
    th.AddNewTH2("h2_pphotonID_min_dphi_jet_met" , 40, -1, 1, 32, 0.   ,3.2  );
    th.AddNewTH2("h2_pphotonID_dphi_dipho_met"   , 40, -1, 1, 36, 2.   ,3.2  );
    th.AddNewTH2("h2_pphotonID_pt_balance"       , 40, -1, 1, 36, -11. ,1    );


    for (int i = 0; i < _tree->GetEntries(); i ++) {
        _tree->GetEntry(i);

        TLorentzVector pho1P4 = Photon1P4();
        TLorentzVector pho2P4 = Photon2P4();
        TLorentzVector diphoP4 = pho1P4 + pho2P4;

        if (vhtype != "") {
            if (vhtype == "zh_dilep" or vhtype == "wh_lep") {
                if (_VhasLep != 1) continue;
            } else if (vhtype == "zh_met") {
                if (_VhasNeu != 1) continue;
            } else if (vhtype == "zh_had" || vhtype == "wh_had") {
                if (_VhasHad != 1) continue;
            }
        }

        int Njets = 0;
        float max_jet_pt   = -1.;
        float max_jet_dCSV = -2;
        float min_dphi_jet_met = 4;

        TVector2 metP2; metP2.SetMagPhi(_met_Pt, _met_Phi); 
        auto jets = SetJetsInfo();

        for (unsigned int i = 0; i < jets.size(); i++) {
            Njets++;

            TVector2 jet_P2 = jets[i].first.Vect().XYvector();

            double dphi_jet_met = fabs( jet_P2.DeltaPhi(metP2) );

            if ( max_jet_pt < jets[i].first.Pt() ) max_jet_pt = jets[i].first.Pt();
            if ( max_jet_dCSV < jets[i].second ) max_jet_dCSV = jets[i].second;
            if ( dphi_jet_met < min_dphi_jet_met ) min_dphi_jet_met = dphi_jet_met;
        }

        f_mass             = _dipho_mass                                              ; 
        f_weight           = Weight() * _scale                                        ; 
        f_pho1_eta         = pho1P4.Eta()                                             ; 
        f_pho2_eta         = pho2P4.Eta()                                             ; 
        f_pho1_ptoM        = _dipho_lead_ptoM                                         ; 
        f_pho2_ptoM        = _dipho_sublead_ptoM                                      ; 
        f_pho1_idmva       = _dipho_leadIDMVA                                         ; 
        f_pho2_idmva       = _dipho_subleadIDMVA                                      ; 
        f_min_phoId        = min(f_pho1_idmva, f_pho2_idmva)                          ; 
        f_max_phoId        = max(f_pho1_idmva, f_pho2_idmva)                          ; 
        f_dipho_pt         = diphoP4.Pt()                                             ; 
        f_dipho_deltaphi   = pho1P4.DeltaPhi(pho2P4)                                  ; 
        f_dipho_cosphi     = cos(f_dipho_deltaphi)                                    ; 
        f_njet             = Njets                                                    ; 
        f_max_jet_pt       = max_jet_pt                                               ;
        //f_max_jet_dCSV     = _maxJetDeepCSV                                           ;
        f_max_jet_dCSV     = max_jet_dCSV                                             ;
        f_met              = _met_Pt                                                  ;
        f_met_sumEt        = _met_sumEt                                               ;
        f_met_Sig          = _met_Sig                                                 ;
        f_met_significance = _met_RealSig                                             ;
        //f_min_dphi_jet_met = _minDeltaPhiJetMet                                       ;
        f_min_dphi_jet_met = min_dphi_jet_met                                         ;
        f_dphi_dipho_met   = fabs( TVector2::Phi_mpi_pi(diphoP4.Phi() - _met_Phi) )   ;
        f_pt_balance       = (diphoP4.Pt() - _met_Pt)/diphoP4.Pt()                    ;
        f_category         = f_njet == 0. ? 0. : 1.;

        if (f_dphi_dipho_met < 2.) continue;

        // ---------------- Data driven start -------------------------------------------
        
        //Check the QCD/Photon + Jets occupancy rate in sideband
        if (f_max_phoId > -0.7 && f_min_phoId < -0.7)
            th.Get1DPlot("h1_max_phoID_check")->Fill(f_max_phoId, f_weight);


        if (isGJets()) {

            if (!isPhoton2Prompt()) {

                //Fake photon ID distribution for fitting
                th.Get1DPlot("h1_phoId_mva_fake")->Fill( f_pho2_idmva, f_weight );

                //Check the correlation between other variables
                th.Get2DPlot("h2_fphotonID_pho1_pt"          )->Fill( f_pho2_idmva, pho1P4.Pt()          );
                th.Get2DPlot("h2_fphotonID_pho2_pt"          )->Fill( f_pho2_idmva, pho2P4.Pt()          );
                th.Get2DPlot("h2_fphotonID_pho1_eta"         )->Fill( f_pho2_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_fphotonID_pho2_eta"         )->Fill( f_pho2_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_fphotonID_pho1_ptoM"        )->Fill( f_pho2_idmva, f_pho1_ptoM          );
                th.Get2DPlot("h2_fphotonID_pho2_ptoM"        )->Fill( f_pho2_idmva, f_pho2_ptoM          );
                th.Get2DPlot("h2_fphotonID_dipho_cosphi"     )->Fill( f_pho2_idmva, f_dipho_cosphi       );
                th.Get2DPlot("h2_fphotonID_njet"             )->Fill( f_pho2_idmva, f_njet               );
                th.Get2DPlot("h2_fphotonID_max_jet_pt"       )->Fill( f_pho2_idmva, f_max_jet_pt         );
                th.Get2DPlot("h2_fphotonID_max_jet_dCSV"     )->Fill( f_pho2_idmva, f_max_jet_dCSV       );
                th.Get2DPlot("h2_fphotonID_met"              )->Fill( f_pho2_idmva, f_met                );
                th.Get2DPlot("h2_fphotonID_met_sumEt"        )->Fill( f_pho2_idmva, f_met_sumEt          );
                th.Get2DPlot("h2_fphotonID_met_significance" )->Fill( f_pho2_idmva, f_met_significance   );
                th.Get2DPlot("h2_fphotonID_min_dphi_jet_met" )->Fill( f_pho2_idmva, f_min_dphi_jet_met   );
                th.Get2DPlot("h2_fphotonID_dphi_dipho_met"   )->Fill( f_pho2_idmva, f_dphi_dipho_met     );
                th.Get2DPlot("h2_fphotonID_pt_balance"       )->Fill( f_pho2_idmva, f_pt_balance         );

                //Especially check the correlation between pt and eta
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

                th.Get1DPlot("h1_phoId_mva_fake")->Fill( f_pho1_idmva, f_weight );

                th.Get2DPlot("h2_fphotonID_pho1_pt"          )->Fill( f_pho1_idmva, pho1P4.Pt()          );
                th.Get2DPlot("h2_fphotonID_pho2_pt"          )->Fill( f_pho1_idmva, pho2P4.Pt()          );
                th.Get2DPlot("h2_fphotonID_pho1_eta"         )->Fill( f_pho1_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_fphotonID_pho2_eta"         )->Fill( f_pho1_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_fphotonID_pho1_ptoM"        )->Fill( f_pho1_idmva, f_pho1_ptoM          );
                th.Get2DPlot("h2_fphotonID_pho2_ptoM"        )->Fill( f_pho1_idmva, f_pho2_ptoM          );
                th.Get2DPlot("h2_fphotonID_dipho_cosphi"     )->Fill( f_pho1_idmva, f_dipho_cosphi       );
                th.Get2DPlot("h2_fphotonID_njet"             )->Fill( f_pho1_idmva, f_njet               );
                th.Get2DPlot("h2_fphotonID_max_jet_pt"       )->Fill( f_pho1_idmva, f_max_jet_pt         );
                th.Get2DPlot("h2_fphotonID_max_jet_dCSV"     )->Fill( f_pho1_idmva, f_max_jet_dCSV       );
                th.Get2DPlot("h2_fphotonID_met"              )->Fill( f_pho1_idmva, f_met                );
                th.Get2DPlot("h2_fphotonID_met_sumEt"        )->Fill( f_pho1_idmva, f_met_sumEt          );
                th.Get2DPlot("h2_fphotonID_met_significance" )->Fill( f_pho1_idmva, f_met_significance   );
                th.Get2DPlot("h2_fphotonID_min_dphi_jet_met" )->Fill( f_pho1_idmva, f_min_dphi_jet_met   );
                th.Get2DPlot("h2_fphotonID_dphi_dipho_met"   )->Fill( f_pho1_idmva, f_dphi_dipho_met     );
                th.Get2DPlot("h2_fphotonID_pt_balance"       )->Fill( f_pho1_idmva, f_pt_balance         );

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

                th.Get1DPlot("h1_phoId_mva_prompt")->Fill( f_pho1_idmva, f_weight );

                th.Get2DPlot("h2_pphotonID_pho1_pt"          )->Fill( f_pho1_idmva, pho1P4.Pt()          );
                th.Get2DPlot("h2_pphotonID_pho2_pt"          )->Fill( f_pho1_idmva, pho2P4.Pt()          );
                th.Get2DPlot("h2_pphotonID_pho1_eta"         )->Fill( f_pho1_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_pphotonID_pho2_eta"         )->Fill( f_pho1_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_pphotonID_pho1_ptoM"        )->Fill( f_pho1_idmva, f_pho1_ptoM          );
                th.Get2DPlot("h2_pphotonID_pho2_ptoM"        )->Fill( f_pho1_idmva, f_pho2_ptoM          );
                th.Get2DPlot("h2_pphotonID_dipho_cosphi"     )->Fill( f_pho1_idmva, f_dipho_cosphi       );
                th.Get2DPlot("h2_pphotonID_njet"             )->Fill( f_pho1_idmva, f_njet               );
                th.Get2DPlot("h2_pphotonID_max_jet_pt"       )->Fill( f_pho1_idmva, f_max_jet_pt         );
                th.Get2DPlot("h2_pphotonID_max_jet_dCSV"     )->Fill( f_pho1_idmva, f_max_jet_dCSV       );
                th.Get2DPlot("h2_pphotonID_met"              )->Fill( f_pho1_idmva, f_met                );
                th.Get2DPlot("h2_pphotonID_met_sumEt"        )->Fill( f_pho1_idmva, f_met_sumEt          );
                th.Get2DPlot("h2_pphotonID_met_significance" )->Fill( f_pho1_idmva, f_met_significance   );
                th.Get2DPlot("h2_pphotonID_min_dphi_jet_met" )->Fill( f_pho1_idmva, f_min_dphi_jet_met   );
                th.Get2DPlot("h2_pphotonID_dphi_dipho_met"   )->Fill( f_pho1_idmva, f_dphi_dipho_met     );
                th.Get2DPlot("h2_pphotonID_pt_balance"       )->Fill( f_pho1_idmva, f_pt_balance         );

            } else if (isPhoton2Prompt()) {

                th.Get1DPlot("h1_phoId_mva_prompt")->Fill( f_pho2_idmva, f_weight );

                th.Get2DPlot("h2_pphotonID_pho1_pt"          )->Fill( f_pho2_idmva, pho1P4.Pt()          );
                th.Get2DPlot("h2_pphotonID_pho2_pt"          )->Fill( f_pho2_idmva, pho2P4.Pt()          );
                th.Get2DPlot("h2_pphotonID_pho1_eta"         )->Fill( f_pho2_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_pphotonID_pho2_eta"         )->Fill( f_pho2_idmva, f_pho1_eta           );
                th.Get2DPlot("h2_pphotonID_pho1_ptoM"        )->Fill( f_pho2_idmva, f_pho1_ptoM          );
                th.Get2DPlot("h2_pphotonID_pho2_ptoM"        )->Fill( f_pho2_idmva, f_pho2_ptoM          );
                th.Get2DPlot("h2_pphotonID_dipho_cosphi"     )->Fill( f_pho2_idmva, f_dipho_cosphi       );
                th.Get2DPlot("h2_pphotonID_njet"             )->Fill( f_pho2_idmva, f_njet               );
                th.Get2DPlot("h2_pphotonID_max_jet_pt"       )->Fill( f_pho2_idmva, f_max_jet_pt         );
                th.Get2DPlot("h2_pphotonID_max_jet_dCSV"     )->Fill( f_pho2_idmva, f_max_jet_dCSV       );
                th.Get2DPlot("h2_pphotonID_met"              )->Fill( f_pho2_idmva, f_met                );
                th.Get2DPlot("h2_pphotonID_met_sumEt"        )->Fill( f_pho2_idmva, f_met_sumEt          );
                th.Get2DPlot("h2_pphotonID_met_significance" )->Fill( f_pho2_idmva, f_met_significance   );
                th.Get2DPlot("h2_pphotonID_min_dphi_jet_met" )->Fill( f_pho2_idmva, f_min_dphi_jet_met   );
                th.Get2DPlot("h2_pphotonID_dphi_dipho_met"   )->Fill( f_pho2_idmva, f_dphi_dipho_met     );
                th.Get2DPlot("h2_pphotonID_pt_balance"       )->Fill( f_pho2_idmva, f_pt_balance         );

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


        if (f_pho1_ptoM < (1. / 3) || f_pho2_ptoM < 0.2) continue;
        if (f_met < 50.) continue;

        f_mva = tmvareader.EvaluateMVA( "BDT" );
        //f_mva = 1. / ( 1. + exp( 0.5*log( 2./(f_mva+1.) - 1 ) ) );
        
        outTree->Fill();
        
        if( !isSignal() )
            if(f_mass > 120. && f_mass < 130.)
              continue;

        th.Get1DPlot("h1_Mgg"                )->Fill(f_mass                 ,f_weight);
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
        th.Get1DPlot("h1_max_jet_pt"         )->Fill(f_max_jet_pt           ,f_weight);
        th.Get1DPlot("h1_max_jet_dCSV"       )->Fill(f_max_jet_dCSV         ,f_weight);
        th.Get1DPlot("h1_met"                )->Fill(f_met                  ,f_weight);
        th.Get1DPlot("h1_met_sumEt"          )->Fill(f_met_sumEt            ,f_weight);
        th.Get1DPlot("h1_met_Sig"            )->Fill(f_met_Sig              ,f_weight);
        th.Get1DPlot("h1_met_significance"   )->Fill(f_met_significance     ,f_weight);
        th.Get1DPlot("h1_min_dphi_jet_met"   )->Fill(f_min_dphi_jet_met     ,f_weight);
        th.Get1DPlot("h1_dphi_dipho_met"     )->Fill(f_dphi_dipho_met       ,f_weight);
        th.Get1DPlot("h1_pt_balance"         )->Fill(f_pt_balance           ,f_weight);
        th.Get1DPlot("h1_VHMet_MVA"          )->Fill(f_mva                  ,f_weight);
        th.Get1DPlot("h1_nvtx"               )->Fill(_nvtx                  ,f_weight);
        th.Get1DPlot("h1_rho"                )->Fill(_rho                   ,f_weight);
        th.Get1DPlot("h1_category"           )->Fill(f_category             ,f_weight);

    }

    outfile->Write();
    th.Close();
    outfile->Close();

}
