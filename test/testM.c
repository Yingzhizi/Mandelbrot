

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STEPS 256
#define TILE_SIZE 60
#define NO_ESCAPE -1

typedef struct _complex {
    double re;
    double im;
} complex;

complex complexAdd(complex a, complex b);
complex complexSquare(complex a);
double complexAbs(complex a);
int escapeSteps(complex c);
void escapeGrid(int grid[TILE_SIZE][TILE_SIZE], complex center);

int main (int argc, char *argv[]) {
    complex a;
    a.re = 1.9;
    a.im = 0.9;
    int array[60][60] = {{0}};
    escapeGrid(array, a);
    //escapeGrid(array, a);

    return EXIT_SUCCESS;
}

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

void escapeGrid(int grid[TILE_SIZE][TILE_SIZE], complex center) {
    int y = 0;
     while (y < TILE_SIZE) {
         int x = 0;
         while (x < TILE_SIZE) {
             complex value;
             //if treat complex center as origin (0, 0)
             value.re = x * 0.025 - center.re;
             value.im = y * 0.025 - center.im;
             grid[y][x] = escapeSteps(value);
             printf("%d ", grid[y][x]);
             x++;
         }
         printf("\n");
         y++;
     }
    // TODO: COMPLETE THIS FUNCTION

}

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
