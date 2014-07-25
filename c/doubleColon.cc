#include<stdio.h>
#include<cstring>
#include "doubleColon.h"
using namespace zly;

void test_colon::printf(char* msg){
    char* quit="quit";
    if(!strcmp(msg,quit)){
        ::printf("quit\n");
        return;
    }
    ::printf("msg=%s\n",msg);
    printf("quit");
}

// :: 默认首先调用全局的函数，如果在本 namespace 中有重名的函数或者类

