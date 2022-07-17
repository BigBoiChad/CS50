// We gonna bulid the Mario block function
// Yet another level of abstraction
#include <stdio.h>
#include <cs50.h>

void Mario(int r);

int main(void)
{
    int r = get_int("how many rows&Colmn in this block? ");
    Mario(r);
}

void Mario(int r)
{
    for (int i = 0 ; i < r ; i++)
    {
        for (int j = 0 ; j < r ; j++)
        {
            printf("?");
        }
        printf("\n");
    }
}