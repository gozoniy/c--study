#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "aeroflot.h"

// конструкторы
//Конструктор по-умолчанию
aeroflot::aeroflot(int T){
    time = T;
}
//Конструктор копий
aeroflot::aeroflot(const aeroflot &B){
    time = B.time;
    destination = B.destination;
    index = B.index;
    type = B.type;
    day = B.day;
}

void aeroflot::set(){
    cout << "Укажите назначение рейса:\n";
    cin >> destination;
    cout << "Укажите номер:\n";
    cin >> index;
    cout << "Укажите тип:\n";
    cin >> type;
    cout << "Укажите время:\n";
    cin >> time;
    cout << "Укажите день недели:\n";
    cin >> day;
}
void aeroflot::print() const{
    cout << "-----------\n";
    cout << "Назначение: " << destination << "\n";
    cout << "Номер: " << index << "\n";
    cout << "Тип: " << type << "\n";
    cout << "Время: " << time / 100 << ":" << time % 100 << "\n";
    cout << "День недели: " << day << "\n";
}
void aeroflot::set_time(const int T){
    time = T;
}
void aeroflot::get_time() const{
    cout << "Время рейса: " << time << "\n";
}

//Функции ввода-вывода для массивов
//Заполнение массива
void setMA(aeroflot *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Заполните рейс № " << i + 1 << ":\n";
        A[i].set();
    }
}
//Вывод массива
void getMA(aeroflot *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Рейс № " << i + 1 << ":\n";
        A[i].print();
    }
}

// Операторы
//Оператор присваивания
const void aeroflot::operator=(const aeroflot B){
    time = B.time;
    destination = B.destination;
    index = B.index;
    type = B.type;
    day = B.day;
}
//Оператор равенства
const bool aeroflot::operator==(const aeroflot &B){
    bool answ = ((B.destination == destination) and (B.index == index) and (B.type == type) and (B.time == time) and (B.day == day));
    return answ;
}
const bool aeroflot::operator>(const aeroflot &B)const{
    bool answ = B.time > time;
    return answ;
}
const bool aeroflot::operator<(const aeroflot &B)const{
    bool answ = B.time < time;
    return answ;
}
    
// Выборки
void DEST(aeroflot *B, int n, string D){
    cout << "Для заданного пункта назначения рейсы с номерами:\n";
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if ((B[i].destination == D))
        {
            cout << B[i].index << "\n";
            c++;
        }
    }
    cout << "Всего: " << c << "\n";
}
void TYPE(aeroflot *B, int n, string T){
    cout << "Для заданного типа рейсы с номерами:\n";
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (B[i].type == T)
        {
            cout << B[i].index << "\n";
            c++;
        }
    }
    cout << "Всего: " << c << "\n";
}
void TIME(aeroflot *B, int n, string D, int t1, int t2){
    cout << "Для заданного дня недели и диапазона времени назначения рейсы с номерами:\n";
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if ((B[i].day == D) && (t1 <= B[i].time) && (B[i].time <= t2))
        {
            cout << B[i].index << "\n";
            c++;
        }
    }
    cout << "Всего: " << c << "\n";
}

// сортировка
//Стандартная сортировка
void SORT(aeroflot *B, int n){
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (B[j].time > B[j + 1].time)
            {
                flag = false;
                aeroflot b; // создали дополнительную переменную
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
}
//Сортировка через перегрузку сравнения
void SORTer(aeroflot *B, int n){
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (B[j] < B[j + 1])
            {
                flag = false;
                aeroflot b; // создали дополнительную переменную
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
}

// Перегрузка ввода в поток
ostream &operator<<(ostream &s_out, const aeroflot &D){
    s_out << D.destination << " " << D.index << " " << D.type << " " << D.time << " " << D.day << "\n";
    return s_out;
}
// Перегрузка вывода из потока
istream &operator>>(istream &s_in, aeroflot &D){
    // cout<<"Укажите назначение, номер, тип, время вылета и день недели через пробел: \n";
    s_in >> D.destination >> D.index >> D.type >> D.time >> D.day;
    return s_in;
}

// Работа с файлами
//Импорт данных из файла
void importA(const string F, aeroflot *B, const int n){
    ifstream fin(F);
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла ввода!" << endl;
    }
    else
    {
        cout << "Файл открыт." << endl;
        int c;
        fin >> c;
        if (c != n)
        {
            cout << "Массив задан неверно!\n";
        }
        else
        {
            for (int i = 0; i < c; i++)
            {
                fin >> B[i];
            }
        }
    }
    cout << "Чтение закончено." << endl;
    fin.close();
}
//Экспорт данных в файл
void exportA(const string F, const aeroflot *B, const int n){
    ofstream fin(F);
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла ввода!" << endl;
    }
    else
    {
        fin << n << "\n";
        cout << "Файл открыт." << endl;
        for (int i = 0; i < n; i++)
        {
            fin << B[i];
        }
    }
    cout << "Запись закончена." << endl;
    fin.close();
}
