#ifndef DATE_H
#define DATE_H

class date{
    int day,month,year;
public:
    void set();
    void print();
    long format();
    int days();
    void undays(int N);

    //Конструкторы
    date(){srand(time(NULL)); day=rand()%31+1; month = rand()%12+1; year = 2022+rand()%2;}
    date(int d, int m, int y){day = d; month = m; year = y;}
    date(date &A){day = A.day; month = A.month; year = A.year;}
    //Деструктор
    ~date(){}

//Арифметические операторы
    const void operator = (date Date){
        date curr = *this;
        date Res;
        undays(Date.days());
    }
    //оператор + (Прибавление дней к дате)
    const date operator + (int Date){
        date curr = *this;
        date Res;
        undays(curr.days() + Date);
        Res.undays(curr.days() + Date) ;
        return Res;
    }
    //оператор - (Вычитание дней из даты)
    const date operator - (int Date){
        date curr = *this;
        date Res;
        undays(curr.days() - Date);
        Res.undays(curr.days() - Date) ;
        return Res;
    }
    //оператор - (количество дней между датами)
    const int operator - (date &Date) {
        date curr = *this;
        int Res;
        Res = (curr.days() - Date.days()) ;
        return Res;
    }

//Унарные операторы
    //оператор ++ (Завтра)
    const date operator ++ () {
        int N = days();
        undays(++N);
        return *this;
    }
    //оператор -- (Вчера)
    const date operator -- () {
        int N = days();
        undays(--N);
        return *this;
    }

//Операторы отношения
    const bool operator == (date &Date){
        date curr = *this;
        if (curr.days()==Date.days()){return true;}
        else {return false;}
    }
        const bool operator > (date &Date){
        date curr = *this;
        if (curr.days()>Date.days()){return true;}
        else {return false;}
    }
    const bool operator < (date &Date){
        date curr = *this;
        if (curr.days()<Date.days()){return true;}
        else {return false;}
    }

};

#endif DATE_H