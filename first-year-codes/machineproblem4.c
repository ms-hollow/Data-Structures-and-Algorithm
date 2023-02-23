//LEONEN, ABBEGAIL MILES
//BSCS-NS-1B
/*
    Instructions
    Modify your Student Record Program to include file handling with update operation 
    and records sorted according to names using ARRAY OF STRUCTURES.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct studentRec {
    char stdntname[31];
    int quiz1, quiz2, quiz3;
    float average;
    char remarks[10];
} SDATA;

SDATA stdntData[MAX];
int marker;

void init();
void add(SDATA sd);
void del(char sname[31]);
void display();
int isFull();
int locate(char sname[31]);
int menu();
void save();
void retrieve();
void update(char sname[31]);
int isPassed(int r);
int searchPos(char sname[31]);


int main(){
    SDATA x;
    init();
    retrieve();
    while (1){
        switch(menu()){
            case 1: system("cls");
                    printf("Student Name: ");
                    scanf("%s", &x.stdntname);
                    printf("Quiz 1: ");scanf("%d", &x.quiz1);
                    printf("Quiz 2: ");scanf("%d", &x.quiz2);
                    printf("Quiz 3: ");scanf("%d", &x.quiz3);
                    x.average = (x.quiz1+x.quiz2+x.quiz3)/3.0;
                    printf("Average: %.2f\n", x.average);
                    add(x);
                    break;
            case 2: system("cls");
                    printf("Student Name: ");
                    scanf("%s", x.stdntname);
                    update(x.stdntname);
                    break;
            case 3: system("cls");
                    printf("Input student name you want to delete: ");
                    scanf("%s", x.stdntname);
                    del(x.stdntname);
                    break;
            case 4: display(); break;
            case 5: save(); exit(0);
            default:
                    printf("Please select from 1 to 5.\n");
                    system("pause");
        }
    }
    return 0;
}

void init(){
    marker = -1;
}

void add(SDATA sd){
    int i, p;
    char sname[31];
    if (isFull()){
        printf("Record is full.\n");
        system("pause");
    } else {
        p = searchPos(sname);
        for (i=marker;i>=p;i--){
            stdntData[i+1]=stdntData[i];
        }
        marker++;
        stdntData[marker]=sd;
        system("pause");
    }
}

void del(char sname[31]){
    int p, i;
    p = locate(sname);
    if (p<0){
        printf("Not Found.\n");
        system("pause");
    } else {
        for (i=p;i<marker;i++){
            stdntData[i]=stdntData[i+1];
        }
        marker--;
        printf("Record successfully deleted.\n");
        system("pause");
    }
}

void display(){
    int i;
    char r;
    system("cls");
    printf("   NAME\t\tQ1\tQ2\tQ3\tAve\tRemarks\n");
    for (i=0;i<=marker;i++){
    r = isPassed(stdntData[i].average);
    printf("%d.) %s\t%2d\t%2d\t%2d\t%.2f\t%s\n",i+1,stdntData[i].stdntname,stdntData[i].quiz1,stdntData[i].quiz2,
            stdntData[i].quiz3,stdntData[i].average,r? "PASSED":"FAILED");
    }
    system("pause");
}

int isFull(){
    if (marker==MAX-1)
        return 1;
    else
        return 0;
}

int locate(char sname[31]){
    int i;
    for (i=0;i<=marker;i++)
        if (strcmp(stdntData[i].stdntname, sname)==0)
              return i;
    return -1;
}

int menu(){
    int op;
    system("cls");
    printf("MENU\n");
    printf("1. Add record\n");
    printf("2. Update a record\n");
    printf("3. Delete record\n");
    printf("4. Display All\n");
    printf("5. Exit\n");
    printf("Select(1-5): ");
    scanf("%d",&op);
    return op;
}

int isPassed(int r){
  return(r>75);
}

void save(){
    FILE *fp;
    int i;
    fp = fopen("SRECORDS.txt","w+");
    if (fp==NULL){
        printf("File error.\n");
        system("pause");
    }
    else {
        for (i=0;i<=marker;i++)
            fprintf(fp,"%s\t%d\t%d\t%d\t%f\t%s\n",stdntData[i].stdntname,stdntData[i].quiz1,stdntData[i].quiz2,stdntData[i].quiz3, stdntData[i].average, stdntData[i].remarks);
        fclose(fp);
      }
}

void retrieve(){
    FILE *fp;
    SDATA y;
    fp = fopen("SRECORDS.txt","r+");
    if (fp==NULL){
        printf("File error.\n");
        system("pause");
      }
    else {
        while (!feof(fp)){
            fscanf(fp,"%s\t%d\t%d\t%d\t%f\t%s\n", y.stdntname,&y.quiz1,&y.quiz2,&y.quiz3, &y.average, y.remarks);
            add(y);
        }
        fclose(fp);
      }
}

void update(char sname[31]){
    int p, ans;
    p = locate(sname);
    if (p<0){
        printf("Record not found.\n");
        system("pause");
    } else{
        printf("Name: %s\n", stdntData[p].stdntname);
        printf("Quiz 1: %d\n", stdntData[p].quiz1);
        printf("Quiz 2: %d\n", stdntData[p].quiz2);
        printf("Quiz 3: %d\n", stdntData[p].quiz3);
        printf("Average: %.2f\n", stdntData[p].average);
        stdntData[p].average = (stdntData[p].quiz1+stdntData[p].quiz2+stdntData[p].quiz3)/3.0;
        printf("Which quiz do you want to change?\n");
        printf("Please select from 1 to 3: ");
        scanf("%d", &ans);
        switch (ans) {
        case 1: printf("Input a new data in Q1: ");
                scanf("%d", &stdntData[p].quiz1);
                break;
        case 2: printf("Input a new data in Q2: ");
                scanf("%d", &stdntData[p].quiz2);
                break;
        case 3: printf("Input a new data in Q3: ");
                scanf("%d", &stdntData[p].quiz3);
                break;
        default: break;
            }
            //stdntData[p].average = (stdntData[p].quiz1+stdntData[p].quiz2+stdntData[p].quiz3)/3.0;
            display();
            //system("cls");
    }
}


int searchPos(char sname[31]){
    int i, j;
    for(i=0;i<=marker;i++)
        for(j=i-1;j<=marker;j++)
        {
            if(strcmp(stdntData[i].stdntname, stdntData[j].stdntname)<=0)
            {
                    strcpy(stdntData[i].stdntname,stdntData[j].stdntname);
                    return i;
            }
        }
}