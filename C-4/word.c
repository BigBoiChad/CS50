//we might declare an array of two strings
//So an array of strings is just an array of arrays of characters.
#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    //tell the computer give me a array of size two in which we put string
    string words[2];
    //not we dont call them strings we call them words
    // the frist word is Hi
    // A string is a array but here we have a array of string
    // so we have is a array of array
    words[0] = "Hi";
    words[1] = "world!";

    // so we can use [] to find the character in a word
    printf("%c %c %c %c \n", words[0][0], words[0][1], words[1][1], words[1][2]);
}