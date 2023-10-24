#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Line.h"

Line::Line(Line &B){
    l = B.l;
}
float Line::length(){
    return l;
}

void Line::set(){
    cout<<"Введите длину линии:\n";
    cin>>l;
}
void Line::get() const{
    cout<<"Длина линии: "<<l<<"\n";
}

//Операторы
void Line::operator=(const Line B){
    l = B.l;
}
bool Line::operator>(const Line B){
    bool a = B.l > l;
    return a;
}
bool Line::operator<(const Line B){
    bool a = B.l < l;
    return a;
}

void getA(Line *A, int n){
    for (int i = 0; i < n; i++)
        {
            cout << "Линия № " << i + 1 << ":\n";
            A[i].get();
        }
}

void setA(Line *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Введите данные для линии № " << i + 1 << ":\n";
        A[i].set();
    }
}

void getAl(Line *A, int n, float l1, float l2){
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
void getS(Line *A, int n){
    cout<<"Отсортированный массив:\n";
    Line *B = new Line [n];
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
                Line b; // создаём дополнительную переменную
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

// Перегрузка ввода в поток
ostream &operator<<(ostream &s_out, const Line &D){
    s_out << D.l<<"\n";
    return s_out;
}
// Перегрузка вывода из потока
istream &operator>>(istream &s_in, Line &D){
    s_in >> D.l;
    return s_in;
}






