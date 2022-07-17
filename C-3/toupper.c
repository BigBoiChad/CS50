#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n ; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}s