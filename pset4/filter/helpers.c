#include "helpers.h"
#include <math.h>
#include <stdio.h>


BYTE average_value(BYTE x, BYTE y, BYTE z);
BYTE convert_to_byte(float x);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE ave_color = average_value(image[i][j].rgbtRed, image[i][j].rgbtBlue, image[i][j].rgbtGreen);
            image[i][j].rgbtRed = ave_color;
            image[i][j].rgbtBlue = ave_color;
            image[i][j].rgbtGreen = ave_color;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float new_Red = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float new_Green = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float new_Blue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            image[i][j].rgbtRed = convert_to_byte(new_Red);
            image[i][j].rgbtBlue = convert_to_byte(new_Blue);
            image[i][j].rgbtGreen = convert_to_byte(new_Green);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {

            image2[i][width - 1 - j] = image[i][j];

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {

            image[i][j] = image2[i][j];

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blur [height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            blur[i][j] = image[i][j];
        }
    }

    // check for every pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // reset every vlaue one at a time
            int count = 0;
            float sumR = 0;
            float sumG = 0;
            float sumB = 0;

            // all row pixel can be show as the past(-1) + self(0) + next(1)
            for (int k = -1; k < 2; k++)
            {
                // all colmn pixel can be show as the past(-1) + self(0) + next(1)
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows
                    // if k = -1;  i = 0; we skip this pixel and make k = 1 then we get the pixel at 0 row
                    // Notice even if i = 0 k = -1 not working the k will increase
                    if (i + k < 0 || i + k >= height)
                    {
                        // jump to l = l + 1 and when l = 2 , k + +
                        // beacuse the row pixel is invaild there is no need to find the colmn pixel
                        continue;
                    }

                    // Check if pixel is outside columns
                    // if l = -1; j = 0; we skip this pixel and make l = 1 we get a pixel at 0 colmn
                    if (j + l < 0 || j + l >= width)
                    {
                        //jump to l = l + 1 and when l = 2 , k + +
                        continue;
                    }
                    // Otherwise add to sums

                    sumR += blur[i + k][j + l].rgbtRed;
                    sumG += blur[i + k][j + l].rgbtGreen;
                    sumB += blur[i + k][j + l].rgbtBlue;
                    count++;
                }
            }

            image[i][j].rgbtRed = round(sumR / count);
            image[i][j].rgbtGreen = round(sumG / count);
            image[i][j].rgbtBlue = round(sumB / count);
        }
    }
    return;
}

BYTE average_value(BYTE x, BYTE y, BYTE z)
{
    float  red = x;
    float  blue = y;
    float  green = z;
    BYTE ave = round((red + blue + green) / 3);
    return ave;
}

BYTE convert_to_byte(float x)
{
    int y = round(x);
    if (y > 255)
    {
        y = 255;
    }
    if (y < 0)
    {
        y = 0;
    }
    ;
    BYTE new_color = y;
    return new_color;
}