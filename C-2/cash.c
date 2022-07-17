// Greedy algorithms
#include <stdio.h>
// round function in math header files
#include <math.h>
#include <cs50.h>

// four function or senarios to achieve the Greedy Algorithms
// a number must be postitve which is the first function.Notice at the final line of code. I covert the dollar into s using round fucntion
// the seconde is a senario when the number is bigger than 5, in this case (it could be bigger than 5 or smaller than 5)
// the third is a senario when the number is bigger than 10. if is it we count the time that it - 10 then return the counter times d
// the forth is a senario where the number is bigger than 25, in this case we count the time that it - 23 until it can't and then return the counter times q
int get_positive_float(void);
int s_Less_than_10(int s);
int s_less_than_25(int s);
int s_bigger_than_25(int s);

int main(void)
{
    // using the frist funcion to get a positive number and a round-digits-converted number  0.1 ---into---10
    //pormpt the quesiton
    int s = get_positive_float();
    //frist senario when s > 25
    if (s >= 25)
    {
        // q is the number of qurater we need to give
        int q = s_bigger_than_25(s);
        // s needs to change since we already minus 25 q times
        s = s - 25 * q;

        //the second senario where number is bigger than ten.
        if (s >= 10)
        {

            int d = s_less_than_25(s);
            //  s needs to change again since we already minus 10 d times
            s = s - d * 10 ;

            //the last senario where the number is bigger or less than 5.
            int p = s_Less_than_10(s);

            //Notice the printf has three vairbles: p d q , that is because we need to add the times we minus 25-q 10-d 5-c and 1-p
            // p in this case has two posibilities 1. p is the time the number minus 5  2. p is the time the number minus 5 and the time the number minus 1
            printf("%i\n", p + d + q);
        }
        //the last senario where the number is bigger or less than 5.
        else
        {
            int p = s_Less_than_10(s);
            printf("%i\n", q + p);
        }

    }
    else if (s >= 10)
    {
        int d = s_less_than_25(s);
        s = s - d * 10 ;
        int p = s_Less_than_10(s);

        printf("%i\n", d + p);
    }
    else
    {
        int p = s_Less_than_10(s);

        printf("%i\n", p);
    }
}


// only give a output that is a converted positive vaule
int get_positive_float(void)
{
    float dollar;
    do
    {
        dollar = get_float("Change Owed: ");
    }
    while (dollar < 0);
    int n = round(dollar * 100);
    return n;
}

// Not only needs a input but also a output
//when s is less than 10 in which it has two possibilities
int s_Less_than_10(int s)
{
    if (s >= 5)
    {
        int c = 0;
        do
        {
            s = s - 5;
            c = c + 1;
        }
        while (s >= 5);
        //when s < 5 , it can only be give by a penney
        //Ergo the number of penneies when need is equal to s
        //P is the total number of coins 5 and 1 needed to give to the coustomer
        int p = s + c;
        return p;
    }
    else
    {
        int p = s;
        return p;
    }
}

// when is less than 25 but bigger than 10.
int s_less_than_25(int s)
{
    int d = 0;
    do
    {
        s = s - 10;
        d = d + 1;
    }
    while (s >= 10);
    return d;
}

int s_bigger_than_25(int s)
{
    int q = 0;
    do
    {
        s = s - 25;
        q = q + 1;
    }
    while (s >= 25);
    return q;
}