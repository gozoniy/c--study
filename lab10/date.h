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
    const void operator = (date Date);
    const date operator + (int Date);   //оператор + (Прибавление дней к дате)
    const date operator - (int Date);   //оператор - (Вычитание дней из даты)
    const int operator - (date &Date);  //оператор - (количество дней между датами)
//Унарные операторы
    const date operator ++ ();    //оператор ++ (Завтра)
    const date operator -- ();    //оператор -- (Вчера)
//Операторы отношения
    const bool operator == (date &Date);
    const bool operator > (date &Date);
    const bool operator < (date &Date);

//перегрузка операций ввода/вывода
friend ostream& operator<<(ostream& s_out, const date& D);
friend istream& operator>>(istream& s_in, date& D);
};



#endif DATE_H