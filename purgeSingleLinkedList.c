#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

/* deleting nodes that do not contain elements present in the integers vector */

typedef struct node *link;
struct node {
    int val;
    link next;
};

typedef struct list *LIST;
struct list {
    link head;
};

void f(LIST L, int *v, int n);
void printList(LIST l);
link deleteNode(link head, link node);
link listInsTail(link head, int val);
link newNode(int val, link next);

int main(){

    LIST l = malloc(sizeof(*l));
    l->head = NULL;
    link x;

    int v[10] = {1,2,3};

    l->head = listInsTail(l->head,11);
    l->head = listInsTail(l->head,10);
    l->head = listInsTail(l->head,6);
    l->head = listInsTail(l->head,3);
    l->head = listInsTail(l->head,1);
    l->head = listInsTail(l->head,4);

    for(x=l->head; x!=NULL; x=x->next){
        printf("Before purging:\n%d -> ",x->val);
    }

    f(l,v,N);

    return 0;
}


link newNode(int val, link next){
    link x = malloc(sizeof(*x));
    x->val = val;
    x->next = next;
    return x;
}


link listInsTail(link head, int val){
    link x;
    if(head == NULL){
        return newNode(val,NULL);
    }

    for(x=head; x->next!=NULL; x=x->next);
    x->next = newNode(val,NULL);

    return head;
}


link deleteNode(link head, link node){
    link t,p;

    for(t=head,p=NULL; t!=NULL; p=t,t=t->next){

        if(t==node){
            if(t==head){
                head = t->next;
            }else{
                p->next = t->next;
            }

        }

    }

    free(t);
    return head;
}

void f(LIST l, int *v, int n){
    link t;
    int i;
    int flag;

    for(t=l->head; t!=NULL; t=t->next){
        flag=0;

        for(i=0; i<n; i++){
            if(t->val == v[i]){
                flag=1;
            }
        }

        if(flag==0){
            l->head = deleteNode(l->head,t);
        }
    }
    
    printf("After purging:\n");
    printList(l);

}

void printList(LIST l){
    link x;
    for(x=l->head; x!=NULL; x=x->next){
        printf("%d -> ",x->val);
    }
    return;
}
