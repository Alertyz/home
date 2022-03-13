#include <stdio.h>
 
int main() 
{
    int func, horas;
    float salario;
    scanf("%i\n %i\n %f", &func, &horas, &salario);

    salario *= horas;
    printf("NUMBER = %i\n", func);
    printf("SALARY = U$ %0.2f\n", salario);

    return 0;
}