// Exercício 14: Escreva uma função em C chamada verificaPrimo que receba um número inteiro como parâmetro e retorne verdadeiro se o número for primo e falso caso contrário. Em seguida, escreva um programa principal que leia um número fornecido pelo usuário e chame a função verificaPrimo para verificar se é primo ou não, imprimindo o resultado correspondente.

#include <stdio.h>

// Prototipação
int verificaPrimo(int);

int main(){

    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    int verific = verificaPrimo(num);

    if (verific == 1)
    {
        printf("O numero %d e primo", num);
    } else {
        printf("O numero %d nao e primo", num);
    }

    getchar();
    return 0;
}

int verificaPrimo(int n){

    int divisores;
    divisores = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n%i==0)
        {
            divisores++;
        }
    }
    
    if (divisores == 2)
    {
        return 1;
    } else {
        return 0;
    }
}