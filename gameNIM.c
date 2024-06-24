/*
    Regras a serem implementadas:
        - A quantidade de Palitos Total deve ser informada no inicio do jogo. (entre 5 e 33  palitos) através de parâmetro.
        - A quantidade máxima de palitos a serem retirados devem ser informados no inicio. O Jogador deve digitar (3 à 5)
        - Perde quem ficar com o ultimo palito.
        - Deverá ter tratamento de erro. (impedir números inválidos letras)
        - Deve informar os palitos retirados e palitos faltantes
        - Deve exibir mensagem informando fim do jogo.
*/

// Importacao de bibliotecas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Prototipacao
void criarMontes(int *);
void jogadorUm();
void jogadorDois();

// Variaveis globais
int numPalitos, totalPalitosRetirados, quantidadeMontes, totalPalitosInclusos, opcao, quantidadeRetirada;
int *array;

main () {
    puts("+----------------------------------+");
    puts("| CONFIGURACAO INICIAL DO JOGO NIM |");
    puts("+----------------------------------+");
    printf("\nQuantos montes tera: ");
    scanf("%d", &quantidadeMontes);
    array = (int *)malloc(quantidadeMontes * sizeof(int));

    if (array == NULL) {
        printf("Erro na alocacao de memoria\n");
        return;
    }

    for (int i = 0; i < quantidadeMontes; i++) {
        printf("Digite a quantidade de palitos do monte %d: ", i+1);
        scanf("%d", &numPalitos);
        array[i] = numPalitos;
        totalPalitosInclusos += numPalitos;
    }

    if (totalPalitosInclusos < 5 || totalPalitosInclusos > 33) {
        puts("\nValor total de palitos invalido. Insira um valor maior que 4 e menor que 34");
        return;
    }

    printf("\nDigite a quantidade maxima de palitos a serem retirados: ");
    scanf("%d", &totalPalitosRetirados);

    if (totalPalitosRetirados < 3 || totalPalitosRetirados > 5)
    {
        puts("\nValor invalido o numero maximo de palitos a serem retirados deve ser maior que 2 e menor que 6");
        return;
    }

    puts("==================================");
    puts("Jogo inicializado:");
    criarMontes(array);

    while (totalPalitosInclusos > 0)
    {

        jogadorUm();

        if (totalPalitosInclusos == 0) {
            system("cls");
            puts("+-----------------------+");
            puts("|    Jogador 2 venceu   |");
            puts("+-----------------------+\n");
            break;
        }
            
        jogadorDois();

        if (totalPalitosInclusos == 0) {
            system("cls");
            puts("+---------------- -------+");
            puts("|    Jogador 1 venceu   |");
            puts("+-----------------------+\n");
        }
            
    }
    puts("Fim de jogo");
    getch();
    
}// Fim da funcao principal

void criarMontes(int *array) {
    for(int i = 0; i < quantidadeMontes; i++) {
        printf("Monte %d: ", i+1);
        for (int j = 0; j < array[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
} // Fim da funcao criarMontes

void jogadorUm() {
    system("cls");
    puts("CONFIGURACAO DOS MONTES");
    puts("==================================\n");
    criarMontes(array);
    puts("\n==================================\n");
    puts("+-----------------------+");
    puts("| Jogador 1 e a sua vez |");
    puts("+-----------------------+");
    printf("\nDigite o monte que deseja retirar: ");
    scanf("%d", &opcao);
    printf("Digite a quantidade de pecas de deseja retirar: ");
    scanf("%d", &quantidadeRetirada);

    if (quantidadeRetirada > 0 && quantidadeRetirada <= totalPalitosRetirados && quantidadeRetirada <= array[opcao-1] && opcao <= quantidadeMontes) {        
        array[opcao-1] -= quantidadeRetirada;
        totalPalitosInclusos -= quantidadeRetirada;
        printf("\n\nPressione qualquer tecla para continuar...");
        getch();
    } else {
        puts("\n\nQuantidade invalida pois e menor que zero ou ultrapassa o limite de palitos a serem retirados");
        puts("---- Tente Novamente ----");
        getch();
        jogadorUm();
    }
}

void jogadorDois() {
    system("cls");
    puts("CONFIGURACAO DOS MONTES");
    puts("==================================\n");
    criarMontes(array);
    puts("\n==================================\n");
    puts("+-----------------------+");
    puts("| Jogador 2 e a sua vez |");
    puts("+-----------------------+");
    printf("\nDigite o monte que deseja retirar: ");
    scanf("%d", &opcao);
    printf("Digite a quantidade de pecas de deseja retirar: ");
    scanf("%d", &quantidadeRetirada);

    if (quantidadeRetirada > 0 && quantidadeRetirada <= totalPalitosRetirados && quantidadeRetirada <= array[opcao-1] && opcao <= quantidadeMontes) {        
        array[opcao-1] -= quantidadeRetirada;
        totalPalitosInclusos -= quantidadeRetirada;
        printf("\n\nPressione qualquer tecla para continuar...");
        getch();
    } else {
        puts("\n\nQuantidade invalida pois e menor que zero ou ultrapassa o limite de palitos a serem retirados");
        puts("---- Tente Novamente ----");
        getch();
        jogadorDois();
    }
}