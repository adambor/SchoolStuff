#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int length;
int positive = 0;

void zisti(int num) {
    if( (int)floor(num/10) %2==0) {
        positive++;
    }
}

void pis(int index, int num) {
    printf("%i. cislo: %i\n", index+1, num);
}

void citaj(int index) {
    int num;
    scanf("%i", &num);
    if(floor(num/1000)>0) {
        printf("Cislo %i, nieje 3-ciferne!\n", num);
        return;
    }
    pis(index, num);
    zisti(num);
}

int main()
{
    printf("Zadaj pocet cisiel, ktore chces nacitat: ");
    scanf("%i", &length);
    int i;
    printf("Zadaj 3-ciferne cisla za sebou:\n");
    for(i=0;i<length;i++) {
        citaj(i);
    }
    printf("Pocet zadanych cisiel: %i\n", length);
    printf("Splnalo podmienku: %i (%0.2f%%)\n", positive, ((double)positive / (double)length) * 100.0);
    printf("Nesplnalo podmienku: %i\n", length-positive);
    return 0;
}
