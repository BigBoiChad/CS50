//Determine how long it takes for a population to reach a particular size.
// A population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0;
    int s;
    int e;

    do
    {
        // TODO: Prompt for start size
        //If the user enters a number less than 9 , the user should be re-prompted to enter a starting population size until >= 9
        s = get_int("Start size: ");
    }
    while (s < 9);

    do
    {
        // TODO: Prompt for end size
        //If the user enters a number less than the starting population size, the user should be re-prompted to enter an ending population size
        e = get_int("End size: ");
    }
    while (e < s);

    // TODO: Calculate number of years until we reach threshold
    while (e > s)
    {
        // A population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.
        s =  s + s / 3 - s / 4;
        i =  i + 1 ;
    }
    // TODO: Print number of years
    printf("Years: %i\n", i);
}
