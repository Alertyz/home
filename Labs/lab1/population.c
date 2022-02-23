#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Prompt for start size
    int x = get_int("start size: ");

    if (x < 9)
    {
        do
        {
            x = get_int("start size: ");
        }
        while (x < 9);
    }
    // Prompt for end size
    int e = get_int("ending size: ");
    
    if (e < x)
    {
        do
        {
            e = get_int("ending size: ");
        } 
        while (e < x);
        
    }
    //Calculation of years until we reach threshold
    //Dead lhamas
    float d = (x / 4);
    //New lhamas
    float n = (x / 3);
    //total lhamas
    float t = x;
    //counter
    int c = 0;
   
    if (t < e)
    {
        do
        {
            x = x + (x / 3) - (x / 4);
            t = x;
            c = c + 1;
        }
        while (t < e);
    }
    
    //Number of years
    printf("Years: %i\n", c);
}

