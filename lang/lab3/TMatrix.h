#pragma once
#ifndef TMATRIX_H
#include <iostream>
#include <time.h>
using namespace std;


template <class Type>
class TMatrix{
        int a,b;
        Type** matrix;
    public:
        //Конструктор по умолчанию
        TMatrix() : a(0), b(0), matrix(nullptr)
        {}
        //Конструктор с параметрами
        TMatrix(int I, int J) : a(I), b(J), matrix(new Type*[a]){
            for(int i = 0; i<a; i++){
                matrix[i] = new Type [b];
            }
        }
        //Конструктор копирования
        TMatrix(const TMatrix& B) : TMatrix(B.a,B.b){
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    matrix[i][j] = B.matrix[i][j];
                }
            }
        }
        //Деструктор
        ~TMatrix(){
            for (int i = 0; i<a; i++){
                delete[] matrix[i];
            }
        }
        //Операторы
        //Индексирование
        Type& operator ()(int A,int B) const{
            return matrix[A][B];
        }
        //присваивание
        TMatrix operator = (const TMatrix& B){
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    matrix[i][j] = B.matrix[i][j];
                }
            }
            return *this;
        }
        //сравнение
        bool operator<(TMatrix B){
            if (this->Psum()<B.Psum()){
                return 1;
            }
            else{
                return 0;
            }
        }
        bool operator>(TMatrix B){
            if (this->Psum()>B.Psum()){
                return 1;
            }
            else{
                return 0;
            }
        }

        //сетеры
        void GenerateRandomValues(int min, int max){
            srand(time(NULL));
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    matrix[i][j] = min + rand()%(max-min+1);
                }
            }
        }
        void SetRandomValue(int I, int J,int min, int max){
            matrix[I][J] = min + rand()%(max-min+1);
        }

        istream& set(istream& in){
            if (&in == &cin){
                cout<<"Введите элементы через пробел:\n";
            }
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    in>>matrix[i][j];
                }
            }
            return in;
        }

        //гетеры
        int getA(){return a;}
        int getB(){return b;}
        ostream& get(ostream& out){
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    out<<matrix[i][j]<<" ";
                }
                out<<"\n";
            }
            return out;
        }

        //Модификация элемета
        void modify(int I,int J){
            int sw;
            cout<<"1) Модифицировать "<<I<<" x "<<J<<" случайно\n";
            cout<<"2) Модифицировать "<<I<<" x "<<J<<" через консоль\n";
            cin>>sw;
            switch(sw){
                case 1:{
                    int min,max;
                    cout<<"Введите диапазон от _ до _:\n";
                    cin>>min>>max;
                    SetRandomValue(I,J,min,max);
                    break;
                }
                case 2:{
                    Type v;
                    cin>>v;
                    matrix[I][J] = v;
                }
            }
        }
        
        int LowAwg(){
            float sum = 0;
            int c = 0;
            for (int i = 0; i<=a/2; i++){
                for (int j = 0; j<b; j++){
                    sum+=matrix[i*2][j];
                    c++;
                }
                
            }
            float avg = sum/c;
            int c2 = 0;
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    if (matrix[i][j]<avg){
                        c2++;
                    }
                }
            }
            return c2;
        }

        Type Psum(){
            Type sum;
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    if (matrix[i][j]>0){
                        sum+=matrix[i][j];
                    }
                }
            }
            return sum;
        }

        
};

template<class Type>
ostream& operator <<(ostream& out, TMatrix<Type>& Matr){
    if (&out == &cout){
        out<<"Матрица размером "<<Matr.getA()<<" x "<<Matr.getB()<<"\n";
    }
    else{
        out<<Matr.getA()<<" "<<Matr.getB()<<"\n";
    }
    Matr.get(out);
    return out;
}
template<class Type>
istream& operator >>(istream& in, TMatrix<Type>& Matr){
    Matr.set(in);
    return in;
}


#endif //TMATRIX_H