#---Source this script to setup the complete environment for this LCG view
#   Generated: Thu Sep 17 12:49:12 2020

#---Get the location this script (thisdir)
SOURCE=${BASH_ARGV[0]}
if [ "x$SOURCE" = "x" ]; then
    SOURCE=${(%):-%N} # for zsh
fi
thisdir=$(cd "$(dirname "${SOURCE}")"; pwd)
# Note: readlink -f is not working on OSX
thisdir=$(python -c "import os,sys; print(os.path.realpath(os.path.expanduser(sys.argv[1])))" ${thisdir})

#  First the compiler
if [ "$COMPILER" != "native" ] && [ -e /cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0/x86_64-centos7/setup.sh ]; then
    source /cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0/x86_64-centos7/setup.sh
fi

#  LCG version
LCG_VERSION=98; export LCG_VERSION

#  then the rest...
if [ -z "${PATH}" ]; then
    PATH=${thisdir}/bin; export PATH
else
    PATH=${thisdir}/bin:$PATH; export PATH
fi
if [ -d ${thisdir}/scripts ]; then
    PATH=${thisdir}/scripts:$PATH; export PATH
fi

if [ -z "${LD_LIBRARY_PATH}" ]; then
    LD_LIBRARY_PATH=${thisdir}/lib; export LD_LIBRARY_PATH
else
    LD_LIBRARY_PATH=${thisdir}/lib:$LD_LIBRARY_PATH; export LD_LIBRARY_PATH
fi
if [ -d ${thisdir}/lib64 ]; then
    LD_LIBRARY_PATH=${thisdir}/lib64:$LD_LIBRARY_PATH; export LD_LIBRARY_PATH
fi

PYTHON_VERSION=`expr $(readlink ${thisdir}/bin/python) : '.*/Python/\([0-9].[0-9]\).*'`
PY_PATHS=${thisdir}/lib/python$PYTHON_VERSION/site-packages

if [ -z "${PYTHONPATH}" ]; then
    PYTHONPATH=${thisdir}/lib:$PY_PATHS; export PYTHONPATH
else
    PYTHONPATH=${thisdir}/lib:$PY_PATHS:$PYTHONPATH; export PYTHONPATH
fi
if [ -d ${thisdir}/python ]; then
    PYTHONPATH=${thisdir}/python:$PYTHONPATH; export PYTHONPATH
fi

if [ -z "${MANPATH}" ]; then
    MANPATH=${thisdir}/man:${thisdir}/share/man; export MANPATH
else
    MANPATH=${thisdir}/man:${thisdir}/share/man:$MANPATH; export MANPATH
fi
if [ -z "${CMAKE_PREFIX_PATH}" ]; then
    CMAKE_PREFIX_PATH=${thisdir}; export CMAKE_PREFIX_PATH
else
    CMAKE_PREFIX_PATH=${thisdir}:$CMAKE_PREFIX_PATH; export CMAKE_PREFIX_PATH
fi
if [ -z "${CPLUS_INCLUDE_PATH}" ]; then
    CPLUS_INCLUDE_PATH=${thisdir}/include; export CPLUS_INCLUDE_PATH
else
    CPLUS_INCLUDE_PATH=${thisdir}/include:$CPLUS_INCLUDE_PATH; export CPLUS_INCLUDE_PATH
fi
if [ -z "${C_INCLUDE_PATH}" ]; then
    C_INCLUDE_PATH=${thisdir}/include; export C_INCLUDE_PATH
else
    C_INCLUDE_PATH=${thisdir}/include:$C_INCLUDE_PATH; export C_INCLUDE_PATH
fi
#if [ -z "${LIBRARY_PATH}" ]; then
#    LIBRARY_PATH=${thisdir}/lib; export LIBRARY_PATH
#else
#    LIBRARY_PATH=${thisdir}/lib:$LIBRARY_PATH; export LIBRARY_PATH
#fi
#if [ -d ${thisdir}/lib64 ]; then
#    export LIBRARY_PATH=${thisdir}/lib64:$LIBRARY_PATH
#fi

#---check for compiler variables
if [ -z "${CXX}" ]; then
    export FC=`command -v gfortran`
    export CC=`command -v gcc`
    export CXX=`command -v g++`
fi

#---Figure out the CMAKE_CXX_STANDARD (using Vc as a victim)
if [ -f $thisdir/include/Vc/Vc ]; then
    vc_home=$(dirname $(dirname $(dirname $(readlink $thisdir/include/Vc/Vc))))
    std=$(cat $vc_home/logs/Vc*configure.cmake | egrep -o "CMAKE_CXX_STANDARD=[0-9]+" | egrep -o "[0-9]+")
    export CMAKE_CXX_STANDARD=$std
