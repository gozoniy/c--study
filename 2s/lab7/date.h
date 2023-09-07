#ifndef DATE_H
#define DATE_H

class date{
    int day,month,year;
public:
    void set();
    void print();
    long format();
    //Конструкторы с инициализацией
    //date():day(1),month(1),year(1970){}
    //date(int d, int m, int y):day(d),month(m),year(y){}
    
    //Конструкторы без инициализации
    date(){srand(time(NULL)); day=rand()%31+1; month = rand()%12+1; year = rand()%2023+1;}      //По умолчанию с рандомом
    date(int d, int m, int y){day = d; month = m; year = y;}                                    //С параметрами
    date(date &A){day = A.day; month = A.month; year = A.year;}                                 //Копий
    //Деструктор
    ~date(){cout<<"Дата "<<day<<"."<<month<<"."<<year<<" удалена.\n";}
};

#endif DATE_H