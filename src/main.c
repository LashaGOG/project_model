#include <stdio.h>
#include "../include/complex.h"
#include "../include/polynom.h"
#include "../include/fft.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

int main()
{
    complex z1 = create_complex(1.0, 2.0);
    complex z2 = create_complex(3.0, 4.0);

    complex sum = add_complex(z1, z2);
    complex sub = subtract_complex(z1, z2);
    complex mul = multiply_complex(z1, z2);
    complex div = divide_complex(z1, z2);
    double norme_z2 = norm_complex(z2);

    print_complex(sum);
    print_complex(sub);
    print_complex(mul);
    print_complex(div);
    printf("%lf\n", norme_z2);


    // complex P[] = {create_complex(5,0) , create_complex(3,0) , create_complex(2,0) , create_complex(1,0) };
    // complex p[] = {create_complex(1,0), create_complex(2,0), create_complex(4,0), create_complex(8,0), 
    // create_complex(16,0), create_complex(32,0)};

    int n = 6;
    
    complex * p = malloc(sizeof(complex[n]));
    for(int l = 0;l<n;l++){
        p[l] = create_complex(pow(2,l),0);
    }

    p = fft(p,n);
    int k = closest_power_of_two(n);
    print_fft(p,k);
    free(p);


    return 0;
}