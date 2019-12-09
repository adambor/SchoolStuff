#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DATA_FILE "data.txt"

char trash[50];

typedef struct QUARTER {
    int count;
    float sum;
} QUARTER;

QUARTER quarters[4];

int main()
{
    FILE *f;
    f = fopen(DATA_FILE,"r");

    if(f==NULL) {
        printf("Subor %s nenajdeny!", DATA_FILE);
        return -1;
    }

    int totalCount = 0;
    float totalAmount = 0;

    while(!feof(f)) {
        char name[50];
        fgets(name, 50, f);

        if(feof(f)) break;

        name[strlen(name)-1] = '\0';
        //printf("NAME: %s", name);
        int month;
        fscanf(f, "%i", &month);
        //printf("MONTH: %i", month);
        float amount;
        fscanf(f, "%f", &amount);
        //printf("AMOUNT: %f", amount);
        fgets(trash, 50, f);

        int quart = (int)floor((month-1)/3);

        //printf("Month:%i Quarter:%i\n", month, quart);

        QUARTER *quarter = &(quarters[quart]);

        if(amount>0) {
            totalCount++;
            quarter->count++;
            totalAmount+=amount;
            quarter->sum+=amount;
        }
    }

    float yearAvg = totalAmount/totalCount;

    char aboveAvg[15];
    char belowAvg[15];
    char equalAvg[15];

    memset(aboveAvg, '\0', 15*sizeof(char));
    memset(belowAvg, '\0', 15*sizeof(char));
    memset(equalAvg, '\0', 15*sizeof(char));

    int i;
    for(i=0;i<4;i++) {
        printf(" --- %i. Stvrtrok --- \n",i+1);
        printf("Odmenu ziskalo: %i ludi\n", quarters[i].count);
        float quarterAvg = quarters[i].sum/quarters[i].count;
        printf("Priemerna odmena: %.02f\n", quarterAvg );
        printf(" --- --- --- --- --- \n");
        if(yearAvg<quarterAvg) {
            if(aboveAvg[0]=='\0') {
                snprintf(aboveAvg, 10, "%i.", i+1);
            } else {
                snprintf(aboveAvg + strlen(aboveAvg), 10, ", %i.", i+1);
            }
        } else if(yearAvg>quarterAvg) {
            if(belowAvg[0]=='\0') {
                snprintf(belowAvg, 10, "%i.", i+1);
            } else {
                snprintf(belowAvg + strlen(belowAvg), 10, ", %i.", i+1);
            }
        } else {
            if(equalAvg[0]=='\0') {
                snprintf(equalAvg, 10, "%i.", i+1);
            } else {
                snprintf(equalAvg + strlen(equalAvg), 10, ", %i.", i+1);
            }
        }
    }

    printf("Pocas celeho roka bolo vyplatenych %i odmien\n",totalCount);
    printf("Priemerna odmena za rok bola %.02f", yearAvg);
    if(aboveAvg[0]!=0x00) printf(", bola prekonana v %s stvrtroku", aboveAvg);
    if(belowAvg[0]!=0x00) printf(", nizsia bola v %s stvrtroku", belowAvg);
    if(equalAvg[0]!=0x00) printf(", rovnaka bola v %s stvrtroku", equalAvg);
    printf("\n");

    return 0;
}
