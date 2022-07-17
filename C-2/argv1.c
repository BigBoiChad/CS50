#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// like other costom funcitons we can give the main function a input
// int argc means the arguments count or number of arguments
//argument vector (or argument list), an array of strings.
// argv[0] is the name of the file
int main (int argc, string argv[])
{
    // when there is two words you type on the command line
    if( argc == 2)
    {
        for(int i = 0, n = strlen(argv[1]); i < n ; i ++)
        {
            // Notice the toupper function only take a single character as input
            printf("%c", toupper(argv[1][i]));
        }
        printf("\n");
    }
}

