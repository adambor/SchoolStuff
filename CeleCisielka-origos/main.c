#include <stdio.h>

int main()
{
    double zlomok;
    int citatel, menovatel;

    printf("Zadaj citatel zlomku: ");
    scanf("%d", &citatel);
    printf("Zadaj menovatel zlomku: ");
    scanf("%d", &menovatel);
    zlomok = (double)citatel / (double)menovatel;

    printf("\nHodnota zlomku %d/%d, s ktorou budem pracovat je %0.3f!\n", citatel, menovatel, zlomok);
}
