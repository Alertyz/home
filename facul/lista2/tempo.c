#include <stdio.h>
 
int main() 
{
    int d, h, m, s;
    int dia, hora, min, seg;
    scanf("Dia %d", &d);
    scanf("%d : %d : %d\n", &h, &m, &s);
    scanf("Dia %d", &dia);
    scanf("%d : %d : %d", &hora, &min, &seg);

    s = seg - s;
    m = min - m;
    h = hora - h;
    d = dia - d;

    if (s < 0)
    {
        s += 60;
        m--;
    }
    if (m < 0)
    {
        m += 60;
        h--;
    }
    if (h < 0)
    {
        h += 24;
        d--;
    }


    printf("%d dia(s)\n", d);
    printf("%d hora(s)\n", h);
    printf("%d minuto(s)\n", m);
    printf("%d segundo(s)\n", s);

    return 0;
}