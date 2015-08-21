# Chaining optional arguments

This example shows the behavior of Fortran's optional arguments when chained together.

The main program calls the function _test1_ with and without an argument. _test1_ then uses
this argument, without checking if it is __present__, to _test2_. _test2_ then evaluates 
__present(arg)__ which is the true state of the argument passed inside of _main_.




