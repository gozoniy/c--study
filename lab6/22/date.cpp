#include <iostream>
using namespace std;
#include "date.h"

void date::set(){     //����� ����� ���, ������ � ����
    cout<<"������� ����, ����� � ��� ����� ������: \n";
    cin>>day>>month>>year;
}
void date::print(){   //����� ������ ���� ��.��.����
    cout<<"���� � ������� ��.��.����: \n"
    <<day<<"."<<month<<"."<<year<<endl;
}
long date::format(){   //����� ������ � ������� ����
    long form = year*10000+month*100+day;
    return form;
}
