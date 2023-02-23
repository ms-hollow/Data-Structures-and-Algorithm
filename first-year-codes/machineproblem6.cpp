//LEONEN, ABBEGAIL MILES
//BSCS-NS-1B
//Modify your previous Machine Problem (student record name, q1,q2,q3,ave,remakrs) 
//using OOP in CPP with file handling and string inputs with spaces.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;
#define MAX 50

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
        void save();
        void retrieve();

};

int menu();
void gotoxy(int x, int y);

int main(){
    StudentRec x;
    string sname;
    int ch, quiz1, quiz2, quiz3;
    x.init();
    x.retrieve();
    while(true){
        ch = menu();
        switch(ch){
            case 1: system("cls");gotoxy(40,5);cout << "Input Student Name: ";gotoxy(40,6);cin.ignore();getline(cin, sname); gotoxy(40,7);cout << "Quiz 1: ";cin >> quiz1;
            gotoxy(40,8);cout << "Quiz 2: ";cin >> quiz2;gotoxy(40,9);cout << "Quiz 3: "; cin >> quiz3;x.add(sname, quiz1, quiz2, quiz3);break;
            case 2: system("cls");gotoxy(40,5);cout <<"Input Student Name: "; cin.ignore();getline(cin, sname);x.del(sname);break;
            case 3: x.display();break;
            case 4: x.save(); exit(0);
            default: cout <<"Select from 1 to 4!"<<endl;system("pause");
        }
    }
}

int menu(){
    int op;
    system("cls");
    gotoxy(55,4);cout << "MENU";
    gotoxy(40,6);cout << "====================================";
    gotoxy(40,7);cout << "[1] Add Record";
    gotoxy(40,8);cout << "[2] Delete Record";
    gotoxy(40,9);cout << "[3] Display Record";
    gotoxy(40,10);cout << "[4] Save & Exit";
    gotoxy(40,11);cout << "===================================";
    gotoxy(40,12);cout << "Select from 1 to 4!: ";
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
    }
}

void StudentRec::del(string n){
    int p, i;
    p = locate(n);

    if (p<0){
        gotoxy(40,5);cout << "Record Not Found.";
        gotoxy(40,6);system("pause");
    } else{
        for (i=p;i<marker;i++){
            name[i]=name[i+1];
            q1[i]= q1[i+1];
            q2[i]= q2[i+1];
            q3[i]= q3[i+1];
        }
        marker--;
        gotoxy(40,7);cout<<"Record Successfully Deleted.";
        gotoxy(40,8);system("pause");
    }
}

void StudentRec::display(){
    int i;
    float ave;
    system("cls");
    gotoxy(30,5);cout << "    NAME          QUIZ1     QUIZ2    QUIZ3     AVERAGE     REMARKS"<<endl;
    gotoxy(30,6);cout << "=================================================================="<<endl;
    for (i=0;i<=marker;i++){
        ave = (q1[i] + q2[i] + q3[i])/3.0;
        gotoxy(30,7+i);cout<<i+1<<".) ";
        gotoxy(33,7+i);cout<<name[i]<<"     ";
        gotoxy(49,7+i);cout<<q1[i]<<"     ";
        gotoxy(59,7+i);cout<<q2[i]<<"     ";
        gotoxy(69,7+i);cout<<q3[i]<<"     ";
        gotoxy(78,7+i);cout<<setprecision(4)<<ave<<"      ";
        gotoxy(89,7+i);ave>=75? cout <<"PASSED"<<endl: cout<<"FAILED"<<endl;
        //Naglagay po ako library na iostream manipulator para ma control ko yung lalabas na output.
    }
    system("pause");
}

void StudentRec::save(){
    fstream fp;
    fp.open("studentrec.txt", ios::out);
    if (!fp){
        cout<<"File Error.";
        system("pause");
    } else{
        for (int i=0;i<=marker;i++){
            fp<<name[i]<<endl<<q1[i]<<" "<<q2[i]<<" "<<q3[i]<<endl;
        }
        fp.close();
    }
}

void StudentRec::retrieve(){
    fstream fp;
    string snm;
    int quiz1, quiz2, quiz3;
    fp.open("studentrec.txt",ios::in);
    if (!fp){
        cout<<"File error.\n";
        system("pause");
    } else{
        while(true){
            getline(fp,snm);
            fp>>quiz1>>quiz2>>quiz3;
            fp.ignore();
            if (!fp.eof())
                add(snm,quiz1,quiz2,quiz3);
            else
                break;
        }
        fp.close();
        system("pause");
    }
}


void gotoxy(int x, int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
