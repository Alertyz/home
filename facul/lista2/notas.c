#include <stdio.h>
#include <math.h>
float count_money(char* text, float* N, float nota, int count);

int main()
{
    float nota, N[] = {100, 50, 20, 10, 5, 2, 0, 1, 0.50, 0.25, 0.10, 0.05, 0.01};
    int count = 0;
    char text[] = "nota(s)";
    char text2[] = "moeda(s)";
    scanf("%f", &nota);

    printf("NOTAS:\n");
    nota = count_money(text, N, nota, count);

    printf("MOEDAS:\n");
    count = 7;
    nota = count_money(text2, N, nota, count);
    
    return 0;
}

float count_money(char* text, float* N, float nota, int count)
{
    int counter = 0;
    while (1)
    {
        if (nota >= N[count])
        {
            nota -= N[count];
            counter++;
        }
        else
        {
            break;
        }
    }
    
    printf("%i %s de R$ %0.2f\n", counter, text, N[count]);
    
    if (count == 11)
    {
        count++;
        counter = round(100 * nota);
        printf("%i %s de R$ %0.2f\n", counter, text, N[count]);
    }

    if (count >= 0 && count <= 4)
    {
        count++;
        nota = count_money(text, N, nota, count);
    }
    else if (count == 6)
    {
        return nota;
    }
    else if (count >= 7 && count <= 11)
    {
        count++;
        nota = count_money(text, N, nota, count);
    }

    return nota;
}