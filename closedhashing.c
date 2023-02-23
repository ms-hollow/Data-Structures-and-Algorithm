/**
 *  lEONEN, ABBEGAIL MILES
 *  BSCS-NS-2B
 *  Closed Hashing (Open Addressing)
 *  Linear probing was used when there's a collision or
 *  if the element was already occupied. 
 *  k = (k+i) % MAX
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10 

int bucket[MAX]={NULL};

void insert(int key){

    int i;
    
    int keyVal = hash(key);
    for (i=0;i<MAX;i++) {

        keyVal = (keyVal+i) % MAX; //if there is collision or already an element at that index

        if(bucket[keyVal] == NULL){
            bucket[keyVal] = key;
            break;
        }
    }
    if(i == MAX){
        printf("Array is full.\n");
    }
}

int hash(int key){
    return (key % MAX);
}

void del(int key){

    int i;
    int keyVal = hash(key);
    for(i=0;i<MAX; i++)
    {
        keyVal=(keyVal+i)%MAX; //if there is collision or already an element at that index
        if(bucket[keyVal]==key) {
        bucket[keyVal]=NULL;
        break;
        }
    }
    if(i == MAX)
        printf("\nValue is not found\n");
}

void display(){
    int i;
    printf("\nElements in the hash table are \n");
    printf("\n%-5s %-6s\n", "Key", "Value");
    for(i=0;i< MAX; i++)
    printf("\n%-5d: %-5d",i,bucket[i]);
    printf("\n");
    system("pause");
}

int menu(){
    int ch;
    system("cls");
    printf("MENU\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Select option (1-3): ");
    scanf("%d", &ch);
    return ch;
}

int main(){

    int  x;
    while(1){
    switch(menu())
        {
            case 1: system("cls"); printf("\nInsert a number: "); scanf("%d", &x); insert(x); system("pause"); system("cls"); break;
            case 2: system("cls"); printf("\nInsert a number: "); scanf("%d", &x); del(x); system("pause"); system("cls"); break;
            case 3: system("cls"); display(); break;
            case 4:exit(0);
        }
    }
    return 0;
}