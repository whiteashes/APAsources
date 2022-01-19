#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node1 *link1;
struct node1 {
    int val;
    link1 next;
};

typedef struct node2 *link2;
struct node2 {
    int val;
    int nOcc;
    link2 next;
};

typedef struct L1 *l1;
struct L1 {
    link1 head;
    int N;
};

typedef struct L2 *l2;
struct L2 {
    link2 head;
};

link2 comprimi(link1 head);
link2 insTail(int val, int nOcc, link2 h);
link1 insHead1(int val, link1 next);
link1 newNode1(int val,link1 next);
link2 newNode2(int val, int nOcc, link2 next);
void printList1(link1 head);
void printList2(link2 head);


link2 comprimi(link1 head){
    link1 x;

    l2 list;
    list = malloc(sizeof(*list));
    list->head = NULL; //inizializzo

    link2 head2 = list->head;

    //cerco n occorrenze
    int val = head->val; //first value
    int nOcc = 1;

    //scorro
    for(x=head->next; x!=NULL; x=x->next){

        if(x->val != val){
            //occ terminate, inserisci in lista la coppia val e nOcc
            head2 = insTail(val,nOcc,head2);
            //update
            nOcc=1;
            val = x->val;
        }else{
            nOcc++;
        }

    }

    //ultimo inserimento -> con il NULL non prende ultima occorrenza altrimenti
    head2 = insTail(val,nOcc,head2);

    return head2;

}

link2 newNode2(int val, int nOcc, link2 next){
    link2 x;
    x=malloc(sizeof(*x));
    x->val=val;
    x->nOcc=nOcc;
    x->next=next; //sempre NULL nell'inserimento in coda
    return x;
}

link1 newNode1(int val, link1 next){
    link1 x;
    x=malloc(sizeof(*x));
    x->val=val;
    x->next=next;
    return x;
}


link2 insTail(int val, int nOcc, link2 h){
    link2 x;

    if(h==NULL){
        return newNode2(val,nOcc,NULL);
    }

    for(x=h; x->next!=NULL; x=x->next);
    x->next = newNode2(val,nOcc,NULL);

    return h; //ritorna sempre la testa
}

link1 insHead1(int val, link1 h){
   h = newNode1(val,h);
   return h;
}

void printList1(link1 head){
    link1 x;
    for(x=head; x!=NULL; x=x->next){
        printf("%d ",x->val);
    }
    printf("\n");

    return;
}

void printList2(link2 head){
    link2 x;
    for(x=head; x!=NULL; x=x->next){
        printf("%d %d\n",x->val,x->nOcc);
    }

    return;
}


int main(){

    l1 list;
    list=malloc(sizeof(struct node1));

    link2 head;

    list->head = NULL;

    link1 x; 
    x = list->head;
    list->N = 0;

    x = insHead1(3,x);
    x = insHead1(3,x);
    x = insHead1(3,x);
    x = insHead1(3,x);
    
    x = insHead1(2,x);
    x = insHead1(2,x);

    x = insHead1(3,x);

    x = insHead1(5,x);
    x = insHead1(5,x);
    x = insHead1(5,x);

    list->N = 10;

    printList1(x);

    head = comprimi(x);

    printList2(head);


    return 0;
}
