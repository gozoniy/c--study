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

        void setS(int S);                       //Задать длину
        void fill();                             //Ввод с клавиатуры
        void fillR(int n1, int n2);             //Рандомные в диапазоне
        void fillU();                           //Упорядоченные
        void fillUr();                          //Упорядоченные в обратном порядке
        void get();     
        void get_file(ofstream &fin);
        void shakerSort();
        void insertSort();



};

#endif //ARRAY_H