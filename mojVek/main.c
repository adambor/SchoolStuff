#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    //Get current year
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currYear = 1900+tm.tm_year;
    int bornYear;
    bool timeTraveller = 0;

    printf("Na zaklade tvojho roku narodenia vypoctam tvoj vek na konci sucasneho roku\n");
    printf("Zadaj rok svojho narodenia: ");
    scanf("%i", &bornYear);
    if(bornYear>currYear) {
        printf("Zdravim ta, cestovatel v case!\n");
        printf("Na vypocet tvojho veku budem musiet poznat rok z ktoreho prichadzas!\n");
        printf("Zadaj rok z ktoreho cestujes: ");
        scanf("%i", &currYear);
        timeTraveller = 1;
    }

    int computedAge = currYear-bornYear;

    printf(computedAge==1 ? "Mas %i rok!\n" : (computedAge==0 || computedAge>4) ? "Mas %i rokov!\n" : "Mas %i roky!\n", computedAge);

    if(timeTraveller && computedAge>100) {
        printf("Wow, uz ste objavili liek na starobu?\n");
    }

    return 0;
}
