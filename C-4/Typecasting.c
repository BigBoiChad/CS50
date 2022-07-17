//Solve the truncation issue by change the data type of x and y using typecasting

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //geting numbers form user
    int x = get_int("x:");
    int y = get_int("y:");

    //Slove the truncation by changing the type of data for x and y using () --Typecasting
    float z = (float) x / (float) y;
    printf("%f\n", z);
}