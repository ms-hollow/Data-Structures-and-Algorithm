/**
 * Abbegail Miles Leonen
 * BSCS-NS-2B
 * Implement ADT Queue (circular array of integers) using a class (MyQueue) in C++.

    Menu
    1. Enqueue
    2. Dequeue
    3. Display
    4. Exit
 * 
 */
#include <iostream>
#include <conio.h>
#include <cstdlib>

#define MAX 5
using namespace std;

typedef struct queue{
    int DATA[MAX];
    int front;
    int rear;
    int count;
}QUEUE;


class MyQueue{
    private:
    QUEUE Q;
    int value[MAX];
    int isEmpty();
    int isFull();
    public:
    int peek();
    void makenull();
    void enqueue(int v);
    void dequeue(int v);
    void display();
};

int menu();

int main(){

    MyQueue q;
    int input;
    q.makenull();
    
    while(1){
        switch(menu()){
            case 1: cout<<"\nEnter an integer: "; cin>>input; q.enqueue(input); break;
            case 2: system("cls"); q.dequeue(input); break;
            case 3: system("cls"); cout<<"QUEUE: \n";q.display(); break;
            case 4: exit(0);

        }
    }
    return 0;
}

void MyQueue::makenull(){
     Q.count = 0; Q.front = 0; Q.rear = -1;
}

int MyQueue::isFull(){
    return(Q.count == MAX);
}

int MyQueue::isEmpty(){
    Q.count==0; return Q.front;
}

void MyQueue::enqueue(int v){
    
    if(isFull()){
        cout <<"Queue is full!\n";
        system("pause");
    }

    else{
        if(Q.front==-1){
            Q.front=0;
        }
        Q.rear= (Q.rear+1)%MAX;
        Q.DATA[Q.rear]=v;
        Q.count++;
    }
    system("pause");
}

void MyQueue::dequeue(int v){
    
    if(isEmpty()){
        printf("\nQueue is empty.");
        getch();
    } else{
        int v = Q.DATA[Q.front];
        cout<<"\nItem "<<v<<" is remove"<<endl;
        Q.count--;
    }
    system("pause");
}

void MyQueue::display(){
    int i;
    if(isEmpty()){
        cout <<"Queue is Empty\n";
    }
    else{
        if(Q.front <=Q.rear){
            for(i=Q.front; i<=Q.rear; i++){
                cout <<Q.DATA[i] <<"\n";
            }
        }

        else{
            i=Q.front;
            while(i<MAX){
                cout <<Q.DATA[i] <<"\n";
                i++;
            }
            i=0;
            while(i<=Q.rear){
                cout <<Q.DATA[i]<<"\n";
                i++;}
        }
    }
    system("pause");
}

int menu(){
int ch;
system("cls");
cout<<"MENU\n";
cout<<"[1] Enqueue\n";
cout<<"[2] Dequeue\n";
cout<<"[3] Display\n";
cout<<"[4] Exit\n";
cout<<"Select (1-4): "; cin>>ch;
return(ch);
}