fi

#---then ROOT
if [ -x $thisdir/bin/root ]; then
    PYTHON_INCLUDE_PATH=$(dirname $(dirname $(readlink $thisdir/bin/python)))/include/$(\ls $(dirname $(dirname $(readlink $thisdir/bin/python)))/include)
    ROOTSYS=$(dirname $(dirname $(readlink $thisdir/bin/root))); export ROOTSYS
    if [ -z "${ROOT_INCLUDE_PATH}" ]; then
        ROOT_INCLUDE_PATH=${thisdir}/include:$PYTHON_INCLUDE_PATH; export ROOT_INCLUDE_PATH
    else
        ROOT_INCLUDE_PATH=${thisdir}/include:$PYTHON_INCLUDE_PATH:$ROOT_INCLUDE_PATH; export ROOT_INCLUDE_PATH
    fi
    if [ -d $thisdir/targets/x86_64-linux/include ]; then
        ROOT_INCLUDE_PATH=${thisdir}/targets/x86_64-linux/include:$ROOT_INCLUDE_PATH; export ROOT_INCLUDE_PATH
    fi
    if [ -z "${JUPYTER_PATH}" ]; then
        JUPYTER_PATH=${thisdir}/etc/notebook; export JUPYTER_PATH
    else
        JUPYTER_PATH=${thisdir}/etc/notebook:$JUPYTER_PATH; export JUPYTER_PATH
    fi
    export CPPYY_BACKEND_LIBRARY=$ROOTSYS/lib/libcppyy_backend${PYTHON_VERSION/./_}
    export CLING_STANDARD_PCH=none
fi

#---then Gaudi
if [ -x $thisdir/include/Gaudi ]; then
    ROOT_INCLUDE_PATH=${thisdir}/src/cpp:$ROOT_INCLUDE_PATH; export ROOT_INCLUDE_PATH
fi

#---then Geant4
if [ -x $thisdir/bin/geant4-config ]; then
    IFS=$'\n'
    for line in `$thisdir/bin/geant4-config --datasets`; do
        unset IFS
        read dataset var value <<< $line;
        export $var=$value
    done
    export G4INSTALL=$(cd $(geant4-config --prefix);pwd)
    export G4EXAMPLES=$G4INSTALL/share/Geant4-$(geant4-config --version)/examples
fi

#---then JAVA
if [ Darwin = `uname` ] && [ -n "$(ls -A /Library/Java/JavaVirtualMachines)" ] && [ -x /usr/libexec/java_home ]; then
    JAVA_HOME=`/usr/libexec/java_home`; export JAVA_HOME
elif [ -x $thisdir/bin/java ]; then
    JAVA_HOME=$(dirname $(dirname $(readlink $thisdir/bin/java))); export JAVA_HOME
    LD_LIBRARY_PATH=$JAVA_HOME/jre/lib/amd64:$LD_LIBRARY_PATH; export LD_LIBRARY_PATH
fi

#---then PYTHON
if [ -x $thisdir/bin/python ]; then
    PYTHONHOME=$(dirname $(dirname $(readlink $thisdir/bin/python))); export PYTHONHOME
elif [ -x $thisdir/bin/python3 ]; then
    PYTHONHOME=$(dirname $(dirname $(readlink $thisdir/bin/python3))); export PYTHONHOME
fi

#---then HADOOP
if [ -x $thisdir/bin/hadoop -a -e $thisdir/lib/hadoop-xrootd.jar ]; then
    HADOOP_CLASSPATH=$thisdir/lib/hadoop-xrootd.jar
    HADOOP_CLASSPATH=`readlink $HADOOP_CLASSPATH`; export HADOOP_CLASSPATH
fi

#---then SPARK
if [ -x $thisdir/bin/pyspark ]; then
    SPARK_HOME=$(dirname $(dirname $(readlink $thisdir/bin/pyspark))); export SPARK_HOME
    if [[ $PYTHON_VERSION == 2* ]]; then
        PYSPARK_PYTHON=$PYTHONHOME/bin/python; export PYSPARK_PYTHON
    elif [[ "$PYTHON_VERSION" == 3* ]]; then
        PYSPARK_PYTHON=$PYTHONHOME/bin/python3; export PYSPARK_PYTHON
    fi
    if [ -x $thisdir/bin/hadoop ]; then
        SPARK_DIST_CLASSPATH=`$thisdir/bin/hadoop classpath`; export SPARK_DIST_CLASSPATH
    fi
