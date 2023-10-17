#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "Line.h"
#include "PolyLine.h"

PolyLine::PolyLine(PolyLine &B){
    l = B.l;
    n = B.n;
    L = new float[n];
    for (int i=0; i<n; i++){
        L[i] = B.L[i];
    }
}

void PolyLine::set(){
    for (int i = 0; i<n; i++){
        cout<<"Укажите длину "<<i<<" линии: ";
        cin>>L[i];
    }
}

void PolyLine::get() const {
    for (int i = 0; i<n; i++){
        cout<<"Длина "<<i<<" линии: ";
        cout<<L[i]<<"\n";
    }
}
