#include<stdio.h>


int main(){
    FILE *fd = fopen("tmp.txt","w");
    char s[] = "REDIS";
    fwrite(s,sizeof(s),5,fd);
}
