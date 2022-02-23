#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float rule_three(int l, int w);
float rule_three2(int s, int w);


int main(void)
{
    // Ask the user for text
    string text = get_string("Text: ");
    
    // Count letters, words and senteences
    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);
    
    // Average number of letters
    float L = rule_three(l, w);
    // Average number of sentences
    float S = rule_three2(s, w);
    
    //  Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // round de index
    int grade = round(index);
    
    // Print the grade
    if (grade > 17)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Function for counting letters
int count_letters(string text)
{
    int counter = 0;
    for (int a = 0; a < strlen(text); a++)
    {
        if (isalpha(text[a]))
        {
            counter++;
        }
    }
    return counter;
}

// Function for counting words
int count_words(string text)
{
    int word = 0;
    for (int b = 0; b < strlen(text); b++)
    {
        if (isspace(text[b]))
        {
            word++;
        }
    }
    word++;
    return word;
}

// Function for counting sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int c = 0; c < strlen(text); c++)
    {
        if (text[c] == 46 || text[c] == 63 || text[c] == 33)
        {
            sentences++;
        }
    }
    return sentences;
}

// Function for the average letters
float rule_three(int l, int w)
{
    float r = l * 100;
    float R = r / w;
    return R;
}

// Function for the average sentences
float rule_three2(int s, int w)
{
    float r = s * 100;
    float R = r / w;
    return R;
}