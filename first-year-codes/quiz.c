/*
    Leonen, Abbegail Miles
    BSCS-NS-1B 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 10


typedef struct studentRec {
    char stdntname[31];
    int quiz1, quiz2, quiz3;
    float average;
    char remarks[10];
} SDATA;

SDATA stdntData[MAX], temp;
int marker;

void gotoxy(int x, int y);
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
//int sort(char sname[31]);
void getRecord(SDATA *sd);
//void setposition();

int main(){
    SDATA x;
    init();
    retrieve();
    while (1){
        switch(menu()){
            case 1: getRecord(&x);
                    add(x);
                    system("pause");
                    break;
            case 2: system("cls");
                    gotoxy(40,4);printf("Student Name: ");
                    scanf("%s", x.stdntname);
                    update(x.stdntname);
                    break;
            case 3: system("cls");
                    gotoxy(40,4);printf("Input student name you want to delete: ");
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
        gotoxy(40,4);printf("Record is full.\n");
        system("pause");
    } else {
       /*sort(sname);
       for (i=marker;i>=p;i--)
            stdntData[i+1]=stdntData[i];*/
        marker++;
        //setposition();
        stdntData[marker]=sd;
        system("pause");
    }
}

void del(char sname[31]){
    int p, i;
    p = locate(sname);
    if (p<0){
        gotoxy(40,5);printf("Not Found.\n");
        system("pause");
    } else {
        for (i=p;i<marker;i++){
            stdntData[i]=stdntData[i+1];
        }
        marker--;
        gotoxy(40,5);printf("Record successfully deleted.\n");
        system("pause");
    }
}

void display(){
    int i;
    char r;
    system("cls");
    gotoxy(40,5);printf("Name ");
    gotoxy(70,5);printf("Quiz 1 ");
    gotoxy(80,5);printf("Quiz 2 ");
    gotoxy(90,5);printf("Quiz 3 ");
    gotoxy(100,5);printf("Average ");
    gotoxy(110,5);printf("Remarks ");
    for (i=0;i<=marker;i++){
    r = isPassed(stdntData[i].average);
            gotoxy(35,7+i);printf("%d.) ",i+1);
            gotoxy(40,7+i);printf("%s", stdntData[i].stdntname);
            gotoxy(70,7+i);printf("%d", stdntData[i].quiz1);
            gotoxy(80,7+i);printf("%d", stdntData[i].quiz2);
            gotoxy(90,7+i);printf("%d", stdntData[i].quiz3);
            gotoxy(100,7+i);printf("%.2f", stdntData[i].average);
            gotoxy(110,7+i);printf("%s",r? "PASSED":"FAILED");
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
    int i, op;
    system("cls");
    gotoxy(50,6);printf("MENU");
    gotoxy(50,7);printf("1. Add record");
    gotoxy(50,8);printf("2. Update a record");
    gotoxy(50,9);printf("3. Delete record");
    gotoxy(50,10);printf("4. Display All");
    gotoxy(50,11);printf("5. Exit");
    gotoxy(50,12);printf("Select(1-5): ");
    scanf("%d",&op);
    return op;
}

int isPassed(int r){
  return(r>75);
}

void save(){
    FILE *fp;
    int i;
    fp = fopen("studrec.txt","w+");
    if (fp==NULL){
        printf("File error.\n");
        system("pause");
    }
    else {
        for (i=0;i<=marker;i++)
            fprintf(fp,"%s\t%d\t%d\t%d\t%.2f\t%s\n",stdntData[i].stdntname,stdntData[i].quiz1,stdntData[i].quiz2,stdntData[i].quiz3, stdntData[i].average, stdntData[i].remarks);
        fclose(fp);
      }
}

void retrieve(){
    FILE *fp;
    SDATA y;
    fp = fopen("studrec.txt","r+");
    if (fp==NULL){
        gotoxy(40,5);printf("File error.\n");
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
    int p, ans, i;
    char r;
    system("cls");
    p = locate(sname);
    if (p<0){
        gotoxy(40,5);printf("Record not found.\n");
        system("pause");
    } else{
        
    for (i=0;i<=marker;i++)
    gotoxy(40,6);printf("Name ");
    gotoxy(70,6);printf("Quiz 1 ");
    gotoxy(80,6);printf("Quiz 2 ");
    gotoxy(90,6);printf("Quiz 3 ");
    gotoxy(100,6);printf("Average ");
    gotoxy(110,6);printf("Remarks ");

    gotoxy(40,6+i);printf("%s", stdntData[p].stdntname);
    gotoxy(70,6+i);printf("%d", stdntData[p].quiz1);
    gotoxy(80,6+i);printf("%d", stdntData[p].quiz2);
    gotoxy(90,6+i);printf("%d", stdntData[p].quiz3);
    gotoxy(100,6+i);printf("%.2f", stdntData[p].average);
    gotoxy(110,6+i);printf("%s",r? "PASSED":"FAILED");
             r = isPassed(stdntData[p].average);
        stdntData[p].average = (stdntData[p].quiz1+stdntData[p].quiz2+stdntData[p].quiz3)/3.0;
        gotoxy(40,8+i);printf("Which quiz do you want to change?\n");
        gotoxy(40,9+i);printf("Please select from 1 to 3: ");
        scanf("%d", &ans);
        switch (ans) {
        case 1: gotoxy(40,10+i);printf("Input a new data in Q1: ");
                scanf("%d", &stdntData[p].quiz1);
                break;
        case 2: gotoxy(40,10+i);printf("Input a new data in Q2: ");
                scanf("%d", &stdntData[p].quiz2);
                break;
        case 3: gotoxy(40,10+i);printf("Input a new data in Q3: ");
                scanf("%d", &stdntData[p].quiz3);
                break;
        default: break;
            
            //stdntData[p].average = (stdntData[p].quiz1+stdntData[p].quiz2+stdntData[p].quiz3)/3.0;
            display();
            menu();
            //system("cls");
    }
}
}
/*
int sort(char sname[31]){

    char temp;

    for(int i=0; i<marker; i++){
    for(int j=0; j<marker-1-i; j++){
      if(strcmp(sname[j], sname[j+1]) > 0){
        //swap array[j] and array[j+1]
        strcpy(temp, sname[j]);
        strcpy(sname[j], sname[j+1]);
        strcpy(sname[j+1], temp);
      }
    }
  }

}
*/

void gotoxy(int x, int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void getRecord(SDATA *sd){
    system("cls");
    gotoxy(40,5);printf("Student Name: ");
    scanf("%s", sd->stdntname);
    gotoxy(40,6);printf("Quiz 1: ");scanf("%d", &sd->quiz1);
    gotoxy(40,7);printf("Quiz 2: ");scanf("%d", &sd->quiz2);
    gotoxy(40,8);printf("Quiz 3: ");scanf("%d", &sd->quiz3);
    sd->average = (sd->quiz1+sd->quiz2+sd->quiz3)/3.0;
    gotoxy(40,9);printf("Average: %.2f\n", sd->average);
}
/*
void setposition(){
int p, i;
    for(i=marker, p=-1; i>=0; i--){
        if(strcmp(stdntData[marker].stdntname, stdntData[i].stdntname)<0){
            p=i;}
    }
    if(p>=0){
        temp=stdntData[marker]; 
        for(i=marker; i>=p; i--){
            stdntData[i+1]=stdntData[i];
        }
        stdntData[p]=temp;
    }
}
*/
