#include <stdio.h>
#include "../include/complex.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

complex* create_complex(double a, double b){
    complex* z = (complex*) calloc(1,sizeof(complex));
    if (z == NULL) {
        perror("Erreur mémoire non allouée pour create_complex! \n");
        exit(1);
    }
    z->re = a;
    z->im = b;
    return z;
}

void delete_complex(complex* z){
    free(z);
}

void print_complex(complex* z){

    if(z == NULL) {
        printf("Le nombre complexe n'existe pas \n");
        return;
    }
    
    if(z->re== 0 && z->im == 0) printf("%lf \n", z->re);    //Si Re et Im sont nuls

    else if (z->re == 0) printf("%lfi \n", z->im);          // Si Re est nul

    else{
        if(z->im > 0) printf("%lf + %lfi \n", z->re, fabs(z->im));      //Si Im positif

        if(z->im == 0) printf("%lf \n", z->re);                         //Nul

        if(z->im < 0) printf("%lf - %lfi \n", z->re, fabs(z->im));      //Négatif
    }
}

complex* add_complex(complex* z1, complex* z2){ 
    complex* c = create_complex(z1->re+z2->re,z1->im+z2->im);
    return c;
}

complex* minus_complex(complex* z1, complex* z2){
    complex* c = create_complex(z1->re - z2->re, z1->im - z2->im);
    return c;
}

complex* mult_complex(complex* z1, complex* z2){
    double re = z1->re*z2->re - z1->im*z2->im;
    double im = z1->re*z2->im + z1->im*z2->re;
    complex* c = create_complex(re,im);
    return c;
}

// complex* conjugate_complex(complex*z1){
//     complex* c = create_complex(z1->re, (-1)*z1->im);
//     return c;
// }

complex* divide_complex(complex* z1, complex* z2){

    if(z2->re+z2->im == 0) {
        printf("On ne peut pas diviser par 0 \n");
        return NULL;
    }
    double norm2 = pow(z2->re,2) + pow(z2->im,2);
    double re = (z1->re*z2->re + z1->im*z2->im)/norm2;
    double im = (z1->im*z2->re - z1->re*z2->im)/norm2;

    complex* c = create_complex(re,im);
    return c;
}

double norme_complex(complex* z){
    return sqrt( pow(z->re,2) + pow(z->im,2) );
}

