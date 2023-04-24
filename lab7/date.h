#ifndef DATE_H
#define DATE_H

class date{
    int day,month,year;
public:
    void set();
    void print();
    long format();

    //Конструкторы
    date(){srand(time(NULL)); day=rand()%31+1; month = rand()%12+1; year = rand()%2023+1;}
    date(int d, int m, int y){day = d; month = m; year = y;}
    date(date &A){day = A.day; month = A.month; year = A.year;}
    //Деструктор
    ~date(){cout<<"Дата "<<day<<"."<<month<<"."<<year<<" удалена.\n";}
};

#endif DATE_H