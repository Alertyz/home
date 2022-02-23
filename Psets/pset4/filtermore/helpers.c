#include "helpers.h"
#include <math.h>

// Function to edge 
void edge_filter(int height, int width, RGBTRIPLE image[height][width], int j, int i, RGBTRIPLE copy[height][width]);

// Function to do the Sobel operator
float G_count(float averagecolor[]);

// Function to blur 
void blur_filter(int height, int width, RGBTRIPLE image[height][width], int j, int i, RGBTRIPLE copy[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            average = round((average) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    
    return;
    
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    float half = round(width / 2);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0, w = width - 1; j < half; j++, w--)
        {
            RGBTRIPLE copy = image[i][j];
            image[i][j] = image[i][w];
            image[i][w] = copy;
        }
    }
    
    return;
    
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE copy[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blur_filter(height, width, image, j, i, copy);
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE copy[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            edge_filter(height, width, image, j, i, copy);
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

void edge_filter(int height, int width, RGBTRIPLE image[height][width], int j, int i, RGBTRIPLE copy[height][width])
{
    
    float G = 0;
    float averageRed[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    float averageGreen[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    float averageBlue[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int count = -1;
    
    for (int m = i - 1; m < i + 2; m++)
    {
        for (int n = j - 1; n < j + 2; n++)
        {
            count++;
            if ((m < 0 || n < 0) || (m >= height || n >= width))
            {
                    
                averageRed[count] = 0;
                averageGreen[count] = 0;
                averageBlue[count] = 0;
                    
            }
                
            else
            {
                    
                averageRed[count] = image[m][n].rgbtRed;
                averageGreen[count] = image[m][n].rgbtGreen;
                averageBlue[count] = image[m][n].rgbtBlue;
                
            }
        }       
    }
        
    // red    
    G = G_count(averageRed);
    copy[i][j].rgbtRed = G;
                
    //green
    G = G_count(averageGreen);
    copy[i][j].rgbtGreen = G;
    
    //blue
    G = G_count(averageBlue);
    copy[i][j].rgbtBlue = G;
        
    return;
}

float G_count(float averagecolor[])
{
    
    float gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    float gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    float Gxv = 0;
    float Gyv = 0;
    

    for (int i = 0; i < 9; i++)
    {
        
        Gxv += gx[i] * (averagecolor[i]);
        
    }
    
    for (int i = 0; i < 9; i++)
    {
        
        Gyv += gy[i] * (averagecolor[i]);
        
    }
    
    Gxv *= Gxv;
    Gyv *= Gyv;
    Gxv += Gyv;
    
    Gxv = sqrt(Gxv);
    Gxv = round(Gxv);
    
    if (Gxv >= 255)
    {
        
        Gxv = 255;
        
    }
    
    return Gxv;
}

void blur_filter(int height, int width, RGBTRIPLE image[height][width], int j, int i, RGBTRIPLE copy[height][width])
{
    float averageRed = 0;
    float averageGreen = 0;
    float averageBlue = 0;
    int count = 0;
    
    for (int m = i - 1; m < i + 2; m++)
    {
        for (int n = j - 1; n < j + 2; n++)
        {
            if ((m < 0 || n < 0) || (m >= height || n >= width))
            {
                    
                averageRed += 0;
                averageGreen += 0;
                averageBlue += 0;
                    
            }
                
            else
            {
                    
                count++;
                    
                averageRed += image[m][n].rgbtRed;
                averageGreen += image[m][n].rgbtGreen;
                averageBlue += image[m][n].rgbtBlue;
                
            }
        }       
    }
        
    if (count == 4)
    {
            
        copy[i][j].rgbtRed = round(averageRed / 4);
        copy[i][j].rgbtGreen = round(averageGreen / 4);
        copy[i][j].rgbtBlue = round(averageBlue / 4);
            
        return;
    }
        
    else if (count == 6)
    {
            
        copy[i][j].rgbtRed = round(averageRed / 6);
        copy[i][j].rgbtGreen = round(averageGreen / 6);
        copy[i][j].rgbtBlue = round(averageBlue / 6);
            
        return;
    }
        
    else if (count == 9)
    {
            
        copy[i][j].rgbtRed = round(averageRed / 9);
        copy[i][j].rgbtGreen = round(averageGreen / 9);
        copy[i][j].rgbtBlue = round(averageBlue / 9);
            
        return;
    }
        
    return;
    
}