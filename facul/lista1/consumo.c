#include <stdio.h>

int main() {
 
    int x; 
    double y;
    scanf("%i\n %lf", &x, &y); 

    y = x / y;

    printf("%0.3lf km/l\n", y);
 
    return 0;
}