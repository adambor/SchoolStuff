#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int y;
    int a;
    int b;
    printf("Nacitaj hodnotu x: ");
    scanf("%i", &x);
    printf("Nacitaj hodnotu y: ");
    scanf("%i", &y);
    a = x;
    b = y;
    GT:if(a!=b) {
        printf("%i\n",a);
    } else {
        if(a>b) {
            a-=b;
        } else {
            b-=a;
        }
        goto GT;
    }
    return 0;
}
