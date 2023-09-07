#ifndef MATR_H
#define MATR_H

class Matr{
    int n, m;
    int *p;

public:
    //конструкторы
    Matr();
    Matr(int N, int M);
    Matr(const Matr &m);
    ~Matr(){delete []p; p = 0;}
    //метод транспонирования
    Matr tr();
    //перегрузка операторов
    const Matr& operator=(const Matr&B);
    int &operator()(int i, int j)const {return p[i*m+j];}
    const Matr operator*(const Matr&B)const;
    bool operator==(const Matr&B)const;
    //перегрузка ввода-вывода
    friend ostream& operator<<(ostream& s_out, const Matr& D);
    friend istream& operator>>(istream& s_in, Matr& D);
};

#endif MATR_H