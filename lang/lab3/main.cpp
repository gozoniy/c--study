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
    TMatrix<int> B(3,3);
    A.GenerateRandomValues(1,5);
    ofstream fout("out.txt");
    A.get(fout);
    ifstream fin("out.txt");
    B.set(fin);
    cout<<B;

}