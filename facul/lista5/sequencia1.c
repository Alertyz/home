#include <stdio.h>

int main()
{
    int i, j;

    for (i = 1, j = 60; j >= 0; i+=3, j-=5)
    {
        printf("I=%i J=%i\n", i , j);
    }

    return 0;

}