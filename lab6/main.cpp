#include <iostream>
using namespace std;
#include "rectangle.cpp"

int main(void){
    system("chcp 1251");

    rectangle r1;                               //статическая переменная
    r1.set();
    r1.print();
    r1.area();

    int l;
    cout<<"Укажите длинну массива:\n";  
    cin>>l;
    rectangle *R = new rectangle[l];            //динамическая переменная
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