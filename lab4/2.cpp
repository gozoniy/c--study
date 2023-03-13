#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string>
#include <locale.h>
#include <cstdlib>  

struct product{
    char name[20];
    char country[20];
    int c;
};

void setProduct(product &product1){
    int count;
    cout<<"������� ��� ������:"<<endl;
    cin>>product1.name;
    cout<<"������� ������ ������:"<<endl;
    cin>>product1.country;
    cout<<"������� ���������� ������:"<<endl;
    cin>>count;
    product1.c=count;
}

void readProduct(product &product1){
    cout<<"��� ������: "<< product1.name<<endl;
    cout<<"������ ������: "<<product1.country<<endl;
    cout<<"���������� ������: "<<product1.c<<endl;
    system("pause");
}

void setMP(product *tovar,int N ){
    
    for (int i = 0; i<N ; i++){
        cout<<"<<������� ������ ������ �"<<i+1<<">>"<<endl;
        setProduct(tovar[i]);
    }
}

int main(void){
    system("chcp 1251");
    int f=1,h=1,m=1;
    int in;
    while (f){
        product product1;
        int N;
        product *tovar;
        cout<<"<<������� ����>>"<<endl;
        cout<<"1) ���������"<<endl;
        cout<<"2) ���������"<<endl;
        cout<<"3) ��������� ������"<<endl;
        cout<<"4) ������� ������"<<endl;
        cout<<"0) �����"<<endl;
        cin>>in;
        switch (in){
            case 0:{
                f=0;
                break;
            }
            case 1:{
                setProduct(product1);
                h=0;
                break;
            }
                
            case 2:{
                if (h){
                    cout<<"��������� ���������."<<endl;
                }
                else{
                    readProduct(product1);
                }
                break;
            }
    
            case 3:{
                int N;
                cout<<"������� ������� ������?"<<endl;
                cin>>N;
                tovar=new product[N];
                setMP(tovar,N);
                m=0;
                readProduct(tovar[0]);
                break;
            }
                
            case 4:{
                if (m){
                    cout<<"��������� ������."<<endl;
                }
                else{
                    for (int i = 0; i<N ; i++){
                        readProduct(tovar[i]);
                    }
                }
                break;
            }
                
            in=0;
        }
    }
}