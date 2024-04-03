/*
	Programa para acessar conta de banco e executar as seguintes taferas:
		- Consultar saldo;
		- Depositar;
		- Sacar;
		- Trocar a senha.
*/

// Importacao de bibliotecas
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
	
	// Invocando a funcao de verificacao de Login
	verLogin();
	
	// Invocando a funcao menu
	menu();
	
}// Fim do programa principal

// Funcao para verificar login
void verLogin() {

	char usuario = ' ';
	
	// Solicita ao usuario o seu login
	printf("Login: ");
	scanf(" %c", &usuario);
	
	// Transforma o dado recebido em Maiuscula para que não acha diferença entre maiuscula e minuscula. Caso o usuario seja valido invoca a funcao que verifica a Senha, caso seja invalido solicita o login novamente de maneira recursiva
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
	
	// Solicita ao usuario o sua senha
	printf("Senha: ");
	scanf("%d", &password);
	
	// Se a senha informada for igual a senha do usuario o acesso e liberado caso contrario apos tres tentativas o usuario e bloqueado
	if (password == senha){
		cont = 0;
		puts("Acesso concedido!\n");
		Sleep(3000);
	} else {
		puts("Senha invalida - Tente novamente!");
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

	// Imprimir as opcoes de menu
	puts("+----------------------------------------------------------------------------------------+");
	puts("| 1 - Consultar Saldo | 2 - Depositar | 3 - Sacar | 4 - Trocar Senha | 5 - Sair da conta |");
	puts("+----------------------------------------------------------------------------------------+");
	
	// Loop Infinito
	while (1)
	{
		// Solicita ao usuario qual opcao do menu ele deseja 
		printf("\nDigite a opcao desejada: ");
		scanf("%d", &opcaoEscolhida);

		// Teste logico para invocar a funcao desejada pelo usuario 
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
			default:
				puts("Opcao invalida - Tente Novamente!");
		}
	}
}

// Funcao para consultar saldo
void consultarSaldo() {

	// Imprime o valor do Saldo
	printf("Saldo: %.2f\n", saldo);
} // Fim da funcao consultar saldo

// Funcao para depositar
void depositar(){

	// Solicita a senha novamente ao usuario por seguranca
	verSenha();

	float deposito = 0.0;
	
	// Solicita ao usuario o valor que ele deseja depositar
	printf("Digite o valor que deseja depositar: ");
	scanf("%f", &deposito);
	
	// Testa se o valor do deposito e maior que zero antes de permitir o deposito
	if(deposito > 0) {
		saldo += deposito;
		Sleep(3000);
		puts("Deposito aprovado!");
	} else {
		puts("Valor de deposito invalido - Tente novamente!");
	}
}// Fim da funcao de deposito

// Funcao para sacar dinheiro
void sacar(){

	// Solicita a senha novamente ao usuario por seguranca
	verSenha();

	float saque = 0.0;

	// Solicita ao usuario o valor que ele deseja sacar
	printf("Digite o valor que deseja sacar: ");
	scanf("%f", &saque);
	
	// Testa se o valor do saque e maior que zero antes de permitir o saque
	if(saque > 0) {
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

	// Solicita a senha novamente ao usuario por seguranca
	puts("\nDigite a senha atual");
	verSenha();

	// Solicita a nova senha ao usuario
	printf("Digite a nova senha: ");
	scanf("%d", &novaSenha);
	
	// Solicita a nova senha ao usuario novamente
	printf("Digite novamente a nova senha: ");
	scanf("%d", &novaSenhaAux);

	// Teste logico para verificar se a nova senha foi inserida duas vezes corretamente, caso não tenha invoca a funcao para o usuario tentar novamente
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