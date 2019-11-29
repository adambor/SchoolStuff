#include <stdio.h>
#include <stdlib.h>

//All weights are in grams
#define WEIGHT_LIMIT 2500

#define BAG 650
#define PEN_CASE 30
#define FOOD 600
#define BOOK_PU 595
#define NOTEPAD 40

#define NIL 9
#define SJL 0
#define MAT 1
#define PVO 2
#define HUV 3
#define ANJ 4
#define NBV 5
#define TSV 6
#define VYV 7
#define INF 8

#define PON 0
#define UTR 1
#define STR 2
#define STV 3
#define PIA 4

int days[5][5] = {
    {SJL, MAT, SJL, TSV, NIL},
    {SJL, MAT, SJL, PVO, NIL},
    {MAT, SJL, ANJ, VYV, VYV},
    {SJL, MAT, HUV, INF, NBV},
    {SJL, MAT, ANJ, TSV, NIL}
};

int weights[10];

void init()
{
    weights[SJL] = 468;
    weights[MAT] = 194;
    weights[PVO] = 155;
    weights[HUV] = 254;
    weights[ANJ] = 365;
    weights[NBV] = 90;
    weights[TSV] = 0;
    weights[VYV] = 0;
    weights[INF] = 0;
    weights[NIL] = 0;
}

int main()
{
    init();
    char day[30];

    int dayI = -1;

    while(dayI==-1) {
        printf("Zadaj den: ");
        scanf("%s", day);

        if(strcmp(day, "pondelok")==0) {
            dayI = PON;
        }
        if(strcmp(day, "utorok")==0) {
            dayI = UTR;
        }
        if(strcmp(day, "streda")==0) {
            dayI = STR;
        }
        if(strcmp(day, "stvrtok")==0) {
            dayI = STV;
        }
        if(strcmp(day, "piatok")==0) {
            dayI = PIA;
        }
    }

    int totalWeight = BAG + PEN_CASE + FOOD + NOTEPAD;

    int i;
    for(i=0;i<5;i++) {
        totalWeight += weights[days[dayI][i]];
    }

    if(totalWeight>WEIGHT_LIMIT) {
        printf("Jurko si nemoze zobrat do skoly ani vsetky ucebnice aby neprekrocil svoj limit %i g, hmotnost ucebnic %i g\n", WEIGHT_LIMIT, totalWeight);
        return 0;
    }

    totalWeight += BOOK_PU;

    if(totalWeight>WEIGHT_LIMIT) {
        printf("Jurko si moze zobrat do skoly vsetky ucebnice, ale na jeho oblubenu knizku miesto uz neostane. Limit je %i g, hmotnost s knizkou je %i g.\n", WEIGHT_LIMIT, totalWeight);
    } else {
        printf("Jurko si moze zobrat do skoly vsetky ucebnice aj s jeho oblubenou knizkou. Limit je %i g, hmotnost je %i g.\n", WEIGHT_LIMIT, totalWeight);
    }

    return 0;
}
