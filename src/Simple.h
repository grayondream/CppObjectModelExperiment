#pragma once

#include <iostream>
#include "utils.h"
#include <cstdint>


class SimpleClass{
    friend std::ostream& operator<<(std::ostream &os, const SimpleClass &cls);
public:
    SimpleClass(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleClass::SimpleClass, p);
    }
    ~SimpleClass(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleClass::~SimpleClass, p);
    }

    static void staticFunc(){}
    void nonStaticFunc() const{
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleClass::nonStaticFunc, p);
    }

    int _nonStaticIntMember{44};
    bool _nonStaticBoolMember{false};
    short _nonStaticShortMember{3};
    static int staticIntMember;
};


