#---Source this script to setup the complete environment for this LCG view
#   Generated: Thu Sep 17 12:49:12 2020

#---Get the location this script (thisdir)
set ARGS=($_)
set LSOF=`env PATH=/usr/sbin:"${PATH}" which lsof`
set thisfile="`${LSOF} -w +p $$ | grep -oE '/.*setup.csh'  `"
if ( "$thisfile" != "" && -e ${thisfile} ) then
    set thisdir="`dirname ${thisfile}`"
else if ("$ARGS" != "") then
    set thisdir="`dirname ${ARGS[2]}`"
endif
if ( -l ${thisdir} ) then
  set thisdir="`readlink -f ${thisdir}`"
endif

#---First the compiler
if ( -e /cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0/x86_64-centos7/setup.csh ) then
    source /cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0/x86_64-centos7/setup.csh
endif

#---LCG version
setenv LCG_VERSION 98

#---then the rest...
if ($?PATH) then
    setenv PATH ${thisdir}/bin:"${PATH}"
else
    setenv PATH ${thisdir}/bin
endif
if ( -d ${thisdir}/scripts ) then
    setenv PATH ${thisdir}/scripts:${PATH}
endif

if ($?LD_LIBRARY_PATH) then
    setenv LD_LIBRARY_PATH ${thisdir}/lib:${LD_LIBRARY_PATH}
else
    setenv LD_LIBRARY_PATH ${thisdir}/lib
endif
if ( -d ${thisdir}/lib64 ) then
    setenv LD_LIBRARY_PATH ${thisdir}/lib64:${LD_LIBRARY_PATH}
endif

set pyversion=`python -c "import sys; print('python{0}.{1}'.format(*sys.version_info))"`
set py_path=${thisdir}/lib/$pyversion/site-packages
if ($?PYTHONPATH) then
    setenv PYTHONPATH ${thisdir}/lib:${py_path}:${PYTHONPATH}
else
    setenv PYTHONPATH ${thisdir}/lib:${py_path}
endif
if ( -d ${thisdir}/python ) then
    setenv PYTHONPATH ${thisdir}/python:${PYTHONPATH}
endif

if ($?MANPATH) then
    setenv MANPATH ${thisdir}/man:${thisdir}/share/man:${MANPATH}
else
    setenv MANPATH ${thisdir}/man:${thisdir}/share/man
endif

if ($?CMAKE_PREFIX_PATH) then
    setenv CMAKE_PREFIX_PATH ${thisdir}:${CMAKE_PREFIX_PATH}
else
    setenv CMAKE_PREFIX_PATH $thisdir
endif

if ($?CPLUS_INCLUDE_PATH) then
    setenv CPLUS_INCLUDE_PATH ${thisdir}/include:${CPLUS_INCLUDE_PATH}
else
    setenv CPLUS_INCLUDE_PATH $thisdir/include
endif
if ($?C_INCLUDE_PATH) then
    setenv C_INCLUDE_PATH ${thisdir}/include:${C_INCLUDE_PATH}
else
    setenv C_INCLUDE_PATH $thisdir/include
endif

#if ($?LIBRARY_PATH) then
#    setenv LIBRARY_PATH ${thisdir}/lib:${LIBRARY_PATH}
#else
#    setenv LIBRARY_PATH ${thisdir}/lib
#endif
#if ( -d ${thisdir}/lib64 ) then
#    setenv LIBRARY_PATH ${thisdir}/lib64:${LIBRARY_PATH}
#endif 

#---Figure out the CMAKE_CXX_STANDARD (using Vc as a victim)
if ( -f $thisdir/include/Vc/Vc ) then
    set vcdir=`readlink $thisdir/include/Vc/Vc`
    set vcdir=`dirname $vcdir`
    set std=`cat $vcdir/../../logs/Vc*configure.cmake | egrep -o 'CMAKE_CXX_STANDARD=[0-9]+' | egrep -o '[0-9]+'`
    setenv CMAKE_CXX_STANDARD ${std}
endif

#---then ROOT
if ( -e $thisdir/bin/root ) then
    set rootdir=`readlink $thisdir/bin/root`
    set rootdir=`dirname $rootdir`
    set rootdir=`dirname $rootdir`
    set pythonincdir=`python -c "from sysconfig import get_paths as gp; print(gp()['include'])"`
    setenv ROOTSYS $rootdir
    if ($?ROOT_INCLUDE_PATH) then
        setenv ROOT_INCLUDE_PATH ${thisdir}/include:${pythonincdir}:${ROOT_INCLUDE_PATH}
    else
        setenv ROOT_INCLUDE_PATH ${thisdir}/include:${pythonincdir}
    endif
    if ( -d ${thisdir}/targets/x86_64-linux/include ) then
        setenv ROOT_INCLUDE_PATH ${thisdir}/targets/x86_64-linux/include:${ROOT_INCLUDE_PATH}
    endif
    if ($?JUPYTER_PATH) then
        setenv JUPYTER_PATH ${thisdir}/etc/notebook:${JUPYTER_PATH}
    else
        setenv JUPYTER_PATH ${thisdir}/etc/notebook
    endif
