#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char determinar(char* string);

int main()
{

    int i, j, n, k;
    char idioma[21];

    scanf("%d", &n);
    scanf("%d", &k);

    char resultado[n][21];
    

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf(" %s", idioma);
        }
    }

    for (i = 0; i < n; i++)
    {
        if (resultado[i] == 'ingles')
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