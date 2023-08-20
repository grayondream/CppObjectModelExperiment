#pragma once

#include "Simple.h"

class SimpleMultiInherit : public SimpleClass, public SimpleClass2{
public:
    SimpleMultiInherit(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleMultiInherit::SimpleMultiInherit, p);
    }

    ~SimpleMultiInherit(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleMultiInherit::~SimpleMultiInherit, p);
    }

    void print(){
        SimpleClass::print();
        SimpleClass2::print();
        OS_CLS_ADDR(*this, SimpleMultiInherit);
        OS_CLS_SIZE(SimpleMultiInherit);
        OS_CLS_ALIGIN_SIZE(SimpleMultiInherit);
        OS_CLS_MEMBER_VAL_ADDR((*this), _ssiNonStaticBoolMem);
    }

    bool _ssiNonStaticBoolMem{false};
};