#include <stdio.h>
#include "../include/fft.h"
#include "../include/polynom.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/


void fft_rec(complex * p, int n) {

    if (n <= 1) return;

    complex pe[n/2];
    complex po[n/2];

    for (int i = 0; i < n/2; i++) {
        pe[i] = p[2*i];
        po[i] = p[2*i + 1];
    }
    fft_rec(pe, n/2);
    fft_rec(po, n/2);

    for (int k = 0; k < n/2; k++) {
        complex t = multiply_complex(exp_complex(2 * PI * k / n), po[k]);
        p[k] = add_complex(pe[k], t);
        p[k + n/2] = subtract_complex(pe[k], t);
    }
}

void print_fft(complex* tab_fft, int n){
    printf("Début de la FFT \n ");
    for (int i = 0; i<n; i++){
        print_complex(tab_fft[i]);
    }
    printf("Fin de la FFT \n");
}

int closest_power_of_two(int n) {
    if (n <= 1) return 1;

    // Décrémenter n pour le cas où n est déjà une puissance de 2
    n--;

    // Effectuer des opérations OR sur les bits pour combler tous les bits à droite
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;  // Cette ligne est suffisante pour les entiers 32 bits

    // Incrémenter n pour obtenir la prochaine puissance de 2
    return n + 1;
}

void fft(complex * p, int n){

if ( (n & (n-1)) == 0){
    fft_rec(p,n);
}
else {
    int k = closest_power_of_two(n);
    complex * p_resized = realloc(p, sizeof(complex[k]));
    if (p_resized == NULL){
        printf("Échec de l'allocation\n");
        return exit(1);
    }

    p = p_resized;
    for(int i=n;i<k;i++){
        p[i] = create_complex(0,0);
    }
    fft_rec(p,k);
}
}

// void ifft_rec(complex * p, int n) {

//     if (n <= 1) return;

//     complex pe[n/2];
//     complex po[n/2];

//     for (int i = 0; i < n/2; i++) {
//         pe[i] = p[2*i];
//         po[i] = p[2*i + 1];
//     }
//     ifft_rec(pe, n/2);
//     ifft_rec(po, n/2);

//     for (int k = 0; k < n/2; k++) {
//         complex omega = exp_complex(-2 * PI * k / n);
//         complex t = multiply_complex(divide_complex(omega,create_complex(n,0)) , po[k]);
//         p[k] = add_complex(pe[k], t);
//         p[k + n/2] = subtract_complex(pe[k], t);
//     }
// }

// void ifft(complex * p, int n){

// if ( (n & (n-1)) == 0){
//     ifft_rec(p,n);
// }
// else {
//     int k = closest_power_of_two(n);
//     complex * p_resized = realloc(p, sizeof(complex[k]));
//     if (p_resized == NULL){
//         printf("Échec de l'allocation\n");
//         return exit(1);
//     }

//     for(int i=n;i<k;i++){
//         p_resized[i] = create_complex(0,0);
//     }
//     ifft_rec(p_resized,k);
// }
// }