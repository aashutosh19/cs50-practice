// inside this file there are all the functions that get used to apply a filter to a picture

#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int row = 0; row < width; row++)
    {
        for (int column = 0; column < height; column++)
        {
            // averages the color intensity and then applies the same value to all the colors to get gray
            float rgbGray = round((image[row][column].rgbtBlue + image[row][column].rgbtGreen + image[row][column].rgbtRed) / 3.000);

            image[row][column].rgbtBlue = rgbGray;
            image[row][column].rgbtGreen = rgbGray;
            image[row][column].rgbtRed = rgbGray;
        }
    }
}

//stops max value at 255 preventing overflow
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaBlue;
    int sepiaRed;
    int sepiaGreen;
    for (int row = 0; row < width; row++)
    {
        for (int column = 0; column < height; column++)
        {
            sepiaRed = limit(round(0.393 * image[row][column].rgbtRed + 0.769 * image[row][column].rgbtGreen + 0.189 * image[row][column].rgbtBlue));
            sepiaGreen = limit(round(0.349 * image[row][column].rgbtRed + 0.686 * image[row][column].rgbtGreen + 0.168 * image[row][column].rgbtBlue));
            sepiaBlue = limit(round(0.272 * image[row][column].rgbtRed + 0.534 * image[row][column].rgbtGreen + 0.131 * image[row][column].rgbtBlue));

            image[row][column].rgbtRed = sepiaRed;
            image[row][column].rgbtGreen = sepiaGreen;
            image[row][column].rgbtBlue = sepiaBlue;

        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for(int column = 0; column < height; column++)
    {
        for (int row = 0; row < width / 2; row++)
        {
            temp[0] = image[row][column].rgbtBlue;
            temp[1] = image[row][column].rgbtRed;
            temp[2] = image[row][column].rgbtGreen;

            image[row][column].rgbtBlue = image[width - row - 1][column].rgbtBlue;
            image[row][column].rgbtRed = image[width - row - 1][column].rgbtRed;
            image[row][column].rgbtGreen = image[width - row - 1][column].rgbtGreen;

            image[width - row - 1][column].rgbtBlue = temp[0];
            image[width - row - 1][column].rgbtRed = temp[1];
            image[width - row - 1][column].rgbtGreen = temp[2];

        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}