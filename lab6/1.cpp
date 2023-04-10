#include <iostream>
using namespace std;
#include "rectangle.h"

int main(void){
    system("chcp 1251");
    rectangle r1;

    int l;
    cout<<"Укажите длинну массива:\n";
    cin>>l;
    rectangle *R = new rectangle[l];
    for (int i=0;i<l;i++){
        cout<<"Прямоугольник №"<<i+1<<endl;
        R[i].set();
    }
    cout<<"Массив прямоугольников:\n";
    for (int i=0;i<l;i++){
        cout<<"Прямоугольник №"<<i+1<<endl;
        R[i].print();
        R[i].area();
    }
}