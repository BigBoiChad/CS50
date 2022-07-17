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
    int j = 0;
    int i = 1;

    // using a while loop to make sure we compare all the candidate's votes
    // Notice the candidates_count - 1 . beacuse we want j start from 0
    while (j < candidate_count - 1)
    {
        // we compare the j candidates'vote with the one benhind him
        // j is 0; i is 1
        // if the candidates has more vote than the latter , then compare to the latter + 1
        if (candidates[j].votes > candidates[i].votes)
        {
            // THis is a the case when the latter candidate is the last candidates
            // meansing the j candidates compare all others and still is the biggest
            if (i == candidate_count - 1)
            {
                // this is a speciall case
                // since we declare the j as winner now we need to find whether their are other in the past has the same votes
                // because this j will increase when it is not bigger (it can be equal)
                // so if A B both has 1 vote
                // the j will change from A to B and declare B as winner
                // Now we need to find wether there are other people has same vote get passed
                // thats why we need m < j ( for the past)
                for (int m = 0 ; m < j; m ++)
                {
                    if (candidates[m].votes == candidates[j].votes)
                    {
                        // if there is then print them too
                        printf("%s\n", candidates[m].name);
                    }
                }
                // we simply print j as winner
                printf("%s\n", candidates[j].name);
                // we end the loop
                j = candidate_count;
            }
            // other case  then -- latter to latter + 1
            i = i + 1;
        }

        // if the A = B votes
        else if (candidates[j].votes == candidates[i].votes)
        {
            // same logic
            // if the latter is the last, we declare the j and i as winner
            // but still need to fix the passed people
            if (i == candidate_count - 1)
            {
                for (int m = 0 ; m < j; m ++)
                {
                    if (candidates[m].votes == candidates[j].votes)
                    {
                        printf("%s\n", candidates[m].name);
                    }
                }
                printf("%s\n%s\n", candidates[j].name, candidates[i].name);
            }
            // if it is not the last we simply pass them
            j = i;
            i = i + 1;
        }

        else
        {
            // we make j to become the latter we compare before
            // and make NEW j to compare its latter
            j = i;
            i = i + 1;
            // Same logic , if the NEW j is the latter we can not compare
            // we just declare the NEW j as winner
            //Notice in this case when OLD j < NEW j
            // there is no equal case
            if (j == candidate_count - 1)
            {
                printf("%s\n", candidates[j].name);
            }
        }
    }
}

