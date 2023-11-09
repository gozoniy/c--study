#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include "TMatrix.h"
#include "complex.cpp"
using namespace std;

int main(){
    system("chcp 1251");
    TMatrix<int> A(3,3);
    cin>>A;
    cout<<A;
}