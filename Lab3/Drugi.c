#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char izbor, s[100], novi[100], uzmi, ime[100];
    int pomjeraj=3, parametri, length;
    FILE *dat, *duzine, *duzine2;
    do {
        printf("Unesite u za unos, p za prikaz: ");
        scanf("%c",&izbor);
    } while(izbor!='u' && izbor!='p');
    if(izbor=='u') {
        if((dat=fopen(argv[1],"ab")) !=NULL ) {
            printf("Unesite string za sifrovanje: ");
            scanf("%s",s);
            int duzina = strlen(s);
            for(int j=0; j<duzina; j++) {
                if((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')) {
                    if(s[j]=='x') novi[j]='a';
                    else if(s[j]=='y') novi[j]='b';
                    else if(s[j]=='z') novi[j]='c';
                    else if(s[j]=='X') novi[j]='A';
                    else if(s[j]=='Y') novi[j]='B';
                    else if(s[j]=='Z') novi[j]='C';
                    else novi[j]=s[j]+pomjeraj;
                }
                else {
                    novi[j] = s[j];
                }
                /*printf("%c",novi[j]);*/
                fputc(novi[j],dat);
            }
            if((duzine=fopen("duzine.txt","a")) !=NULL && (!strcmp(argv[1],"#.dat"))) {
                fprintf(duzine, "%d\n",duzina);
            }
            else if((duzine2=fopen("duzine2.txt","a")) !=NULL) {
                fprintf(duzine2, "%d\n", duzina);
            }
            else printf("Neuspjesno upisivanje u duzine.txt");
            fclose(dat);
        }
        else return printf("Neuspjesno upisivanje u .dat"), -1;
    }
    else {
        if(strcmp("#.dat",argv[1])==0) {
            if((dat=fopen(argv[1],"rb")) !=NULL ) {
                if((duzine=fopen("duzine.txt","r")) !=NULL ) {
                    parametri = fscanf(duzine, "%d\n", &length);
                    do {
                        if(parametri==1) {
                            for(int i=0; i<length; i++) {
                                uzmi = fgetc(dat);
                                printf("%c",uzmi);
                            }
                        }
                        printf("\n");
                        parametri = fscanf(duzine, "%d\n", &length);
                    } while(parametri==1);
                }
                else printf("Neuspjesno iscitavanje iz duzine.txt");
            }
            else return printf("Neuspjesno iscitavanje iz #.dat"), -1;
        }
        else {
            printf("Unesite ime binarne datoteke: ");
            scanf("%s",ime);
            if((dat=fopen(ime,"rb")) !=NULL ) {
                if((duzine2=fopen("duzine2.txt","r")) !=NULL ) {
                    parametri = fscanf(duzine2, "%d\n", &length);
                    do {
                        if(parametri==1) {
                            for(int i=0; i<length; i++) {
                                uzmi = fgetc(dat);
                                printf("%c",uzmi);
                            }
                        }
                        printf("\n");
                        parametri = fscanf(duzine2, "%d\n", &length);
                    } while(parametri==1);
                }
                else printf("Neuspjesno iscitavanje iz duzine2.txt");
            }
            else return printf("Neuspjesno iscitavanje iz .dat"), -1;
        }
    }
    return 0;
}
