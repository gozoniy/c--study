#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cstdlib>  

class rectangle{    //����� �������������
public:
    float x1,y1,x2,y2;

    void set(){     //����� ������� ���������
        cout<<"������� ���������� ������ ����� ����� ������\n";
        cin>>x1>>y1;
        cout<<"������� ���������� ������ ����� ����� ������\n";
        cin>>x2>>y2;
    }

    void print(){   //����� ������ ���������
        
        cout<<"1 ����:   ("<<x1<<";"<<y1<<")\n"
        <<"2 ����:   ("<<x2<<";"<<y2<<")\n";
    }

    float area(){   //����� �������� �������
        float S;
        S=abs(x1-x2)*abs(y1-y2);
        cout<<"S = "<<S<<endl;
        return S;
    }
};

int main(void){
    system("chcp 1251");
    rectangle r1;

    int l;
    cout<<"������� ������ �������:\n";
    cin>>l;
    rectangle *R = new rectangle[l];
    for (int i=0;i<l;i++){
        cout<<"������������� �"<<i+1<<endl;
        R[i].set();
    }
    cout<<"������ ���������������:\n";
    for (int i=0;i<l;i++){
        cout<<"������������� �"<<i+1<<endl;
        R[i].print();
        R[i].area();
    }
}