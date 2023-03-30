
#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string.h>
#include <locale.h>
#include <cstdlib>  

#include <list>

#define PI 3.14

int main(void){
    system("chcp 1251");

    list <int> my_list = {1, 2, 3, 12, 0, 32};
    cout<<my_list.back()<<endl;
    cout<<(PI+PI);
}