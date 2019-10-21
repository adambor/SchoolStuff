#include <stdio.h>
#include <stdlib.h>

int readNumber(int *length) {
    printf("Zadaj pocet cisel, ktore chces nahodne vygenerovat: ");
    scanf("%i", length);
    if(*length<1 || *length>100) {
        printf("Zadane cislo musi byt v intervale <1;100>!\n");
        return -1;
    }
    return 0;
}

int main()
{
    srand(time(NULL));

    int length;
    while(readNumber(&length)!=0);
    int arr[length];

    int i;
    for(i=0;i<length;i++) {
        arr[i] = rand()%32767;
    }

    printf("Vymyslene cisla v opacnom poradi: ");
    for(i--;i>=0;i--) {
        printf(i==0 ? "%i" : "%i, ", arr[i]);
    }

    return 0;
}
