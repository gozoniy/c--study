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
    cout<<"¬ведите длину линии:\n";
    cin>>l;
}
void Line::get() const{
    cout<<"ƒлина линии: "<<l<<"\n";
}

void Line::operator=(const Line B){
    l = B.l;
}






