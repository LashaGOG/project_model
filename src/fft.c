#include <stdio.h>
#include "../include/fft.h"
#include "../include/polynom.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

double *fft(double *p, int n)
{
    /* Returns fft of polynom p which is represented with coefficients */
    if (n == 1) // base case length == 1
    {
        return p;
    }
    complex *omega = create_complex(cos(2 * PI / n), sin(2 * PI / n));
    int *pe = get_pe(p, n);
    int *po = get_po(p, n);
    double *ye = fft(pe, n / 2);
    double *yo = fft(po, n / 2);
    double *y = calloc(n, sizeof(double));

    for (int j = 0; j < n / 2; j++)
    {
        y[j] = ye[j] + pow_complex(omega, j) * yo[j]; // pow_complex needs to be defined
        y[j + n / 2] = ye[j] - pow_complex(omega, j) * yo[j];
    }
    free(omega);
    free(pe);
    free(po);
    return y;
}