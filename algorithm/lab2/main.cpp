#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "sorts.h"
using namespace std;

int main(void){
    system("chcp 1251");
    int f = 1;
    int in;
    while (f){
        cout<<"1) Cортировка одного файла, сформированного случайным образом\n";
        cout<<"2) Режим накопления статистических данных\n";
        cout<<"0) Выход \n";
        cin>>in;
        switch(in){
            case 1:{
                int n;
                cout<<"Задайте длину файла: ";
                cin>>n;
                cout<<"Введите диапозон генерации от n1 до n2 (n1_n2):";
                int n1, n2;
                cin>>n1>>n2;
                getFile("numbers.txt",n,n1,n2);
                int inp;
                cout<<"1) Сортировка прямым слиянием Merge Sort\n"
                <<"2) Многофазная сортировка Polyphase Merge Sort\n";
                cin>>inp;
                int t_1 = clock();
                switch (inp){
                    case 1:{
                        DirectSort("numbers.txt",n);
                        break;
                    }
                    case 2:{
                        PolyphaseSort("numbers.txt");
                        break;
                    }
                }
                int t_2 = clock();
                int ans = t_2 - t_1;
                cout<<n<< " эл отсортированы за "<<ans<<"ms\n";
                readFile("numbers.txt",n);
                break;
            }
            
            case 2:{
                int size;
                int in2,in3;
                int a1,b1,l;
                cout<<"1) Заполнение случайными значениями\n"
                <<"2) Заполнение упорядоченными значениями\n"
                <<"3) Заполнение обратноупорядоченными значениями\n";
                cin>>in2;
                cout<<"Введите диапазон (от _ до _) и шаг через пробел:\n";
                cin>>a1>>b1>>l;
                int N = (b1-a1)/l+1;
                for (int i = 0; i<N-1; i++){
                    size = ((i)*l)+a1;
                    switch (in2){
                        case 1:{
                            getFile("numbers" + to_string(i+1) + ".txt",size,1,10);
                            break;
                        }
                        case 2:{
                            getUFile("numbers" + to_string(i+1) + ".txt",size);
                            break;
                        }
                        case 3:{
                            getUrFile("numbers" + to_string(i+1) + ".txt",size);
                            break;
                        }
                    }
                }
                cout<<"Всего заполнено "<<N-1<<" массивов.\n";

                cout<<"1) Сортировка прямым слиянием Merge Sort\n"
                <<"2) Многофазная сортировка Polyphase Merge Sort\n";
                cin>>in2;
                ofstream fout("results.txt");
                int t1 = clock();
                switch (in2){
                    case 1:{
                        for (int i = 0; i<N-1; i++){
                            size = ((i)*l)+a1;
                            int t_1 = clock();
                            DirectSort("numbers" + to_string(i+1) + ".txt",size);
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<" эл отсортированы за "<<ans<<"ms\n";
                            fout<<size<<" "<<ans<<"\n";
                        }
                        break;
                    }
                    case 2:{
                        for (int i = 0; i<N-1; i++){
                            size = ((i)*l)+a1;
                            int t_1 = clock();
                            PolyphaseSort("numbers" + to_string(i+1) + ".txt");
                            int t_2 = clock();
                            int ans = t_2 - t_1;
                            cout<<" эл отсортированы за "<<ans<<"ms\n";
                            fout<<size<<" "<<ans<<"\n";
                        }
                        break;
                    }
                }
                int t2 = clock();
                int answ = (t2-t1);
                cout<<"Общее время: "<<answ<<"ms\n";
                cout<<"Очистить файлы сортировки? 1/0\n";
                int clear;
                cin>>clear;
                if (clear){
                    for (int i = 0; i<N-1; i++){
                        remove(("numbers" + to_string(i+1) + ".txt").c_str());
                    }
                }
                break;
            }
            case 0:{
                f = 0;
                break;
            }
        }
    }
}

