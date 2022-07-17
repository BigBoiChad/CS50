#include <stdio.h>
#include <stdlib.h>

void swap(int x, int y);

int main (void)
{
    int x = 10;
    int y = 11;

    printf("x: %i , y: %i\n", x , y);
    // stack upwards
    // The swap function, when it’s called, has its own area of memory that’s on top of main’s,
    // with the local variables a, b, and tmp:
    swap(x,y);
    printf("x: %i , y: %i\n", x , y);
}


void swap(int a, int b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    // in this function the x and y did swaped
    // but the value x ,y is then left on the swap stack and seen as garbage value.
    // in a word it cannot change the value of x y in main fuction
    // one way to do that is to use pointer.
    // the funciton follow a pointer to change the value stored in the main function
}