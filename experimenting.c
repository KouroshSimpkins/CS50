#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "Hello world";
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", *(s+i));
    }
}