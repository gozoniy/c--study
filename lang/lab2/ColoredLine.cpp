#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Line.h"
#include "ColoredLine.h"


void ColoredLine::setColor(){
    cout<<"”кажите цвет r g b:\n";
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
void ColoredLine::set(istream& s_in) {
    Line::set(s_in);
    s_in>>r>>g>>b;
    
}

ostream& ColoredLine::get(ostream& s_out) const{
    Line::get(s_out);
    if (&s_out == &cout){
        s_out<<"÷вет линии r g b: \n"
        << r <<" "<<g<<" "<<b<<"\n";
    }
    else{
        s_out<<r<<" "<<g<<" "<<b<<"\n";
    }
    return s_out;
}

//ќператоры
void ColoredLine::operator=(const ColoredLine B){
    l = B.l;
    r = B.r;
    g = B.g;
    b = B.b;
}


