#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "aeroflot.h"

//������������
aeroflot::aeroflot(){
    time = 1010;
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
//������
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
void aeroflot::print()const{
    cout<<"-----------\n";
    cout<<"����������: "<<destination<<"\n";
    cout<<"�����: "<<index<<"\n";
    cout<<"���: "<<type<<"\n";
    cout<<"�����: "<<time/100<<":"<<time%100<<"\n";
    cout<<"���� ������: "<<day<<"\n";
}
void aeroflot::set_time(const int T){
    time = T;
}
void aeroflot::get_time()const{
    cout<<"����� �����: "<<time<<"\n";

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

//���������
const void aeroflot::operator = (const aeroflot B){
    time = B.time;
    for (int i = 0; i < 20; i++ ){
        destination[i] = B.destination[i];
        index[i] = B.index[i];
        type[i] = B.type[i];
        day[i] = B.day[i];
    }
}
const bool aeroflot::operator == (const aeroflot &B){
    aeroflot A = *this;
    bool answ;
    answ = ((B.destination == A.destination)and(B.index == A.index)and(B.type == A.type)and(B.time == A.time)and(B.day == A.day));
    return answ;
}
const bool aeroflot::operator > (const aeroflot &B){
    aeroflot A = *this;
    bool answ;
    answ = B.time>time;
    return answ;
}
const bool aeroflot::operator < (const aeroflot &B){
    aeroflot A = *this;
    bool answ;
    answ = B.time<time;
    return answ;
}

//�������
void DEST(aeroflot *B, int n, char *D){
    cout<<"��� ��������� ������ ���������� ����� � ��������:\n";
    int c = 0;
    for (int i = 0; i < n; i++){
        if (!strcmp(B[i].destination,D)){
            cout<<B[i].index<<"\n";
            c++;
        }
    }
    cout<<"�����: "<<c<<"\n";
}
void TYPE(aeroflot *B, int n, char *T){
    cout<<"��� ��������� ���� ����� � ��������:\n";
    int c = 0;
    for (int i = 0; i < n; i++){
        if (!strcmp(B[i].type,T)){
            cout<<B[i].index<<"\n";
            c++;
        }
    }
    cout<<"�����: "<<c<<"\n";
}
void TIME(aeroflot *B, int n, char *D, int t1, int t2){
    cout<<"��� ��������� ��� ������ � ��������� ������� ���������� ����� � ��������:\n";
    int c = 0;
    for (int i = 0; i < n; i++){
        if ((!strcmp(B[i].day,D) && (t1<=B[i].time) && (B[i].time<=t2))){
            cout<<B[i].index<<"\n";
            c++;
        }
    }
    cout<<"�����: "<<c<<"\n";
}

//����������
void SORT(aeroflot *B, int n){
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n-1; j++) {
            if (B[j].time > B[j+1].time) {
                flag = false;
                aeroflot b; // ������� �������������� ����������
                b = B[j];
                B[j] = B[j+1]; // ������ ������� ��������
                B[j+1] = b;
            }
        }
        if (flag){
            break;
        }
    }
    
}
void SORTer(aeroflot *B, int n){
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n-1; j++) {
            if (B[j] < B[j+1]) {
                flag = false;
                aeroflot b; // ������� �������������� ����������
                b = B[j];
                B[j] = B[j+1]; // ������ ������� ��������
                B[j+1] = b;
            }
        }
        if (flag){
            break;
        }
    }
}

//���������� �������� �����/������
ostream& operator<<(ostream& s_out, const aeroflot& D){
    s_out << D.destination<<" "<<D.index<<" "<<D.type<<" "<<D.time<<" "<<D.day<<"\n";
    return s_out;
}
istream& operator>>(istream& s_in, aeroflot& D){
    //cout<<"������� ����������, �����, ���, ����� ������ � ���� ������ ����� ������: \n";
    s_in >> D.destination >> D.index >> D.type >> D.time >> D.day;
    return s_in;
}

//������ � �������
void importA(const char *F, aeroflot *B, const int n){
    ifstream fin(F);
    if (!fin.is_open()){
        cout<<"������ �������� ����� �����!"<<endl;
    }
    else{
        cout<<"���� ������."<<endl;
        int c;
        fin>>c;
        if (c!=n){
            cout<<"������ ����� �������!\n";
            }
        else {
            for (int i = 0; i < c; i++){
                    fin>>B[i];
                }
            }
    }
    cout<<"������ ���������."<<endl;
    fin.close();
}
void exportA(const char *F, const aeroflot *B, const int n){
    ofstream fin(F);
    if (!fin.is_open()){
        cout<<"������ �������� ����� �����!"<<endl;
    }
    else{
        fin<<n<<"\n";
        cout<<"���� ������."<<endl;
        for (int i = 0; i < n; i++){
            fin<<B[i];
        }
    }
    cout<<"������ ���������."<<endl;
    fin.close();
}

