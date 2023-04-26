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
int date::days(){      //метод превращения полей класса в количество дней
    int M = 0;
    for (int i = 0; i<month ; i++){
        if (i%2 == 0){M+=30;}
        else {M+=31;}
    }
    int Ans = year * 365 + M + day;
    return Ans;
}
void date::undays(int N){   //метод превращения количества дней в поля класса
    year = N%365;
    N = N - year * 365;
    month = N%30;
    N = N - month * 30;
    day = N;
}


