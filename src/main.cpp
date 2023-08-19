#include <iostream>
#include <tuple>
#include "utils.h"
#include "ClassOs.h"

int SimpleClass::staticIntMember = 33;


int main(int argc, char **argv){
    std::cout<<"hello cpp"<<std::endl;
    std::tuple objs = {
        SimpleClass{}
        };

    auto printFunc = [](auto&& v) { 
        std::cout << v << std::endl; 
    };

    TupleTraverser()(objs, printFunc);

    return 0;
}