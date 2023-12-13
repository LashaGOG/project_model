#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

#ifndef COMPLEX
#define COMPLEX

typedef struct
{
    double re;
    double im;
} complex;

complex create_complex(double re, double im);
// void delete_complex(complex* z);
void print_complex(complex z);

complex add_complex(complex z1, complex z2);
complex subtract_complex(complex z1, complex z2);
complex multiply_complex(complex z1, complex z2);
complex conjugate_complex(complex z1);
complex divide_complex(complex z1, complex z2);
double norm_complex(complex z);
complex exp_complex(double theta);



#endif // COMPLEX