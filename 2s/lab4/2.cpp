#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string.h>
#include <locale.h>
#include <cstdlib>  

#include <C:\Users\User\Desktop\prog\c\lab4\functions.h>

int main(void){
    system("chcp 1251");
    int f=1,h=1,m=1;
    int in;
    int N;
    while (f){
        product product1;
        int N;
        product *tovar;
        cout<<"*Главное меню*"<<endl;
        cout<<"1) Заполнить"<<endl;
        cout<<"2) Прочитать"<<endl;
        cout<<"3) Заполнить массив"<<endl;
        cout<<"4) Вывести массив"<<endl;
        cout<<"5) Выборка стран по товару"<<endl;
        cout<<"0) Выход"<<endl;
        cin>>in;
        switch (in){
            case 0:{        //клавиша (0) - Выход
                f=0;
                break;
            }
            case 1:{        //клавиша (1) - Заполнить одну структуру
                setProduct(product1);
                h=0;
                break;
            } 
            case 2:{        //клавиша (2) - Чтените одной струтуры
                if (h){
                    cout<<"Заполните структуру."<<endl;     //проверка на существование струтуры через флаг h
                }
                else{
                    readProduct(product1);
                }
                break;
            }
            case 3:{        //клавиша (3) - Заполнить массив структур
                cout<<"Сколько позиций задать?"<<endl;
                cin>>N;
                tovar=new product[N];
                setMP(tovar,N);
                m=0;
                break;
            }
            case 4:{        //клавиша (4) - Чтение массива струтур
                if (m){
                    cout<<"Заполните массив."<<endl;        //проверка на существование массива через флаг m
                }
                else{
                    readMP(tovar,N);
                }
                break;
            }
            case 5:{
                if (m){
                    cout<<"Заполните массив."<<endl;        //проверка на существование массива через флаг m
                }
                else{
                    cout<<"*Выборка по товару*"<<endl;
                    char prod[20];
                    cout<<"Введите товар для выборки:"<<endl;
                    cin>>prod;
                    COUNTRY(tovar,N,prod);
                }
            }
            in=0;
        }
    }
}