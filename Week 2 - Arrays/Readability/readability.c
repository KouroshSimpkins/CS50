// Compute the coleman-liau index of a given input string.

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Get input from user
    string input = get_string("Text: ");

    // return the number of letters in the input
    int letters = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            letters++;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            letters++;
        }
    }

    // return the number of words in the input
    int words = 1;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            words++;
        }
    }

    // return the number of sentences in the input
    int sentences = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentences++;
        }
    }

    // compute the Coleman-Liau index
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // if the index is less than 1, print "Before Grade 1"
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    // if the index is between 1 and 16, print "Grade %i"
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    // if the index is 16 or higher, print "Grade 16+"
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}