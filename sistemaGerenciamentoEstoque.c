/*
    SISTEMA DE GERENCIAMENTO DE ESTOQUE - PROJETO EM ANDAMENTO

        - Permitir ao usuário adicionar novos produtos ao estoque, incluindo nome, código, quantidade e preço unitário.
        - Permitir ao usuário visualizar o estoque atual, mostrando o nome, código, quantidade disponível e preço unitário de cada produto.
        - Permitir ao usuário buscar um produto pelo código e atualizar sua quantidade no estoque, seja para adicionar mais unidades ou remover.
        - Calcular e exibir o valor total do estoque (quantidade disponível multiplicada pelo preço unitário) e o valor médio dos produtos.
*/

// Importacao de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Sessao de prototipacao
void adicionarProduto();
//  void consultarEstoque();
//  void atualizarQuantidadeProduto();
//  void calcExibirValorTotalProduto();
void menu();

// Declaracao de variaveis globais

// Definicao de Struct
struct DadosProduto 
{
    char nome[50];
    int codigo;
    int quantidade;
    float precoUnitario;
};

// Programa principal
main(){

    puts("Sistema inicializado!");

    menu();

}// Fim programa principal

// Funcao Menu
void menu(){

    int opcaoEscolhida = 0;

    puts("+------------------------------------------------------+");
    puts("|           1 - Adicionar novo produto                 |\n|           2 - Consulta de Estoque                    |\n|           3 - Atualizar quantidade em Estoque        |\n|           4 - Exibir valor total do Estoque          |\n|           5 - Sair do sistema                        |");
    puts("+------------------------------------------------------+");

    while (1)
    {
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcaoEscolhida);

        switch (opcaoEscolhida)
        {
            case 1:
                adicionarProduto();
                break;
            
            case 2:
                consultarEstoque();
                break;
            
            case 3:
                // atualizarQuantidadeProduto();
                break;

            case 4:
                // calcExibirValorTotalProduto();
                break;

            case 5:
                puts("Sistema finalizado!");
                Sleep(3000);
                exit(0);
            
        }
    }
}// Fim funcao Menu

// Funcao para adicionar um novo produto ao estoque
void adicionarProduto() {

    struct DadosProduto produto;

    printf("Digite o nome do produto: ");
    scanf("%s", &produto.nome);

    printf("Digite o codigo do produto: ");
    scanf("%d", &produto.codigo);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &produto.quantidade);

    printf("Digite o preco unitario do produto: ");
    scanf("%f", &produto.precoUnitario);

    // Proximo passo: Armazenar as informacoes inseridas.

}// Fim funcao adicionarProduto