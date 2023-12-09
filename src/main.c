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
    int n = 3;
    complex **roots = nth_roots(n);
    for (int i = 0; i < n - 1; i++)
    {
        print_complex(roots[i]);
    }
    return 0;
}