
#include <iostream>
using namespace std;

int main(void){
    system("chcp 1251");
    int f = 1;
    int in;
    while (f){
        cout<<"1) Cортировка одного массива, сформированного случайным образом\n";
        cout<<"2) Режим накопления статистических данных\n";
        cout<<"0) Выход \n";
        cin>>in;;
        switch (in){
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 0:{
                f = 0;
                break;
            }
        }
    }
}