#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");

    date d1(30,11,2023);                //по умолчанию
    d1.print();
    date d2(12,12,2023);    //с параметрами
    d2.print();
    cout<<"ƒней между d1 и d2: "<<d2 - d1<<endl;

    date d3(d2);            //копий
    d3.print();
    ++d3;
    d3.print();
    
}