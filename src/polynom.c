#include "../include/polynom.h"

/* AUTHORS : TAN Philippe
             GOGRITCHIANI Lasha
             CHEN Virginie
*/

double* naive_algo(double* p1,double* p2, int len1, int len2){
    int i,j;
    double *p3 =(double*) calloc(len1+len2-1,sizeof(double));

    if (p3 == NULL) {
        perror("Erreur mémoire non allouée pour naive_algo! \n");
        exit(1);
    }

    for (i=0; i<len1 ;i++){
        for(j=0; j<len2 ;j++){
        p3[i + j] += p1[i]*p2[j];
        }
    }
    return p3;
}

void print_polynom(double *p, int len){
    int i;
    printf("Le polynôme est : \n");
    for(i= 0; i< len; i++){
        printf("%.2lf*X^%d ",p[i],i);
    }
    printf("\n");
}

void delete_polynom(double *p){
    free(p);
}

double generate_random_real(double a, double b) {
    //Génère un réel aléatoire entre a et b
    return a + ((double)rand() / RAND_MAX) * (b - a);
}


double* random_polynom(int deg, int a, int b){
    //Renvoie un polynôme de degré deg-1 à coefficients réels aléatoires entre a et b
    double* p = (double*) calloc(deg, sizeof(double));
    int i;

    if (p == NULL) {
            perror("Erreur mémoire non allouée pour random_polynom! \n");
            exit(1);
        }
    
    for(i=0; i<deg ; i++){
        p[i] = generate_random_real(a,b);
    }
    return p;

}
