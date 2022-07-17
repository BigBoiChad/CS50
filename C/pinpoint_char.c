#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    //s[i] != \0 is a boolean expression to determined the length of the array
    // since the end of the arrat is 0 --- '\0''
    for( int i = 0 ; s[i] != '\0' ; i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
}