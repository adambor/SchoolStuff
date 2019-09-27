#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int a,b,c,d;
    printf("Zadaj 1. dvojicu cisel!\n");
    scanf("%i",&a);
    scanf("%i",&b);
    c = rand();
    d = rand();
    printf("Pocitac vymyslel cisla: %i, %i\n", c, d);
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
