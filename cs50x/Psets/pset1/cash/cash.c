#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    // how much change is owed
    float o = get_float("Change owed: ");
    
    if (o < 0)
    {
        do
        {
            o = get_float("Change owed: ");
        }
        while (o < 0);
    }
    // convert dollar to cents
    int c = round(o * 100);
    // number of quarters used
    int q = 0;
    // number of dimes used
    int d = 0;
    // number of nickels used
    int n = 0;
    // number of pennies used
    int p = 0;
    
    // if greater than or equal to subtract 25
    if (c > 25 || c == 25)
    {
        do
        {
            c = c - 25;
            q = q + 1;
        }
        while (c > 25 || c == 25);
    }
    // if greater than or equal to subtract 10
    if (c > 10 || c == 10)
    {
        do
        {
            c = c - 10;
            d = d + 1;
        }
        while (c > 10 || c == 10);
    }
    // if greater than or equal to subtract 5
    if (c > 5 || c == 5)
    {
        do
        {
            c = c - 5;
            n = n + 1;
        }
        while (c > 5 || c == 5);
    }
    // if greater than or equal to subtract 1
    if (c > 1 || c == 1)
    {
        do
        {
            c = c - 1;
            p = p + 1;
        }
        while (c > 1 || c == 1);
    }
    // number of coins used
    int counter = 0 + q + d + n + p;
    
    printf("%i\n", counter);
}