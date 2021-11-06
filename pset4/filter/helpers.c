#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Convert all pixels to grayscale
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average of RGB values
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Set RGB values to average
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // convert the image to sepia
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Store original RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Calculate sepia values
            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            // If value is greater than 255, set to 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Set RGB values to sepia
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // flip the image horizontally
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap the pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // perform a box blur which takes into account edges and corners
    // Create a temporary image
    RGBTRIPLE temp[height][width];
    // Copy original image to temporary image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // Perform blur
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Set RGB values to 0
            image[i][j].rgbtRed = 0;
            image[i][j].rgbtGreen = 0;
            image[i][j].rgbtBlue = 0;
            // Calculate average of RGB values
            int avg = 0;
            // Set RGB values to average
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                avg += temp[i - 1][j - 1].rgbtRed;
                avg += temp[i - 1][j - 1].rgbtGreen;
                avg += temp[i - 1][j - 1].rgbtBlue;
            }
            if (i - 1 >= 0)
            {
                avg += temp[i - 1][j].rgbtRed;
                avg += temp[i - 1][j].rgbtGreen;
                avg += temp[i - 1][j].rgbtBlue;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                avg += temp[i - 1][j + 1].rgbtRed;
                avg += temp[i - 1][j + 1].rgbtGreen;
                avg += temp[i - 1][j + 1].rgbtBlue;
            }
            if (j - 1 >= 0)
            {
                avg += temp[i][j - 1].rgbtRed;
                avg += temp[i][j - 1].rgbtGreen;
                avg += temp[i][j - 1].rgbtBlue;
            }
            avg += temp[i][j].rgbtRed;
            avg += temp[i][j].rgbtGreen;
            avg += temp[i][j].rgbtBlue;
            if (j + 1 < width)
            {
                avg += temp[i][j + 1].rgbtRed;
                avg += temp[i][j + 1].rgbtGreen;
                avg += temp[i][j + 1].rgbtBlue;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                avg += temp[i + 1][j - 1].rgbtRed;
                avg += temp[i + 1][j - 1].rgbtGreen;
                avg += temp[i + 1][j - 1].rgbtBlue;
            }
            if (i + 1 < height)
            {
                avg += temp[i + 1][j].rgbtRed;
                avg += temp[i + 1][j].rgbtGreen;
                avg += temp[i + 1][j].rgbtBlue;
            }
            if (i + 1 < height && j + 1 < width)
            {
                avg += temp[i + 1][j + 1].rgbtRed;
                avg += temp[i + 1][j + 1].rgbtGreen;
                avg += temp[i + 1][j + 1].rgbtBlue;
            }
            avg = round(avg / 9.0);
            // Set RGB values to average
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}
