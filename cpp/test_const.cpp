#include "test_const.h"
#include<iostream>
using namespace std;

void test_const::resize(int sz){
      cout<<"resize"<<endl; 
}

test_const::test_const(const test_const& tc){
    cout<<"copy constructor"<<endl;
}

test_const& test_const::operator=(const test_const& tc){
    if(&tc != this){
        cout<<"not equal"<<endl;
        this->setX(tc.getX());
    }else{
        cout<<"equal"<<endl;
    }
    return *this;
}

