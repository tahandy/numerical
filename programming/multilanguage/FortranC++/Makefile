#
# 'make depend' uses makedepend to automatically generate dependencies
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
FC  = gfortran
CXX = g++
CC  = gcc
FFLAGS = -Wall -g
CXXFLAGS = -Wall -g
INCLUDES =
LFLAGS =
LIBS = -lgfortran

define ECHO-COMPILING
@echo Compiling $<
endef

# Fortran-in-C++ files
HDRS = BoxClass.h \
       cxxFortFuncs.h \
       cxxFuncs.h \
       BoxClass_fortAPI.h

SRCS = BoxClass.cxx \
	   BoxClass_fortAPI.cxx \
	   BoxClass_module.F90 \
	   cxxFuncs.cxx \
	   cxxFuncsInterface.F90 \
	   cxxFortFuncs.F90 \
	   main.cxx

OBJS = $(patsubst %.cxx,%.o,$(patsubst %.F90,%.o,$(SRCS)))


# define the executable file
MAIN = main

#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN)
		@echo  C++-in-Fortran and Fortran-in-C++ examples built

$(MAIN): $(OBJS) $(HDRS)
		$(CXX) $(FLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
%.o: %.F90
		$(ECHO-COMPILING)
		$(FC) $(FFLAGS) $(INCLUDES) -c $<  -o $@
%.o: %.cxx
		$(ECHO-COMPILING)
		$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		@echo $(OBJS)
		$(RM) *.o *~ *.mod  $(MAIN)

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
