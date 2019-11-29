#include <stdio.h>
#include <stdlib.h>

#define MIN -10000
#define MAX 10000

/*
    z kl�vesnice na��ta, ak� po�et ��sle m� PC vymyslie�;

    PC vymysl� pr�slu�n� po�et ��sel a zap�e ich do po�a;

    n�jde minimum a maximum, pri�om ur�� ich poz�cie (��slo na poz�ci� pole0 bude ako prv� ��slo), �o vyp�e na monitor - napr. minimum 9 - 5. ��slo;

    urob� aritmetick� priemer minima a maxima, pri�om ur��, �i je priemer kladn�, z�porn� alebo rovn� nule;

    urob� s��et ��sel nach�dzaj�cich sa pred minimom;

    urob� s��et ��sel nach�dzaj�cich sa medzi minimom a maximom (ak minimum a maximum id� ihne� za sebou, tak to vyp�e na obrazovku a tento s��et bude nulov�);

    urob� s��et ��sel nach�dzaj�cich sa za maximom;

    vypo��tan� 3 s��ty vyp�e na obrazovku zostupne.
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
