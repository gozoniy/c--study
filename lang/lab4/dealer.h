#pragma once
#ifndef DEALER_H
#define DEALER_H

class car{
    private:
        string brand; // марка автомобиля
        string model; // модель автомобиля
        int speed; // скорость автомобиля
        char GearBox; // 1 буква коробки передач автомобиля
    public:
        // установить значения из входного потока
        void set(istream& in);
        // получить значения в выходной поток
        void get(ostream& out) const;
        // получить тип коробки передач
        char getT() const { return GearBox; }
        // получить скорость
        int getS() const { return speed; }
        // скопировать значения из другого объекта car
        void copy(const car& B);
        // перегрузка оператора присваивания
        car& operator= (const car& B){ copy(B); return *this; }
        // перегрузка оператора меньше
        bool operator<(const car& B) const;
        // перегрузка оператора вывода в поток
        friend ostream& operator<<(ostream&, const car& B);
        // перегрузка оператора ввода из потока
        friend istream& operator>>(istream&, car&);
};

class dealer{
    private:
        vector<car> catalogA; // каталог автомобилей с автоматом
        vector<car> catalogM; // каталог автомобилей с механикой
    public:
        // очистить каталоги
        void Clear();
        // отсортировать каталог по скорости
        void sortS();
        // установить значения из входного потока
        istream& set(istream& in);
        // получить значения в выходной поток
        ostream& get(ostream& out) const;
        // вывести топ 5 автомобилей
        ostream& top5(ostream& out);
};

#endif //DEALER_H
