#include <iostream>
using namespace std;
#include "rectangle.h"

void rectangle::set(){     //����� ������� ���������
    cout<<"������� ���������� ������ ����� ����� ������\n";
    cin>>x1>>y1;
    cout<<"������� ���������� ������ ����� ����� ������\n";
    cin>>x2>>y2;
}
void rectangle::print(){   //����� ������ ���������
    cout<<"1 ����:   ("<<x1<<";"<<y1<<")\n"
    <<"2 ����:   ("<<x2<<";"<<y2<<")\n";
}
float rectangle::area(){   //����� �������� �������
    float S;
    S=abs(x1-x2)*abs(y1-y2);
    cout<<"S = "<<S<<endl;
    return S;
}
