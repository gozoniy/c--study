#ifndef PICTURE_H
#define PICTURE_H
#include "Line.h"

class Picture{
        int size;   
        Line *objects;
    public:
        Picture(){}
        Picture(int S);
        Picture(Picture &B);
        ~Picture(){delete[] objects;}

        //����-�����
        void set();
        void get();

};

#endif //PICTURE_H