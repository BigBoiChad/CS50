// Adding another level of abstration
// make the for loop a Mario function
// make the do while a get_width_int funciton
// use two for loops to print a matrix-looklike stuff :)
#include <stdio.h>
#include <cs50.h>

//Two levels of abstraction
//Mario funciton need a input, ergo the second part is not void
//get_widtn_int function is on the right part of the "=" ergo it require to provide a output.
void Mario (int n);
int get_width_int(void);

//main code only three lines :) easy!
int main(void)
{
    int w = get_width_int();

    Mario(w);
}

// the funciton is to ask the user for width which can only be posistive.
// using do while to contantly ask user the width until the width is a positive number (>=1 or not < 1)
int get_width_int(void)
{
    int w;
    do
    {
        w = get_int("what is the width?\n");
    }
    while (w < 1);
    return w;
}

//use two for loops to print a matrix-looklike stuff :)
void Mario (int n)
{
    for( int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("?");
        }
        printf("\n");
    }
}