#pragma once
#include "VirtualClass.h"

class VirtualSingleInherit : public VirtualClass{
public:
    VirtualSingleInherit(){
        void *p = fetchRunningFuncAddress<0x16>();
        OS_ADDR(VirtualSingleInherit::VirtualSingleInherit, p);
    }

    virtual ~VirtualSingleInherit(){
        void *p = fetchRunningFuncAddress<0xe>();
        OS_ADDR(VirtualSingleInherit::~VirtualSingleInherit, p);
    }

    virtual void vfunc1() override{
        std::cout<<"VirtualSingleInhert Class virtual function 1"<<std::endl;
    }

    virtual void vfunc3(){
        std::cout<<"VirtualSingleInhert Class virtual function 3"<<std::endl;
    }

    void print(int n = 3){
        VirtualClass::print(2);
        OS_CLS_ADDR(*this, VirtualSingleInherit);
        OS_CLS_SIZE(VirtualSingleInherit);
        OS_CLS_ALIGIN_SIZE(VirtualSingleInherit);
        OS_CLS_MEMBER_VAL_ADDR((*this), _vsiBoolValue);
        paresVtp((const void**)this, n);
    }
    bool _vsiBoolValue{};
};
