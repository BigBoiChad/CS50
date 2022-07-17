#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    string names[] = {"Alex", "Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

    for (int i = 0 ; i < 8 ; i++)
    {
        // the strcmp function can compare strings letters to letter
        // it bascially compare numbers according to ASCII code
        // it can return three values : 0 --means the name is right in string
        // negatative values means the word or string is on the left of the string we in put
        // Positive value measn the word or string is on the right part of the string
        // remember the if () needs a boolean expression or a bool type , which can only input ture or flase
        // only value 0 is false, any value is considered ture (postitive & negataitve)
        if (strcmp(names[i], "Alx") == 0)
        {

            printf ("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}


//Sort1
//Random10000- 0.475s / 0.229s / 0.012s
//Reversed10000- 0.341s / 0.184s / 0.012s
//Sorted10000- 0.037s/ 0.000s/0.027s


//Sort2
//Random10000- 0.019s / 0.007s/0.011s
//Reversed10000- 0.098/ 0.008s/0.016s
//Sorted10000-0.022s/ 0.009s/0.013s


//Sort3
//Random10000- 0.225s/0.098s/0.016s
//Reversed10000- 0.166s/0.103s/0.012s
//Sorted10000-0.187s/0.100s/0.016s