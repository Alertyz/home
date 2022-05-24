#include <stdio.h>


int main()
{
    int ini, fim, i, j, fatorial;
    scanf("%i %i", &ini, &fim);

    for(i = ini+1; i < fim; i++)
    {
        fatorial = 1;
        for (j = 1; j <= i; j++)
        {
            fatorial *= j;
        }
        printf("%i\n", fatorial);
    }

}
