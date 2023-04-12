#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cstdlib>  

#include "functions.h"
#include "Pstruct.h"

int main(void){
    system("chcp 1251");
    int f=1,h=1,m=1;
    int in,inp;
    int N;
    product product1;
    product *tovar;
    int l;
    Node *pEnd=0, *pBegin=0;
    int list=0;
    while (f){
        cout<<"*������� ����*"<<endl;
        cout<<"1) ���������"<<endl;
        cout<<"2) ���������"<<endl;
        cout<<"3) ��������� ������"<<endl;
        cout<<"4) ������� ������"<<endl;
        cout<<"5) ������� ����� �� ������"<<endl;
        cout<<"6) �������� �� �������"<<endl;
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
            case 5:{        //������� (5) - ������� �����
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
                break;
            }
            case 6:{        //������� (6) - �������� ��� �������
                int ext=1;
                while (ext){
                    cout<<"1) ������������ ������� �������� ������\n"
                        <<"2) �������� ������� � ������������� ������\n"
                        <<"3) ��������� ������\n"
                        <<"4) ��������� � �������� �������\n"
                        <<"5) ������� ������\n"
                        <<"6) ������� ������� �� ����\n"
                        <<"0) <------\n";
                    cin>>inp;
                    switch (inp){
                        case 1:{            //������� (1) - ������������ ������� �������� ������
                            pBegin=pEnd=first();
                            list=1;
                            break;
                        }
                        case 2:{            //������� (2) - �������� ������� � �����
                            if (list){
                                pEnd=add(pEnd);
                                break;
                            }
                            else{
                                cout<<"������� ������� ������.\n";
                            }
                            break;
                        }
                        case 3:{            //������� (3) - ��������� ������
                            if (list){
                                cout<<"��� ������:\n";
                                print(pBegin);
                            }
                            else{
                                cout<<"������� ������� ������.\n";
                            }
                            break;
                        }
                        case 4:{            //������� (4) - ��������� � �������� �������
                            if (list){
                                cout<<"��� ������:\n";
                                backwardPrint(pEnd);
                            }
                            else{
                                cout<<"������� ������� ������.\n";
                            }
                            break;
                        }
                        
                        case 5:{            //������� (5) - �������� ������
                            if (list){
                                cout<<"�������� ������...\n";
                                delList(pBegin);
                                list=0;
                            }
                            else{
                                cout<<"������� ������� ������.\n";
                            }
                            break;
                        }
                        case 6:{            //������� (6) - �������� �� ����
                            delP(pBegin);
                            break;
                        }

                        case 0:{            //������� (0) - ������� � ������� ����
                            ext=0;
                            break;
                        }
                    }
                }
            }
            in=0;
        }
    }
}