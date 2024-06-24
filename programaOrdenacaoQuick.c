/*
    Name: programaOrdenacaoQuick.c
    Author: Alexandre Ribeiro dos Santos
    Date: 29/05/24 09:50
    Description: Implementação do método de ordenação Quick Sort
*/

#include <stdio.h>
#include <conio.h>

// Prototipacao
void quickSort(int *, int, int);
int particionar(int *, int, int);

int i, tam, comp = 0, trocas = 0;

main() {

    int vet [] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
    tam = sizeof(vet)/sizeof(int);

    puts("Vetor desordenado");
    for (i = 0; i < tam; i++)
        printf(" %d |", vet[i]);

    quickSort(vet, 0, tam-1);

    puts("\n\nVetor ordenado");
    for (i = 0; i < tam; i++)
        printf(" %d |", vet[i]);

    printf("\n\nQuantidade de trocas realizadas: %d", trocas);
    printf("\nQuantidade de comparacoes realizadas: %d", comp);
    
} // Fim do main

void quickSort(int *vetor, int inicio, int fim) {

    int pivot;

    if (fim > inicio)
    {
        pivot = particionar (vetor, inicio, fim);
        quickSort(vetor, inicio, pivot-1);
        quickSort(vetor, pivot+1, fim);
    }
    
} // Fim da funcao quickSort

int particionar(int *vetor, int inicio, int fim){

    int dir, esq, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = vetor[inicio];

    while (esq < dir) {
        while (vetor[esq] <= pivo){
            esq++;
            comp++;
        }
        
        while (vetor[dir] > pivo){
            dir--;
            comp++;
        }
        
        if (esq < dir){
            trocas++;
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
        /*
            puts("\n");
            for (i = 0; i < tam; i++)
                printf(" %d |", vetor[i]);
            getch();
        */

    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    trocas++;
    return dir;
} // Fim da funcao particionar