#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "cars.h"

using namespace std;

void main(){
    system("chcp 1251");
    cars A;
    A.set("input.txt", 2);
    A.get("output.txt");
}