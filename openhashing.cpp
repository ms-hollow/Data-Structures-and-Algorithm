/**
 *  LEONEN, ABBEGAIL MILES
 *  BSCS-NS-2B
 *  Open Hashing(Closed Addressing)/Separate Chaining
 *  The program uses a linked list for execution.
 */

#include <iostream>
#define MAX 10

using namespace std;

typedef struct node{
    int x;
    struct node *nxt;
}NODE;

NODE *bucket[MAX];

void init();
int hashFunc(int key);
void insert(int key);
int del(int key);
void display();
int menu();

int main(){
    //init array of list to NULL
    init();
    int  input;
    while(1){
    switch(menu())
        {
            case 1: system("cls"); cout<<"\nInsert a number: "; cin>>input; insert(input); system("pause"); system("cls"); break;
            case 2: system("cls"); cout<<"\nInsert a number: "; cin>>input; del(input); system("pause"); system("cls"); break;
            case 3: system("cls"); display(); break;
            case 4: exit(0);
        }
    }
    return 0;
}

void init(){
    for(int i=0; i<MAX; i++)
        bucket[i] = NULL;
}

int hashFunc(int key){
    return (key%MAX);
}


void insert(int key)
{
    //create a newnode with value
    NODE *newNode = new NODE;
    newNode->x= key;
    newNode->nxt = NULL;

    //get the calculated hash key
    int keyVal = hashFunc(key);

    //check if bucket is empty
    if(bucket[keyVal] == NULL)
        bucket[keyVal] = newNode;
    //collision
    else
    {
        //add the node at the end of bucket.
        struct node *temp = bucket[keyVal];
        while(temp->nxt)
        {
            temp = temp->nxt;
        }

        temp->nxt = newNode;
    }
}

int del(int key){
    int keyVal = hashFunc(key);
    NODE *temp =bucket[keyVal], *dealloc;
    if(temp != NULL)
    {
        if(temp->x== key)
        {
            dealloc = temp;
            temp = temp->nxt;
            free(dealloc);
            return 1; //successful delete
        }
        else
        {
            while(temp->nxt)
            {
                if(temp->nxt->x == key)
                {
                    dealloc = temp->nxt;
                    temp->nxt = temp->nxt->nxt;
                    free(dealloc);
                    return 1;//successful delete
                }
                temp = temp->nxt;
            }
        }
    }
    return 0; //value not found
}


void display(){
    int i;
    cout<<"Elements in the hash table\n";
    for(i = 0; i <MAX ; i++)
    {
        NODE *temp = bucket[i];
        cout<<i<<" -> ";
        while(temp)
        {
            cout<<temp->x<<" -> ";
            temp = temp->nxt;
        }
        printf("NULL\n");
    }
    system("pause");
}

int menu(){
    int ch;
    system("cls");
    cout<<"MENU\n";
    cout<<"1. Insert\n";
    cout<<"2. Delete\n";
    cout<<"3. Display\n";
    cout<<"4. Exit\n";
    cout<<"Select option (1-3): ";
    cin>>ch;
    return ch;
}