#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

string LOWER_ALPHABET[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
string UPPER_ALPHABET[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "U", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        char keyArray[strlen(key)];
        strcpy(keyArray, key);
        for (int i = 0; i < strlen(key); i++)
        {
            char temp = keyArray[i];
            keyArray[i] = toupper(temp);
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
    }
}
