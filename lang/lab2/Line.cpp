#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Line.h"

void Line::set(istream& s_in){
    if (&s_in == &cin){
        cout<<"������� ����� �����:\n";
		s_in>>l;
    }
	else{
		s_in>>l;
    }
}
ostream& Line::get(ostream& s_out) const{
    if (&s_out == &cout){
        cout<<"����� �����:\n";
		s_out<<l<<"\n";
    }
	else{
		s_out<<l<<"\n";
    }
    return s_out;
}

//���������
void Line::operator=(const Line B){
    l = B.l;
}
bool Line::operator>(const Line B)const{
    return B.l > l;
}
bool Line::operator<(const Line B)const{
    return B.l < l;
}

Line* Line::getCopy() const {
    return new Line(*this);
}


// ���������� ����� � �����
ostream &operator<<(ostream &s_out, const Line &D){
    D.get(s_out);
    return s_out;
}
// ���������� ������ �� ������
istream &operator>>(istream &s_in, Line &D){
    D.set(s_in);
    return s_in;
}






