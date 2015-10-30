!!=============================================================================
!!               Interfaces for C++ functions (akin to C++ headers)
!!
!! This interface module is used to provide the proper Fortran interfaces for
!! C++ functions defined in cxxFuncs.cxx.
!!=============================================================================
module cxxFuncsInterface
    use, intrinsic :: iso_c_binding
    implicit none

    interface
        subroutine sayHello() bind(C,name='sayHello')
            use iso_c_binding
        end subroutine sayHello
    end interface

end module cxxFuncsInterface
