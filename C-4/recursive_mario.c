#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


void draw (int h);

int main (void)
{

    //But if we enter a large enough value for the height, like 2000000000,
    //we’ll still run out of memory, since we’re calling draw too many times without returning
    int height = get_int("height: ");
    draw(height);

}



void draw (int h)
{
    // this is a base
    // tells the recursive function when to stop
    if (h == 0)
    {
        return;
    }
    // we call the function itself
    // but with a DIFFERENT Input
    draw(h - 1);


    for (int i = 0; i < h ; i++)
    {
        printf("#");
    }
    printf("\n");

}