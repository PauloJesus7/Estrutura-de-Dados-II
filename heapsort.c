// Heap Sort em C
#include <stdio.h>
// Função para trocar a posição de dois elementos
void troca(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// para o heapify a sub-arvore tem a raiz com nó i
// que é um índice do array A[].
// N é o tamanho da pilha
void MaxHeapify(int A[], int N, int i){
	// encontra o maior nó entre as raizes,dos filhos a esquerda e a direita
	// inicializar com o elemento maior na raiz
	int raiz = i;
	// posicao filho esquerda = 2*i + 1
	int left = 2 * i + 1;

	// posicao filho direita = 2*i + 2
	int right = 2 * i + 2;

	// Se o filho esquerdo for maior que a raiz
	if (left < N && A[left] > A[raiz])

		raiz = left;

	// Se o filho a direita for maior que a raiz,então raiz sera atualizada
	if (right < N && A[right] > A[raiz])

		raiz = right;

	// troca e continua o processo do Maxheapify
	// caso a raiz não seja maior ou seja o maior não esta na raiz, então:
	if (raiz != i) {
		troca(&A[i], &A[raiz]);
		MaxHeapify(A, N, raiz);
	}
}

// função principal do heapSort
void heapSort(int A[], int N){
	// construindo a max Heap
	for (int i = N / 2 - 1; i >= 0; i--)

		MaxHeapify(A, N, i);

	// Heap sort
	for (int i = N - 1; i >= 0; i--) {

		troca(&A[0], &A[i]);

		// Heapify para obter elemento mais alto
		// e inserir ele na raiz.
		MaxHeapify(A, i, 0);
	}
}

//função dpara imprimir matriz de tamanho n
void Imprimir(int A[], int N){
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(){
	int A[] = { 12, 11, 13, 5, 6, 7,23 ,2};
	int N = sizeof(A) / sizeof(A[0]);

	// chamada de funcao
	heapSort(A, N);
	printf("Array ordenado\n");
	Imprimir(A, N);
}

