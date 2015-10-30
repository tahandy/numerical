#ifndef _BOXCLASS_H
#define _BOXCLASS_H

//=============================================================================
//        Simple demo class to use for testing C++ <-> Fortran bindings
//=============================================================================
class BoxClass
{
    private:
        int ID;

    public:
        BoxClass();
        ~BoxClass();

        void setID(int inputID);
        int  getID();
};

#endif
