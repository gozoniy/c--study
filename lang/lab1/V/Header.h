#pragma once

class InstSession {
    char SecondName[20];
    char Group[20];
    int PhysicMark;
    int HistoryMark;
    int MathMark;
    int AvgMark;


public:
    //конструкторы
    InstSession();
    InstSession(int M, int M2, int M3);
    InstSession(const InstSession& B);
    //методы
    void set();
    void print();
    void set_Mark(int M, int M2, int M3);
    void get_Mark();
    friend void DOLG(InstSession* B, int n, int D);
    friend void PRED(InstSession* B, int n, int T);
    friend void GROUP(InstSession* B, int n, char* D);
    friend void SORT(InstSession* B, int n);
    //операторы
    void operator = (InstSession B);
    //потоковый ввод-вывод
    friend ostream& operator<<(ostream& s_out, const InstSession& D);
    friend istream& operator>>(istream& s_in, InstSession& D);
    //Работа с файлами
    friend void importA(const char* F, InstSession* B, int n);
    friend void exportA(char* F, InstSession* B, int n);
};
