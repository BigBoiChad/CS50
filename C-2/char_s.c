#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // this is indetical to a string and string is actually just a pointer with the address of the first character:
    char *s = "Hi!";
    printf("%p\n", s);
    printf("%s\n", s);
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%c\n", s[4000000000000000000]);
}

