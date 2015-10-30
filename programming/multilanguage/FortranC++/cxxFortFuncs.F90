
    !!=============================================================================
    !!                                  Interfaces
    !!=============================================================================


    !!=============================================================================
    !!
    !!                            Print an integer.
    !!
    !! NOTE:
    !!     After compilation, the name will be mangled. This includes both
    !!     appended characters (e.g. '_'), and may be converted to all
    !!     lowercase. With gfortran 4.8.3, the final compiled version is named
    !!     "fortranprintid_".
    !!=============================================================================
    subroutine fortranPrintID(ID)
        implicit none
        integer, intent(in) :: ID
        write(*,'(a,i5)') '[fortranPrintID] ID is: ', ID
    end subroutine fortranPrintID

    !!=============================================================================
    !!
    !!                            Print an integer
    !!
    !! NOTE:
    !!     By using bind(C,name='...'), we can force the compiled name in the
    !!     object file. After compilation, this will be named "fortranPrintID_bound",
    !!     which is
    !!=============================================================================
    subroutine fortranPrintID_bound(ID) bind(C,name='fortranPrintID_bound')
        implicit none
        integer, intent(in) :: ID
        write(*,'(a,i5)') '[fortranPrintID_bound] ID is: ', ID
    end subroutine fortranPrintID_bound

    !!=============================================================================
    !!
    !!                        Call the C++ function sayHello
    !!
    !!=============================================================================
    subroutine fortranSayHello() bind(C,name='fortranSayHello')
        use, intrinsic :: iso_c_binding
        use cxxFuncsInterface, ONLY: sayHello
        implicit none
        write(*,'(a,i5)') '[fortranSayHello] Calling C++ sayHello'
        call sayHello()
    end subroutine fortranSayHello

    !!=============================================================================
    !!
    !!    C++-available subroutine for setting the ID of a BoxClass instance
    !!    from within Fortran. This uses the interface "setID" which is defined
    !!    in BoxClass_module. This, in turn, is bound to the BoxClass Fortran API
    !!    function "setID_fortAPI".
    !!
    !!=============================================================================
    subroutine fortranSetID(boxPtr, ID) bind(C,name='fortranSetID')
        use iso_c_binding, ONLY: C_int, C_ptr
        use BoxClass_module, ONLY: setID
        implicit none
        type(C_ptr) :: boxPtr
        integer(C_int) :: ID

        write(*,'(a,i5)') '[fortranSetID] Calling BoxClass API setID'
        call setID(boxPtr, ID)
    end subroutine fortranSetID
