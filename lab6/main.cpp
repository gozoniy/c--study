#include <iostream>
using namespace std;
#include "rectangle.cpp"

int main(void){
    system("chcp 1251");

    rectangle r1;                               //����������� ����������
    r1.set();
    r1.print();
    r1.area();

    int l;
    cout<<"������� ������ �������:\n";  
    cin>>l;
    rectangle *R = new rectangle[l];            //������������ ����������
    for (int i=0;i<l;i++){
        cout<<"������������� �"<<i+1<<endl;
        R[i].set();
    }
    cout<<"������ ���������������:\n";
    for (int i=0;i<l;i++){
        cout<<"������������� �"<<i+1<<endl;
        R[i].print();
        R[i].area();
    }
}