#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ricerca(int *vet1, int *vet2, int d1,int d2){

    int i,t;
    int found;
    int j=1;
    for(i=0;i<d1;i++){
        if(vet1[i]==vet2[0]){
            for(t=i,j=1; j<d2; j++,t++){
                if(vet1[t]!=vet2[j]){
                    found=0;
                }
            }
            found=1;
        }
    }

    if(found==0){
        return 0;
    }
    
    return 1;
}

int main(){
    int d1 = 8, d2 = 3, vet1[8] = {0, 15, 12, 3, 7, 15, 12, 21}, vet2[3] = {15, 12, 21}; 
    int res = ricerca(vet1,vet2,d1,d2);

    if(res==0){
        printf("soluzione non trovata\n");
    }else{
        printf("%d\n",res);
        printf("soluzione trovata");
    }

    return 0;
}
