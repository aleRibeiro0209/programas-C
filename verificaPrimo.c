// Escreva uma função em C chamada verificaPrimo que receba um número inteiro como parâmetro e retorne verdadeiro se o número for primo e falso caso contrário. Em seguida, escreva um programa principal que leia um número fornecido pelo usuário e chame a função verificaPrimo para verificar se é primo ou não, imprimindo o resultado correspondente.

// Inclusão da biblioteca Standard Input Output
#include <stdio.h>

// Prototipação
int verificaPrimo(int);

// Função principal
int main(){

    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    int verific = verificaPrimo(num);

    if (verific)
    {
        printf("O numero %d e primo", num);
    } else {
        printf("O numero %d nao e primo", num);
    }

    getchar();
    return 0;
}// Fim do programa principal

// Função para verificar se o numero digitado é primo
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

    // Para incluir o numero 1 como um numero primo
    if (n==1)
    {
        return 1;
    } 
    else if (divisores == 2)
    {
        return 1;
    } else 
    {
        return 0;
    }
}