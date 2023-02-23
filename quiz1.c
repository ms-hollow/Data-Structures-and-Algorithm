//Leonen, Abbegail Miles
//BSCS-NS-2B

/*Write the Student Record Program (name, q1,q2,q3,ave,remarks - use array of structures) 
using List Operations (INSERT, DELETE, DISPLAY)  in C.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct rec{
    char name[31];
    int quiz1, quiz2, quiz3;
} rec; // struct var type

rec list[MAX]; // array of struct
int marker;

void init();
void insert(rec sr);
void delete(char name[31]);
void display();
int locate(char n[31]);
int pos(char n[31]);
int isFull();
int menu();

int main(){
    rec rcrd;
    init();
    while(1){
        switch (menu()){
        case 1: system("cls");
                printf("Input student name: "); scanf("%s", rcrd.name);
                printf("Input quiz 1: "); scanf("%d", &rcrd.quiz1);
                printf("Input quiz 2: "); scanf("%d", &rcrd.quiz2);
                printf("Input quiz 3: "); scanf("%d", &rcrd.quiz3);
                float ave = (rcrd.quiz1 + rcrd.quiz2 + rcrd.quiz3) /3.0;
                printf("Average = %0.2f\n", ave);
                insert(rcrd);
                break;
        
        case 2: system("cls");
                printf("Input student name: ");
                scanf("%s", rcrd.name);
                delete(rcrd.name);
                break;

        case 3: system("cls");
                display();
                break;
        
        case 4: exit(0);

        default:
                printf("Select from 1 to 5. \n");
                system("pause");
            break;
        }
    }
}

void init(){
    marker = -1;
}

int isFull(){
    if (marker==MAX-1)
        return 1;
    else
        return 0;
}

int isPassed(int r){
  return(r>=75);
}

int locate(char n[31]){
    int i;
    for(i=0;i<marker;i++)
        if(strcmp(list[i].name, n)==0);
            return i;
    return -1;
}


void insert(rec sr){

    int i, p;
    char name[31];
    
    if(isFull()){
        printf("List is full.\n");
        system("pause");
    } else {
        p = locate(sr.name);
        for(i=marker;i>=p;i--)
            list[i+1]=list[i];
    }
    list[p]=sr;
    marker++;
    system("pause");
}

void delete(char name[31]){
    int p, i;
    p = locate(name);
    if (p<0){
        printf("name not found.\n");
        system("pause");
    } else{
        for(i=p;i<marker;i++)
            list[i]=list[i+1];
    } 
    marker--;
    printf("Record successfully deleted.\n");
    system("pause");
}

void display(){
    int i;
    char r;
    printf("    NAME\tQUIZ1\tQUIZ2\tQUIZ3\tAVE\tREMARKS\n");
    for(i=0;i<=marker;i++){
        float ave = (list[i].quiz1 + list[i].quiz2 + list[i].quiz3) /3.0;
        r = isPassed(ave);
        printf("%d). %s\t%2d\t%2d\t%2d\t%0.2f\t%s\n", i+1, list[i].name, list[i].quiz1, list[i].quiz2, list[i].quiz3, ave, r? "PASSED":"FAILED");
    }
    system("pause");
}

int menu(){
    int op;
    system("cls");
    printf("MENU\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Select from 1 to 4: ");
    scanf("%d",&op);
    return op;
}

int pos(char n[31]){
    int i;
    for (i=0;i<=marker;i++)
    if (strcmp(list[i].name,n)>0)
        return i;
    return i;
}