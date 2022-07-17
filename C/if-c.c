//Conditional funcation use If
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");
    //Prompt user for y
    int y = get_int("y: ");

    // if condition compare the two values
    if (x < y)
    {
        printf("x is less than y\n");
    }

    //Notice that, to compare two values in C, we use ==, two equals sign.
    else if (x == y)
    {
        printf("x is equal than y\n");
    }

    //beccause there is only on outcome left, so we don't need another else if.
    else
    {
        printf("x is bigger to y\n");
    }
}