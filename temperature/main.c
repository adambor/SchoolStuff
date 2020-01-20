#include <stdio.h>
#include <stdlib.h>

float CtoK(float val) {
    return val+273.15;
}

float KtoC(float val) {
    return val-273.15;
}

float CtoF(float val) {
    return (9.0/5.0*val)+32;
}

float FtoC(float val) {
    return 5.0/9.0*(val-32);
}

int main()
{
    char str[20];
    char *ptr;
    while(1) {
        printf("Zadaj teplotu (s K, F alebo C na konci), alebo napis \"exit\" pre ukoncenie: ");
        scanf("%s", str);
        if(strcmp(str, "exit")==0) {
            break;
        }

        float num = strtof(str, &ptr);

        float celsius;
        switch(*ptr) {
        case 'K':
            celsius = KtoC(num);
            break;
        case 'F':
            celsius = FtoC(num);
            break;
        default:
            celsius = num;
            break;
        }

        printf("Zadaj jednotku, do ktorej to chces premenit (K, F alebo C): ");
        scanf("%s", str);

        float result;
        switch(str[0]) {
        case 'K':
            result = CtoK(celsius);
            break;
        case 'F':
            result = CtoF(celsius);
            break;
        default:
            result = celsius;
            break;
        }

        printf("%0.2f%c = %0.2f%c\n", num, *ptr, result, str[0]);
    }
    return 0;
}
