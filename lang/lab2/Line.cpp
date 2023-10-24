#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Line.h"

Line::Line(Line &B){
    l = B.l;
}
float Line::length(){
    return l;
}

void Line::set(){
    cout<<"������� ����� �����:\n";
    cin>>l;
}
void Line::get() const{
    cout<<"����� �����: "<<l<<"\n";
}

//���������
void Line::operator=(const Line B){
    l = B.l;
}
bool Line::operator>(const Line B){
    bool a = B.l > l;
    return a;
}
bool Line::operator<(const Line B){
    bool a = B.l < l;
    return a;
}

void getA(Line *A, int n){
    for (int i = 0; i < n; i++)
        {
            cout << "����� � " << i + 1 << ":\n";
            A[i].get();
        }
}

void setA(Line *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "������� ������ ��� ����� � " << i + 1 << ":\n";
        A[i].set();
    }
}

void getAl(Line *A, int n, float l1, float l2){
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
void getS(Line *A, int n){
    cout<<"��������������� ������:\n";
    Line *B = new Line [n];
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
                Line b; // ������ �������������� ����������
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

// ���������� ����� � �����
ostream &operator<<(ostream &s_out, const Line &D){
    s_out << D.l<<"\n";
    return s_out;
}
// ���������� ������ �� ������
istream &operator>>(istream &s_in, Line &D){
    s_in >> D.l;
    return s_in;
}






