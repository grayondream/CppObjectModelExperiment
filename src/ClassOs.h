#pragma once
#include <iostream>
#include "utils.h"
#include "Simple.h"
#include "SimpleSingleInherit.h"
#include "SimpleMultiInherit.h"
#include "SimpleDiamandInherit.h"
#include "VirtualClass.h"

template<class T>
void print(){
    std::cout<<"******************CLASS SEPARETOR*************************"<<std::endl;
    T* cls = new T;
    cls->print();
    delete cls;
    std::cout<<"******************CLASS SEPARETOR*************************"<<std::endl;
}