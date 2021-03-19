//3. Napisati program koji učitava prirodan broj n te dva vektora dimenzije n, a zatim ispisuje zbir učitanih
//vektora. Računanje zbira dva vektora treba da se vrši u rekurzivnoj funkciji čiji je prototip:
//void saberi(double *vektor_a, double *vektor_b, double *vektor_rez, int n);

#include<stdio.h>

void saberi(double *vektor_a,double *vektor_b,double *vektor_rez,int n)
{
    if(n) saberi(vektor_a,vektor_b,vektor_rez,n-1);

    vektor_rez[n] = vektor_a[n] + vektor_b[n];
    printf(" %.2lf,",vektor_rez[n]);
}

int main()
{
    int n;
    double vektor_a[20]={0};
    double vektor_b[20]={0};
    double vektor_c[20]={0};

    do{
        printf("Unijeti prirodan broj n: ");
        scanf("%d",&n);
    }while(n<1);

    printf("Prvi vektor: ");
    for(int i=0;i<n;i++)
        scanf("%lf",&vektor_a[i]);

    printf("Drugi vektor: ");
    for(int i=0;i<n;i++)
        scanf("%lf",&vektor_b[i]);

    printf("\nRezultantni vektor je: \n");

    printf("(");
    saberi(vektor_a, vektor_b, vektor_c, n-1);
    printf("\b )\n");

    return 0;
}
