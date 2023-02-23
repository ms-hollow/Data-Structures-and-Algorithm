//Leonen, Abbegail Miles
//BSCS-NS-2B
/*
Write the Student Record Program using the pointer implementation of Lists (link lists) with file handling in C and C++

MENU
1. Add record
2. Delete record
3. Display All
4. Exit
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


typedef struct record {
    char name[31];
    int a, b, c;
} REC;

typedef struct node {
    REC r;
    struct node* nxt;
} LIST;

LIST *L;
void makenull();
void insert(REC r);
void del(char n[31]);
void display();
void save();
void retrieve();
int menu();
int isEmpty();


int main(){
    REC x;
    makenull();
    retrieve();
    while(1){
        switch(menu()){
        case 1: system("cls"); printf("Insert Mode\n");
                printf("Input name: "); scanf("  %[^\n]s", x.name);
                printf("Quiz 1: "); scanf("%d", &x.a);
                printf("Quiz 2: "); scanf("%d", &x.b);
                printf("Quiz 3: "); scanf("%d", &x.c);
                insert(x); break;
        case 2: system("cls"); printf("Delete Mode\n");
                printf("Input name: "); scanf("  %[^\n]s", x.name); del(x.name); break;
        case 3: display();break;
        case 4:  save(); exit(0);
        }
    }
}

void makenull(){
    L = NULL;
}

int isEmpty(){
    return(L==NULL);
}

void insert(REC r){
    LIST *p, *q, *temp;
    p=q=L;
    int i;
    char n[31];
    temp = (LIST*)((malloc(sizeof(LIST))));
    temp->r = r;
    (temp->r.name,r.name);

    while(p!=NULL && p->r.name<r.name){
        q = p;
        p = p->nxt;
    }
    if (p==L)
        L = temp;
    else
        q->nxt = temp;
    temp->nxt = p;
}

void del(char n[31]){
    LIST *p, *q;
    p=q=L;
    if (isEmpty()){
        printf("List is empty");
        system("pause");
    }
    while(p!=NULL && strcmp(p->r.name,n)!=0){
        q=p;
        p=p->nxt;
    }
    if(p==NULL){
        printf("Record not Found.\n");
        system("pause");
    }
    else{
        if(L==p)
            L=p->nxt;
        else
            q->nxt=p->nxt;
        free(p);
        printf("Record successfully deleted \n");
    }
    system("pause");
}

void display(){
    LIST *p;
    int i=1;
    float ave;
    p = L;
    system("cls");
    printf("Name       Q1 Q2 Q3  AVE    REMARKS\n");

    while (p!=NULL){
        ave = (p->r.a+p->r.b+p->r.c)/3.0;
        printf("%d). %s   %d %d %d %0.2f  %s\n",i++,p->r.name,p->r.a,p->r.b,p->r.c,ave, ave>=75? "PASSED":"FAILED");
        p=p->nxt;
    }
    system("pause");
}


int menu(){
    int op;
    system("cls");
    printf("MENU\n");
    printf("[1] Insert Record\n");
    printf("[2] Delete Record\n");
    printf("[3] Display Record\n");
    printf("[4] Exit\n");
    printf("Select from 1-4: ");
    scanf("%d",&op);
    return(op);
}

void save(){
    FILE *fp = fopen("list.txt", "w+");
    LIST *p;
    p=L;
    while (p!=NULL){
        fprintf(fp,"%s %d %d %d\n",p->r.name,p->r.a,p->r.b,p->r.c);
        p=p->nxt;
    }
    fclose(fp);
}


void retrieve(){
    FILE *fp = fopen("list.txt", "r+");
    REC y;
    if(fp==NULL){
        printf("File Error");
    }
    while (!feof(fp)){
        fscanf(fp,"%s", &y.name);
        fscanf(fp,"%d %d %d\n", &y.a, &y.b, &y.c);
        insert(y);
    }
    fclose(fp);
}
