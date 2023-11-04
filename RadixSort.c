#include <stdio.h>
#include <stdlib.h>
//Algoritmo CountingSort com complexidade de tempo linear
int max(int *A,int n){
    int k=A[0];
    for(int i=1;i <n;i++){//função para achar maior elemento do vetor
        if(A[i] > k)
            k = A[i];//retira o maior elemento do vetor
    }
    return k;
}
void RadixSort(int *A,int n){
    int base,k = max(A, n);//variavel para receber o maior elemento do vetor
    for(base = 1; k / base > 0; base *=10)//chamada CoutingSort(algoritmo estável) seguindo ordem, unidade,dezena,centenas, em diante.
        CountingSort(A, n, base);
}

void CountingSort(int *A,int n,int base){
   int saida[n];//vetor de saida com o resultado ordenado da ordem numerica que for inserida
   int i, count[10] = {0};//contador sera inicializado com 0, neste caso apenas 10 numeros serao avaliados visto que de 0 a 9 sao as possibilidades

   for(i = 0; i < n; i++)
        count[(A[i] / base) % 10]++;//funcao armazena a contagem de ocorrencias em count[]

   for(i = 1;i<10;i++)
        count[i]+=count[i-1];//função para atualizar onde começa as posições atuais de cada elemento no vetor

   for(i = (n-1);i>=0;i--){
        saida[count[(A[i] / base) % 10] - 1] = A[i];//funcao para construir a saida
        count[(A[i] / base) % 10]--;
   }

   for(i = 0; i < n; i++)
        A[i] = saida[i];//função para copiar o array de saída para o ponteiro
}

int main(){
    int A[] = {329,457,657,839,436,720,355};
    int n = sizeof(A) / sizeof(A[0]);
    RadixSort(A, n);
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}

