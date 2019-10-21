#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num;
    printf("Zadaj prirodzene cislo: ");
    scanf("%i", &num);
    if(num<=0) {
        printf("Cislo %i nie je prirodzene cislo!\n", num);
        return -1;
    }
    if(num==1) {
        printf("Cislo %i je jednotka!\n", num);
        return -1;
    }
    int i;
    for(i=2;i<=sqrt(num);i++) {
        double res = (double) num/i;
        if(floor(res)==res) {
            printf("Cislo %i je zlozene cislo, najdeny delitel: %i!\n", num, i);
            return -1;
        }
    }
    printf("Cislo %i je prvocislo!\n", num);
    return 0;
}
