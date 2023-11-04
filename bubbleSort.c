#include<stdio.h>
#include<stdlib.h>

int main(){
    int V[7] = {7,4,3,8,2,5,3} ;
    int j,i=0,aux;
    int tam=(int)(sizeof(V))/(int)(sizeof(V[0]));

    for (j = (tam-1);j > 0; j--){
        i=0;
        while (i < j){
            if(V[i+1] < V[i]){
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
            }i++;
        }
    }for(i = 0; i < tam; i++)
        printf("%d ",V[i]);
    return 0;
}
