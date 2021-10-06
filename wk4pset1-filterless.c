#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //This is currently reading each image[i][j], height and width, data location
    //so we need to get the height and width number and DIRECTLY TARGET the array location with changes
    //for this one we average and assign to each pixel accordingly

    int average;

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            int blue = image[h][w].rgbtBlue;
            int red = image[h][w].rgbtRed;
            int green = image[h][w].rgbtGreen;

            average = (blue + red + green) / 3;

            image[h][w].rgbtBlue = average;
            image[h][w].rgbtRed = average;
            image[h][w].rgbtGreen = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //get original values
    //run through sepia formula
    //for each one: if more than 255, turn them into 255
    //assign sepiaVariants to image[h][w]

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            int blue = image[h][w].rgbtBlue;
            int red = image[h][w].rgbtRed;
            int green = image[h][w].rgbtGreen;

            int sepiaRed = (.393 * red) + (.769 * green) + (.189 * blue);
            int sepiaGreen = (.349 * red) + (.686 * green) + (.168 * blue);
            int sepiaBlue = (.272 * red) + (.534 * green) + (.131 * blue);

            if (sepiaRed > 255) {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255) {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255) {
                sepiaGreen = 255;
            }

            image[h][w].rgbtBlue = sepiaBlue;
            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    So in a 100x100 image, essentially:
    image[10][10] = image[10][90]
    height will be the same, but the width location is max width - current width => set to that index
    So essentially we're taking the width argument, subtracting w from it, and then assigning that
    otherwise, every pixel is the same
    */

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width / 2; w++) {

            //essentially: the new width index is max width - the current iteration loop number
            RGBTRIPLE temp = image[h][w]; //declare essentially copy of existing image struct
            image[h][w] = image[h][width-w]; //assign the image already there the modified [h][i] indexes
            image[h][width-w] = temp; //then assign that to the temp struct to use that instead
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{


    //make a copy of the image to work with, otherwise you're writing onto the original when doing this in subsequent passes
    RGBTRIPLE temp[height][width];

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {

            int red_total = 0;
            int blue_total = 0;
            int green_total = 0;
            int counter = 0;

            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <=1; y++) {

                    //check to make sure new x and y doesn't fall outside of the grid of indices
                    if (h+x < 0 || h+x > height-1 || w+y < 0 || w+y > width-1) {
                        continue;
                    }
                    blue_total += image[h+x][w+y].rgbtBlue;
                    red_total += image[h+x][w+y].rgbtRed;
                    green_total += image[h+x][w+y].rgbtGreen;

                    counter++;

                    temp[h][w].rgbtBlue = (blue_total / counter);
                    temp[h][w].rgbtRed = (red_total / counter);
                    temp[h][w].rgbtGreen = (green_total / counter);

                }
            }
        }
    }

    //copy temp onto original image
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            image[h][w].rgbtRed = temp[h][w].rgbtRed;
            image[h][w].rgbtBlue = temp[h][w].rgbtBlue;
            image[h][w].rgbtGreen = temp[h][w].rgbtGreen;
        }
    }

}
