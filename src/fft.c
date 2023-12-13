#include <stdio.h>
#include "../include/fft.h"
#include "../include/polynom.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

/******************** FFT ********************/

void fft_rec(complex *p, int n)
{
    /*Give the FFT of a polynom of size equal to a power of 2*/

    if (n <= 1)
        return; // Coefficients of degree 0, return the FFT

    complex pe[n / 2]; // Split the polynom in two parts, even and odd
    complex po[n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        pe[i] = p[2 * i]; // Bringing the even and odd coefficients in the array associated
        po[i] = p[2 * i + 1];
    }
    fft_rec(pe, n / 2); // Applying recursively the fft on each polynom
    fft_rec(po, n / 2);

    for (int k = 0; k < n / 2; k++)
    {
        complex t = multiply_complex(exp_complex(2 * PI * k / n), po[k]);
        p[k] = add_complex(pe[k], t);
        p[k + n / 2] = subtract_complex(pe[k], t);
    }
}

complex *fft(complex *p, int n)
{
    /* Give the FFT of a polynom whatever his size */

    if ((n & (n - 1)) == 0)
    { // Condition if the polynom has a size equal to a power of 2
        fft_rec(p, n);
    }
    else
    {
        int k = closest_power_of_two(n);                     // Determines the closest power of 2 greater or equal
        complex *p_resized = realloc(p, sizeof(complex[k])); // Enlarge the array
        if (p_resized == NULL)
        { // Check if the memory is allocated
            printf("Échec de l'allocation\n");
            exit(1);
        }

        p = p_resized;
        for (int i = n; i < k; i++)
        { // Add 0 so the array is a size of a power of 2
            p[i] = create_complex(0, 0);
        }
        fft_rec(p, k); // Call the FFT on the new array
    }
    return p;
}

/******************** INVERSE FFT ********************/

void ifft_rec(complex *p, int n)
{
    if (n <= 1)
        return;

    complex pe[n / 2];
    complex po[n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        pe[i] = p[2 * i];
        po[i] = p[2 * i + 1];
    }
    ifft_rec(pe, n / 2);
    ifft_rec(po, n / 2);

    for (int k = 0; k < n / 2; k++)
    {
        // The only change is here: the minus sign in the exponent
        complex t = multiply_complex(exp_complex(-2 * PI * k / n), po[k]);
        p[k] = add_complex(pe[k], t);
        p[k + n / 2] = subtract_complex(pe[k], t);
    }
}

complex *ifft(complex *p, int n)
{
    if ((n & (n - 1)) == 0)
    {
        printf("n = %d\n", n);
        ifft_rec(p, n);

        for (int i = 0; i < n; i++)
        {
            p[i] = divide_complex(p[i], create_complex(n, 0));
        }
    }
    else
    {
        int k = closest_power_of_two(n);
        ifft_rec(p, k);
        complex *p_resized = realloc(p, sizeof(complex) * k);
        if (p_resized == NULL)
        {
            printf("Allocation failure\n");
            exit(1);
        }

        p = p_resized;
        for (int i = n; i < k; i++)
        {
            p[i] = create_complex(0, 0);
        }
        ifft_rec(p, k);
        // printf("error\n");
        // exit(1);

        // int k = closest_power_of_two(n);
        // printf("n = %d\n", n);
        // printf("k = %d\n", k);
        // ifft_rec(p, k);

        // Scale the IFFT by the size
        for (int i = 0; i < k; i++)
        {
            p[i] = divide_complex(p[i], create_complex(k, 0));
        }
    }

    return p;
}

/******************** FFT BASED MULTIPLICATION ********************/

int *multiply_poly_fft(int *p1, int *p2, int n1, int n2)
{
    int n = closest_power_of_two(n1 + n2 - 1);
    // prepare polynoms for fft
    complex *x = calloc(n, sizeof(complex));
    complex *y = calloc(n, sizeof(complex));

    for (int i = 0; i < 0; i++)
    {
        x[i] = create_complex(0, 0);
        y[i] = create_complex(0, 0);
    }

    for (int i = 0; i < n1; i++)
    {
        x[i] = create_complex(p1[i], 0);
    }
    for (int i = 0; i < n2; i++)
    {
        y[i] = create_complex(p2[i], 0);
    }

    // compute fft for each polynom with n > deg1 + deg2
    complex *fft_p1 = fft(x, n);
    complex *fft_p2 = fft(y, n);

    complex *result = calloc(n, sizeof(complex));

    for (int i = 0; i < n; i++)
    {
        result[i] = multiply_complex(fft_p1[i], fft_p2[i]);
    }

    complex *complex_result = ifft(result, n);

    /* transform result to array of integers */
    int *final_result = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        final_result[i] = round(complex_result[i].re);

    free(result);
    free(fft_p1);
    free(fft_p2);
    // free(x);
    // free(y);

    return final_result;
}

/******************** UTILITY FUNCTIONS ********************/

void print_fft(complex *tab_fft, int n)
{
    /*Display the FFT with one coefficients on each line*/

    printf("Début de la FFT \n ");
    for (int i = 0; i < n; i++)
    {
        print_complex(tab_fft[i]);
    }
    printf("Fin de la FFT \n");
}

int closest_power_of_two(int n)
{
    /*Give the closest power of 2 greater or equal to n*/

    if (n <= 1)
        return 1;

    n--; // Décrémenter n pour le cas où n est déjà une puissance de 2

    // Effectuer des opérations OR sur les bits pour combler tous les bits à droite
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return n + 1; // Incrémenter n pour obtenir la prochaine puissance de 2
}