#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "dealer.cpp"

using namespace std;

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
        }

    }
}