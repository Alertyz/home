#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *card = fopen("card.raw", "r");
    BYTE header[4];
    int j = 0;
    while()
    {
        if (header[0] == 0xff && header[1] == 0xd8 && header[2] == 0xff && (header[3] & 0xf0) == 0xe0)
        {
            j++;
        }
    }
    fclose(card);

}