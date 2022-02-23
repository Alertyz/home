#include "helpers.h"
#include <stdio.h>
#include <math.h>

//Function to blur the middle
void middle_blur(int height, int width, RGBTRIPLE image[height][width], int j, int i, RGBTRIPLE copy[height][width],
                 float averageRed, float averageGreen, float averageBlue);
                 
//Function to blur the edge
void edge_blur(int height, int width, RGBTRIPLE image[height][width], int j, int i, RGBTRIPLE copy[height][width], float averageRed,
               float averageGreen, float averageBlue);
               
//Function to blur the corner
void corner_blur(int height, int width, RGBTRIPLE image[height][width], int j, int i, RGBTRIPLE copy[height][width],
                 float averageRed, float averageGreen, float averageBlue);
                 
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            average = average / 3;
            average = round(average);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
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
            float sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            float sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            float sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            else if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            else if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            
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
    float half = width / 2;
    half = round(half);
    
    for (int i = 0; i < height; i++)
    {
        int w = width - 1;
        for (int j = 0; j < half; j++)
        {
            RGBTRIPLE copy = image[i][j];
            image[i][j] = image[i][w];
            image[i][w] = copy;
            w--;
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{ 
    float averageRed = 0;
    float averageGreen = 0;
    float averageBlue = 0;
    RGBTRIPLE copy[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            middle_blur(height, width, image, j, i, copy, averageRed, averageGreen, averageBlue);
            edge_blur(height, width, image, j, i, copy, averageRed, averageGreen, averageBlue);
            corner_blur(height, width, image, j, i, copy, averageRed, averageGreen, averageBlue);
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j]; 
        }
    }
    
    return;
}

void middle_blur(int height, int width, RGBTRIPLE image[height][width], int j, int i, RGBTRIPLE copy[height][width], 
                 float averageRed, float averageGreen, float averageBlue)
{
    if (height >= 3 && width >= 3 && i != 0 && i != height - 1 && j != 0 && j != width - 1)
    {
        for (int m = i - 1; m < i + 2; m++)
        {
            for (int n = j - 1; n < j + 2; n++)
            {
                averageRed += image[m][n].rgbtRed;
                averageGreen += image[m][n].rgbtGreen;
                averageBlue += image[m][n].rgbtBlue;
            }
        }    
        copy[i][j].rgbtRed = round(averageRed / 9);
        copy[i][j].rgbtGreen = round(averageGreen / 9);
        copy[i][j].rgbtBlue = round(averageBlue / 9);
        
        averageRed = 0;
        averageGreen = 0;
        averageBlue = 0;
    }
    
    return;
}

void edge_blur(int height, int width, RGBTRIPLE image[height][width], int j, int i, RGBTRIPLE copy[height][width], float averageRed, 
               float averageGreen, float averageBlue)
{
    if ((i == 0 || i == height - 1) && j != 0 && j != width - 1)
    {
        int m = i - 1;
        int n = j - 1;
        if (m == -1)
        {
            m++;
        }
        
        for (int a = m; a < m + 2; a++)
        {
            for (int b = n; b < n + 3; b++)
            {
                averageRed += image[a][b].rgbtRed;
                averageGreen += image[a][b].rgbtGreen;
                averageBlue += image[a][b].rgbtBlue;
            }
        }
        
        copy[i][j].rgbtRed = round(averageRed / 6);
        copy[i][j].rgbtGreen = round(averageGreen / 6);
        copy[i][j].rgbtBlue = round(averageBlue / 6);
        
        averageRed = 0;
        averageGreen = 0;
        averageBlue = 0;
    }
    
    if (i != 0 && i != height - 1 && (j == 0 || j == width - 1))
    {
        int m = i - 1;
        int n = j - 1;
        if (n == -1)
        {
            
            n++;
            
        }
        
        for (int a = m; a < m + 3; a++)
        {
            for (int b = n; b < n + 2; b++)
            {
                averageRed += image[a][b].rgbtRed;
                averageGreen += image[a][b].rgbtGreen;
                averageBlue += image[a][b].rgbtBlue;
            }
        }
        
        copy[i][j].rgbtRed = round(averageRed / 6);
        copy[i][j].rgbtGreen = round(averageGreen / 6);
        copy[i][j].rgbtBlue = round(averageBlue / 6);
        
        averageRed = 0;
        averageGreen = 0;
        averageBlue = 0;
    }
    
    return;
}

void corner_blur(int height, int width, RGBTRIPLE image[height][width], int j, int i, RGBTRIPLE copy[height][width],
                 float averageRed, float averageGreen, float averageBlue)
{
    if ((i == 0 || i == height - 1) && (j == 0 || j == width - 1))
    {
        int m = i - 1;
        int n = j - 1;
        
        if (n == -1)
        {
            n++;
        }
        if (m == -1)
        {
            m++;
        }
        
        for (int a = m; a < m + 2; a++)
        {
            for (int b = n; b < n + 2; b++)
            {
                averageRed += image[a][b].rgbtRed;
                averageGreen += image[a][b].rgbtGreen;
                averageBlue += image[a][b].rgbtBlue;
            }
        }
        
        copy[i][j].rgbtRed = round(averageRed / 4);
        copy[i][j].rgbtGreen = round(averageGreen / 4);
        copy[i][j].rgbtBlue = round(averageBlue / 4);
        
        averageRed = 0;
        averageGreen = 0;
        averageBlue = 0;
    }
    return;
}