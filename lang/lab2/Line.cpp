#include <iostream>
#include <string.h>
#include <fstream>
#include <typeinfo>
using namespace std;
#include "Line.h"

Line::Line(Line &B){
    l = B.l;
}
float Line::length(){
    return l;
}

void Line::setL(){
    cout<<"������� �����:\n";
    cin>>l;
}
void Line::getL() const{
    cout<<"�����: "<<l<<"\n";
}

void ColoredLine::setColor(){
    cout<<"������� ���� r g b:\n";
    cin>>r>>g>>b;
}
void ColoredLine::getColor(){
    cout<<"����\n";
    cout<<r<<g<<b;
}

ColoredLine::ColoredLine(ColoredLine &B){
    l = B.l;
    r = B.r;
    g = B.g;
    b = B.b;
}

PolyLine::PolyLine(PolyLine &B){
    l = B.l;
    n = B.n;
    L = new float[n];
    for (int i=0; i<n; i++){
        L[i] = B.L[i];
    }
}


