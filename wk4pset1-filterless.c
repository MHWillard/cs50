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
    int total = 0;
    //int h = height;
    //int w = width;
    //printf("H:%i ", h);
    //printf("W:%i ", w);


    //RBGTRIPLE temp[h][w];

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < height; w++) {

            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <=1; y++) {

                        //check to make sure new x and y doesn't fall outside of the grid of indices
                        //currently only checks for that and not for corner stuff
                        if (h+x >= 0 && w+y >= 0 ) {
                        int blue = image[h+x][w+y].rgbtBlue;
                        int red = image[h+x][w+y].rgbtRed;
                        int green = image[h+x][w+y].rgbtGreen;

                        int average = (blue + red + green) / 3;
                        total += average;

                        //printf("B:%i ", blue);
                        //printf("G:%i ", green);
                        //printf("R%i\n", red);
                        }

                }
            }

        int final_avg = (total / 9);
        //printf("final: %i", final_avg);

        image[h][w].rgbtBlue = final_avg;
        image[h][w].rgbtRed = final_avg;
        image[h][w].rgbtGreen = final_avg;

        }
    }

    //int final_avg = (total / 9);
    //printf("final: %i", final_avg);

    //temp[h][w].rgbtBlue = final_avg;
    //temp[h][w].rgbtRed = final_avg;
    //temp[h][w].rgbtGreen = final_avg;


    //so for here I think I want to use image[h][w] as a starting point to get the values of the surrounding images in image[h][w] format
    //for each neighboring pixel: get their RBG values,
    /*
    use compare and copy here

    or iterate:
    get current pixel value [h][w]
    [h+1][w], [h-1][w]
    [h+1][w+1], [h-1][w-1]
    [h][w+1], [h-1][w-1]

    if beyond height and width, don't use it

    -we need a function in here, looks like, where we get the average of a blue/red/green color
    average = (image[h][w].rgbtBlue + image[h][w].rgbtRed + image[h][w].rgbtGreen) / 3

    so what we then need to do is get it programmatically for:
    h-1, h, h+1
    w-1 w w+1

    IE, we then iterate with a little mini-grid

    for image[h][w]:
        set RGBTRIPLE temp
        get value of original h and w

    int total;

    for (int x = h-1; x > h; x++) {
        for (int y = w-1; y > w; y++) {
            int average = (image[h][w].rgbtBlue + image[h][w].rgbtRed + image[h][w].rgbtGreen) / 3
            total += average;
        }
    }

    int final_avg = (total / 9);

    image[h][w].rgbtBlue = final_avg;
    image[h][w].rgbtRed = final_avg;
    image[h][w].rgbtGreen = final_avg;

    */
}