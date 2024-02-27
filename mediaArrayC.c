// Escreva uma função em C chamada media que receba um array de números inteiros e seu tamanho como parâmetros e retorne a média dos números. Em seguida, escreva um programa principal que leia uma sequência de números fornecidos pelo usuário, armazene-os em um array e chame a função media para calcular e imprimir a média.
#include <stdio.h>

// Prototipação
float media(float tamanho, int *sequenciaNumerica);

// Função principal
int main(){

    int sequenciaNumerica[5]; 
    float t;
    t = 5;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o %d numero da sequencia numerica: ", i+1);
        scanf("%d", &sequenciaNumerica[i]);
    }

    // Chamando a função media 
    float resultMedia = media(t, sequenciaNumerica);

    printf("\nO resultado da media dos numero inseridos no array e: %.2f", resultMedia);

    getchar();
    return 0;
}

// Funcao para calcular media
float media(float tamanho, int *sequenciaNumerica){

    int soma;
    float m;
    soma = 0;
    m = 0.0;

    for (int t = 0; t < tamanho; t++)
    {
        soma += sequenciaNumerica[t];
    }
    
    m = soma/tamanho;

    return m;

}