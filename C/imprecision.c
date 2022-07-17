//a issue with the memeroy compter can only give the approximete number
//the issue called  floating-point imprecision, where we don’t have enough bits to store all possible values
//we can’t represent all possible real numbers (of which there are an infinite number of), so the computer has to store the closest value it can.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float x = get_float("x:");
    float y = get_float("y:");

    //%.50f means we will see fifity 0s behinde the decimal point.
    //With %.50f, we can specify the number of decimal places displayed.
    // Notice is % . 50 f
    printf("%.50f\n", x / y );
}
