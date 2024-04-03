/*
	Implementação do conceito de Filas - FIFO - First In First Out
        - Inserir valor na Fila;
        - Retirar valor na Fila;
        - Testar se a Fila esta cheia;
        - Testar se a Fila esta vazia;
        - Imprimir os valores da Fila.
*/
 
// Sessao de Prototipacao
void menu();
void inserir();
int retirar();
int isFull();
int isEmpty();
void imprimirFila();
 
// Sessao de importacao das bibliotecas
#include <conio.h>
#include <stdio.h>
#include <windows.h>
 
// Declaração de Variáveis Globais
int inicio, fim, total;
int senhas[5];

// Programa principal
main()
{
	inicio = 0;
	fim = 0;
	total = 0;
	menu();
}// Fim do programa principal
 
// Funcao que exibe o menu do programa
void menu(){

	int opcaoEscolhida = 0;

    // Loop infinito
	while (1)
	{
        // Imprimindo o menu
		puts("+--------------------------------------------------------------------+");
		puts("| 1 - Inserir | 2 - Retirar | 3 - Imprima Fila | 4 - Sair do Sistema |");
		puts("+--------------------------------------------------------------------+");

        // Solicita ao usuario a opcao do menu
		printf("\nDigite a opcao desejada: ");
		scanf("%d", &opcaoEscolhida);
        
        // Teste logico para invocar a opcao que o usuario selecionar. Caso digite uma opcao invalida retorna "Opcao Invalida!"
		switch (opcaoEscolhida)
		{
			case 1: 
				inserir();
				break;
			case 2: 
				retirar();
				break;
			case 3: 
				imprimirFila();
				break;
			case 4:
				Sleep(5000);
                puts("\n+---------------------+");
				puts("| Sistema finalizado! |");
                puts("+---------------------+");
				exit(0);
			default:
				puts("Opcao Invalida!");
		}

        // Aguarda que o usuario tecle alguma tecla
		getch();
		printf("\nCarregando ...");
		
        // Pausa o sistema por 2 segundos
        Sleep(2000);

        // Limpa o terminal para trazer uma experiencia melhor
		system("cls");
	}
}
 
// Funcao para inserir um elemento na Fila
void inserir()
{
    // Testa se a Fila esta cheia antes de inserir um novo valor
	if(isFull())
		puts("\nA Fila esta cheia!");
	else
	{
		int element = 0;
		printf("\nDigite um numero: ");
		scanf("%d", &element);
		senhas[fim] = element;
		fim = (fim + 1)%5;
		total++;
		puts("Senha Emitida! - Tecle Enter");
	}
}
 
// Funcao para retirar um elemento da Fila
int retirar()
{
    // Testa se a Fila esta vazia antes de retirar um valor
	if(isEmpty())
		puts("\nA Fila esta vazia!");
	else
	{
		int elemento;
		elemento = senhas[inicio];
		inicio = (inicio + 1)%5;
		total--;
        puts("Tarefa Concluida! - Tecle Enter");
		return elemento;
	}
}
 
// Funcao que testa quando a Fila esta cheia - RETORNA 1
int isFull()
{
    // Se a Fila estiver cheia retorna 1 senão 0
	if(total == 5)
		return 1;
	else
		return 0;
}
 
// Funcao que testa quando a Fila esta vazia - RETORNA 1
int isEmpty()
{
    // Se a Fila estiver vazia retorna 1 senão 0
	if(total == 0)
		return 1;
	else
		return 0;
}
 
// Funcao que exibir todos os elementos presentes na Fila
void imprimirFila() 
{
	int i, cont;

    // Testa se a Fila esta vazia antes de imprimir o Conteudo da Fila
	if(isEmpty())
		puts("\nA Fila esta vazia!");
	else
	{
		puts("\nConteudo da Fila: ");
		for(cont = 0, i = inicio; cont < total; cont++)
		{
            // Utilizando operador ternario para mudar a formatacao do texto
			printf(cont < 4 ? "| %d " : "| %d |", senhas[i++]);
			if (i == 5)
				i = 0;
		}
	}
}