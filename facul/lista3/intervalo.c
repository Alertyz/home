#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, N, count = 0;
    scanf("%i", &j);

    for (i = 0; i < j; i++)
        {
            scanf("%i", &N);
            if (N >= 10 && N <= 20)
                {
                    count++;
                }
        }

    printf("%i in\n", count);
    count = abs(count - j);
    printf("%i out\n", count);

    return 0;

}
