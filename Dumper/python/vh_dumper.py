import HggAnalyzer.Dumper.pluginVHDumper as hggdumper


def zhleptonic_proc_func(filename, type, scale, outdir, vhtype):
    zhleptonic = hggdumper.ZHLeptonicDumper(filename, type)
    zhleptonic.SetGlobalScale(scale)
    zhleptonic.Dumper(outdir, vhtype)

def whleptonic_proc_func(filename, type, scale, outdir, vhtype):
    whleptonic = hggdumper.WHLeptonicDumper(filename, type)
    whleptonic.SetGlobalScale(scale)
    whleptonic.Dumper(outdir, vhtype)

def vhmet_proc_func(filename, type, scale, outdir, vhtype, is_data_driven = False):
    vhmet = hggdumper.VHMetDumper(filename, type)
    vhmet.SetGlobalScale(scale)
    vhmet.Dumper(outdir, vhtype, is_data_driven)
