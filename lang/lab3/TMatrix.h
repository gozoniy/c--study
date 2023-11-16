#pragma once
#ifndef TMATRIX_H
#define TMATRIX_H

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
        TMatrix(const TMatrix& B) {
            Clear();
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    matrix[i][j] = B.matrix[i][j];
                }
            }
        }
        //Деструктор
        ~TMatrix(){
            Clear();
        }
        void Clear(){
            for (int i = 0; i<a; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix=nullptr;
            a = b = 0;
        }

        //Операторы
        //Индексирование
        Type& operator ()(int A,int B) const{
            return matrix[A][B];
        }
        //присваивание
        void operator = (TMatrix& B){
            Clear();
            a = B.a;
            b = B.b;
            matrix = new Type * [a];
            for(int i = 0; i<a; i++){
                matrix[i] = new Type [b];
            }
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    matrix[i][j] = B.matrix[i][j];
                }
            }
        }
        //сравнение
        bool operator<(const TMatrix& B){
            if (this->Psum()<B.Psum()){
                return 1;
            }
            else{
                return 0;
            }
        }
        bool operator>(const TMatrix& B){
            if (this->Psum()>B.Psum()){
                return 1;
            }
            else{
                return 0;
            }
        }

        //сетеры
        void GenerateRandomValues(int min, int max){
            if (a==0||b==0){
                cout<<"Введите размерность _ x _\n";
                cin>>a>>b;
                matrix = new Type * [a];
                for(int i = 0; i<a; i++){
                    matrix[i] = new Type [b];
                }
            }
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
            Clear();
            if (&in == &cin){
                cout<<"Введите размерность _ x _\n";
            }
            in>>a>>b;
            matrix = new Type * [a];
            for(int i = 0; i<a; i++){
                matrix[i] = new Type [b];
            }
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
        ostream& get(ostream& out){
            if (&out == &cout){
                cout<<"Матрица размером "<<a<<" x "<<b<<":\n";
            }
            else{
                out<<a<<" "<<b<<"\n";
            }
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
            Type sum=0;
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    if (matrix[i][j]>0){
                        sum+=matrix[i][j];
                    }
                }
            }
            return sum;
        }
        
    //Работа с файлами
    void f_in(string filename){
        Clear();
        ifstream fin(filename);
        set(fin);
        cout<<"Запись завершена.\n";
    }
    void f_out(string filename){
        ofstream fout(filename);
        get(fout);
        cout<<"Запись завершена.\n";
    }
        
};

template<class Type>
ostream& operator <<(ostream& out, TMatrix<Type>& Matr){
    Matr.get(out);
    return out;
}
template<class Type>
istream& operator >>(istream& in, TMatrix<Type>& Matr){
    Matr.set(in);
    return in;
}



#endif //TMATRIX_H