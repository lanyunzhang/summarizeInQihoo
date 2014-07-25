#include<stdio.h>

#define CHANGE(b) do { \
   b=5;	               \
} while(0);

void main(){
  	
    int c=4;
    CHANGE(c); 
    printf("%d\n",c);
}

/** the difference between function and macro */
