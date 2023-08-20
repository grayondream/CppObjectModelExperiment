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
        std::cout<<"[**] Virtual Class virtual function 1"<<std::endl;
    }

    virtual void vfunc2(){
        std::cout<<"[**] Virtual Class virtual function 2"<<std::endl;
    }

    virtual void vc1func(){
        std::cout<<"[**] Virtual Class virtual function vc1func"<<std::endl;
    }

    void print(int n = 3){
        OS_CLS_ADDR(*this, VirtualClass);
        OS_CLS_SIZE(VirtualClass);
        OS_CLS_ALIGIN_SIZE(VirtualClass);
        OS_CLS_MEMBER_VAL_ADDR((*this), _vcBoolVal);
        paresVtp((const void**)this, n);
    }

    bool _vcBoolVal{};
};


class VirtualClass2{
public:
    VirtualClass2(){
        void *p = fetchRunningFuncAddress<0x16>();
        OS_ADDR(VirtualClass2::VirtualClass2, p);
    }

    virtual ~VirtualClass2(){
        void *p = fetchRunningFuncAddress<0xe>();
        OS_ADDR(VirtualClass2::~VirtualClass2, p);
    }

    virtual void vfunc1(){
        std::cout<<"[**] VirtualClass2 Class virtual function 1"<<std::endl;
    }

    virtual void vfunc2(){
        std::cout<<"[**] VirtualClass2 Class virtual function 2"<<std::endl;
    }

    virtual void vc2func(){
        std::cout<<"[**] VirtualClass2 Class virtual function vc2func"<<std::endl;
    }

    void print(int n = 3){
        OS_CLS_ADDR(*this, VirtualClass2);
        OS_CLS_SIZE(VirtualClass2);
        OS_CLS_ALIGIN_SIZE(VirtualClass2);
        OS_CLS_MEMBER_VAL_ADDR((*this), _vcBoolVal2);
        paresVtp((const void**)this, n);
    }

    bool _vcBoolVal2{};
};