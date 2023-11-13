#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include "TMatrix.h"
#include "complex.cpp"
using namespace std;

int main(){
    system("chcp 1251");
    int sw,sw2;
    cout<<"Выберите тип тестируемых данных:\n"
    <<"1) double\n"
    <<"2) complex\n";
    cin>>sw;
    int a,b;
    cout<<"Введите размерность _ x _\n";
    cin>>a>>b;
    if (sw == 1){
        TMatrix<double> A(a,b);
        int f = 1;
        while(f){
        cout<<"1) Заполнить матрицу с консоли\n"
        <<"2) Заполнить матрицу случайно\n"
        <<"3) Вывести матрицу\n"
        <<"4) Модифицировать элемент\n"
        <<"5) Кол-во чисел меньше среднего четных строк - minAvg()\n"
        <<"6) Сумма положительных элементов массива - Psum()\n"
        <<"7) Вывести в файл\n"
        <<"8) Прочитать из файла\n"
        <<"9) <<< Выход\n";
            cin>>sw2;
            switch (sw2){
                case 1:{
                    A.set(cin);
                    break;
                }
                case 2:{
                    A.GenerateRandomValues(1,9);
                    A.get(cout);
                    break;
                }
                case 3:{
                    A.get(cout);
                    break;
                }
                case 4:{
                    int I,J;
                    cout<<"Укажите i,j элемента: _ x _ \n";
                    cin>>I>>J;
                    A.modify(I,J);
                    break;
                }
                case 5:{
                    cout<<"Всего: "<<A.LowAwg()<<"\n";
                    break;
                }
                case 6:{
                    cout<<"Сумма: "<< A.Psum()<< "\n";
                    break;
                }
                case 7:{
                    string file_name;
                    cout<<"Введите имя файла:\n";
                    cin>>file_name;
                    A.f_out(file_name);
                    break;
                }
                case 8:{
                    string file_name;
                    cout<<"Введите имя файла:\n";
                    cin>>file_name;
                    A.f_in(file_name);
                    break;
                    break;
                }
                case 9:{
                    f = 0;
                    break;
                }
            }
        }
    }
    else if (sw == 2){
        TMatrix<complex> A(a,b);
        int f = 1;
        while(f){
        cout<<"1) Заполнить матрицу с консоли\n"
        <<"2) Заполнить матрицу случайно\n"
        <<"3) Вывести матрицу\n"
        <<"4) Модифицировать элемент\n"
        <<"5) Кол-во чисел меньше среднего четных строк - minAvg()\n"
        <<"6) Сумма положительных элементов массива - Psum()\n"
        <<"7) Вывести в файл\n"
        <<"8) Прочитать из файла\n"
        <<"9) <<< Выход\n";
            cin>>sw2;
            switch (sw2){
                case 1:{
                    A.set(cin);
                    break;
                }
                case 2:{
                    A.GenerateRandomValues(1,9);
                    A.get(cout);
                    break;
                }
                case 3:{
                    A.get(cout);
                    break;
                }
                case 4:{
                    int I,J;
                    cout<<"Укажите i,j элемента: _ x _ \n";
                    cin>>I>>J;
                    A.modify(I,J);
                    break;
                }
                case 5:{
                    cout<<"Всего: "<<A.LowAwg()<<"\n";
                    break;
                }
                case 6:{
                    cout<<"Сумма: "<< A.Psum()<< "\n";
                    break;
                }
                case 7:{
                    string file_name;
                    cout<<"Введите имя файла:\n";
                    cin>>file_name;
                    A.f_out(file_name);
                    break;
                }
                case 8:{
                    string file_name;
                    cout<<"Введите имя файла:\n";
                    cin>>file_name;
                    A.f_in(file_name);
                    break;
                    break;
                }
                case 9:{
                    f = 0;
                    break;
                }
            }
        }
    }
}