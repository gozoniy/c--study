#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#include "Picture.h"

Picture::Picture(int S){
    size = S;
    objects = new Line[size];
}

Picture::Picture(Picture &B){
    size = B.size;
    for (int i = 0; i < size; i++){
        objects[i] = B.objects[i];
    }
}

void Picture::set(){
    for (int i = 0; i < size; i++){
        cout<<"Линия "<<i<<":\n";
        objects[i].set();
    }
}

void Picture::get(){
    for (int i = 0; i<size; i++){
        cout<<"Линия "<<i<<":\n";
        objects[i].get();
    }
}

void Picture::getS(){
    cout<<"Отсортированный массив:\n";
    Line *B = new Line [size];
    for (int i = 0; i < size; i++){        //перенос данных в копию
        B[i]=objects[i];
    }

    for (int i = 0; i < size; i++)
    {
        bool flag = true;
        for (int j = 0; j < size - 1; j++)
        {
            if (B[j] < B[j + 1])
            {
                flag = false;
                Line b; // создаём дополнительную переменную
                b = B[j];
                B[j] = B[j + 1]; // меняем местами значения
                B[j + 1] = b;
            }
        }
        if (flag)
        {
            break;
        }
    }
    getA(B,size);
    delete[] B;
}

void Picture::getAl(float l1, float l2){
    cout<<"Удовлетворяют условию:\n";
    int c = 0;
    for (int i = 0; i < size; i++)
        {
            if (objects[i].length()>l1 && objects[i].length()<l2){
                cout << "Линия № " << i + 1 << ":\n";
                objects[i].get();
                c++;
            }
        }
    cout<<"Всего: "<< c <<"\n";
}
//Работа с файлами
void Picture::f_in(string filename){
    ifstream fin(filename);
    fin>>size;
    for (int i = 0; i < size; i++){
        fin>>objects[i];
    }
    cout<<"Запись завершена.\n";
}
void Picture::f_out(string filename){
    ofstream fout(filename);
    fout<<size<<"\n";
    for (int i = 0; i < size; i++){
        fout<<objects[i]<<" ";
    }
    cout<<"Запись завершена.\n";
}
