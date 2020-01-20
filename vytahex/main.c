#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "ludia.txt"
#define DEBUG 0

int main()
{
    FILE *f;
    f = fopen(FILE_NAME, "r");
    if(f==NULL) {
        printf("Nemozno otvorit subor %s ...\n", FILE_NAME);
        return -1;
    }

    int maxWeight;
    printf("Zadaj nosnost vytahu v kg: ");
    scanf("%i", &maxWeight);

    char name[50];
    char weightChar[50];
    int weight;

    int currentWeight = 0;

    int peopleInLift = 0;
    int iteration = 0;

    while(!feof(f)) {
        if(fgets(name, 50, f)==NULL) {
            break;
        }
        name[strlen(name)-1] = 0x00;
        if(fgets(weightChar, 50, f)==NULL) {
            break;
        }

        weight = atoi(weightChar);
        if(DEBUG) {
            printf("Meno: %s Weight: %i\n", name, weight);
        }

        if(weight>maxWeight) {
            printf("Osoba %s je zjavne tazsia ako vorvan, preto sa ani sama nedokaze zmestit do vytahu, odporucame vyskusat schody, poksytuju vysoky zdravotny benefit. Odporuca slovenska komora lekarov!\n",name);
            continue;
        }
        if(currentWeight+weight>maxWeight) {
            iteration++;
            printf("%i. jazda - %i\n", iteration, peopleInLift);
            peopleInLift = 0;
            currentWeight = 0;
        }
        currentWeight+=weight;
        peopleInLift++;
    }

    iteration++;
    printf("%i. jazda - %i\n", iteration, peopleInLift);

    return 0;
}
