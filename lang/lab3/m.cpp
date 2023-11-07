#include <iostream>
#include "complex.cpp"
using namespace std;

int main(){
    system("chcp 1251");
    complex a(2,2);
    float i = 1.0;
    bool f;
    f = i<a;
    cout<<f;
}