#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Zadaj cislo v 10 sustave: ");
    int a;
    char arr[16];
    int len = 0;
    scanf("%i", &a);
    while(a!=0) {
        arr[len] = a & 0b1;
        a>>=1;
        len++;
    }
    printf("Cislo v binarnej sustave: ");
    for(len-=1;len>=0;len--) {
        printf("%i", arr[len]);
    }
    printf("\n");
    return 0;
}
