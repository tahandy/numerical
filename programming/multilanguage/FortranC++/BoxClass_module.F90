!!=============================================================================
!!                    Interfaces for the BoxClass Fortran API
!!
!!  This module+interfaces provide the interfaces required to call the BoxClass
!!  Fortran API.
!!=============================================================================
module BoxClass_module
    use, intrinsic :: iso_c_binding
    implicit none

    interface
        subroutine setID(boxPtr, ID) bind(C,name='setID_fortAPI')
            use iso_c_binding, ONLY: C_int, C_ptr
            type(C_ptr) :: boxPtr
            integer(C_int) :: ID
        end subroutine setID
    end interface

end module BoxClass_module
