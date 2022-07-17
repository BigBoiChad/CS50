#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main (int argc, char *argv[])
{
    if (argc != 3)
    {
        return 1;
    }

    FILE *source = fopen(argv[1], "r");

    if (source == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    FILE *destination = fopen(argv[2],"w");

    if (destination == NULL)
    {
        fclose(source);
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // this is a buffer of one byte !!!
    BYTE buffer;
    int count = 0;
    while (fread(&buffer, sizeof(BYTE), 1, source))
    {   
        count ++ ;
        
        fwrite(&buffer, sizeof(BYTE), 1, destination);
    }

    fclose(source);
    fclose(destination);
    printf("%i bytes\n",count);
    return 0;
}


