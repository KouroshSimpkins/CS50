#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>


string cipher(int key, string plaintext);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string tmp = argv[1];
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if ((atoi(& tmp[i]) == 0) && tmp[i] != 48)
            {
                printf("Usage: ./caeser key\n");
                return 1;
            }
        }

        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext:  ");
        string ciphertext = cipher(key, plaintext);
        printf("ciphertext: %s\n", ciphertext);

    }
    else
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
}


string cipher(int key, string plaintext)
{
    string ciphertext = plaintext;

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char ch = plaintext[i];

        for (int j = 0; j < key; j++)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                ch = ch + 1;

                if (ch > 'z')
                {
                    ch = ch - 'z' + 'a' - 1;
                }
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + 1;

                if (ch > 'Z')
                {
                    ch = ch - 'Z' + 'A' - 1;
                }
            }

            ciphertext[i] = ch;
        }

        printf("%c\n", ch);
    }
    return ciphertext;
}
