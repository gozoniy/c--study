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
    TMatrix<double> A;
    int f = 1;
    cout<<"1) ��������� ������� � �������\n"
    <<"2) ��������� ������� ��������\n"
    <<"3) ������� �������\n"
    <<"4) �������������� �������\n"
    <<"5) minAvg\n"
    <<"6) �����\n";
    while(f){
        cin>>sw2;
        switch (sw2){
            case 1:{
                A.set(cin);
                break;
            }
            case 2:{
                A.GenerateRandomValues(1,9);
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
                cout<<A.LowAwg();
                break;
            }
            case 6:{
                f = 0;
                break;
            }
        }
    }
}