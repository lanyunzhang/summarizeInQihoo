#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc ,char* argv[]){
    struct stat *buf = malloc(sizeof(struct stat));
    stat(argv[1],buf);

    chmod(argv[1],buf->st_mode|S_IXOTH);
    return 0;
}
