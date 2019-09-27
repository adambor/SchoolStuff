#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    printf("Zadaj 1. dvojicu cisel!\n");
    scanf("%i",&a);
    scanf("%i",&b);
    printf("Zadaj 2. dvojicu cisel!\n");
    scanf("%i",&c);
    scanf("%i",&d);
    if(a+b>c+d) {
        printf("1. dvojica je vacsia!\n");
    } else {
        if(a+b==c+d) {
            printf("Dvojice su si rovne\n");
        } else {
            printf("2. dvojica je vacsia!\n");
        }
    }
    return 0;
}
