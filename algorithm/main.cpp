//21. ���������� ������� ��������; ���������� ������� �����������. 
#include <iostream>
using namespace std;
#include "array.cpp"

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
                int n;
                cout<<"������� ������ �������: ";
                cin>>n;
                array<int> A(n);
                cout<<"������� �������� ��������� �� n1 �� n2 (n1_n2):";
                int n1, n2;
                cin>>n1>>n2;
                A.setR(n1,n2);
                A.get();
                array<int> B(A);
                B.shakerSort();
                cout<<"��������������� ������: \n";
                B.get();
                string name;
                cout<<"������� ��� ����� ������: \n";
                cin>>name;
                ofstream fout(name);
                if (!fout.is_open()){
                    cout<<"������ ��������!";
                }
                else{
                    A.get_file(fout);
                    B.get_file(fout);
                }
                break;
            }
            case 2:{
                cout<<"1) ���������� ���������� ����������\n"
                <<"2) ���������� �������������� ����������\n"
                <<"3) ���������� ��������������������� ����������\n";
                
                break;
            }
            case 0:{
                f = 0;
                break;
            }
        }
    }
}