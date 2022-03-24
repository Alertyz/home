#include <stdio.h>

int main()
{
    int i, maior, N = 0, atual = 0, N2 = 1;

    scanf("%i", &maior);
    N++;

    for (i = 0; i < 100; i++)
        {

            scanf("%i", &atual);
            N2++;

            if (maior < atual)
                {
                    maior = atual;
                    N = N2;
                }
        }

    printf("%i\n%i\n", maior, N);

    return 0;

}
