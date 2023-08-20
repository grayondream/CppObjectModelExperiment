#include <iostream>
#include <tuple>
#include "utils.h"
#include "ClassOs.h"

int SimpleClass::staticIntMember = 33;

template<class T>
void printall(){
    std::cout<<"-----------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"-----------------------------------------------------------------------------------"<<std::endl<<std::endl;
    print<T>();
}

template<class T, class... Args, typename = typename std::enable_if<sizeof...(Args) != 0, void>::type>
void printall(){
    printall<T>();
    printall<Args...>();
}

int main(int argc, char **argv){
    std::cout<<"hello cpp"<<std::endl;
    printall<   SimpleClass, 
                SimpleSingleInherit, 
                SimpleSingleInherit2,
                SimpleMultiInherit,
                SimpleDiamandInherit,
                VirtualClass>();
    return 0;
}