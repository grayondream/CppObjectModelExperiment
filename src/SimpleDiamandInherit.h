#pragma
#include "Simple.h"

class SimpleClassLeft : public SimpleClass{
public:
    SimpleClassLeft(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleClassLeft::SimpleClassLeft, p);
    }
    ~SimpleClassLeft(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleClassLeft::~SimpleClassLeft, p);
    }

    void print(){
        SimpleClass::print();
        OS_CLS_ADDR(*this, SimpleClassLeft);
        OS_CLS_SIZE(SimpleClassLeft);
        OS_CLS_ALIGIN_SIZE(SimpleClassLeft);
        OS_CLS_MEMBER_VAL_ADDR((*this), _simpleLeftBool);
    }
    bool _simpleLeftBool;
};

class SimpleClassRight : public SimpleClass{
public:
    SimpleClassRight(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleClassRight::SimpleClassRight, p);
    }
    ~SimpleClassRight(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleClassRight::~SimpleClassRight, p);
    }
    
    void print(){
        SimpleClass::print();
        OS_CLS_ADDR(*this, SimpleClassRight);
        OS_CLS_SIZE(SimpleClassRight);
        OS_CLS_ALIGIN_SIZE(SimpleClassRight);
        OS_CLS_MEMBER_VAL_ADDR((*this), _simpleRightBool);
    }
    bool _simpleRightBool;
};

class SimpleDiamandInherit : public SimpleClassLeft, public SimpleClassRight{
public:
    SimpleDiamandInherit(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleDiamandInherit::SimpleDiamandInherit, p);
    }
    ~SimpleDiamandInherit(){
        void *p = fetchRunningFuncAddress();
        OS_ADDR(SimpleDiamandInherit::~SimpleDiamandInherit, p);
    }

    void print(){
        SimpleClassLeft::print();
        SimpleClassRight::print();
        OS_CLS_ADDR(*this, SimpleDiamandInherit);
        OS_CLS_SIZE(SimpleDiamandInherit);
        OS_CLS_ALIGIN_SIZE(SimpleDiamandInherit);
        OS_CLS_MEMBER_VAL_ADDR((*this), _simpleDiamandBool);
    }
    bool _simpleDiamandBool;
};