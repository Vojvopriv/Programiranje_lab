#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc<3) {
        return printf("Nedovoljno argumenata!"), -1;
    }
    FILE *dat1, *dat2;
    int br=0, k=0, max=0;
    char i,s[100], najveci[100];
    if((dat1=fopen(argv[1],"r")) !=NULL ) {
        if((dat2=fopen(argv[2],"w")) !=NULL ) {
            while((i=fgetc(dat1))!=EOF) {
                if((i>='A' && i<='Z') || (i>='a' && i<='z')) {
                    k=0;
                    fputc(i,dat2);
                }
                else {
                    k++;
                    if(k==1) {
                        fprintf(dat2,"\n");
                    }
                }
            }

            fclose(dat2);
        }
        else {
            return printf("Neuspjesno upisivanje u b.txt"), -1;
        }
        fclose(dat1);
    }
    else {
        return printf("Neuspjesno ocitavanje a.txt"), -1;
    }
    if((dat2=fopen(argv[2],"r")) !=NULL ) {
        while(fgets(s,100,dat2)!=NULL) {
            if(strlen(s)>=max) {

                max = strlen(s);
                for(i=0; i<max; i++) {
                    najveci[i] = s[i];
                }
            }
        }
        fclose(dat2);
    }
    else {
        return printf("Neuspjesno otvaranje datoteke b.txt"), -1;
    }
    printf("Najduza rijec je: %s",najveci);
    return 0;
}
