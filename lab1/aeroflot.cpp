#include <iostream>
#include <string.h>
using namespace std;
#include "aeroflot.h"


aeroflot::aeroflot(){
    time = 1020;
}
aeroflot::aeroflot(int T){
    time = T;
}
aeroflot::aeroflot(const aeroflot &B){
    time = B.time;

    for (int i = 0; i < 20; i++ ){
        destination[i] = B.destination[i];
        index[i] = B.index[i];
        type[i] = B.type[i];
        day[i] = B.day[i];
    }
}

void aeroflot::set(){
    cout<<"������� ���������� �����:\n";
    cin>>destination;
    cout<<"������� �����:\n";
    cin>>index;
    cout<<"������� ���:\n";
    cin>>type;
    cout<<"������� �����:\n";
    cin>>time;
    cout<<"������� ���� ������:\n";
    cin>>day;
}

void aeroflot::print(){
    cout<<"����������: "<<destination<<"\n";
    cout<<"�����: "<<index<<"\n";
    cout<<"���:\n"<<type<<"\n";
    cout<<"�����:\n"<<time<<"\n";
    cout<<"���� ������:\n"<<day<<"\n";
}

void aeroflot::set_time(int T){
    time = T;
}
void aeroflot::get_time(){
    cout<<"����� �����: "<<time<<"\n";

}

void DEST(aeroflot *B, int n, char *D){
    cout<<"��� ��������� ������ ���������� �����:\n";
    int c = 0;
    for (int i = 0; i < n; i++){
        if (!strcmp(B[i].destination,D)){
            cout<<B[i].index<<"\n";
            c++;
        }
    }
    cout<<"�����: "<<c<<"\n";
}

//������� �����-������ ��� ��������
void setMA(aeroflot *A, int n){
    for (int i = 0; i < n; i++){
        cout<<"��������� ���� � "<<i+1<<":\n";
        A[i].set();
    }
}

void getMA(aeroflot *A, int n){
    for (int i = 0; i < n; i++){
        cout<<"���� � "<<i+1<<":\n";
        A[i].print();
    }
}