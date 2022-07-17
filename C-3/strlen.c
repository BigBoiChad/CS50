#include <cs50.h>
#include <stdio.h>
//using the string header file to link the strlen function, which is used to determined the lengtg of a array
// just as the pinpoint_char before it use the boolean expression s[i] != '\0'
#include <string.h>


int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    //s[i] != \0 is a boolean expression to determined the length of the array

    // since the end of the arrat is 0 --- '\0''
    // we can just get rid of n by useing i < strlen(s) but in this case, it is kinda inefficient since we have to check strlen every time we loop back
    // instead we bring a new varibles called n
    for( int i = 0, n = strlen(s) ; i < n ; i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
}