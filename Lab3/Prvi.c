#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char prezime[20];
    char ime[20];
    char broj[20];
} OSOBA;

int main(int argc, char *argv[])
{
    FILE *dat;
    char izbor;
    int n=0,br=0, i, p, c=10;
    OSOBA *niz, o;
    do {
        printf("Unesite u za unos ili p za prikaz: ");
        scanf("%c",&izbor);
    } while(izbor!='u' && izbor!='p');
    if(izbor=='u') {
        if((dat=fopen(argv[1],"ab")) !=NULL ) {
            do {
                printf("Koliko osoba za unos: ");
                scanf("%d",&n);
            } while(n<1);
            niz = (OSOBA *)malloc(n*sizeof(OSOBA));
            for(i=0; i<n; i++) {
                printf("Unesite podatke o %d. osobi: ",i+1);
                printf("Prezime, ime, broj: ");
                scanf("%s %s %s",niz[i].prezime,niz[i].ime,niz[i].broj);
            }
            p = fwrite(niz,sizeof(OSOBA),n,dat);
            free(niz); niz=NULL;
            fclose(dat);
        }
        else {
            return printf("Neuspjesno dodavanje u binarnu datoteku"), -1;
        }
    }
    else {
        if(strcmp(argv[1],"#.dat")==0) {
            niz = (OSOBA *)malloc(c*sizeof(OSOBA));
        if((dat=fopen(argv[1],"rb")) !=NULL ) {
            do {
                p = fread(&o, sizeof(OSOBA),1,dat);
                if(p) {
                    if(n==c) niz=(OSOBA *)realloc(niz, (c*=2)*sizeof(OSOBA));
                    niz[n++] = o;
                }
            } while(p);
            for(i=0; i<n; i++) {
                printf("%s %s %s\n",niz[i].prezime, niz[i].ime, niz[i].broj);
            }
            fclose(dat);
        }
        else {
            return printf("Neuspjesno iscitavanje iz #.txt"), -1;
        }
    }
    else {
        niz = (OSOBA *)malloc(c*sizeof(OSOBA));
        char s[100];
        printf("Unesite naziv datoteke: ");
        scanf("%s",s);
        if((dat=fopen(s,"rb")) !=NULL ) {
            do {
                p = fread(&o, sizeof(OSOBA),1,dat);
                if(p) {
                    if(n==c) niz=(OSOBA *)realloc(niz, (c*=2)*sizeof(OSOBA));
                    niz[n++] = o;
                }
            } while(p);
            for(i=0; i<n; i++) {
                printf("%s %s %s\n",niz[i].prezime, niz[i].ime, niz[i].broj);
            }
            fclose(dat);
        }
        else {
            return printf("Neuspjesno iscitavanje iz .dat"), -1;
        }
        }
    }
    return 0;
}
