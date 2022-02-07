#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int powerset_w(int *v, int k, int n);
int powerset_r(int *v, int *sol, int pos, int start,int k, int n);
int checkSol(int *sol, int k);

int main(){
    int count=0;
    int v[9] = {8,9,6,4,5,7,3,2,4};
    int k; /*len max sottoseq*/
    int n=9; /*len v*/

    printf("Inserisci la lunghezza massima della sottosequenza: ");
    scanf("%d",&k);

    count = powerset_w(v,k,n);
    printf("Numero soluzioni: %d\n",count);

    return 0;
}

int powerset_w(int *v, int k, int n){
    int count=0;
    int i;

    int *sol = malloc(k*sizeof(int));

    printf(":;/\n"); /*sol vuota*/
    count++;

    /* sottoinsiemi da 1 a n (dimensione di v)*/
    //for(i=1; i<=n; i++){
        i=k;
        printf("Soluzione di cardinalita %d: \n",i);
        count += powerset_r(v,sol,0,0,i,n);
    //}

    return count;
}

int powerset_r(int *v, int *sol, int pos, int start,int k, int n){
    int count=0;
    int j,i;

    if(pos >= k){

        if(checkSol(sol,k)){
            for(j=0;j<k;j++){
                printf("%d ",sol[j]);
            }
            printf("\n");

            return 1;
        }
    }

    for(i=start; i<n; i++){
        sol[pos] = v[i];
        count += powerset_r(v,sol,pos+1,i+1,k,n);
    }

    return count;
}

int checkSol(int *sol, int k){
    int isvalid=1;
    int i;

    for(i=0; i<k; i++){

        if(i%2==0){
            if(sol[i]>sol[i+1]){
                isvalid=0;
            }

        }else{
            if(sol[i]<sol[i+1]){
                isvalid=0;
            }
        }
    }

    return isvalid;
}
