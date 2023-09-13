#include <iostream>
#include "Source.cpp"

int main(void) {
    system("chcp 1251");
    InstSession A[2];
    importA("test.txt", A, 2);
    getMA(A, 2);
}