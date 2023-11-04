#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    /*Ideia Básica: Dividir e Conquistar
    Divida recursivamente o conjunto de dados até que cada
    subconjunto possua 1 elemento
    Combinar dois subconjuntos de forma a obter 1 conjunto
    maior e ordenado
    processo se repete ate que exista apenas 1 conjunto.*/
void mergeSort(int *V,int ini,int fim);

void merge(int *V,int ini,int meio,int fim);

int main(){
    int V[8]={13,4,15,9,2,7,10,8};
    int i=0;
    int tam=(int)(sizeof(V))/(int)(sizeof(V[0]));
    mergeSort(V, i, tam-1);
    printf("\n");
    for(i=0;i<tam;i++){
        printf("%d ",V[i]);
    }printf("\n");
    return 0;
}
void mergeSort(int *V,int ini,int fim){
    if(ini<fim){
        int meio=((ini+fim)/2);
        mergeSort(V,ini,meio);
        mergeSort(V,meio+1,fim);
        merge(V,ini,meio,fim);
    }
}
void merge(int *V,int ini,int meio,int fim){
    int i=ini,j=meio+1,k=0;
    int *B=malloc((fim-ini+1)*sizeof(int));
    while(k<(fim-ini+1)){
        if(i <= meio && j <= fim){//Caso o i e j, estejam dentro dos vetores ini-meio e meio+1 ate o fim
            if(V[i]<=V[j]){
                B[k]=V[i];
                i++;
            }else{
                B[k]=V[j];
                j++;
            }
        }else{
            if(i<=meio){//caso do i ter ultrapassado o vetor i ate o meio, então copiará o restante de j
                B[k]=V[i];
                i++;
            }if(j<=fim){//caso do j ter ultrapassado o vetor j ate o fim, então copiará o restante de i
                B[k]=V[j];
                j++;
            }
        }k++;//fim da intercalação logo é necessario fazer a copia do vetor no ponteiro original
    }i=ini;k=0;
    memcpy(&V[i],&B[k],(fim-ini+1) * sizeof(int));
    free(B);
}//encerramento da função merge
