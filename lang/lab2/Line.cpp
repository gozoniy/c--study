#include <iostream>
#include <string.h>
#include <fstream>
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

void Line::operator=(const Line B){
    l = B.l;
}






