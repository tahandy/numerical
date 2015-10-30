//=============================================================================
//             Implementations of BoxClass Fortran API functions
//
// Functions defined here should wrap the appropriate member functions of
// BoxClass. These functions should be relatively simple, and stick to just
// calling the actual member functions using the supplied object pointer
// and supplemental arguments.
//=============================================================================

#include "BoxClass_fortAPI.h"

void setID_fortAPI(BoxClass* obj, int& ID)
{
    obj->setID(ID);
}


int  getID_fortAPI(BoxClass* obj)
{
    return obj->getID();
}
