#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char *monthName[] = {
    "Januar",
    "Februar",
    "Marec",
    "April",
    "Maj",
    "Jun",
    "Jul",
    "August",
    "September",
    "Oktober",
    "November",
    "December"
};

char *monthInRoman[] = {
    "I",
    "II",
    "III",
    "IV",
    "V",
    "VI",
    "VII",
    "VIII",
    "IX",
    "X",
    "XI",
    "XII"
};

int monthLengths[] = {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};

int getMonth(char *str) {
    int month = -1;
    int i;
    for(i=0;i<12;i++) {
        if(strcasecmp(monthInRoman[i], str)==0) {
            //Found
            month = i;
            break;
        }
        if(strcasecmp(monthName[i], str)==0) {
            //Found
            month = i;
            break;
        }
    }
    return month;
}

int main()
{
    char str[30];
    int month;

    do {
        printf("Zadaj mesiac rimskou cislicou alebo nazvom: ");
        scanf("%s",str);
        month = getMonth(str);
        if(month==-1) printf("Mesiac nenajdeny, skus to znova!\n");
    } while (month==-1);

    int dayInMonth;

    do {
        printf("Zadaj den v mesiaci: ");
        scanf("%i", &dayInMonth);
        if(dayInMonth<=0) printf("Den v mesiaci musi byt kladne a nenulove cele cislo!\n");
    } while(dayInMonth<=0);

    int daysInMonth = monthLengths[month];

    if(month==1) {

        if(daysInMonth<dayInMonth) {
            printf("Pocet dni v mesiaci je len %i! Zadal si cislo %i.\n", daysInMonth, dayInMonth);
        } else {
            printf("Pocet dni zostavajucich do konca mesiaca je %i\n", daysInMonth-dayInMonth);
        }

        daysInMonth++;

        if(daysInMonth<dayInMonth) {
            printf("Pocet dni v mesiaci v priestupny rok je len %i! Zadal si cislo %i.\n", daysInMonth, dayInMonth);
        } else {
            printf("Pocet dni zostavajucich do konca mesiaca v priestupny rok je %i\n", daysInMonth-dayInMonth);
        }

    } else {

        if(daysInMonth<dayInMonth) {
            printf("Pocet dni v mesiaci je len %i! Zadal si cislo %i.\n", daysInMonth, dayInMonth);
        } else {
            printf("Pocet dni zostavajucich do konca mesiaca je %i\n", daysInMonth-dayInMonth);
        }

    }

    return 0;
}
