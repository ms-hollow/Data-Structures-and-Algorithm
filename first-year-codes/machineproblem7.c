//LEONEN, ABBEGAIL MILES
//BSCS-NS-1B
//Write the student record program with file handling using link list with records added in a sorted list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>


typedef struct Student{
    char name[31];
    int quiz1,quiz2,quiz3;
    struct Student *next;
} STDNT;

STDNT *head;
void init();
void add(char* name, int quiz1, int quiz2, int quiz3);
void del(char name[31]);
void display();
int isEmpty();
int menu();
void save();
void retrieve();


int main(){

    STDNT x;
    init();
    retrieve();
    while(1){
        switch(menu()){
            case 1: system("cls");gotoxy(50,6);printf("Add Mode");
                    gotoxy(50,7);printf("Student Name: "); scanf(" %[^\n]s", x.name);
                    gotoxy(50,8);printf("Enter Quiz 1: "); scanf("%d", &x.quiz1);
                    gotoxy(50,9);printf("Enter Quiz 2: "); scanf("%d", &x.quiz2);
                    gotoxy(50,10);printf("Enter Quiz 3: "); scanf("%d", &x.quiz3);
                    add(x.name,x.quiz1, x.quiz2, x.quiz3); break;
            case 2: system("cls");gotoxy(50,6);printf("Delete Mode");
                    gotoxy(50,7);printf("Student Name: "); scanf("  %[^\n]s", x.name);
                    del(x.name);
            case 3: display();break;
            case 4: save(); exit(0);
            default:gotoxy(50,13);printf("1 to 4 only."); system("pause");

        }
    }
    return 0;
}

void init(){
    head = NULL;
}

void add(char* name, int quiz1, int quiz2, int quiz3){

    STDNT *p, *q, *n, *temp;
    char nm[31];
    int i;
    p=q=head;
    n = (STDNT*)malloc(sizeof(STDNT));
    strcpy(n->name, name);
    n->quiz1 = quiz1;
    n->quiz2 = quiz2;
    n->quiz3 = quiz3;
    //n->next = NULL;

    while (p!=NULL && strcmp(n->name,p)>0){
        q=p;
        p=p->next;
    }
    if (head==p) //locate the last element in the list
        head = n;
    else
    q->next = n;//kung hawak ni q
    n->next = p;

    gotoxy(50,11);system("pause");
}

void del(char n[31]){
    STDNT *p, *q;
    p=q=head;
    if (isEmpty()){
        gotoxy(50,5);printf("List is empty.");
        system("pause");
    }
    else{
        while(p!=NULL && strcmp(n,p->name)<0){
            q=p;
            p=p->next;
        }
            if(p==NULL){
                gotoxy(50,6);printf("Not found.");
                system("pause");
            }
                else{
                    if (head==p)
                        head=p->next;
                        else
                            q->next = p->next;
                                free(p);
                }
    }
}

void display(){
    STDNT *p;
    int i=1;
    float ave;
    p = head;
    system("cls");
    gotoxy(35,5);printf("Name       Q1 Q2 Q3  AVE    REMARKS");

    while (p!=NULL){
        ave = (p->quiz1+p->quiz2+p->quiz3)/3.0;
        gotoxy(35,7+i);printf("%d). %s   %d %d %d %0.2f  %s",i++,p->name,p->quiz1,p->quiz2,p->quiz3,ave, ave>=75? "PASSED":"FAILED");
        p=p->next;
    }
     gotoxy(40,10+1);system("pause");
}

int isEmpty(){
    return(head==NULL);
}

int menu(){
    int i, op;
    system("cls");
    gotoxy(50,6);printf("MENU");
    gotoxy(50,7);printf("1. Add record");
    gotoxy(50,8);printf("2. Delete record");
    gotoxy(50,9);printf("3. Display All");
    gotoxy(50,10);printf("4. Exit");
    gotoxy(50,11);printf("Select(1-5): ");
    scanf("%d",&op);
    return op;
}

void save(){
    FILE *fp = fopen("list.txt", "w+");
    STDNT *p;
    p=head;
    while (p!=NULL){
        fprintf(fp, "%s %d %d %d\n", p->name, p->quiz1, p->quiz2, p->quiz3);
        p=p->next;
    }
    fclose(fp);
}

void retrieve(){
    FILE *fp = fopen("list.txt", "r+");
    STDNT x;
    while (!feof(fp)){
        fscanf(fp,"%s", &x.name);
        fscanf(fp,"%d %d %d\n", &x.quiz1, &x.quiz2, &x.quiz3);
        add(x.name, x.quiz1, x.quiz2, x.quiz3);
    }
    fclose(fp);
}

void gotoxy(int x,int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}