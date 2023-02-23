#include <stdio.h>
#include <stdlib.h>
#define MAX 2

void getRecord();
void Display();

    //GLOBAL VARIABLE
    int q1[MAX],q2[MAX],q3[MAX];
    float ave;
    int i;
    char name[MAX][31];

int main(){
    getRecord();
    Display();
    return 0;
}

void getRecord(){
    int i;
    for (i=0;i<MAX;i++){
    printf("\nInput name: ");
    scanf(" %[^\n]s", name[i]);
    printf("Input Quiz1: ");
    scanf("%d",&q1[i]);
    printf("Input Quiz2: ");
    scanf("%d",&q2[i]);
    printf("Input Quiz3: ");
    scanf("%d",&q3[i]);
    }
}

//results in tabular form
void Display(){
system("cls");
int i;
printf("   NAME\t\tQ1\tQ2\tQ3\tAve\tRemarks\n");
for (i=0;i<MAX;i++){
    ave = (q1[i]+q2[i]+q3[i])/3.0;
    printf("%d.) %s\t%d\t%d\t%d\t%6.2f\t%s\n",i+1,name[i],q1[i],q2[i],q3[i],ave,ave>=75? "PASSED":"FAILED");
    }
}