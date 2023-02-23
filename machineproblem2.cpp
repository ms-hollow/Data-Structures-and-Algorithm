#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

typedef struct record {
    string name;
    int a,b,c;
} REC;

typedef struct node{
    REC r;
    struct node* nxt;
} NODE;

class Class {
private:
    NODE *n;
    bool isEmpty();
public:
    void makenull();
    void add(REC r);
    void del(string n);
    void display();
    void save();
    void retrieve();
};

int menu();

int main(){
    Class l;
    REC r;
    l.makenull();
    l.retrieve();
    while(1){
        switch(menu()){
        case 1: system("cls"); cout<<"INSERT MODE\n"; cout<<"Input name: "; cin.ignore(); getline(cin,r.name);
                cout<<"Enter Quiz 1: "; cin>>r.a;
                cout<<"Enter Quiz 2: "; cin>>r.b;
                cout<<"Enter Quiz 3: "; cin>>r.c;
                l.add(r); break;
        case 2: system("cls"); cout<<"DELETE MODE\n"; cout<<"Input name: "; cin.ignore();getline(cin,r.name);
                l.del(r.name); break;
        case 3: system("cls"); l.display(); break;
        case 4: l.save(); exit(0);
        default: cout<<"Please select from 1 to 4!"<<endl; system("pause");
        }
    }
}

void Class::makenull(){
    n = NULL;
}

bool Class::isEmpty(){
    return(n==NULL);
}

void Class::add(REC r){
    NODE *p, *q, *temp;
    p=q=n;
    temp = new NODE;
    temp->r.name = r.name;
    temp->r.a = r.a;
    temp->r.b = r.b;
    temp->r.c = r.c;

     while(p!=NULL && p->r.name<r.name){
        q = p;
        p = p->nxt;
    }
    if (p==n)
        n = temp;
    else
        q->nxt = temp;
    temp->nxt = p;
}

void Class::del(string nm){
    NODE *p, *q;
    p=q=n;
    if (isEmpty()){
        cout<<"List is empty";
        system("pause");
    }
    while(p!=NULL && nm>p->r.name){
        q=p;
        p=p->nxt;
    }
    if(p==NULL){
        cout<<"Record not Found.\n";
        system("pause");
    }
    else{
        if(n==p)
            n=p->nxt;
        else
            q->nxt=p->nxt;
        free(p);
        cout<<"Record successfully deleted \n";
    }
    system("pause");
}

void Class::display(){
    NODE *p;
    REC r;
    int i=1;
    float avg;
    p = n;
    system("cls");
    cout<<"Name       Q1   Q2   Q3    AVE   REMARKS\n";

    while (p!=NULL){
        avg = (p->r.a+p->r.b+p->r.c)/3.0;
        cout<<i++<<".) "<<p->r.name<<"      "<<p->r.a<<"   "<<p->r.b<<"   "<<p->r.c<<"   "<<setprecision(4)<<avg<<"   ";avg>=74.00? cout <<"PASSED"<<endl: cout<<"FAILED"<<endl;
        p=p->nxt;
    }
    system("pause");
}

int menu(){
int ch;
system("cls");
cout<<"MENU\n";
cout<<"[1] INSERT MODE\n";
cout<<"[2] DELETE MODE\n";
cout<<"[3] DISPLAY MODE\n";
cout<<"[4] SAVE AND EXIT\n";
cout<<"SELECT (1-4): "; cin>>ch;
return(ch);
}

void Class::save(){
    fstream fp;
    fp.open("data.txt", ios::out);
    NODE *p;
    p=n;
    while (p!=NULL){
        fp<<p->r.name<<endl<<p->r.a<<" "<<p->r.b<<" "<<p->r.c<<endl;
        p=p->nxt;
    }
    fp.close();
}

void Class::retrieve(){
    fstream fp;
    REC r;
    fp.open("data.txt",ios::in);
    if(!fp){
        cout<<"File error.\n";
        system("pause");
    }
    else{
        while(true){
            getline(fp,r.name);
            fp>>r.a>>r.b>>r.c;
            fp.ignore();

            if(!fp.eof())
                add(r);
            else
                break;
        }
        fp.close();
    }
}
