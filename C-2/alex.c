#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Ask user's name
    string answer = get_string("What's your name? ");
    //Greet the users
    printf("Hello, %s\n", answer);
}