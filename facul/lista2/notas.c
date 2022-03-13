#include <stdio.h>
#include <math.h>
float count_money(char* text, float N, float nota);

int main()
{
    float nota, N = 100;
    char text[] = "nota(s)";
    char text2[] = "moeda(s)";
    scanf("%f", &nota);

    printf("NOTAS:\n");
    nota = count_money(text, N, nota);
    N = 50;
    nota = count_money(text, N, nota);
    N = 20;
    nota = count_money(text, N, nota);
    N = 10;
    nota = count_money(text, N, nota);
    N = 5;
    nota = count_money(text, N, nota);
    N = 2;
    nota = count_money(text, N, nota);

    printf("MOEDAS:\n");
    N--;
    nota = count_money(text2, N, nota);
    N = 0.50;
    nota = count_money(text2, N, nota);
    N = 0.25;
    nota = count_money(text2, N, nota);
    N = 0.10;
    nota = count_money(text2, N, nota);
    N = 0.05;
    nota = count_money(text2, N, nota);
    N = 0.01;
    int notas = round(nota * 100);
    printf("%i %s de R$ %0.2f\n", notas, text2, N);
    
    return 0;
}

float count_money(char* text, float N, float nota)
{
    int counter = 0;
    while (1)
    {
        if (nota >= N || nota == N)
        {
            nota -= N;
            counter++;
        }
        else
        {
            break;
        }
    }

    printf("%i %s de R$ %0.2f\n", counter, text, N);

    return nota;
}