#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Line.h"
#include "PolyLine.h"

PolyLine::PolyLine(PolyLine &B){
    l = B.l;
    n = B.n;
    L = new float[n];
    for (int i=0; i<n; i++){
        L[i] = B.L[i];
    }
}

void PolyLine::set(){
    
    cout<<"������� ����� "<<0<<" �����: ";
    cin>>l;
    if (n>0){
        L = new float [n];
        for (int i = 0; i<n; i++){
            cout<<"������� ����� "<<i+1<<" �����: ";
            cin>>L[i];

        }
    }
}

void PolyLine::get() const {
    cout<<"����� "<<0<<" �����: ";
    cout<<l<<"\n";
    if (n>0){
        for (int i = 0; i<n; i++){
            cout<<"����� "<<i+1<<" �����: ";
            cout<<L[i]<<"\n";
        }
    }
}

//���������
void PolyLine::operator=(const PolyLine B){
    l = B.l;
    n = B.n;
    L = new float[n];
    for (int i=0; i<n; i++){
        L[i] = B.L[i];
    }
}

//����� �������
void getA(PolyLine *A, int n){
    for (int i = 0; i < n; i++)
        {
            cout << "����� � " << i + 1 << ":\n";
            A[i].get();
        }
}

//������� �������
void setA(PolyLine *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "������� ������ ��� ����� � " << i + 1 << ":\n";
        A[i].set();
    }
}

//������� �� �����
void getAl(PolyLine *A, int n, float l1, float l2){
    cout<<"������������� �������:\n";
    int c = 0;
    for (int i = 0; i < n; i++)
        {
            if (A[i].length()>l1 && A[i].length()<l2){
                cout << "����� � " << i + 1 << ":\n";
                A[i].get();
                c++;
            }
        }
    cout<<"�����: "<< c <<"\n";
}

//����� ��������������� �����
void getS(PolyLine *A, int n){
    cout<<"��������������� ������:\n";
    PolyLine *B = new PolyLine [n];
    for (int i = 0; i < n; i++){        //������� ������ � �����
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
                PolyLine b; // ������ �������������� ����������
                b = B[j];
                B[j] = B[j + 1]; // ������ ������� ��������
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

ostream &operator<<(ostream &s_out, const PolyLine &D){
    s_out << D.l << " ";
    s_out << D.n << " ";
    for (int i = 0; i < D.n; i++){
        s_out<<D.L[i]<<" ";
    }
    s_out<<"\n";
    return s_out;
}
// ���������� ������ �� ������
istream &operator>>(istream &s_in, PolyLine &D){
    s_in >> D.l;
    s_in >> D.n;
    for (int i = 0; i < D.n; i++){
        s_in>>D.L[i];
    }
    return s_in;
}
