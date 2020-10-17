#include "HggAnalyzer/Dumper/interface/THistService.h"

#include <iostream>
#include <cstdlib>

using namespace std;

namespace Dumper{

    THistService::THistService()
    {
        _isDelete = false;
    }
    
    THistService::~THistService()
    {
        if (!_isDelete) Close();
    }
    
    void
    THistService::AddNewTH1( std::string name, int nbin, double min, double max )
    {
    
        if (_th1set.find(name) != _th1set.end()){
            std::cout << name << " TH1 plot already exists in THService !" << std::endl;
            exit(EXIT_FAILURE);
        }
    
        auto h1 = new TH1D(name.c_str(), "", nbin, min, max);
        h1->Sumw2();
        _th1set.emplace(name, h1);
        _isDelete = false;
    }
    
    void
    THistService::AddNewTH2(std::string name, int nbinx, double xmin, double xmax, int nbiny, double ymin, double ymax)
    {
    
        if (_th2set.find(name) != _th2set.end()){
            std::cout << name << " TH2 plot already exists in THService !" << std::endl;
            exit(EXIT_FAILURE);
        }
    
        auto h2 = new TH2D(name.c_str(), "", nbinx, xmin, xmax, nbiny, ymin, ymax);
        h2->Sumw2();
        _th2set.emplace(name, h2);
        _isDelete = false;
    }
    
    TH1*
    THistService::Get1DPlot(std::string name)
    {
        if (!_th1set[name]) {
            std::cout << name << " is empty !" << std::endl;
            exit(EXIT_FAILURE);
        }
    
        return _th1set[name];
    }
    
    TH2*
    THistService::Get2DPlot(std::string name)
    {
        if (!_th2set[name]) {
            std::cout << name << " is empty !" << std::endl;
            exit(EXIT_FAILURE);
        }
    
        return _th2set[name];
    }

    void
    THistService::OverFlowMerge(std::string name)
    {
        int finalbin = _th1set[name]->GetNbinsX();
        _th1set[name]->SetBinContent( finalbin, _th1set[name]->GetBinContent( finalbin ) + _th1set[name]->GetBinContent( finalbin+1 ) );
    }

    void
    THistService::UnderFlowMerge(std::string name)
    {
        _th1set[name]->SetBinContent( 1, _th1set[name]->GetBinContent( 0 ) + _th1set[name]->GetBinContent( 1 ) );
    }
    
    void
    THistService::Close()
    {
        for ( const auto& it : _th1set ) delete it.second; 
        for ( const auto& it : _th2set ) delete it.second; 
        _isDelete = true;
    }
}
