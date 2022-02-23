#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string cipher_text(string text, int c);

int main(int argc, string argv[])
{
    // Don't let the command line argument be different than 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Don't let the command line argument [1] contain letters
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // convert argv into a int
    int c = atoi(argv[1]);
    // Prompts the user for the message that will be encrypted 
    string text = get_string("plaintext:  ");
    // Encrypte the message
    string cipher = cipher_text(text, c);
    // Print the encrypted message
    printf("ciphertext: %s\n", cipher);
}
// Function that encrypt the text
string cipher_text(string text, int c)
{
    // Copy the message
    string m = text;
    // The number that will define which letter of the strings alphaupper and alphalower will be copy
    int counter = 0;
    // Lower letters of the alphabet in string 
    string alphalower = "abcdefghijklmnopqrstuvwxyz";
    // Upper letters of the alphabet in string 
    string alphaupper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Encrypts the copy
    for (int o = 0; o < strlen(text); o++)
    {
        // Makes the upper letters of ASCII match their number in the alphabet 
        int T = text[o] - (65 - 1);
        // Makes the lower letters of ASCII match their number in the alphabet 
        int t =  text[o] - (97 - 1);
        // If is upper and goes wraparound
        if (isupper(text[o]) && isalpha(text[o]))
        {
            if (T + c > 26)
            {
                counter = (T + c) % 26;
                counter -= 1;
                m[o] = alphaupper[counter];
            }
        }
        // If is lower and goes wraparound
        if (islower(text[o]) && isalpha(text[o]))
        {
            if (t + c > 26)
            {
                counter = (t + c) % 26;
                counter -= 1;
                m[o] = alphalower[counter];
            }
        }
        // If is upper and dosen't go wraparound
        if (isupper(text[o]) && isalpha(text[o]))
        {
            if (T + c < 26)
            {
                m[o] = text[o] + c;
            }
        }
        // If is lower and doesn't go wraparound
        if (islower(text[o]) && isalpha(text[o]))
        {
            if (t + c < 26)
            {
                m[o] = text[o] + c;
            }
        }
        // Reset counter
        counter = 0;
    }
    // Returns encrypted message 
    return m;
}