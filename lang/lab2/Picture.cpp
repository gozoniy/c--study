#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#include "Picture.h"

Picture::Picture(int S){
    size = S;
    objects = new Line[size];
}

Picture::Picture(Picture &B){
    size = B.size;
    for (int i = 0; i < size; i++){
        objects[i] = B.objects[i];
    }
}

void Picture::set(){
    for (int i = 0; i < size; i++){
        cout<<"Линия "<<i<<":\n";
        objects[i].set();
    }
}

void Picture::get(){
    for (int i = 0; i<size; i++){
        cout<<"Линия "<<i<<":\n";
        objects[i].get();
    }
}