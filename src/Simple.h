#pragma once

#include <iostream>
#include "utils.h"
#include <cstdint>


class SimpleClass{
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

    void print(){
        OS_CLS_ADDR(*this, SimpleClass);
        OS_CLS_SIZE(SimpleClass);
        OS_CLS_ALIGIN_SIZE(SimpleClass);
        OS_CLS_MEMBER_VAL_ADDR((*this), _nonStaticIntMember);
        OS_CLS_MEMBER_VAL_ADDR((*this), _nonStaticBoolMember);
        OS_CLS_MEMBER_VAL_ADDR((*this), _nonStaticShortMember);
        OS_CLS_STATIC_MEMBER_VAL_ADDR(SimpleClass, staticIntMember);
    }

    void print(int){
        OS_CLS_ADDR(*this, SimpleClass);
        OS_CLS_SIZE(SimpleClass);
        OS_CLS_ALIGIN_SIZE(SimpleClass);
        OS_CLS_MEMBER_VAL_ADDR((*this), _nonStaticIntMember);
        OS_CLS_MEMBER_VAL_ADDR((*this), _nonStaticBoolMember);
        OS_CLS_MEMBER_VAL_ADDR((*this), _nonStaticShortMember);
        OS_CLS_STATIC_MEMBER_VAL_ADDR(SimpleClass, staticIntMember);
        OS_CLS_MEMBER_FUNC_ADDR(SimpleClass, staticFunc);
        OS_CLS_MEMBER_FUNC_ADDR(SimpleClass, nonStaticFunc);
    }

    int _nonStaticIntMember{44};
    bool _nonStaticBoolMember{false};
    short _nonStaticShortMember{};
    static int staticIntMember;
};


class SimpleClass2{
public:
    SimpleClass2(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleClass2::SimpleClass2, p);
    }
    ~SimpleClass2(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleClass2::~SimpleClass, p);
    }

    static void staticFunc(){}
    void nonStaticFunc() const{
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleClass2::nonStaticFunc, p);
    }

    void print(){
        OS_CLS_ADDR(*this, SimpleClass2);
        OS_CLS_SIZE(SimpleClass2);
        OS_CLS_ALIGIN_SIZE(SimpleClass2);
        OS_CLS_MEMBER_VAL_ADDR((*this), _nonStaticBoolMember);
    }

    bool _nonStaticBoolMember{};
};