#ifndef AEROFLOT_H
#define AEROFLOT_H

class aeroflot{
        string destination;
        string index;
        string type;
        int time;
        string day;
    public:
    //конструкторы
        aeroflot() {}; //по-молчанию
        aeroflot(int T); //с параметрами
        aeroflot(const aeroflot &B); //копий
    //деструктор
        ~aeroflot() {} 
    //методы ввода-вывода
        void set();
        void print()const;
        void set_time(const int T);
        void get_time()const;
    //¬ыборки
        friend void DEST(aeroflot *B, int n, string D);
        friend void TYPE(aeroflot *B, int n, string T);
        friend void TIME(aeroflot *B, int n, string D, int t1, int t2);
    //операторы сравнени€
        const void operator = (const aeroflot B);
        const bool operator == (const aeroflot &B);
        const bool operator > (const aeroflot &B)const;
        const bool operator < (const aeroflot &B)const;
    //потоковый ввод-вывод
        friend ostream& operator<<(ostream& s_out, const aeroflot& D);
        friend istream& operator>>(istream& s_in, aeroflot& D);
};

#endif //AEROFLOT_H