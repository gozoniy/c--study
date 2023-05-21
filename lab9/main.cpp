#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");

    date d1(26,4,2023);                //по умолчанию
    cin>>d1;
    cout<<d1;
}