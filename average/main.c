#include <stdio.h>
#include <stdlib.h>

FILE *file;

void getStudent(int i) {
    printf("Zadaj meno studenta cislo %i: ", i+1);
    char name[50];
    scanf("%s",name);
    printf("Zadaj pocet znamok studenta cislo %i: ", i+1);
    int markCount;
    int markSum = 0;
    scanf("%i",&markCount);
    printf("Zadaj zaradom %i znamok studenta\n",markCount);
    int e;
    int mark;
    for(e=0;e<markCount;e++) {
        scanf("%i", &mark);
        markSum += mark;
    }
    if(markCount==0) {
        //Neklasifikovany
        markSum = 5;
        markCount = 1;
    }
    double average = markSum/markCount;
    printf("Priemerna znamka studenta %s je %.0f\n",name,round(average));
    fprintf(file, "%s - %.0f\n", name, round(average));
}

int main()
{
    file = fopen("vysvedcenie.txt", "w");
    if(file==NULL) {
        printf("Nemozno otvorit subor vysvedcenie.txt, program bude ukonceny!\n");
        return -1;
    }
    int length;
    printf("Zadaj pocet studentov: ");
    scanf("%i", &length);
    int i;
    for(i=0;i<length;i++) {
        getStudent(i);
    }
    fclose(file);
    return 0;
}
