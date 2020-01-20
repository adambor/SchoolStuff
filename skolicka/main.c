#include <stdio.h>
#include <stdlib.h>

#define FILENAME "skolicka.txt"

void printFile() {
    FILE *f;

    f = fopen(FILENAME, "r");

    if(f==NULL) {
        printf("Nemozno otvorit subor %s\n", FILENAME);
        return;
    }

    while(!feof(f)) {
        printf("%c", fgetc(f));
    }

    fclose(f);
}

void getValues() {
    FILE *f;

    f = fopen(FILENAME, "r");

    if(f==NULL) {
        printf("Nemozno otvorit subor %s\n", FILENAME);
        return;
    }

    int sumTotal = 0;
    int sumBoys = 0;

    while(!feof(f)) {
        char name[10];
        fgets(name, 10, f);
        //printf("Name: %s\n", name);
        int total;
        if(fscanf(f, "%i", &total) == EOF) break;
        //printf("Total: %i\n", total);
        int boys;
        if(fscanf(f, "%i", &boys) == EOF) break;
        //printf("Boys: %i\n", boys);
        sumBoys+=boys;
        sumTotal+=total;
    }

    printf("\n\n\nNa skole je %i ziakov.\n", sumTotal);
    printf("Z toho je %i chlapcov a %i dievcat.\n", sumBoys, sumTotal-sumBoys);

    fclose(f);
}

int main()
{
    printFile();
    getValues();
    return 0;
}
