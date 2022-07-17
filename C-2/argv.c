#include <cs50.h>
#include <stdio.h>
#include <string.h>

// like other costom funcitons we can give the main function a input
// int argc means the arguments count or number of arguments
//argument vector (or argument list), an array of strings.
// argv[0] is the name of the file
int main (int argc, string argv[])
{
    // when there is two words you type on the command line
    if( argc == 2)
    {
        // the argv[1] is the second word you type on the command line
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}
