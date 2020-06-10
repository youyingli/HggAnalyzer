#ifndef __DIPHOTONBASE__
#define __DIPHOTONBASE__

#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"

#include <string>

class DiphotonBase{

    public:

        DiphotonBase(std::string filename, std::string tagname, std::string type);
        ~DiphotonBase();

        TLorentzVector Photon1P4();
        TLorentzVector Photon2P4();

        float Photon1PSV() { return _dipho_leadhasPixelSeed == 0.; }
        float Photon2PSV() { return _dipho_subleadhasPixelSeed == 0.; }
        bool isPhoton1Prompt() { return _dipho_lead_prompt == 1.; }
        bool isPhoton2Prompt() { return _dipho_sublead_prompt == 1.; }
        bool isSignal() { return _isSignal; }
        bool isGJets() { return _isGJets; }
        bool isData() { return _isData; }
        double Weight();

    protected:


        TFile* _file;
        TTree* _tree;

        std::string _filename;

        float _dipho_mass               ; 
        float _dipho_lead_ptoM          ; 
        float _dipho_leadIDMVA          ; 
        float _dipho_sublead_ptoM       ; 
        float _dipho_subleadIDMVA       ; 
        int   _nvtx                     ;
        float _rho                      ;

    private:

        void InitializationBase();

        float _dipho_leadPt             ; 
        float _dipho_leadEta            ; 
        float _dipho_leadPhi            ; 
        float _dipho_leadE              ; 
        float _dipho_leadhasPixelSeed   ; 
        float _dipho_lead_prompt        ; 
        float _dipho_subleadPt          ; 
        float _dipho_subleadEta         ; 
        float _dipho_subleadPhi         ; 
        float _dipho_subleadE           ; 
        float _dipho_subleadhasPixelSeed; 
        float _dipho_sublead_prompt     ;
        float _weight                   ;
        float _centralObjectWeight      ;

        bool _isSignal                  ;
        bool _isGJets                   ;
        bool _isData                    ;

};

#endif
