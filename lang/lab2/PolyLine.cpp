#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Line.h"
#include "PolyLine.h"

PolyLine::PolyLine(PolyLine &B){
    l = B.l;
    n = B.n;
    L = new float[n];
    for (int i=0; i<n; i++){
        L[i] = B.L[i];
    }
}

void PolyLine::set(){
    
    cout<<"Укажите длину "<<0<<" линии: ";
    cin>>l;
    if (n>0){
        L = new float [n];
        for (int i = 0; i<n; i++){
            cout<<"Укажите длину "<<i+1<<" линии: ";
            cin>>L[i];

        }
    }
}

void PolyLine::get() const {
    cout<<"Длина "<<0<<" линии: ";
    cout<<l<<"\n";
    if (n>0){
        for (int i = 0; i<n; i++){
            cout<<"Длина "<<i+1<<" линии: ";
            cout<<L[i]<<"\n";
        }
    }
}

//Операторы
void PolyLine::operator=(const PolyLine B){
    l = B.l;
    n = B.n;
    L = new float[n];
    for (int i=0; i<n; i++){
        L[i] = B.L[i];
    }
}

//Вывод массива
void getA(PolyLine *A, int n){
    for (int i = 0; i < n; i++)
        {
            cout << "Линия № " << i + 1 << ":\n";
            A[i].get();
        }
}

//Задание массива
void setA(PolyLine *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Введите данные для линии № " << i + 1 << ":\n";
        A[i].set();
    }
}

//Выборка по длине
void getAl(PolyLine *A, int n, float l1, float l2){
    cout<<"Удовлетворяют условию:\n";
    int c = 0;
    for (int i = 0; i < n; i++)
        {
            if (A[i].length()>l1 && A[i].length()<l2){
                cout << "Линия № " << i + 1 << ":\n";
                A[i].get();
                c++;
            }
        }
    cout<<"Всего: "<< c <<"\n";
}

//Вывод отсортированной копии
void getS(PolyLine *A, int n){
    cout<<"Отсортированный массив:\n";
    PolyLine *B = new PolyLine [n];
    for (int i = 0; i < n; i++){        //перенос данных в копию
        B[i]=A[i];
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (B[j] < B[j + 1])
            {
                flag = false;
                PolyLine b; // создаём дополнительную переменную
                b = B[j];
                B[j] = B[j + 1]; // меняем местами значения
                B[j + 1] = b;
            }
        }
        if (flag)
        {
            break;
        }
    }
    getA(B,n);
    delete[] B;
}

ostream &operator<<(ostream &s_out, const PolyLine &D){
    s_out << D.l << " ";
    s_out << D.n << " ";
    for (int i = 0; i < D.n; i++){
        s_out<<D.L[i]<<" ";
    }
    s_out<<"\n";
    return s_out;
}
// Перегрузка вывода из потока
istream &operator>>(istream &s_in, PolyLine &D){
    s_in >> D.l;
    s_in >> D.n;
    for (int i = 0; i < D.n; i++){
        s_in>>D.L[i];
    }
    return s_in;
}
