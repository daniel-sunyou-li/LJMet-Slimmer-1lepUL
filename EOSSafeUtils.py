import os, sys, getopt
import string
#This file has some general EOS safe utilities for eos file operations
# EOSpathExists(path)
# EOSisfile(path)
# EOSrm(path):
# EOSrmdir(path): 

xrd = 'eos root://cmseos.fnal.gov/'
#xrd = 'xrdfs root://cmseos.fnal.gov/' #doesn't work. 

def cleanEOSpath(path): 
	#if path starts with /eos/uscms remove it. 
	if string.find(path,'/eos/uscms',0,10) == 0:
		return path[10:]
	return path

def EOSpathExists(path): 
	#returns a bool true iff the path exists
	path = cleanEOSpath(path)
	return len(os.popen(xrd+' ls -d '+path).readlines()) == 1

def EOSisfile(path): 
	#returns a bool saying if this is a file. 
	path = cleanEOSpath(path)
	if not EOSpathExists(path):
		return False
	lines = os.popen(xrd+' ls -l '+path).readlines()
	if len(lines) != 1:
		return False
	else:
		return string.find(lines[0],'-',0,1) == 0 #entry should start with -

def EOSisZeroSizefile(path, month): 
	#returns a bool saying if this is a file. 
	path = cleanEOSpath(path)
	if not EOSpathExists(path):
		return False
	lines = os.popen(xrd+' ls -l '+path).readlines()
	if len(lines) != 1:
		return False
	else:
		return string.find(lines[0],' 0 '+month+' ',0,len(lines[0])) > 0

def EOSrm(path):
	#rm path, but EOS safe.
	path = cleanEOSpath(path)
	if EOSpathExists(path):
		os.system(xrd +" rm "+path)
	
def EOSrmdir(path): 
	#rmdir path, but EOS safe.
	path = cleanEOSpath(path)
	if EOSpathExists(path):
		os.system(xrd +" rmdir "+path)


def striplist(alist): 
	#takes a list of strings, returns a version of the list with 
	#whitespace stripped from all entries.
	ret = []
	for item in alist:
		ret.append(item.strip())
	return ret
	
def EOSlistdir(Dir):
	#ls Dir, only eos safe.
	#does not check that this is a directory
	#returns a list of the contents of ls 
	Dir = cleanEOSpath(Dir)
	items = os.popen(xrd+' ls '+Dir).readlines() #they have a \n at the end 
	return striplist(items)

def BRUXlistdir(Dir):
	if not Dir.startswith('/store'):
		print 'BRUXlistdir: begin path with /store'
		return 
        items = os.popen('gfal-ls gsiftp://brux30.hep.brown.edu//isilon/hadoop/'+Dir).readlines()
	return striplist(items)

def EOSlist_root_files(Dir):
	#ls Dir/*.root, returns a list of the root file names that it finds (without the path) 
	Dir = cleanEOSpath(Dir)
	items = os.popen(xrd+' ls '+Dir).readlines() #they have a \n at the end 
	items2 = striplist(items)
	rootlist = []
	for item in items2:
		if string.rfind(item,'root',-4) != -1:
			rootlist.append(item)
	return rootlist

def BRUXlist_root_files(Dir):
	if not Dir.startswith('/store'):
		print 'BRUXlistdir: begin path with /store'
		return 
        items = os.popen('gfal-ls gsiftp://brux30.hep.brown.edu//isilon/hadoop/'+Dir).readlines()
	items2 = striplist(items)
	rootlist = []
	for item in items2:
		if string.rfind(item,'root',-4) != -1:
			rootlist.append(item)
	return rootlist

def EOSlist_lhe_files(Dir): 
	#ls Dir/*.root, returns a list of the root file names that it finds (without the path) 
	Dir = cleanEOSpath(Dir)
	items = os.popen(xrd+' ls '+Dir).readlines() #they have a \n at the end 
	items2 = striplist(items)
	rootlist = []
	for item in items2:
		if string.rfind(item,'lhe.gz',-6) != -1:
			rootlist.append(item)
	return rootlist

tempfile = '.eossafetemp'
def killtemp(): 
	#deletes the the temp file 
	if os.path.exists(tempfile):
		os.system("rm "+tempfile)

def EOSopen_via_temp(path,option): 
	#copies the file to the temp file, then opens that. 
	#be careful to not open more than one file at a time 
	#or else the first file will get deleted. 
	path = cleanEOSpath(path)
	killtemp()
	os.system("xrdcp -s root://cmseos.fnal.gov/"+path+" ./"+tempfile)
	return open(tempfile,option)

def copytotemp(path): 
	#copies a file from eos to the local temp file
	killtemp()
	path = cleanEOSpath(path)
	os.system("xrdcp -s root://cmseos.fnal.gov/"+path+" ./"+tempfile)
	
	#I need to replace thei line:
	#folders = [x for x in os.walk(Dir).next()[1] ] 
	#this lists all the folders in Dir. 

def EOSlistSubdirs(Dir):
	#returns a list of all the subdirectories of Dir
	#built to substitutes for the line
	#folders = [x for x in os.walk(Dir).next()[1] ] 
	Dir = cleanEOSpath(Dir)
	ret = []
	if not EOSpathExists(Dir): 
		return ret
	for line in os.popen(xrd+' ls -l '+Dir).readlines():
		words = line.split()
		if len(words) < 9: #if not a full ls -l entry
			continue
		elif words[0][0]=='d': #if its a directory
			ret.append(words[8]) #append the directory name
	return ret

#def EOSwalk(Dir):
	#safeDir = cleanEOSpath(Dir)
	#https://docs.python.org/2/library/os.html	
