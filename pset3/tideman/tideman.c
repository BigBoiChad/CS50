#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

void merge_sort(int i, int j, pair a[], pair aux[]);
bool recursive_lock(int a, int b);

int main (int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{

    for (int i = 0 ; i < candidate_count ; i ++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{

    for (int i = 0 ; i < candidate_count; i ++)
    {
        for (int j = i + 1; j < candidate_count; j ++)
        {
            preferences[ranks[i]][ranks[j]] ++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //we need two index[] [] 
    // each index need to loop from 0 - candidiate_count 
    int i = 0;
    while (i < candidate_count)
    {
        for (int j = 0; j < candidate_count; j ++)
        {   
            // for i = 0 , make j = 0 ~ candididate_count, to compare every candidate with 0
            // Notice the j is also start from 0 , but we should ignore a tie, so this way is easy
            // if [0][1] is small, we also ignore, because when i = 1 , j still start from 0 , that way [1][0] > [0][1]
            // so this pair is still recorded.
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count ++;
            }
        }
        i ++;
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
// notice is in decreasing order. the bigger one out of two should be placed at first
void sort_pairs(void)
{
    // we need a pairs that is the same size as all the pairs regradless of a tie or small.
    pair pairs_final[MAX * (MAX - 1) / 2];
    // then we call a function to merge_sort.
    // 0 is the smallest index,candidiate_count is biggerst index. pairs[pair count] is the last pair.
    merge_sort(0, candidate_count, pairs, pairs_final);
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (recursive_lock(pairs[i].winner, pairs[i].loser) == true)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}



// Print the winner of the election
// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int winning_candidate = i; // current candidate to evaluate
        bool no_edge = true; // assumes that current candidate is winner
        
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i]) // evaluates if current candidate loses to other candidates
            {
                no_edge = false;
                break; // if current candidate loses, break loop and go back to outer loop to next candidate
            }
        }
        
        if (no_edge) // if candidate does not lose, then it is the winner
        {
            printf("%s\n", candidates[winning_candidate]);
            return;
        }
    }        
    return;
}

// Notice the i - j is the a[]'s length. since a[i ~ j]
// a[] is the array we need to sort
// Notice aux[] here is just a tmp memory location
// the size of aux[] shoulde be the same as a[]
// This funciton need a pointer, becasue after all we need to swap two value
// meaning we need go to one varible that point a address and then do something to the value in that adrress
void merge_sort(int i, int j, pair a[], pair aux[])
{
    //note function from https://hackr.io/blog/merge-sort-in-c
    // this is the so called base case. 
    if (j <= i)
    {
        return;
    }
    // divide the array in two
    int mid = (i + j) / 2;
    
    // call the recursive function
    // this the frist two steps
    // merge left and then merger right
    // after that , we reach the thrid step
    merge_sort(i, mid, a, aux);
    merge_sort(mid + 1, j, a, aux);
    
    //  we set a pointer which point at the first value of the left half array
    int pointer_left = i;
    // we set a pointer which point at the first value of the right half array
    int pointer_right = mid + 1;
    // k is used as an index in aux[] array
    int k;

    for (k = i; k <= j; k++)
    {
        // this is used to find wether the pointer reach a limit
        // meaning that half of array is sorted
        // since when sorted the pinoter value can thus change
        // it make more sense to put this part at the end
        if (pointer_left == mid + 1)
        {
            aux[k] = a[pointer_right];
            pointer_right++;
        }
        // same logic here
        else if (pointer_right == j + 1)
        {
            aux[k] = a[pointer_left];
            pointer_left++;
        }
        // we compare the strength of each pair.
        // meaning each pair's strength, the a[i].winner and loser
        // the strength is how many voters perfer that winner over that loser
        // if we find the bigger vlaue we put it in the first (decreasing order)
        // this is the meger put\\ two out of three
        else if ((preferences[a[pointer_left].winner][a[pointer_left].loser]) >
                 (preferences[a[pointer_right].winner][a[pointer_right].loser]))
        {
            // we put the bigger one (in this case is the left array) in the K position that strart at i -- the first position
            aux[k] = a[pointer_left];
            // the move the left pointer to the next pair
            pointer_left++;
        }
        else
        {
            // same logic
            aux[k] = a[pointer_right];
            pointer_right++;
        }
        // after this loop the aux[] array is sorted. from 2 + 2 items [1][2]- [3][4]-- to 4 items[1][2][3][4]-- 
    }

    // after all fo the above this function is to swap the aux[] to a[]
    for (k = i; k <= j; k++)
    {
        a[k] = aux[k];
    }
}

bool recursive_lock(int a, int b)
{
    if (a == b)
    {
        return false;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[i][a] == true)
        {
            if (recursive_lock(i, b) == false)
            {
                return false;
            }
        }
    }

    return true;
}
