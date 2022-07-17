#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //geting numbers form user
    int x = get_int("x:");
    int y = get_int("y:");

    // truncation happens when x<y, the right part (x/y) still results as Int --- it won't show as the float type on the rignt part
    // it can be solved by using typecasting
    float z = x / y;
    printf("%f\n", z);
}