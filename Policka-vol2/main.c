#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

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

    //struct IntArr arr = IntArr.new();

    int *arr1 = (int *) malloc(capacity*sizeof(int));

    int number;
    while(fscanf(f, "%i", &number)>0) {
        if(length>capacity-1) {
            capacity += CAPACITY_STEP;
            arr1 = (int *) realloc(arr1, capacity*sizeof(int));
        }
        arr1[length] = number;
        printf("Number: %i\n", number);
        length++;
    }

    int element;

    printf("Zadaj cifru, ktoru chces vyhladat v danom poli cisel:");
    scanf("%i", &element);



}
