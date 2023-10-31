#pragma once
#ifndef TMATRIX_H

template <class Type>
class TMatrix{
        int a,b;
        Type** matrix;
    public:
        matrix():size(0), matrix(nullptr){}
        martix(I,J): a(I), b(J), matrix(new Type[a]){
            for(int i = 0; i<a; i++){
                matrix[i] = new int * [b]
            }
        }
        void set();

};

#endif //TMATRIX_H