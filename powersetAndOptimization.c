#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7
#define M 100

/*version without pruning technique (downstream checks) */

typedef struct Obj item_t;
struct Obj {
    int costo;
    int valore;
    int tipo;
    int qta;
};

int powerset(int pos, int *sol,item_t *v, int k, int start,int count, int tot_c, int *c_tmp);
int checkSol(int *sol,int n);


int main(){
    int *sol = malloc(N*sizeof(int));
    for(int i=0;i<N;i++){
        sol[i]=0;
    }

    int c_tmp=0;

    item_t v[N];
    v[0].costo=10; v[0].tipo=1; v[1].costo=30; v[2].costo=40; v[3].costo=21; v[4].costo=11;
    v[1].tipo=3; v[2].tipo=1; v[3].tipo=4; v[4].tipo=7;

    int count = powerset(0,sol,v,5,0,0,78,&c_tmp);
    printf("%d diocane\n",count);

    return 0;

}


int powerset(int pos, int *sol,item_t *v, int k, int start,int count, int tot_c, int *c_tmp){
    int i;

    if (start >= k) {

        if(*c_tmp <= tot_c){
            *c_tmp=0;              
            
            if(checkSol(sol,pos)){
                for(i=0;i<pos;i++){
                    printf("%d ",sol[i]);
                }
                printf("\n");    
                return count+1;
            }
        }
        
        *c_tmp=0;
        return count;

    }


    for(i=start; i<k; i++) {
            sol[pos] = v[i].tipo;
            printf("\n");
            *c_tmp += v[i].costo;
            printf("costo attuale %d\n",*c_tmp);
            count = powerset(pos+1, sol,v, k, i+1, count,tot_c,c_tmp);
    }

    count = powerset(pos,sol,v,k,k,count,tot_c,c_tmp);
    return count;
}

int checkSol(int *sol,int n){
    int i;
    char *mark = malloc(M*sizeof(int));
    for(i=0;i<M;i++){
        mark[i]=0;
    }

    for(i=0;i<n;i++){
        mark[sol[i]]++;
    }

    for(i=0;i<M;i++){
        if(mark[sol[i]]>1){
            return 0;
        }
    }

    return 1;
}
