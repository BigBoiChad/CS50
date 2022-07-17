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

    int *tmp = malloc(4*sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }
    for (int i = 0 ; i < 4 ; i ++)
    {
        tmp[i] = list [i];
    }
    tmp[3] = 3;
    
    // Free original list of size 3
    free(list);

    // Remember new list of size 4
    list = tmp;

    // Print list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free new list
    free(list);
}
