#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//modello disposizioni ripetute
//k puo essere maggiore di n

int disp_rip(int pos, char *val, char *sol, int *mark,int n, int k, int count);
int checkSol(char *sol, char *val, int *mark,int n, int k);

int main(){
    int k=6,n=5;
    int count=0;

    char *val;
    val = malloc(n*sizeof(char));
    char *sol;
    sol = malloc(k*sizeof(char));
    val[0]='A';val[1]='E';val[2]='I';val[3]='O';val[4]='U';

    int *mark;
    mark = malloc(k*sizeof(char));

    for(int j=0;j<k;j++){
        mark[j]=0;
    }

    count = disp_rip(0,val,sol,mark,n,k,count);

    return 0;
}


int disp_rip(int pos, char *val, char *sol, int *mark,int n, int k, int count){
    int i;

    if (pos >= k){

        if(checkSol(sol,val,mark,n,k)){
            for(i=0;i<k;i++){
                printf("%c ",sol[i]);
            }
            printf("\n");
        }

        return count+1;

    }

    for(i=0; i<n; i++){
        sol[pos] = val[i];
        count = disp_rip(pos+1,val,sol,mark,n,k,count);
    }

    return count;

}


int checkSol(char *sol,char *val,int *mark,int n, int k){
    int i,j;
    int is_sol=1;

    for(i=0;i<k;i++){
        for(j=0;j<n;j++){
            if(sol[i]==val[j] && i!=j){
                mark[j]++;
            }
        }
    }

    for(i=0;i<n;i++){
        if(mark[i]==0){
            is_sol=0;
        }
    }

    //riazzeramento
    for(i=0;i<n;i++){
        mark[i]=0;
    }

    return is_sol;
}
