#ifndef PICTURE_H
#define PICTURE_H
#include "Line.h"

class Picture{
        int size = 0;   
        Line **objects = nullptr;
    public:
        Picture(){}
        Picture(const int S): size(S), objects(new Line * [size]){};
        Picture(const Picture &B);
        ~Picture(){Clear();};

        //¬вод-вывод
        istream& set(istream& s_in);
        ostream& get(ostream& s_out) const;
        void getL(const float l1, const float l2);
        void Sort();
        void f_in(string filename);
        void f_out(string filename) const;
        void Clear();
};
#endif //PICTURE_H