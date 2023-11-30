#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/


#ifndef COMPLEX
#define COMPLEX


typedef struct _complex {
    double re;
    double im;
}complex;


complex* create_complex(double a, double b);
void delete_complex(complex* z);
void print_complex(complex* z);

complex* add_complex(complex* z1, complex* z2);
complex* minus_complex(complex* z1, complex* z2);
complex* mult_complex(complex* z1, complex* z2);
// complex* conjugate_complex(complex*z1);
complex* divide_complex(complex* z1, complex* z2);
double norme_complex(complex* z);






#endif // COMPLEX