/*
    Name: programaOrdenacaoInsertion.c
    Author: Alexandre Ribeiro
    Description: Implementação do método de ordenação Insertion Sort
*/

#include <stdio.h>
#include <conio.h>

int comp = 0, trocas = 0;

// Prototipacao
void insertionSort(int *, int);

// Funcao principal
main() {

    // char vet [] = {'A', 'L', 'E', 'X', 'A', 'N', 'D', 'R', 'E'};
    int vet [] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
    int i;
    int tam = sizeof(vet)/sizeof(int);

    puts("Vetor original:");
    for (i = 0; i < tam; i++)
    {
        printf(" %d |", vet[i]);
    }

    insertionSort(vet, tam);

    puts("\n\nVetor ordenado pelo Insertion Sort:");
    for (i = 0; i < tam; i++)
    {
        printf(" %d |", vet[i]);
    }
    
    printf("\n\nQuantidade de comparacoes: %d", comp); 
    printf("\nQuantidade de trocas: %d", trocas);
}// Fim da funcao principal

void insertionSort(int vet[], int tam) {
    int i, j, chave;

    for(i = 1; i < tam; i++) {
        chave = vet[i];
        j = i - 1;
        comp++;

        while (j >= 0 && vet[j] > chave) {
            comp++;
            trocas++;
            vet[j + 1] = vet[j];
            j = j - 1;
        }

        vet[j + 1] = chave;
    }
}