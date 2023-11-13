#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Line.h"
#include "PolyLine.h"

PolyLine::PolyLine(const PolyLine &B){
    l = B.l;
    n = B.n;
    L = new float[n];
    for (int i=0; i<n; i++){
        L[i] = B.L[i];
    }
}

void PolyLine::set(istream& s_in){
    Line::set(s_in);
    if (n>0){
        L = new float [n];
        for (int i = 0; i<n; i++){
            if (&s_in == &cin){
                cout<<"Укажите длину "<<i+1<<" линии: ";
                s_in>>L[i];
            }
            else{
                s_in>>L[i];
            }

        }
    }
}

ostream& PolyLine::get(ostream& s_out) const{
    Line::get(s_out);
    if (n>0){
        for (int i = 0; i<n; i++){
            if (&s_out == &cout){
                cout<<"Длина "<<i+1<<" линии: ";
                s_out<<L[i]<<"\n";
            }
            else{
                s_out<<L[i]<<"\n";
            }
        }
    }
    return s_out;
}

void PolyLine::operator=(const PolyLine B){
    l = B.l;
    n = B.n;
    L = new float[n];
    for (int i=0; i<n; i++){
        L[i] = B.L[i];
    }
}



