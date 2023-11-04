#include <stdio.h>
#include <stdlib.h>

#define TAM 10 // Quantidade máxima de elementos por balde

// Algoritmo Bucket Sort ou ordenação usando baldes
// Distribui os valores a serem ordenados em um conjunto de baldes, onde cada balde guarda uma faixa de valores

struct balde {
    int qtd;
    float valores[TAM];
};

void InsertionSort(float *A, int n) {
    int i, j;
    float chave;

    for (i = 1; i < n; i++) {
        chave = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > chave) {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = chave;
    }
}

void BucketSort(float *A, int tam) {
    int i, j, maior, menor, nBuckets, pos;
    struct balde *B;

    maior = menor = A[0];

    for (i = 1; i < tam; i++) {
        if (A[i] > maior)
            maior = A[i];
        if (A[i] < menor)
            menor = A[i];
    }

    nBuckets = ((maior - menor) / TAM + 1);
    B = (struct balde *)malloc(nBuckets * sizeof(struct balde));

    for (i = 0; i < nBuckets; i++)
        B[i].qtd = 0;

    for (i = 0; i < tam; i++) {
        pos = (A[i] - menor) / TAM;

        if (B[pos].qtd < TAM) {
            B[pos].valores[B[pos].qtd] = A[i];
            B[pos].qtd++;
        } else {
            // Se o balde estiver cheio, você deve aumentar o tamanho do TAM
            // ou implementar uma estratégia de redimensionamento dos baldes
            // para acomodar mais elementos
            printf("Erro: balde cheio, ajuste o valor de TAM\n");
            free(B);
            return;
        }
    }

    pos = 0;

    for (i = 0; i < nBuckets; i++) {
        if (B[i].qtd > 0) {
            InsertionSort(B[i].valores, B[i].qtd);
            for (j = 0; j < B[i].qtd; j++) {
                A[pos] = B[i].valores[j];
                pos++;
            }
        }
    }

    free(B);
}

void imprimir(float *A, int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", A[i]);
    printf("\n");
}

int main() {
    float A[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int tam = sizeof(A) / sizeof(A[0]);

    BucketSort(A, tam);
    imprimir(A, tam);

    return 0;
}
