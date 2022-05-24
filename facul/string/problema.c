#include <stdio.h>
#include <stdlib.h>

int achar(char* string, int j);

int main()
{

    int i, j = 0, n;
    char text[100001];

    scanf("%d", &n);
    int result[n];

    for (i = 0; i < n ; i++)
    {
        scanf(" %s", text);
        result[i] = achar(text, j);
        j++;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;

}

int achar(char* string, int j)
{

    int total = 0, i;
    for (i = 0; i < 14; i++)
    {

        if (i == 2 || i == 5 || i == 11)
        {
            total = total + atoi(string);
            string[i] = '0';
        }
        else
        {
            string[i] = '0';

        }
    }

    return total;

}
