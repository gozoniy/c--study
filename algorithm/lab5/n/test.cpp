#include <iostream>
#include <fstream>
#include "hashtab.h"
#include <ctime>
using namespace std;
int HF(int key){
    int table_size = 100;
    float f = rand()%9+rand()/static_cast <float> (RAND_MAX);
    f = f / 10;
    // умножить ключ на случайное число из диапазона 0...1
    f = key * f;
    // взять дробную часть
    f = f - int(f);
    // возвратить число в диапазоне 0...n-1
    return table_size*f;
}
int main(){
	setlocale(LC_ALL, "Russian");
    int size = 100;
    int key = 80;
    srand(time(NULL));

    cout<<HF(55);
}