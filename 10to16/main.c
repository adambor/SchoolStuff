#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("Zadaj cislo v 10 sustave: ");
    scanf("%i",&i);
    while(i<0 || i>0x7FFF) {
        printf("Cislo nieje v rozsahu od 0 do 32767: ");
        scanf("%i",&i);
    }
    printf("Cislo v 16 sustave: %X\n", i);
    return 0;
}
