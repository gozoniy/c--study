#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");

    date d1(26,4,2023);                //�� ���������
    d1.print();
    date d2(27,4,2023);    //� �����������
    d2.print();
    cout<<"���� ����� d1 � d2: "<<d2 - d1<<endl;
    cout<<"����� 365 ���� �����: "<<endl;
    d1+365;
    d1.print();
    d1-365;
    cout<<"������ �����: "<<endl;
    ++d1;
    d1.print();
    --d1;
    if (d1==d2){cout<<"d2 �������"<<endl;}
    else {cout<<"d2 �� �������"<<endl;}
    if (d1<d2){cout<<"d2 ��� �������� "<<endl;}
    cout<<"������ d1=d2"<<endl;
    d1=d2;
    d1.print();
    cin>>d1;
    cout<<d1;
}