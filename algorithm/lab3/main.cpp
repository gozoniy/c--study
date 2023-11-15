//������� �20.
//��������� ��� ������ �� ������������ �����, �������� � ����������: ������ L1 � ������ L2. 
//�� ������ ������� L1 � L2 ���������� ������ L3 �� �����, ������� ������ � ���-��� L1, �� �� ������ � ������ L2. 
//������� ������ L3 �� �����.

#include <iostream>
#include <fstream>
#include <string>

#include "List.h"
using namespace std;

int main(void){
    system("chcp 1251");
    bool f = true;
    List<int> L;
    while (f){
        cout<<"������� ����\n"
        <<"1) �������� �������\n"
        <<"2) ������� �������\n"
        <<"3) ���������\n"
        <<"4) ������� �� �����\n"
        <<"5) �����\n"
        <<"6) ���������� ������� L1 � L2 � L3\n"
        <<"0) <<< �����\n";
        int sw;
        cin>>sw;
        switch(sw){
            case 1:{
                cout<<"1) �������� � ������\n"
                <<"2) �������� � �����\n"
                <<"3) �������� �� �������\n";
                int sw1;
                cin>>sw1;
                switch (sw1){
                    case 1:{
                        int temp;
                        cout<<"������� ��������:\n";
                        cin>>temp;
                        L.setBegin(temp);
                        break;
                    }
                    case 2:{
                        int temp;
                        cout<<"������� ��������:\n";
                        cin>>temp;
                        L.setEnd(temp);
                        break;
                    }
                    case 3:{
                        int temp, ind;
                        cout<<"������� �������� � ������:\n";
                        cin>>temp>>ind;
                        L.setIndex(temp,ind);
                        break;
                    }
                }
                break;
            }
            case 2:{
                cout<<"1) ������� � ������\n"
                <<"2) ������� � ������\n"
                <<"3) ������� �� �������\n";
                int sw2;
                cin>>sw2;
                switch (sw2){
                    case 1:{
                        L.Delete_start();
                        break;
                    }
                    case 2:{
                        L.Delete_end();
                        break;
                    }
                    case 3:{
                        int ind;
                        cout<<"������� ������:\n";
                        cin>>ind;
                        L.DelIndex(ind);
                        break;
                    }
                }
                break;
            }
            case 3:{
                int size;
                L.Clear();
                cout<<"������� ����� ������:\n";
                cin>>size;
                L.set(cin, size);
                break;
            }
            case 4:{
                L.get(cout);
                break;
            }
            case 5:{
                int temp;
                cout<<"������� ������� ������:\n";
                cin>>temp;
                L.search(temp,0);
                break;
            }
            case 6:{
                int s1, s2;
                List<int> L1, L2, L3;
                cout<<"������� ����� ������� L1 � L2:\n";
                cin>>s1>>s2;
                cout<<"��������� ������ L1:\n";
                L1.set(cin, s1);
                cout<<"��������� ������ L2:\n";
                L2.set(cin, s2);
                int c = 0;
                //������� ���������
                for (int j = 0; j < L2.size(); j++){
                    for (int i = 0; i < L1.size(); i++){
                        if (L1.GetValue(i) == L2.GetValue(j) && !L3.search(L1.GetValue(i), 1)){
                            L3.setEnd(L1.GetValue(i));
                        }
                    }
                }

                cout<<"������ �����, ������� ������ ��� � L1, ��� � � L2:\n";
                L3.get(cout);
                break;
            }
            
            case 0:{
                f = false;
                break;
            
            }
        }
    }
}