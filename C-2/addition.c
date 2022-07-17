#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //geting numbers form user
    int x = get_int("x:");
    int y = get_int("y:");

    printf("%i\n", x + y);
}