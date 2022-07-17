// this case shows grabage value
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main (void)
{

    // we frist declare a pointer and then use the malloc to assign some memory to it
    int *i = malloc(sizeof(int));
    // Notice we did not assign y any memory
    int *y;

    // go to i and then put the value 42 in that address
    *i = 42;
    // go to y and then put the value 15 in that address
    // Expect y dont have a memory it can point to
    // ie, it might point anywhere in the memory
    // if we put the value 15 in it, the it is a random place.
    // so we bascially touch and CHANGE a memory we are not supposed to touch.
    // Thus Segament Fault
    *y = 15;

    printf("%i\n", *y);
}