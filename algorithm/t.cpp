#include <iostream>
#include <time.h>
using namespace std;
#include "array.cpp"

int main(void){
    system("chcp 1251");
    int size = 1000;
    array<int> A[size];
    for (int i = 0; i<size; i++){
        A[i].setS(size);
    }
    cout<<"ok\n";
    for (int i = 0; i<size; i++){
        A[i].fillR(1,20);
    }
    int t1 = clock();
    A[99].get();
    cout<<"ok2\n";
    for (int i = 0; i<size; i++){
        A[i].insertSort();
    }
    int t2 = clock();
    A[99].get();
    cout<<"pass.\n";
    int answ = (t2-t1);
    cout<<"Время: "<<answ<<"ms";
}