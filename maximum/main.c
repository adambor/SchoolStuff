#include <stdio.h>
#include <stdlib.h>

/*
Vo WORDe nakreslite vývojový diagram, pomocou ktorého zistíte maximum z 3 èísel zadaných z klávesnice. Pod¾a vývojového diagramu napíšte program v jazyku C.
*/

int main()
{
    int x;
    int i;
    int min = 2147483647;
    for(i=0;i<3;i++) {
        printf("Zadaj %i. cislo: ",i+1);
        scanf("%i", &x);
        if(x<min) {
            min = x;
        }
    }
    printf("Najmensie cislo je: %i", min);
    return 0;
}
