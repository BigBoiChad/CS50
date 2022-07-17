#include <cs50.h>
#include <stdio.h>

//We can give it a constant int that cannot change during the following
//In this case we set it to be the lenght of the scores []
const int TOTAL = 3;

float average(int length , int array[]);

int main(void)
{
    // the length of scores[] is 3 which means it contain three values
    // but the frist number is show as scores[0] ; the last number is scores[2]
    // we need to tell computer the lenght of the array in C
    int scores[TOTAL];

    for(int i = 0; i < TOTAL ; i++)
    {
        // Change i from 0 to 2 -- three times
        scores[i] = get_int("Scores: ");
    }

    // Print average
    printf("Average: %f\n", average(TOTAL, scores));
}


//the length in this case is the const int TOTAL
//Notice we use the typecase in the length at the last line of code. That is beacuse we need to return a float poiont value
//since the sum is divide by three
//Notice if we need to retrun a float vlaue we need to change the frist part of function-i.e- the input from int to float
//Notice the input is array[] with the number in the [].
float average(int length , int array[])
{
    int sum = 0;
    for( int i = 0 ; i < length ; i++)
    {
        sum += array[i];
    }
    return sum /(float) length;
}