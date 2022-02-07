#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4
#define M 5

int powerset_w(int mat[][M],int k,int m);
int powerset_r(int mat[][M],int **sol,int *mark,int pos, int start, int n, int m, int k);
int checkSol(int **sol, int k,int m);

int main(){

    int mat[N][M] = { {1,1,0,0,1}, {1,0,1,0,0}, {0,1,1,1,0}, {1,0,0,1,0} };
    
    int k=4; /*righe totali matrix su cui ricorrere*/
    int m=5; /*lampadine per ogni interruttore*/

    int count=0;
    count = powerset_w(mat,k,m);
    printf("Numero totale soluzioni: %d\n",count);

    return 0;
}

int powerset_w(int mat[][M],int k,int m){
    int count=0;
    int i,n;

    /*init*/
    int **sol = malloc(k*sizeof(int*));
    for(i=0; i<k; i++){
        sol[i] = malloc(m*sizeof(int));
    }

    int *mark = malloc(N*sizeof(int)); /*ogni N-esimo elemento e' la riga della matrice -> se vale 1 si e' preso l'interruttore i-esimo*/
    for(n=0;n<N;n++){
        mark[n]=0; /*init*/
    }
    
    printf(":;\n"); /*insieme vuoto*/
    count++;

    /*insiemi ordinati per cardinalita crescente*/
    for(n=1; n<=k; n++){
        printf("Insieme di %d elementi: \n\n",n);
        count += powerset_r(mat,sol,mark,0,0,n,M,k);
    }

    return count;
}

int powerset_r(int mat[][M],int **sol,int *mark,int pos, int start, int n, int m, int k){
    int count=0;
    int i,j;

    /* n sottoinsiemi presi -> caso terminale */
    if(pos >= n) {
        
        if(checkSol(sol,k,m)){
            printf("Soluzione valida di cardinalita %d\n",n);
            printf("Interruttori utilizzati: ");
            for(j=0; j<N; j++) {
                if(mark[j]==1){
                    printf("%d ",j);
                }
            }
            printf("\n\n");
        }


        return 1;
    }


    for(i=start; i<k; i++){
      
        /* fillo il vettore sol con la riga i di mat (sottoinsieme preso)*/
        for(j=0; j<m; j++){
            sol[pos][j] = mat[i][j];
        }
        
        /* marko l'interruttore */
        mark[i] = 1;
        count += powerset_r(mat,sol,mark,pos+1,i+1,n,m,k);
        /* tolgo il mark uscendo dalla ricorsione */
        mark[i] = 0;
    }

    return count;
}

int checkSol(int **sol,int k,int m){
    int i,j;
    int isvalid=1;
    int cnt;
    
    /* scan per colonne -> tutte le colonne (tutte le lampadine) devono avere interruttori attivi dispari*/
    for(j=0; j<m; j++){
        cnt=0;
        for(i=0; i<k; i++){
            if(sol[i][j]==1){
                cnt++;
            }
        }
        if(cnt%2==0){
            isvalid=0;
        }
    }

    return isvalid;
}
