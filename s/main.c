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

    dvojica dvoj[40];
    char zadane[20];
    int spolu = 0, dobre = 0, i = 0;
    float uspesnost;

    if ((fr = fopen("slovicka.txt","r"))== NULL)
        printf("Subor slovicka.txt sa nepodarilo otvorit, resp. neexistuje.\n");
    else
    {
        do
        {
            fscanf(fr, "%s\n", dvoj[i].sjl);
            fscanf(fr, "%s\n", dvoj[i].anj);
            i++;
        }while(!feof(fr));
    }

    spolu = i;

    printf("\tSkusam slovicka z anglictiny!\n");    //\t - funguje, \b - nefunguje

    for (i = 0; i < spolu; i++)
    {
        printf("\nNapis po slovensky: %s\n", dvoj[i].anj);
        scanf("%s", zadane);
        if (strcmp(zadane, dvoj[i].sjl) == 0) dobre++;
    }

    uspesnost = (((float)dobre / spolu) * 100);
    printf("Tvoja uspesnost je %.2f percent.\n", uspesnost);

    return 0;
}
