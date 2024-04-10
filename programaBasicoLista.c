// Programa para criar uma lista básica - Aprendendo o conceito de lista

// Importanto bibliotecas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Declaracao da estrutura Pessoas
typedef struct {
    char nome;
    int idade;
} Pessoas;

// Funcao principal
int main() 
{
    // Declara variaveis do tipo Pessoas
    Pessoas p1, p2, p3;

    // Imprime o valor hexadecimal das variaveis criadas
    printf("Endereco de memoria P1: %d", &p1);
    printf("\nEndereco de memoria P2: %d", &p2);
    printf("\nEndereco de memoria P3: %d", &p3);

    return 0;
}// Fim funcao principal