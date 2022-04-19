#include <stdio.h>

int main()
{
    int i, j;

    for (i = 1, j = 7; i <= 9; j-=1)
    {
        
        printf("I=%i J=%i\n", i , j);

        if (j == 5)
        {
            j = 8;
            i += 2;
        }
    }

    return 0;

}