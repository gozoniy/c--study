#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <locale.h>

int main(void){
    setlocale(LC_ALL,"Rus");
    ifstream fin("text.txt");
    if (!fin.is_open()){
        cout<<"������ �������� ����� �����!"<<endl;
    }
    else{
        cout<<"���� ������."<<endl;
        float n=0;
        int a;
        float b;
        ofstream oI("outputI.txt");
        ofstream oF("outputF.txt");
        if (!oI.is_open()||!oF.is_open()){
            cout<<"������ �������� ������ ������!"<<endl;
        }
        else{
            while(fin>>n){
                a=n;
                oI<<a<<endl;
                b=n-a;
                oF<<b<<endl;
            }
            cout<<"������ ���������."<<endl;
            fin.close();
        }
    }
}