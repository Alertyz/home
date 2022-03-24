#include <stdio.h>
#include <stdlib.h>

int main() {
 
    int x, y, z; 
    
    scanf("%d %d %d", &x, &y, &z); 

    x = (x + y + abs(x - y))/2;
    z = (x + z + abs(x - z))/2;

    printf("%d eh o maior\n", z);
 
    return 0;
}