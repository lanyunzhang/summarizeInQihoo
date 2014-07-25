#include<stdio.h>

int main(){
    int a[3]={1,2,3};
    int* p = &a[0];
    int* q = a;


    char str[3][3] = { "abc", "def","ghi"};
    printf("%c\n",**(str+1));
    //printf("%c\n",**(str++));

    char* pi = &str[0][0];
    printf("%c\n",*++pi);

    const char* keyword[] = { "do", "for","while","each"};

    printf("%d\n",sizeof(keyword)/sizeof(keyword[0]));

}

// str++ with str + 1 is not the same question.
// sizeof(keyword[0]) is a pointer size , but the sizeof(keyword) is 
// an array of N size pointer.

