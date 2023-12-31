#pragma once
#include <type_traits>
#include <tuple>
#include <iomanip>
#include <iostream>

class TupleTraverser {
    template<typename T, typename Func, size_t... i>
    void execute(T&& t, Func&& f, std::index_sequence<i...>) {
        ((f(std::get<i>(t))), ...);
    }
public:
    template<typename T, typename Func>
    auto operator()(T&& t, Func&& f) {
        execute(t, f, std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<T>>>{});
    }
};

template<class Func>
void* func2addr(Func &&f){
    union {
        Func f;
        void *addr;
    } v = {f};
    return v.addr;
}

class EmptyClass{};

template<int t = 0>
void* fetchRunningFuncAddress(){
    //!TODO:此处的代码不可移植
    uint64_t rbp{};
    asm("\t movq 8(%%rbp),%0" : "=r"(rbp));
    return (void*)(rbp - 0x11 - t);
}

template<class T>
void print(){
    std::cout<<"******************CLASS SEPARETOR*************************"<<std::endl;
    T* cls = new T;
    cls->print();
    delete cls;
    std::cout<<"******************CLASS SEPARETOR*************************"<<std::endl;
}

void paresVtp(const void **p, const int cnt);

#define TO_STR(x) #x

#define OS_OUT std::cout<<std::left<<std::setw(60)
#define OS_END std::endl

#define OS_CLS_SIZE(cls) OS_OUT<<"size of class(bytes):"<<sizeof(cls)<<OS_END;
#define OS_CLS_ALIGIN_SIZE(cls) OS_OUT<<"align of class(bytes):"<<std::alignment_of_v<cls><<OS_END;
#define OS_CLS_ADDR(cls, name) OS_OUT<<"address of class " #name":"<<std::addressof(cls)<<OS_END;
#define OS_CLS_MEMBER_VAL_ADDR(cls, val) OS_OUT<<"member address "#val":"<<std::addressof(cls.val)<<OS_END;
#define OS_CLS_STATIC_MEMBER_VAL_ADDR(cls, val) OS_OUT<<"static function address "#val":"<<std::addressof(cls::val)<<OS_END;
#define OS_CLS_MEMBER_FUNC_ADDR(cls, func) OS_OUT<<"function addres "#func":"<<func2addr(&cls::func)<<OS_END;
#define OS_ADDR(str, addr) OS_OUT<<"address of "#str":"<<addr<<OS_END;

#define PRINT_REG(reg, out) { asm volatile("mov %%"#reg", %[var]" : [var] "=r" (out));}