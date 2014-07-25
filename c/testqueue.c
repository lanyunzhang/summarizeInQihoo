#include<stdio.h>
#include<stdlib.h>
#include "nc_queue.h"


int main(){

    SLIST_HEAD(slist,entry) head;
    struct slist* headp; // head pointer.
    struct entry{
        int value;
        SLIST_ENTRY(entry) entries;
    }*n1,*n2,*n3,*n4,*np;

    SLIST_INIT(&head);
    n1 = malloc(sizeof(struct entry));
    n1->value = 1;
    SLIST_INSERT_HEAD(&head,n1,entries);

    n2 = malloc(sizeof(struct entry));
    n2->value = 2;
    SLIST_INSERT_AFTER(n1,n2,entries);

    n3 = malloc(sizeof(struct entry));
    n3->value = 3;
    SLIST_INSERT_HEAD(&head,n3,entries);

    n4 = malloc(sizeof(struct entry));
    n4->value = 4;
    SLIST_INSERT_AFTER(n3,n4,entries);

    for (np = head.slh_first; np != NULL; np = np->entries.sle_next)
        printf("single list %d\n",np->value);

    /* tail queue  has pointer in the first and in the last */
   
    // redeclaration struct list_node *th1
    STAILQ_HEAD(tailhead,list_node) h;   
    struct tailhead* hp;

    struct list_node{
        int value;
        STAILQ_ENTRY(list_node) lns;
    }*th1,*th2,*th3,*th4,*tp;

    STAILQ_INIT(&h);

    th1 = malloc(sizeof(struct list_node));
    th1->value = 1;

    th2 = malloc(sizeof(struct list_node));
    th2->value = 2;

    th3 = malloc(sizeof(struct list_node));
    th3->value = 3; 

    th4 = malloc(sizeof(struct list_node)); 
    th4->value = 4;

    STAILQ_INSERT_HEAD(&h,th1,lns);
    STAILQ_INSERT_AFTER(&h,th1,th2,lns);
    STAILQ_INSERT_AFTER(&h,th2,th3,lns);
    STAILQ_INSERT_TAIL(&h,th4,lns);
    
    for(tp = h.stqh_first ; tp !=NULL;tp = tp->lns.stqe_next)
        printf("tail queue %d\n",tp->value);
    
    /* double linked list , has prev and next pointer */
    
    LIST_HEAD(dlist,node) dh;
    struct dlist* dhhead;

    struct node{
        int value;
        LIST_ENTRY(node) nodes;
    }*nd1,*nd2,*nd3,*nd4,*nd;

    LIST_INIT(&dh);

    nd1 = malloc(sizeof(struct node));
    nd1->value = 1;

    nd2 = malloc(sizeof(struct node));
    nd2->value = 2;

    nd3 = malloc(sizeof(struct node));
    nd3->value = 3;

    nd4 = malloc(sizeof(struct node));
    nd4->value = 4;

    LIST_INSERT_HEAD(&dh,nd1,nodes);
    LIST_INSERT_AFTER(nd1,nd2,nodes);
    LIST_INSERT_AFTER(nd2,nd3,nodes);
    LIST_INSERT_BEFORE(nd3,nd4,nodes);

    for(nd = dh.lh_first;nd != NULL; nd = nd->nodes.le_next)
        printf("list %d\n",nd->value);

    int res = (*dh.lh_first->nodes.le_prev)->value;
    printf("head prev value %d\n",res);
    return 0;
}

// using macro to implemention many data structure , but aha I can't use it 
// properly.
// man queue , then get the use example.
