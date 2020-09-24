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
    for (int index_count = 0; index_count < candidate_count; index_count++)
    {
        candidates[index_count].name = argv[index_count + 1];
        candidates[index_count].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int index_count = 0; index_count < voter_count; index_count++)
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
    for (int index_count = 0; index_count < candidate_count; index_count++)
    {
        //compares candidate name with the input and increment vote if the name matches.
        if (strcmp(candidates[index_count].name, name) == 0)
        {
            candidates[index_count].votes++;
            return true;
        }
    }
    // TODO
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int maxVotes = 0;
    //loop to find who got the highest vote
    for (int index_count = 0; index_count < candidate_count; index_count++)
    {
        if (candidates[index_count].votes > maxVotes)
        {
            maxVotes = candidates[index_count].votes;
        }
    }

    //prints out the candidate name whose vote is highest.
    for (int index_count = 0; index_count < candidate_count; index_count++)
    {
        if (candidates[index_count].votes == maxVotes)
        {
            printf("%s\n", candidates[index_count].name);
        }
    }
    // TODO
    return;
}
