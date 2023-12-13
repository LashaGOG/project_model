#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/complex.h"
#define PI 3.14159265358979323846264338327950288

#ifndef FFT
#define FFT

void fft_rec(complex *p, int n);
complex *fft(complex *p, int n);

void ifft_rec(complex *p, int n);
complex *ifft(complex *p, int n);

void print_fft(complex *tab_fft, int n);
int closest_power_of_two(int n);

int *multiply_poly_fft(int *p1, int *p2, int n1, int n2);

#endif // FFT