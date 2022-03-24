#include <stdio.h>

int main()
{
    int i, j, N, r = 0, s = 0, c = 0;
    char ca;
    scanf("%d", &j);

    for (i = 0; i < j; i++)
        {
            scanf("%d %c", &N, &ca);
            if (ca == 'C')
                {
                    c += N;
                }
            else if (ca == 'R')
                {
                    r += N;
                }
            else if (ca == 'S')
                {
                    s += N;
                }
        }

    printf("Total: %d cobaias\n", c + r + s);
    printf("Total de coelhos: %d\n", c);
    printf("Total de ratos: %d\n", r);
    printf("Total de sapos: %d\n", s);
    printf("Percentual de coelhos: %.2f %%\n", (float)c * 100.0 / (c + r + s));
    printf("Percentual de ratos: %.2f %%\n", (float)r * 100.0 / (c + r + s));
    printf("Percentual de sapos: %.2f %%\n", (float)s * 100.0 / (c + r + s));

    return 0;

}
