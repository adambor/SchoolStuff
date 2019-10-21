#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_PATH "data.txt"
#define BUFFER_LENGTH 128

int main()
{
    FILE *file;
    file = fopen(DATA_PATH, "r");

    if(file==NULL) {
        printf("Subor %s nemozno otvorit!\n", DATA_PATH);
        return -1;
    }

    int uni = 0;
    int high = 0;

    char buffer[BUFFER_LENGTH];

    while(!feof(file)) {
        fgets(buffer, BUFFER_LENGTH, file); // name
        fgets(buffer, BUFFER_LENGTH, file); // gender
        fgets(buffer, BUFFER_LENGTH, file); // state
        if(strstr(buffer, "r")) {
            fgets(buffer, BUFFER_LENGTH, file); //education
            if(strstr(buffer, "s")) {
                high++;
            }
            if(strstr(buffer, "v")) {
                uni++;
            }
        } else {
            fgets(buffer, BUFFER_LENGTH, file); //education
        }
    }

    fclose(file);

    printf("Rozvedenych stredoskolacok: %i\n", high);
    printf("Rozvedenych vysokoskolacok: %i\n", uni);
    printf(high>uni ? "Vysokoskolacok je rozvedenych viac ako stredoskolacok!\n" : "Vysokoskolacok nie je rozvedenych viac ako stredoskolacok!\n");
    return 0;
}
