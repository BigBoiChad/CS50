//The for loop is more elegant than a while loop
#include <stdio.h>
#include <cs50.h>

int main(void)
{
// first we create a variable named i and set it to 0. Then, we check that i < 50 every time we reach the top of the loop.
// before we run any of the code inside. If that expression is true, then we run the code inside
    for(int i = 0; i<10; i++)
    {
        printf("hello\n");
    }
}
// Notice that for many of these lines of code, like if conditions and for loops, we don’t put a semicolon at the end. 
//Instead notice that in the () we use ";" to seperate one another