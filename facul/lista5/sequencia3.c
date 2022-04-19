#include <stdio.h>

int main()
{
    float i, j;
    int count = 0, count2 = 0;

    for (i = 0, j = 1; i <= 2.2; j++)
    {
        count++;
        if (i == 0 || (count2 % 5) == 0)
        {
            printf("I=%0.0f J=%0.0f\n", i , j);
        }
        else
        {
            printf("I=%0.1f J=%0.1f\n", i , j);
        }
        if (count == 3)
        {
            i += 0.2;
            j = 0 + i;
            count = 0;
            count2++;
        }

    }
    
    return 0;

}