#pragma
#include "VirtualClass.h"

class VirtualDiamandLeft : virtual public VirtualClass{
public:
    virtual void vfunc1() override{
        std::cout<<"[**] VirtualDiamandLeft Class virtual function 1"<<std::endl;
    }

    void print(int n = 3){
        VirtualClass::print(n);
        OS_CLS_ADDR(*this, VirtualDiamandLeft);
        OS_CLS_SIZE(VirtualDiamandLeft);
        OS_CLS_ALIGIN_SIZE(VirtualDiamandLeft);
        OS_CLS_MEMBER_VAL_ADDR((*this), _vdlBoolValue);
    }

    bool _vdlBoolValue{};
};

class VirtualDiamandRight : virtual public VirtualClass{
public:
    virtual void vfunc2() override{
        std::cout<<"[**] VirtualDiamandRight Class virtual function 2"<<std::endl;
    }

    void print(int n = 3){
        VirtualClass::print(n);
        OS_CLS_ADDR(*this, VirtualDiamandRight);
        OS_CLS_SIZE(VirtualDiamandRight);
        OS_CLS_ALIGIN_SIZE(VirtualDiamandRight);
        OS_CLS_MEMBER_VAL_ADDR((*this), _vdrBoolValue);
    }
    bool _vdrBoolValue{};
};

typedef void(*VoidFunc)(void);
void paresVvtp(const void **p, const int cnt){
    std::cout<<"pares vtptr from this function"<<std::endl;

    void **vptr = (void**)*(void**)(p);
    std::type_info *info = (std::type_info*)(vptr[-1]);
    std::cout<<"current class's typeinfo name:"<<info->name()<<std::endl;
    std::cout<<"call virtual function from virtual pointer table"<<std::endl;
    for(int i = 2;i < 2 + cnt;i ++){
        VoidFunc func = (VoidFunc)vptr[i];
        func();
    }
}

class VirtualMultiDiamand : public VirtualDiamandLeft, public VirtualDiamandRight{
public:
    virtual void vc1func() override{
        std::cout<<"[**] VirtualMultiDiamand Class virtual function vc1func"<<std::endl;
    }

    void print(int n = 3){
        //VirtualDiamandLeft::print(1);
        //VirtualDiamandRight::print(1);
        OS_CLS_ADDR(*this, VirtualMultiDiamand);
        OS_CLS_SIZE(VirtualMultiDiamand);
        OS_CLS_ALIGIN_SIZE(VirtualMultiDiamand);
        OS_CLS_MEMBER_VAL_ADDR((*this), _vcBoolVal);
        int64_t offset = 0;
        {
            void **vptr = (void**)*(void**)(this);
            std::type_info *info = (std::type_info*)(vptr[-1]);
            std::cout<<"current class's typeinfo name:"<<info->name()<<std::endl;
            std::cout<<"call virtual function from virtual pointer table"<<std::endl;
            offset = (int64_t)vptr[-3];
            {
                VoidFunc func = (VoidFunc)vptr[0];
                func();
            }
            {
                VoidFunc func = (VoidFunc)vptr[3];
                func();
            }
        }
        {
            void **vptr = (void**)*(void**)(((uint64_t)this) + 0x10);
            std::type_info *info = (std::type_info*)(vptr[-1]);
            std::cout<<"current class's typeinfo name:"<<info->name()<<std::endl;
            std::cout<<"call virtual function from virtual pointer table"<<std::endl;
            {
                VoidFunc func = (VoidFunc)vptr[0];
                func();
            }
        }
        {
            void **vptr = (void**)*(void**)(((uint64_t)this) + offset);
            std::type_info *info = (std::type_info*)(vptr[-1]);
            std::cout<<"current class's typeinfo name:"<<info->name()<<std::endl;
            std::cout<<"call virtual function from virtual pointer table"<<std::endl;
            {
                VoidFunc func = (VoidFunc)vptr[0];
            }
        }
    }
    bool vmdBoolValue{};
};