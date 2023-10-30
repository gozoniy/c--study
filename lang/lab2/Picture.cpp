#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#include "Picture.h"

Picture::Picture(int S){
    size = S;
    objects = new Line*[size];
}

Picture::Picture(Picture &B){
    size = B.size;
    objects = new Line*[size];
    for (int i = 0; i < size; i++){
        objects[i] = B.objects[i]->getCopy();
    }
}

Picture::~Picture(){
    Clear();
}

void Picture::Clear(){
    cout<<"!\n";

    for (int i = 0; i < size; i++){

        delete objects[i];
        cout<<"!\n";
    }
    delete[] objects;
    size = 0;
    objects = nullptr;

}

istream& Picture::set(istream& s_in){
    
    if (exists){
        Clear();
    }
    if (&s_in == &cin){
        
        if (size == 0){
            cout<<"ниче\n";
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
    exists = true;
    return s_in;
}

ostream& Picture::get(ostream& s_out){
    for (int i = 0; i<size; i++){
        cout<<"Линия "<<i<<" типа "<<objects[i]->myName()<<":\n";
        objects[i]->get(s_out);
    }
    return s_out;
}

void Picture::sort(){
    for (int i = 0; i < size; i++)
    {
        bool flag = true;
        for (int j = 0; j < size - 1; j++)
        {
            if (objects[j] < objects[j + 1])
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

void Picture::getAl(float l1, float l2){
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
    if (exists){
        Clear();
    }
    ifstream fin(filename);
    fin>>size;
    for (int i = 0; i < size; i++){
        string name;
        fin>>name;
        if (name == "Line"){
            objects[i] = new Line;
        }
        else if(name == "ColoredLine"){
            objects[i] = new ColoredLine;
        }
        else if(name == "PolyLine"){
            objects[i] = new PolyLine;
        }
        fin>>*objects[i];
    }
    cout<<"Запись завершена.\n";
    exists = true;
}
void Picture::f_out(string filename){
    ofstream fout(filename);
    fout<<size<<"\n";
    for (int i = 0; i < size; i++){
        fout<<objects[i]->myName()<<" ";
        fout<<*objects[i];
    }
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