#include <iostream>
using namespace std;
#include "date.h"

void date::set(){     //метод ввода дня, месяца и года
    cout<<"Укажите день, месяц и год через пробел: \n";
    cin>>day>>month>>year;
}
void date::print(){   //метод вывода даты ДД.ММ.ГГГГ
    //cout<<"Дата в формате ДД.ММ.ГГГГ: \n"
    cout<<day<<"."<<month<<"."<<year<<endl;
}
long date::format(){   //метод вывода в формате дней
    long form = year*10000+month*100+day;
    return form;
}
int date::days()const{      //метод превращения полей класса в количество дней
    int M = 0;
    for (int i = 1; i<month ; i++){//Счёт месяцев
        if (i == 2){M+=28;}//проверка на февраль
        else if (i%2 == 0){M+=30;}
        else {M+=31;}
    }
    int Ans = year * 365 + M + day;
    return Ans;
}
void date::undays(int N){   //метод превращения количества дней в поля класса
    year = N/365;
    N = N - year * 365;
    int M = 0;
    int k = 1;
    while (!(N<32)){//Счёт месяцев
        if (k == 2){M=28;}//проверка на февраль
        else if (k%2 == 0){M=30;}
        else {M=31;}
        k++;
        N-=M;
    }
    day = N;
}
//Арифметические операторы
const void date::operator = (const date &Date){    //опеартор = (копирование)
        undays(Date.days());
    }
const date date::operator + (int Date){     //оператор + (Прибавление дней к дате)
        date curr = *this;
        date Res;
        Res.undays(curr.days() + Date) ;
        return Res;
    }
const date date::operator - (int Date){     //оператор - (Вычитание дней из даты)
        date curr = *this;
        date Res;
        //undays(curr.days() - Date);
        Res.undays(curr.days() - Date) ;
        return Res;
    }
const int date::operator - (const date &Date) {   //оператор - (количество дней между датами)
        date curr = *this;
        int Res;
        Res = (curr.days() - Date.days()) ;
        return Res;
    }

//Унарные операторы
const date date::operator ++ () {   //оператор ++ (Завтра)
        int N = days();
        undays(++N);
        return *this;
    }
const date date::operator -- () {   //оператор -- (Вчера)
        int N = days();
        undays(--N);
        return *this;
    }

//Операторы отношения
const bool date::operator == (date &Date){
        date curr = *this;
        if (curr.days()==Date.days()){return true;}
        else {return false;}
    }
const bool date::operator > (date &Date){
        date curr = *this;
        if (curr.days()>Date.days()){return true;}
        else {return false;}
    }
const bool date::operator < (date &Date){
        date curr = *this;
        if (curr.days()<Date.days()){return true;}
        else {return false;}
    }


