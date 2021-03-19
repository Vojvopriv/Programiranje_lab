//2. Napisati program koji učitava prirodan broj b, a zatim ispisuje sumu cifara učitanog broja. Računanje
//sume cifara treba da se vrši u rekurzivnoj funkciji čiji je prototip:
//int suma_cifara(int b);

#include<stdio.h>

int suma_cifara(int b)
{
    if(b==0) return 0;

    return b%10 + suma_cifara(b/10);
}

int main()
{
    int b;

    do{
        printf("Unijeti prirodan b: ");
        scanf("%d",&b);
    }while(b<1);

    printf("Suma cifara datog broja je: %d\n",suma_cifara(b));

    return 0;
}
