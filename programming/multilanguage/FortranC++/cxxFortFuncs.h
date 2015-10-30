#ifndef _CXXFORTFUNCS_H
#define _CXXFORTFUNCS_H

//=============================================================================
//
//                      Declarations for Fortran functions.
// This header file acts like a Fortran interface for the Fortran
// subroutines/functions defined in cxxFortFuncs.F90.
//
// NOTE:
//     After compilation name mangling, our original "fortranPrintID" function
//     will be named "fortranprintid_". However, our use of bind(C,name='...')
//     when defining "fortranPrintID_bound" allows it to retain its true name.
//=============================================================================
#include "BoxClass.h"

extern"C"
{
    void fortranprintid_(int*);
    void fortranPrintID_bound(int*);
    void fortranSayHello();
    void fortranSetID(BoxClass*, int*);
}

#endif
