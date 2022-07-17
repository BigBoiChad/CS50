// Integer overflow; Computer can only store a finite number of data.
// In this case when caculate 64 time it will overfolw and then give me a wrong value

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    // Iteratively double i
    int i = 1;
    while (true)
    {
        printf("%i\n", i);
        //sleep means to give result per seconds sleep 1 seconds and then start
        sleep(1);
        // i = 2 * i
        i*=2;
    }
}