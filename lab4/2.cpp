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
    cout<<"Введите имя товара:"<<endl;
    cin>>product1.name;
    cout<<"Введите страну товара:"<<endl;
    cin>>product1.country;
    cout<<"Введите количество товара:"<<endl;
    cin>>count;
    product1.c=count;
}

void readProduct(product &product1){
    cout<<"Имя товара: "<< product1.name<<endl;
    cout<<"Страна товара: "<<product1.country<<endl;
    cout<<"Количество товара: "<<product1.c<<endl;
    system("pause");
}

void setMP(product *tovar,int N ){
    
    for (int i = 0; i<N ; i++){
        cout<<"<<Укажите данные позици №"<<i+1<<">>"<<endl;
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
        cout<<"<<Главное меню>>"<<endl;
        cout<<"1) Заполнить"<<endl;
        cout<<"2) Прочитать"<<endl;
        cout<<"3) Заполнить массив"<<endl;
        cout<<"4) Вывести массив"<<endl;
        cout<<"0) Выход"<<endl;
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
                    cout<<"Заполните структуру."<<endl;
                }
                else{
                    readProduct(product1);
                }
                break;
            }
    
            case 3:{
                int N;
                cout<<"Сколько позиций задать?"<<endl;
                cin>>N;
                tovar=new product[N];
                setMP(tovar,N);
                m=0;
                readProduct(tovar[0]);
                break;
            }
                
            case 4:{
                if (m){
                    cout<<"Заполните массив."<<endl;
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