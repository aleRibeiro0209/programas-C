/*
    Name: programaOrdenacaoShell.c
    Author: Alexandre Ribeiro
    Description: Implementação do método Busca Binaria ou Logarítmica
*/

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

// Prototipacao
void shellSort(int *, int);
void buscaBinaria(int *, int, int);

// Funcao principal
main() {

    // int vet [] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
    int vet[10000];
    int i;
    int tam = sizeof(vet)/sizeof(int);
    srand(time(NULL)); // Utiliza o tempo para gerar numeros aleatorios
	
	for(i=0;i < tam;i++)
	{
		vet[i] = rand()%100000; // 0 ate 1000
	}

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

    puts("\n\nRealizando uma Busca Binaria ou Logaritmica");
    while (1)
    {
        buscaBinaria(vet, 0, tam-1);
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
} // Fim da funcao Shell Sort

void buscaBinaria(int *vet, int inicio, int fim) {
    int elem = 0;
    int meio = 0;
    int achou = 0; // Inicializando com o valor "Falso"

    printf("Digite o elemento que deseja encontrar: ");
    scanf("%d", &elem);

    while (inicio <= fim) {
        meio = (inicio + fim)/2;
        printf("\nmeio: %d", meio);
        if (elem == vet[meio]){
            achou = 1;
            break;
        }
        else if (elem < vet[meio])
            fim = meio - 1;
             else
                inicio = meio + 1;
        
    }

    if (achou == 1)
        printf("\n\nElemento esta na posicao %d do vetor", meio+1);
    else 
        printf("\n\nElemento nao encontrado");
    
} // Fim da funcao Busca Binaria