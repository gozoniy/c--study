#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#include "dealer.h"

void car::set(istream& in){
        in>>brand;
        in>>model;
        in>>speed;
        in>>GearBox;
}
void car::get(ostream& out){
    out<<brand<<" ";
    out<<model<<" ";
    out<<speed<<" ";
    out<<GearBox<<" ";
}

ostream& operator<<(ostream& out, car& B){
    B.get(out);
    return out;
}
istream& operator>>(istream& in, car& B){
    B.set(in);
    return in;
}

void car::copy(const car& B){
    brand = B.brand;
    model = B.model;
    speed = B.speed;
    GearBox = B.GearBox;
}

bool car::operator<(const car& B){
    if (GearBox < B.GearBox)
        return true;
    else if (GearBox == B.GearBox){
        if (brand<B.brand){
            return true;
        }
        else if (brand == B.brand){
            if (model < B.model)
                return true;
            else if (model == B.model){
                if (speed < B.speed)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
char car::getT(){
    return GearBox;
}
int car::getS(){
    return speed;
}

istream& dealer::set(istream& in){
    Clear();
    if (&in == &cin){
        int size;
        cout<<"Введите размер каталога:\n";
        cin >> size;
        cout<<"Каталог из "<<size<<" авто - марка, модель,  максимальную скорость и коробку передач:\n";
        car temp;
        for (int i = 0; i < size; i++){
            in>>temp;
            if (temp.getT() == 'A'){
                catalogA.push_back(temp);
            }
            else{
                catalogM.push_back(temp);
            }
            
        }
    }
    else{
        car temp;
        while(in>>temp){
            if (temp.getT() == 'A'){
                catalogA.push_back(temp);
            }
            else{
                catalogM.push_back(temp);
            }
        }
    }
    sort(catalogA.begin(),catalogA.end());
    sort(catalogM.begin(),catalogM.end());
    return in;
}

ostream& dealer::get(ostream& out){
    if (&out == &cout){
        cout<<"Каталог:\n";
        cout<<"Автомобили с автоматической коробкой передач:\n";
    }
    for (int i = 0; i < catalogA.size(); i++){
        out<<catalogA[i]<<"\n";
    }
    if (&out == &cout)
        cout<<"Автомобили с механической коробкой передач:\n";
    for (int i = 0; i < catalogM.size(); i++){
        out<<catalogM[i]<<"\n";
    }
    return out;
}

void dealer::sortS(){
    for (int i = 0; i < catalogA.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < catalogA.size() - 1; j++)
        {
            if (catalogA[j].getS()<catalogA[j+1].getS())
            {
                flag = false;
                swap(catalogA[j],catalogA[j+1]);
            }
        }
        if (flag)
        {
            break;
        }
    }
    for (int i = 0; i < catalogM.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < catalogM.size() - 1; j++)
        {
            if (catalogM[j].getS()<catalogM[j+1].getS())
            {
                flag = false;
                swap(catalogM[j],catalogM[j+1]);
            }
        }
        if (flag)
        {
            break;
        }
    }
}

ostream& dealer::top5(ostream& out){
    if (&out == &cout){
        cout<<"5 самых быстрых авто на автоматической коробке передач:\n";
    }
    sortS();
    car temp;
    int c = 0;
    for (int i = 0; i < catalogA.size() && c<5; i++){
        cout<<catalogA[i]<<"\n";
        c++;
    }
    if (&out == &cout){
        cout<<"5 самых быстрых авто на механической коробке передач:\n";
    }
    c = 0;
    for (int i = 0; i < catalogM.size() && c<5; i++){
        cout<<catalogM[i]<<"\n";
        c++;
    }
    return out;
}

void dealer::Clear(){
    catalogA.clear();
    catalogM.clear();
}
