#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char *s = malloc(3);
    s[0] = 'H';
    s[1] = 'i';
    s[2] = '\0';
    printf("%s\n", s);
    free(s);
}