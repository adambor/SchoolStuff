#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[15];
    memset(arr, 0x00, 15);

    printf("Zadaj cislo v 2 sustave od 0 do 111111111111111: ");
    scanf("%s", arr);

    int num = 0;

    int i;
    int bitCounter = 0;
    for(i=14;i>=0;i--) {
        if(arr[i]=='0') {
            bitCounter++;
        } else if(arr[i]=='1') {
            //Set bit
            num |= 1 << bitCounter;
            printf("Value: %i\n", num);
            bitCounter++;
        } else if(arr[i]!=0x00) {
            printf("Zadana hodnota nieje cislo v 2 sustave!");
            return -1;
        }
    }

    printf("Cislo v 10 sustave: %i\n", num);

    return 0;
}
