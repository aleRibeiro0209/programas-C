/*
    Programa para ordenar um array de inteiros:
        - Utilizar metodo de ordenacao Bubble Sort;
        - Mostrar a quantidade de comparacoes;
        - Mostrar a quantidade de trocas.
*/

// Sessao de importacao de biblioteca
#include <stdio.h>

// Declaracao de variavel global
int vetor[] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};

// Funcao principal
main(){

    // Declaracao do tamanho do vetor de maneira dinamica
    int tam = sizeof(vetor) / sizeof(int);
    
    // Declaracao de variaveis locais
    int comp = 0, troca = 0, aux = 0, i = 0, j = 0;

    // Imprime o vetor da forma em que ele esta
    puts("VETOR DESORDENADO:");
    for (i = 0; i < tam; i++)
    {
        printf(" %d |", vetor[i]);
    }

    // Aplicacao do metodo bubble sort para ordenar o vetor
    while (j < tam)
    {
        for (i = 0; i < tam-1; i++)
        {
            comp++;
            if (vetor[i] > vetor[i+1]) 
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                troca++;
            }
        }
        tam--;
    }
    
    // Apos o tamanho ser decrementado na While, e necessario realizar o calculo do tamanho novamente
    tam = sizeof(vetor) / sizeof(int);

    // Imprime o vetor organizado do menor para o maior
    puts("\n\nVETOR ORDENADO COM O METODO BUBBLE SORT:");
    for (i = 0; i < tam; i++)
    {
        printf(" %d |", vetor[i]);
    } 
    
    // Imprime ao usuario a quantidade de comparacoes e trocas realizadas
    printf("\n\nA quantidade de trocas foi: %d", troca);
    printf("\nA quantidade de comparacoes foi: %d", comp);
} // fim da funcao principal