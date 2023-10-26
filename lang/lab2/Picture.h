#ifndef PICTURE_H
#define PICTURE_H
#include "Line.h"

class Picture{
        int size;   
        Line **objects;
    public:
        Picture(){}
        Picture(int S);
        Picture(Picture &B);
        ~Picture(){delete[] objects;}

        //¬вод-вывод
        istream& set(istream& s_in);
        ostream& get(ostream& s_out);
        void sort();
        void getAl(float l1, float l2);
        void f_in(string filename);
        void f_out(string filename);
};

#endif //PICTURE_H