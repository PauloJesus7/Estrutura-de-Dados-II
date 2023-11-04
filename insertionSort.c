#include<stdio.h>

int main(){
    int V[7]={7,4,3,8,2,5,3};
    int i,j,chave;
    int tam=(int)(sizeof(V))/(int)(sizeof(V[0]));
    for(j = 1; j < tam; j++){
        i=j-1;
        chave = V[j];
        while(i >= 0 && V[i]>chave){
            V[i+1]=V[i];
            i--;
        }V[i+1]=chave;
    }
    for(i = 0; i < tam; i++)
        printf("%d ", V[i]);
    return 0;
}
