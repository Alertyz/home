#include <stdio.h>
#include <cs50.h>

int lenght_check(long copy);
bool check_sum(long copy, int lenght);
bool card_name_check(long copy, int lenght);


int main(void)
{
    
    // Credit card Number
    long credit = get_long("Number: ");
    // Copy of the Credit card Number
    long copy = credit;
    
    // If the credit card number is not between 13 or 16 print invalid
    if (credit < 1000000000000 || credit > 10000000000000000)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // Get the lenght of the credit card
    int lenght = lenght_check(copy);
    
    // Luhn’s Algorithm
    bool c = check_sum(copy, lenght);
    
    // Didn't pass Luhn’s Algorithm
    if (c == false)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // Print name of the credit card
    bool card = card_name_check(copy, lenght);
    
}

int lenght_check(long copy)
{
    
    // Counter
    int counter = 0;
    do
    {
        copy /= 10;
        counter++;
    }
    while (copy != 0);
    
    // Return Counter
    return counter;
    
}

bool check_sum(long copy, int lenght)
{
    //Declaration of Variables
    int digit = 0;
    int one = 0;
    int three = 0;
    
    // Checksum
    for (int i = 0; i < lenght; i++)
    {
        if ((i % 2) == 0)
        {
            digit = copy % 10;
            copy /= 10;
            one += digit;
        }
        else if ((i % 2) != 0)
        {
            digit = copy % 10;
            copy /= 10;
            int two = digit * 2;
            
            if (two >= 10)
            {
                three += two % 10;
                two /= 10;
                three += two;
            }
            else
            {
                three += two;
            }
        }
    }
    one += three;
    if ((one % 10) == 0) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool card_name_check(long copy, int lenght)
{
    for (int i = 0; i < lenght - 2; i++)
    {
        copy /= 10;
    }
    if (copy == 34 || copy == 37)
    {
        printf("AMEX\n");
        return true;
    }
    if (copy >= 51 && copy <= 55)
    {
        printf("MASTERCARD\n");
        return true;
    }
    copy /= 10;
    if (copy == 4)
    {
        printf("VISA\n");
        return true;
    }
    printf("INVALID\n");
    return false;
}