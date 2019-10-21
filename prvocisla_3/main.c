#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int ZERO = 0;
const int ONE = 1;
const int PRIME = 2;
const int NOT_PRIME = 3;

int max = 30000;

void genPrimes(bool* primeLookup) {
    memset(primeLookup, true, max);
    primeLookup[0] = primeLookup[1] = false;
    int i;
    for(i=2;i<max;i++) {
        if(!primeLookup[i]) continue;

        int e;
        for(e=i*i;e<=max;e+=i) {
            primeLookup[e] = false;
        }
    }
}

int checkNum(bool* primeLookup, int num) {
    if(num<=0) {
        printf("Cislo %i nie je prirodzene cislo!\n", num);
        return ZERO;
    }
    if(num==1) {
        printf("Cislo %i je jednotka!\n", num);
        return ONE;
    }
    if(primeLookup[num]) {
        printf("Cislo %i je prvocislo!\n", num);
        return PRIME;
    } else {
        printf("Cislo %i je zlozene cislo!\n", num);
        return NOT_PRIME;
    }
}

int main()
{
    srand(time(NULL));
    bool primeLookup[max];
    genPrimes(primeLookup);
    int n;
    printf("Zadaj pocet cisel, ktore zadas: ");
    scanf("%i", &n);
    int i;
    int num;
    int primes[n];
    int primes_count = 0;
    int not_primes[n];
    int not_primes_count = 0;
    bool zero = false;
    bool one = false;
    for(i=0;i<n;i++) {
        printf("Zadaj cislo: ");
        scanf("%i", &num);
        switch(checkNum(primeLookup, num)) {
            case 0:
                zero = true;
                break;
            case 1:
                one = true;
                break;
            case 2:
                primes[primes_count] = num;
                primes_count++;
                break;
            case 3:
                not_primes[not_primes_count] = num;
                not_primes_count++;
                break;
        }
    }
    printf(primes_count>0 ? "Prvocisla: " : "Ziadne prvocisla neboli zadane!");
    for(i=0;i<primes_count;i++) {
        printf("%i, ", primes[i]);
    }
    printf("\n");
    printf(not_primes_count>0 ? "Zlozene cisla: " : "Ziadne zlozene cisla neboli zadane!");
    for(i=0;i<not_primes_count;i++) {
        printf("%i, ", not_primes[i]);
    }
    printf("\n");
    printf("Medzi zadanymi cislami ");
    printf(zero && one ? "bola 0 aj 1" : zero && !one ? "bola len 0" : !zero && !one ? "nebola ani 1 ani 0" : "bola len 1");
    printf("\n");
    return 0;
}
