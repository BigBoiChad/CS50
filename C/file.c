#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main (void)
{
    //fopen is a new function we can use to open a file.
    // It will return a pointer to a new type, FILE, that we can read from and write to. The first argument is the name of the file
    // the second argument is the mode we want to open the file in (r for read, w for write, and a for append, or adding to).
    // we creat a file called phonebook
    FILE *file = fopen("phonebook.csv", "a");
    // if we dont have any memory . the fopen will return a NULL pointer
    // means there is no room to point
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);
}
