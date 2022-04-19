#include <stdio.h>

int main()
{
    int m = 1, n = 1, i, soma;
    
    while (m > 0 && n > 0)
    {
        soma = 0;
        scanf("%d %d", &m, &n);
        if (m > 0 && n > 0)
        {
            if (n < m)
            {
                for (i = n; i <= m; i++)
                {
                    printf("%d ", i);
                    soma += i;
                }
                printf("Sum=%d\n", soma);
            }
            else
            {
                for (i = m; i <= n; i++)
                {
                    printf("%d ", i);
            
                    soma += i;
                }
                printf("Sum=%d\n", soma);
            }
        }
    }
    
    return 0;

}