#include <stdio.h>
#include <stdlib.h>

FILE *input;
FILE *output;

int main()
{
    input = fopen("skokani.txt", "r");
    output = fopen("vysledky.txt", "w");
    if(input==NULL) {
        printf("Subor skokani.txt nenajdeny!\n");
        return -1;
    }
    if(output==NULL) {
        printf("Nemozno otvorit subor vysledky.txt!\n");
        return -2;
    }
    char name[100];
    while(fscanf(input, "%s", name)!=EOF) {
        int distance;
        int sum = 0;
        int i;
        for(i=0;i<10;i++) {
            fscanf(input, "%i", &distance);
            sum += distance;
        }
        double average = round(sum)/10;
        fprintf(output, "%s - %.1f\n", name, average);
        memset(name, 0x00, 100);
    }
    fclose(input);
    fclose(output);
    return 0;
}
