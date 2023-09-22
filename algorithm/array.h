#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class array{
        int size;
        T *arr;
    public:
        array();
        array(int n);
        array(const array &A);
        ~array(){delete[]arr;}

        void set();
        void setR(int n1, int n2);
        void get();
        void get_file(ofstream &fin);
        void shakerSort();
        void insert_sort();



};

#endif //ARRAY_H