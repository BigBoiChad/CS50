//// Uppercases a string

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //Promt user the question
    string s = get_string("Before: ");
    printf("After: ");

    for (int i = 0, n = strlen(s); i < n ; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] =s[i] - 32;
            printf ("%c",s[i]);
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");
}