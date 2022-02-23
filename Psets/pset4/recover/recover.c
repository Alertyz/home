#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        return 1;
    }
    
    // Open card
    FILE *card = fopen(argv[1], "r");
    
    // Check if card
    if (card == NULL)
    {
        return 2;
    }
    
    // Buffer
    BYTE buffer[512];
    
    // Image
    FILE *image;
    
    // String for sprintf
    char *s = malloc(8);
    
    // Warn if it's not the first JPEG 
    int warning = 0;
    
    int counter = 0;
    
    // JPEG counter
    int i = 0;

    // Repeat and read(512) until end of card
    while (fread(&buffer, 512, 1, card))
    {
        
        // Check if is a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            
            // Close Previous JPEG 
            if (warning != 0)
            {
                
                // Close image
                fclose(image);
                i++;
                counter = 0;
                warning = 0;
                
            }
            
            // Create and write into new JPEG
            sprintf(s, "%03i.jpg", i);
            image = fopen(s, "w");
            fwrite(&buffer, 512, 1, image);
            
            counter++;
        }
        
        // If already found JPEG
        else if (counter != 0)
        {
            fwrite(&buffer, 512, 1, image);
            warning++;
        }
        
    }
    
    // Free s memory
    free(s);
    
    // Close image
    fclose(image);
    
    // Close card
    fclose(card);
}