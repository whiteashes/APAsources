#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct riga Riga; 
struct Riga {
    char *str;
    int dim;
};

int mult(int pos, Riga *val, char *sol, int max, int nSol){
    int i;

    if(pos >= max){
        for(i=0; i<pos; i++){
            printf("%c",sol[i]);
        }
        printf("\n");

        return nSol+1;
    }

    for(i=0; i < val[pos].dimStr; i++){
        sol[pos] = val[pos].str[i];
        nSol = mult(pos+1,val,sol,max,nSol);
    }

    return nSol;

}

int main(){
    int nRighe;
    FILE *fp = fopen("file.txt","r");
    fscanf(fp,"%d",&nRighe);

    char *sol;
    sol = malloc(nRighe*sizeof(char));

    Riga r;
    r = malloc(nRighe*sizeof(*r));

    int nSol = mult(0,r,sol,nRighe,0);

    return 0;
}
