#include <stdio.h>
#include <stdlib.h>

/*
Vo WORDe nakreslite v�vojov� diagram, pomocou ktor�ho zist�te maximum z 3 ��sel zadan�ch z kl�vesnice. Pod�a v�vojov�ho diagramu nap�te program v jazyku C.
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
