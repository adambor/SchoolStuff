#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "intarr.h"

#define FILE_NAME "cisielka.txt"

#define INITIAL_CAPACITY 10
#define CAPACITY_STEP 10

int main()
{
    FILE *f = fopen(FILE_NAME, "r");

    if(f==NULL) {
        printf("Nemozno otvorit subor %s!\n", FILE_NAME);
        return;
    }

    int sum1 = 0;
    int sum2 = 0;

    //struct IntArr arr = IntArr.new();
    int length1 = 0;
    int capacity1 = INITIAL_CAPACITY;
    int *arr1 = (int *) malloc(capacity1*sizeof(int));

    int number;

    printf("Povodne pole:\n");
    while(fscanf(f, "%i", &number)>0) {
        if(length1>capacity1-1) {
            capacity1 += CAPACITY_STEP;
            arr1 = (int *) realloc(arr1, capacity1*sizeof(int));
        }
        sum1 += number;
        arr1[length1] = number;
        printf("%i\n", number);
        length1++;
    }

    int element;

    printf("Zadaj cifru, ktoru chces vyhladat v danom poli cisel:");
    scanf("%i", &element);

    printf("Filtrovane pole:\n");
    int length2 = 0;
    int capacity2 = INITIAL_CAPACITY;
    int *arr2 = (int *) malloc(capacity2*sizeof(int));
    int i;
    for(i=0;i<length1;i++) {
        number = arr1[i];
        while(number>0) {
            if(number % 10 == element) {
                if(length2>capacity2-1) {
                    capacity2 += CAPACITY_STEP;
                    arr2 = (int *) realloc(arr2, capacity2*sizeof(int));
                }
                arr2[length2] = arr1[i];
                sum2 += arr1[i];
                printf("%i\n", arr1[i]);
                length2++;
                break;
            }
            number = floor(number/10);
        }
    }

    printf("Sucet cisel povodneho pola je o %i vacsi ako sucet cisiel filtrovaneho pola!\n", sum1-sum2);

}
