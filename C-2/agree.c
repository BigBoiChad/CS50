// Boolean expression or ( || )Logical operators

#include <cs50.h>
#include <stdio.h>

//In agree.c, we can ask the user to confirm or deny something:
int main (void)
{
    //With get_char, we can get a single character
    char c = get_char("Do you agree? ");

    //We use two vertical bars, ||, to indicate a logical “or” (Two ampersands, &&, indicate a logical “and”）
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed!\n");
    }

    //notice that we use two equals signs, ==, to compare two values, as well as single quotes, ', to surround our values of single characters.
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed!\n");
    }
}