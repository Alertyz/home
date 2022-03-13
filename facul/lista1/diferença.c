#include <stdio.h>
 
int main() 
{
    int A, B, C, D;
    scanf("%i\n %i\n %i\n %i", &A, &B, &C, &D);

    A = (A * B - C * D);
    
    printf("DIFERENCA = %i\n", A);

    return 0;
}