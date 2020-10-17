import HggAnalyzer.Dumper.pluginVHDumper as hggdumper


def zhleptonic_proc_func(filename, type, scale, outdir, vhtype, pufilename = ''):
    zhleptonic = hggdumper.ZHLeptonicDumper(filename, type, pufilename)
    zhleptonic.SetGlobalScale(scale)
    zhleptonic.Dumper(outdir, vhtype)

def whleptonic_proc_func(filename, type, scale, outdir, vhtype, pufilename = ''):
    whleptonic = hggdumper.WHLeptonicDumper(filename, type, pufilename)
    whleptonic.SetGlobalScale(scale)
    whleptonic.Dumper(outdir, vhtype)

def vhmet_proc_func(filename, type, scale, outdir, vhtype, pufilename = '', is_data_driven = False):
    vhmet = hggdumper.VHMetDumper(filename, type, pufilename)
    vhmet.SetGlobalScale(scale)
    vhmet.Dumper(outdir, vhtype, is_data_driven)
