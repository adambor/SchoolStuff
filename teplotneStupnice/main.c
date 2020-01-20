#include <stdio.h>
#include <stdlib.h>

float toKelvin(float value) {
    return value+273.15;
}

float toFaran(float value) {
    return (9.0/5.0*value)+32.0;
}

int main()
{
    printf("Teploty:\n");
    float i;
    for(i=-50;i<=300;i++) {
        printf("%10.2f stupnov C %10.2f K %10.2f stupnov F\n", i, toKelvin(i), toFaran(i));
    }
    return 0;
}
