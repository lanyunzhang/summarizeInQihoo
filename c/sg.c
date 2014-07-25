#include<stdio.h>
#include<string.h>
#include<stdlib.h>

union m_union {
    int i;
    char a[2]; // little endian
};

void main(){
    int (*b)[10][10]; // array pointer , pointer array

    int len_int = sizeof(int);
    int len_char = sizeof(char);

    printf("%d\n",len_int);
    printf("%d\n",len_char);
    printf("%d\n",sizeof(b));

    int* m = 0;
    char* n = "abc";
    printf("%d\n",sizeof(m));
    printf("%d\n",sizeof(n));

    union m_union mu; 
    mu.i = 0;
    mu.a[0] = 10;
    mu.a[1] = 1;

    printf("%d\n",mu);

    //printf("%p\n",NULL);
    char a[2],bbb[2];
    strcpy(bbb,"aaaa");

    int  aa[2]={0};
    free(aa); // attempt to free ... 
}
/** bagging boosting PLRS CRT */
