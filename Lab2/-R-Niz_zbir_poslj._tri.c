//4. Napisati program koji učitava prirodan broj n, a zatim ispisuje n-ti član (fn) sljedećeg niza:
//f1 = 1, f2 = 2, f3 = 3 fk = fk-1 + fk-2 + fk-3, k ≥ 4.
//n-ti član datog niza treba da se računa u rekurzivnoj funkciji čiji je prototip:
//int clan(int n);

#include<stdio.h>

int x[100]={0,1,2,3};

int clan(int n)
{
    if(x[n] == 0)
        return x[n]=clan(n-1)+clan(n-2)+clan(n-3);
    else
        return x[n];
}

int main()
{
    int n;
    do{
        printf("Unijeti prirodan broj n: ");
        scanf("%d",&n);
    }while(n<1);


    printf("%d. clan niza je %d\n",n,clan(n));

    return 0;
}
