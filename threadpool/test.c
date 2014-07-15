#include<stdio.h>
#include "threadpool.h"

void task(void* arg){
    printf("Hello world\n");
}

void main(){
   int i = 0;
   ThreadPool* tp = threadpool_create(4,15);
   for(i=0;i<10;i++){ 
       threadpool_add_task(tp,task,NULL);
   }
    
   /*while(1){
        if(tp != NULL){
            if(getThreadNum(tp) > 0 ){
                continue;
            }
            break;
        }
   }*/
   while(getThreadNum(tp) != 10);
}
