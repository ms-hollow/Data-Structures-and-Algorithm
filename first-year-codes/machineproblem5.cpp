//LEONEN, ABBEGAIL MILES
//BSCS-NS-1B
//Write the Student Record Program (name, q1,q2,q3,ave,remarks) in CPP using OOP.

#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 5

class StudentRec{
    private:
        string name[MAX];
        int q1[MAX], q2[MAX], q3[MAX];
        int marker;
        bool isFull();
        int locate(string n);
    public: 
        void init();
        void add(string n, int q1, int q2, int q3);
        void del(string n);
        void display();
};

int menu();

int main(){
    StudentRec x; 
    string sname;
    int ch, quiz1, quiz2, quiz3;
    x.init();
    while(true){
        ch = menu();
        switch(ch){
            case 1: system("cls");cout << "Input Student Name: ";cin >> sname;cout << "Quiz 1: ";cin >> quiz1;
            cout << "Quiz 2: ";cin >> quiz2;cout << "Quiz 3: "; cin >> quiz3;x.add(sname, quiz1, quiz2, quiz3);break;
            case 2: system("cls");cout <<"Input Student Name: ";cin >> sname;x.del(sname);break;
            case 3: x.display();break;
            case 4: exit(0);
            default: cout <<"Select from 1 to 4!"<<endl;system("pause");
        }
    }
}

int menu(){
    int op;
    system("cls");
    cout << "MENU\n";
    cout << "[1] Add Record\n";
    cout << "[2] Delete Record\n";
    cout << "[3] Display Record\n";
    cout << "[4]  Exit\n";
    cout << "Select from 1 to 4!: ";
    cin >> op;
    return op;
}

bool StudentRec::isFull(){
    return (marker==MAX-1);
}

int StudentRec::locate(string n){
    for (int i = 0;i<=marker;i++)
        if (name[i]==n)
            return i;
    return -1;
}

void StudentRec::init(){
    marker = -1;
}

void StudentRec::add(string n, int a, int b, int c){
    if (isFull()){
        cout << "Record is Full";
        system("pause");
    } else{
        marker++;
        name[marker] = n;
        q1[marker] = a;
        q2[marker] = b;
        q3[marker] = c;
        cout <<"Record added successfully\n";
        system("pause");
    }
}

void StudentRec::del(string n){
    int p, i;
    p = locate(n);

    if (p<0){
        cout << "Record Not Found.";
        system("pause");
    } else{
        for (i=p;i<marker;i++){
            name[i]=name[i+1];
            q1[i]= q1[i+1];
            q2[i]= q2[i+1];
            q3[i]= q3[i+1];
        }
        marker--;
    }
}

void StudentRec::display(){
    int i;
    float ave;
    system("cls");
    cout << "   NAME    QUIZ1   QUIZ2   QUIZ3   AVE     REMARKS"<<endl;
    for (i=0;i<=marker;i++){
        ave = (q1[i] + q2[i] + q3[i])/3.0;
        cout<<i+1<<".) "<<name[i]<<"    "<<q1[i]<<"     "<<q2[i]<<"     "<<q3[i]<<"     "<<setprecision(2)<<ave<<"   ";ave>=75? cout <<"PASSED"<<endl: cout<<"FAILED"<<endl;
    }
    system("pause");
}