#include<stdio.h>
#include<stdlib.h>
//Algoritmo de ordenação QuickSort

int Particao(int *A,int p,int r);
int ParticaoAleatorizada(int *A, int ini,int fim);
void QuickSortAleatorizado(int *A,int p,int r);
void imprimir(int *A,int N);

int main(){
    int A[17] = {9,7,2,1,0,5,5,5,4,4,4,3,3,2,6,4,5};
    int tam = sizeof(A)/sizeof(A[0]);
    QuickSortAleatorizado(A, 0, tam-1);
    imprimir(A, tam);
    return 0;
}
void imprimir(int *A,int N){
    for(int i=0;i<N;i++)
        printf("%d ",A[i]);
}
int Particao(int *A,int primeiro,int ultimo){
    int pivo = A[ultimo];
    int aux = primeiro-1;
    int armazena;
    for(int i=primeiro; i < ultimo; ++i){
        if(A[i] <= pivo){
            ++aux;
            armazena = A[aux];
            A[aux] = A[i];
            A[i] = armazena;
        }
    }
    armazena = A[aux+1];
    A[aux+1] = A[ultimo];
    A[ultimo] = armazena;
    return aux+1;
}
int ParticaoAleatorizada(int *A,int inicio,int fim){
    int x = (rand() % (fim - inicio + 1)) + inicio;
    int aux=A[fim];
    A[fim]=A[x];
    A[x]=aux;
    return Particao(A,inicio,fim);
}
void QuickSortAleatorizado(int *A,int ini,int fim){
    if(ini < fim){
        int q = ParticaoAleatorizada(A, ini, fim);
        QuickSortAleatorizado(A, ini, q-1);
        QuickSortAleatorizado(A, q+1, fim);
    }
}
