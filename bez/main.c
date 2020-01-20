#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fr;

    typedef struct dvojica
    {
        char sjl[20];
        char anj[20];
    }dvojica;

    dvojica dvoj;
    char zadane[20];
    int spolu = 0, dobre = 0;
    float uspesnost;

    if ((fr = fopen("slovicka.txt","r"))== NULL)
        printf("Subor slovicka.txt sa nepodarilo otvorit, resp. neexistuje.\n");
    else
    {
        printf("\tSKUSANIE SLOVICOK Z ANGLICTINY!\n\n");    //\t - sposobi odsunutie o niekolko znakov, \b - nefunguje
        do
        {
            fscanf(fr, "%s\n", dvoj.sjl);
            fscanf(fr, "%s\n", dvoj.anj);
            printf("Napis po slovensky: %s\n", dvoj.anj);
            scanf("%s", zadane);
            if (strcmp(zadane, dvoj.sjl) == 0) {
                dobre++;
                printf("[+] Tyyy vyborne!\n");
            } else {
                printf("[-] Veru nie, ani nie, malo to byt: %s\n", dvoj.sjl);
            }
            spolu++;
        }while(!feof(fr));
    }

    uspesnost = (((float)dobre / spolu) * 100);
    printf("\nTvoja uspesnost je %.2f percent.\n", uspesnost);

    return 0;
}
