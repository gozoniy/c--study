#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "dealer.cpp"

using namespace std;

int main(void){
    system("chcp 1251");
    bool f = true;
    int sw;
    dealer A;
    while (f){
        cout<<"������� ����\n"
        <<"1) ��������� ������� �� ����� input.txt\n"
        <<"2) ��������� ������� �� �������\n"
        <<"3) ������� ������� � ���� output.txt\n"
        <<"4) ������� ������� � �������\n"
        <<"5) ������� 5 ����� ������� ����������� ������ ���������\n"
        <<"0) <<< �����\n";
        cin>>sw;
        switch(sw){
            case 1:{
                ifstream in("input.txt");
                A.set(in);
                in.close();
                break;
            }
            case 2:{
                A.set(cin);
                break;
            }
            case 3:{
                ofstream out("output.txt");
                A.get(out);
                break;
            }
            case 4:{
                A.get(cout);
                break;
            }
            case 5:{
                A.top5(cout);
                break;
            }
        }

    }
}