#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");

    date d1(26,4,2023);                //по умолчанию
    d1.print();
    date d2(27,4,2023);    //с параметрами
    d2.print();
    cout<<"Дней между d1 и d2: "<<d2 - d1<<endl;
    cout<<"Через 365 дней будет: "<<endl;
    d1+365;
    d1.print();
    d1-365;
    cout<<"Завтра будет: "<<endl;
    ++d1;
    d1.print();
    --d1;
    if (d1==d2){cout<<"d2 сегодня"<<endl;}
    else {cout<<"d2 не сегодня"<<endl;}
    if (d1<d2){cout<<"d2 еще наступит "<<endl;}
    cout<<"Теперь d1=d2"<<endl;
    d1=d2;
    d1.print();
    cin>>d1;
    cout<<d1;
}