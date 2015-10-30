#ifndef _CXXFUNCS_H
#define _CXXFUNCS_H

//=============================================================================
//              Declare C++ functions to be called from Fortran.
//
//    Name-mangling during compilation will add additional tokens to the
//    function name (e.g. sayHello -> _Z8sayHellov). By telling the compiler
//    these should be 'extern "C"', we can fix this problem. Not doing so
//    makes it uncertain how to call a function in Fortran, since the appended
//    tokens are compiler-dependent.
//=============================================================================
extern "C"
{
    void sayHello();
}

#endif
