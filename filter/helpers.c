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

// stops max value at 255 preventing overflow
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
//create a temporary image to be blurred
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            temp[row][column] = image[row][column];
        }
    }
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int sum_blue;
            int sum_green;
            int sum_red;
            float counter;
            sum_blue = sum_green = sum_red = counter = 0;

            //corner pixel on bottom right
            if (row >= 0 && column >= 0)
            {
                sum_red += temp[row][column].rgbtRed;
                sum_green += temp[row][column].rgbtGreen;
                sum_blue += temp[row][column].rgbtBlue;
                counter++;
            }
            //corner pixel on bottom left
            if (row >= 0 && column - 1 >= 0)
            {
                sum_red += temp[row][column-1].rgbtRed;
                sum_green += temp[row][column-1].rgbtGreen;
                sum_blue += temp[row][column-1].rgbtBlue;
                counter++;
            }
            //corner pixel on top left
            if (row - 1 >= 0 && column >= 0)
            {
                sum_red += temp[row-1][column].rgbtRed;
                sum_green += temp[row-1][column].rgbtGreen;
                sum_blue += temp[row-1][column].rgbtBlue;
                counter++;
            }
            //corner pixel on top right
            if (row - 1 >= 0 && column - 1 >= 0)
            {
                sum_red += temp[row-1][column-1].rgbtRed;
                sum_green += temp[row-1][column-1].rgbtGreen;
                sum_blue += temp[row-1][column-1].rgbtBlue;
                counter++;
            }

            //pixels on bottom edge
            if ((row >= 0 && column + 1 >= 0) && (row >= 0 && column + 1 < width))
            {
                sum_red += temp[row][column+1].rgbtRed;
                sum_green += temp[row][column+1].rgbtGreen;
                sum_blue += temp[row][column+1].rgbtBlue;
                counter++;
            }
            //pixels on top edge
            if ((row - 1 >= 0 && column + 1 >= 0) && (row - 1 >= 0 && column + 1 < width))
            {
                sum_red += temp[row-1][column+1].rgbtRed;
                sum_green += temp[row-1][column+1].rgbtGreen;
                sum_blue += temp[row-1][column+1].rgbtBlue;
                counter++;
            }
            //pixels on left edge
            if ((row + 1 >= 0 && column >= 0) && (row + 1 < height && column >= 0))
            {
                sum_red += temp[row+1][column].rgbtRed;
                sum_green += temp[row+1][column].rgbtGreen;
                sum_blue += temp[row+1][column].rgbtBlue;
                counter++;
            }
            //pixels on right edge
            if ((row + 1 >= 0 && column - 1 >= 0) && (row + 1 < height && column - 1 >= 0))
            {
                sum_red += temp[row+1][column-1].rgbtRed;
                sum_green += temp[row+1][column-1].rgbtGreen;
                sum_blue += temp[row+1][column-1].rgbtBlue;
                counter++;
            }

            //middle pixels
            if ((row + 1 >= 0 && column + 1 >= 0) && (row + 1 < height && column + 1 < width))
            {
                sum_red += temp[row+1][column+1].rgbtRed;
                sum_green += temp[row+1][column+1].rgbtGreen;
                sum_blue += temp[row+1][column+1].rgbtBlue;
                counter++;
            }
            //find average colour value
            image[row][column].rgbtRed = round(sum_red / counter);
            image[row][column].rgbtGreen = round(sum_green / counter);
            image[row][column].rgbtBlue = round(sum_blue / counter);
        }
    }
return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];

    for (int rows = 0; rows < height; rows++)
    {
        for (int column = 0; column < width; column++)
        {
            float rGx, gGx, bGx, rGy, gGy, bGy;
            rGx = gGx = bGx = rGy = gGy = bGy = 0;

            // Up
            if (rows > 0)
            {
                rGy += -2 * image[rows-1][column].rgbtRed;
                gGy += -2 * image[rows-1][column].rgbtGreen;
                bGy += -2 * image[rows-1][column].rgbtBlue;
            }
            // Down
            if (rows < height - 1)
            {

                rGy += 2 * image[rows+1][column].rgbtRed;
                gGy += 2 * image[rows+1][column].rgbtGreen;
                bGy += 2 * image[rows+1][column].rgbtBlue;
            }
            // Left
            if (column > 0)
            {
                rGx += -2 * image[rows][column-1].rgbtRed;
                gGx += -2 * image[rows][column-1].rgbtGreen;
                bGx += -2 * image[rows][column-1].rgbtBlue;

            }
            // Right
             if (column < height - 1)
            {
                rGx += 2 * image[rows][column+1].rgbtRed;
                gGx += 2 * image[rows][column+1].rgbtGreen;
                bGx += 2 * image[rows][column+1].rgbtBlue;

            }
            // Up left
            if (rows >= 1 && column >= 1)
            {
                // Primeros tres valores, cambiando de signo muevo de lado el resultado
                rGx += -1 * image[rows-1][column-1].rgbtRed;
                gGx += -1 * image[rows-1][column-1].rgbtGreen;
                bGx += -1 * image[rows-1][column-1].rgbtBlue;
                rGy += -1 * image[rows-1][column-1].rgbtRed;
                gGy += -1 * image[rows-1][column-1].rgbtGreen;
                bGy += -1 * image[rows-1][column-1].rgbtBlue;
            }
            // Up right
            if (rows > 0 && column < width - 1)
            {
                rGx += 1 * image[rows-1][column+1].rgbtRed;
                gGx += 1 * image[rows-1][column+1].rgbtGreen;
                bGx += 1 * image[rows-1][column+1].rgbtBlue;
                rGy += -1 * image[rows-1][column+1].rgbtRed;
                gGy += -1 * image[rows-1][column+1].rgbtGreen;
                bGy += -1 * image[rows-1][column+1].rgbtBlue;
            }
            // Bottom right
            if (rows < height - 1  && column < width - 1)
            {
                rGx += 1 * image[rows+1][column+1].rgbtRed;
                gGx += 1 * image[rows+1][column+1].rgbtGreen;
                bGx += 1 * image[rows+1][column+1].rgbtBlue;
                rGy += 1 * image[rows+1][column+1].rgbtRed;
                gGy += 1 * image[rows+1][column+1].rgbtGreen;
                bGy += 1 * image[rows+1][column+1].rgbtBlue;
            }
            // Bottom left
            if (rows < height - 1  && column > 0)
            {
                rGx += -1 * image[rows+1][column-1].rgbtRed;
                gGx += -1 * image[rows+1][column-1].rgbtGreen;
                bGx += -1 * image[rows+1][column-1].rgbtBlue;
                rGy += 1 * image[rows+1][column-1].rgbtRed;
                gGy += 1 * image[rows+1][column-1].rgbtGreen;
                bGy += 1 * image[rows+1][column-1].rgbtBlue;
            }

            // Compute result
            copy[rows][column].rgbtRed = (int) cap255(sqrt((rGx*rGx)+(rGy*rGy)));
            copy[rows][column].rgbtGreen = (int) cap255(sqrt((gGx*gGx)+(gGy*gGy)));
            copy[rows][column].rgbtBlue = (int) cap255(sqrt((bGx*bGx)+(bGy*bGy)));
        }
    }

    for (int rows = 0; rows < height; rows++)
        {
            for (int column = 0; column < width; column++)
            {
                image[rows][column] = copy[rows][column];
            }
        }
    return;
}

int cap255(double count)
{
    int result = 0;

    if (count >= 255)
    {
        result = 255;
    }
    else if(count < 0)
    {
        result = 0;
    }
    else
    {
        result = (int) round(count);
    }
    return (result);
}
