/*
    Programa para ordenar um array de inteiros:
        - Utilizar metodo de ordenacao Bubble Sort;
        - Mostrar a quantidade de comparacoes;
        - Mostrar a quantidade de trocas.
*/

// Importação de Biblioteca
#include <stdio.h>
#include <time.h>

// Prototipacao
void bubbleSort(int *, int);

// Funcao principal
main(){

    // int vet[] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
    int vet[251];
    srand(time(NULL));
    int tam = sizeof(vet) / sizeof(int);

    for(int i=0;i < tam;i++)
	{
		vet[i] = rand()%251;
	}

    puts("Vetor desordenado:");
    for (int i = 0; i < tam; i++)
    {
        printf(" %d |", vet[i]);
    }
    
    bubbleSort(vet, tam);

    puts("\n\nVetor ordenado:");
    for (int i = 0; i < tam; i++)
    {
        printf(" %d |", vet[i]);
    }
}

void bubbleSort(int *vetor, int tamanho){
    int aux = 0, j = 0, trocas = 0;

    while (j < tamanho)
    {
        for (int i = 0; i < tamanho-1; i++)
        {
            if (vetor[i] > vetor[i+1])
            {
                trocas++;
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
        tamanho--;
    }

    printf("\n\nForam realizadas %d trocas.", trocas);
}