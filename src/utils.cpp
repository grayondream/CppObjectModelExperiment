#include "utils.h"
#include <iostream>

typedef void(*VoidFunc)(void);

void paresVtp(const void **p, const int cnt){
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
