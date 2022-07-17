//Implement a program that encrypts messages using Caesar’s cipher, per the below.
//$ ./caesar 13
//plaintext:  HELLO
//ciphertext: URYYB
//https://cs50.harvard.edu/x/2021/psets/2/caesar/
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

// Command-Line Arguments
// in this case we give the main function a input
//argc conuting the number of arguments in the command line
//argv[] is a string of word we typed at the command line
int main(int argc, string argv[])
{
    if (argc == 2)
    {

        //m here is used to counting the digits number in a string
        // as a way to determine whther the word we type is completely numeric not just a number and a letter.
        int m = 0;
        for (int i = 0, n = strlen(argv[1]); i < n ; i++)
        {
            //using isdigit funciton to check whether the single character is a number or not
            // Notice the input here argv[1][i]
            // this means to find the frist character in the second word
            if (isdigit(argv[1][i]))
            {
                m = m + 1;
            }
        }
        // if the nuber of digit string  contains equals to its length then this string is compeletely numberic
        if (m == strlen(argv[1]))
        {
            //using atoi function to turn the string type number into a integer
            //toi this function converts a (positive or negative) integer from a string
            int key = atoi(argv[1]);
            string pl = get_string("plaintext: ");
            printf("ciphertext:");

            for (int i = 0, n = strlen(pl); i < n; i++)
            {
                //convert the single character into a number
                int p = pl[i];
                // determine whether the character is a upperclass-letter (A-Z)
                if (p >= 65 && p <= 90)
                {
                    // since there is only26 letter, we use this to make sure we only add key once
                    key = key % 26;
                    // the number after adding up the key---encypted!!
                    p = (p + key);
                    //determine whether the p is bigger than 90 --- bigger than Z
                    //if it is we need to cycle back to A --that is 65
                    if (p > 90)
                    {
                        // by minus 26 we can cycle back to A+
                        p = p - 26;
                        //print the encypted letter by simply print %c type integer
                        printf("%c", p);
                    }
                    else
                    {
                        //if p is not bigger than Z or 90, we don not need to cycle back
                        // we just print the letter --- pl[i] --here is a single character+key
                        printf("%c", pl[i] + key);
                    }
                }
                //determine wheter it is a lower class letter.
                else if (p >= 97 && p <= 122)
                {
                    //same logic here
                    key = key % 26;
                    p = (p + key);
                    if (p > 122)
                    {
                        p = p - 26;
                        printf("%c", p);
                    }
                    else
                    {
                        printf("%c", pl[i] + key);
                    }
                }
                else
                {
                    printf("%c", pl[i]);
                }
            }
            printf("\n");
            // Notice we return 0; becasue the user did do what we ask them to do
            // type two words and the latter word is numeric
            return 0;
        }
        else
        {
            printf("Usage: %s key\n", argv[0]);
            //The user did not do what we ask them to do; that is to make sure the second word is numeric
            return 1;
        }
    }
    else
    {
        printf("Usage: %s\n", argv[0]);
        //Notice we return 0; becasue the user did not do what we ask them to do
        // type two words and the latter word is numeric
        return 1;
    }
}
