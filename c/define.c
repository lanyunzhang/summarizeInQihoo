#include<stdio.h>

#define swap_value(a,b) { a = a - b; b = b + a ; a = b - a ;}

void main(){
    int a = 5 + 4 ;
    int b = 6;

    swap_value(a,b);
    printf("%d - %d\n",a,b);
}

