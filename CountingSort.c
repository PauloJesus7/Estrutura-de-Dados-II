#include <stdio.h>
#include <stdlib.h>
//Algoritmo CountingSort com complexidade de tempo linear
void CountingSort(int *A,int *c,int k,int n);

int main(){
    //cria��o de vetor ao qual ser� ordenado
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
    CountingSort(A, c, k, n-1);//chamada de fun��o de ordena��o do vetor
    free(c);
    return 0;
}

void CountingSort(int *A,int *c,int k,int n){
    int *B = malloc((k+1) * sizeof(*B));//cria��o de vetor com tamanho k para fazer o controle do array principal e aloca��o de espa�o para novo vetor
    if( B == NULL){
        printf("Erro de aloca��o");
        exit(1);
    }int i,j;
    //B deve primeiramente receber 0 em cada posi��o de 0 a k-1
    for(i = 0;i <= k;i++)
        B[i] = 0;//zerar todos os elementos do vetor B
    //Percorrendo o vetor original com o indice j ate o ultimo elemento da posi��o n.
    for(j = 0; j <= n; j++)
        B[A[j]]++;//Ao passo que no vetor original encontrar um valor, ser� ent�o acrescido 1, na posi��o referente a ele em B
    //B[i]contem o numero de elementos em A que s�o iguais a i
    for(i = 1; i <= k;i++)
        B[i] = B[i] + B[i-1];//soma cumulativa dos elementos em B de acordo com sua posi��o, somando o indice i com o anterior
    //B[i] contem o numero de elemeentos em A que s�o menores ou iguais a i
    for(j = n; j >= 0;j--){//Deve ser avaliado o vetor original da ultima posi��o ate a primeira para fazer a ordena��o
        c[B[A[j]]-1] = A[j];//Sera verificado o elemento do vetor original,ele ser� inserido no vetor auxiliar na posi��o de B[A[i]-1
        B[A[j]]--;//apos a inser��o o vetor B[A[i]] deve ser decrementado para que n�o haja inser��o de outro valor na mesma posi��o
    }printf("\n\n");
    for(j = n;j >= 0;j--)
        A[j]=c[j];//copiar os valores do vetor auxiliar C, para o vetor original a ser ordenado A
    for(j = 0; j <= n; j++)
        printf("%d ",A[j]);//imprimir vetor original ordenado
    free(B);
}

