#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIETY "diety.txt"
#define KURZY "kurzy.txt"

#define BREAKFAST 0.25
#define LUNCH 0.4
#define DINNER 0.35

typedef struct STAY {
    int hours;
    char country[50];
    double reduction;
} STAY;

STAY stays[3];

int main()
{
    FILE *diety, *kurzy;

    diety = fopen(DIETY, "r");
    kurzy = fopen(KURZY, "r");

    if(diety==NULL) {
        printf("Nemozno otvorit subor %s!", DIETY);
        return -1;
    }
    if(kurzy==NULL) {
        printf("Nemozno otvorit subor %s!", KURZY);
        return -2;
    }

    int length = 0;
    printf("Kolko krajin zamestnanec navstivil? (max. 3): ");
    scanf("%i", &length);

    int i;
    for(i=0;i<length;i++) {
        printf("Zadaj nazov krajiny: ");
        scanf("%s", stays[i].country);

        printf("Zadaj pocet hodin stravenych v krajine: ");
        scanf("%i",&(stays[i].hours));

        printf("Zadaj zaplatene jedla oddelene medzerou (obed vecera ranajky): \n");
        char str[128];
        gets(str);

        stays[i].reduction = 0;

        char *p;
        p = strtok(str, " ");
        do {
            printf("%s\n", p);
            p = strtok(NULL, " ");
            if(p!=NULL) {
                if(strcmp(p,"obed")) {
                    stays[i].reduction += LUNCH;
                }
                if(strcmp(p,"vecera")) {
                    stays[i].reduction += DINNER;
                }
                if(strcmp(p,"ranajky")) {
                    stays[i].reduction += BREAKFAST;
                }
            }
        } while(p);

        printf("Krajina: %s\n", stays[i].country);
        printf("Duration: %i\n", stays[i].hours);
        printf("Reduction: %f\n", stays[i].reduction);
    }

    printf("Hello world!\n");
    return 0;
}
