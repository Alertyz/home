#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    
    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        return 0;
        
    }
    // If player 2 wins
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
        return 0;
    }
    // If it's a tie
    else
    {
        printf("Tie!\n");
        return 0;
    }
}

int compute_score(string word)
{
    
    // counter of points per letter
    int score = 0;
    
    //System of scores
    for (int i = 0; i < strlen(word); i++)
    {
        
        // Makes the upper letters of ASCII match their number in the alphabet 
        int T = word[i] - 65;
        // Makes the lower letters of ASCII match their number in the alphabet 
        int t =  word[i] - 97;
        
        // If is upper
        if (isupper(word[i]) && isalpha(word[i]))
        {
            score += POINTS[T];
        }
        // If is lower
        if (islower(word[i]) && isalpha(word[i]))
        {
            score += POINTS[t];
        }
        
    }
    
    return score;
}
