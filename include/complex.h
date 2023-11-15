#include <stdio.h>
#include <stdlib.h>

#ifndef COMPLEX
#define COMPLEX

typedef struct _complex {
    double re;
    double im;
}complex;

complex create_complex(double a, double b);
void delete_complex(complex z);
void print_complex(complex z);






#endif // COMPLEX