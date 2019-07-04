// Assignment 1 Mandelbrot: Pixel Color
//
// Completed by
// Yingzhi Zhou (z5125679)
//  ... (z0000000)
//
// Modified on 2017-09-11
// Stephen Leung (F09B)
//2ed Modifield 2017-09-13
#include "mandelbrot.h"
#include "pixelColor.h"

#include <math.h>
#include <stdlib.h>

// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
//
// You have artistic licence here, so make your Mandelbrot look amazing.
pixel pixelColor(int steps) {
    pixel color = {
        .red = 0,
        .green = 0,
        .blue = 0
    };

    if (steps == 0){
        color.red = 0;
        color.green = 0;
        color.blue = 0;
    } else {
        // Modular rings.
        color.red = (steps * 3) % MAX_STEPS;
        color.green = (steps * 8) % MAX_STEPS;
        color.blue = (steps * 2) % MAX_STEPS;
    }
    return color;
}

// if (steps < MAX_STEPS) {
//     log_zn = log(complexAbs(zAfterEscape(c/**/))
// }
//
// complex zAfterEscape(complex c) {
//     complex z;
//     z.re = 0;
//     z.im = 0;
//     int steps = 0;
//     //until you have performed 256 iterations
//     while (complexAbs(z) < 2 && steps < MAX_STEPS) {
//         z = complexAdd(complexSquare(z), c);
//         steps++;
//     }
//
//     return z;
// }

//Black: 0， 0， 0
//White: 255, 255, 255
//Dark Blue: 24, 57, 112
//Middle Blue: 33, 87, 147
//Pink：255， 153， 153
//Light pink: 255， 204， 204
//Coral: 255, 127, 80
//salmon: 250, 128, 114
//dark orange: 255, 165, 0
//chocolate: 210, 105, 30
//Orange: 255， 153， 51
