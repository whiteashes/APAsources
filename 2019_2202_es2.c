#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo nodo_t;
typedef nodo_t *link;
struct nodo {
    float key;
    link left;
    link right;
};

typedef struct tree_h tH;
struct tree_h {
    link root;
};

int maxSum(link root,float *maxwt);
void visit(link root,float *maxwt,float *maxtmp);


int maxSum(link root,float *maxwt){
    float maxtmp=0;
    visit(root,maxwt,&maxtmp);
    return *maxwt;
}

void visit(link root,float *maxwt,float *maxtmp){
    if(root==NULL){
        if(*maxwt>*maxtmp){
            *maxtmp=*maxwt;
        }
        return;
    }

    visit(root->left,maxwt,maxtmp);
    *maxwt=*maxwt+root->key;
    visit(root->right,maxwt,maxtmp);
}

int main(){
    float maxwt=0;
    tH *t;
    t=malloc(sizeof(*t));

    nodo_t n06 = {14.4};
    nodo_t n05 = {21.4};
    nodo_t n04 = {27.4};
    nodo_t n03 = {29.4};
    nodo_t n02 = {23.4};
    nodo_t n01 = {13.4};

    n01.right = &n03;
    n01.left = &n05;
    n02.right = &n06;
    n02.left = &n04;

    nodo_t n00 = {23.4};
    n00.left = &n01;
    n00.right = &n02;

    t->root = &n00;

    float res = maxSum(t->root,&maxwt);
    printf("max sum: %f\n",res);

    return 0;
}
