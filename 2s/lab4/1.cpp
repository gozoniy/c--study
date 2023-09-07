#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <string>

class human{
public:
    int age;
    string name;


};

int main(void){
    setlocale(LC_ALL,"Rus");
    cout <<"алоха бебрам"<<endl;

    human first;
    first.age=18;
    first.name= "Ivan";

    cout<< first.age <<endl;
}