#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string>
#include <locale.h>
#include <cstdlib>  

struct book{
    string name;
    string author;
    int year;
};

void setBook(book &book1){
    string N,A;
    int Y;
    cout<<"������� ��� �����:"<<endl;
    cin>>N;
    cout<<"������� ������ �����:"<<endl;
    cin>>A;
    cout<<"������� ��� �����:"<<endl;
    cin>>Y;
    book1.name=N;
    book1.author=A;
    book1.year=Y;
}

void readBook(const book &book1){
    cout<<"��� �����: "<< book1.name<<endl;
    cout<<"����� �����: "<<book1.author<<endl;
    cout<<"��� �����: "<<book1.year<<endl;
}

int main(void){
    system("chcp 1251");
    int f=1,h=1;
    int in;
    while (f){
        book book1;
        cout<<"������� ����"<<endl;
        cout<<"1) ���������"<<endl;
        cout<<"2) ���������"<<endl;
        cout<<"3) ��������� ������"<<endl;
        cout<<"4) ������� ������"<<endl;
        cout<<"0) �����"<<endl;
        cin>>in;
        switch (in){
            case 0: 
                f=0;
            case 1:
                {
                setBook(book1);
                cout<<book1.author<<endl;
                h=0;
                break;
                }
            case 2:
                if (h){
                    cout<<"��������� ���������."<<endl;
                }
                else{
                    readBook(book1);
                    cout<<book1.author<<endl;

                }
                break;

        in=0;
        }
    }
}