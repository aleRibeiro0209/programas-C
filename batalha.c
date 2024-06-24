#include <stdio.h>

void criandoMatriz();
void imprimirMatriz();

char **matriz;

main()
{
    char peca = '+';
    criandoMatriz();
    imprimirMatriz();

    while (1)
    {
        int num1, num2;
        printf("\nDigite a linha: ");
        scanf("%d", &num1);

        printf("\nDigite a coluna: ");
        scanf("%d", &num2);

        if (&matriz[num1][num2] == &matriz[1][1])
        {
           printf("Peca");
           imprimirMatriz();
           break;
        } else
        {
            printf("Agua");
        }
        
    }    

} //Fim do main

void criandoMatriz() {
    
    matriz = (char **)malloc(2 * sizeof(char**));

    //Alocacao dinamica da memoria
    for (int i = 0; i < 2; i++)
    {
        matriz[i] = (char *)malloc(2 * sizeof(char *));
    }

}

void imprimirMatriz() {
    
    // Imprimindo matriz de 0
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matriz[i][j] = '~';
            printf(" %c", matriz[i][j]);
        }
        printf("\n");
    }
}