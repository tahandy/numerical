//=============================================================================
//                     Implementation of the demo BoxClass
//=============================================================================

#include "BoxClass.h"
#include <iostream>

BoxClass::BoxClass()
{
    this->setID(-1);
}

BoxClass::~BoxClass() {}

void BoxClass::setID(int inputID)
{
    this->ID = inputID;
    std::cout<<"[BoxClass::setID] Set ID to "<<this->ID<<std::endl;
}

int  BoxClass::getID()
{
    std::cout<<"[BoxClass::setID] Retrieving ID with value "<<this->ID<<std::endl;
    return this->ID;
}


