//Вариант №21. 
//Формулировка задания: На основе каталога автосалона требуется определить пять 
//самых быстрых автомобилей с автоматической коробкой передач и пять с механической. 
//Вывод данных на экран осуществлять с группировкой по коробке передач и отображать в 
//алфавитном порядке по формату: Марка автомобиля Модель (Скорость) 
//Формат входных данных: Марка автомобиля, Модель, Скорость автомобиля и тип 
//коробки передач.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include "dealer.cpp"

int main(void){
    system("chcp 1251");
    bool f = true;
    int sw;
    dealer A;
    while (f){
        cout<<"Главное меню\n"
        <<"1) Прочитать каталог из файла input.txt\n"
        <<"2) Прочитать каталог из консоли\n"
        <<"3) Вывести каталог в файл output.txt\n"
        <<"4) Вывести каталог в консоль\n"
        <<"5) Вывести 5 самых быстрых автомобилей каждой категории\n"
        <<"0) <<< Выход\n";
        cin>>sw;
        switch(sw){
            case 1:{
                ifstream in("input.txt");
                A.set(in);
                in.close();
                break;
            }
            case 2:{
                A.set(cin);
                break;
            }
            case 3:{
                ofstream out("output.txt");
                A.get(out);
                break;
            }
            case 4:{
                A.get(cout);
                break;
            }
            case 5:{
                A.top5(cout);
                break;
            }
            case 0:{
                f = false;
                break;
            }
        }

    }
}

