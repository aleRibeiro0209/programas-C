/*
    Name: programaBasicoPilha.c
    Author: Alexandre Ribeiro
    Date: 10/04/24 09:48
    Description: Programa para demonstrar o algoritmo da Pilha - LIFO => Last in First out

    - A conversão binário é limitada em relação ao tamanho da máximo da minha pilha gi
*/
// Importando bibliotecas
#include <stdio.h>
#include <conio.h>
#include <windows.h>

// Sessao de prototipacao
void menu();
void push();
int pop();
int isFull();
int isEmpty();
void listarPilha();
void top();

// Prototipacao das funcoes para conversao binaria
void conversorBinario();
void exibirBinario();
void pushBinario(int);

// Variaveis globais
int pilha[10];
int topo = -1;

main()
{
    menu();

}// Fim do main

// Funcao que cria um menu para o usuario
void menu(){
    int opcaoEscolha = 0;

    while (1)
    {   
        puts("----------------------------------");
        puts("| 1 - Inserir elemento na pilha  |");
        puts("| 2 - Retirar elemento da pilha  |");
        puts("| 3 - Listar o conteudo na pilha |");
        puts("| 4 - Elemento no topo da pilha  |");
        puts("| 5 - Conversor Binario          |");
        puts("| 6 - Sair do sistema            |");
        puts("----------------------------------");

        printf("Digite a opcao desejada: ");
        scanf("%d", &opcaoEscolha);

        switch (opcaoEscolha)
        {
            case 1:
                push();  
                break;
            
            case 2:
                pop();
                break;
            
            case 3:
                listarPilha();
                break;

            case 4: 
                top();
                break;
            
            case 5:
                conversorBinario();
                break;
            
            case 6:
                Sleep(2000);
                puts("Sistema finalizado!");
                exit(0);

            default:
                puts("\nOpcao invalida -Tente novamente!");
                break;
        }
        puts("\n\n===> PRESSIONE QUALQUER TECLA PARA PROSSEGUIR <===");
        getch();
        system("cls");
    }
    
}

// Funcao que inseri um elemento na pilha
void push(){

    if(isFull())
        puts("\nA Pilha esta cheia - Stack Overflow!");
    else
    {   
        topo++;
        int elemento = 0;
        printf("\nDigite o elemento que deseja inserir na pilha: ");
        scanf("%d", &elemento);
        pilha[topo] = elemento;
    }
    
}

 // Funcao que retira um elemento da pilha
int pop(){
    
    if(isEmpty())
        puts("\nA Pilha esta vazia - Stack is Empty!");
    else
    {
        return pilha[topo--];
        /*
        O codigo abaixo faz a mesma coisa, porém utilizando uma espaço na 
        memoria que pode ser poupado:
            int elemento;
            elemento = pilha[topo];
            topo--;
            return elemento;
        */
    }
}

// Funcao que testa se a Pilha esta cheia
int isFull(){

    if(topo >= 9)
        return 1;
    else 
        return 0;

}

// Funcao que testa se a Pliha esta vazia
int isEmpty(){

    if(topo == -1)
        return 1;
    else 
        return 0;

}

// Funcao para imprimir os valores da Pilha
void listarPilha(){
    puts("\nConteudo da pilha: ");
    if (isEmpty())
        puts("\nPilha vazia");
    else {

        for(int i = 0; i <= topo; i++){
            puts("-------");
            printf("| %d\n", pilha[i]);
        }
        puts("-------");
    }
}

// Funcao que retorna o elemento que esta no topo da pilha
void top(){
    if(isEmpty())
        puts("\nA Pilha esta vazia - Stack is Empty!");
    else
        printf("\nO elemento no topo da pilha e: %d\n", pilha[topo]);
}

// Funcao que converte um numero na base decimal para a base binaria
void conversorBinario(){
    int num, quoc, resto = 0;

    printf("\nDigite um numero na base 10: ");
    scanf("%d", &num);

    while (num >= 1)
    {
        quoc = num/2;
        resto = num%2;
        pushBinario(resto);
        num = quoc;        
    }
    
    exibirBinario();
}

// Funcao que exibi a pilha formatada como equivalente binario
void exibirBinario(){

    puts("\nEquivalente Binario: ");

    while (isEmpty() == 0)
    {
        printf("%d", pilha[topo]);
        pop();
    }
    
}

// Funcao de push exclusiva para a conversam binária
void pushBinario(int elem){

    if(isFull())
        puts("\nA Pilha esta cheia - Stack Overflow!");
    else
    {   
        topo++;
        pilha[topo] = elem;
    }
    
}