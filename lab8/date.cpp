#include <iostream>
using namespace std;
#include "date.h"

void date::set(){     //����� ����� ���, ������ � ����
    cout<<"������� ����, ����� � ��� ����� ������: \n";
    cin>>day>>month>>year;
}
void date::print(){   //����� ������ ���� ��.��.����
    //cout<<"���� � ������� ��.��.����: \n"
    cout<<day<<"."<<month<<"."<<year<<endl;
}
long date::format(){   //����� ������ � ������� ����
    long form = year*10000+month*100+day;
    return form;
}
int date::days()const{      //����� ����������� ����� ������ � ���������� ����
    int M = 0;
    for (int i = 1; i<month ; i++){//���� �������
        if (i == 2){M+=28;}//�������� �� �������
        else if (i%2 == 0){M+=30;}
        else {M+=31;}
    }
    int Ans = year * 365 + M + day;
    return Ans;
}
void date::undays(int N){   //����� ����������� ���������� ���� � ���� ������
    year = N/365;
    N = N - year * 365;
    int M = 0;
    int k = 1;
    while (!(N<32)){//���� �������
        if (k == 2){M=28;}//�������� �� �������
        else if (k%2 == 0){M=30;}
        else {M=31;}
        k++;
        N-=M;
    }
    day = N;
}
//�������������� ���������
const void date::operator = (const date &Date){    //�������� = (�����������)
        undays(Date.days());
    }
const date date::operator + (int Date){     //�������� + (����������� ���� � ����)
        date curr = *this;
        date Res;
        Res.undays(curr.days() + Date) ;
        return Res;
    }
const date date::operator - (int Date){     //�������� - (��������� ���� �� ����)
        date curr = *this;
        date Res;
        //undays(curr.days() - Date);
        Res.undays(curr.days() - Date) ;
        return Res;
    }
const int date::operator - (const date &Date) {   //�������� - (���������� ���� ����� ������)
        date curr = *this;
        int Res;
        Res = (curr.days() - Date.days()) ;
        return Res;
    }

//������� ���������
const date date::operator ++ () {   //�������� ++ (������)
        int N = days();
        undays(++N);
        return *this;
    }
const date date::operator -- () {   //�������� -- (�����)
        int N = days();
        undays(--N);
        return *this;
    }

//��������� ���������
const bool date::operator == (date &Date){
        date curr = *this;
        if (curr.days()==Date.days()){return true;}
        else {return false;}
    }
const bool date::operator > (date &Date){
        date curr = *this;
        if (curr.days()>Date.days()){return true;}
        else {return false;}
    }
const bool date::operator < (date &Date){
        date curr = *this;
        if (curr.days()<Date.days()){return true;}
        else {return false;}
    }


