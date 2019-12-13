#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculatev(double a, int n) {
    double angle = 2*M_PI/n;
    return (a/2)/tan(angle/2);
}

double calculateSp(double a, int n) {
    return n*a*calculatev(a,n)/2;
}

double calculateS(double a, double h, int n) {
    return (n*a*h)+(2*calculateSp(a,n));
}

double calculateV(double a, double h, int n) {
    return h*calculateSp(a,n);
}

double calculateVpyramid(double a, double h, int n) {
    return h*calculateSp(a,n)/3;
}

double calculateSpyramid(double a, double h, int n) {
    double v = calculatev(a, n);
    double wallv = sqrt(pow(v,2)+pow(h,2));

    return (wallv*a*n/2)+calculateSp(a,n);
}

int main()
{
    printf("Vypocet povrchu a obsahu n-bokeho hranola...\n");

    int n;
    printf("Zadaj n: ");
    scanf("%i", &n);

    if(n<3) {
        printf("n musi byt vacsie ako 2!");
        return -1;
    }

    double a;
    printf("Zadaj a: ");
    scanf("%lf", &a);

    double h;
    printf("Zadaj h: ");
    scanf("%lf", &h);

    printf("Hodnoty pre hranol: \n");
    printf("Sh=%lf\n", calculateS(a, h, n));
    printf("Vh=%lf\n", calculateV(a, h, n));

    printf("Hodnoty pre ihlan: \n");
    printf("Si=%lf\n", calculateSpyramid(a, h, n));
    printf("Vi=%lf\n", calculateVpyramid(a, h, n));
    return 0;
}
