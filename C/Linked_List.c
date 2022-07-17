#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main (void)
{
    // list here is the starting pointer as show in the video
    // we creat a empty list
    // we need to set the pointer to NULL; otgherwise it will just pointing at everywhere (grabage value or some value we are not supposed to touch)
    node *list = NULL;

    // We use sizeof(node) to get the right amount of memory to allocate, and
    // malloc returns a pointer (a address of the node) that we save as n
    // n here is a tem pointer we use every time when a new value is added
    // Notice here n is also a empty list
    // the malloc will find two memory and then return a address of the first memory(number ) to n
    // so n is pointing at the number
    node *n = malloc (sizeof(node));

    // Check whether the computer is out of memeory
    if (n == NULL)
    {
        free(list);
        return 1;
    }

    // this is the same as n -> (arrow notation) number
    // follow the n pointer to the number's address and put 1 in it
    n->number = 1;
    // this is  the same as n -> next
    n->next = NULL;

    // Now we need to make the list pointer at n node
    // the list and the n now pointing at the same location
    list = n;

    // we change the location n pointer to point a new node
    n = malloc (sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }

    n -> number = 2;
    n -> next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
    }
    n->number = 3;
    n->next = NULL;
    list -> next -> next = n;

    // Print list using a loop, by using a temporary variable, tmp, to point
    // to list, the first node. Then, every time we go over the loop, we use
    // tmp = tmp->next to update our temporary pointer to the next node. We
    // keep going as long as tmp points to somewhere, stopping when we get to
    // the last node and tmp->next is null.
    for (node *tmp = list; tmp != NULL; tmp =tmp->next)
    {
        printf("%i\n", tmp->number);
    }



    // Now suppose we want to insert a number 0 to the front of the list
    n = malloc (sizeof(node));
    if (n == NULL)
    {
        free (list);
        return 1;
    }

    n->number = 0;

    // Notice here we assign the pinter to be the same as the first node
    n->next = list;

    // the then make the list pointing at the n.
    list = n;

    for (node *tmp = list; tmp != NULL; tmp =tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // Now we want to insert a number in the middle
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n -> number = 99;
    n -> next = list->next ->next;
    list -> next -> next= n;

    for (node *tmp = list; tmp != NULL; tmp =tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    while(list != NULL)
    {
        // we need to creat a tmp node to store the node the list is pointing at
        // before we free the list
        // otherwise we will lost keeping track the rest of the linked list
        node *tmp = list -> next;

        free(list);
        list = tmp;

    }
}



