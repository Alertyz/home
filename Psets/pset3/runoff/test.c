#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main (void)
{
    int votes = get_int("votes: ");
    
    float half = votes / 2;
    int halfi = round(half);
    printf("%i", halfi);
}