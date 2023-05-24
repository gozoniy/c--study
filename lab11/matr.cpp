#include "matr.h"

Matr::Matr(int N, int M){                   //Конструктор с параметрами
    n = N; 
    m = M;
    p = new int [n*m];
    for (int i = 0; i<n*m; i++)
        p[i] = 0;
}
Matr::Matr(const Matr &B){                        //Конструктор копий
    n = B.n;
    m = B.m;
    p = new int [n*m];

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            (*this)(i,j) = B(i,j);
}
const Matr& Matr::operator=(const Matr&B) {        //Копирование
    if (this == &B)
        return *this;
    n = B.n;
    m = B.m;
    delete []p;
    p = new int [n*m];

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            (*this)(i,j) = B(i,j);
}
const Matr Matr::operator*(const Matr &B)const{        //Умножение матриц
    if (m == B.n){
        Matr C(n,B.m);  //Создание матрицы результата
        for (int i = 0; i<C.n; i++)
            for (int j = 0; j<C.m; j++)
                for (int k = 0; k<m; k++)
                    C(i,j)+=(*this)(i,k)*B(k,j);
        return C;
    }
    else
        return B;
}
bool Matr::operator==(const Matr &B)const{          //Сравнение матриц
    Matr A = *this;
    int i,j;
    int flag = 1;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            if (A(i,j)!=B(i,j))
                flag = 0;
    if (flag)
        return true;
    else
        return false;
}
Matr Matr::tr(){                 //Транспонирование матрицы
    Matr A = *this;
    Matr C(m,n);
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            C(j,i) = A(i,j);
    return C;
}
//перегрузка ввода-вывода
istream& operator>>(istream& s_in, Matr& M){
    delete []M.p;
    M.p = new int [M.n*M.m];
    int r;
    int i,j;
    for (int i = 0; i<M.n; i++)
        for (int j = 0; j<M.m; j++){
            cout<<"Введите элемент "<<i+1<<" x "<<j+1<<endl;
            cin>>r;
            M(i,j) = r;
        }
}
ostream& operator<<(ostream& s_out, const Matr& M){
    int i,j;
    for (int i = 0; i<M.n; i++)
        for (int j = 0; j<M.m; j++){
            if (j == 0)
                s_out<<"| ";
            s_out<<M(i,j)<<" ";
            if (j == M.m-1)
                s_out<<"|\n";
        }
}