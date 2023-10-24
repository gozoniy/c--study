#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "Line.h"
#include "ColoredLine.h"

void ColoredLine::setColor(){
    cout<<"Укажите цвет r g b:\n";
    cin>>r>>g>>b;
}
void ColoredLine::getColor(){
    cout<<r<<" "<<g<<" "<<b<<"\n";
}

ColoredLine::ColoredLine(ColoredLine &B){
    l = B.l;
    r = B.r;
    g = B.g;
    b = B.b;
}