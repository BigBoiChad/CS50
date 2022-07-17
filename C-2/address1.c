#include <cs50.h>
#include <stdio.h>


int main (void)
{
    // get_string here is a function the cs50 designed
    // it return the address of the first character we typed
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // here we are not compare the string s and t
    // rather we compare the location of the string we input as s and t
    // s here stands for the first location of the character we type
    if (s == t)
    {
        // try if we change s==t to *s == *t (notice we can indeed compare two characters using == , we cannot compare string that will need the strcmp funciton)
        printf("Same\n");
        printf("%p\n", s);
        printf("%p\n", t);
    }
    else
    {
        printf("Different\n");
        printf("%p\n", s);
        printf("%p\n", t);
    }

}


