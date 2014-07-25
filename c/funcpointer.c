#include<stdio.h>
#include<stdlib.h>


typedef int (*zly)(int,int);

struct fuc{
    zly name;
};

int zzc(int a,int b){
    return b - a;
}

int mfc(zly z,int a,int b){
    return z(a,b);
    //return (*z)(a,b);
}

int main(){
    struct fuc *s = malloc(sizeof(struct fuc));    
    //s->name = &zzc;
    s->name = zzc;
    int res = mfc(s->name, 5,10); 
    printf("%d\n",res);

    // two has same address. 
    printf("%x -- %x \n",&zzc,zzc);
    
}

// test two ways about function pointer, found that 
// there is no difference between them.