endif

#---then Gaudi
if ( -e $thisdir/include/Gaudi ) then
    setenv ROOT_INCLUDE_PATH ${thisdir}/src/cpp:${ROOT_INCLUDE_PATH}
endif

#---then Geant4
if ( -e $thisdir/bin/geant4-config ) then
    foreach line ( "`$thisdir/bin/geant4-config --datasets`" )
        set vars = ($line)
        setenv $vars[2] $vars[3]
    end
    set g4dir=`geant4-config --prefix`
    set g4dir=`cd ${g4dir};pwd`
    setenv G4INSTALL ${g4dir}
    setenv G4EXAMPLES ${g4dir}/share/Geant4-`geant4-config --version`/examples
endif

#---then JAVA
if ( Darwin == `uname` && -e /usr/libexec/java_home ) then
    setenv JAVA_HOME `/usr/libexec/java_home`
else if ( -e $thisdir/bin/java ) then
    set java_home=`readlink $thisdir/bin/java`
    set java_home=`dirname $java_home`
    set java_home=`dirname $java_home`
    setenv JAVA_HOME $java_home
    setenv LD_LIBRARY_PATH ${java_home}/jre/lib/amd64:${LD_LIBRARY_PATH}
endif

#---then PYTHON
if ( -e $thisdir/bin/python ) then
    set python_home=`readlink $thisdir/bin/python`
    set python_home=`dirname $python_home`
    set python_home=`dirname $python_home`
    setenv PYTHONHOME $python_home
else if ( -e $thisdir/bin/python3 ) then
    set python_home=`readlink $thisdir/bin/python3`
    set python_home=`dirname $python_home`
    set python_home=`dirname $python_home`
    setenv PYTHONHOME $python_home
endif

#---then HADOOP
if ( -e $thisdir/bin/hadoop && -e $thisdir/lib/hadoop-xrootd.jar ) then
    set hadoop_classpath=$thisdir/lib/hadoop-xrootd.jar
    set hadoop_classpath=`readlink $hadoop_classpath`
    setenv HADOOP_CLASSPATH $hadoop_classpath
endif

#---then SPARK
if ( -e $thisdir/bin/pyspark ) then
    set spark_home=`readlink $thisdir/bin/pyspark`
    set spark_home=`dirname $spark_home`
    set spark_home=`dirname $spark_home`
    setenv SPARK_HOME $spark_home
    if ( $pyversion =~ python2* ) then
        set pysparkpython=$PYTHONHOME/bin/python
        setenv PYSPARK_PYTHON $pysparkpython
    else if ( $pyversion =~ python3* ) then
        set pysparkpython=$PYTHONHOME/bin/python3
        setenv PYSPARK_PYTHON $pysparkpython
    endif
    if ( -e $thisdir/bin/hadoop ) then
        set spark_dist_classpath=`$thisdir/bin/hadoop classpath`
        setenv SPARK_DIST_CLASSPATH "$spark_dist_classpath"
    endif
endif

#---then BLAS
if ( -e $thisdir/lib/libBLAS.a ) then
    setenv BLAS_LIBS `readlink $thisdir/lib/libBLAS.a`
else
    setenv BLAS_LIBS
endif 

#---then LAPACK
if ( -e $thisdir/lib/libLAPACK.a ) then
    setenv LAPACK_LIBS `readlink $thisdir/lib/libLAPACK.a`
else
    setenv LAPACK_LIBS
endif

#---then OCTAVE
if ( -e $thisdir/bin/octave ) then
    set octave_bin=`readlink $thisdir/bin/octave`
    set octave_bin=`dirname $octave_bin`
    set octave_home=`dirname $octave_bin`
    setenv OCTAVE_BINDIR $octave_bin
    setenv OCTAVE_HOME $octave_home
    setenv OCTAVE_LINK_DEPS "-lfreetype -lz -lGL -lGLU -lfontconfig -lfreetype -lX11 -lncurses -lpcre -ldl -lgfortran -lm -lquadmath -lutil -lm -L$thisdir/lib $BLAS_LIBS $LAPACK_LIBS"
    setenv OCT_LINK_DEPS '$OCTAVE_LINK_DEPS'
endif

#---then HBASE
if ( -e $thisdir/bin/hbase ) then
    set hbase_home=`readlink $thisdir/bin/hbase`
    set hbase_home=`dirname $hbase_home`
    set hbase_home=`dirname $hbase_home`
    setenv HBASE_HOME $hbase_home
