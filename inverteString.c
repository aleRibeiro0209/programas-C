// Escreva uma função em C chamada inverteString que receba uma string como parâmetro e a inverta. Em seguida, escreva um programa principal que leia uma string fornecida pelo usuário, chame a função inverteString e imprima a string invertida.

#include <stdio.h>
#include <string.h>

// Sessão de prototipação
void inverteString(char *);


// Função principal
int main(){
    
    char frase[100];

    printf("Digite o conteudo da String: ");
    gets(frase);
     
    inverteString(&frase);

    getchar();
    return 0;
}// Fim da função principal


// Função para inverter e imprimir uma string. Essa função recebe como parâmetro o ponteiro da string(no caso o valor hexadecimal do endereço de memória)
void inverteString(char *frase){

    // A função strlen é uma função da biblioteca string.h e captura o tamanho da string
    int tamanhoS = strlen(frase); 
    char fraseInvertida[100]; 
    char aux;

    for (int i = 0; i < tamanhoS; i++)
    {
        aux = frase[i];
        fraseInvertida[i] = frase[tamanhoS - 1 - i];
    }

    // Adicionando o elemento 'nulo' ao final da string. Para garantir que o output(saída) tenha o resultado esperado e precisão(evita que tenha lixo de memória após os caracteres utilizados na string).
    fraseInvertida[tamanhoS] = '\0';
    
    printf("A String invertida fica: %s", fraseInvertida);
}