/*������� 8
��� ��������� ����. ���������� �� ��������� ����� 
� ������ ���� ��� ������ �� ������� n ��������.*/
#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <string.h>

int main(void){
    setlocale(LC_ALL,"Rus");
    ifstream is("text.txt");
    ofstream os("output.txt");
    if (!is.is_open()||!os.is_open()){
        cout<<"������ �������� �����!"<<endl;
    }
    else{
        cout<<"���� ������� ������!"<<endl;
        int n,l;
        string str;
        cout<<"������� ������ ������ n:";
        cin>>n;
        while(getline(is, str)){
            l=str.length();
            if (l<n){
                os<<str<<endl;
            }
        }
        cout<<"��� �� ������� ����� �������� ����������."<<endl;
        is.close();
        os.close();
    }
}
