// Notice the main funtion always return a int value --- WHY?
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// That is because we need the function to return our a value that represent a certain status
// Like 404 when you enter a page that does not exit.
int main (int argc, string argv[])
{
    // when there is two words you type on the command line
    if( argc != 2)
    {
        // if the user dosent do we want they will see this
       printf("Missing Command line arguments\n");
       // the user will not be able to see this number -- the main fuction return
       // however that are ways for us to access this value  like GUI
       // we can type echo $? to see the value
       // the number 1 represents that the user do not type two words
       return 1;
    }
    else
    {
        printf("hello, %s\n", argv[1]);
        //0 represents they did
        return 0;
    }
}
