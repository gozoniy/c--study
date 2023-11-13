#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#include "Picture.h"

Picture::Picture(const Picture &B){
    size = B.size;
    objects = new Line*[size];
    for (int i = 0; i < size; i++){
        objects[i] = B.objects[i]->getCopy();
    }
}

void Picture::Clear(){
    for (int i = 0; i < size; i++){
        delete objects[i];
        cout<<"!\n";
    }
    delete[] objects;
    size = 0;
    objects = nullptr;

}

istream& Picture::set(istream& s_in){
    Clear();
    if (&s_in == &cin){
        
        if (size == 0){
            cout<<"Укажите кол-во элементов:\n";
            cin>>size;
            objects = new Line*[size];
        }
        
        for (int i = 0; i < size; i++){
            cout<<"Линия "<<i<<":\n";
            cout<<"Укажите тип:\n";
            string type;
            s_in >> type;
            if (type == "Line"){
                objects[i] = new Line();
            }
            else if (type == "ColoredLine"){
                objects[i] = new ColoredLine();
            }
            else if (type == "PolyLine"){
                objects[i] = new PolyLine();
            }
            objects[i]->set(s_in);
        }
    }
    else{
        s_in>>size;
        objects = new Line*[size];
        for (int i = 0; i < size; i++){
            string type;
            s_in >> type;
            if (type == "Line"){
                objects[i] = new Line;
            }
            else if (type == "ColoredLine"){
                objects[i] = new ColoredLine;
            }
            else if (type == "PolyLine"){
                objects[i] = new PolyLine;
            }
            objects[i]->set(s_in);
        }
    }
    return s_in;
}

ostream& Picture::get(ostream& s_out)const {
    if (&s_out == &cout){
        for (int i = 0; i<size; i++){
            cout<<"Линия "<<i<<" типа "<<objects[i]->myName()<<":\n";
            objects[i]->get(s_out);
        }
    }
    else{
        s_out<<size<<"\n";
        for (int i = 0; i<size; i++){
            s_out<<objects[i]->myName()<<"\n";
            objects[i]->get(s_out);
        }
    }
    return s_out;
}

void Picture::getL(const float l1, const float l2){
    cout<<"Удовлетворяют условию:\n";
    int c = 0;
    for (int i = 0; i < size; i++)
        {
            if (objects[i]->length()>l1 && objects[i]->length()<l2){
                cout << "Линия № " << i + 1 << ":\n";
                objects[i]->get(cout);
                c++;
            }
        }
    cout<<"Всего: "<< c <<"\n";
}

//Работа с файлами
void Picture::f_in(string filename){
    Clear();
    ifstream fin(filename);
    set(fin);
    cout<<"Запись завершена.\n";
}
void Picture::f_out(string filename) const {
    ofstream fout(filename);
    get(fout);
    cout<<"Запись завершена.\n";
}

void Picture::Sort(){
    for (int i = 0; i < size; i++)
    {
        bool flag = true;
        for (int j = 0; j < size - 1; j++)
        {
            if (*objects[j] < *objects[j + 1])
            {
                flag = false;
                swap(objects[j],objects[j+1]);
            }
        }
        if (flag)
        {
            break;
        }
    }
}