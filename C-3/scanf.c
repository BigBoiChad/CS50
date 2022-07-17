#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    
    int x;
    printf("x: ");

    // it will scan we typed
    // notice the second input is a address we want to put value in
    // scanf dont have any erro checking system
    // if we type cat , it will return a 0 value
    scanf("%i", &x);
    printf("%i\n",x);
    
    
    
    // we try this we string
    // notice we need to allocate memort frist
    // get_string function contiunesly to increase the malloc as we type more character
    char *s  = malloc(4);
    printf("s: ");
    // notice here s is just a pointer
    scanf("%s", s);
    printf("s: %s \n",s);
}