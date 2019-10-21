#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max = 30000;

void genPrimes(bool* primeLookup) {
    memset(primeLookup, true, max);
    primeLookup[0] = primeLookup[1] = false;
    int i;
    for(i=2;i<max;i++) {
        if(!primeLookup[i]) continue;

        int e;
        for(e=i*i;e<=max;e+=i) {
            primeLookup[e] = false;
        }
    }
}

void checkNum(bool* primeLookup, int num) {
    if(num<=0) {
        printf("Cislo %i nie je prirodzene cislo!\n", num);
        return -1;
    }
    if(num==1) {
        printf("Cislo %i je jednotka!\n", num);
        return -1;
    }
    if(primeLookup[num]) {
        printf("Cislo %i je prvocislo!\n", num);
    } else {
        printf("Cislo %i je zlozene cislo!\n", num);
    }
}

int main()
{
    srand(time(NULL));
    bool primeLookup[max];
    genPrimes(primeLookup);
    int n;
    printf("Zadaj pocet cisel, ktore si ma pocitac vymysliet a zistit ci su prvocisla: ");
    scanf("%i", &n);
    int i;
    int num;
    for(i=0;i<n;i++) {
        num = rand()%30000;
        checkNum(primeLookup, num);
    }
    return 0;
}
