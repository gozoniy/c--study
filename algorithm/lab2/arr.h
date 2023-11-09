#ifndef ARR_H
#define ARR_H

template<typename T>
class arr{
        int size;
        T *a;
    public:
        arr();
        arr(int n);
        arr(const arr &A);
        ~arr(){delete a;}

        void setS(int S);                    //Задать длину
        int getS();                          //Вернуть длину
        void fill();                         //Ввод с клавиатуры
        void fillR(int n1, int n2);          //Рандомные в диапазоне
        void fillU();                        //Упорядоченные
        void fillUr();                       //Упорядоченные в обратном порядке
        void get();                          //Вывод на экран
        void get_file(ofstream &fin);        //Вывод в поток
        void mergeSort();                    //Сортировка прямым слиянием
        void polyphaseMergeSort();           //Многофазная сортировка
};
#endif //ARR_H