fi

#---then BLAS
if [ -f $thisdir/lib/libBLAS.a ]; then
    export BLAS_LIBS=`readlink $thisdir/lib/libBLAS.a`
fi

#---then LAPACK
if [ -f $thisdir/lib/libLAPACK.a ]; then
    export LAPACK_LIBS=`readlink $thisdir/lib/libLAPACK.a`
fi

#---then OCTAVE
if [ -x $thisdir/bin/octave ]; then
    OCTAVE_BINDIR=$(dirname $(readlink $thisdir/bin/octave)); export OCTAVE_BINDIR
    OCTAVE_HOME=$(dirname $OCTAVE_BINDIR); export OCTAVE_HOME
    export OCTAVE_LINK_DEPS="-lfreetype -lz -lGL -lGLU -lfontconfig -lfreetype -lX11 -lncurses -lpcre -ldl -lgfortran -lm -lquadmath -lutil -lm -L$thisdir/lib $BLAS_LIBS $LAPACK_LIBS"
    export OCT_LINK_DEPS=$OCTAVE_LINK_DEPS
fi

#---then HBASE
if [ -x $thisdir/bin/hbase ]; then
    HBASE_HOME=$(dirname $(dirname $(readlink $thisdir/bin/hbase))); export HBASE_HOME
fi

#---then Jupyter
if [ -x $thisdir/bin/jupyter ]; then
    if [ -z "${JUPYTER_PATH}" ]; then
        JUPYTER_PATH=${thisdir}/share/jupyter; export JUPYTER_PATH
    else
        JUPYTER_PATH=${thisdir}/share/jupyter:$JUPYTER_PATH; export JUPYTER_PATH
    fi
fi

#---then R (requires fortran RT)
if [ -x $thisdir/bin/R ] && [ -n "$FC" ]; then
    unset R_HOME; RHOME=`echo "cat(Sys.getenv('R_HOME'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`; export RHOME; export R_HOME=${RHOME}
    if [ -z "${ROOT_INCLUDE_PATH}" ]; then
        ROOT_INCLUDE_PATH=`echo "cat(Sys.getenv('R_INCLUDE_DIR'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`
    else
        ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:`echo "cat(Sys.getenv('R_INCLUDE_DIR'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`
    fi
    ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:`echo "cat(find.package('RInside'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`/include
    ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:`echo "cat(find.package('Rcpp'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`/include
    LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:`echo "cat(find.package('readr'))" | env LC_CTYPE=en_US.UTF-8 $thisdir/bin/R --vanilla --slave`/rcon
    export ROOT_INCLUDE_PATH
fi

#---then Valgrind
if [ -x $thisdir/bin/valgrind ]; then
    VALGRIND_LIB=$thisdir/lib/valgrind; export VALGRIND_LIB
fi

#---then Delphes
if [ -x $thisdir/bin/DelphesHepMC ]; then
    DELPHES_DIR=$(dirname $(dirname $(readlink $thisdir/bin/DelphesHepMC))); export DELPHES_DIR
fi

#---then Pythia8
if [ -f $thisdir/bin/pythia8-config ]; then
    PYTHIA8=$(dirname $(dirname $(readlink $thisdir/bin/pythia8-config))); export PYTHIA8
    PYTHIA8DATA=$PYTHIA8/share/Pythia8/xmldoc; export PYTHIA8DATA
fi

#---then Graphviz
if [ -f $thisdir/bin/dot ]; then
    GVBINDIR=$(dirname $(dirname $(readlink $thisdir/bin/dot)))/lib/graphviz; export GVBINDIR
fi

#---then go
if [ -f $thisdir/bin/go ]; then
    GOROOT=$(dirname $(dirname $(readlink $thisdir/bin/go))); export GOROOT
fi
#---then gothernote
if [ -f $thisdir/bin/gophernotes ]; then
    GOPATH=$(dirname $(dirname $(readlink $thisdir/bin/gophernotes))):$GOPATH; export GOPATH
    GOBIN=$(dirname $(readlink $thisdir/bin/gophernotes)); export GOBIN
fi

if [ -f $thisdir/lib/libQt5Gui.so ]; then
    export QT_PLUGIN_PATH=$(dirname $(dirname $(readlink $thisdir/lib/libQt5Gui.so )))/plugins
    export QT_XKB_CONFIG_ROOT=/usr/share/X11/xkb
fi

if [ -f $thisdir/etc/fonts/fonts.conf ]; then
    export FONTCONFIG_PATH=$thisdir/etc/fonts
