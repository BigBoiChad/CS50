#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int *list = malloc (3*sizeof(int));
    if (list == NULL)
    {
        free(list);
        return 1;
    }

    list[0]  = 0;
    list[1]  = 1;
    list[2]  = 2;

    // realloc take the past list as input and it will copy the list to the sizeof memeroy
    // This function returns the address of the reallocated block’s first byte
    int *tmp = realloc(list ,4*sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    list = tmp;
    list[3] = 3;

    for (int i = 0; i < 4; i ++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
}
