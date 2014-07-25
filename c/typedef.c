#include<stdio.h>

typedef char* charp;
int main(){
    char c = 'z';
    const charp p=&c;

    char m = 'm';
    //p = &m;
    //p='m';
    // compare
    
    const char* q = "zh";
    char* s = "zhang";
    q = s;
    printf("%s\n",q);

}
// line 6 ,p is const
    
