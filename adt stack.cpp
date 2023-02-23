/*
    LEONEN, ABBEGAIL MILES
    BSCS-NS-2B

    Implement the ADT STACK operations (Array of integers) using a class (MyStack) in C++.

     Menu
    1. Push
    2. Pop
    3. Display
    4. Exit

*/

#include <iostream>
#include <conio.h>
#include <cstdlib>

#define MAX 10

using namespace std;

typedef struct stack{
    int S[MAX];
    int top;
}STACK;

class MyStack{
    private:
    STACK S;
    int value[MAX];
    int isEmpty();
    int isFull();
    public:
    void makenull();
    void push(int v); 
    void pop();
    void display();
};

int menu();

int main(){
    
    MyStack s;
    int input;
    s.makenull();

    while(1){
        switch(menu()){
            case 1: system("cls"); cout<<"\nEnter an integer: "; cin>>input; s.push(input); break;
            case 2: s.pop(); break;
            case 3: s.display(); break;
            case 4: exit(0);

        }
    }
    return 0;
}

int MyStack::isFull(){
    return(S.top==0);
}

int MyStack::isEmpty(){
    return(S.top==MAX);
}

void MyStack::makenull(){
    S.top = MAX;
}

/**
 * Funtion: push
 * Description: Function that will push/add the value on the stacks 
 */
void MyStack::push(int v){

    if(isFull()){
        cout<<"\nStack Overflow";
        getch();
    }
    else{
        cout<<"\nValue is added to the stack";
        S.top--;
        S.S[S.top] = v;
    }
    cout<<'\n'; system("pause");
}

/**
 * Funtion: pop
 * Description: Function that will pop/delete the value on the stacks 
 */
void MyStack::pop(){

    if(isEmpty()){
        cout<<"\nStack is empty";
        getch();
    }
    else{
        cout<<"\nThe value is remove.";
        S.top++;
    }
    cout<<'\n'; system("pause");
}

void MyStack::display(){
    
    int i, j = 1;
    system("cls");
    printf("\nThe stack contains: \n");
    for(i=S.top;i<MAX;i++)
        cout<<j++<<".) "<<S.S[i]<<'\n';
    getch();
}

int menu(){
int ch;
system("cls");
cout<<"MENU\n";
cout<<"[1] Push\n";
cout<<"[2] Pop\n";
cout<<"[3] Display\n";
cout<<"[4] Exit\n";
cout<<"Select (1-4): "; cin>>ch;
return(ch);
}
