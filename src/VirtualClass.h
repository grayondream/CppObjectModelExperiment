#pragma once
#include <iostream>
#include "utils.h"
#include <cstdint>

class VirtualClass{
public:
    VirtualClass(){
        void *p = fetchRunningFuncAddress<0x16>();
        OS_ADDR(VirtualClass::VirtualClass, p);
    }

    virtual ~VirtualClass(){
        void *p = fetchRunningFuncAddress<0xe>();
        OS_ADDR(VirtualClass::~VirtualClass, p);
    }

    virtual void vfunc1(){
        std::cout<<"Virtual Class virtual function 1"<<std::endl;
    }

    virtual void vfunc2(){
        std::cout<<"Virtual Class virtual function 2"<<std::endl;
    }

    void print(){
        OS_CLS_ADDR(*this, VirtualClass);
        OS_CLS_SIZE(VirtualClass);
        OS_CLS_ALIGIN_SIZE(VirtualClass);
        OS_CLS_MEMBER_VAL_ADDR((*this), _vcBoolVal);
        paresVtp((const void**)this, 2);
    }

    bool _vcBoolVal{};
};