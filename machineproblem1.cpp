//Leonen, Abbegail Miles
//BSCS-NS-2B

/* Write the Student Record Program in C++(use own class) with saving and retrieving.
Use Array of Structures for the Records.
-Menu
-Insert Record
-Update Record
-Delete Record
-Display All
-Exit*/

#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 50
using namespace std;

typedef struct student{
    string name;
    int q1, q2, q3;
}STUD;

typedef struct list{ //parang marker lang to
    STUD rec[MAX];
    int tail;
}LIST;

class Class{
    private:
        LIST L;
        int locate(string nm);
        bool isFull();
        bool isEmpty();
        float ave(int a, int b, int c);
    public:
        void makenull();//init
        void add(STUD s);
        void update(string nm);
        void del(string nm);
        void display();
        void save();
        void retrieve();
};

int menu();

int main(){

    Class cl; //instance of an object
    STUD sr;
    cl.makenull();
    cl.retrieve();
    while(1){
        switch(menu()){
            case 1: system("cls"); cout<<"INSERT MODE\n";cout<<"Input name: "; cin.ignore();getline(cin,sr.name);
                    cout<<"Enter Quiz 1: "; cin>>sr.q1;
                    cout<<"Enter Quiz 2: "; cin>>sr.q2;
                    cout<<"Enter Quiz 3: "; cin>>sr.q3;
                    cl.add(sr); break;
            case 2: system("cls"); cout<<"UPDATE MODE\n";cout<<"Input name: "; cin.ignore();getline(cin,sr.name);
                    cl.update(sr.name); break;
            case 3: system("cls"); cout<<"DELETE MODE\n";cout<<"Input name: "; cin.ignore();getline(cin,sr.name); cl.del(sr.name); break;
            case 4: system("cls"); cl.display();break;
            case 5: cl.save(); exit(0);
            default: cout<<"Please select from 1 to 5!"<<endl; system("pause");
        }
    }

}

void Class::makenull(){
    L.tail = -1;
}

void Class::add(STUD s){
    int i, p;
    if(isFull()){
        cout<<"List is Full";
        system("pause");
    }
    else{
        L.tail++;
        L.rec[L.tail] = s;
    }
}

void Class::update(string nm){
    int p, ch;
    p = locate(nm);
    if(p<0){
        cout<<"Name not found";
        system("pause");
    }
    else{
        while(ch!=4){
            cout<<"\nName: "<<L.rec[p].name;
            cout<<"\nQuiz 1: "<<L.rec[p].q1;
            cout<<"\nQuiz 2: "<<L.rec[p].q2;
            cout<<"\nQuiz 3: "<<L.rec[p].q3;

            cout<<"\nSelect an item to update: ";
            cout<<"\n[1] Quiz#1\t[2] Quiz#2\t[3] Quiz#3\t[4] Return to main menu"<<endl;
            cout<<"Input a number (1-5): "; cin>>ch;
            switch(ch){
                case 1: cout<<"\n Input new Quiz#1: "; cin>>L.rec[p].q1;break;
                case 2: cout<<"\n Input new Quiz#2: "; cin>>L.rec[p].q2;break;
                case 3: cout<<"\n Input new Quiz#3: "; cin>>L.rec[p].q3;break;
                case 4: break;

            }
            display();
        }
    }
}

void Class::del(string nm){
    int i, p;
    if(isEmpty()){
        cout<<"List is empty";
        system("pause");
    }
    else{
        p=locate(nm);
        if (p==-1){
            cout<<"Name not found";
            system("pause");
        }
        else{
            for (i=p;i<L.tail;i++)
            L.rec[i]=L.rec[i+1];
            L.tail--;
        }
    }
}

void Class::display(){
    int i;
    float avg;
    system("cls");
    cout<<"NAME         QUIZ#1 QUIZ#2 QUIZ#3 REMARKS"<<endl;
    for(i=0;i<=L.tail;i++){
        avg = ave(L.rec[i].q1,L.rec[i].q2,L.rec[i].q3);
        cout<<i+1<<".) "<<L.rec[i].name<<"      "<<L.rec[i].q1<<"   "<<L.rec[i].q2<<"   "<<L.rec[i].q3<<"   "<<setprecision(4)<<avg<<"   ";avg>=74.00? cout <<"PASSED"<<endl: cout<<"FAILED"<<endl;
    }
    system("pause");
}

int Class::locate(string nm){
    int i;
    for(i=0;i<=L.tail;i++)
        if(L.rec[i].name==nm)
            return (i);
    return (-1);
}

bool Class::isEmpty(){
    return(L.tail==-1);
}

bool Class::isFull(){
    return(L.tail==MAX-1);
}

float Class::ave(int a, int b, int c){
    return((a+b+c)/3.0);
}

int menu(){
int ch;
system("cls");
cout<<"MENU\n";
cout<<"[1] INSERT\n";
cout<<"[2] UPDATE\n";
cout<<"[3] DELETE\n";
cout<<"[4] DISPLAY\n";
cout<<"[5] SAVE AND EXIT\n";
cout<<"SELECT (1-5): "; cin>>ch;
return(ch);
}


void Class::save(){

    fstream fp;
    STUD x;
    fp.open("studentrec.txt", ios::out);
    if(!fp){
        cout<<"File error.\n";
        system("pause");
    }
    else{
        for(int i=0;i<=L.tail;i++){
            fp<<L.rec[i].name<<endl<<L.rec[i].q1<<endl<<L.rec[i].q2<<endl<<L.rec[i].q3<<endl;
        }
        fp.close();
    }
}

void Class::retrieve(){

    fstream fp;
    STUD x;
    fp.open("studentrec.txt",ios::in);
    if(!fp){
        cout<<"File error.\n";
        system("pause");
    }
    else{
        while(true){
            getline(fp,x.name);
            fp>>x.q1>>x.q2>>x.q3;
            fp.ignore();

            if(!fp.eof())
                add(x);
            else
                break;
        }
        fp.close();
    }
}



