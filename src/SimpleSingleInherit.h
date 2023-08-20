#pragma once
#include "Simple.h"

class SimpleSingleInherit : public SimpleClass{
public:
    SimpleSingleInherit(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleSingleInherit::SimpleSingleInherit, p);
    }

    ~SimpleSingleInherit(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleSingleInherit::~SimpleSingleInherit, p);
    }

    void print(){
        SimpleClass::print();
        OS_CLS_ADDR(*this, SimpleSingleInherit);
        OS_CLS_SIZE(SimpleSingleInherit);
        OS_CLS_ALIGIN_SIZE(SimpleSingleInherit);
        OS_CLS_MEMBER_VAL_ADDR((*this), _ssiNonStaticBoolMem);
    }

    bool _ssiNonStaticBoolMem{false};
};


class SimpleSingleInherit2 : public SimpleSingleInherit{
public:
    SimpleSingleInherit2(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleSingleInherit2::SimpleSingleInherit2, p);
    }

    ~SimpleSingleInherit2(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleSingleInherit2::~SimpleSingleInherit2, p);
    }

    void print(){
        SimpleSingleInherit::print();
        OS_CLS_ADDR(*this, SimpleSingleInherit2);
        OS_CLS_SIZE(SimpleSingleInherit2);
        OS_CLS_ALIGIN_SIZE(SimpleSingleInherit2);
        OS_CLS_MEMBER_VAL_ADDR((*this), _ssiNonStaticBoolMem2);
    }

    bool _ssiNonStaticBoolMem2{false};
};