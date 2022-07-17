#include <stdio.h>
#include <cs50.h>
#include <string.h>
//using a funciton in this ctype.h
#include <ctype.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {   
        //toupper expect a character you cannot pass a whole word to it
        // that's why the for -loop is still nesserary
        printf("%c", toupper(s[i]));
    }
    printf("\n");

}