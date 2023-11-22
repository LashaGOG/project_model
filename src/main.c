#include "../include/complex.h"
#include <stdio.h>


int main() 
{
    complex* z1 = create_complex(-2,-2);
    complex* z2 = create_complex(0,0);
    print_complex(z1);
    print_complex(z2);

    // complex* Z = add_complex(z1,z2);
    // complex* Z = minus_complex(z1,z2);
    // complex* Z = mult_complex(z1,z2);
    complex* Z = divide_complex(z1,z2);

    print_complex(Z);
    double norme = norme_complex(z1);
    printf("La norme vaut %lf\n", norme);

    delete_complex(z1);
    delete_complex(z2);
    delete_complex(Z);


    return 0;
}