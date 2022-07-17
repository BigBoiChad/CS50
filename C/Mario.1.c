//Let’s recreate that pyramid in C, albeit in text, using hashes (#) for brick
//       #
//      ##
//     ###
//    ####
//   #####
//  ######
// #######
//########
#include <cs50.h>
#include <stdio.h>

int get_height_int(void);
void Draw(int n);

int main(void)
{
    //first functiong to get a number from use. If the number is fits the threshold then return the value to h, else re-prompt the question
    int h = get_height_int();

    //using for loop to draw h number of #s
    // Notice the n starts at 1 because this time we want to start drawing first # not zero #
    for (int n = 1; n < h + 1 ; n++)
    {
        // Notice there is a new int m-- which is use for store the vluae height -- since the overall height cannot be changed
        // and the number of space in one line is dertermined by the overall height
        int m = h;
        // use for loop again to draw the number of spaces before the # sign.
        // since the number of space is determinded by the height h; for example; if the height is 8,
        // then the first line needs 7 spaces and 1 # ; if the h is 7 , then the first line needs 6 spaces and 1 #.
        // thats why we use int m to store the h, which will be used latter in l < m - n . inwhich the n is changing.
        // the for loop has two varibles--Two inputs-- thus cannot be include using a simple funciton.
        for (int l = 0 ; l < m - n ; l++)
        {
            //print space befor draw #
            printf(" ");
        }
        //a level of abstraction
        //this function is used to darw number of #s
        //when input n then darw n #s then move to a different line
        Draw(n);
    }
}


//use to get a number between [1,8]
int get_height_int(void)
{
    int h;
    do
    {
        //prompts the user for the pyramid’s height, storing their input in a variable,
        //re-prompting the user again and again as needed if their input is not a positive integer between 1 and 8, inclusive
        h = get_int("Height: ");
    }
    // use || to indicate " or "
    while (h > 8 || h < 1);
    return h;
}


// A for loop similar to the one before
void Draw(int n)
{
    //Draw number of # on each line
    //Draw number of # once on one line then move on to the next. for example; line 7 needs 7# , line 8 needs 8 #
    for (int i = 0 ; i < n ; i++)
    {
        printf("#");
    }
    printf("\n");
}