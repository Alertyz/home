#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Check if the candidate exists
    for (int c = 0; c < candidate_count; c++)
    {
        if (strcmp(name, candidates[c].name) == 0)
        {
            candidates[c].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Bubble sort
    int z = candidate_count;
    int swap = -1;
    if (swap != 0)
    {
        do
        {
            swap = 0;
            for (int b = 0; b < z; b++)
            {
                int a = b + 1;
                if (a > candidate_count)
                {
                    a = candidate_count;
                }
                if (candidates[b].votes > candidates[a].votes)
                {
                    int copy1 = candidates[b].votes;
                    string copy1name = candidates[b].name;
                    candidates[b].votes = candidates[a].votes;
                    candidates[a].votes = copy1;
                    candidates[b].name = candidates[a].name;
                    candidates[a].name = copy1name;
                    swap++;
                }
            }
            z--;
        }
        while (swap != 0);
    }
    //Print the winner
    printf("%s", candidates[candidate_count].name);
    //If there is more than one winner print them to
    for (int b = 0; b < candidate_count; b++)
    {
        if (candidates[b].votes == candidates[candidate_count].votes)
        {
            printf("\n%s", candidates[b].name);
        }
    }
    printf("\n");
    return;
}

