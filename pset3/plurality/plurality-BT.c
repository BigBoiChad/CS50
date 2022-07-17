#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    //Notice the votes is int type
    int votes;
}
candidate;

// Array of candidates
// [MAX] means the length of the array that is it contain 9 data
//from candidates[0] to candidates[8]
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
// the first function taking a input string and then give output a boolean type than can eigth be ture or false
bool vote(string name);
// the second function does not take any input nor given any output
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    // make sure there are names behinde the ./plurality
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    // the totle number of names is all the things user type on the command line minus the 1 (./plurality)
    candidate_count = argc - 1;
    // if the user put more than 9 names then return 2;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        //Notice the argv[i + 1] that is because the the first [1] = ./plurality
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }


    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        // Notice the !vote(name) that is when the vote(name) return ture then the if is false , when return false the if is ture
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
    // First we need to compare the name to our database that is the candidate[i].name
    // also notice in this function we can use the varibles we defined before like candidates counts
    for (int i = 0 ; i < candidate_count; i ++)
    {
        // Use strcmp to compare the name letter to letter
        // Notice the strcmp returm three kinds of value
        // 0(same or found) positive and negative value
        if (strcmp(name, candidates[i].name) == 0)
        {
            //if we match the vote name and the candidate's name, we can increase that candidate's votes
            candidates[i].votes = candidates[i].votes + 1;
            // return true and then in the if fucntion it will not print Invild
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int votes = 0;
    for (int i = 0, n = candidate_count; i < n; i ++)
    {
        if (votes < candidates[i].votes)
        {
            votes = candidates[i].votes;
        }
    }
    for (int i = 0, n = candidate_count; i < n; i ++)
    {
        if (votes == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

