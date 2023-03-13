#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string>
#include <locale.h>
#include <cstdlib>  

struct book{
    char name[20];
    char author[20];
    int year;
};

void setBook(book &book1){
    int Y;
    cout<<"Введите имя книги:"<<endl;
    cin.getline(book1.name,20);

    cout<<"Введите автора книги:"<<endl;
    cin.getline(book1.author,20);
    
    cout<<"Введите год книги:"<<endl;
    cin>>Y;
    book1.year=Y;
}

void readBook(book &book1){
    cout<<"Имя книги: "<< book1.name<<endl;
    cout<<"Автор книги: "<<book1.author<<endl;
    cout<<"Год книги: "<<book1.year<<endl;
}

int main(void){
    system("chcp 1251");
    int f=1,h=1;
    int in;
    while (f){
        book book1;
        cout<<"Главное меню"<<endl;
        cout<<"1) Заполнить"<<endl;
        cout<<"2) Прочитать"<<endl;
        cout<<"3) Заполнить массив"<<endl;
        cout<<"4) Вывести массив"<<endl;
        cout<<"0) Выход"<<endl;
        cin>>in;
        switch (in){
            case 0: 
                f=0;
            case 1:
                
                setBook(book1);
                h=0;
                break;
            case 2:
                if (h){
                    cout<<"Заполните структуру."<<endl;
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