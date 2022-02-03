#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Purging a double linked list composed by integer values when an element is not divisible by a given number. 

*/

typedef struct node *link;
struct node {
    int val;
    link prev;
    link next;
};

typedef struct list *LIST;
struct list {
    link head;
};

void purge(LIST l, int div);
link deleteNode(link head, link node);
link listInsHead(int val, link next);


int main(){
    int div=3;

    LIST l = malloc(sizeof(*l));
    l->head = malloc(sizeof(link)); //inizialmente vuota

    l->head = listInsHead(10,l->head);
    l->head = listInsHead(9,l->head);
    l->head = listInsHead(5,l->head);
    l->head = listInsHead(9,l->head);
    l->head = listInsHead(6,l->head);
    l->head = listInsHead(5,l->head);
    l->head = listInsHead(5,l->head);

    for(link t=l->head; t!=NULL; t=t->next){
        printf(" %d -> ",t->val);
    }
    printf("\n");

    purge(l,div);

    return 0;
}

link deleteNode(link head, link node){
    link t;

    //head
    if(node==head){
        t = head;
        head = head->next;
        head->prev = NULL; 
    }

    //middle
    if(node->prev!=NULL && node->next!=NULL){
        t = node;
        node->prev->next = node->next;
    }

    //tail
    if(node->next==NULL){
        t = node;
        node->prev->next = NULL;
    }

    free(t);
    return head;
}

void purge(LIST l, int div){

    link x;

    for(x=l->head; x!=NULL; x=x->next){
        if(x->val%div != 0){
            l->head = deleteNode(l->head,x);
        }
    }

    for(x=l->head; x!=NULL; x=x->next){
        printf("%d ->",x->val);
    }
    printf("\n");


    return;
}

link listInsHead(int val, link next){
    link x = malloc(sizeof(*x));

    if(x==NULL){
        return NULL;
    }

    x->val = val;
    x->next = next; //come prossimo gli passo la testa di prima
    x->prev = NULL; //è la testa

    x->next->prev = x; 

    return x;
}
