#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string.h>
#include <locale.h>
#include <cstdlib>  

#include <C:\Users\User\Desktop\prog\c\lab4\functions.h>

int main(void){
    system("chcp 1251");
    int f=1,h=1,m=1;
    int in;
    int N;
    while (f){
        product product1;
        int N;
        product *tovar;
        cout<<"*������� ����*"<<endl;
        cout<<"1) ���������"<<endl;
        cout<<"2) ���������"<<endl;
        cout<<"3) ��������� ������"<<endl;
        cout<<"4) ������� ������"<<endl;
        cout<<"5) ������� ����� �� ������"<<endl;
        cout<<"0) �����"<<endl;
        cin>>in;
        switch (in){
            case 0:{        //������� (0) - �����
                f=0;
                break;
            }
            case 1:{        //������� (1) - ��������� ���� ���������
                setProduct(product1);
                h=0;
                break;
            } 
            case 2:{        //������� (2) - ������� ����� ��������
                if (h){
                    cout<<"��������� ���������."<<endl;     //�������� �� ������������� �������� ����� ���� h
                }
                else{
                    readProduct(product1);
                }
                break;
            }
            case 3:{        //������� (3) - ��������� ������ ��������
                cout<<"������� ������� ������?"<<endl;
                cin>>N;
                tovar=new product[N];
                setMP(tovar,N);
                m=0;
                break;
            }
            case 4:{        //������� (4) - ������ ������� �������
                if (m){
                    cout<<"��������� ������."<<endl;        //�������� �� ������������� ������� ����� ���� m
                }
                else{
                    readMP(tovar,N);
                }
                break;
            }
            case 5:{
                if (m){
                    cout<<"��������� ������."<<endl;        //�������� �� ������������� ������� ����� ���� m
                }
                else{
                    cout<<"*������� �� ������*"<<endl;
                    char prod[20];
                    cout<<"������� ����� ��� �������:"<<endl;
                    cin>>prod;
                    COUNTRY(tovar,N,prod);
                }
            }
            in=0;
        }
    }
}