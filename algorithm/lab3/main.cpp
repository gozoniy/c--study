//Вариант №20.
//Построить два списка из вещественных чисел, вводимых с клавиатуры: список L1 и список L2. 
//На основе списков L1 и L2 образовать список L3 из чисел, которые входят в спи-сок L1, но не входят в список L2. 
//Вывести список L3 на экран.

#include <iostream>
#include <fstream>
#include <string>

#include "List.h"
using namespace std;

int main(void){
    system("chcp 1251");
    bool f = true;
    List<int> L;
    while (f){
        cout<<"Главное меню\n"
        <<"1) Добавить элемент\n"
        <<"2) Удалить элемент\n"
        <<"3) Заполнить\n"
        <<"4) Вывести на экран\n"
        <<"5) Поиск\n"
        <<"6) Соединение списков L1 и L2 в L3\n"
        <<"0) <<< Выход\n";
        int sw;
        cin>>sw;
        switch(sw){
            case 1:{
                cout<<"1) Добавить в начало\n"
                <<"2) Добавить в конец\n"
                <<"3) Добавить по индексу\n";
                int sw1;
                cin>>sw1;
                switch (sw1){
                    case 1:{
                        int temp;
                        cout<<"Укажите значение:\n";
                        cin>>temp;
                        L.setBegin(temp);
                        break;
                    }
                    case 2:{
                        int temp;
                        cout<<"Укажите значение:\n";
                        cin>>temp;
                        L.setEnd(temp);
                        break;
                    }
                    case 3:{
                        int temp, ind;
                        cout<<"Укажите значение и индекс:\n";
                        cin>>temp>>ind;
                        L.setIndex(temp,ind);
                        break;
                    }
                }
                break;
            }
            case 2:{
                cout<<"1) Удалить в начале\n"
                <<"2) Удалить в конеце\n"
                <<"3) Удалить по индексу\n";
                int sw2;
                cin>>sw2;
                switch (sw2){
                    case 1:{
                        L.Delete_start();
                        break;
                    }
                    case 2:{
                        L.Delete_end();
                        break;
                    }
                    case 3:{
                        int ind;
                        cout<<"Укажите индекс:\n";
                        cin>>ind;
                        L.DelIndex(ind);
                        break;
                    }
                }
                break;
            }
            case 3:{
                int size;
                L.Clear();
                cout<<"Укажите длину списка:\n";
                cin>>size;
                L.set(cin, size);
                break;
            }
            case 4:{
                L.get(cout);
                break;
            }
            case 5:{
                int temp;
                cout<<"Введите элемент поиска:\n";
                cin>>temp;
                L.search(temp,0);
                break;
            }
            case 6:{
                int s1, s2;
                List<int> L1, L2, L3;
                cout<<"Укажите длину списков L1 и L2:\n";
                cin>>s1>>s2;
                cout<<"Заполните список L1:\n";
                L1.set(cin, s1);
                cout<<"Заполните список L2:\n";
                L2.set(cin, s2);
                int c = 0;
                //Матрица сравнений
                for (int j = 0; j < L2.size(); j++){
                    for (int i = 0; i < L1.size(); i++){
                        if (L1.GetValue(i) == L2.GetValue(j) && !L3.search(L1.GetValue(i), 1)){
                            L3.setEnd(L1.GetValue(i));
                        }
                    }
                }

                cout<<"Список чисел, которые входят как в L1, так и в L2:\n";
                L3.get(cout);
                break;
            }
            
            case 0:{
                f = false;
                break;
            
            }
        }
    }
}