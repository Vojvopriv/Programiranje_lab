#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc<2) return printf("Nedovoljno argumenata"), -1;
    FILE *dat;
    int i,j,n=0,*niz, p,br,c=10;
    char s[15];
    if((dat=fopen(argv[1],"wb")) != NULL) {
        do {
            printf("n=");
            scanf("%d",&n);
        } while(n<1);
        niz = (int *)malloc(n*sizeof(int));
        for(i=0; i<n; i++) {
            printf("Unesite %d. clan niza: ",i+1);
            scanf("%d",&niz[i]);
        }
        for(i=0; i<n-1; i++) {
            for(j=i+1; j<n; j++) {
                if(niz[i]<niz[j]) {
                    int temp = niz[i];
                    niz[i] = niz[j];
                    niz[j] = temp;
                }
            }
        }
        p = fwrite(niz, sizeof(int),n,dat);
        free(niz); niz=NULL; n=0;
        fclose(dat);
    }
    else {
        return printf("Neuspjesno upisivanje u datoteku"), -1;
    }
    niz = (int *)malloc(c*sizeof(int));
    if(strcmp("#.dat",argv[1])==0) {
        if((dat=fopen(argv[1],"rb")) != NULL) {
            do {
                p = fread(&br, sizeof(int), 1, dat);
                if(p) {
                    if(n==c) niz = (int *)realloc(niz, (c*=2)*sizeof(int));
                    niz[n++] = br;
                }
            } while(p);
            for(i=0; i<n; i++) {
                printf(" %d",niz[i]);
            }
        }
    }
    else {
        printf("s="); scanf("%s",s);
        if((dat=fopen(s,"rb")) != NULL) {
            do {
                p = fread(&br, sizeof(int), 1, dat);
                if(p) {
                    if(n==c) niz = (int *)realloc(niz, (c*=2)*sizeof(int));
                    niz[n++] = br;
                }
            } while(p);
            for(i=0; i<n; i++) {
                printf(" %d",niz[i]);
            }
        }
        else {
            return printf("Nije dobar string s!"), -1;
        }
    }
    return 0;
}
