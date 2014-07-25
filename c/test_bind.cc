#include<boost/bind.hpp>
#include<boost/function.hpp>
#include<stdio.h>

typedef boost::function<void()> callback;

void function(callback cb){
    cb();
}

void print(){
    printf("this is a bind function\n");
}

int main(){
    function(boost::bind(print));   
    return 0;
}

// test bind , function , use bind to set callback
