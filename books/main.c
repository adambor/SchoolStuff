#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define FILE_PATH "books.txt"

int main()
{
    FILE *file;
    file = fopen(FILE_PATH,"r");

    if(NULL==file) {
        printf("Nemozno otvorit subor books.txt!\n");
        return -1;
    }

    char name[MAX_LENGTH];

    printf("Zadaj meno hladaneho autora: ");
    gets(name);

    int counter = 0;
    char nameF[MAX_LENGTH];
    while(!feof(file)) {
        fgets(nameF, MAX_LENGTH, file);
        if(strstr(nameF, name)>0) {
            counter++;
        }
    }

    fclose(file);

    if(counter==0) {
        printf("Meno autora sa v subore nenachadza\n");
        return 0;
    }

    printf("Meno autora sa v subore nachadza %i krat\n", counter);

    return 0;
}
