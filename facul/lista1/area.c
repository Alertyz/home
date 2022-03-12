#include <stdio.h>
 
 
int main() 
{
 
    double pi = 3.14159;
    double raio;

    scanf("%lf", &raio);

    double area = pi * (raio * raio);

    printf("A=%0.4lf\n", area);
 
    return 0;
}