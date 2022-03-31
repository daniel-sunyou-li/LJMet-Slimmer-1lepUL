# LJMet-Slimmer-1lepUL -- `step2`

## Before running `step2`
There are several analysis-specific parameters that should be calculated and edited in the relevant scripts before running `run_step2.py` to produce the `step2` ntuples. One can individually produce `step2` ntuples once the `step1` file finishes since there is primarily a one-to-one dependency for the `step2` files. However, it is recommended to modify the parameters in one sitting to avoid overlooking individual values, as these can be heavily production dependent.

### 1. Running `compute_renorm.py` and `merge_renorm.py`
2D scale factors are evaluated binned in HT and jet multiplicity for various samples, listed in `HardcodedConditions.h`.  The relevant scripts are:
* `hadd_root.py` (optional) -- use to hadd `step1hadds` together to compute a combined renormalization
* `compute_renorm.py` -- use to obtain a `.root` file with `TH2D` weights
* `merge_renorm.py` -- combine all the `TH2D` weights calculated into one `.root` file for `step2`

### 2. Update `HardcodedConditions.cc`
2D scale factors are provided for select samples as indicated in `HardcodedConditions.cc`. The scaling need only be applied to the ttbar background, as this is the dominant background, but can be applied for the various minor backgrounds as well. It is necessary to add a new "hscale" `SFMap` in `HardcodedConditions.h` and match the `sampleType` to that listed in `step2.cc` if you wish to add new renormalization 2D SF.

One should also modify `GetCrossSectionEfficiency()` in `HardcodedConditions.cc` since the efficiency is dependent on the MC count. One can use the `compute_nrun.py` to obtain the MC count by sample, then update the dictionary `nrun` in `config.py`, which can then be read out on the console by printing `xsecEff`.

### 3. Update `config.py`
The remainder of the parameters that should be checked are listed in `config.py` and are necessary to check for each era. One would update the `haddPath` to match what was used in `step1` or wherever the `step1hadds` files are stored. Then, one can define the path where the `step2` files should be stored.

The luminosity should be checked as this affects the cross section efficiency calculation. One can reference the [luminosity twiki](https://twiki.cern.ch/twiki/bin/view/CMS/TWikiLUM) for recommended luminosity values by era.
