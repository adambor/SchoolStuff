#include <stdio.h>
#include <stdlib.h>

/*
Pracujete v obore celıch èísel. Poèet èísel od 5 do 30, ktoré bude program spracováva, vygeneruje poèítaè. Èísla následne zadáte z klávesnice. Program dané èísla vypíše:
tak, ako boli zadané;
tak, e maximálne a minimálne navzájom vymeníte.
*/

void read(int* arr, int length) {
    printf("Zadaj prosim %i cisel:\n",length);
    int i;
    for(i=0;i<length;i++) {
        printf("Zadaj %i. cislo: ",i+1);
        scanf("%i", &(arr[i]));
    }
}

void write(int* arr, int length) {
    int i;
    for(i=0;i<length;i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void flipMinMax(int* arr, int length) {
    int minIndex = -1;
    int min = 2147483647;

    int maxIndex = -1;
    int max = -2147483648;

    int i;
    for(i=0;i<length;i++) {
        int val = arr[i];
        if(val < min) {
            min = val;
            minIndex = i;
        }
        if(val > max) {
            max = val;
            maxIndex = i;
        }
    }

    if(minIndex!=maxIndex) {
        arr[minIndex] = max;
        arr[maxIndex] = min;
    }
}

int main()
{
    srand(time(NULL));
    int length = 5+(rand()%25);
    int array[length];
    read(array, length);
    printf("Tak ako boli zadane: ");
    write(array , length);
    flipMinMax(array, length);
    printf("Min max vymenene: ");
    write(array, length);

    return 0;
}
