#include "utils.h"

void* fetchRunningFuncAddress(){
    //!TODO:此处的代码不可移植
    uint64_t rbp{};
    asm("\t movq 8(%%rbp),%0" : "=r"(rbp));
    return (void*)(rbp - 0x11);
}