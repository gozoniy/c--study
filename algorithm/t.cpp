#include <iostream>
using namespace std;
#include "array.cpp"

int main(void){
    system("chcp 1251");
    array<int> A[2];
    A[0].fillUr();
    A[0].get();
    A[0].shakerSort();
    A[0].get();
    A[1].fillR(1,20);
    A[1].get();
    A[1].shakerSort();
    A[1].get();
}