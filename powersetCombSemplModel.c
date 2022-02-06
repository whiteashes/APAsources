#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define M 50

/* powerset con il modello delle combinazioni semplici + verifica validita' soluzione (no pruning) */

void cover(int S[][9], int n, int k);
int cover_r(int S[][9],int *U,int n,int k,int pos, int start, int **sol, int count);
int checkSol(int **sol, int *U, int n);

int main(){
    int S[N][9] = {{1,2,3,0,0,0,0,0,0},{4,5,0,0,0,0,0,0,0},{7,8,6,0,0,0,0,0,0},{3,4,6,0,0,0,0,0,0},{4,7,0,0,0,0,0,0,0}};
    int k=3;

    cover(S,N,k);
    return 0;
}

void cover(int S[][9], int n, int k){
    int j;
    int count=0;

    int **sol = malloc(n*sizeof(int*));
    for(j=0;j<n;j++){
        sol[j] = malloc(9*sizeof(int));
    }

    int U[10] = {1,2,3,4,5,6,7,8};


    count = cover_r(S,U,n,k,0,0,sol,count);
    printf("numero di soluzioni: %d\n",count);

    return;
}

int cover_r(int S[][9],int *U,int n,int k,int pos,int start,int **sol,int count){

    int i,j;

    /* ho finito di raccogliere i k insiemi */
    if(pos >= k){

        for(j=0; j<k; j++){
            for(i=0;i < 9; i++){
                if(sol[j][i]!=0){
                    printf("%d ",sol[j][i]);
                }
            }
            printf("-");
        }
        printf("\n");

        if(checkSol(sol,U,n)){
            printf("Soluzione corrispondente al vettore U trovata:\n");
        }


        return count+1;

    }

    for(i=start; i<n; i++){

        /* riempio la riga sol[pos][] ovvero uno dei k sottoinsiemi della soluzione a fronte di n insiemi totali */
        for(j=0;j<9;j++){
            sol[pos][j] = S[i][j];
        }
        count += cover_r(S,U,n,k,pos+1,i+1,sol,count);
    }
    
    return count;
}

int checkSol(int **sol, int *U, int n){
    int isvalid=1,m=50;
    int i,j,k;

    int *mark = malloc(m*sizeof(int));
    for(i=0;i<8;i++){
        mark[U[i]] = 0; /*init*/
    }

    /*esplorazione matrix*/
    for(i=0;i<n;i++){
        for(j=0;j<9;j++){

            for(k=0; k<8; k++){
                if(sol[i][j] == U[k]){
                    mark[U[k]] = 1; /*elemento trovato*/
                }
            }
            
        }
    }

    for(i=0;i<8;i++){
        printf("%d ",mark[U[i]]);
    }
    printf("\n");

    /* soluzione valida se tutti gli elementi di mark sono a 1 */
    for(i=0;i<8;i++){
        if(mark[U[i]]==0){
            isvalid=0;
        }
    }

    return isvalid;

}
