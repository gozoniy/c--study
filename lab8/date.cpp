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
int date::days(){      //����� ����������� ����� ������ � ���������� ����
    int M = 0;
    for (int i = 0; i<month ; i++){
        if (i%2 == 0){M+=30;}
        else {M+=31;}
    }
    int Ans = year * 365 + M + day;
    return Ans;
}
void date::undays(int N){   //����� ����������� ���������� ���� � ���� ������
    year = N%365;
    N = N - year * 365;
    month = N%30;
    N = N - month * 30;
    day = N;
}


