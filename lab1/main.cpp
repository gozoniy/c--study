#include "aeroflot.cpp"

int main(void){
    system("chcp 1251");
    aeroflot A[3];
    importA("test.txt",A,3);
    SORTer(A,3);
    cout<<"sorted: \n";
    getMA(A,3);
}