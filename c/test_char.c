#include<stdio.h>

/** test if the char different with unsigned char */
/** is different if for compute , the "01..0" is same */
void main(){

    int m = 193;
    char c = m;
    unsigned char uc = m;
    signed char sc = m;

    if(  c & 0xE1) printf("char c\n");
    if( uc & 0xE1) printf("unsigned char uc\n");
    if( sc & 0xE1) printf("signed char sc\n");
}
