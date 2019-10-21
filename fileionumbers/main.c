#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    printf("Otvaram subor!\n");
    file = fopen("04_10_subor/cisla.txt","r");
    if(file==NULL) {
        printf("Subor 04_10_subor/cisla.txt neexistuje!\n");
        return -1;
    }

    int numberCount = 0;
    int zeroCount = 0;
    int positiveCount = 0;
    int positiveSum = 0;
    int negativeCount = 0;
    int negativeSum = 0;
    int evenCount = 0;
    int oddCount = 0;
    int min = 32767;
    int max = -32768;
    long long product = 1;

    int i;
    while(fscanf(file, "%i", &i)!=EOF) {
        numberCount++;
        if(i==0) zeroCount++;
        if(i>0) {
            positiveCount++;
            positiveSum+=i;
        }
        if(i<0) {
            negativeCount++;
            negativeSum+=i;
        }
        if(i%2==1) {
            oddCount++;
        } else {
            evenCount++;
        }
        if(i<min) min = i;
        if(i>max) max = i;
        product *= i;
    }

    fclose(file);

    if(numberCount>25 || numberCount<10) {
        printf("Pocet cisel v subore je vacsi ako 25 alebo mensi ako 10!\n");
        return -2;
    }

    printf("Pocet cisel: %i\n", numberCount);
    printf(zeroCount==0 ? "Subor neobsahuje ziadne nuly\n" : "Pocet nul: %i\n", zeroCount);
    printf("Pocet kladnych cisel: %i\n", positiveCount);
    printf(positiveCount==0 ? "Priemer kladnych cisel nemozno spravit\n" : "Priemer kladnych cisel: %.2f\n", positiveCount!=0 ? (float) positiveSum/positiveCount : 0);
    printf("Pocet zapornych cisel: %i\n", negativeCount);
    printf(negativeCount==0 ? "Priemer zapornych cisel nemozno spravit\n" : "Priemer zapornych cisel: %.2f\n", negativeCount!=0 ? (float) negativeSum/negativeCount : 0);
    printf("Pocet parnych cisel: %i\n", evenCount);
    printf("Pocet neparnych cisel: %i\n",oddCount);
    printf("Minimum: %i\n", min);
    printf("Maximum: %i\n", max);
    printf("Sucin: %I64d\n", product);
    return 0;
}
