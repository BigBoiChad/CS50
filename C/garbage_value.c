#include <stdio.h>
#include <stdlib.h>

int main (void)
{

    // frist we just declae there is an array of numbers size 10
    // we did not give it value
    // but it alreadt have a palce in memory
    // and currently those memeory are garbage memeory
    int g[10];

    for (int i = 0; i < 10; i ++)
    {
        printf("%i\n", g[i]);
    }

}