#include<stdio.h>

int age = 27;
extern void func(int a);

void main(){
    func(5);
    printf("%d\n",age);
}

/** test for external linkage. */
