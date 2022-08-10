# LJMet-Slimmer-1lepUL -- `step1` 

As an example, to run `step1` for 2017 single electron data on BRUX to store files on BRUX, do:

    run_step1.py -y 17 -g DATAE -l BRUX -s BRUX 
    
You can find all the possible arguments for `-g` in `config.py` under the `samples` dictionary. This script was made to run on both LPC and BRUX with the respective paths modifiable in `config.py`. To run `step1` on the JEC/JER shift samples, include the argument `--shifts`.  You can also use the following options:
* `-f` (default = `30`) for number of files per Condor job
* `-j` (default = `-1`) for number of jobs to submit per sample
* `--test` to only submit one job

After running `run_step1.py` and having the `step1` files stored either on BRUX or LPC. You need to `hadd` together the separate files using `run_hadd.py`:

    run_hadd.py -y 17 -g DATAE -l BRUX
    
You can also include the argument `-f` to indicate how many files to hadd together.

You can find code for calculating the triggerX efficiencies using the cut-and-count method in the `triggerX` directory. This requires having produced some `step1` files for the data and ttbar background to make the calculation.

## Script descriptions

For a more comprehensive explanation of what each script in `step1` does:
* `BTagCalibForLJMet.cpp` - loads and parses through the b-tagging scale factors (both `deepCSV` and `deepJet`)
* `BTagCalibForLJMet.h` - header file for `BTagCalibForLJMet.cpp`
* `HardcodedConditions.cc` - scale factor configuration file, edit if updating scale factors or adding new scale factors
* `HardcodedConditions.h` - header file for `HardcodedConditions.cc`, be sure to update if adding new scale factors
* `compile_step1.C` - run in `run_step1.py` to compile the necessary `C++` scripts used for `step1`
* `config.py` - various configurable parameters used in `step1` including file paths, sample names, etc. Be sure to edit for your specific analysis.
* `make_step1.C` - wrapper for running `step1.cc` 
* `make_step1.sh` - condor submission shell script for running `step1`
* `run_hadd.py` - `hadds` (consolidates) all the individual `step1` files into fewer files (typically a single one)
* `run_step1.py` - submits condor jobs that will run `step1`
* `step1.cc` - applies pre-selection to LJMet ntuples as well as computes various higher-level variables and adds scale factors
* `step1.h` - header file for `step1.cc`
