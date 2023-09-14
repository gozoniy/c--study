#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "aeroflot.h"

// ������������
//����������� ��-���������
aeroflot::aeroflot(int T){
    time = T;
}
//����������� �����
aeroflot::aeroflot(const aeroflot &B){
    time = B.time;
    destination = B.destination;
    index = B.index;
    type = B.type;
    day = B.day;
}

void aeroflot::set(){
    cout << "������� ���������� �����:\n";
    cin >> destination;
    cout << "������� �����:\n";
    cin >> index;
    cout << "������� ���:\n";
    cin >> type;
    cout << "������� �����:\n";
    cin >> time;
    cout << "������� ���� ������:\n";
    cin >> day;
}
void aeroflot::print() const{
    cout << "-----------\n";
    cout << "����������: " << destination << "\n";
    cout << "�����: " << index << "\n";
    cout << "���: " << type << "\n";
    cout << "�����: " << time / 100 << ":" << time % 100 << "\n";
    cout << "���� ������: " << day << "\n";
}
void aeroflot::set_time(const int T){
    time = T;
}
void aeroflot::get_time() const{
    cout << "����� �����: " << time << "\n";
}

//������� �����-������ ��� ��������
//���������� �������
void setMA(aeroflot *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "��������� ���� � " << i + 1 << ":\n";
        A[i].set();
    }
}
//����� �������
void getMA(aeroflot *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "���� � " << i + 1 << ":\n";
        A[i].print();
    }
}

// ���������
//�������� ������������
const void aeroflot::operator=(const aeroflot B){
    time = B.time;
    destination = B.destination;
    index = B.index;
    type = B.type;
    day = B.day;
}
//�������� ���������
const bool aeroflot::operator==(const aeroflot &B){
    bool answ = ((B.destination == destination) and (B.index == index) and (B.type == type) and (B.time == time) and (B.day == day));
    return answ;
}
const bool aeroflot::operator>(const aeroflot &B)const{
    bool answ = B.time > time;
    return answ;
}
const bool aeroflot::operator<(const aeroflot &B)const{
    bool answ = B.time < time;
    return answ;
}
    
// �������
void DEST(aeroflot *B, int n, string D){
    cout << "��� ��������� ������ ���������� ����� � ��������:\n";
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if ((B[i].destination == D))
        {
            cout << B[i].index << "\n";
            c++;
        }
    }
    cout << "�����: " << c << "\n";
}
void TYPE(aeroflot *B, int n, string T){
    cout << "��� ��������� ���� ����� � ��������:\n";
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (B[i].type == T)
        {
            cout << B[i].index << "\n";
            c++;
        }
    }
    cout << "�����: " << c << "\n";
}
void TIME(aeroflot *B, int n, string D, int t1, int t2){
    cout << "��� ��������� ��� ������ � ��������� ������� ���������� ����� � ��������:\n";
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if ((B[i].day == D) && (t1 <= B[i].time) && (B[i].time <= t2))
        {
            cout << B[i].index << "\n";
            c++;
        }
    }
    cout << "�����: " << c << "\n";
}

// ����������
//����������� ����������
void SORT(aeroflot *B, int n){
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (B[j].time > B[j + 1].time)
            {
                flag = false;
                aeroflot b; // ������� �������������� ����������
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
}
//���������� ����� ���������� ���������
void SORTer(aeroflot *B, int n){
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (B[j] < B[j + 1])
            {
                flag = false;
                aeroflot b; // ������� �������������� ����������
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
}

// ���������� ����� � �����
ostream &operator<<(ostream &s_out, const aeroflot &D){
    s_out << D.destination << " " << D.index << " " << D.type << " " << D.time << " " << D.day << "\n";
    return s_out;
}
// ���������� ������ �� ������
istream &operator>>(istream &s_in, aeroflot &D){
    // cout<<"������� ����������, �����, ���, ����� ������ � ���� ������ ����� ������: \n";
    s_in >> D.destination >> D.index >> D.type >> D.time >> D.day;
    return s_in;
}

// ������ � �������
//������ ������ �� �����
void importA(const string F, aeroflot *B, const int n){
    ifstream fin(F);
    if (!fin.is_open())
    {
        cout << "������ �������� ����� �����!" << endl;
    }
    else
    {
        cout << "���� ������." << endl;
        int c;
        fin >> c;
        if (c != n)
        {
            cout << "������ ����� �������!\n";
        }
        else
        {
            for (int i = 0; i < c; i++)
            {
                fin >> B[i];
            }
        }
    }
    cout << "������ ���������." << endl;
    fin.close();
}
//������� ������ � ����
void exportA(const string F, const aeroflot *B, const int n){
    ofstream fin(F);
    if (!fin.is_open())
    {
        cout << "������ �������� ����� �����!" << endl;
    }
    else
    {
        fin << n << "\n";
        cout << "���� ������." << endl;
        for (int i = 0; i < n; i++)
        {
            fin << B[i];
        }
    }
    cout << "������ ���������." << endl;
    fin.close();
}
