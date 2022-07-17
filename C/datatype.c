#include <cs50.h>
#include <stdio.h>
#include <string.h>

//used to def a new data type with new data structure
//Creat our own costom data types that themslevs data strcture
typedef struct
{
    string name;
    string number;
}
person;

const int NUMBER = 2;
int main (void)
{
    // [2] means the legth, that is how many data we need
    // it will still count from 0-1
    // 0 means the first data
    person people[NUMBER];
    for(int i = 0 ; i < NUMBER; i++)
    {
        people[i].name = get_string("What is your name? ");
        people[i].number = get_string("What is the number?");
    }
    for (int i = 0; i < 2 ; i ++)
    {
        if (strcmp(people[i].name, "Alex") == 0)
        {
            printf("Found\n Number : %s\n Name: %s\n", people[i].number,people[i].name);
        }
    }
}
