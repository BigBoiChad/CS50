#include <stdio.h>
#include <cs50.h>

// Notice I said before a string is just string of character. If a single charachter is actually number
//Then a string of number is ARRALY!!!!
//so a string is a array of single character!!!

int main(void)
{
    // since a string is just a array of characters
    // them we cam use array to pinpoiont each single character
    string s = "HI!";
    //the string s contains three character H I ! .
    //However  a string ends with a special character, '\0'. This character is called the null character.
    //So we actually need four bytes to store our string with three characters:
    printf("%i %i %i %i \n", s[0], s[1], s[2], s[3]);
    //With C, our code has the ability to access or change memory that it otherwise shouldn’t, which is both powerful and dangerous.
    printf("%i\n", s[5]);
}