#include <stdio.h>

int main()
{
    int i, x[10], soma;
    scanf("%d", &soma);

    for(i = 0; i < 10; i++)
    {
        x[i] = soma;
        printf("X[%d] = %d\n",i ,x[i]);
        soma = soma * 2;

    }
}
