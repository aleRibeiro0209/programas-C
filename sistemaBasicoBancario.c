/*
	Programa para acessar conta de banco e executar as seguintes taferas:
		- Consultar saldo;
		- Depositar;
		- Sacar;
		- Trocar a senha.
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>

// Sessao de prototipacao
void verSenha();
void verLogin();
void consultarSaldo();
void depositar();
void sacar();
void trocarSenha();
void menu();

// Variaveis globais
char user = 'A';
int senha = 123;
int cont = 0;
float saldo = 0.0;

// Programa principal
main() {
	
	puts("Faca login no sistema");
	puts("---------------------");
	
	verLogin();
	
	menu();
	
}// Fim do programa principal

// Funcao para verificar login
void verLogin() {

	char usuario = ' ';
	
	printf("Login: ");
	scanf(" %c", &usuario);
	
	if(toupper(usuario) == user) {
		verSenha();
	} else {
		puts("Usuario invalido - Tente novamente!");
		verLogin();	
	}
}// Fim da funcao verificar login

// Funcao para Verificar Senha
void verSenha(){

	int password = 0;
	
	printf("Senha: ");
	scanf("%d", &password);
	
	if (password == senha){
		cont = 0;
		puts("Acesso concedido!\n");
		Sleep(3000);
	} else {
		puts("Senha invalida - Tente novamente");
		cont++;
		if (cont > 2) {
			Sleep(3000);
			puts("Usuario bloqueado!");
			exit(0);
		}
		verSenha();
	}
}// Fim da funcao Verificar Senha

// Funcao que exibe o menu do programa
void menu(){

	int opcaoEscolhida = 0;
	puts("+----------------------------------------------------------------------------------------+");
	puts("| 1 - Consultar Saldo | 2 - Depositar | 3 - Sacar | 4 - Trocar Senha | 5 - Sair da conta |");
	puts("+----------------------------------------------------------------------------------------+");
	
	while (1)
	{
		printf("\nDigite a opcao desejada: ");
		scanf("%d", &opcaoEscolhida);

		switch (opcaoEscolhida)
		{
			case 1: 
				consultarSaldo();
				break;
			case 2: 
				depositar();
				break;
			case 3: 
				sacar();
				break;
			case 4: 
				trocarSenha();
				break;
			case 5: 
				Sleep(5000);
                puts("\n+---------------------+");
				puts("| Sistema finalizado! |");
                puts("+---------------------+");
				exit(0);
		}
	}
}

// Funcao para consultar saldo
void consultarSaldo() {
	printf("Saldo: %.2f\n", saldo);
} // Fim da funcao consultar saldo

// Funcao para depositar
void depositar(){
	verSenha();

	float deposito = 0.0;
	printf("Digite o valor que deseja depositar: ");
	scanf("%f", &deposito);
	
	if(deposito != 0) {
		saldo += deposito;
		Sleep(3000);
		puts("Deposito aprovado!");
	} else {
		puts("Valor de deposito invalido - Tente novamente!");
	}
}// Fim da funcao de deposito

// Funcao para sacar dinheiro
void sacar(){
	verSenha();

	float saque = 0.0;
	printf("Digite o valor que deseja sacar: ");
	scanf("%f", &saque);
	
	if(saque != 0) {
		saldo -= saque;
		Sleep(3000);
		puts("Saque aprovado!");
	} else {
		puts("Valor de saque invalido - Tente novamente!");
	}
}// Fim da funcao sacar dinheiro

// Funcao para trocar senha
void trocarSenha(){

	int novaSenha = 0;
	int novaSenhaAux = 0;

	puts("\nDigite a senha atual");
	verSenha();

	printf("Digite a nova senha: ");
	scanf("%d", &novaSenha);

	printf("Digite novamente a nova senha: ");
	scanf("%d", &novaSenhaAux);

	if (novaSenha == novaSenhaAux)
	{
		Sleep(3000);
		puts("Senha alterada com sucesso!");
		senha = novaSenha;
	} else
	{
		puts("Senhas diferentes - Tente novamente!");
		trocarSenha();
	}
}// Fim da funcao trocar senha