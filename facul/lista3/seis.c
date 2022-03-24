#include <stdio.h>

int main()
{
    int i, j;
    scanf("%i", &j);
    if (j % 2 == 0)
        {
            j++;
        }


    for (i = 0; i < 6; i++)
        {
            printf("%i\n", j);
            j += 2;
        }

    return 0;

}
