//=============================================================================
//
//  Primary driver for demonstrating the implementation of C++ <-> Fortran
//  bindings, including passing class objects.
//
//=============================================================================

#include <iostream>
#include "BoxClass.h"
#include "cxxFuncs.h"
#include "cxxFortFuncs.h"

int main(int argc, char const *argv[])
{
    // Setup some variables for testing
    int ID = 7;
    BoxClass* box = new BoxClass();

    // Demonstrate name-mangling. With gfortran 4.8.3 the Fortran subroutine
    // "fortranPrintID" is mangled to "fortranprintid_". However, if we
    // use the "bind" directives cxxFortFuncs.F90, we can ensure
    // that "fortranPrintID_bound" retains its name through the compilation
    // process.
    fortranprintid_(&ID);
    fortranPrintID_bound(&ID);

    // Call a Fortran subroutine, "fortranSayHello", which calls the C++
    // function "sayHello"
    fortranSayHello();

    // Pass a box object into Fortran, set its ID using the BoxClass Fortran
    // API, and then check that its ID has been properly stored.
    std::cout<<"[cxxmain] Before fortranSetID: box->ID = "<<box->getID()<<std::endl;
    fortranSetID(box,&ID);
    std::cout<<"[cxxmain] After fortranSetID: box->ID = "<<box->getID()<<std::endl;
}
