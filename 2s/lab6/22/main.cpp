#include <iostream>
using namespace std;
#include "date.cpp"

int main(void){
    system("chcp 1251");
    bool x = 1;
    int in = 0;
    int l;
    date *D;
    date d1();
    while(x){
        cout<<"<Главное меню>\n"
        <<"1) Заполнить статическую переменную\n"
        <<"2) Вывести\n"
        <<"3) Вывести в формате дней\n"
        <<"4) Заполнить динамический массив\n"
        <<"5) Вывести динамический массив\n"
        <<"0) Выход\n";
        cin>>in;
        switch(in){
            case 0:{        //Выход
                x = 0;
                break;
            }
            case 1:{        //Заполнить
                int d,m,y;
                cout<<"Укажите день, месяц и год через пробел: \n";
                cin>>d>>m>>y;
                date d1(d,m,y);
                break;
            }
            case 2:{        //Вывести
                d1.print();
                break;
            }
            case 3:{        //Вывод в формате одного числа
                cout<<"Дата в виде одного числа: "<<d1.format()<<endl;
                break;
            }
            case 4:{
                cin>>l;
                date *D = new date[l];     //Динамическая переменная
                for (int i = 0; i < l; i++){    //Заполнение динамической переменной
                    cout<<"Дата №"<<i+1<<":\n";
                    D[i].set();
                }
                break;
            }
            case 5:{
                for (int i = 0; i < l; i++){    //Вывод динамиеской переменной
                    cout<<"Дата №"<<i+1<<":\n";
                    D[i].print();
                    cout<<D[i].format()<<endl;
                }
                break;
            }

        }
        in = 0;
    }
}