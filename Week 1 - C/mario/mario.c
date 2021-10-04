#include <stdio.h>
#include <cs50.h>

int main(void) {
    string block = "#";
    string space = " ";

    int choice;

    do
    {
        choice = get_int("Height: ");
    }
    while (choice < 1 || choice > 8);


    for (int i=0; i<choice; i++)
    {
        for (int j=0; j<choice-i-1; j++) {
            printf("%s", space);
        } for (int j=0; j<i+1; j++) {
            printf("%s", block);
        }
        printf("%s", space);
        for (int j=0; j<i+1; j++) {
            printf("%s", block);
        }

        printf("\n");
    }
}

//   #  #
//  ##  ##
// ###  ###
//####  ####
