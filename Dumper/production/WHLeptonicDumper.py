#!/usr/bin/env python

from HggAnalyzer.Dumper.parallel_process import parallel_process
from HggAnalyzer.Dumper.vh_dumper import whleptonic_proc_func

indir  = "/wk_cms2/youying/public/vh_ntuples/whleptonic"
outdir = "/wk_cms2/youying/VHAnalysis/vhmet_an/CMSSW_10_2_20/src/pre_UL_test_v2"

is2016 = True
is2017 = True
is2018 = True

argu_list = []


if is2016:

    argu_list.append([indir + "/2016/output_DoubleEG.root"                                                                 , "Data"           , 1.0,   outdir + "/2016", ""])

    argu_list.append([indir + "/2016/output_GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8.root"                              , "ggh_125"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root"                                   , "ggh_125"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_VBFHToGG_M125_13TeV_amcatnlo_pythia8.root"                                     , "vbf_125"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_VBFHToGG_M-125_13TeV_powheg_pythia8.root"                                      , "vbf_125"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_ttHJetToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                       , "tth_125"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_ttHToGG_M125_13TeV_powheg_pythia8.root"                                        , "tth_125"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_WminusH_HToGG_WToAll_M120_13TeV_powheg_pythia8.root"                           , "wh_120"         , 35.92, outdir + "/2016", "wh_lep"])
    argu_list.append([indir + "/2016/output_WplusH_HToGG_WToAll_M120_13TeV_powheg_pythia8.root"                            , "wh_120"         , 35.92, outdir + "/2016", "wh_lep"])
    argu_list.append([indir + "/2016/output_WHToGG_M123_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_123"         , 35.92, outdir + "/2016", "wh_lep"])
    argu_list.append([indir + "/2016/output_WminusH_HToGG_WToAll_M125_13TeV_powheg_pythia8.root"                           , "wh_125"         , 35.92, outdir + "/2016", "wh_lep"])
    argu_list.append([indir + "/2016/output_WplusH_HToGG_WToAll_M125_13TeV_powheg_pythia8.root"                            , "wh_125"         , 35.92, outdir + "/2016", "wh_lep"])
    argu_list.append([indir + "/2016/output_WHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_125"         , 35.92, outdir + "/2016", "wh_lep"])
    argu_list.append([indir + "/2016/output_WHToGG_M126_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_126"         , 35.92, outdir + "/2016", "wh_lep"])
    argu_list.append([indir + "/2016/output_WHToGG_M127_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_127"         , 35.92, outdir + "/2016", "wh_lep"])
    argu_list.append([indir + "/2016/output_WminusH_HToGG_WToAll_M130_13TeV_powheg_pythia8.root"                           , "wh_130"         , 35.92, outdir + "/2016", "wh_lep"])
    argu_list.append([indir + "/2016/output_WplusH_HToGG_WToAll_M130_13TeV_powheg_pythia8.root"                            , "wh_130"         , 35.92, outdir + "/2016", "wh_lep"])
    argu_list.append([indir + "/2016/output_WminusH_HToGG_WToAll_M120_13TeV_powheg_pythia8.root"                           , "wh_120"         , 35.92, outdir + "/2016", "wh_had"])
    argu_list.append([indir + "/2016/output_WplusH_HToGG_WToAll_M120_13TeV_powheg_pythia8.root"                            , "wh_120"         , 35.92, outdir + "/2016", "wh_had"])
    argu_list.append([indir + "/2016/output_WHToGG_M123_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_123"         , 35.92, outdir + "/2016", "wh_had"])
    argu_list.append([indir + "/2016/output_WminusH_HToGG_WToAll_M125_13TeV_powheg_pythia8.root"                           , "wh_125"         , 35.92, outdir + "/2016", "wh_had"])
    argu_list.append([indir + "/2016/output_WplusH_HToGG_WToAll_M125_13TeV_powheg_pythia8.root"                            , "wh_125"         , 35.92, outdir + "/2016", "wh_had"])
    argu_list.append([indir + "/2016/output_WHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_125"         , 35.92, outdir + "/2016", "wh_had"])
    argu_list.append([indir + "/2016/output_WHToGG_M126_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_126"         , 35.92, outdir + "/2016", "wh_had"])
    argu_list.append([indir + "/2016/output_WHToGG_M127_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_127"         , 35.92, outdir + "/2016", "wh_had"])
    argu_list.append([indir + "/2016/output_WminusH_HToGG_WToAll_M130_13TeV_powheg_pythia8.root"                           , "wh_130"         , 35.92, outdir + "/2016", "wh_had"])
    argu_list.append([indir + "/2016/output_WplusH_HToGG_WToAll_M130_13TeV_powheg_pythia8.root"                            , "wh_130"         , 35.92, outdir + "/2016", "wh_had"])
    argu_list.append([indir + "/2016/output_ZH_HToGG_ZToAll_M125_13TeV_powheg_pythia8.root"                                , "zh_125"         , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_ZHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "zh_125"         , 35.92, outdir + "/2016", ""])

    argu_list.append([indir + "/2016/output_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root"                  , "DYjets"         , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root"                                 , "diphoton"       , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root"   , "gjet_fakephoton", 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_GJet_Pt-20toInf_DoubleEMEnriched_MGG-40to80_TuneCUETP8M1_13TeV_Pythia8.root"   , "gjet_fakephoton", 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root"  , "gjet_fakephoton", 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_QCD_Pt-30to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root"    , "qcd_fakephoton" , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_QCD_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8.root"   , "qcd_fakephoton" , 35.92, outdir + "/2016", ""])

    argu_list.append([indir + "/2016/output_TTGG_0Jets_TuneCUETP8M1_13TeV_amcatnlo_madspin_pythia8.root"                   , "Top_bkg"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8.root"                  , "Top_bkg"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8.root"                         , "Top_bkg"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_TGJets_TuneCUETP8M1_13TeV_amcatnlo_madspin_pythia8.root"                       , "Top_bkg"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1.root"       , "Top_bkg"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M2T4.root"         , "Top_bkg"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8.root"             , "Top_bkg"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root"                     , "Top_bkg"        , 35.92, outdir + "/2016", ""])

    argu_list.append([indir + "/2016/output_WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root"                         , "diboson"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root"                          , "diboson"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_WW_TuneCUETP8M1_13TeV-pythia8.root"                                            , "diboson"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_WZ_TuneCUETP8M1_13TeV-pythia8.root"                                            , "diboson"        , 35.92, outdir + "/2016", ""])
    argu_list.append([indir + "/2016/output_ZZ_TuneCUETP8M1_13TeV-pythia8.root"                                            , "diboson"        , 35.92, outdir + "/2016", ""])


if is2017:

    argu_list.append([indir + "/2017/output_DoubleEG.root"                                                                 , "Data"           ,   1.0, outdir + "/2017", ""])

    argu_list.append([indir + "/2017/output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root"                                   , "ggh_125"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8.root"                              , "ggh_125"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_VBFHToGG_M125_13TeV_amcatnlo_pythia8.root"                                     , "vbf_125"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_VBFHToGG_M-125_13TeV_powheg_pythia8.root"                                      , "vbf_125"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_ttHJetToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                       , "tth_125"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_ttHJetToGG_M126_13TeV_amcatnloFXFX_madspin_pythia8.root"                       , "tth_126"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_WplusH_HToGG_WToAll_M120_13TeV_powheg_pythia8.root"                            , "wh_120"         , 41.53, outdir + "/2017", "wh_lep"])
    argu_list.append([indir + "/2017/output_WHToGG_M123_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_123"         , 41.53, outdir + "/2017", "wh_lep"])
    argu_list.append([indir + "/2017/output_WHToGG_M124_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_124"         , 41.53, outdir + "/2017", "wh_lep"])
    argu_list.append([indir + "/2017/output_WHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_125"         , 41.53, outdir + "/2017", "wh_lep"])
    argu_list.append([indir + "/2017/output_WminusH_HToGG_WToAll_M125_13TeV_powheg_pythia8.root"                           , "wh_125"         , 41.53, outdir + "/2017", "wh_lep"])
    argu_list.append([indir + "/2017/output_WHToGG_M127_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_127"         , 41.53, outdir + "/2017", "wh_lep"])
    argu_list.append([indir + "/2017/output_WminusH_HToGG_WToAll_M130_13TeV_powheg_pythia8.root"                           , "wh_130"         , 41.53, outdir + "/2017", "wh_lep"])
    argu_list.append([indir + "/2017/output_WplusH_HToGG_WToAll_M120_13TeV_powheg_pythia8.root"                            , "wh_120"         , 41.53, outdir + "/2017", "wh_had"])
    argu_list.append([indir + "/2017/output_WHToGG_M123_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_123"         , 41.53, outdir + "/2017", "wh_had"])
    argu_list.append([indir + "/2017/output_WHToGG_M124_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_124"         , 41.53, outdir + "/2017", "wh_had"])
    argu_list.append([indir + "/2017/output_WHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_125"         , 41.53, outdir + "/2017", "wh_had"])
    argu_list.append([indir + "/2017/output_WminusH_HToGG_WToAll_M125_13TeV_powheg_pythia8.root"                           , "wh_125"         , 41.53, outdir + "/2017", "wh_had"])
    argu_list.append([indir + "/2017/output_WHToGG_M127_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_127"         , 41.53, outdir + "/2017", "wh_had"])
    argu_list.append([indir + "/2017/output_WminusH_HToGG_WToAll_M130_13TeV_powheg_pythia8.root"                           , "wh_130"         , 41.53, outdir + "/2017", "wh_had"])
    argu_list.append([indir + "/2017/output_ZHToGG_M124_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "zh_124"         , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_ZHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "zh_125"         , 41.53, outdir + "/2017", ""])

    argu_list.append([indir + "/2017/output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root"                                 , "diphoton"       , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8.root"                       , "DYjets"         , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_GJet_Pt-20toInf_DoubleEMEnriched_MGG-40to80_TuneCP5_13TeV_Pythia8.root"        , "gjet_fakephoton", 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root"        , "gjet_fakephoton", 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root"       , "gjet_fakephoton", 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_QCD_Pt-30toInf_DoubleEMEnriched_MGG-40to80_TuneCP5_13TeV_Pythia8.root"         , "qcd_fakephoton" , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_QCD_Pt-30to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root"         , "qcd_fakephoton" , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_QCD_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root"        , "qcd_fakephoton" , 41.53, outdir + "/2017", ""])

    argu_list.append([indir + "/2017/output_TTGG_0Jets_TuneCP5_13TeV_amcatnlo_madspin_pythia8.root"                        , "Top_bkg"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8.root"                       , "Top_bkg"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_TTJets_TuneCP5_13TeV-amcatnloFXFX-pythia8.root"                                , "Top_bkg"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_TGJets_TuneCP5_13TeV_amcatnlo_madspin_pythia8.root"                            , "Top_bkg"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8.root"            , "Top_bkg"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8.root"                , "Top_bkg"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8.root"                  , "Top_bkg"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8.root"                          , "Top_bkg"        , 41.53, outdir + "/2017", ""])

    argu_list.append([indir + "/2017/output_WGToLNuG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8.root"                       , "diboson"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_ZGToLLG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8.root"                        , "diboson"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_WW_TuneCP5_13TeV-pythia8.root"                                                 , "diboson"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_WZ_TuneCP5_13TeV-pythia8.root"                                                 , "diboson"        , 41.53, outdir + "/2017", ""])
    argu_list.append([indir + "/2017/output_ZZ_TuneCP5_13TeV-pythia8.root"                                                 , "diboson"        , 41.53, outdir + "/2017", ""])

if is2018:

    argu_list.append([indir + "/2018/output_EGamma.root"                                                                   , "Data"           ,   1.0, outdir + "/2018", ""])

    argu_list.append([indir + "/2018/output_GluGluHToGG_M125_TuneCP5_13TeV-amcatnloFXFX-pythia8.root"                      , "ggh_125"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_GluGluHToGG_M-125_13TeV_powheg_pythia8.root"                                   , "ggh_125"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_VBFHToGG_M125_13TeV_amcatnlo_pythia8.root"                                     , "vbf_125"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_VBFHToGG_M-125_13TeV_powheg_pythia8.root"                                      , "vbf_125"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_ttHJetToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                       , "tth_125"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_ttHJetToGG_M126_13TeV_amcatnloFXFX_madspin_pythia8.root"                       , "tth_126"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_WminusH_HToGG_WToAll_M120_13TeV_powheg_pythia8.root"                           , "wh_120"         , 59.69, outdir + "/2018", "wh_lep"])
    argu_list.append([indir + "/2018/output_WHToGG_M123_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_123"         , 59.69, outdir + "/2018", "wh_lep"])
    argu_list.append([indir + "/2018/output_WHToGG_M124_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_124"         , 59.69, outdir + "/2018", "wh_lep"])
    argu_list.append([indir + "/2018/output_WHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_125"         , 59.69, outdir + "/2018", "wh_lep"])
    argu_list.append([indir + "/2018/output_WminusH_HToGG_WToAll_M125_TuneCP5_13TeV-powheg-pythia8.root"                   , "wh_125"         , 59.69, outdir + "/2018", "wh_lep"])
    argu_list.append([indir + "/2018/output_WplusH_HToGG_WToAll_M125_13TeV_powheg_pythia8.root"                            , "wh_125"         , 59.69, outdir + "/2018", "wh_lep"])
    argu_list.append([indir + "/2018/output_WHToGG_M126_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_126"         , 59.69, outdir + "/2018", "wh_lep"])
    argu_list.append([indir + "/2018/output_WHToGG_M127_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_127"         , 59.69, outdir + "/2018", "wh_lep"])
    argu_list.append([indir + "/2018/output_WplusH_HToGG_WToAll_M130_13TeV_powheg_pythia8.root"                            , "wh_130"         , 59.69, outdir + "/2018", "wh_lep"])
    argu_list.append([indir + "/2018/output_WminusH_HToGG_WToAll_M120_13TeV_powheg_pythia8.root"                           , "wh_120"         , 59.69, outdir + "/2018", "wh_had"])
    argu_list.append([indir + "/2018/output_WHToGG_M123_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_123"         , 59.69, outdir + "/2018", "wh_had"])
    argu_list.append([indir + "/2018/output_WHToGG_M124_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_124"         , 59.69, outdir + "/2018", "wh_had"])
    argu_list.append([indir + "/2018/output_WHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_125"         , 59.69, outdir + "/2018", "wh_had"])
    argu_list.append([indir + "/2018/output_WminusH_HToGG_WToAll_M125_TuneCP5_13TeV-powheg-pythia8.root"                   , "wh_125"         , 59.69, outdir + "/2018", "wh_had"])
    argu_list.append([indir + "/2018/output_WplusH_HToGG_WToAll_M125_13TeV_powheg_pythia8.root"                            , "wh_125"         , 59.69, outdir + "/2018", "wh_had"])
    argu_list.append([indir + "/2018/output_WHToGG_M126_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_126"         , 59.69, outdir + "/2018", "wh_had"])
    argu_list.append([indir + "/2018/output_WHToGG_M127_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "wh_127"         , 59.69, outdir + "/2018", "wh_had"])
    argu_list.append([indir + "/2018/output_WplusH_HToGG_WToAll_M130_13TeV_powheg_pythia8.root"                            , "wh_130"         , 59.69, outdir + "/2018", "wh_had"])
    argu_list.append([indir + "/2018/output_ZHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"                           , "zh_125"         , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_ZH_HToGG_ZToAll_M130_TuneCP5_13TeV-powheg-pythia8.root"                        , "zh_130"         , 59.69, outdir + "/2018", ""])

    argu_list.append([indir + "/2018/output_DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa.root"                                 , "diphoton"       , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8.root"                       , "DYjets"         , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_GJet_Pt-20toInf_DoubleEMEnriched_MGG-40to80_TuneCP5_13TeV_Pythia8.root"        , "gjet_fakephoton", 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root"        , "gjet_fakephoton", 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root"       , "gjet_fakephoton", 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_QCD_Pt-30toInf_DoubleEMEnriched_MGG-40to80_TuneCP5_13TeV_Pythia8.root"         , "qcd_fakephoton" , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_QCD_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8.root"        , "qcd_fakephoton" , 59.69, outdir + "/2018", ""])

    argu_list.append([indir + "/2018/output_TTGG_0Jets_TuneCP5_13TeV_amcatnlo_madspin_pythia8.root"                        , "Top_bkg"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8.root"                       , "Top_bkg"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_TTJets_TuneCP5_13TeV-amcatnloFXFX-pythia8.root"                                , "Top_bkg"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_TGJets_TuneCP5_13TeV_amcatnlo_madspin_pythia8.root"                            , "Top_bkg"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8.root"            , "Top_bkg"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8.root"                , "Top_bkg"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8.root"                  , "Top_bkg"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8.root"                          , "Top_bkg"        , 59.69, outdir + "/2018", ""])

    argu_list.append([indir + "/2018/output_WGToLNuG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8.root"                       , "diboson"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_ZGToLLG_01J_5f_TuneCP5_13TeV-amcatnloFXFX-pythia8.root"                        , "diboson"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_WW_TuneCP5_13TeV-pythia8.root"                                                 , "diboson"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_WZ_TuneCP5_13TeV-pythia8.root"                                                 , "diboson"        , 59.69, outdir + "/2018", ""])
    argu_list.append([indir + "/2018/output_ZZ_TuneCP5_13TeV-pythia8.root"                                                 , "diboson"        , 59.69, outdir + "/2018", ""])

parallel_process( whleptonic_proc_func, argu_list )
