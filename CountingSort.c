#include <stdio.h>
#include <stdlib.h>
//Algoritmo CountingSort com complexidade de tempo linear
void CountingSort(int *A,int *c,int k,int n);

int main(){
    //criação de vetor ao qual será ordenado
    int A[]= {2, 5, 3, 0, 2, 3, 0, 3};
    //tamanho do vetor para encontrar o maior elemento
    int n =(sizeof(A))/(sizeof(A[0]));
    //vetor c recebera O ARRAY ORDENADO
    int *c;
    c = malloc( n * sizeof(int));
    int k;
    k=A[0];//encontrando o maior elemento do vetor e atribuindo a variavel K
    for(int i = 1;i < n;i++){
        if(k<A[i])
            k=A[i];
    }
    CountingSort(A, c, k, n-1);//chamada de função de ordenação do vetor
    free(c);
    return 0;
}

void CountingSort(int *A,int *c,int k,int n){
    int *B = malloc((k+1) * sizeof(*B));//criação de vetor com tamanho k para fazer o controle do array principal e alocação de espaço para novo vetor
    if( B == NULL){
        printf("Erro de alocação");
        exit(1);
    }int i,j;
    //B deve primeiramente receber 0 em cada posição de 0 a k-1
    for(i = 0;i <= k;i++)
        B[i] = 0;//zerar todos os elementos do vetor B
    //Percorrendo o vetor original com o indice j ate o ultimo elemento da posição n.
    for(j = 0; j <= n; j++)
        B[A[j]]++;//Ao passo que no vetor original encontrar um valor, será então acrescido 1, na posição referente a ele em B
    //B[i]contem o numero de elementos em A que são iguais a i
    for(i = 1; i <= k;i++)
        B[i] = B[i] + B[i-1];//soma cumulativa dos elementos em B de acordo com sua posição, somando o indice i com o anterior
    //B[i] contem o numero de elemeentos em A que são menores ou iguais a i
    for(j = n; j >= 0;j--){//Deve ser avaliado o vetor original da ultima posição ate a primeira para fazer a ordenação
        c[B[A[j]]-1] = A[j];//Sera verificado o elemento do vetor original,ele será inserido no vetor auxiliar na posição de B[A[i]-1
        B[A[j]]--;//apos a inserção o vetor B[A[i]] deve ser decrementado para que não haja inserção de outro valor na mesma posição
    }printf("\n\n");
    for(j = n;j >= 0;j--)
        A[j]=c[j];//copiar os valores do vetor auxiliar C, para o vetor original a ser ordenado A
    for(j = 0; j <= n; j++)
        printf("%d ",A[j]);//imprimir vetor original ordenado
    free(B);
}

