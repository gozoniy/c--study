#ifndef DATE_H
#define DATE_H



class date{
    int day,month,year;
public:
    void set();
    void print();
    long format();
    date(){
        day = rand()%30;
        month = rand()%12;
        year = rand()%3000;
    }
};


#endif DATE_H