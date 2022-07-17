#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // this is indetical to a string and string is actually just a pointer with the address of the first character:
    char *s = "Hi!";
    // s now is just a pointer
    // s + 1 shoulde be the address of the second character
    printf("%p\n", s);
    printf("%p\n", s + 1);

    //*s goes to the address stored in s
    printf("%c\n", *(s));
    //*(s+1) goes to the address stored in （s+1)  and print out the character(is not stroed in s but rather stored in the address that s have)
    printf("%c\n", *(s+1));
    //we’ll get a segmentation fault, or crash as a result of our program touching memory in a segment it shouldn’t have.
    printf("%c\n",*(s+10000000000));
}

