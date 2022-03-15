#include <stdio.h>

int main()
{
    int number, times;
    float total = 0;
    scanf("%i %i", &number, &times);

    switch(number) 
    {
        case 1 : total += 4;
            break;
        case 2 : total += 4.50;
            break;
        case 3 : total += 5;
            break;
        case 4 : total += 2;
            break;
        case 5 : total += 1.50;
            break;
        default: printf("Opcão Invalida!\n");
    }

    total *= times;
    printf("Total: R$ %.2f\n", total);
    
    return 0;

}