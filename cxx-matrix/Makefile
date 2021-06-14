################################################################################
#
#  Universidade Federal Rural do Rio de Janeiro - DCC - SmartCOMM
#  por: Marcelo Zamith - mzamith@ufrrj.br
#  https://software.intel.com/content/www/us/en/develop/documentation/vtune-help/top/analyze-performance/microarchitecture-analysis-group/memory-access-analysis.html
################################################################################
CPUCC     = g++
CPPFLAGS  =   
DEFS      = 
PAPI      = /opt/papi
INCLUDES  = -I. -I$(PAPI)/testlib -I$(PAPI)/include -I$(PAPI)/share/papi/testlib/ -I../lib/
LIBDIR    = -L/usr/lib
#PAPILIBS  =  $(PAPI)/lib/libpapi.a
LIBS     =  -lm
LINK     =  $(LIBDIR) $(LIBS)
#DEFS     =  -DPAPI


CPU_COMPILE = $(CPUCC) $(DEFS) $(INCLUDES) $(CPPFLAGS)

all: jacobi-papi

jacobi-papi:
	$(CPU_COMPILE) ../lib/System.cpp jacobi-papi.cpp $(LINK) -o bin/jacobi-papi $(PAPI)/lib/libpapi.a


clean:
	rm bin/*
