#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");
    date d1;                //�� ���������
    d1.print();
    date d2(12,12,2023);    //� �����������
    d2.print();
    date d3(d2);            //�����
    d3.print();
    date D = d1 + d2;
    D.print();
}