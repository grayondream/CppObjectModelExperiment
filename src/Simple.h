#pragma once

#include <iostream>
#include "utils.h"
#include <cstdint>

class SimpleClass{
    friend std::ostream& operator<<(std::ostream &os, const SimpleClass &cls);
public:
    SimpleClass(){}
    ~SimpleClass(){}

    static void staticFunc(){}
    void nonStaticFunc() const{
        std::cout<<"a"<<std::endl;
        uint64_t val{};
        asm("\t movq %%rbp,%0" : "=r"(val));
        printf("%p\n", val);
    }

    int _nonStaticIntMember{44};
    bool _nonStaticBoolMember{false};
    short _nonStaticShortMember{3};
    static int staticIntMember;
};


