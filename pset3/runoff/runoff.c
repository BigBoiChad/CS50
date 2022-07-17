//https://cs50.harvard.edu/x/2021/psets/3/runoff/
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
// a excel looklike array
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
// the frist function can update the voters preferences
bool vote(int voter, int rank, string name);
// seconde is used to cacualted the score for uneliminated candidates
void tabulate(void);
// print out the winner
bool print_winner(void);
// used to find the min socre among the uneliminated candidates
int find_min(void);
// find out whether the remining candidates votes is the same
bool is_tie(int min);
// used to eliminated the candidates with least votes
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        //used to put data in the candidate strcture
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        // Ask evey voters j times and the j needs to be equal to how many candidates are there
        for (int j = 0; j < candidate_count; j++)
        {
            // ask for each rank
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            // use the vote funtion
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();


        // Check if election has been won
        // if the print_winner return ture means we have a winner
        // for this to have a winner we need a candidate who have more than half of the votes
        bool won = print_winner();
        // the bool won was used in this if funciton
        if (won)
        {
            // break the entire while loop
            break;
        }
        // else we dont have a winners
        // meaning there is one has more than 50% of the votes
        // we need to apply a runoff we need to eliminated the candidates who has least votes
        // Eliminate last-place candidates
        // we use the fin_min to find the least votes
        int min = find_min();
        //we use a another function to dertermine whether there is a tie

        bool tie = is_tie(min);

        // If there is a tie, everyone wins
        if (tie)
        {
            // we need to print out every winner that still existed
            for (int i = 0; i < candidate_count; i++)
            {
                // we can just use the status
                // since the eliminated status itself is a boolean expression
                if (!candidates[i].eliminated)
                {
                    // we print out every non-elimindated candidates
                    printf("%s\n", candidates[i].name);
                }
            }
            // we find the winner, thus we need tp jump out of the loop
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // since those voters who vote for candidates that are eliminated, so we need to vote for their second favoriate candidates
        // we need to do the loop again ,  that means those unemlinated voters will still be count again sp we need to reset the votes
        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            // we set everyone's votes to zero and then loop agian until we have a winner
            // Notice each round we eliminated some canndidates
            // so we will definately find the winner
            candidates[i].votes = 0;
        }
    }

    return 0;
}

// Record preference if vote is valid
// when the voters rank someone as 1, its prefrences needs to be [i][0] and needs to equal to tha candidates
// the frist candidates is 0 ,...
bool vote(int voter, int rank, string name)
{
    // comparing the name with each candidates
    // i in this can represent the candidates position (argv[1][i])
    for (int i = 0; i < candidate_count; i ++)
    {
        // if we find a match we need to update the preferences funciton
        if (strcmp(name, candidates[i].name) == 0)
        {
            // we need to store data in the excel look-like two dimensional form
            // the voter's rank j is argv[1][i]
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
// canidates needs to be unelimindated
void tabulate(void)
{
    // we need to keep counting all voters
    int i = 0;
    while (i < voter_count)
    {
        // we use the j to represent the ranking for candidates by each voter
        for (int j = 0 ; j < candidate_count; j ++)
        {
            // findout whether the voters voted candidates are eliminated or not
            // Notice we put the preferences as input :)
            if (candidates[preferences[i][j]].eliminated == false)
            {
                // if the candidate does exist we increase the votes
                // Notice we use the preference as input
                // that way, if the rank 1 candidate for voter 1 is eliminated
                // we enter the loop to add j to see the rank 2
                // if rank 2 caindiate still there, we add this vote to the that candidates
                candidates[preferences[i][j]].votes ++;
                // after we add the vote -- the voters 1 is complete ,
                // we dont need to keep counting voter 1's preferences/\
                // we use the break funtion to jump out of the loop
                break;
            }
        }
        // after we count 1 voter we need to count fot the next voter
        i = i + 1;
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // we check each candidate's votes
    for (int i = 0; i < candidate_count; i ++)
    {
        //  check if the votes is bigger than half
        if (candidates[i].votes >= round(voter_count / 2) + 1)
        {
            // if there is we printf the winner and return true
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

//Notice we need to return a integer to the min
// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // lets make the min the biggest (that is the total votes)
    int min = voter_count;

    for (int i = 0; i < candidate_count; i ++)
    {
        // if the min find a vote that is smaller and that vote is valid (meaning the candidates is still not eliminated)
        if (min >= candidates[i].votes && candidates[i].eliminated == false)
        {
            // we make sure the min is equal to the least votes
            //Notice we cannot know wheter there is a tie
            // for example there is two least votes
            min = candidates[i].votes;
        }
    }
    return min;
    return 0;
}




// Return true if the election is tied between all candidates, false otherwise
// when every remining candidates has the min vote
// because we do not want to eliminated every candidates
// thats when there is a tie
bool is_tie(int min)
{
    int j = 0;
    int s = 0;
    for (int i = 0 ; i < candidate_count ; i ++)
    {
        // we need to find out how many reming people are there
        if (candidates[i].eliminated == false)
        {
            j ++;
        }
    }

    for (int i = 0; i < candidate_count ; i++)
    {
        // two conditions need to be fullfill at the same time
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            s = s + 1;
        }
    }

    if (s == j)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i ++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}


//reference :
//https://github.com/ewartj/cs50_2020/blob/2ab1290324ede5b0637a8daf1360b0ced429186a/week3/runoff.c