#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string tmp = argv[1];
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (atoi(& tmp[i]) == 0)
            {
                printf("Usage: ./caeser key\n");
                return 1;
            }
        }

        int key = atoi(argv[1]);
        printf("%d\n", key);
    }
    else
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
}
