#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompts user for size at start of time period
    int Start_Size = get_int("Start size: ");

    while (Start_Size < 9) {
        printf("Start size must be greater than 9");
        Start_Size = get_int("\nStart size: ");
    }
    //Prompts user for size at end of time period
    int End_Size = get_int("End size: ");

    while (End_Size < Start_Size) {
        printf("End size must be larger than start size");
        End_Size = get_int("\nEnd size: ");
    }
    //Calculates the number of years until the end size is readhed
    int n = Start_Size;
    int years = 0;

    while (n < End_Size) {
        int Dead_llamas = (n/4);
        int New_llamas = (n/3);
        n = n + New_llamas - Dead_llamas;
        years++;
    }
    
    //prints the number of years that it takes
    printf("Years: %d\n", years);
}