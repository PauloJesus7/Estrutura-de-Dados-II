#include<stdio.h>
#include<stdlib.h>

int main(){
    int V[7]= {7,4,3,8,2,5,3};
    int min,i,j;
    int tam=(int)(sizeof(V))/(int)(sizeof(V[0]));
    for(j = 0;j < (tam-1); j++){
        min = j;
        for(i = j+1; i < tam; i++){
            if(V[j]>V[i]){
                min=V[i];
                V[i]=V[j];
                V[j]=min;
    }   }   }
    for(i = 0; i < tam; i++)
        printf("%d ", V[i]);
    return 0;
}
