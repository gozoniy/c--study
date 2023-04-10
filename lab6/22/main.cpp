#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");
    int l;
    cout<<"Заполнение статической переменной: \n";
    date d2;    //Статическая переменная
    d2.set();
    d2.print();
    cout<<d2.format()<<endl;

    cout<<"Заполнение динамической переменной: \n"
        <<"Укажите длинну массива дат:\n";
    cin>>l;
    date *d1 = new date[l];     //Динамическая переменная
    for (int i = 0; i < l; i++){    //Заполнение переменной
        cout<<"Дата №"<<i+1<<":\n";
        d1[i].set();
    }
    for (int i = 0; i < l; i++){    //Вывод переменной
        cout<<"Дата №"<<i+1<<":\n";
        d1[i].print();
        cout<<d1[i].format()<<endl;
    }
}