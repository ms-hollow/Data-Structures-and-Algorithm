/*
    LEONEN, ABBEGAIL MILES
    BSCS-NS-1B
    Write the student record program with file handling and update function.
    MENU
    1. ADD
    2. UPDATE
    3. DELETE
    4. DISPLAY
    5. EXIT
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

char name[MAX][31];
float ave[MAX];
int q1[MAX], q2[MAX], q3[MAX];

int marker;
void init();
void add();
void del(char n[]);
void display();
void getRecord();
int isFull();
int locate(char n[]);
int menu();
void save();
void retrieve();
void update(char n[], int quiz[], int quiz2[], int quiz3[], float a[]);

int main(){
    char n[31];
    init();
    while (1)
    {
        switch(menu()){
            case 1: system("cls");
                    add();
                    break;
            case 2: system("cls");
                    printf("Input student name you want to edit: ");
                    scanf("%s", n);
                    update(n, q1, q2, q3, ave);
                    break;
            case 3: system("cls");
                    printf("Input student name you want to delete: ");
                    scanf("%s", n);
                    del(n);
                    break;
            case 4: system("cls");
                    display();
                    break;
            case 5: save(); exit(0);
            default:
                    printf("Please select from 1 to 5.\n");
                    system("pause");
        }
    }
    retrieve();
    return 0;
}

void getRecord(int i){

    printf("\nInput Student name: ");
    scanf(" %[^\n]s", name[i]);
    printf("Input Quiz1: ");
    scanf("%d",&q1[i]);
    printf("Input Quiz2: ");
    scanf("%d",&q2[i]);
    printf("Input Quiz3: ");
    scanf("%d",&q3[i]);

    ave [i]= (q1[i]+q2[i]+q3[i])/3.0;
    printf("Average: %.2f\n\n", ave[i]);
}

void init(){
  marker = -1;
}

void add(){
if (isFull()){
    printf("Record is full.\n");
    system("pause");
  } else {
    marker++;
    getRecord(marker);
    printf("Data is successfully added.\n");
    system("pause");
   }
}

void del(char n[]){
int i,p;
p = locate(n);
if (p<0){
    printf("Not found.\n");
    system("pause");
   }
else {
    for (i=p; i<marker;i++){
       strcpy(name[i], name[i+1]);
            q1[i]= q1[i+1];
            q2[i]= q2[i+1];
            q3[i]= q3[i+1];
            ave[i]= ave[i+1];
    }
    marker--;
    printf("Data is successfully deleted.\n");
    system("pause");
}
}

void display(){
    int i;
    system("cls");
    printf("   NAME\t\tQ1\tQ2\tQ3\tAve\tRemarks\n");
    for (i=0;i<=marker;i++)
    printf("%d.) %s\t%2d\t%2d\t%2d\t%.2f\t%s\n",i+1,name[i],q1[i],q2[i],q3[i],ave[i],ave[i]>=75? "PASSED":"FAILED");
    system("pause");
}

int isFull(){
    if (marker==MAX-1)
        return 1;
    else
        return 0;
}

int locate(char n[]){
    int i;
    for (i=0;i<=marker;i++)
    if (strcmp(name[i],n)==0)
        return i;
    return -1;
}

int menu(){
    int op;
    system("cls");
    printf("MENU\n");
    printf("1. Add a Record\n");
    printf("2. Update record. \n");
    printf("3. Delete a Record\n");
    printf("4. Display All Records\n");
    printf("5. Exit\n");
    printf("Select(1-5): ");
    scanf("%d",&op);
    return op;
}

void save(){
    FILE *fp;
    int i;
    fp = fopen("StudentRecord.txt", "w+");
    if (fp==NULL){
        printf("File Error.\n");
        system("pause");
    } else{
        for (i=0;i<=marker;i++)
         fprintf(fp, "%d.) %s\t%2d\t%2d\t%2d\t%.2f\t%s\n",i+1,name[i],q1[i],q2[i],q3[i],ave[i],ave[i]>=75? "PASSED":"FAILED");
         fclose(fp);
    }
}

void retrieve(){
    FILE *fp;
    char n[31];
    int i;
    fp = fopen("StudentRecord.txt", "r+");
    if (fp==NULL){
        printf("File Error.\n");
        system("pause");
    } else{
        while(!feof(fp)){
            fscanf(fp, "%d.) %s\t%2d\t%2d\t%2d\t%.2f\t%s\n",i+1,name[i],q1[i],q2[i],q3[i],ave[i],ave[i]>=75? "PASSED":"FAILED");
            add();
        }
        fclose(fp);
    }
}

void update(char n[], int quiz[], int quiz2[], int quiz3[], float a[]){
    int p, ans, score;
    p = locate(n);

    if (p<0) {
        printf("Not Found.\n");
        system("pause");
    } else {
        printf("Name: %s\n", name[p]);
        printf("Quiz 1: %d\n", q1[p]);
        printf("Quiz 2: %d\n", q2[p]);
        printf("Quiz 3: %d\n", q3[p]);
        printf("Average: %.2f\n", ave[p]);
        printf("Which quiz do you want to change?\n");
        printf("Please select from 1 to 3: ");
        scanf("%d", &ans);

        if (ans==1) {
            printf("Input a new data in Q1: ");
            scanf("%d", &q1[p]);
            ave [p]= (q1[p]+q2[p]+q3[p])/3.0;
            display();
        } else if (ans==2) {
            printf("Input a new data in Q2: ");
            scanf("%d", &q2[p]);
            ave [p]= (q1[p]+q2[p]+q3[p])/3.0;
            display();
        } else if (ans==3) {
            printf("Input a new data in Q3: ");
            scanf("%d", &q3[p]);
            ave [p]= (q1[p]+q2[p]+q3[p])/3.0;
            display();
        } else;
        }
}
