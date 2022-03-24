#include <stdio.h>

int main()
{
    int i, count = 0;
    float posi, media = 0;

    for (i = 0; i < 6; i++)
        {
            scanf("%f", &posi);
            if (posi > 0)
            {
                media += posi;
                count++;
            }
        }

    printf("%i valores positivos\n", count);
    printf("%0.1f\n", media/ count);
    return 0;

}
