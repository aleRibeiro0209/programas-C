/*
    SISTEMA DE GERENCIAMENTO DE ESTOQUE:
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
void consultarEstoque();
void atualizarQuantidadeProduto();
void calcExibirValorTotalProduto();
void menu();

// Definicao de Struct
typedef struct DadosProduto 
{
    char nome[50];
    int codigo;
    int quantidade;
    float precoUnitario;
};

typedef struct No {
    struct DadosProduto produto;
    struct No *prox;
};

// Declaracao de variaveis globais
struct No *inicio = NULL;

// Programa principal
main(){

    puts("+---------------- Sistema inicializado! ---------------+\n");

    menu();

}// Fim programa principal

// Funcao Menu
void menu(){

    int opcaoEscolhida = 0;

    while (1)
    {
        // Imprime menu
        puts("+------------------------------------------------------+");
        puts("|           1 - Adicionar novo produto                 |\n|           2 - Consulta de Estoque                    |\n|           3 - Atualizar quantidade em Estoque        |\n|           4 - Exibir valor total do Estoque          |\n|           5 - Sair do sistema                        |");
        puts("+------------------------------------------------------+");

        // Solicita ao usuario a opcao
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcaoEscolhida);

        // Teste logico para saber a opcao desejada e chamar a funcao correspondente
        switch (opcaoEscolhida)
        {
            case 1:
                adicionarProduto();
                break;
            
            case 2:
                consultarEstoque();
                break;
            
            case 3:
                atualizarQuantidadeProduto();
                break;

            case 4:
                calcExibirValorTotalProduto();
                break;

            case 5:
                Sleep(3000);
                puts("\n\n+---------------- Sistema finalizado! -----------------+");
                exit(0);
            
            default:
                puts("Opcao Invalida - Tente Novamente!");
                break;
            
        }

        puts("\n\n==> PRESSIONE QUALQUER TECLA PARA PROSSEGUIR <==");
        getch();
        system("cls");
    }
}// Fim funcao Menu

// Funcao para adicionar um novo produto ao estoque
void adicionarProduto() {

    // Declaracao de variaveis do tipo das Structs criadas
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    struct DadosProduto produto;
    
    // Para tratar caso ocorra algum erro na alocacao da memoria
    if (novo == NULL)
    {
        return;
    }

    // Solicita ao usuario os dados do produto
    printf("\nDigite o nome do produto: ");
    scanf("%s", &produto.nome);

    printf("Digite o codigo do produto: ");
    scanf("%d", &produto.codigo);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &produto.quantidade);

    printf("Digite o preco unitario do produto: ");
    scanf("%f", &produto.precoUnitario);

    // Verifica se o codigo ja existe na lista
    struct No *atual = inicio;
    while (atual != NULL)
    {
        if (produto.codigo == atual->produto.codigo)
        {
            puts("\nCodigo existente!");
            free(novo); // Libera a memoria alocada para o No novo
            return;
        }
        atual = atual->prox;
    }

    // A variavel novo do tipo No recebe o produto ou seja todos os dados inseridos e o proximo No recebe Null
    novo->produto = produto;
    novo->prox = NULL;

    // Se o valor de inicio for igual a Null ou seja a Lista estiver vazia o No inicio recebe o novo produto
    if(inicio == NULL){
        inicio = novo;
    } else {
        // Senao enquanto o proximo No do No atual for diferente Null executa para adicionar o novo produto no ultimo No
        struct No *atual = inicio;

        while (atual->prox != NULL)
        {   
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}// Fim funcao adicionarProduto

// Funcao para consultar o estoque
void consultarEstoque(){

    struct No *atual = inicio;

    // Checa se o estoque tem algum produto
    if (atual == NULL)
    {
        puts("\nO estoque esta vazio!");
        return;
    }

    // Se o valor de proximo for igual a Null executa uma vez so
    if(atual->prox == NULL){
        puts("\n| CODIGO -- NOME -- QUANTIDADE -- PRECO UNITARIO |");
        printf("\n| %d -- ", atual->produto.codigo);
        printf("%s -- ", atual->produto.nome);
        printf("%d -- ", atual->produto.quantidade);
        printf("%.2f |", atual->produto.precoUnitario);
    } else {  
        puts("\n| CODIGO -- NOME -- QUANTIDADE -- PRECO UNITARIO |");
        // Senao enquanto atual diferente de Null executa   
        while (atual != NULL)
        {
            printf("\n| %d -- ", atual->produto.codigo);
            printf("%s -- ", atual->produto.nome);
            printf("%d -- ", atual->produto.quantidade);
            printf("%.2f", atual->produto.precoUnitario);
            atual = atual->prox;
        }
    }
}// Fim funcao consultarEstoque

// Funcao para buscar um produto pelo seu codigo e alterar a quantidade dele, assim atualizando o estoque
void atualizarQuantidadeProduto(){

    struct No *atual = inicio;
    int buscaCodigo = 0;
    int novaQuantidade = 0;

    // Checa se o estoque tem algum produto 
    if (atual == NULL)
        {
            puts("\nO estoque esta vazio!");
            return;
        }


    // Solicita ao usuario o codigo do produto que ele deseja alterar a quantidade 
    printf("\nDigite o codigo do produto para busca: ");
    scanf("%d", &buscaCodigo);

    // Se o valor de proximo for igual a Null executa uma vez so
    if(atual->prox == NULL){
       if (buscaCodigo == atual->produto.codigo)
       {
            printf("Digite a nova quantidade do %s: ", atual->produto.nome);
            scanf("%d", &novaQuantidade);
            atual->produto.quantidade = novaQuantidade;
       } else{
            puts("Codigo nao encontrado!"); 
       }
    } else {    
        while (atual != NULL)
        {
            // Senao enquanto atual diferente de Null executa 
            if (buscaCodigo == atual->produto.codigo)
            {
                printf("Digite a nova quantidade do %s: ", atual->produto.nome);
                scanf("%d", &novaQuantidade);
                atual->produto.quantidade = novaQuantidade;
                puts("Atualizacao bem sucedida!");
                return;
            }
            atual = atual->prox;
        }

        // Se depois de percorrer todo o estoque não encontrar 
        puts("\nCodigo nao encontrado - Tente novamente!"); 
    }     

}// Fim funcao atualizarQuantidadeProduto


// Calcular e exibir o valor total do estoque (quantidade disponível multiplicada pelo preço unitário) e o valor médio dos produtos.
void calcExibirValorTotalProduto(){

    // Declaracao de variaveis
    struct No *atual = inicio;
    float valorTotalEstoque = 0.0;
    float valorMedio = 0.0;
    int somaQuantidadeTotal = 0;
    float somaPrecoUnitario = 0;

    // Checa se o estoque tem algum produto
    if (atual == NULL)
        {
            puts("\nO estoque esta vazio!");
            return;
        }

    // Se o valor de proximo for igual a Null executa uma vez so
    if(atual->prox == NULL){
        valorTotalEstoque += (atual->produto.quantidade * atual->produto.precoUnitario);
        somaQuantidadeTotal += atual->produto.quantidade;
        somaPrecoUnitario += atual->produto.precoUnitario;
    } else {  
        // Senao enquanto atual diferente de Null executa 
        while (atual != NULL)
        {
            valorTotalEstoque += (atual->produto.quantidade * atual->produto.precoUnitario);
            somaQuantidadeTotal += atual->produto.quantidade;
            somaPrecoUnitario += atual->produto.precoUnitario;
            atual = atual->prox;
        }
    }

    // Verifica se a quantidade total de produtos é maior que zero
    if (somaQuantidadeTotal > 0)
    {
        // Calculo para descobrir o valor medio dos produtos
        valorMedio = somaPrecoUnitario / somaQuantidadeTotal;
        printf("\nValor total do estoque: %.2f", valorTotalEstoque);
        printf("\nValor medio dos produtos: %.2f\n", valorMedio);
    } else {
        puts("\nImpossivel calcular o valor medio de produtos");
    }

    
}// Fim funcao calcExibirValorTotalProduto