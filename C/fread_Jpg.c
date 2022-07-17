#include <stdio.h>
#include <stdint.h>

// we define a BYTE as eight bits
typedef uint8_t  BYTE;

// Notice the second input is char *argv[]
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    // we need to input the file name in the command line and then read
    FILE *file = fopen(argv[1], "r");

    if (!file)
    {
        return 1;
    }

    // first of all we creat a array of 3 BYTE which is a BYTE type
    // bytes[3] can store 3 bytes
    // this is a buffer zone
    BYTE bytes[3];
    //Then, we try to open a file and read the first three bytes from the file with fread,
    // into a buffer called bytes.
    // this function grad bytes from the file
    // it reads into this buffer(bytes) , the type is BYTE and reads 3 from the file
    fread(bytes,  3, file);

    // Now we have the firs three bytes and compare each to the stander Prefix
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Maybe\n");
    }
    else
    {
        printf("NO\n");
    }
    fclose(file);
}