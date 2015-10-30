//=============================================================================
//  Definitions for simple C++ functions to be called from inside Fortran.
//=============================================================================

#include "cxxFuncs.h"
#include <iostream>

void sayHello()
{
    std::cout<<"[sayHello] Hello!"<<std::endl;
}
