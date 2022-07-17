// use while loop to say hello ten times
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //We create a variable, i, and set it to 0. while i is less than 10, we run the following code
    int i = 0;
    while (i < 10)
    {
        printf("hello\n");
        //including one where we add 1 to i each time (i= i+1;) or (i += 1;)  i--; or i-=1; i=i-1;
        i++;
    }
}