#include<stdio.h>
#include<string.h>


unsigned int siteHashCode (char *host) {
    unsigned int h=0;
    unsigned int i=0;
    int len = strlen(host);
    printf("%d\n",len); 
    printf("%s\n",host);
    while (host[i] != 0) {
        h = 37*h + host[i];
        i++;
    }
    return h; 
}

struct node{
    int a:3;
};

void main(){
    int left = 1;
    unsigned int right ;
    printf("%d\n",right);

    if( right > 1 ){
        printf("yes\n");
    }

    char* m=0;
    //printf("%s\n",m[5]);
    //int a = strlen(m);
    //printf("%d\n",a);


    char* ho = "www.popart.cn";
    char* p = 100; // 会转化为 p 的地址为 100 处
    char* p2 = 101;
    //unsigned int lens = siteHashCode(NULL);
    //unsigned int ls = siteHashCode(p);
    //printf("lens=%u\n",lens);
    printf("%p\n",ho);
    printf("%p\n",p2);

    printf("%d\n",sizeof(struct node));
}
