#include <stdio.h>
#include <stdlib.h>

//Uzavrety interval
#define INT_MIN -99
#define INT_MAX 100

#define RAND_MIN 5
#define RAND_MAX 25

int main()
{
    srand(time(NULL));

    int amount = RAND_MIN+(rand()%(RAND_MAX-RAND_MIN+1));

    printf("Zadaj %i cisel...\n", amount);

    int success = 0;
    int failed = 0;

    int num;
    int i;
    for(i=0;i<amount;i++) {
        printf("Zadaj %i. cislo: ", i+1);
        scanf("%i",&num);
        if(num>=INT_MIN && num<=INT_MAX) {
            success++;
            printf("Zadane cislo je z intervalu <%i;%i>\n", INT_MIN, INT_MAX);
        } else {
            failed++;
            printf("Zadane cislo nie je z intervalu <%i;%i>\n", INT_MIN, INT_MAX);
        }
    }

    printf("Cisiel z intervalu: %i\n", success);
    printf("Cisiel mimo intervalu: %i\n", failed);
    printf("Percentualna uspesnost: %.2f%%\n", (double) (success)/(success+failed)*100.0 );

    return 0;
}
