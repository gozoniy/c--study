#ifndef PICTURE_H
#define PICTURE_H
#include "Line.h"

class Picture{
        int size = 0;   
        Line **objects = nullptr;
        bool exists = false;
    public:
        Picture(){}
        Picture(int S);
        Picture(Picture &B);
        ~Picture();

        //¬вод-вывод
        istream& set(istream& s_in);
        ostream& get(ostream& s_out);
        void Sort();
        void sort();
        void getAl(float l1, float l2);
        void f_in(string filename);
        void f_out(string filename);
        void Clear();
};
//выделение, конст и копии вывода в файл, убрать экзистс и второй сорт
#endif //PICTURE_H