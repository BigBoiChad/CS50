// Abstraction and scope
// creat a function to only get positive number ergo get_positive_int
#include <stdio.h>
#include <cs50.h>

// A prototype
int get_positive_int(void);


int main(void)
{
// call the funtcion to get a positive nunmber
// the right part needs to give a output and then this output will be stored in i
    int i = get_positive_int();

    printf("%i\n", i);

}

// calls get_int repeatedly until we have some integer that’s not less than 1.
// we need this function to give a output (int)
int get_positive_int(void)
{
    //Do while condition means do something (first) while ( n < 1 ).
    //Notice the n follow ; Also by declare the n outside the do while {} we will solve a issue called scope
    //the scope of the varible is where you can use the varible ergo where the varible exists
    int n;
    do
    {
        // if we change the n to int n, it will not work because then the int n only existed in it's scope which in this case is the “ {} ”,
        // ergo, while(-outside the {}-) cannot find the n value
        n = get_int("Posititve interge: ");
    }
    // while(n < 1) keep doing the thing inside of do { };
    while (n < 1);
    //use return to give the n which is the int type to the computer as output
    return n;
}