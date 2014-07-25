#include<stdio.h>

void main(){ 
    int  c = 0x0D0C0B0A;
    int* m = &c;
    printf("%d\n",*((char*)m));
    printf("%d\n",*((char*)(m)+1));
    printf("%d\n",*((char*)(m)+2));
    printf("%d\n",*((char*)(m)+3));
}

/** 3 0 0 0  */
