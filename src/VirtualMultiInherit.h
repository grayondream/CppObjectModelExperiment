#pragma
#include "VirtualClass.h"

class VirtualMultiInherit : public VirtualClass, public VirtualClass2{
public:
    virtual void vfunc1() override{
        std::cout<<"[**] VirtualMultiInherit Class virtual function 1"<<std::endl;
    }
    
    virtual void vc1func() override{
        std::cout<<"[**] VirtualMultiInherit virtual function vc1func"<<std::endl;
    }

    virtual void vc2func() override{
        std::cout<<"[**] VirtualMultiInherit Class virtual function vc2func"<<std::endl;
    }

    virtual void vmifunc(){
        std::cout<<"[**] VirtualMultiInherit Class virtual function vmifunc"<<std::endl;
    }

    void print(){
        VirtualClass::print(5);
        VirtualClass2::print(3);
        OS_CLS_ADDR(*this, VirtualMultiInherit);
        OS_CLS_SIZE(VirtualMultiInherit);
        OS_CLS_ALIGIN_SIZE(VirtualMultiInherit);
        OS_CLS_MEMBER_VAL_ADDR((*this), _vmiBoolValue);
        paresVtp((const void**)this, 5);
    }
    bool _vmiBoolValue{};
};