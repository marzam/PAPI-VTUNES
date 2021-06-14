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

all: quick-vtune bubble-vtune bubble-papi-clk bubble-papi-cache

quick-vtune:
	$(CPU_COMPILE) quick.cpp $(LINK) -o bin/quick-vtune

bubble-vtune:
	$(CPU_COMPILE) bubble.cpp $(LINK) -o bin/bubble-vtune

bubble-papi-clk:
	$(CPU_COMPILE) ../lib/System.cpp bubble-papi-clk.cpp $(LINK) -o bin/bubble-papi-clk $(PAPI)/lib/libpapi.a

bubble-papi-cache:
	$(CPU_COMPILE) ../lib/System.cpp bubble-papi-cache.cpp $(LINK) -o bin/bubble-papi-cache $(PAPI)/lib/libpapi.a

clean:
	rm bin/*
