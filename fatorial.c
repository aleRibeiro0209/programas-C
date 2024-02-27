// Escreva uma função em C chamada fatorial que receba um número inteiro como parâmetro e retorne o fatorial desse número. Em seguida, escreva um programa principal que leia um número fornecido pelo usuário e chame a função fatorial para calcular e imprimir seu fatorial.

#include <stdio.h>

// Prototipação
int fatorial(int);

// Função principal
int main(){

    int fat;

    printf("Digite um numero: ");
    scanf("%d", &fat);

    // Chamando a função
    int resultFat = fatorial(fat);

    printf("\nO fatorial de %d e: %d", fat, resultFat);

    getchar();
    return 0;
}

// Função para encontrar o fatorial do numero digitado
int fatorial(int fat){

    int result;
    result = 1;

    for(int i = fat; i > 0; i--){
        result = result * i;
    }

    return result;
}