endif

#---then Jupyter
if ( -e $thisdir/bin/jupyter ) then
    if ($?JUPYTER_PATH) then
        setenv JUPYTER_PATH ${thisdir}/share/jupyter:${JUPYTER_PATH}
    else
        setenv JUPYTER_PATH ${thisdir}/share/jupyter
    endif
endif

#---then R (requires gfortran)
if ( -e $thisdir/bin/R && $?FC ) then
    unsetenv R_HOME
    setenv RHOME `echo "cat(Sys.getenv('R_HOME'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`
    setenv R_HOME ${RHOME}
    if ($?ROOT_INCLUDE_PATH) then
        setenv ROOT_INCLUDE_PATH ${ROOT_INCLUDE_PATH}:`echo "cat(Sys.getenv('R_INCLUDE_DIR'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`
    else
        setenv ROOT_INCLUDE_PATH `echo "cat(Sys.getenv('R_INCLUDE_DIR'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`
    endif
    setenv ROOT_INCLUDE_PATH ${ROOT_INCLUDE_PATH}:`echo "cat(find.package('RInside'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`/include
    setenv ROOT_INCLUDE_PATH ${ROOT_INCLUDE_PATH}:`echo "cat(find.package('Rcpp'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`/include
    setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:`echo "cat(find.package('readr'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`/rcon
endif

#---then Valgrind
if ( -e $thisdir/bin/valgrind ) then
    setenv VALGRIND_LIB ${thisdir}/lib/valgrind
endif

#---then Delphes
if ( -e $thisdir/bin/DelphesHepMC ) then
    set delphes_dir=`readlink $thisdir/bin/DelphesHepMC`
    set delphes_dir=`dirname $delphes_dir`
    set delphes_dir=`dirname $delphes_dir`
    setenv DELPHES_DIR $delphes_dir
endif

#---then Pythia8
if ( -e $thisdir/bin/pythia8-config ) then
    set pythia8_dir=`readlink $thisdir/bin/pythia8-config`
    set pythia8_dir=`dirname $pythia8_dir`
    set pythia8_dir=`dirname $pythia8_dir`
    setenv PYTHIA8 $pythia8_dir
    setenv PYTHIA8DATA ${PYTHIA8}/share/Pythia8/xmldoc
endif

#---then Graphviz
if ( -e $thisdir/bin/dot ) then
    set graphviz_dir=`readlink $thisdir/bin/dot`
    set graphviz_dir=`dirname $graphviz_dir`
    set graphviz_dir=`dirname $graphviz_dir`
    setenv GVBINDIR $graphviz_dir/lib/graphviz
endif

#---then Go
if ( -e $thisdir/bin/go ) then
    set go_dir=`readlink $thisdir/bin/go`
    set go_dir=`dirname $go_dir`
    set go_dir=`dirname $go_dir`
    setenv GOROOT $go_dir
endif

#---then gophernotes
if ( -e $thisdir/bin/gophernotes ) then
    set gophernotes_bindir=`readlink $thisdir/bin/gophernotes`
    set gophernotes_dir=`dirname $gophernotes_bindir`
    set gophernotes_dir=`dirname $gophernotes_dir`
    if ($?GOPATH) then
        setenv GOPATH ${gophernotes_dir}:${GOPATH}
    else
        setenv GOPATH ${gophernotes_dir}
    endif
    setenv GOBIN `dirname $gophernotes_bindir`
endif

if ( -e $thisdir/lib/libQt5Gui.so ) then
    set qt_dir=`readlink $thisdir/lib/libQt5Gui.so`
    set qt_dir=`dirname $qt_dir`
    set qt_dir=`dirname $qt_dir`
    setenv QT_PLUGIN_PATH $qt_dir/plugins
    setenv QT_XKB_CONFIG_ROOT /usr/share/X11/xkb
endif

if ( -f $thisdir/etc/fonts/fonts.conf ) then
    setenv FONTCONFIG_PATH $thisdir/etc/fonts
endif

#---then tensorflow
if ( -d $py_path/tensorflow_core ) then
    setenv LD_LIBRARY_PATH $py_path/tensorflow_core:${LD_LIBRARY_PATH}  # version > 2.0
else if ( -d $py_path/tensorflow ) then
    setenv LD_LIBRARY_PATH $py_path/tensorflow:$py_path/tensorflow/contrib/tensor_forest:$py_path/tensorflow/python/framework:${LD_LIBRARY_PATH}
endif

#---then PKG_CONFIG_FILE
if ($?PKG_CONFIG_PATH) then
    setenv PKG_CONFIG_PATH ${thisdir}/lib/pkgconfig:${PKG_CONFIG_PATH}
else
    setenv PKG_CONFIG_PATH ${thisdir}/lib/pkgconfig
