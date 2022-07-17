#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

int main (void)
{
    // tree is a pointer to a node that is the root of the tree we're searching in.
    // number is the value we're trying to find in the tree.
    bool search(node *tree, int number)
    {
        // First, we make sure that the tree isn't NULL, if we've reached a node
        // on the bottom, or if our tree is entirely empty
        if (tree == NULL)
        {
            return false;
        }
        // If we're looking for a number that's less than the tree's number,
        // search the left side, using the node on the left as the new root
        else if (number < tree->number)
        {
            return search(tree->left, number);
        }
        // Otherwise, search the right side, using the node on the right as the new root
        else if (number > tree->number)
        {
            return search(tree->right, number);
        }
        // Finally, we've found the number we're looking for, so we can return true.
        // We can simplify this to just "else", since there's no other case possible
        else if (number == tree->number)
        {
            return true;
        }
    }
}