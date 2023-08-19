#pragma once
#include <iostream>
#include "utils.h"
#include "Simple.h"

std::ostream& operator<<(std::ostream &os, const SimpleClass &obj){
    os<<"Simple Class:"<<std::endl;
    OS_CLS_SIZE(SimpleClass);
    OS_CLS_ALIGIN_SIZE(SimpleClass);
    SimpleClass cls;
    OS_CLS_ADDR(cls);

    OS_CLS_MEMBER_VAL_ADDR(cls, _nonStaticIntMember);
    OS_CLS_MEMBER_VAL_ADDR(cls, _nonStaticBoolMember);
    OS_CLS_MEMBER_VAL_ADDR(cls, _nonStaticShortMember);
    OS_CLS_STATIC_MEMBER_VAL_ADDR(SimpleClass, staticIntMember);
    OS_CLS_MEMBER_FUNC_ADDR(SimpleClass, staticFunc);
    OS_CLS_MEMBER_FUNC_ADDR(SimpleClass, nonStaticFunc);
    cls.nonStaticFunc();
    cls.~SimpleClass();
    os<<std::endl;   
    return os; 
}