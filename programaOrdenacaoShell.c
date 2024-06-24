/*
    Name: programaOrdenacaoShell.c
    Author: Alexandre Ribeiro
    Description: Implementação do método de ordenação Shell Sort
*/

#include <stdio.h>
#include <conio.h>

// Prototipacao
void shellSort(int *, int);

// Funcao principal
main() {

    int vet [] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
    int i;
    int tam = sizeof(vet)/sizeof(int);

    puts("Vetor original:");
    for (i = 0; i < tam; i++)
    {
        printf(" %d |", vet[i]);
    }

    shellSort(vet, tam);

    puts("\n\nVetor ordenado pelo Shell Sort:");
    for (i = 0; i < tam; i++)
    {
        printf(" %d |", vet[i]);
    }
    
}// Fim da funcao principal

void shellSort(int vet[], int tam) {
    int i, j, chave, h = 1;
    
    while (h < tam)
    {
        h = 3*h + 1;
    }
    
    while (h > 0)
    {
        for (i = h; i < tam; i++)
        {
            chave = vet[i];
            j = i;
            while (j > h-1 && chave <= vet[j - h])
            {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = chave;
        }
        h = h/2;
    }
    
}