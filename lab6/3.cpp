#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cstdlib>  

class rectangle{    //класс прямоугольник
public:
    float x1,y1,x2,y2;

    void set(){     //метод задания координат
        cout<<"Укажите координаты первой точки через пробел\n";
        cin>>x1>>y1;
        cout<<"Укажите координаты второй точки через пробел\n";
        cin>>x2>>y2;
    }

    void print(){   //метод вывода координат
        
        cout<<"1 угол:   ("<<x1<<";"<<y1<<")\n"
        <<"2 угол:   ("<<x2<<";"<<y2<<")\n";
    }

    float area(){   //метод рассчета площади
        float S;
        S=abs(x1-x2)*abs(y1-y2);
        cout<<"S = "<<S<<endl;
        return S;
    }
};

int main(void){
    system("chcp 1251");
    rectangle r1;

    int l;
    cout<<"Укажите длинну массива:\n";
    cin>>l;
    rectangle *R = new rectangle[l];
    for (int i=0;i<l;i++){
        cout<<"Прямоугольник №"<<i+1<<endl;
        R[i].set();
    }
    cout<<"Массив прямоугольников:\n";
    for (int i=0;i<l;i++){
        cout<<"Прямоугольник №"<<i+1<<endl;
        R[i].print();
        R[i].area();
    }
}