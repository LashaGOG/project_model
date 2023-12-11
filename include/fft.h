#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/complex.h"
#define PI 3.14159265358979323846264338327950288

#ifndef FFT
#define FFT

void fft_rec(complex * p, int n);
void print_fft(complex* tab_fft, int n);

int closest_power_of_two(int n);
complex* fft(complex * p, int n);

// void ifft_rec(complex * p, int n);
// void ifft(complex * p, int n);



#endif // FFT