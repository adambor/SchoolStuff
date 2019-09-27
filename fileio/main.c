#include <stdio.h>
#include <stdlib.h>

/*
Vytvorte program, ktor�:

    na��ta �daje z prilo�en�ho textov�ho s�boru (v riadkoch pod sebou s� zap�san� v��ky platov zamestnancov) a vyp�e ich v termin�li nasledovne:
        Plat 1. zamestnanca je 300 eur.
        Plat 2. zamestnanca je 300 eur.
    zist� a n�sledne vyp�e na termin�li, ak� je v��ka najvy��ieho/najni��ieho platu - napr.: Najvyssi plat je 800 eur, najnizsi 200 eur.
    vypo��ta priemern� plat zamestnancov.
    textov� s�bor po skon�en� pr�ce s n�m korektne zatvor�.

Bonusov� �loha: Otestuje existenciu textov�ho s�boru, s ktor�m m� pracova�.
*/

int * readFile(FILE *fptr, int *len) {
    //Start with array length of 10
    int arrLength = 10;
    int *arr = (int*) malloc(arrLength * sizeof(int));

    if(NULL == arr) {
        printf("Failed to allocate memory...\n");
        return -2;
    }

    (*len) = 0;

    int wage;
    while(fscanf(fptr, "%i", &wage)!=EOF) {
        arr[*len] = wage;
        (*len)++;
        if((*len) >= arrLength) {
            //Make the array bigger
            arrLength+=10;
            if(NULL == realloc(arr, arrLength * sizeof(int))) {
                printf("Failed to re-allocate memory...\n");
                return -3;
            }
        }
    }
    return arr;
}

int main()
{
    FILE *fptr;

    fptr = fopen("data.txt", "r");
    if(NULL==fptr) {
        //Error
        printf("Failed to open file data.txt, aborting...");
        return -1;
    }
    int length;
    int *wages = readFile(fptr, &length);
    fclose(fptr);

    if(length==0) {
        printf("Subor je prazdny!");
        return 0;
    }

    int i;
    int min = wages[0];
    int max = wages[0];
    double sum = 0;

    for(i=0;i<length;i++) {
        printf("Plat %i. zamestnanca je %i eur\n", i+1, wages[i]);
        if(wages[i]>max) {
            max = wages[i];
        }
        if(wages[i]<min) {
            min = wages[i];
        }
        sum += wages[i];
    }

    printf("Najnizsi plat: %i\n", min);
    printf("Najvyssi plat: %i\n", max);
    printf("Priemerny plat: %f\n", sum/(double)length);
    return 0;
}
