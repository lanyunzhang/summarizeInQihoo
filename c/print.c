#include<stdio.h>

int main(int argc, char *argv[]){
    int size = printf("");
    printf("%d\n",size);
    char buf[BUFSIZ] ;

    
    FILE* fp = fopen(argv[1] , "r+");
    setvbuf(fp,buf,_IOFBF,BUFSIZ);
}
