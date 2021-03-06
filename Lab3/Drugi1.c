#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

typedef struct {
    double x,y,r;
} KRUG;

int main(int argc, char *argv[])
{
    if(argc<2) {
        return printf("Nema naziva datoteke"), -1;
    }
    KRUG k, naj;
    FILE *dat;
    double maxp=0.0, p=1.0;
    int br_parametara;
    if((dat=fopen(argv[1],"r")) !=NULL ) {
        br_parametara = fscanf(dat, "(%lf,%lf,%lf)\n",&k.x, &k.y, &k.r);
        while(br_parametara==3) {
            p = k.r * k.r * PI;
            if(p>maxp) {
                maxp=p;
                naj.x = k.x;
                naj.y = k.y;
                naj.r = k.r;
            }
            br_parametara = fscanf(dat, "(%lf,%lf,%lf)\n",&k.x, &k.y, &k.r);
        }
        fclose(dat);
    }
    else {
        return printf("Neuspjesno otvaranje KRUGOVI.TXT"), -1;
    }
    printf("Najvecu povrsinu (P=%6.2lf) ima krug: (%4.2lf, %4.2lf, %4.2lf)",maxp, naj.x, naj.y, naj.r);
    return 0;
}
