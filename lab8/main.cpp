#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");
    date d1;                //по умолчанию
    d1.print();
    date d2(12,12,2023);    //с параметрами
    d2.print();
    date d3(d2);            //копий
    d3.print();
    date D = d1 + d2;
    D.print();
}