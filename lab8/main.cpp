#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");

    date d1(30,11,2023);                //�� ���������
    d1.print();
    date d2(12,12,2023);    //� �����������
    d2.print();
    cout<<"���� ����� d1 � d2: "<<d2 - d1<<endl;

    date d3(d2);            //�����
    d3.print();
    ++d3;
    d3.print();
    
}