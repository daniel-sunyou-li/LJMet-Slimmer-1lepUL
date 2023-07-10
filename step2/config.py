eosUserName = "dali"
postfix = "3t"
years = [ "16APV", "16", "17", "18" ]

haddPath = {
  year: {
    "LPC": "/eos/uscms/store/user/{}/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_{}_step1hadds".format( eosUserName, year, postfix ),
    "BRUX": "/isilon/hadoop/store/user/{}/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_{}_step1hadds".format( eosUserName, year, postfix ) 
  } for year in years
}

step2Path = {
  year: {
    "LPC": "/eos/uscms/store/user/{}/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_{}_step2".format( eosUserName, year, postfix ), 
    "BRUX": "/isilon/hadoop/store/user/{}/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_{}_step2".format( eosUserName, year, postfix )
  } for year in years
}

# https://docs.google.com/presentation/d/1gEF2jExqS1hWs-dlYgxrTT2xQztYbBZcrLdw45Aiy7g/edit#slide=id.ge8cc301637_0_55
lumi = {
  "16APV": 19520., # From PdmV 
  "16": 16810.,    # From PdmV 
  "17": 41480.,    # calculated using brilcalc on GoldenJSON 
  "18": 59832.     # calculated using brilcalc on GoldenJSON
}

JES_shifts = {
  "JER": False,
  "JEC": True, # fully de-correlated, corresponds to total JEC from LJMet
  "FlavorQCD": False,
  "FlavorPureQuark": False,
  "FlavorPureGluon": False,
  "FlavorPureBottom": False,
  "FlavorPureCharm": False,
  "RelativeBal": False,
  "RelativeSample_Era": False,
  "HF": False,
  "HF_Era": False,
  "BBEC1": False,
  "BBEC1_Era": False,
  "EC2": False,
  "EC2_Era": False,
  "Absolute": False,
  "Absolute_Era": False
}

