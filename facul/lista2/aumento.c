#include <stdio.h>

int main()
{
    float salario;
    scanf("%f", &salario);

    float copy = salario;
    int count;

    if (salario >= 0 && salario <= 400)
    {
        salario = salario * 15 / 100 + salario;
        count = 15; 
    }
    else if (salario >= 400.01 && salario <= 800)
    {
        salario = salario * 12 / 100 + salario;
        count = 12;
    }
    else if (salario >= 800.01 && salario <= 1200)
    {
        salario = salario * 10 / 100 + salario;
        count = 10;
    }
    else if (salario >= 1200.01 && salario <= 2000)
    {
        salario = salario * 7 / 100 + salario;
        count = 7;
    }
    else if (salario > 2000)
    {
        salario = salario * 4 / 100 + salario;
        count = 4;
    }
    char p = '%';

    printf("Novo salario: %0.2f\n", salario);
    printf("Reajuste ganho: %0.2f\n", (salario - copy));
    printf("Em percentual: %i %c \n", count, p);
    return 0;

}