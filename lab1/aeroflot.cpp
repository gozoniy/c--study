#include <iostream>
using namespace std;
#include "aeroflot.h"

aeroflot::aeroflot(){
    time = 1020;
}
aeroflot::aeroflot(int T){
    time = T;
}
aeroflot::aeroflot(const aeroflot &B){
    time = B.time;

    for (int i = 0; i < 20; i++ ){
        destination[i] = B.destination[i];
        index[i] = B.index[i];
        type[i] = B.type[i];
        day[i] = B.day[i];
    }
}

void aeroflot::set(){
    cout<<"Укажите назначение рейса:\n";
    cin>>destination;
    cout<<"Укажите номер:\n";
    cin>>index;
    cout<<"Укажите тип:\n";
    cin>>type;
    cout<<"Укажите время:\n";
    cin>>time;
    cout<<"Укажите день недели:\n";
    cin>>day;
}

void aeroflot::print(){
    cout<<"Назначение: "<<destination<<"\n";
    cout<<"Номер: "<<index<<"\n";
    cout<<"Тип:\n"<<type<<"\n";
    cout<<"Время:\n"<<time<<"\n";
    cout<<"День недели:\n"<<day<<"\n";
}

void aeroflot::set_time(int T){
    time = T;
}
void aeroflot::get_time(){
    cout<<"Время рейса: "<<time<<"\n";

}

