#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#include "Line.cpp"
#include "ColoredLine.cpp"
#include "PolyLine.cpp"
#include "Picture.cpp"

int main(void){
    system("chcp 1251");
    Picture A(2);
    A.set(cin);
    A.Sort();
    A.get(cout);

}
