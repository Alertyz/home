#include <stdio.h>

int main()
{
    int n , lugar = 0, menor = 99999999, i;
    scanf("%d", &n);
    int x[n];

    for (i = 0; i < n; i++)
    {   
        scanf("%d", &x[i]);
        if (menor > x[i])
        {
            menor = x[i];
            lugar = i;
        }
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", lugar);

    return 0;

}