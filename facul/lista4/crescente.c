#include <stdio.h>


int main()
{
    int i, j;

    while(1)
    {
        scanf("%d %d", &i, &j);
        if (i > j)
        {
            printf("Decrescente\n");

        }
        else if (i < j)
        {
            printf("Crescente\n");

        }
        else if (i == j)
        {
            return 0;
        }

    }
}
