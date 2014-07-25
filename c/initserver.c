#include<errno.h>
#include<sys/socket.h>
#include<stdio.h>

#define MAXSLEEP 128

int initserver(int type,const struct sockaddr* addr,socklen_t alen,int qlen){
    int fd;
    int err = 0;

    fd = socket(addr->sa_family,type,0);
    if(fd < 0){
        printf("%d\n is little 0 ",fd);
    }
    bind(fd,addr,alen);
    if(type == SOCK_STREAM || type == SOCK_SEQPACKET){
        listen(fd,qlen);
    }
    return fd;
}

int connect_retry(int sockfd,const struct sockaddr* addr,socklen_t alen){
    int nsec;

    for(nsec = 1;nsec <= MAXSLEEP ;nsec <<=1){
        if(connect(sockfd,addr,alen) == 0){
            return 0;
        }
        if(nsec <= MAXSLEEP/2)
            sleep(nsec);
    }
    return -1;
}
