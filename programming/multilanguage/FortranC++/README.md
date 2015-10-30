# Interfacing C++ and Fortran
The example here demonstrates how to interface C++ and Fortran functions and includes:

- Calling simple C++/Fortran functions from Fortran/C++
- Using **extern "C"** and iso_c_binding's **bind** to avoid name-mangling during compilation
- Creating and using a Fortran API for a C++ class

## BoxClass.{cxx,h}

A simple demonstration C++ class with getters and setters.

## BoxClass_fortAPI.{cxx,h}

C++ functions to be used when calling BoxClass member functions from inside Fortran.

## BoxClass_module.F90

Fortran interfaces for the BoxClass_fortAPI C++ functions.

## cxxFuncs.{cxx,h} cxxFuncsInterface.F90

Simple C++ functions for use in Fortran, plus the Fortran interfaces required to use them.

## cxxFortFuncs.{F90,h}

Fortran functions which should be called from the C++ driver. These perform the calling of cxxFuncs and
the BoxClass Fortran API.

## main.cxx

Driver program for demonstrating function calls.



