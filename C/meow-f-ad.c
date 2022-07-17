//Advanced meow funtion, by given a input for the meow funtion
//Abstraction with parameterization
#include <stdio.h>
#include <cs50.h>

//A prototype
void MEOW(int n);

int main(void)
{
// the right part needs to give a output to the computer and then the computer will assign the output to int n
    int n = get_int("How many time do you want to meow?\n");
//using MEOW function :) easy!!!
    MEOW(n);
}

//MEOW function defination; change our meow function to take in some input
//the second (int n) means that the MEOW function needs a input!! which we will get for the question above!!
void MEOW(int n)
{
//meow n times
    for(int i = 0; i < n ; i++)
    {
        printf("meow\n");
    }
}