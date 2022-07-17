#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


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

    printf("%i %i\n", score1, score2);
    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Ties!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    for (int i = 0, n = strlen(word); i < n ; i++)
    {
        //we turn the characters into numbers by simple change the type
        //We use the touuper function to make sure every charachter is the uppercase. since the uppercsase hand lowe case point is the same
        int m = toupper(word[i]);

        //we need to only find index in POINTS when the charachter is a letter from A-Z
        //Again we use ASCII code where we know A-Z is 65-90
        if (m >= 65 && m <= 90)
        {
            score += POINTS[m - 65];
        }
        // If it is not a letter we assign score to 0
        else
        {
            score += 0;
        }
    }
    return score;
}