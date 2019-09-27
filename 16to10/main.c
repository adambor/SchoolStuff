#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("Zadaj cislo v 16 sustave: ");
    scanf("%x",&i);
    while(i<0 || i>0x7FFF) {
        printf("Cislo nieje v rozsahu od 0 do 32767: ");
        scanf("%i",&i);
    }
    printf("Cislo v 10 sustave: %i\n", i);
    return 0;
}
