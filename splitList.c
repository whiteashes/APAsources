#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *link;
struct node {
    int val;
    link next;
};

typedef struct l_t lista_t;
struct l_t {
    link head;
};

link listInsHead(link head, int val);
link listInsTail(link head, int val);
link newNode(int val, link next);
lista_t* splitList(int, lista_t *L1, lista_t **L2);
void printList(lista_t *l);

int main(){
    int i;
    int n=18;

    lista_t *L0, *L1, *L2;
    L0 = malloc(sizeof(*L0));
    L1 = malloc(sizeof(*L1));
    L2 = malloc(sizeof(*L2));

    L0->head = NULL; L2->head = NULL;

    int to_add[10] = {7,8,25,2,9,-5,10,37};
    for(i=0;i<8;i++){
        L0->head = listInsTail(L0->head,to_add[i]);
    }

    /*print for test*/
    printList(L0);

    L1 = splitList(n,L0,&L2);

    printList(L1);
    printList(L2);

    return 0;
}

link listInsHead(link head, int val){
    head = newNode(val, head);
    return head;
}

link listInsTail(link head, int val){
    link x;
    if(head==NULL){
        return newNode(val,NULL);
    }

    for(x=head; x->next!=NULL; x=x->next);
    x->next = newNode(val,NULL);

    return head;
}

link newNode(int val, link next){
    link x = malloc(sizeof(*x));
    x->val = val;
    x->next = next;
    return x;
}

lista_t* splitList(int n, lista_t *L0, lista_t **L2){
    /*valori minori della soglia li metto in L1 */
    lista_t *L1 = malloc(sizeof(*L1)); L1->head = NULL;
    link x;
    for(x=L0->head; x!=NULL; x=x->next){
        if(x->val < n){
            L1->head = listInsTail(L1->head,x->val);
        }
        if(x->val > n){ /*L2 by reference */
            (*L2)->head = listInsTail((*L2)->head,x->val);
        }
    }

    return L1;
}

void printList(lista_t *l){
    link x;
    for(x=l->head; x!=NULL; x=x->next){
        printf("%d ",x->val);
    }
    printf("\n");
    
    return;
}
