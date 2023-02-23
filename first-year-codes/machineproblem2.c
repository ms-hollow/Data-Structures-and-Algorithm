//Leonen, Abbegail Miles
//BSCS-NS-1B

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

int marker;
void init();
void add();
void del(char n[]);
void display();
void getRecord(int i);
int isFull();
int locate(char n[]);
int menu();
int q1[MAX],q2[MAX],q3[MAX];
float ave[MAX];
char name[MAX][31];

int main(){
char n[31];
init();
while (1){
    switch(menu()){
    case 1: system("cls");
            add();
            break;
    case 2: system("cls");
            printf("Input student name: ");
            scanf(" %[^\n]s",n);
            del(n);
            break;
    case 3: system("cls"); 
            display();
            break;
    case 4: exit (0);
    default: 
            printf("Please pick from 1 to 4.\n");
            system("pause");
    }
}
return 0;
}


void getRecord(int i){
  
    printf("\nInput name: ");
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
//return (marker==MAX-1)
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
printf("2. Delete a Record\n");
printf("3. Display All Records\n");
printf("4. Exit\n");
printf("Select(1-4): ");
scanf("%d",&op);
return op;
}