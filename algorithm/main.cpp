//21. сортировка прямыми обменами; сортировка прямыми включениями. 
#include <iostream>
using namespace std;
#include "array.cpp"

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
                int n;
                cout<<"Задайте размер массива: ";
                cin>>n;
                array<int> A(n);
                cout<<"Введите диапозон генерации от n1 до n2 (n1_n2):";
                int n1, n2;
                cin>>n1>>n2;
                A.setR(n1,n2);
                A.get();
                array<int> B(A);
                B.shakerSort();
                cout<<"Отсортированный массив: \n";
                B.get();
                string name;
                cout<<"Укажите имя файла вывода: \n";
                cin>>name;
                ofstream fout(name);
                if (!fout.is_open()){
                    cout<<"Ошибка открытия!";
                }
                else{
                    A.get_file(fout);
                    B.get_file(fout);
                }
                break;
            }
            case 2:{
                cout<<"1) Заполнение случайными значениями\n"
                <<"2) Заполнение упорядоченными значениями\n"
                <<"3) Заполнение обратноупорядоченными значениями\n";
                
                break;
            }
            case 0:{
                f = 0;
                break;
            }
        }
    }
}