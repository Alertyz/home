#include <stdio.h>


int main()
{
    int i, j;
    scanf("%d", &j);

    for (i = 0; i < j+2; i++)
        {
            if (((i % 2) == 0) && (i != 0))
            {
                printf("%d^2 = %d\n", i, i * i);
            }
        }

    return 0;

}
