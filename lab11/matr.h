#ifndef MATR_H
#define MATR_H

class Matr{
    int n, m;
    int *p;

public:
    Matr(int N, int M);
    Matr(const Matr &m);
    ~Matr(){delete []p; p = 0;}

    const Matr& operator=(Matr&B);
    int &operator()(int i, int j)const {return p[i*m+j];}
    const Matr operator*(const Matr&B)const;
     bool operator==(const Matr&B)const;


    //перегрузка ввода-вывода
    friend ostream& operator<<(ostream& s_out, Matr& D);
    friend istream& operator>>(istream& s_in, Matr& D);



};


#endif MATR_H