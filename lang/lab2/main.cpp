#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "Line.cpp"
#include "ColoredLine.cpp"
#include "PolyLine.cpp"
#include "Picture.cpp"

int main(void){
    system("chcp 1251");
    bool f = true, M = false;
    int sw,sw2,sw3,n;
    while (f){
        cout<<"*������� ����*\n"
        <<"1) ������ � ��������\n"
        <<"2) ������ � �������� ����������\n"
        <<"0) ��������� ������ � ����������\n";
        cin>>sw;
        switch (sw){
            case 1:{//�������� �������
                cout<<"1) Line\n"
                <<"2) Colored Line\n"
                <<"3) Poly Line\n";
                cin>>sw2;
                switch (sw2){
                    case 1:{
                        Line A;
                        A.set(cin);
                        A.get(cout);
                        break;
                    }
                    case 2:{
                        ColoredLine A;
                        A.set(cin);
                        A.setColor();
                        A.get(cout);
                        break;
                    }
                    case 3:{
                        PolyLine A;
                        A.set(cin);
                        A.get(cout);
                        break;
                    }
                }
                break;
            }
            case 2:{//������ ����������
                bool f2 = true;
                int N;
                string filename;
                cout<<"������� ����� ������� ����������: ";
                cin>>N;
                Picture P(N);
                
                while (f2){
                    cout
                    <<"1) ��������� ������ ����������\n"
                    <<"2) ������� ������ ����������\n"
                    <<"3) ������������� �� �����������\n"
                    <<"4) ������� � ���������\n"
                    <<"5) ��������� �� �����\n"
                    <<"6) ������� � ����\n"
                    <<"0) <<<<<<<\n";
                    cin>>sw3;
                    switch (sw3){
                        case 1:{
                            P.set(cin);
                            break;
                        }
                        case 2:{
                            P.get(cout);
                            break;
                        }
                        case 3:{
                            P.Sort();
                            break;
                        }
                        case 4:{
                            float l1,l2;
                            cout<<"������� �������� ��_ ��_:\n";
                            cin>>l1>>l2;
                            P.getAl(l1,l2);
                            break;
                        }
                        case 5:{
                            cout<<"������� ��� �����:\n";
                            cin>>filename;
                            P.f_in(filename);
                            break;
                        }
                        case 6:{
                            cout<<"������� ��� �����:\n";
                            cin>>filename;
                            P.f_out(filename);
                            break;
                        }
                        case 0:{
                            f2 = false;
                            break;
                        }
                    }
                    
                }
                break;
            }
            case 0:{
                f = false;
                break;
            }
        }
    }
}