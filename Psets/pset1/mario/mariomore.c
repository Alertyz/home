#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    // Prompt for height
    int h = get_int("Height: ");
    
    // retornar o valor de 1 a 8
    if (h < 1 || h > 8)
    {
        do
        {
            h = get_int("Height: ");
        }
        while (h < 1 || h > 8);
    }
    
    // Pyramid
    int d = h;
    // height -1
    int y = h - 1;
    // zero
    int s = 0;
    // middle
    int t = 2;
    
    // Print Pyramid
    for (int n = 0; n < h; n++)
    {
        for (int p = s; p < y; p++)
        {
            printf(" ");
        }
        for (int w = h + 1; w > d; w--)
        {
            printf("#");
        }
        for (int e = s; e < t; e++)
        {
            printf(" ");
        }
        for (int i = h + 1; i > d; i--)
        {
            printf("#");
        }
        y = y - 1;
        d = d - 1;
        s = 0;
        printf("\n");
    }
}
