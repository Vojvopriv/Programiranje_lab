//3. Napisati funkciju koji vrši konkatenaciju (spajanje) stringova i sabiranje cjelobrojnih podataka koji su
//argumenti komandne linije te nakon toga ispisuje rezultat. Stringovi se navode poslije argumenta
//komandne linije –s a brojevi poslije argumenta komandne linije –b.
//Prototip funkcije je:
//void spoji_saberi(int argc, char *argv[], char* (*dodaj)(char*, char*),
//int (*saberi)(int, int));
//Pri tome prva funkcija dodaje naredni string koji je argument komandne linije na string koji je do tog
//trenutka kreiran i vraća novi string, a druga funkcija na trenutnu sumu dodaje naredni broj koji je
//argument komandne linije i vraća novu sumu. U glavnom programu ilustrovati upotrebu funkcije.
//Uzeti u obzir samo kombinacije koje su navedene u narednim primjerima uz pretpostavku da će
//argumenti biti uneseni pravilno. Primjeri poziva i izvršavanja programa:
//D:\>program.exe -s ab cd ef –b 1 2 3
//String je 'abcdef'. Suma brojeva je 6.
//D:\>program.exe -s ab cd ef
//String je 'abcdef'.
//D:\>program.exe –b 1 2 3
//Suma brojeva je 6.
//D:\>program.exe –b 1 2 3 -s ab cd ef
//Suma brojeva je 6. String je 'abcdef'.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int saberi(int s, int a)
{
    return s+a;
}

char* dodaj(char *s1, char *s2)
{
    int a;

    if(s1) a = strlen(s1);
    else a = 0;

    char *c = (char*)malloc(a + strlen(s2) + 1);

    strcpy(c,s1);
    strcat(c,s2);

    return c;
}

void spoji_saberi(int argc, char *argv[], char* (*dodaj)(char*, char*), int (*saberi)(int, int))
{
    char* rez = 0;
    int zbir =0,i;

    for(i = 1; i < argc; i++)
    {
        if(strcmp(argv[i],"-b") == 0)
        {
            i++;
            do
            {
                if(strcmp(argv[i],"-s") == 0)
                {
                    i--;break;
                }
                zbir = (*saberi)(zbir,atoi(argv[i]));
                i++;
            }while(i<argc);
        }
        else if(strcmp(argv[i],"-s") == 0)
        {
            i++; rez = (char*)calloc(1,1);

            do
            {
                if(strcmp(argv[i],"-b") == 0)
                {
                    i--;break;
                }
                char *ss = (*dodaj)(rez,argv[i]);
                strcpy(rez,ss);
                free(ss);
                i++;
            }while(i<argc);
        }
        else printf("Greska");
    }
    if(zbir) printf("Zbir: %d\n", zbir);
    if(rez) printf("Rezultat: %s\n", rez);

    free(rez);
}

int main(int argc,char *argv[])
{

    spoji_saberi(argc,argv,&dodaj,&saberi);

    return 0;
}
