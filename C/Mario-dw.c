//use do-while function to only select the posititve number and use for function to loop
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // avoid the socpe issue
    int w;
    do
    {
        //Promt the user
        w = get_int("what is the width?\n");
    }
    while (w < 1);

    // for loop
    for( int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            printf("?");
        }
        printf("\n");
    }
}