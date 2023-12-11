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
    // complex z1 = create_complex(1.0, 2.0);
    // complex z2 = create_complex(3.0, 4.0);

    // complex sum = add_complex(z1, z2);
    // complex sub = subtract_complex(z1, z2);
    // complex mul = multiply_complex(z1, z2);
    // complex div = divide_complex(z1, z2);
    // double norme_z2 = norm_complex(z2);

    // print_complex(sum);
    // print_complex(sub);
    // print_complex(mul);
    // print_complex(div);
    // printf("%lf\n", norme_z2);

    // complex P[] = {create_complex(5,0) , create_complex(3,0) , create_complex(2,0) , create_complex(1,0) };
    // complex p[] = {create_complex(1,0), create_complex(2,0), create_complex(4,0), create_complex(8,0),
    // create_complex(16,0), create_complex(32,0)};

    int n = 6;

    int *p1 = malloc(sizeof(int[n]));
    for (int l = 0; l < n; l++)
    {
        p1[l] = pow(2, l);
    }

    int *p2 = malloc(sizeof(int[n]));
    for (int l = 0; l < n; l++)
    {
        p2[l] = pow(3, l);
    }

    printf("p1 = ");
    print_polynom(p1, n);

    printf("p2 = ");
    print_polynom(p2, n);

    int *multiply_naive = naive_algo(p1, p2, n, n);
    printf("p1*p2 = ");
    print_polynom(multiply_naive, 2 * n - 1);

    complex *multiply_fft = multiply_poly_fft(p1, p2, n, n);
    for (int i = 0; i < n + n - 1; i++)
    {
        print_complex(multiply_fft[i]);
    }

    free(p1);
    free(p2);

    return 0;
}