// using loop to creat the blocks appears as ?  in mario bro
#include <cs50.h>
#include <stdio.h>

//usnig a loop inside of another loop to creat a matrix-looklike block
int main(void)
{
//this loop is to vertically print 9 time "?"
    for (int i = 0 ; i < 9 ; i++)
    {
// this loop is to herizontally print 9 time "?"
        for (int j =0 ; j < 9 ; j++)
        {
            printf("?");
        }
        printf("\n");
    }
}