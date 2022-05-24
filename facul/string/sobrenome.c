#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool determinar(char* string);

int main()
{

    int i, j = 0, n;
    scanf("%d", &n);

    bool result[n];
    char sobrenomes[n][43];

    for (i = 0; i < n ; i++)
    {
        scanf(" %s", sobrenomes[i]);
        result[i] = determinar(sobrenomes[i]);

    }

    for (i = 0; i < n ; i++)
    {
        if (result[i] == true)
        {
            printf("%s nao eh facil\n", sobrenomes[i]);
        }
        else
        {
            printf("%s eh facil\n", sobrenomes[i]);
        }
    }


    return 0;

}

bool determinar(char* string)
{
    int i = 0, count = 0;

    while (string[i] != '\0')
    {
        if (tolower(string[i]) == 'a' || tolower(string[i]) == 'e' ||tolower(string[i]) == 'i' ||tolower(string[i]) == 'o' || tolower(string[i]) == 'u')
        {
            count = 0;
        }
        else
        {
            count++;
            if (count >= 3)
            {
                return true;
            }
        }
        i++;
    }
    
    return false;
}
