// Assignment 1 Mandelbrot
//
// Completed by
// Yingzhi Zhou (z5125679)
//  ... (z0000000)
//
// 1st Modified on 2017-09-10 complete function escapeSteps
// 2ed Modifired on 2017-09-11 complete function escapeGrid
// 3rd Modified on 2017-09-11 complete function drawMandelbrot
// 4th Modified on 2017-09-12 find something bud in function escapeGrid

// Stphen Leung (F09B)

// Add your own #includes here
#include <math.h>

#include "mandelbrot.h"
#include "pixelColor.h"


// Add your own #defines here

// Add your own function prototypes here
complex complexAdd(complex a, complex b);
complex complexSquare(complex a);
double complexAbs(complex a);


// Draw a single Mandelbrot tile, by calculating and colouring each of
// the pixels in the tile.
//
// Your function "returns" this tile by filling in the `pixels` 2D array
// that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the image.
// Each pixel is 2^(-z) apart from each other.
void drawMandelbrot(pixel pixels[TILE_SIZE][TILE_SIZE],
        complex center, int z) {
    // hint: use this array to store the result from escapeGrid.
    int grid[TILE_SIZE][TILE_SIZE];
    escapeGrid(grid, center, z);

    int y = 0;
    while (y < TILE_SIZE) {
        int x = 0;
        while (x < TILE_SIZE) {
            pixels[y][x] = pixelColor[grid[y][x]];
            x++;
        }
        y++;
    }
}

// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps(complex c) {
    int steps = 0;
    complex z;
    z.re = 0;
    z.im = 0;
    //until you have performed 256 iterations
    while (complexAbs(z) < 2 && steps < MAX_STEPS) {
        z = complexAdd(complexSquare(z), c);
        steps++;
    }

    if (steps == MAX_STEPS) {
        steps = NO_ESCAPE;
    }

    return steps;
}

// Fill a grid of TILE_SIZE by TILE_SIZE pixels, with the number of
// steps each pixel took to escape the Mandelbrot set.
// something wrong
void escapeGrid(int grid[TILE_SIZE][TILE_SIZE], complex center, int z) {
    int y = 0;
     while (y < TILE_SIZE) {
         int x = 0;
         while (x < TILE_SIZE) {
             complex value;
             //if treat complex center as origin (0, 0), the (x, y) of the centre is (TILE_SIZE/2, TILE_SIZE/2)
             //And the actual coordinate of each pixels was the x, y corrdinate times 2^-z separately
             //which means pixel length is 1*2^-z;
             //z was the zoom size;
             value.re = (x - TILE_SIZE / 2) * pow(2, -z) + center.re;
             value.im = (y - TILE_SIZE / 2) * pow(2, -z) + center.im;
             grid[y][x] = escapeSteps(value);
             x++;
         }
         y++;
     }
    // TODO: COMPLETE THIS FUNCTION
}

// Add your own functions here.
complex complexAdd(complex a, complex b) {
    complex value;
    value.re = a.re + b.re;
    value.im = a.im + b.im;
    return value;
}

complex complexSquare(complex a) {
    complex value;
    value.re = a.re * a.re - a.im * a.im;
    value.im = 2 * a.re * a.im;
    return value;
}

double complexAbs(complex a) {
    double absolute;
    absolute = sqrt(a.re * a.re + a.im * a.im);
    return absolute;

}
// Remember to make them static.
