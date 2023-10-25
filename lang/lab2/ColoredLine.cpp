#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Line.h"
#include "ColoredLine.h"


void ColoredLine::setColor(){
    cout<<"������� ���� r g b:\n";
    cin>>r>>g>>b;
}
void ColoredLine::getColor(){
    cout<<r<<" "<<g<<" "<<b<<"\n";
}

ColoredLine::ColoredLine(ColoredLine &B){
    l = B.l;
    r = B.r;
    g = B.g;
    b = B.
    b;
}

void ColoredLine::get() const{
    cout<<"����� �����: "<<l<<"\n";
    cout<<"���� ����� r g b: \n"
    << r <<" "<<g<<" "<<b<<"\n";
}

//���������
void ColoredLine::operator=(const ColoredLine B){
    l = B.l;
    r = B.r;
    g = B.g;
    b = B.b;
}


void getA(ColoredLine *A, int n){
    for (int i = 0; i < n; i++)
        {
            cout << "����� � " << i + 1 << ":\n";
            A[i].get();
            A[i].getColor();
        }
}

void setA(ColoredLine *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "������� ������ ��� ����� � " << i + 1 << ":\n";
        A[i].set();
        A[i].setColor();
    }
    
}

void getAl(ColoredLine *A, int n, float l1, float l2){
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
void getS(ColoredLine *A, int n){
    cout<<"��������������� ������:\n";
    ColoredLine *B = new ColoredLine [n];
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
                ColoredLine b; // ������ �������������� ����������
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
ostream &operator<<(ostream &s_out, const ColoredLine &D){
    s_out << D.l << " " << D.r << " " << D.g << " " << D.b << "\n";
    return s_out;
}
// ���������� ������ �� ������
istream &operator>>(istream &s_in, ColoredLine &D){
    s_in >> D.l >> D.r >> D.g >> D.b;
    return s_in;
}

