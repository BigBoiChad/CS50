#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *y);

int main (void)
{
    int x = 10;
    int y = 11;

    printf("x: %i , y: %i\n", x , y);

    // the swap funciton take the pointer as a input
    // that way we know the x y address so we can follow the pointer to change its value
    swap(&x,&y);
    printf("x: %i , y: %i\n", x , y);
}


void swap(int *a, int *b)
{
    // the thrid glass of wine
    int tmp;
    // we go to x pointer and then find the value to put it back to tmp
    // tmp now euals to x
    tmp = *a;
    // we go to the b pointer and find the value(y) and then go to x pointer and put it in there
    *a = *b;
    // we go to b pointer and then put tmp value in it
    *b = tmp;

}