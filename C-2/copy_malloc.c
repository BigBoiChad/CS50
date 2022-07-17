#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    //get_string, too, calls malloc to allocate memory for strings, and calls free just before the main function returns.
    char *s = get_string("s: ");

    // With malloc, we allocate some number of bytes in memory (that aren’t already used to store other values)
    // we give malloc a integer as input, it will assign that much space of memory for us
    // Notice this malloc happens in the heap part of memory
    // so if we keep using malloc and not free those space
    // we will get a heap overflow
    // as oppose to stack overflow, if we use a recursive funciton, and call so many function
    // we may encountet a stack overflow
    char *t = malloc(strlen(s) + 1);
    //if computer is out of memeory malloc will return NULL, the null pointer, or a special value that indicates there isn’t an address to point to.
    //so we need to check this issue
    if (t == NULL)
    {
        return 1;
    }
    for (int i = 0, n = strlen(s); i < n + 1 ; i++)
    {
        // *(t + i) = *(s + i)
        // go to the t+i address, and then go to the s+i address
        // Now put the vlaue we find at s+i address and then put it into the t + i adress
        t[i] = s[i];
    }

    if( strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n",t);
    free(t);
}
