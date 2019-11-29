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
    float reduction;
} STAY;

typedef struct DIETA {
    char country[50];
    char currency[5];
    float under6;
    float under12;
    float under24;
} DIETA;

typedef struct RATE {
    char currency[5];
    float rate;
} RATE;

char trash[50];

STAY stays[3];
int staysLength = 0;

RATE rates[20];
int ratesLength = 0;
DIETA diets[50];
int dietsLength = 0;

void calculateStays() {
    float total = 0;

    int i;
    int e;
    for(i=0;i<staysLength;i++) {
        STAY stay = stays[i];
        DIETA *diet = NULL;
        RATE *rate = NULL;

        for(e=0;e<dietsLength;e++) {
            //printf("CMP: %s : %s\n", stay.country, diets[e].country);
            if(strcmp(stay.country, diets[e].country)==0) {
                diet = &(diets[e]);
            }
        }

        if(diet==NULL) {
            printf("Krajina %s nenajdena!\n", stay.country);
            continue;
        }

        if(strcmp(diet->currency,"EUR")!=0) {
            for(e=0;e<ratesLength;e++) {
                if(strcmp(diet->currency, rates[e].currency)==0) {
                    rate = &(rates[e]);
                }
            }
            if(rate==NULL) {
                printf("Menovy kurz pre %s nenajdeny!\n", diet->currency);
                continue;
            }
        }

        int days = (int)floor(stay.hours/24.0);
        stay.hours -= days*24;

        float finalPrice = days*(diet->under24);
        finalPrice += stay.hours<6 ? diet->under6 : stay.hours<12 ? diet->under12 : diet->under24;

        finalPrice *= 1-stay.reduction;

        if(rate==NULL) {
            printf(" %s - %.02f EUR\n", stay.country, finalPrice);
            total += finalPrice;
        } else {
            printf(" %s - %.02f %s - %.02f EUR\n", stay.country, finalPrice, rate->currency, finalPrice/(rate->rate));
            total += finalPrice/(rate->rate);
        }
    }

    printf("SPOLU: %.02f\n", total);
}

int loadRates() {
    FILE *kurzy;

    kurzy = fopen(KURZY, "r");

    if(kurzy==NULL) {
        printf("Nemozno otvorit subor %s!", KURZY);
        return -1;
    }
    printf("-> Loading rates...\n");

    int pointer = 0;
    while(!feof(kurzy)) {
        fscanf(kurzy, "%s", rates[pointer].currency);
        printf("Currency: %s\n", rates[pointer].currency);

        fscanf(kurzy, "%f", &(rates[pointer].rate));
        printf("Rate: %f\n", rates[pointer].rate);

        pointer++;
    }
    printf("-> Rates loaded...\n\n\n");

    ratesLength = pointer;

    return 0;
}

int loadDiety() {
    FILE *diety;

    diety = fopen(DIETY, "r");

    if(diety==NULL) {
        printf("Nemozno otvorit subor %s!", DIETY);
        return -1;
    }
    printf("-> Loading diets...\n");

    int pointer = 0;
    while(!feof(diety)) {
        fgets(diets[pointer].country, 50, diety);
        diets[pointer].country[strlen(diets[pointer].country)-1] = '\0';
        printf("Country: %s\n", diets[pointer].country);

        fscanf(diety, "%f", &(diets[pointer].under6));
        printf("Under6: %f\n", diets[pointer].under6);
        fgets(trash, 50, diety);

        fscanf(diety, "%f", &(diets[pointer].under12));
        printf("Under12: %f\n", diets[pointer].under12);
        fgets(trash, 50, diety);

        char curr[10];
        fscanf(diety, "%f", &(diets[pointer].under24));
        printf("Under24: %f\n", diets[pointer].under24);
        fgets(curr, 10, diety);

        memcpy(diets[pointer].currency, &(curr[1]), 3);
        diets[pointer].currency[3] = '\0';

        printf("Currency: %s\n", diets[pointer].currency);

        pointer++;
    }

    printf("-> Diets loaded...\n\n\n");

    dietsLength = pointer;

    return 0;
}

int main()
{
    if(loadRates()!=0 || loadDiety()!=0) return -1;

    printf("Kolko krajin zamestnanec navstivil? (max. 3): ");
    scanf("%i", &staysLength);

    if(staysLength>3) {
        printf("Nemozno pocitat s viac ako 3 krajinami");
        return -1;
    }

    gets(trash);

    int i;
    for(i=0;i<staysLength;i++) {
        printf("Zadaj nazov krajiny: ");
        gets(stays[i].country);

        printf("Zadaj pocet hodin stravenych v krajine: ");
        scanf("%i",&(stays[i].hours));

        gets(trash);

        printf("Zadaj zaplatene jedla oddelene medzerou (obed vecera ranajky): \n");
        char str[128];
        gets(str);

        stays[i].reduction = 0;

        char *p;
        p = strtok(str, " ");
        do {
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
            p = strtok(NULL, " ");
        } while(p);

        //printf("Krajina: %s\n", stays[i].country);
        //printf("Duration: %i\n", stays[i].hours);
        //printf("Reduction: %f\n", stays[i].reduction);
    }

    calculateStays();

    return 0;
}
