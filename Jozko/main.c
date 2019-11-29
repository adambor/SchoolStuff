#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "data.txt"
#define OUT_FILE_NAME "out.txt"

int earnPerDay[5];
int earnPerWeek = 0;



int loadEarnings() {
    FILE *file;

    file = fopen(FILE_NAME, "r");
    if(file==NULL) {
        printf("Subor %s nieje mozne otvorit!\n", FILE_NAME);
        return -1;
    }

    int i;
    char amount[128];
    char day[128];
    char job[128];
    for(i=0;i<5;i++) {
        fgets(day, 128, file);
        fgets(job, 128, file);
        fgets(amount, 128, file);
        earnPerDay[i] = atoi(amount);
        earnPerWeek+=earnPerDay[i];
        printf("%s - %s - %i EUR\n", day, job, earnPerDay[i]);
    }

    printf("Tyzdenny prijem: %i EUR\n", earnPerWeek);

    fclose(file);

    return 0;
}

void getWeeksAndDays(double itemPrice, int *weeks, int *days) {

    int res = (int) floor(itemPrice/((double)earnPerWeek));

    //printf("Weeks and days called %f earnPerWeek %i floor %i!\n", itemPrice, earnPerWeek, res);

    (*weeks) = res;

    itemPrice-=(*weeks)*earnPerWeek;

    (*days) = 0;

    int i;
    for(i=0;i<5;i++) {
        if(itemPrice<=0) break;
        itemPrice-=earnPerDay[i];
        (*days)++;
    }

}

int main()
{
    if(loadEarnings()<0) return -1;

    printf("Opening out file...\n");

    FILE *out;

    out = fopen(OUT_FILE_NAME, "w");
    if(out==NULL) {
        printf("Subor %s nieje mozne otvorit!\n", OUT_FILE_NAME);
        return -1;
    }

    char itemName[128];

    char timeStr[128];
    int timeStrEnd = 0;

    float itemPrice;
    while(1) {
        printf("Co by si si rad kupil? ");
        scanf("%s", itemName);
        printf("Hmmm, a kolko to stoji? ");
        scanf("%f", &itemPrice);
        int weeks = 0;
        int days = 0;
        getWeeksAndDays(itemPrice, &weeks, &days);
        timeStrEnd = 0;
        if(weeks>0) {
            timeStrEnd = snprintf(timeStr, 32, "%i %s%s", weeks, weeks==1 ? "tyzden" : weeks>4 ? "tyzdnov" : "tyzdne", days>0 ? " a " : "");
        }
        if(days>0) {
            snprintf(&(timeStr[timeStrEnd]), 32, "%i %s", days, days==1 ? "den" : "dni");
        }
        printf("Tak na to si budes zarabat %s\n", timeStr);

        fprintf(out, "%s - %s\n", itemName, timeStr);
        fflush(out);
    }

}
