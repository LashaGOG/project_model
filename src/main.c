#include <stdio.h>
#include "../include/complex.h"
#include "../include/polynom.h"


/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/


int main() 
{
    complex* z1 = create_complex(-2,-2);
    complex* z2 = create_complex(0,0);
    print_complex(z1);
    print_complex(z2);

    int p1[] = {1,-1,0,2};         //2x^3-x+1
    int p2[] = {0,-10,1,0,0,-4};   //-4x^5+x^2-10x
    int len1 = 4;
    int len2 = 6;

    // int p1[] = {0, 1};
    // int p2[] = {2, -4};
    // int len1 = 2;
    // int len2 = 2;
    int len = len1+len2-1;


    // complex* Z = add_complex(z1,z2);
    // complex* Z = minus_complex(z1,z2);
    // complex* Z = mult_complex(z1,z2);
    complex* Z = divide_complex(z1,z2);

    print_complex(Z);
    double norme = norme_complex(z1);
    printf("La norme vaut %lf\n", norme);

    int* p3 = naive_algo(p1,p2,len1,len2);
    print_polynom(p3,len);
    delete_polynom(p3);


    delete_complex(z1);
    delete_complex(z2);
    delete_complex(Z);

    return 0;
}