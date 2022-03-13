#include <stdio.h>
 
int main() 
{
    int A, B, D, E;
    float C, F;
    scanf("%i %i %f", &A, &B, &C);
    scanf("%i %i %f", &D, &E, &F);


    C = C * B + (F * E);
    
    printf("VALOR A PAGAR: R$ %0.2f\n", C);

    return 0;
}