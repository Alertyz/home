#include <stdio.h>

void dez(char* string);

int main()
{

    char um[101];
    char dois[101];
    char tres[101];

    scanf(" %[^\n]", um);
    scanf(" %[^\n]", dois);
    scanf(" %[^\n]", tres);

    printf("%s%s%s\n", um, dois, tres);
    printf("%s%s%s\n", dois, tres, um);
    printf("%s%s%s\n", tres, um, dois);

    dez(um);
    dez(dois);
    dez(tres);
    
    printf("\n");
    return 0;

}

void dez(char* string)
{

    int count = 0;
    while (string[count] != '\0' && count < 10)
    {
        printf("%c", string[count]);
        count++;
    }

}