#include <iostream>
using namespace std;
#include "rectangle.h"

void rectangle::set(){     //метод задания координат
    cout<<"Укажите координаты первой точки через пробел\n";
    cin>>x1>>y1;
    cout<<"Укажите координаты второй точки через пробел\n";
    cin>>x2>>y2;
}
void rectangle::print(){   //метод вывода координат
    cout<<"1 угол:   ("<<x1<<";"<<y1<<")\n"
    <<"2 угол:   ("<<x2<<";"<<y2<<")\n";
}
float rectangle::area(){   //метод рассчета площади
    float S;
    S=abs(x1-x2)*abs(y1-y2);
    cout<<"S = "<<S<<endl;
    return S;
}
