#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Line.h"

Line::Line(const Line &B){
    l = B.l;
}

float Line::length(){
    return l;
}

void Line::set(istream& s_in){
    if (&s_in == &cin){
        cout<<"Введите длину линии:\n";
		s_in>>l;
    }
	else{
		s_in>>l;
    }
}
ostream& Line::get(ostream& s_out) const{
    if (&s_out == &cout){
        cout<<"Длина линии:\n";
		s_out<<l<<"\n";
    }
	else{
		s_out<<l<<"\n";
    }
    return s_out;
}

//Операторы
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

Line* Line::getCopy() const {
    return new Line(*this);
}


// Перегрузка ввода в поток
ostream &operator<<(ostream &s_out, const Line &D){
    D.get(s_out);
    return s_out;
}
// Перегрузка вывода из потока
istream &operator>>(istream &s_in, Line &D){
    D.set(s_in);
    return s_in;
}






