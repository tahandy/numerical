#
# 'make depend' uses makedepend to automatically generate dependencies
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
FC = gfortran
FFLAGS = -Wall -g
INCLUDES =
LFLAGS =
LIBS =

define ECHO-COMPILING
@echo Compiling $<
endef


SRCS = test1.F90 \
	   test2.F90 \
	   test3.F90 \
	   testInterface.F90 \
	   main.F90

OBJS = $(SRCS:.F90=.o)

# define the executable file
MAIN = test

#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN)
		@echo  Simple compiler named mycc has been compiled

$(MAIN): $(OBJS)
		$(FC) $(FFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
%.o: %.F90
		#$(ECHO-COMPILING)
		$(FC) $(FFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) *.o *~ *.mod $(MAIN)

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
