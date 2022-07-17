#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    int number[] = {4, 6, 8, 2, 7, 5, 0};
    for (int i = 0; i < 7; i++)
    {
        if (number[i] == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
