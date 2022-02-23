#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Say hello to a certain person
    string answer = get_string("What's your name? ");
    printf("Hello, %s\n", answer);
}