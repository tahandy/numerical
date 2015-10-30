#ifndef _BOXCLASS_FORTAPI_H
#define _BOXCLASS_FORTAPI_H

//=============================================================================
//          External declarations for BoxClass Fortran API functions
//
// Functions declared here are used to wrap C++ BoxClass member functions
// functionality in a form suitable for use in Fortran code.
//=============================================================================
#include "BoxClass.h"

extern "C"
{
    void setID_fortAPI(BoxClass* obj, int& ID);
    int  getID_fortAPI(BoxClass* obj);
}

#endif
