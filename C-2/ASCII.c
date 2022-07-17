#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Notice our varible is character type
    //A single character using ''
    // a string of character using ""
    char c = '#';
    // in this case we use %i - which means we will printf a integer
    // and arrcoding to ASCII # is the number of 35
    // Since a char use 1 bytes which is 256 = 2^8 and the ASCII is also 0~256.
    // so in a way all characters are actually numbers from 0~255.
    printf("%i\n", c);
}

// Notice I said before a string is just string of character. If a single charachter is actually number
//Then a string of number is ARRALY!!!!
//so a string is a array of single character!!!