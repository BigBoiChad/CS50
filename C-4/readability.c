//Implement a program that computes the approximate grade level needed to comprehend some text, per the below.
//$ ./readability
//Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
//Grade 3
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//https://cs50.harvard.edu/x/2021/psets/2/readability/


//frist funciton is to count letters in the text. or charachters in a string of characters
int count_letters(string text);
//Second funtion is to count the number of words in a string of characters.
int count_words(string text);
//Third funciton is to count the number of sentence in a string of characters.
int count_sentence(string text);
//Forth function is to use to caculate the how many numbers(letters or sentences) per 100 words
float numebrs_per_100_words(int n, int word);
// using Coleman-Liau index to determine the readability
void Grade_level(float Index);

int main(void)
{
    //Promt the user for text
    string Text = get_string("TEXT: ");
    //count letters in the text.
    int letter = count_letters(Text);
    //count the number of words in the text
    int word = count_words(Text);
    //count the number of sentence in the text
    int sentence = count_sentence(Text);
    //caculate the how many letters per 100 words
    float L = numebrs_per_100_words(letter, word);
    //caculate the how many sentences per 100 words
    float S = numebrs_per_100_words(sentence, word);
    //caculate the Coleman-Liau index
    float Index = 0.0588 * L - 0.296 * S - 15.8;
    //using Coleman-Liau index to determine the readability
    Grade_level(Index);
    printf("%i\n", sentence);
}






int count_letters(string text)
{

    int letter = 0;
    // strlen fuciton is used to determine the length of the text
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        //using toupper to capitalize every single letters, so all letters are from A-Z.(65-90)
        int m = toupper(text[i]);
        //Determine whether the character is A-Z
        if (m >= 65 && m <= 90)
        {
            // if it is a letter. then letter + 1
            letter = letter + 1;
        }
    }
    return letter;
}


int count_words(string text)
{
    int words = 0;
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        int m = text[i];
        // One way to counting words is to counting the number is space in a text.
        // space '  ' = 32
        if (m == 32)
        {
            words = words + 1;
        }
    }
    //Notice the last word in a sentence doesnt end up with a space rather. It end up with a .
    //so we just add 1 to the word
    words = words + 1;
    return words;
}

int count_sentence(string text)
{
    int sentence = 0;
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        int m = text[i];
        //One way to counting sentence is to counting the number of ! . and ?
        // accoring to ASCII that is ! (33） ? (63）. (46)
        if (m == 46 || m == 33 || m == 63)
        {
            sentence = sentence + 1;
        }
    }
    return sentence;
}

//Notice this costom function return a float type value
float numebrs_per_100_words(int n, int word)
{
    //Using typecasting to convert the divident of two integer into a floating point
    float L = n / (float)word * 100;
    return L;
}

//Notice the input is a floating point
void Grade_level(float Index)
{
    if (Index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        //Notice we use the round up funciton from math.h
        //to round the number to the nearest integer
        int index = round(Index);
        if (index >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", index);
        }
    }
}