#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include "TMatrix.h"
#include "complex.cpp"
using namespace std;

int main(){
    system("chcp 1251");
    int sw,sw2;
    cout<<"�������� ��� ����������� ������:\n"
    <<"1) double\n"
    <<"2) complex\n";
    cin>>sw;
    int a,b;
    cout<<"������� ����������� _ x _\n";
    cin>>a>>b;
    if (sw == 1){
        TMatrix<double> A(a,b);
        int f = 1;
        while(f){
        cout<<"1) ��������� ������� � �������\n"
        <<"2) ��������� ������� ��������\n"
        <<"3) ������� �������\n"
        <<"4) �������������� �������\n"
        <<"5) ���-�� ����� ������ �������� ������ ����� - minAvg()\n"
        <<"6) ����� ������������� ��������� ������� - Psum()\n"
        <<"7) ������� � ����\n"
        <<"8) ��������� �� �����\n"
        <<"9) <<< �����\n";
            cin>>sw2;
            switch (sw2){
                case 1:{
                    A.set(cin);
                    break;
                }
                case 2:{
                    A.GenerateRandomValues(1,9);
                    A.get(cout);
                    break;
                }
                case 3:{
                    A.get(cout);
                    break;
                }
                case 4:{
                    int I,J;
                    cout<<"������� i,j ��������: _ x _ \n";
                    cin>>I>>J;
                    A.modify(I,J);
                    break;
                }
                case 5:{
                    cout<<"�����: "<<A.LowAwg()<<"\n";
                    break;
                }
                case 6:{
                    cout<<"�����: "<< A.Psum()<< "\n";
                    break;
                }
                case 7:{
                    string file_name;
                    cout<<"������� ��� �����:\n";
                    cin>>file_name;
                    A.f_out(file_name);
                    break;
                }
                case 8:{
                    string file_name;
                    cout<<"������� ��� �����:\n";
                    cin>>file_name;
                    A.f_in(file_name);
                    break;
                    break;
                }
                case 9:{
                    f = 0;
                    break;
                }
            }
        }
    }
    else if (sw == 2){
        TMatrix<complex> A(a,b);
        int f = 1;
        while(f){
        cout<<"1) ��������� ������� � �������\n"
        <<"2) ��������� ������� ��������\n"
        <<"3) ������� �������\n"
        <<"4) �������������� �������\n"
        <<"5) ���-�� ����� ������ �������� ������ ����� - minAvg()\n"
        <<"6) ����� ������������� ��������� ������� - Psum()\n"
        <<"7) ������� � ����\n"
        <<"8) ��������� �� �����\n"
        <<"9) <<< �����\n";
            cin>>sw2;
            switch (sw2){
                case 1:{
                    A.set(cin);
                    break;
                }
                case 2:{
                    A.GenerateRandomValues(1,9);
                    A.get(cout);
                    break;
                }
                case 3:{
                    A.get(cout);
                    break;
                }
                case 4:{
                    int I,J;
                    cout<<"������� i,j ��������: _ x _ \n";
                    cin>>I>>J;
                    A.modify(I,J);
                    break;
                }
                case 5:{
                    cout<<"�����: "<<A.LowAwg()<<"\n";
                    break;
                }
                case 6:{
                    cout<<"�����: "<< A.Psum()<< "\n";
                    break;
                }
                case 7:{
                    string file_name;
                    cout<<"������� ��� �����:\n";
                    cin>>file_name;
                    A.f_out(file_name);
                    break;
                }
                case 8:{
                    string file_name;
                    cout<<"������� ��� �����:\n";
                    cin>>file_name;
                    A.f_in(file_name);
                    break;
                    break;
                }
                case 9:{
                    f = 0;
                    break;
                }
            }
        }
    }
}