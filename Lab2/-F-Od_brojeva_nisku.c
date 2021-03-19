//1. Napisati funkciju sa promjenljivim brojem argumenata koja cjelobrojne podatke konvertuje i spaja u
//jedan dinamički string. Prototip funkcije je:
//char* formiraj(int n, ...);
//Napisati program kojim se ilustruje rad sa datom funkcijom. Dozvoljena je upotreba funkcija iz
//string.h.
//Primjer:
//formiraj(3, 123, 456, 789);
// Funkcija kao rezultat vraća string čija je vrijednost "123456789".

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>


char *formiraj(int n, ...)
{
    char *s = (char*)calloc(50,sizeof(char));
    char c[10];

    va_list var;
    va_start(var,n);

    for(int i=0;i<n;i++)
    {
        strcat(s,itoa(va_arg(var,int), c, 10));
    }

    return s;
}

int main()
{
    char *s;

    s = formiraj(3, 123, 456, 789);
    printf("\n%s\n",s);
    free(s);

    s =  formiraj(3, 6, 6, 6);
    printf("\n%s\n",s);
    free(s);

    s = formiraj(5, 4, 4, 8, 1, 10);
    printf("\n%s\n", s);
    free(s);

    return 0;
}
