#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");
    int l;
    cout<<"���������� ����������� ����������: \n";
    date d2;    //����������� ����������
    d2.set();
    d2.print();
    cout<<d2.format()<<endl;

    cout<<"���������� ������������ ����������: \n"
        <<"������� ������ ������� ���:\n";
    cin>>l;
    date *d1 = new date[l];     //������������ ����������
    for (int i = 0; i < l; i++){    //���������� ����������
        cout<<"���� �"<<i+1<<":\n";
        d1[i].set();
    }
    for (int i = 0; i < l; i++){    //����� ����������
        cout<<"���� �"<<i+1<<":\n";
        d1[i].print();
        cout<<d1[i].format()<<endl;
    }
}