#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool validate_key(int argc, string argv[]);
string cipher_text(string argv[], string text);

int main(int argc, string argv[])
{
    // Validates key
    if (!validate_key(argc, argv))
    {
        return 1;
    }
    
    // Get text from user
    string text = get_string("plaintext: ");
    
    // Cipher that text and print it
    cipher_text(argv, text);
}

bool validate_key(int argc, string argv[])
{
    // Doesn't let let the command line argument be different than 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }
    // Doesn't let let the command line argument be greater than or less than 26
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    //Doesn't let the command line argument contain anything but letters
    for (int i = 0; i < 26; i++)
    {
        if ((isalpha(argv[1][i])) == 0)
        {
            printf("Usage: ./substitution key\n");
            return false;
        }
        
        //Doesn't let the command line argument contain duplicate letters
        char copy = argv[1][i];
        char copy2 = copy;
        if (islower(copy))
        {
            copy2 = toupper(copy);
        }
        if (isupper(copy))
        {
            copy2 = tolower(copy);
        }
        
        for (int j = 0; j < 26; j++)
        {
            if ((copy == argv[1][j] || copy2 == argv[1][j]) && i != j)
            {
                printf("Key must not repeated characters.\n");
                return false;
            }
        }
    }
    
    // If pass everthing the key is valid so return true
    return true;
}

string cipher_text(string argv[], string text)
{
    // Copy the key
    string copy = argv[1];
    
    // Encrypts the text using the copy
    for (int i = 0; i < strlen(text); i++)
    {
        // Makes the upper letters of ASCII match their number in the alphabet 
        int T = text[i] - 65;
        // Makes the lower letters of ASCII match their number in the alphabet 
        int t =  text[i] - 97;
        
        // If is upper
        if (isupper(text[i]) && isalpha(text[i]))
        {
            char upper = toupper(copy[T]);
            text[i] = upper;
        }
        // If is lower
        if (islower(text[i]) && isalpha(text[i]))
        {
            char lower = tolower(copy[t]);
            text[i] = lower;
        }
    }
    
    // Print the encrypted message
    printf("ciphertext: %s\n", text);
    
    // Returns encrypted message 
    return text;
}