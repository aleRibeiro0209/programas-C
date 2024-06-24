#include <stdio.h>

main() {
    int vet[] = {104, 7, 66, 15, -7, 3, 9, 40, 23, 52};
    int n = sizeof(vet)/sizeof(int);
    int i, j, m, aux; i = 0;
    int trocas = 0;

    puts("\n\nImprimindo");
    for (int b = 0; b < n; b++)
    {
       printf(" %d |", vet[b]);
    }

    while (i<n/2)
    {
        m = i;
        j = i + 1;
        do
        {
            if (vet[j] < vet[m])
                m = j;
        j++;
        } while (j < n);
        
        if (i != m)
        {
            aux = vet[i];
            vet[i] = vet[m];
            vet[m] = aux;
            trocas++;
        }
        i++;

        puts("\n\nImprimindo");
        for (int b = 0; b < n; b++)
        {
           printf(" %d |", vet[b]);
        }
        
    }
    printf("\nForam feitas %d trocas", trocas);
}