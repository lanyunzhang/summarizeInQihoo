#include<fcntl.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<string.h>


int main(int argc ,char* argv[]){
    int fdin,fdout;
    void *src,*dst;
    struct stat statbuf;

    fdin = open(argv[1],O_RDONLY);
    fdout = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP,S_IROTH);
    fstat(fdin,&statbuf);
    lseek(fdout,statbuf.st_size - 1,SEEK_SET);
    write(fdout,"",1);

    src = mmap(0,statbuf.st_size,PROT_READ,MAP_SHARED,fdin,0);
    dst = mmap(0,statbuf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fdout,0);

    memcpy(dst,src,statbuf.st_size);
    return 0;
}

