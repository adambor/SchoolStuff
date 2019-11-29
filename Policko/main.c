#include <stdio.h>
#include <stdlib.h>

#define MIN -10000
#define MAX 10000

/*
    z klávesnice naèíta, akı poèet èísle má PC vymyslie;

    PC vymyslí príslušnı poèet èísel a zapíše ich do po¾a;

    nájde minimum a maximum, prièom urèí ich pozície (èíslo na pozícií pole0 bude ako prvé èíslo), èo vypíše na monitor - napr. minimum 9 - 5. èíslo;

    urobí aritmetickı priemer minima a maxima, prièom urèí, èi je priemer kladnı, zápornı alebo rovnı nule;

    urobí súèet èísel nachádzajúcich sa pred minimom;

    urobí súèet èísel nachádzajúcich sa medzi minimom a maximom (ak minimum a maximum idú ihneï za sebou, tak to vypíše na obrazovku a tento súèet bude nulovı);

    urobí súèet èísel nachádzajúcich sa za maximom;

    vypoèítané 3 súèty vypíše na obrazovku zostupne.
*/

int compare( const void* a_void, const void* b_void)
{
    //Cast to int
    int a = * ( (int*) a_void );
    int b = * ( (int*) b_void );

    return a==b ? 0 : a<b ? 1 : -1;
}

int main()
{
    srand(time(NULL));
    int len = 0;
    while(len<1) {
        printf("Zadaj pocet cisel, ktore si ma pocitac vymysliet: ");
        scanf("%i", &len);
    }

    int numbers[len];

    int min, max;
    min = MAX;
    max = MIN;

    int minPtr, maxPtr;
    minPtr = maxPtr = -1;

    int i;
    for(i=0;i<len;i++) {
        numbers[i] = (rand()%(MAX-MIN))+MIN;
        if(numbers[i] > max) {
            max = numbers[i];
            maxPtr = i;
        }
        if(numbers[i] < min) {
            min = numbers[i];
            minPtr = i;
        }
    }

    printf("Najmensie cislo: %i, %i. pozicia\n", min, minPtr+1);
    printf("Najvacsie cislo: %i, %i. pozicia\n", max, maxPtr+1);

    int avg = (min+max)/2;
    printf("Priemer najmensieho a najvacsieho je: %i co je ", avg);
    printf(avg>0 ? "kladne" : avg<0 ? "zaporne" : "rovne nule");
    printf("\n");

    //Sucet cisel pred minimom
    int underMinSum = 0;
    for(i=minPtr-1;i>=0;i--) {
        underMinSum+=numbers[i];
    }
    printf("Sucet cisiel pred minimom: %i\n", underMinSum);

    //Sucet medzi minPtr a maxPtr
    int diffSum = 0;
    if(abs(minPtr-maxPtr)<=1) {
        printf("Sucet cisel medzi minimom a maxmimom je rovny nule kedze nasleduju hned za sebou\n");
    } else {
        if(minPtr<maxPtr) {
            for(i=minPtr+1;i<maxPtr;i++) {
                diffSum+=numbers[i];
            }
        }
        if(maxPtr<minPtr) {
            for(i=maxPtr+1;i<minPtr;i++) {
                diffSum+=numbers[i];
            }
        }
        printf("Sucet cisel medzi minimom a maxmimom je: %i\n", diffSum);
    }

    //Sucet cisel za maximom
    int overMaxSum = 0;
    for(i=maxPtr+1;i<len;i++) {
        overMaxSum+=numbers[i];
    }
    printf("Sucet cisiel za maximom: %i\n", overMaxSum);

    int arr[] = {underMinSum, diffSum, overMaxSum};
    printf("Zostupne vypisane sucty:\n");
    qsort( arr, 3, sizeof(int), compare );
    for(i=0;i<3;i++) {
        printf("%i\n", arr[i]);
    }

    return 0;
}
