#include <iostream>
using namespace std;
#include "date.h"

void date::set(){     //метод ввода дня, месяца и года
    cout<<"Укажите день, месяц и год через пробел: \n";
    cin>>day>>month>>year;
}
void date::print(){   //метод вывода даты ДД.ММ.ГГГГ
    cout<<"Дата в формате ДД.ММ.ГГГГ: \n"
    <<day<<"."<<month<<"."<<year<<endl;
}
long date::format(){   //метод вывода в формате дней
    long form = year*10000+month*100+day;
    return form;
}
