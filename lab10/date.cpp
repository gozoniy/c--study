#include <iostream>
using namespace std;
#include "date.h"

void date::set(){     //метод ввода дн€, мес€ца и года
    cout<<"”кажите день, мес€ц и год через пробел: \n";
    cin>>day>>month>>year;
}
void date::print(){   //метод вывода даты ƒƒ.ћћ.√√√√
    //cout<<"ƒата в формате ƒƒ.ћћ.√√√√: \n"
    cout<<day<<"."<<month<<"."<<year<<endl;
}
long date::format(){   //метод вывода в формате дней
    long form = year*10000+month*100+day;
    return form;
}
int date::days(){      //метод превращени€ полей класса в количество дней
    int M = 0;
    for (int i = 1; i<month ; i++){//—чЄт мес€цев
        if (i == 2){M+=28;}//проверка на февраль
        else if (i%2 == 0){M+=30;}
        else {M+=31;}
    }
    int Ans = year * 365 + M + day;
    return Ans;
}
void date::undays(int N){   //метод превращени€ количества дней в пол€ класса
    year = N/365;
    N = N - year * 365;
    int M = 0;
    int k = 1;
    while (!(N<32)){//—чЄт мес€цев
        if (k == 2){M=28;}//проверка на февраль
        else if (k%2 == 0){M=30;}
        else {M=31;}
        k++;
        N-=M;
    }
    day = N;
    
}

//јрифметические операторы
const void date::operator = (date Date){
        date curr = *this;
        date Res;
        undays(Date.days());
    }
const date date::operator + (int Date){
        date curr = *this;
        date Res;
        undays(curr.days() + Date);
        Res.undays(curr.days() + Date) ;
        return Res;
    }
const date date::operator - (int Date){
        date curr = *this;
        date Res;
        undays(curr.days() - Date);
        Res.undays(curr.days() - Date) ;
        return Res;
    }
const int date::operator - (date &Date) {
        date curr = *this;
        int Res;
        Res = (curr.days() - Date.days()) ;
        return Res;
    }

//”нарные операторы
const date date::operator ++ () {
        int N = days();
        undays(++N);
        return *this;
    }
const date date::operator -- () {
        int N = days();
        undays(--N);
        return *this;
    }

//ќператоры отношени€
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

//перегрузка операций ввода/вывода
istream& operator>>(istream& s_in, date& D){                //ввод - копирует функцию set()
    cout<<"”кажите день, мес€ц и год через пробел: \n";
    s_in>>D.day>>D.month>>D.year;
}
ostream& operator<<(ostream& s_out, const date& D){         //вывод - копирует функцию print()
    s_out << D.day <<"."<< D.month <<"."<< D.year <<endl;
    return s_out;
}


