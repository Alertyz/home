#include <stdio.h>


int main()
{
    int i, count = 0;
    float posi;

    for (i = 0; i < 6; i++)
        {
            scanf("%f", &posi);
            if (posi > 0)
            {
                count++;
            }
        }

    printf("%i valores positivos\n", count);
    return 0;

}
