
#include <iostream>
using namespace std;

int main(void){
    system("chcp 1251");
    int f = 1;
    int in;
    while (f){
        cout<<"1) C��������� ������ �������, ��������������� ��������� �������\n";
        cout<<"2) ����� ���������� �������������� ������\n";
        cout<<"0) ����� \n";
        cin>>in;;
        switch (in){
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 0:{
                f = 0;
                break;
            }
        }
    }
}