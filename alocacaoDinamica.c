// Programa para criar e alocar dinâmicamente a memória para uma matriz[2][10]

#include <stdio.h>
#include <stdlib.h>

int main() {

    int **matriz;
 
    // Criando e alocando a memória dinâmica para as 2 linhas
    matriz = (int **)malloc(2 * sizeof(int **));

    // Criando e alocando a memória dinâmica para as 10 colunas
    matriz[0] = (int *)malloc(10 * sizeof(int *));
    matriz[1] = (int *)malloc(10 * sizeof(int *));

    // Atibuindo valores pela referência de memória
    matriz[0][0] = 100;
    matriz[1][0] = 200;


    printf("Armazenado na linha 1 e coluna 1 e: %d\n", matriz[0][0]);
    printf("Armazenado na linha 2 e coluna 1 e: %d\n", matriz[1][0]);

    // Não foi atribuído nenhum valor para este índice da matriz, portanto o comando abaixo imprimira apenas lixo de memória
    printf("Armazenado na linha 1 e coluna 2 e: %d\n", matriz[0][1]);
    
    getchar();
    return 0;
}