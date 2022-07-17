#include <math.h>
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n = 50;
    //We can use the * operator to declare a point
    // and we take the address of n as an input for *p
    // so the p points at a location where n is stored
    int *p = &n;
    // &n is to show n vlaue's location in memory
    printf("%p\n", &n);
    printf("%p\n", p);
    printf("%i\n",*p);
}