#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");
    bool x = 1;
    int in = 0;
    int l;
    date *D;
    date d1();
    while(x){
        cout<<"<������� ����>\n"
        <<"1) ��������� ����������� ����������\n"
        <<"2) �������\n"
        <<"3) ������� � ������� ����\n"
        <<"4) ��������� ������������ ������\n"
        <<"5) ������� ������������ ������\n"
        <<"0) �����\n";
        cin>>in;
        switch(in){
            case 0:{        //�����
                x = 0;
                break;
            }
            case 1:{        //���������
                int d,m,y;
                cout<<"������� ����, ����� � ��� ����� ������: \n";
                cin>>d>>m>>y;
                date d1(d,m,y);
                break;
            }
            case 2:{        //�������
                d1.print();
                break;
            }
            case 3:{        //����� � ������� ������ �����
                cout<<"���� � ���� ������ �����: "<<d1.format()<<endl;
                break;
            }
            case 4:{
                cin>>l;
                date *D = new date[l];     //������������ ����������
                for (int i = 0; i < l; i++){    //���������� ������������ ����������
                    cout<<"���� �"<<i+1<<":\n";
                    D[i].set();
                }
                break;
            }
            case 5:{
                for (int i = 0; i < l; i++){    //����� ����������� ����������
                    cout<<"���� �"<<i+1<<":\n";
                    D[i].print();
                    cout<<D[i].format()<<endl;
                }
                break;
            }

        }
        in = 0;
    }
}