fi

#---then tensorflow
if [ -d $PY_PATHS/tensorflow_core ]; then   # version > 2.0
    export LD_LIBRARY_PATH=$PY_PATHS/tensorflow_core:$LD_LIBRARY_PATH

elif [ -d $PY_PATHS/tensorflow ]; then
    export LD_LIBRARY_PATH=$PY_PATHS/tensorflow:$PY_PATHS/tensorflow/contrib/tensor_forest:$PY_PATHS/tensorflow/python/framework:$LD_LIBRARY_PATH
fi

#---then PKG_CONFIG_PATH
if [ -z "$PKG_CONFIG_PATH" ]; then
    export PKG_CONFIG_PATH="$thisdir/lib/pkgconfig"
else
    export PKG_CONFIG_PATH="$thisdir/lib/pkgconfig:$PKG_CONFIG_PATH"
fi
if [ -d ${thisdir}/lib64/pkgconfig ]; then
    PKG_CONFIG_PATH=${thisdir}/lib64/pkgconfig:$PKG_CONFIG_PATH; export PKG_CONFIG_PATH
fi

#---then SWIG
if [ -d $thisdir/share/swig ]; then 
    export SWIG_LIB=$thisdir/share/swig/$(\ls -1 $thisdir/share/swig | head -1 )
fi

#---then cuda
if [ -x $thisdir/bin/nvcc ]; then
    CUDA_TOOLKIT_ROOT=$(dirname $(dirname $(readlink $thisdir/bin/nvcc))); export CUDA_TOOLKIT_ROOT
    PATH=${thisdir}/nvvm/bin:$PATH; export PATH
    LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${thisdir}/extras/CUPTI/lib64; export LD_LIBRARY_PATH
    if [ -d $thisdir/targets/x86_64-linux/lib ]; then
        LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${thisdir}/targets/x86_64-linux/lib; export LD_LIBRARY_PATH
    fi
fi

#---then Garfield++
if [ -f $thisdir/lib/cmake/Garfield/GarfieldConfig.cmake ]; then
    GARFIELD_HOME=$(dirname $(dirname $(dirname $(dirname $(readlink $thisdir/lib/cmake/Garfield/GarfieldConfig.cmake))))); export GARFIELD_HOME
    ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:${thisdir}/include/Garfield; export ROOT_INCLUDE_PATH
fi

#---then PyTorch
if [ -d $PY_PATHS/torch ]; then
    export LD_LIBRARY_PATH=$PY_PATHS/torch/lib:$LD_LIBRARY_PATH
fi

#---then pyLCIO
if [ -f $thisdir/python/pylcio.py ]; then
    export LCIO=$thisdir
fi

#---then UniGen
if [ -f $thisdir/lib/libUniGen.so ]; then
    export UNIGEN=$(dirname $(dirname $(readlink $thisdir/lib/libUniGen.so )))
fi

#---then MySQL
if [ -f $thisdir/bin/mariadb_config ]; then
    export MYSQL_HOME=$(dirname $(dirname $(readlink $thisdir/bin/mariadb_config )))
fi

#---then Apache Ant
if [ -d $thisdir/bin/ant ]; then
    export ANT_HOME=$(dirname $(dirname $(readlink $thisdir/bin/ant )))
fi

#--- Openloops
if [ -x $thisdir/lib/libopenloops.so ]; then
    OL_PROCLIB_PATH=$(dirname $(dirname $(readlink $thisdir/lib/libopenloops.so))); export OL_PROCLIB_PATH
fi

#---Herwig
if [ -f $thisdir/bin/Herwig ]; then
    HERWIGAPI_PATH=$(dirname $(dirname $(readlink $thisdir/bin/Herwig )))/lib/Herwig
    export LD_LIBRARY_PATH=$HERWIGAPI_PATH:$LD_LIBRARY_PATH
fi

#---ThePeg
if [ -f $thisdir/bin/runThePEG ]; then
    THEPEGLIB_PATH=$(dirname $(dirname $(readlink $thisdir/bin/runThePEG )))/lib/ThePEG
    export LD_LIBRARY_PATH=$THEPEGLIB_PATH:$LD_LIBRARY_PATH
fi



#---then git
if [ -f $thisdir/bin/git ]; then
    export GIT_EXEC_PATH=$(dirname $(dirname $(readlink $thisdir/bin/git )))/libexec/git-core
fi

#---then openmpi
if [ -f $thisdir/bin/mpirun ]; then
    export OPAL_PREFIX=$(dirname $(dirname $(readlink $thisdir/bin/mpirun )))
fi

