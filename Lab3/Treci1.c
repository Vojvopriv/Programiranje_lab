#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char sifra[6];
    char naziv[20];
    double cijena;
} ARTIKAL;

int main(int argc, char *argv[])
{
    if(argc<2) {
        return printf("Nedovoljno argumenata!"), -1;
    }
    FILE *dat;
    int i,n;
    ARTIKAL *niz;
    if((dat=fopen(argv[1],"w")) !=NULL ) {
        do {
            printf("n = ");
            scanf("%d",&n);
        } while(n<1);
        niz = (ARTIKAL *)malloc(n*sizeof(ARTIKAL));
        for(i=0; i<n; i++) {
            printf("Unosenje podataka o %d artiklu: \n",i+1);
            printf("Sifra: "); scanf("%s",niz[i].sifra);
            printf("Naziv: "); scanf("%s",niz[i].naziv);
            printf("Cijena: "); scanf("%lf",&niz[i].cijena);
        }
        fprintf(dat, "=== ===== ==================== ======\n");
        fprintf(dat, "RB. SIFRA NAZIV                CIJENA\n");
        fprintf(dat, "=== ===== ==================== ======\n");
        for(i=0; i<n; i++) {
            fprintf(dat, "%2d. %-5s %-20s %6.2lf",i+1, niz[i].sifra,niz[i].naziv, niz[i].cijena);
            fprintf(dat, "\n");
        }
        fprintf(dat, "=== ===== ==================== ======");
        fclose(dat);
        free(niz);
        niz=NULL;
    }
    else {
        return printf("Neuspjesno otvaranja fajla za pisanje!"), -1;
    }
    return 0;
}
