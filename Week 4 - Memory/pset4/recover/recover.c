// A program to recover a file from a .raw file.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
int main(int argc, char *argv[])
{
    // Program should accept exactly one command line argument, and that argument should be a file name.
    if (argc != 2) 
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file for reading.
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) 
    {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    // Loop through the file and read 512 bytes at a time into a buffer.
    uint8_t buffer[512];
    int i = 0; // Keep track of the number of 512-byte blocks read.
    while (fread(buffer, 1, 512, f) == 512) 
    {
        // Check if the buffer contains a jpeg header, where the 4th byte in the signature can be any value.
        // If it does, then the buffer contains a jpeg.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1 || buffer[3] == 0xe2
                || buffer[3] == 0xe3 || buffer[3] == 0xe4 || buffer[3] == 0xe5 || buffer[3] == 0xe6 || buffer[3] == 0xe7 || buffer[3] == 0xe8
                || buffer[3] == 0xe9)) 
        {
            // Given that the buffer contains a jpeg image, write the buffer to a new file.
            // The file name should be ###.jpg where ### is the number of the block.
            char filename[8];
            sprintf(filename, "%03d.jpg", i);
            FILE *g = fopen(filename, "w");
            fwrite(buffer, 1, 512, g);
            fclose(g);
            i++;
        }
        // if no jpeg header is found, the buffer should be written to the same jpeg file as the previous block.
        else 
        {
            // The file name should be ###.jpg where ### is the number of the block.
            char filename[8];
            sprintf(filename, "%03d.jpg", i - 1);
            FILE *g = fopen(filename, "a");
            fwrite(buffer, 1, 512, g);
            fclose(g);
        }
    }

    // close the file
    fclose(f);
}