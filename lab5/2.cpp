#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cstdlib>  

#include "functions.h"
#include "Pstruct.h"

int main(void){
    system("chcp 1251");
    int f=1,h=1,m=1;
    int in,inp;
    int N;
    product product1;
    product *tovar;
    int l;
    Node *pEnd=0, *pBegin=0;
    int list=0;
    while (f){
        cout<<"*Главное меню*"<<endl;
        cout<<"1) Заполнить"<<endl;
        cout<<"2) Прочитать"<<endl;
        cout<<"3) Заполнить массив"<<endl;
        cout<<"4) Вывести массив"<<endl;
        cout<<"5) Выборка стран по товару"<<endl;
        cout<<"6) Операции со списком"<<endl;
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
            case 5:{        //клавиша (5) - Выборка стран
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
                break;
            }
            case 6:{        //клавиша (6) - операции над списком
                int ext=1;
                while (ext){
                    cout<<"1) Формирование первого элемента списка\n"
                        <<"2) Добавить элемент к существующему списку\n"
                        <<"3) Прочитать список\n"
                        <<"4) Прочитать в обратном порядке\n"
                        <<"5) Удалить список\n"
                        <<"6) Удалить элемент по полю\n"
                        <<"0) <------\n";
                    cin>>inp;
                    switch (inp){
                        case 1:{            //клавиша (1) - Формирование первого элемента списка
                            pBegin=pEnd=first();
                            list=1;
                            break;
                        }
                        case 2:{            //клавиша (2) - добавить элемент в конец
                            if (list){
                                pEnd=add(pEnd);
                                break;
                            }
                            else{
                                cout<<"Сначала задайте список.\n";
                            }
                            break;
                        }
                        case 3:{            //клавиша (3) - прочитать список
                            if (list){
                                cout<<"Ваш список:\n";
                                print(pBegin);
                            }
                            else{
                                cout<<"Сначала задайте список.\n";
                            }
                            break;
                        }
                        case 4:{            //клавиша (4) - прочитать в обратном порядке
                            if (list){
                                cout<<"Ваш список:\n";
                                backwardPrint(pEnd);
                            }
                            else{
                                cout<<"Сначала задайте список.\n";
                            }
                            break;
                        }
                        
                        case 5:{            //клавиша (5) - удаление списка
                            if (list){
                                cout<<"Удаление списка...\n";
                                delList(pBegin);
                                list=0;
                            }
                            else{
                                cout<<"Сначала задайте список.\n";
                            }
                            break;
                        }
                        case 6:{            //клавиша (6) - удаление по полю
                            delP(pBegin);
                            break;
                        }

                        case 0:{            //клавиша (0) - возврат в главное меню
                            ext=0;
                            break;
                        }
                    }
                }
            }
            in=0;
        }
    }
}