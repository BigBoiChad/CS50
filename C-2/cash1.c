// Greedy Algorithms
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int get_positive_float(void);

int main(void)
{
    int s = get_positive_float();

    if (s >= 25)
    {
        int q = 0;
        do
        {
            s = s - 25;
            q = q + 1;
        }
        while (s >= 25);

        if (s >= 10)
        {
            int d = 0;
            do
            {
                s = s - 10;
                d = d + 1;
            }
            while (s >= 10);

            if (s >= 5)
            {
                int c = 0;
                do
                {
                    s = s - 5;
                    c = c + 1;
                }
                while (s >= 5);
                int p = s;
                printf("%i\n", q + d + c + s);
            }
            else
            {
                printf("%i\n", q + d + s);
            }
        }
        else if (s >= 5)
        {
            int c = 0;
            do
            {
                s = s - 5;
                c = c + 1;
            }
            while (s >= 5);
            int p = s;
            printf("%i\n", q + c + s);
        }
        else
        {
            printf("%i\n", q + s);
        }
    }
    else if (s >= 10)
    {
        int d = 0;
        do
        {
            s = s - 10;
            d = d + 1;
        }
        while (s >= 10);

        if (s >= 5)
        {
            int c = 0;
            do
            {
                s = s - 5;
                c = c + 1;
            }
            while (s >= 5);
            int p = s;
            printf("%i\n", d + c + s);
        }
        else
        {
            printf("%i\n", d + s);
        }
    }
    else if (s >= 5)
    {
        int c = 0;
        do
        {
            s = s - 5;
            c = c + 1;
        }
        while (s >= 5);
        int p = s;
        printf("%i\n", c + s);
    }
    else
    {
        int p = s;
        printf("%i\n", p);
    }
}

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