endif
if ( -d ${thisdir}/lib64/pkgconfig ) then
    setenv PKG_CONFIG_PATH ${thisdir}/lib64/pkgconfig:${PKG_CONFIG_PATH}
endif

#---then SWIG
if ( -e $thisdir/share/swig ) then
    set swigver=`\ls -1 $thisdir/share/swig | head -1`
    setenv SWIG_LIB $thisdir/share/swig/${swigver}
endif

#---then cuda
if ( -x $thisdir/bin/nvcc ) then
    set cuda_root=`readlink $thisdir/bin/nvcc`
    set cuda_root=`dirname $cuda_root`
    set cuda_root=`dirname $cuda_root`
    setenv CUDA_TOOLKIT_ROOT $cuda_root
    setenv PATH ${thisdir}/nvvm/bin:${PATH}
    setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${thisdir}/extras/CUPTI/lib64
    if ( -d $thisdir/targets/x86_64-linux/lib ) then
        setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${thisdir}/targets/x86_64-linux/lib
    endif
endif

#---then Garfield++
if ( -f $thisdir/lib/cmake/Garfield/GarfieldConfig.cmake ) then
    set garfield_home=`readlink $thisdir/lib/cmake/Garfield/GarfieldConfig.cmake`
    set garfield_home=`dirname $garfield_home`
    set garfield_home=`dirname $garfield_home`
    set garfield_home=`dirname $garfield_home`
    set garfield_home=`dirname $garfield_home`
    setenv GARFIELD_HOME $garfield_home
    setenv ROOT_INCLUDE_PATH ${ROOT_INCLUDE_PATH}:${thisdir}/include/Garfield
endif

#---then pytorch
if ( -d $py_path/torch ) then
    setenv LD_LIBRARY_PATH $py_path/torch/lib:${LD_LIBRARY_PATH}
endif

#---then Gaudi
if ( -x $thisdir/bin/Gaudi.exe ) then
    setenv PATH ${thisdir}/scripts:${PATH}
    setenv PYTHONPATH ${thisdir}/python:${PYTHONPATH}
endif 

#---then pyLCIO
if ( -f $thisdir/python/pylcio.py ) then
    setenv LCIO $thisdir
endif

#---then UniGen
if ( -f $thisdir/lib/libUniGen.so ) then
    set unigen_dir=`readlink $thisdir/lib/libUniGen.so`
    set unigen_dir=`dirname $unigen_dir`
    setenv UNIGEN `dirname $unigen_dir`
endif

#---then MySQL
if ( -f $thisdir/bin/mariadb_config ) then
    set mysql_dir=`readlink $thisdir/bin/mariadb_config`
    set mysql_dir=`dirname $mysql_dir`
    setenv MYSQL_HOME `dirname $mysql_dir`
endif

#---then Apache Ant
if ( -d $thisdir/bin/ant ) then
    set ant_dir=`readlink $thisdir/bin/ant`
    set ant_dir=`dirname $ant_dir`
    setenv ANT_HOME `dirname $ant_dir`
endif

#---then Openloops
if ( -e $thisdir/lib/libopenloops.so ) then
    set proclib_path=`readlink $thisdir/lib/libopenloops.so`
    set proclib_path=`dirname $proclib_path`
    set proclib_path=`dirname $proclib_path`
    setenv OL_PROCLIB_PATH $proclib_path
endif

#--- then Herwig
if ( -e $thisdir/bin/Herwig ) then
    set proclib_path=`readlink $thisdir/bin/Herwig`
    set proclib_path=`dirname $proclib_path`
    set proclib_path=`dirname $proclib_path`
    setenv LD_LIBRARY_PATH ${proclib_path}/lib/Herwig:${LD_LIBRARY_PATH}
endif

#--- then ThePeg
if ( -e $thisdir/bin/runThePEG ) then
    set proclib_path=`readlink $thisdir/bin/runThePEG`
    set proclib_path=`dirname $proclib_path`
    set proclib_path=`dirname $proclib_path`
    setenv LD_LIBRARY_PATH ${proclib_path}/lib/ThePEG:${LD_LIBRARY_PATH}
endif



#--- then git
if ( -e $thisdir/bin/git ) then
    set proclib_path=`readlink $thisdir/bin/git`
    set proclib_path=`dirname $proclib_path`
    set proclib_path=`dirname $proclib_path`
    setenv GIT_EXEC_PATH ${proclib_path}/libexec/git-core
endif

#--- then openmpi
if ( -e $thisdir/bin/mpirun ) then
    set proclib_path=`readlink $thisdir/bin/mpirun`
    set proclib_path=`dirname $proclib_path`
    set proclib_path=`dirname $proclib_path`
    setenv OPAL_PREFIX ${proclib_path}/
endif

