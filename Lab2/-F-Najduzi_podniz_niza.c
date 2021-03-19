//2. Napisati funkciju koja u nizu cijelih brojeva određuje najdužu seriju elemenata koji zadovoljavaju dato
//svojstvo. Prototip funkcije je:
//void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina);
//Napisati program u kojem se učitava dinamički niz od n cijelih brojeva, nakon toga poziva funkcija za
//taj niz, a zatim se ispisuje najduža serija parnih, kao i najduža serija pozitivnih elemenata niza (ispis
//vršiti u glavnom programu poslije poziva funkcije).

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int par(int n)
{
    return (n%2)? 0 : 1;
}

int poz(int n)
{
    return (n>=0)? 1 : 0;
}

void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina)
{
    int i, max = 1;
    int *kraj, *poc;

    for(i = 0; i < n; i++)
        if( (*s)(*(*pocetak + i)) )                     // if - paran
        {
            poc = *pocetak + i;                         // poc pokazuje na u_niz[i]
            for(int j = i; j < n; j++)
            {
                if( (*s)(*(*pocetak + j)) ) kraj = *pocetak + j;
                else
                    break;
            }
            if( (kraj - poc + 1) > max)                 //razlika pokazivaca
                {
                    max = (kraj - poc) + 1;

                    for(int k = i, c = 0; k < i + max; k++, c++)
                        *(niz+c) = *(*pocetak+k);
                }
        }
    *duzina = max;
}

int main()
{
    int ima_paran,ima_pozitivan;
    int n, niz[50]={0};                         // u nizu su elementi koji se ispisuju
    int duzina = 1;

    do{
        printf("Unijeti n: ");
        scanf("%d",&n);
    }while(n<1);

    int *u_niz = (int *)calloc(n+1,sizeof(int));   // ovdje su svi elementi pocetnog niza

    for(int i=0;i<n;i++)
    {
        scanf("%d",u_niz+i);
        if(*(u_niz+i)%2 == 0) ima_paran = *(u_niz+i);
        if(*(u_niz+i) > 0)    ima_pozitivan = *(u_niz+i);
    }

    int *pocetak = u_niz;

    if(ima_pozitivan)
    {
        serija(niz, n, &poz, &pocetak, &duzina);
        printf("Najduzi niz pozitivnih brojeva je:\n");

        if(duzina == 1) printf("%d",ima_pozitivan);        // ovaj if - else krpi to sto nece da radi za slucaj kad je samo jedan broj poz.
        else
        {
            for(int i = 0; i < duzina; i++)
                printf("%d ",niz[i]);
        }
    }
    else printf("Nema pozitivnih...\n");


    if(ima_paran)
    {
        serija(niz, n, &par, &pocetak, &duzina);
        printf("\nNajduzi niz parnih brojeva je:\n");       // ovaj if - else krpi to sto nece da radi za slucaj kad je samo jedan broj par.

        if(duzina == 1) printf("%d",ima_paran);
        else{
            for(int i = 0; i < duzina; i++)
                printf("%d ",niz[i]);
        }
    }
    else printf("Nema parnih...\n");

    free(u_niz);
    return 0;
}
