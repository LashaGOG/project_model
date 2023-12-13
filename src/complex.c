#include <stdio.h>
#include "../include/complex.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

complex create_complex(double re, double im)
{
    /* create, initialise and return complex number */
    complex z;
    z.re = re;
    z.im = im;
    return z;
}

// void delete_complex(complex z)
// void delete_complex(complex z)
// {
//     free(z);
// }

void print_complex(complex z)
{
    if ( (z.re == 0) && (z.im == 0) )
        printf("%lf \n", z.re); // Si Re et Im sont nuls
    else if (z.im == 0){
        printf("%lf \n", z.re);
    }

    else if (z.re == 0){
        printf("%lf * i \n", z.im); // Si Re est nul
    }

    else
    {
        if (z.im > 0)
            printf("%lf + %lf * i \n", z.re, fabs(z.im)); // Si Im positif

        if (z.im == 0)
            printf("%lf \n", z.re); // Nul

        if (z.im < 0)
            printf("%lf - %lf * i \n", z.re, fabs(z.im)); // Négatif
    }
}

complex add_complex(complex z1, complex z2)
{
    complex sum;
    sum.re = z1.re + z2.re;
    sum.im = z1.im + z2.im;

    return sum;
}

complex subtract_complex(complex z1, complex z2)
{
    complex sub = create_complex(z1.re - z2.re, z1.im - z2.im);
    return sub;
}

complex multiply_complex(complex z1, complex z2)
{
    double re = z1.re * z2.re - z1.im * z2.im;
    double im = z1.re * z2.im + z1.im * z2.re;
    complex z = create_complex(re, im);
    return z;
}

complex conjugate_complex(complex z1){
    return create_complex(z1.re, (-1)*z1.im);
}

complex divide_complex(complex z1, complex z2)
{

    if ((z2.re == 0) && (z2.im == 0))
    {
        fprintf(stderr, "Division by zero error\n");
        return create_complex(NAN, NAN);
    }
    double norm2 = pow(z2.re, 2) + pow(z2.im, 2);
    double re = (z1.re * z2.re + z1.im * z2.im) / norm2;
    double im = (z1.im * z2.re - z1.re * z2.im) / norm2;

    complex z = create_complex(re, im);
    return z;
}

double norm_complex(complex z)
{
    return sqrt(pow(z.re, 2) + pow(z.im, 2));
}

complex exp_complex(double theta)
{
    return create_complex(cos(theta), sin(theta));
}
