//1. Napisati program koji učitava prirodan broj n te niz od n cijelih brojeva, a zatim ispisuje sumu brojeva
//učitanog niza. Elementi niza treba da se sumiraju u rekurzivnoj funkciji čiji je prototip:
//int suma(int *niz, int n);

#include<stdio.h>

int suma(int *niz,int n)
{
    if(n==1) return niz[0];

    return niz[n-1]+suma(niz,n-1);
}

int main()
{
    int n, niz[100];

    do{
    printf("Unijeti n:");
    scanf("%d",&n);
    }while (n<1);
    for(int i=0;i<n;i++)
        scanf("%d",&niz[i]);

    printf("Suma brojeva ucitanog niza je: %d\n",suma(niz,n));

    return 0;
}
