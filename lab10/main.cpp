#include <iostream>
using namespace std;
#include "date.cpp"


int main(void){
    system("chcp 1251");

    date* d1 = new date;
    date* d2 = new date;
    cout<<"Всего элементов типа date: "<<date::count<<endl;
    delete d2;
    cout<<"Всего элементов типа date: "<<d1->count<<endl;
}