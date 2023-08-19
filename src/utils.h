#pragma once
#include <type_traits>
#include <tuple>
#include <iomanip>

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

#define OS_OUT std::cout<<std::left<<std::setw(50)
#define OS_END std::endl

#define OS_CLS_SIZE(cls) OS_OUT<<"size of class(bytes):"<<sizeof(cls)<<OS_END;
#define OS_CLS_ALIGIN_SIZE(cls) OS_OUT<<"align of class(bytes):"<<std::alignment_of_v<cls><<OS_END;
#define OS_CLS_ADDR(cls) OS_OUT<<"address of class:"<<std::addressof(cls)<<OS_END;
#define OS_CLS_MEMBER_VAL_ADDR(cls, val) OS_OUT<<"member address "#val" :"<<std::addressof(cls.val)<<OS_END;
#define OS_CLS_STATIC_MEMBER_VAL_ADDR(cls, val) OS_OUT<<"static function address "#val" :"<<std::addressof(cls::val)<<OS_END;
#define OS_CLS_MEMBER_FUNC_ADDR(cls, func) OS_OUT<<"function addres "#func" :"<<func2addr(&cls::func)<<OS_END;

#define PRINT_REG(reg, out) { asm volatile("mov %%"#reg", %[var]" : [var] "=r" (out));}