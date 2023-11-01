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
        //����������� �� ���������
        TMatrix() : a(0), b(0), matrix(nullptr)
        {}
        //����������� � �����������
        TMatrix(int I, int J) : a(I), b(J), matrix(new Type*[a]){
            for(int i = 0; i<a; i++){
                matrix[i] = new Type [b];
            }
        }
        //����������� �����������
        TMatrix(const TMatrix& B) : TMatrix(B.a,B.b){
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    matrix[i][j] = B.matrix[i][j];
                }
            }
        }
        //����������
        ~TMatrix(){
            for (int i = 0; i<a; i++){
                delete[] matrix[i];
            }
        }
        //�������� ��������������
        Type& operator ()(int A,int B) const{
            return matrix[A][B];
        }

        //������
        void setR(int min, int max){
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
                cout<<"������� �������� ����� ������:\n";
            }
            for(int i = 0; i<a; i++){
                for (int j = 0; j<b; j++){
                    in>>matrix[i][j];
                }
            }
            return in;
        }

        //������
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

        //����������� �������
        void modify(int I,int J){
            int sw;
            cout<<"1) �������������� "<<I<<" x "<<J<<" ��������\n";
            cout<<"2) �������������� "<<I<<" x "<<J<<" ����� �������\n";
            cin>>sw;
            switch(sw){
                case 1:{
                    int min,max;
                    cout<<"������� �������� �� _ �� _:\n";
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
            cout<<c2<<"\n";
        }

        
};

template<class Type>
ostream& operator <<(ostream& out, TMatrix<Type>& Matr){
    if (&out == &cout){
        out<<"������� �������� "<<Matr.getA()<<" x "<<Matr.getB()<<"\n";
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