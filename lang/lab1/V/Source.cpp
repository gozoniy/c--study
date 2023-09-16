#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "Header.h"


InstSession::InstSession() {
    PhysicMark = 1;
    HistoryMark = 1;
    MathMark = 1;
    AvgMark = (PhysicMark + HistoryMark + MathMark) / 3;
}
InstSession::InstSession(int M, int M2, int M3) {
    PhysicMark = M;
    HistoryMark = M2;
    MathMark = M3;
    AvgMark = (PhysicMark + HistoryMark + MathMark) / 3;
}
InstSession::InstSession(const InstSession& B) {
    PhysicMark = B.PhysicMark;
    HistoryMark = B.HistoryMark;
    MathMark = B.MathMark;
    AvgMark = B.AvgMark;

    for (int i = 0; i < 20; i++) {
        SecondName[i] = B.SecondName[i];
        Group[i] = B.Group[i];
    }
}

void InstSession::set() {
    cout << "Укажите фамилию:\n";
    cin >> SecondName;
    cout << "Укажите группу:\n";
    cin >> Group;
    cout << "Укажите оценку по физике:\n";
    cin >> PhysicMark;
    cout << "Укажите оценку по истории:\n";
    cin >> HistoryMark;
    cout << "Укажите оценку по математике:\n";
    cin >> MathMark;
}

void InstSession::print() {
    cout << "-----------\n";
    cout << "Фамилия: " << SecondName << "\n";
    cout << "Группа: " << Group << "\n";
    cout << "   Оценка по физике: " << PhysicMark << "\n";
    cout << "   Оценка по истории: " << HistoryMark << "\n";
    cout << "   Оценка по математике: " << MathMark << "\n";
}

void InstSession::set_Mark(int M, int M2, int M3) {
    PhysicMark = M;
    HistoryMark = M2;
    MathMark = M3;
    AvgMark = (PhysicMark + HistoryMark + MathMark) / 3;
}
void InstSession::get_Mark() {
    cout << "Средняя оценка: " << AvgMark << "\n";
}

//Функции ввода-вывода для массивов
void setMA(InstSession* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Заполните студента № " << i + 1 << ":\n";
        A[i].set();
    }
}

void getMA(InstSession* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Студент № " << i + 1 << ":\n";
        A[i].print();
    }
}

//Операторы
void InstSession::operator = (InstSession B) {
    PhysicMark = B.PhysicMark;
    HistoryMark = B.HistoryMark;
    MathMark = B.MathMark;
    AvgMark = B.AvgMark;
    for (int i = 0; i < 20; i++) {
        SecondName[i] = B.SecondName[i];
        Group[i] = B.Group[i];
    }
}


//Выборки
void DOLG(InstSession* B, int n, int D) {
    cout << "Задолжники для заданного предмета(1 - Физика, 2 - История, 3 - Математика):\n";
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (D == 1 && B[i].PhysicMark < 3) {
            cout << B[i].SecondName << "\n";
        }
        if (D == 2 && B[i].HistoryMark < 3) {
            cout << B[i].SecondName << "\n";
        }
        if (D == 3 && B[i].MathMark < 3) {
            cout << B[i].SecondName << "\n";
        }
    }
}
void PRED(InstSession* B, int n, int T) {
    cout << "Для заданного предмета(1 - Физика, 2 - История, 3 - Математика):\n";
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (T == 1) {
            cout << B[i].SecondName << B[i].PhysicMark << "\n";
        }
        if (T == 2) {
            cout << B[i].SecondName << B[i].HistoryMark << "\n";
        }
        if (T == 3) {
            cout << B[i].SecondName << B[i].MathMark << "\n";
        }
    }
}
void GROUP(InstSession* B, int n, char* D) {
    cout << "Для заданной группы:\n";
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!strcmp(B[i].Group, D)) {
            cout << B[i].SecondName << (B[i].PhysicMark + B[i].HistoryMark + B[i].MathMark) / 3 << "\n";
        }
    }
}

//сортировка
void SORT(InstSession* B, int n) {
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (B[j].AvgMark > B[j + 1].AvgMark) {
                flag = false;
                InstSession b; // создали дополнительную переменную
                b = B[j];
                B[j] = B[j + 1]; // меняем местами значения
                B[j + 1] = b;
            }
        }
        if (flag) {
            break;
        }
    }

}

//перегрузка операций ввода/вывода
istream& operator>>(istream& s_in, InstSession& D) {                //ввод
    cout << "Укажите фамилию, группу, оценку по физике, истории и математике: \n";
    s_in >> D.SecondName >> D.SecondName >> D.PhysicMark >> D.HistoryMark >> D.MathMark;
    return s_in;
}
ostream& operator<<(ostream& s_out, const InstSession& D) {         //вывод
    s_out <<
        "Фамилия: " << D.SecondName << "\n" <<
        "Группа: " << D.SecondName << "\n" <<
        "Оценка по физике: " << D.PhysicMark << "\n" <<
        "Оценка по истории: " << D.HistoryMark << "\n" <<
        "Оценка по математике: " << D.MathMark << "\n";
    return s_out;
}

//Работа с файлами
void importA(const char* F, InstSession* B, int n) {
    ifstream fin(F);
    if (!fin.is_open()) {
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        int c;
        fin >> c;
        if (c != n) {
            cout << "Неправильно задан массив\n";
        }
        else {
            //while(fin>>n){
            for (int i = 0; i < c; i++) {
                fin >> B[i].SecondName >> B[i].Group >> B[i].PhysicMark >> B[i].HistoryMark >> B[i].MathMark;
            }
        }
    }
    fin.close();
}

void exportA(char* F, InstSession* B, int n) {
    ifstream fin(F);
    if (!fin.is_open()) {
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        int c;
        fin >> c;
        if (c != n) {
            cout << "Неправильно задан массив\n";
        }
        else {
            //while(fin>>n){
            for (int i = 0; i < c; i++) {
                fin >> B[i].SecondName >> B[i].Group >> B[i].PhysicMark >> B[i].HistoryMark >> B[i].MathMark;
            }
        }
    }
    fin.close();
}