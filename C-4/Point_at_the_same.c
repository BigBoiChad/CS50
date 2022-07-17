// this case two address is the same
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>



int main (void)
{
    char *s = "hi";
    // Notice we copy s to t
    // But does the t = the string we type?
    // or it equals to the address where we type the string?
    char *t = s;
    printf("%s\n",s);
    printf("%s\n",t);
    printf("%c\n",t[0]);
    // Indeed the t copy the address
    // so if we change the t[0]  == * (t + 0) which is h to H
    // we literally to go that address and change it
    // so s have the address and when we printf s we see the H
    //so we capitalized the same character in memory!
    *t =  toupper(*(t+0));
    printf("%c\n",s[0]);
    printf("%c\n",t[0]);

}