//use for loop to meow N times that then up to a new level of abstraction by creating a MEOW function!!!
#include <cs50.h>
#include <stdio.h>

//It turns out that we need to declare our meow function first with a prototype, before we use it in main, and actually define it after.
void MEOW(void);

int main(void)
{
   for (int i = 0 ; i < 3 ; i++)
    {
// here we can call the MEOW function we defined before :) easy
        MEOW();
    }
}

//Notice the first void means there is not output for this MEOW funciton; the secend void () means there is not input for this function
//MEOW funciton as Printf("meow\n")
void MEOW(void)
{
        printf("meow\n");
}

