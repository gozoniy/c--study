#include <iostream>
#include <random>
#include <time.h>
#include "TMatrix.h"

using namespace std;

int main(){
    system("chcp 1251");
    TMatrix<double> M(3,3);
    cin>>M;
    cout<<M;
    M.LowAwg();

}