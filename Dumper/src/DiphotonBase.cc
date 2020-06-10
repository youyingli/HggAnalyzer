#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include "HggAnalyzer/Dumper/interface/DiphotonBase.h"


using namespace std;

DiphotonBase::DiphotonBase(string filename, string tagname, string type)
{
    _file = TFile::Open(filename.c_str());
    _tree = (TTree*) _file->Get( Form("tagsDumper/trees/%s_13TeV_%s", type.c_str(), tagname.c_str()) );
    
    _isSignal = ( type.find("h_") != string::npos ) || ( type.find("vbf_") != string::npos );
    _isGJets = ( type.find("gjet_fakephoton") != string::npos );
    _isData  = ( type.find("Data") != string::npos );

    vector<string> dummy_filename;
    boost::split(dummy_filename, filename, boost::is_any_of("/"));
    _filename = dummy_filename[ dummy_filename.size() - 1 ];

    InitializationBase();
}

DiphotonBase::~DiphotonBase()
{
    _file->Close();
}

void
DiphotonBase::InitializationBase()
{

    _tree -> SetBranchAddress("dipho_mass",                &_dipho_mass                 );
    _tree -> SetBranchAddress("dipho_leadPt",              &_dipho_leadPt               );
    _tree -> SetBranchAddress("dipho_leadEta",             &_dipho_leadEta              );
    _tree -> SetBranchAddress("dipho_leadPhi",             &_dipho_leadPhi              );
    _tree -> SetBranchAddress("dipho_leadE",               &_dipho_leadE                );
    _tree -> SetBranchAddress("dipho_lead_ptoM",           &_dipho_lead_ptoM            );
    _tree -> SetBranchAddress("dipho_leadIDMVA",           &_dipho_leadIDMVA            );
    _tree -> SetBranchAddress("dipho_leadhasPixelSeed",    &_dipho_leadhasPixelSeed     );
    _tree -> SetBranchAddress("dipho_lead_prompt",         &_dipho_lead_prompt          );
    _tree -> SetBranchAddress("dipho_subleadPt",           &_dipho_subleadPt            );
    _tree -> SetBranchAddress("dipho_subleadEta",          &_dipho_subleadEta           );
    _tree -> SetBranchAddress("dipho_subleadPhi",          &_dipho_subleadPhi           );
    _tree -> SetBranchAddress("dipho_subleadE",            &_dipho_subleadE             );
    _tree -> SetBranchAddress("dipho_sublead_ptoM",        &_dipho_sublead_ptoM         );
    _tree -> SetBranchAddress("dipho_subleadIDMVA",        &_dipho_subleadIDMVA         );
    _tree -> SetBranchAddress("dipho_subleadhasPixelSeed", &_dipho_subleadhasPixelSeed  );
    _tree -> SetBranchAddress("dipho_sublead_prompt",      &_dipho_sublead_prompt       );
    _tree -> SetBranchAddress("weight",                    &_weight                     );
    _tree -> SetBranchAddress("nvtx",                      &_nvtx                       );
    _tree -> SetBranchAddress("rho",                       &_rho                        );
    if (_isSignal) _tree -> SetBranchAddress("centralObjectWeight",       &_centralObjectWeight        );


}

TLorentzVector
DiphotonBase::Photon1P4()
{
    TLorentzVector p1;
    p1.SetPtEtaPhiE(_dipho_leadPt, _dipho_leadEta, _dipho_leadPhi, _dipho_leadE);

    return p1;
}

TLorentzVector
DiphotonBase::Photon2P4()
{
    TLorentzVector p2;
    p2.SetPtEtaPhiE(_dipho_subleadPt, _dipho_subleadEta, _dipho_subleadPhi, _dipho_subleadE);

    return p2;
}

double
DiphotonBase::Weight()
{
    if (_isSignal) return _weight * _centralObjectWeight;
    else return _weight;
}
