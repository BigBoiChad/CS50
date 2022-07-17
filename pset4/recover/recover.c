#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Input only one command-line argument");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (!file)
    {
        printf("The file cannot be open for reading");
        return 1;
    }
    
    // creat a buffer the same size as a single bolck 
    // and copy that data into a new jpg file
    BYTE buffer[512];
    // keep track of the name of a file
    int i = 0;
    // file name contains 8 BYTES 000.jpg
    // a array of character -- an array of BYTES
    char filename[8];

    // we need to creat a file called jpg and make it 0 or NULL
    FILE *jpg = NULL;

    // the fread wii return a number that indicate how many data left, showing the limit
    while (fread(&buffer, sizeof(BYTE), 512, file))
    {    
        // each time to find a header and at the same time close the last file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {   
            // close the last file and then write a new one
            if (jpg != NULL)
            {   
                fclose(jpg);
            }

            
            // this can creat a string
            sprintf(filename, "%03i.jpg", i);
            // open the file and start the write mode 
            jpg = fopen(filename, "w");
            
            fwrite(&buffer, sizeof(BYTE), 512, jpg);
            i ++ ;
        }


        // we have the first block that contain a header , now we need to write the rest blocks
        else if (jpg != NULL)
        {   
            // this blocks dont contain a header but follows the header!!!
            fwrite(&buffer, sizeof(BYTE), 512, jpg);
        }
    }
    fclose(file);
    return 0;
}