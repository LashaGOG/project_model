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

void print_complex(complex z)
{
    if ( (z.re == 0) && (z.im == 0) )
        printf("%lf \n", z.re);         //If Re and Im are zeros
    
    else if (z.im == 0){
        printf("%lf \n", z.re);
    }

    else if (z.re == 0){
        printf("%lf * i \n", z.im); 
    }

    else
    {
        if (z.im > 0)
            printf("%lf + %lf * i \n", z.re, fabs(z.im));   //If Im is positive

        if (z.im == 0)
            printf("%lf \n", z.re);                         //Zero

        if (z.im < 0)
            printf("%lf - %lf * i \n", z.re, fabs(z.im));   //Negative
    }
}

complex add_complex(complex z1, complex z2)
{
    /*Returns the addition of two complex numbers */

    complex sum;
    sum.re = z1.re + z2.re;
    sum.im = z1.im + z2.im;

    return sum;
}

complex subtract_complex(complex z1, complex z2)
{
    /*Returns the subtraction between two complex numbers*/

    complex sub = create_complex(z1.re - z2.re, z1.im - z2.im);
    return sub;
}

complex multiply_complex(complex z1, complex z2)
{
    /*Returns the multiplication of two complex numbers*/

    double re = z1.re * z2.re - z1.im * z2.im;
    double im = z1.re * z2.im + z1.im * z2.re;
    complex z = create_complex(re, im);
    return z;
}

complex conjugate_complex(complex z1){
    /*Returns the complex conjugate of a complex number*/

    return create_complex(z1.re, (-1)*z1.im);
}

complex divide_complex(complex z1, complex z2)
{
    /*Returns the division between two complex numbers*/

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
    /*Returns the norm of a complex number*/

    return sqrt(pow(z.re, 2) + pow(z.im, 2));
}

complex exp_complex(double theta)
{
    /*Transforms an exponential form complex number in trigonometric form*/
    
    return create_complex(cos(theta), sin(theta));
}
