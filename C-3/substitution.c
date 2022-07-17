//Implement a program that implements a substitution cipher, per the below.
//$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
//plaintext:  HELLO
//ciphertext: VKXXN
//https://cs50.harvard.edu/x/2021/psets/2/substitution/
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

//argc conuting the number of arguments in the command line.
//argv[] is a string of word we typed at the command line.
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //int s is used to count the number of letters in the argv[1]-- the seconde command line argument.
        int s = 0;
        //int m is use to add up all the letters from 65 - 90 (A - Z) As a way to determine whether all 26 letters are included.
        int m = 0;
        //int j is used to convert the character in argv into a integer.
        int j = 0;
        for (int i = 0, n = strlen(argv[1]); i < n ; i++)
        {
            // determine whether the character is a letter.
            if (isalpha(argv[1][i]))
            {
                // Notice we use the touuper funciton from ctype.h
                // the reason is we want to make sure the j is ranging from 65 to 90.
                j = toupper(argv[1][i]);
                // m is the sum of all letter-integer ASCII.
                m = j + m;
                // s is the number of letter in argv[1].
                s = s + 1;
            }
        }
        //the sum of letter (A-Z) is 2015. If m = 2015, it means that it include A-Z.
        // S = 26 means there are 26 letters and the sum is 2015 -- (A-Z).
        if (m == 2015 && s == 26)
        {
            //Key is the the index we need to find in the argv[1].
            int key = 0;
            //Prompt user the question
            string pl = get_string("plaintext: ");
            //Print the ciphertext
            printf("ciphertext: ");
            //Now we need encypted the plaintext one character by a time.
            for (int i = 0, n = strlen(pl); i < n ; i++)
            {
                // the reson we upper the letter is that we need the key to be 0-25;contain all the index number in argv[1].
                // since argv[1] have 26 letter starting from argv[1][0] to argv[1][25].
                // this way we can show argv[1][i] by showing argv[1][key].
                //Now we know the position the character in plaintext should be in the argv[1].
                key = toupper(pl[i]) - 65;
                // use isalpha funciton from ctype.h to determine whether the character in plaintext is a letter.
                if (isalpha(pl[i]))
                {
                    // use islower funciton from ctype.h to determine whether the letter is capitalized.
                    if (islower(pl[i]))
                    {
                        // if it is lower we print out the lowercase of letter.
                        // and the letter is on the key position in argv[1].
                        printf("%c", tolower(argv[1][key]));
                    }
                    else
                    {
                        // if it is upper we print out the upper case of letter.
                        // and the letter is on the key position in argv[1].
                        printf("%c", toupper(argv[1][key]));
                    }
                }
                else
                {
                    //If it is not a letter we return the same character.
                    printf("%c", pl[i]);
                }
            }
            printf("\n");
            return 0;
        }
        else if (s == 26)
        {
            // If s = 26 means there are 26 characters while the m != 2015. ergo there must be a repeated letter.
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        else
        {
            // if s != 26 || m != 2015. means there is not 26 letters
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
}